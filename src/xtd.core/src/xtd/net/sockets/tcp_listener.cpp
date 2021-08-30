#include "../../../../include/xtd/net/sockets/tcp_listener.h"
#include "../../../../include/xtd/net/sockets/socket_exception.h"
#include "../../../../include/xtd/invalid_operation_exception.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

struct tcp_listener::data {
  socket server_socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
  ip_end_point local_end_point;
  bool active = false;
};

tcp_listener::tcp_listener(const ip_end_point& local_end_point) {
  data_ = make_shared<data>();
  data_->local_end_point = local_end_point;
  data_->server_socket = socket(data_->local_end_point.address_family(), socket_type::stream, protocol_type::tcp);
  data_->server_socket.set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::reuse_address, true);
}

tcp_listener::tcp_listener(const ip_address& ip_address, uint16_t port) : tcp_listener(ip_end_point(ip_address, port)) {
}

tcp_listener::~tcp_listener() {
  if (data_.use_count() == 1) stop();
}

bool tcp_listener::exclusive_address_use() const {
  return data_->server_socket.exclusive_address_use();
}

tcp_listener& tcp_listener::exclusive_address_use(bool value) {
  if (active()) throw invalid_operation_exception(csf_);
  data_->server_socket.exclusive_address_use(value);
  return *this;
}

const xtd::net::end_point& tcp_listener::local_end_point() const noexcept {
  return data_->local_end_point;
}

xtd::net::sockets::socket tcp_listener::server() const noexcept {
  return data_->server_socket;
}

xtd::net::sockets::socket tcp_listener::accept_socket() {
  if (!active()) throw invalid_operation_exception(csf_);
  return data_->server_socket.accept();
}

xtd::net::sockets::tcp_client tcp_listener::accept_tcp_client() {
  if (!active()) throw invalid_operation_exception(csf_);
  return tcp_client(data_->server_socket.accept());
}

tcp_listener tcp_listener::create(uint16_t port) {
  return tcp_listener(ip_address::any, port);
}

bool tcp_listener::pending() {
  if (!active()) throw invalid_operation_exception(csf_);
  return data_->server_socket.poll(0, select_mode::select_read);
}

void tcp_listener::start() {
  start(static_cast<size_t>(-1));
}

void tcp_listener::start(size_t backlog) {
  if (!active()) {
    data_->server_socket.bind(data_->local_end_point);
    try {
      data_->server_socket.listen(backlog);
    } catch (const socket_exception& e) {
      stop();
      throw e;
    }
  }
  data_->active = true;
}

void tcp_listener::stop() {
  bool exclusive_address_use = data_->server_socket.exclusive_address_use();
  data_->active = false;
  data_->server_socket = socket(data_->local_end_point.address_family(), socket_type::stream, protocol_type::tcp);
  data_->server_socket.exclusive_address_use(exclusive_address_use);
}

bool tcp_listener::active() const noexcept {
  return data_->active;
}
