#include "../../../../include/xtd/net/sockets/tcp_listener.hpp"
#include "../../../../include/xtd/net/sockets/socket_exception.hpp"
#include "../../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../../include/xtd/runtime/exception_services/exception_dispatch_info.hpp"
#include "../../../../include/xtd/as.hpp"
#include "../../../../include/xtd/is.hpp"
#include <thread>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::runtime::exception_services;

struct tcp_listener::data {
  socket server_socket {address_family::inter_network, socket_type::stream, protocol_type::tcp};
  ip_end_point local_end_point {};
  bool active = false;
};

tcp_listener::tcp_listener(const ip_end_point& local_end_point) : data_(new_sptr<tcp_listener::data>()) {
  data_->local_end_point = local_end_point;
  data_->server_socket = socket(data_->local_end_point.address_family(), socket_type::stream, protocol_type::tcp);
  data_->server_socket.set_socket_option(socket_option_level::socket, socket_option_name::reuse_address, true);
}

tcp_listener::tcp_listener(const ip_address& ip_address, uint16 port) : tcp_listener(ip_end_point(ip_address, port)) {
}

tcp_listener::~tcp_listener() {
  if (data_.use_count() == 1) stop();
}

auto tcp_listener::exclusive_address_use() const -> bool {
  return data_->server_socket.exclusive_address_use();
}

auto tcp_listener::exclusive_address_use(bool value) -> tcp_listener& {
  if (active()) throw_helper::throws(exception_case::invalid_operation);
  data_->server_socket.exclusive_address_use(value);
  return *this;
}

auto tcp_listener::local_end_point() const noexcept -> const end_point& {
  return data_->local_end_point;
}

auto tcp_listener::server() const noexcept -> socket {
  return data_->server_socket;
}

auto tcp_listener::accept_socket() -> socket {
  if (!active()) throw_helper::throws(exception_case::invalid_operation);
  return data_->server_socket.accept();
}

auto tcp_listener::accept_tcp_client() -> tcp_client {
  if (!active()) throw_helper::throws(exception_case::invalid_operation);
  return tcp_client(data_->server_socket.accept());
}

auto tcp_listener::begin_accept_socket(async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_accept_socket>(state);
  auto operation_thread = std::thread {[](tcp_listener * listener, sptr<async_result_accept_socket> ar, async_callback callback) {
    try {
      ar->socket_ = listener->accept_socket();
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, ar, callback};
  operation_thread.detach();
  return ar;
}

auto tcp_listener::begin_accept_tcp_client(async_callback callback, const any_object& state) -> sptr<iasync_result> {
  auto ar = new_sptr<async_result_accept_tcp_client>(state);
  auto operation_thread = std::thread {[](tcp_listener * listener, sptr<async_result_accept_tcp_client> ar, async_callback callback) {
    try {
      ar->tcp_client_ = listener->accept_tcp_client();
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->exception_ = std::current_exception();
    }
  }, this, ar, callback};
  operation_thread.detach();
  return ar;
}

auto tcp_listener::create(uint16 port) -> tcp_listener {
  return tcp_listener(ip_address::any, port);
}

auto tcp_listener::end_accept_socket(sptr<iasync_result> async_result) -> socket {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_accept_socket>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_accept_socket>(async_result)->exception_) rethrow_exception(as<async_result_accept_socket>(async_result)->exception_);
  return as<async_result_accept_socket>(async_result)->socket_;
}

auto tcp_listener::end_accept_tcp_client(sptr<iasync_result> async_result) -> tcp_client {
  if (async_result == nullptr) throw_helper::throws(exception_case::argument_null);
  if (!is<async_result_accept_tcp_client>(async_result)) throw_helper::throws(exception_case::argument);
  async_result->async_wait_handle().wait_one();
  if (as<async_result_accept_tcp_client>(async_result)->exception_) rethrow_exception(as<async_result_accept_tcp_client>(async_result)->exception_);
  return as<async_result_accept_tcp_client>(async_result)->tcp_client_;
}

auto tcp_listener::equals(const object& obj) const noexcept -> bool {
  return is<tcp_listener>(obj) && equals(static_cast<const tcp_listener&>(obj));
}

auto tcp_listener::equals(const tcp_listener& other) const noexcept -> bool {
  return data_ == other.data_;
}

auto tcp_listener::pending() -> bool {
  if (!active()) throw_helper::throws(exception_case::invalid_operation);
  return data_->server_socket.poll(0, select_mode::select_read);
}

auto tcp_listener::start() -> void {
  start(static_cast<size_t>(-1));
}

auto tcp_listener::start(size_t backlog) -> void {
  if (!active()) {
    data_->server_socket.bind(data_->local_end_point);
    try {
      data_->server_socket.listen(backlog);
    } catch (const socket_exception& e) {
      stop();
      exception_dispatch_info::rethrow(e);
    }
  }
  data_->active = true;
}

auto tcp_listener::stop() -> void {
  bool eau = data_->server_socket.exclusive_address_use();
  data_->active = false;
  data_->server_socket = socket(data_->local_end_point.address_family(), socket_type::stream, protocol_type::tcp);
  data_->server_socket.exclusive_address_use(eau);
}

auto tcp_listener::active() const noexcept -> bool {
  return data_->active;
}
