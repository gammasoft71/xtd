#include "../../../../include/xtd/net/sockets/udp_client.hpp"
#include "../../../../include/xtd/net/sockets/socket_error.hpp"
#include "../../../../include/xtd/net/sockets/socket_exception.hpp"
#include "../../../../include/xtd/net/dns.hpp"
#include "../../../../include/xtd/as.hpp"
#include "../../../../include/xtd/is.hpp"
#include <thread>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

struct udp_client::data {
  //static constexpr size_t max_udp_size = 0x10000;
  socket client_socket {address_family::inter_network, socket_type::dgram, protocol_type::udp};
  bool active = false;
  array<xtd::byte> buffer = array<xtd::byte>(0x10000);
};

udp_client::udp_client() : data_(xtd::new_sptr<udp_client::data>()) {
  active(true);
}

udp_client::udp_client(uint16 port) : data_(xtd::new_sptr<udp_client::data>()) {
  data_->client_socket.bind(ip_end_point(ip_address::any, port));
}

udp_client::udp_client(const xtd::net::ip_end_point& local_end_point) : data_(xtd::new_sptr<udp_client::data>()) {
  data_->client_socket = socket(local_end_point.address_family(), socket_type::dgram, protocol_type::udp);
  data_->client_socket.bind(local_end_point);
}

udp_client::udp_client(address_family address_family) : data_(xtd::new_sptr<udp_client::data>()) {
  if (address_family != xtd::net::sockets::address_family::inter_network && address_family != xtd::net::sockets::address_family::inter_network_v6) throw_helper::throws(exception_case::argument);
  data_->client_socket = socket(address_family, socket_type::dgram, protocol_type::udp);
}

udp_client::udp_client(uint16 port, xtd::net::sockets::address_family address_family) : data_(xtd::new_sptr<udp_client::data>()) {
  if (address_family != xtd::net::sockets::address_family::inter_network && address_family != xtd::net::sockets::address_family::inter_network_v6) throw_helper::throws(exception_case::argument);
  data_->client_socket = socket(address_family, socket_type::dgram, protocol_type::udp);
  data_->client_socket.bind(ip_end_point(dns::get_host_addresses(dns::get_host_name())[0], port));
}

udp_client::udp_client(const xtd::string& hostname, uint16 port) : data_(xtd::new_sptr<udp_client::data>()) {
  connect(hostname, port);
}

udp_client::~udp_client() {
  if (data_.use_count() == 1) close();
}

size_t udp_client::available() const {
  return data_->client_socket.available();
}

xtd::net::sockets::socket udp_client::client() const noexcept {
  return data_->client_socket;
}

udp_client& udp_client::client(const xtd::net::sockets::socket& value) noexcept {
  data_->client_socket = value;
  return *this;
}

bool udp_client::dont_fragment() const {
  return data_->client_socket.dont_fragment();
}

udp_client& udp_client::dont_fragment(bool value) {
  data_->client_socket.dont_fragment(value);
  return *this;
}

bool udp_client::enable_broadcast() const {
  return data_->client_socket.enable_broadcast();
}

udp_client& udp_client::enable_broadcast(bool value) {
  data_->client_socket.enable_broadcast(value);
  return *this;
}

bool udp_client::exclusive_address_use() const {
  return data_->client_socket.exclusive_address_use();
}

udp_client& udp_client::exclusive_address_use(bool value) {
  data_->client_socket.exclusive_address_use(value);
  return *this;
}

bool udp_client::multicast_loopback() const {
  return data_->client_socket.multicast_loopback();
}

udp_client& udp_client::multicast_loopback(bool value) {
  data_->client_socket.multicast_loopback(value);
  return *this;
}

xtd::byte udp_client::ttl() const {
  return data_->client_socket.ttl();
}

udp_client& udp_client::ttl(xtd::byte value) {
  data_->client_socket.ttl(value);
  return *this;
}

void udp_client::allow_nat_traversal(bool allowed) {
  if (allowed) data_->client_socket.set_ip_protection_level(xtd::net::sockets::ip_protection_level::unrestricted);
  else data_->client_socket.set_ip_protection_level(xtd::net::sockets::ip_protection_level::edge_restricted);
}

xtd::sptr<xtd::iasync_result> udp_client::begin_receive(xtd::async_callback callback, const any_object& state) {
  auto ar = xtd::new_sptr<async_result_receive>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, xtd::sptr<async_result_receive> ar, xtd::async_callback callback) {
    try {
      ar->buffer_ = udp_client->receive(ar->remote_end_point_);
      ar->is_completed_ = true;
      as<threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> udp_client::begin_send(const array<xtd::byte>& dgram, size_t bytes, const xtd::string& hostname, uint16 port, xtd::async_callback callback, const any_object& state) {
  auto ar = xtd::new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size_t bytes, const xtd::string & hostname, uint16 port, xtd::sptr<async_result_send> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = udp_client->send(dgram, bytes, hostname, port);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, dgram, bytes, hostname, port, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> udp_client::begin_send(const array<xtd::byte>& dgram, size_t bytes, const xtd::net::ip_end_point& end_point, xtd::async_callback callback, const any_object& state) {
  auto ar = xtd::new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size_t bytes, const xtd::net::ip_end_point & end_point, xtd::sptr<async_result_send> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = udp_client->send(dgram, bytes, end_point);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, dgram, bytes, end_point, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> udp_client::begin_send(const array<xtd::byte>& dgram, size_t bytes, xtd::async_callback callback, const any_object& state) {
  auto ar = xtd::new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size_t bytes, xtd::sptr<async_result_send> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = udp_client->send(dgram, bytes);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, dgram, bytes, ar, callback};
  operation_thread.detach();
  return ar;
}

void udp_client::close() {
  active(false);
  data_->client_socket.close();
}

void udp_client::connect(const ip_end_point& end_point) {
  data_->client_socket.connect(end_point);
  active(true);
}

void udp_client::connect(const ip_address& ip_address, uint16 port) {
  data_->client_socket.connect(ip_address, port);
  active(true);
}

void udp_client::connect(const string& hostname, uint16 port) {
  data_->client_socket.connect(hostname, port);
  active(true);
}

void udp_client::drop_multicast_group(const xtd::net::ip_address& multicast_address) {
  if (data_->client_socket.address_family() == address_family::inter_network) data_->client_socket.set_socket_option(socket_option_name::drop_membership, multicast_option(multicast_address));
  else data_->client_socket.set_socket_option(socket_option_name::drop_membership, ip_v6_multicast_option(multicast_address));
}

void udp_client::drop_multicast_group(const xtd::net::ip_address& multicast_address, uint32 if_index) {
  if (data_->client_socket.address_family() != address_family::inter_network_v6) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::drop_membership, ip_v6_multicast_option(multicast_address, if_index));
}

array<xtd::byte> udp_client::end_receive(xtd::sptr<xtd::iasync_result> async_result, ip_end_point& remote_end_point) {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_receive>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_receive>(async_result)->exception_) rethrow_exception(as<async_result_receive>(async_result)->exception_);
  remote_end_point = as<async_result_receive>(async_result)->remote_end_point_;
  return as<async_result_receive>(async_result)->buffer_;
}

size_t udp_client::end_send(xtd::sptr<xtd::iasync_result> async_result) {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_send>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_send>(async_result)->exception_) rethrow_exception(as<async_result_receive>(async_result)->exception_);
  return as<async_result_send>(async_result)->number_of_bytes_sent_;
}

bool udp_client::equals(const object& obj) const noexcept {
  return is<udp_client>(obj) && equals(static_cast<const udp_client&>(obj));
}

bool udp_client::equals(const udp_client& other) const noexcept {
  return data_ == other.data_;
}

void udp_client::join_multicast_group(const xtd::net::ip_address& multicast_address) {
  if (data_->client_socket.address_family() == address_family::inter_network) data_->client_socket.set_socket_option(socket_option_name::add_membership, multicast_option(multicast_address));
  else data_->client_socket.set_socket_option(socket_option_name::add_membership, ip_v6_multicast_option(multicast_address));
}

void udp_client::join_multicast_group(uint32 if_index, const xtd::net::ip_address& multicast_address) {
  if (data_->client_socket.address_family() != address_family::inter_network_v6) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::add_membership, ip_v6_multicast_option(multicast_address, if_index));
}

void udp_client::join_multicast_group(const xtd::net::ip_address& multicast_address, xtd::byte ttl) {
  join_multicast_group(multicast_address);
  data_->client_socket.ttl(ttl);
}

void udp_client::join_multicast_group(const xtd::net::ip_address& multicast_address, const xtd::net::ip_address& local_address) {
  if (data_->client_socket.address_family() != address_family::inter_network) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::add_membership, multicast_option(multicast_address, local_address));
}

array<xtd::byte> udp_client::receive(ip_end_point& remote_end_point) {
  auto received = data_->client_socket.receive_from(data_->buffer, remote_end_point);
  return array<xtd::byte>(data_->buffer.begin(), data_->buffer.begin() + received);
}

size_t udp_client::send(const array<xtd::byte>& dgram, size_t bytes, const string& hostname, uint16 port) {
  if (hostname != ip_address::broadcast.to_string()) return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, ip_end_point(dns::get_host_addresses(hostname)[0], port));
  data_->client_socket.enable_broadcast(true);
  return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, ip_end_point(ip_address::broadcast, port));
}

size_t udp_client::send(const array<xtd::byte>& dgram, size_t bytes, const ip_end_point& end_point) {
  if (end_point.address() == ip_address::broadcast) data_->client_socket.enable_broadcast(true);
  return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, end_point);
}

size_t udp_client::send(const array<xtd::byte>& dgram, size_t bytes) {
  return data_->client_socket.send(dgram, 0, bytes, socket_flags::none);
}

bool udp_client::active() const noexcept {
  return data_->active;
}

udp_client& udp_client::active(bool value) noexcept {
  data_->active = value;
  return *this;
}
