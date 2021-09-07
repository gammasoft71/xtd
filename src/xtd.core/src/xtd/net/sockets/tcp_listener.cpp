#include "../../../../include/xtd/net/sockets/tcp_listener.h"
#include "../../../../include/xtd/net/sockets/socket_exception.h"
#include "../../../../include/xtd/invalid_operation_exception.h"
#include "../../../../include/xtd/as.h"
#include "../../../../include/xtd/is.h"
#include <thread>

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

std::shared_ptr<xtd::iasync_result> tcp_listener::begin_accept_socket(xtd::async_callback callback, const std::any& state) {
  std::shared_ptr<async_result_accept_socket> ar = make_shared<async_result_accept_socket>(state);
  ar->async_mutex().lock();
  thread operation_thread([](tcp_listener* listener, std::shared_ptr<async_result_accept_socket> ar, xtd::async_callback callback) {
    try {
      ar->socket_ = listener->accept_socket();
      ar->is_completed_ = true;
      ar->async_mutex().unlock();
      callback(ar);
    } catch(...) {
      ar->exception_ = current_exception();
    }
  }, this, ar, callback);
  operation_thread.detach();
  return ar;
}

std::shared_ptr<xtd::iasync_result> tcp_listener::begin_accept_tcp_client(xtd::async_callback callback, const std::any& state) {
  std::shared_ptr<async_result_accept_tcp_client> ar = make_shared<async_result_accept_tcp_client>(state);
  ar->async_mutex().lock();
  thread operation_thread([](tcp_listener* listener, std::shared_ptr<async_result_accept_tcp_client> ar, xtd::async_callback callback) {
    try {
      ar->tcp_client_ = listener->accept_tcp_client();
      ar->is_completed_ = true;
      ar->async_mutex().unlock();
      callback(ar);
    } catch(...) {
      ar->exception_ = current_exception();
    }
  }, this, ar, callback);
  operation_thread.detach();
  return ar;
}

tcp_listener tcp_listener::create(uint16_t port) {
  return tcp_listener(ip_address::any, port);
}

xtd::net::sockets::socket tcp_listener::end_accept_socket(std::shared_ptr<xtd::iasync_result> async_result) {
  if (async_result == nullptr) throw argument_null_exception(csf_);
  if (!is<async_result_accept_socket>(async_result)) throw argument_exception(csf_);
  lock_guard<shared_mutex> lock(async_result->async_mutex());
  if (as<async_result_accept_socket>(async_result)->exception_) rethrow_exception(as<async_result_accept_socket>(async_result)->exception_);
  return as<async_result_accept_socket>(async_result)->socket_;
}

xtd::net::sockets::tcp_client tcp_listener::end_accept_tcp_client(std::shared_ptr<xtd::iasync_result> async_result) {
  if (async_result == nullptr) throw argument_null_exception(csf_);
  if (!is<async_result_accept_tcp_client>(async_result)) throw argument_exception(csf_);
  lock_guard<shared_mutex> lock(async_result->async_mutex());
  if (as<async_result_accept_tcp_client>(async_result)->exception_) rethrow_exception(as<async_result_accept_tcp_client>(async_result)->exception_);
  return as<async_result_accept_tcp_client>(async_result)->tcp_client_;
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
