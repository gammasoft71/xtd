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
  //static constexpr size max_udp_size = 0x10000;
  socket client_socket {address_family::inter_network, socket_type::dgram, protocol_type::udp};
  bool active = false;
  array<xtd::byte> buffer = array<xtd::byte>(0x10000);
};

udp_client::udp_client() : data_(new_sptr<udp_client::data>()) {
  active(true);
}

udp_client::udp_client(uint16 port) : data_(new_sptr<udp_client::data>()) {
  data_->client_socket.bind(ip_end_point(ip_address::any, port));
}

udp_client::udp_client(const ip_end_point& local_end_point) : data_(new_sptr<udp_client::data>()) {
  data_->client_socket = socket(local_end_point.address_family(), socket_type::dgram, protocol_type::udp);
  data_->client_socket.bind(local_end_point);
}

udp_client::udp_client(address_family address_family) : data_(new_sptr<udp_client::data>()) {
  if (address_family != sockets::address_family::inter_network && address_family != sockets::address_family::inter_network_v6) throw_helper::throws(exception_case::argument);
  data_->client_socket = socket(address_family, socket_type::dgram, protocol_type::udp);
}

udp_client::udp_client(uint16 port, xtd::net::sockets::address_family address_family) : data_(new_sptr<udp_client::data>()) {
  if (address_family != sockets::address_family::inter_network && address_family != sockets::address_family::inter_network_v6) throw_helper::throws(exception_case::argument);
  data_->client_socket = socket(address_family, socket_type::dgram, protocol_type::udp);
  data_->client_socket.bind(ip_end_point(dns::get_host_addresses(dns::get_host_name())[0], port));
}

udp_client::udp_client(const string& hostname, uint16 port) : data_(new_sptr<udp_client::data>()) {
  connect(hostname, port);
}

udp_client::~udp_client() {
  if (data_.use_count() == 1) close();
}

auto udp_client::available() const -> size {
  return data_->client_socket.available();
}

auto udp_client::client() const noexcept -> socket {
  return data_->client_socket;
}

auto udp_client::client(const socket& value) noexcept -> udp_client& {
  data_->client_socket = value;
  return *this;
}

auto udp_client::dont_fragment() const -> bool {
  return data_->client_socket.dont_fragment();
}

auto udp_client::dont_fragment(bool value) -> udp_client& {
  data_->client_socket.dont_fragment(value);
  return *this;
}

auto udp_client::enable_broadcast() const -> bool {
  return data_->client_socket.enable_broadcast();
}

auto udp_client::enable_broadcast(bool value) -> udp_client& {
  data_->client_socket.enable_broadcast(value);
  return *this;
}

auto udp_client::exclusive_address_use() const -> bool {
  return data_->client_socket.exclusive_address_use();
}

auto udp_client::exclusive_address_use(bool value) -> udp_client& {
  data_->client_socket.exclusive_address_use(value);
  return *this;
}

auto udp_client::multicast_loopback() const -> bool {
  return data_->client_socket.multicast_loopback();
}

auto udp_client::multicast_loopback(bool value) -> udp_client& {
  data_->client_socket.multicast_loopback(value);
  return *this;
}

auto udp_client::ttl() const -> xtd::byte {
  return data_->client_socket.ttl();
}

auto udp_client::ttl(xtd::byte value) -> udp_client& {
  data_->client_socket.ttl(value);
  return *this;
}

auto udp_client::allow_nat_traversal(bool allowed) -> void {
  if (allowed) data_->client_socket.set_ip_protection_level(ip_protection_level::unrestricted);
  else data_->client_socket.set_ip_protection_level(ip_protection_level::edge_restricted);
}

auto udp_client::begin_receive(async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_receive>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, sptr<async_result_receive> ar, async_callback callback) {
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

auto udp_client::begin_send(const array<xtd::byte>& dgram, size bytes, const string& hostname, uint16 port, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size bytes, const string & hostname, uint16 port, sptr<async_result_send> ar, async_callback callback) {
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

auto udp_client::begin_send(const array<xtd::byte>& dgram, size bytes, const ip_end_point& end_point, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size bytes, const ip_end_point & end_point, sptr<async_result_send> ar, async_callback callback) {
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

auto udp_client::begin_send(const array<xtd::byte>& dgram, size bytes, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](udp_client * udp_client, const array<xtd::byte>& dgram, size bytes, sptr<async_result_send> ar, async_callback callback) {
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

auto udp_client::close() -> void {
  active(false);
  data_->client_socket.close();
}

auto udp_client::connect(const ip_end_point& end_point) -> void {
  data_->client_socket.connect(end_point);
  active(true);
}

auto udp_client::connect(const ip_address& ip_address, uint16 port) -> void {
  data_->client_socket.connect(ip_address, port);
  active(true);
}

auto udp_client::connect(const string& hostname, uint16 port) -> void {
  data_->client_socket.connect(hostname, port);
  active(true);
}

auto udp_client::drop_multicast_group(const ip_address& multicast_address) -> void {
  if (data_->client_socket.address_family() == address_family::inter_network) data_->client_socket.set_socket_option(socket_option_name::drop_membership, multicast_option(multicast_address));
  else data_->client_socket.set_socket_option(socket_option_name::drop_membership, ip_v6_multicast_option(multicast_address));
}

auto udp_client::drop_multicast_group(const ip_address& multicast_address, uint32 if_index) -> void {
  if (data_->client_socket.address_family() != address_family::inter_network_v6) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::drop_membership, ip_v6_multicast_option(multicast_address, if_index));
}

auto udp_client::end_receive(sptr<iasync_result> async_result, ip_end_point& remote_end_point) -> array<xtd::byte> {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_receive>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_receive>(async_result)->exception_) rethrow_exception(as<async_result_receive>(async_result)->exception_);
  remote_end_point = as<async_result_receive>(async_result)->remote_end_point_;
  return as<async_result_receive>(async_result)->buffer_;
}

auto udp_client::end_send(sptr<iasync_result> async_result) -> size {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_send>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_send>(async_result)->exception_) rethrow_exception(as<async_result_receive>(async_result)->exception_);
  return as<async_result_send>(async_result)->number_of_bytes_sent_;
}

auto udp_client::equals(const object& obj) const noexcept -> bool {
  return is<udp_client>(obj) && equals(static_cast<const udp_client&>(obj));
}

auto udp_client::equals(const udp_client& other) const noexcept -> bool {
  return data_ == other.data_;
}

auto udp_client::join_multicast_group(const ip_address& multicast_address) -> void {
  if (data_->client_socket.address_family() == address_family::inter_network) data_->client_socket.set_socket_option(socket_option_name::add_membership, multicast_option(multicast_address));
  else data_->client_socket.set_socket_option(socket_option_name::add_membership, ip_v6_multicast_option(multicast_address));
}

auto udp_client::join_multicast_group(uint32 if_index, const ip_address& multicast_address) -> void {
  if (data_->client_socket.address_family() != address_family::inter_network_v6) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::add_membership, ip_v6_multicast_option(multicast_address, if_index));
}

auto udp_client::join_multicast_group(const ip_address& multicast_address, xtd::byte ttl) -> void {
  join_multicast_group(multicast_address);
  data_->client_socket.ttl(ttl);
}

auto udp_client::join_multicast_group(const ip_address& multicast_address, const ip_address& local_address) -> void {
  if (data_->client_socket.address_family() != address_family::inter_network) throw_helper::throws(exception_case::socket, socket_error::operation_not_supported);
  data_->client_socket.set_socket_option(socket_option_name::add_membership, multicast_option(multicast_address, local_address));
}

auto udp_client::receive(ip_end_point& remote_end_point) -> array<xtd::byte> {
  auto received = data_->client_socket.receive_from(data_->buffer, remote_end_point);
  return array<xtd::byte>(data_->buffer.begin(), data_->buffer.begin() + received);
}

auto udp_client::send(const array<xtd::byte>& dgram, size bytes, const string& hostname, uint16 port) -> size {
  if (hostname != ip_address::broadcast.to_string()) return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, ip_end_point(dns::get_host_addresses(hostname)[0], port));
  data_->client_socket.enable_broadcast(true);
  return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, ip_end_point(ip_address::broadcast, port));
}

auto udp_client::send(const array<xtd::byte>& dgram, size bytes, const ip_end_point& end_point) -> size {
  if (end_point.address() == ip_address::broadcast) data_->client_socket.enable_broadcast(true);
  return data_->client_socket.send_to(dgram, 0, bytes, socket_flags::none, end_point);
}

auto udp_client::send(const array<xtd::byte>& dgram, size bytes) -> size {
  return data_->client_socket.send(dgram, 0, bytes, socket_flags::none);
}

auto udp_client::active() const noexcept -> bool {
  return data_->active;
}

auto udp_client::active(bool value) noexcept -> udp_client& {
  data_->active = value;
  return *this;
}
