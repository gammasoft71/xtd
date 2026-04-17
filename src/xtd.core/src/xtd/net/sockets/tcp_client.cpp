#include "../../../../include/xtd/net/sockets/tcp_client.hpp"
#include "../../../../include/xtd/net/sockets/socket.hpp"
#include "../../../../include/xtd/net/sockets/socket_exception.hpp"
#include "../../../../include/xtd/net/dns.hpp"
#include <mutex>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

struct tcp_client::data {
  socket client_socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
  bool active = false;
};

tcp_client::tcp_client() : data_(xtd::new_sptr<data>()) {
}

tcp_client::tcp_client(const ip_end_point& local_end_point) : data_(xtd::new_sptr<tcp_client::data>()) {
  data_->client_socket.bind(local_end_point);
}

tcp_client::tcp_client(address_family address_family) : data_(xtd::new_sptr<tcp_client::data>()) {
  if (address_family != address_family::inter_network && address_family != address_family::inter_network_v6) throw_helper::throws(exception_case::argument);
  data_->client_socket = socket(address_family, socket_type::stream, protocol_type::tcp);
}

tcp_client::tcp_client(const xtd::string& hostname, uint16 port) : data_(xtd::new_sptr<tcp_client::data>()) {
  connect(hostname, port);
}

tcp_client::~tcp_client() {
  if (data_.use_count() == 1) close();
}

auto tcp_client::available() const -> usize {
  return data_->client_socket.available();
}

auto tcp_client::client() const noexcept -> socket {
  return data_->client_socket;
}

auto tcp_client::client(const socket& value) noexcept -> tcp_client& {
  data_->client_socket = value;
  active(data_->client_socket.connected());
  return *this;
}

auto tcp_client::connected() const noexcept -> bool {
  return data_->client_socket.connected();
}

auto tcp_client::exclusive_address_use() const -> bool {
  return data_->client_socket.exclusive_address_use();
}

auto tcp_client::exclusive_address_use(bool value) -> tcp_client& {
  data_->client_socket.exclusive_address_use(value);
  return *this;
}

auto tcp_client::linger_state() const -> linger_option {
  return data_->client_socket.linger_state();
}

auto tcp_client::linger_state(const linger_option& value) -> tcp_client& {
  data_->client_socket.linger_state(value);
  return *this;
}

auto tcp_client::no_delay() const -> bool {
  return data_->client_socket.no_delay();
}

auto tcp_client::no_delay(bool value) -> tcp_client& {
  data_->client_socket.no_delay(value);
  return *this;
}

auto tcp_client::receive_buffer_size() const -> usize {
  return data_->client_socket.receive_buffer_size();
}

auto tcp_client::receive_buffer_size(usize value) -> tcp_client& {
  data_->client_socket.receive_buffer_size(value);
  return *this;
}

auto tcp_client::receive_timeout() const -> int32 {
  return data_->client_socket.receive_timeout();
}

auto tcp_client::receive_timeout(int32 value) -> tcp_client& {
  data_->client_socket.receive_timeout(value);
  return *this;
}

auto tcp_client::send_buffer_size() const -> usize {
  return data_->client_socket.send_buffer_size();
}

auto tcp_client::send_buffer_size(usize value) -> tcp_client& {
  data_->client_socket.send_buffer_size(value);
  return *this;
}

auto tcp_client::send_timeout() const -> int32 {
  return data_->client_socket.send_timeout();
}

auto tcp_client::send_timeout(int32 value) -> tcp_client& {
  data_->client_socket.send_timeout(value);
  return *this;
}

auto tcp_client::begin_connect(const ip_address& address, uint16 port, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  return data_->client_socket.begin_connect(address, port, callback, state);
}

auto tcp_client::begin_connect(const array<ip_address>& addresses, uint16 port, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  return data_->client_socket.begin_connect(addresses, port, callback, state);
}

auto tcp_client::begin_connect(const xtd::string& host, uint16 port, async_callback callback, const any_object& state) -> sptr<iasync_result> {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  return data_->client_socket.begin_connect(host, port, callback, state);
}

auto tcp_client::close() -> void {
  data_->active = false;
  data_->client_socket = socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
  data_->client_socket.set_socket_option(socket_option_level::socket, socket_option_name::reuse_address, true);
}

auto tcp_client::connect(const xtd::net::ip_end_point& remote_end_point) -> void {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  data_->client_socket.connect(remote_end_point);
  active(true);
}

auto tcp_client::connect(const ip_address& ip_address, uint16 port) -> void {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  data_->client_socket.connect(ip_address, port);
  active(true);
}

auto tcp_client::connect(const xtd::string& host_name, uint16 port) -> void {
  if (active()) throw_helper::throws(exception_case::socket, socket_error::is_connected);
  data_->client_socket.connect(dns::get_host_addresses(host_name), port);
  active(true);
}

auto tcp_client::end_connect(sptr<iasync_result> async_result) -> void {
  data_->client_socket.end_connect(async_result);
  active(true);
}

auto tcp_client::equals(const object& obj) const noexcept -> bool {
  return is<tcp_client>(obj) && equals(static_cast<const tcp_client&>(obj));
}

auto tcp_client::equals(const tcp_client& other) const noexcept -> bool {
  return data_ == other.data_;
}

auto tcp_client::get_stream() const -> network_stream {
  if (!data_->client_socket.connected()) throw_helper::throws(exception_case::socket, socket_error::not_connected);
  return network_stream(data_->client_socket, true);
}

auto tcp_client::active() const noexcept -> bool {
  return data_->active;
}

auto tcp_client::active(bool value) noexcept -> tcp_client& {
  data_->active = value;
  return *this;
}

tcp_client::tcp_client(const socket& socket) : data_(new_sptr<tcp_client::data>()) {
  data_->client_socket = socket;
  active(data_->client_socket.connected());
}
