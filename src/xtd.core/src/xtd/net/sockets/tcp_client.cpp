#include "../../../../include/xtd/net/sockets/tcp_client.h"
#include "../../../../include/xtd/net/sockets/socket.h"
#include "../../../../include/xtd/net/sockets/socket_exception.h"
#include "../../../../include/xtd/net/dns.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

struct tcp_client::data {
  socket client_socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
  bool active = false;
};

tcp_client::tcp_client() {
  data_ = make_shared<data>();
}

tcp_client::tcp_client(const ip_end_point& local_end_point) {
  data_ = make_shared<data>();
  data_->client_socket.bind(local_end_point);
}

tcp_client::tcp_client(address_family address_family) {
  if (address_family != address_family::inter_network && address_family != address_family::inter_network_v6) throw argument_exception(csf_);
  data_ = make_shared<data>();
  data_->client_socket = socket(address_family, socket_type::stream, protocol_type::tcp);
}

tcp_client::tcp_client(const xtd::ustring& hostname, uint16_t port) {
  data_ = make_shared<data>();
  connect(hostname, port);
}

tcp_client::~tcp_client() {
  if (data_.use_count() == 1) close();
}

size_t tcp_client::available() const {
  return data_->client_socket.available();
}

socket tcp_client::client() const noexcept {
  return data_->client_socket;
}

tcp_client& tcp_client::client(const socket& value) noexcept {
  data_->client_socket = value;
  active(data_->client_socket.connected());
  return *this;
}

bool tcp_client::connected() const noexcept {
  return data_->client_socket.connected();
}

bool tcp_client::exclusive_address_use() const {
  return data_->client_socket.exclusive_address_use();
}

tcp_client& tcp_client::exclusive_address_use(bool value) {
  data_->client_socket.exclusive_address_use(value);
  return *this;
}

linger_option tcp_client::linger_state() const {
  return data_->client_socket.linger_state();
}

tcp_client& tcp_client::linger_state(const linger_option& value) {
  data_->client_socket.linger_state(value);
  return *this;
}

bool tcp_client::no_delay() const {
  return data_->client_socket.no_delay();
}

tcp_client& tcp_client::no_delay(bool value) {
  data_->client_socket.no_delay(value);
  return *this;
}

size_t tcp_client::receive_buffer_size() const {
  return data_->client_socket.receive_buffer_size();
}

tcp_client& tcp_client::receive_buffer_size(size_t value) {
  data_->client_socket.receive_buffer_size(value);
  return *this;
}

int32_t tcp_client::receive_timeout() const {
  return data_->client_socket.receive_timeout();
}

tcp_client& tcp_client::receive_timeout(int32_t value) {
  data_->client_socket.receive_timeout(value);
  return *this;
}

size_t tcp_client::send_buffer_size() const {
  return data_->client_socket.send_buffer_size();
}

tcp_client& tcp_client::send_buffer_size(size_t value) {
  data_->client_socket.send_buffer_size(value);
  return *this;
}

int32_t tcp_client::send_timeout() const {
  return data_->client_socket.send_timeout();
}

tcp_client& tcp_client::send_timeout(int32_t value) {
  data_->client_socket.send_timeout(value);
  return *this;
}

std::shared_ptr<xtd::iasync_result> tcp_client::begin_connect(const xtd::net::ip_address& address, uint16_t port, xtd::async_callback callback, const std::any& state) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  return data_->client_socket.begin_connect(address, port, callback, state);
}

std::shared_ptr<xtd::iasync_result> tcp_client::begin_connect(const std::vector<xtd::net::ip_address>& addresses, uint16_t port, xtd::async_callback callback, const std::any& state) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  return data_->client_socket.begin_connect(addresses, port, callback, state);
}

std::shared_ptr<xtd::iasync_result> tcp_client::begin_connect(const xtd::ustring& host, uint16_t port, xtd::async_callback callback, const std::any& state) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  return data_->client_socket.begin_connect(host, port, callback, state);
}

void tcp_client::close() {
  data_->active = false;
  data_->client_socket = socket(address_family::inter_network, socket_type::stream, protocol_type::tcp);
  data_->client_socket.set_socket_option(socket_option_level::socket, socket_option_name::reuse_address, true);
}

void tcp_client::connect(const xtd::net::ip_end_point& remote_end_point) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  data_->client_socket.connect(remote_end_point);
  active(true);
}

void tcp_client::connect(const xtd::net::ip_address& ip_address, uint16_t port) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  data_->client_socket.connect(ip_address, port);
  active(true);
}

void tcp_client::connect(const xtd::ustring& host_name, uint16_t port) {
  if (active()) throw socket_exception(socket_error::is_connected, csf_);
  data_->client_socket.connect(dns::get_host_addresses(host_name), port);
  active(true);
}

void tcp_client::end_connect(std::shared_ptr<xtd::iasync_result> async_result) {
  data_->client_socket.end_connect(async_result);
  active(true);
}

network_stream tcp_client::get_stream() const {
  if (!data_->client_socket.connected()) throw socket_exception(socket_error::not_connected, csf_);
  return network_stream(data_->client_socket, true);
}

bool tcp_client::active() const noexcept {
  return data_->active;
}

tcp_client& tcp_client::active(bool value) noexcept {
  data_->active = value;
  return *this;
}

tcp_client::tcp_client(const xtd::net::sockets::socket& socket) {
  data_ = make_shared<data>();
  data_->client_socket = socket;
  active(data_->client_socket.connected());
}
