#include "../../../../include/xtd/bit_converter.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../../include/xtd/as.hpp"
#include "../../../../include/xtd/is.hpp"
#include "../../../../include/xtd/object_closed_exception.hpp"
#include "../../../../include/xtd/diagnostics/boolean_switch.hpp"
#include "../../../../include/xtd/diagnostics/debug.hpp"
#include "../../../../include/xtd/collections/generic/list.hpp"
#include "../../../../include/xtd/net/dns.hpp"
#include "../../../../include/xtd/net/ip_end_point.hpp"
#include "../../../../include/xtd/net/sockets/socket.hpp"
#include "../../../../include/xtd/net/sockets/socket_async_event_args.hpp"
#include "../../../../include/xtd/net/sockets/socket_error.hpp"
#include "../../../../include/xtd/net/sockets/socket_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <thread>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;
using namespace xtd::net;
using namespace xtd::net::sockets;

class __using_socket__ {
public:
  __using_socket__() {native::socket::startup();}
  ~__using_socket__() {native::socket::cleanup();}
} __using_socket_instance__;

namespace {
  boolean_switch show_debug_socket("socket", "Shows xtd::net::sockets:socket log", "false");
}

struct socket::data {
  xtd::net::sockets::address_family address_family = xtd::net::sockets::address_family::unspecified;
  bool will_block = true;
  bool is_connected = false;
  bool is_disconnected = false;
  intptr handle = 0;
  bool is_bound = false;
  bool is_listening = false;
  xtd::sptr<xtd::net::end_point> local_end_point;
  xtd::net::sockets::protocol_type protocol_type = xtd::net::sockets::protocol_type::unspecified;
  xtd::sptr<xtd::net::end_point> remote_end_point;
  xtd::net::sockets::socket_type socket_type = xtd::net::sockets::socket_type::unknown;
};

socket::socket() {
  data_ = xtd::new_sptr<socket::data>();
}
socket::socket(intptr handle)  {
  data_ = xtd::new_sptr<socket::data>();
  debug::write_if(show_debug_socket.enabled(), string::format("socket::socket(handle) : socket=[{}]", handle));
  if (handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[handle_invalid]");
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  }
  data_->handle = handle;
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
}

socket::socket(const socket_information& socket_information) {
  /*data_ = xtd::new_sptr<socket::data>();*/
  if (data_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::not_implemented);
}

socket::socket(xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) : socket(native::socket::get_os_supports_ip_v6() ? address_family::inter_network_v6 : address_family::inter_network, socket_type, protocol_type)  {
  if (data_->address_family == address_family::inter_network_v6) dual_mode(true);
}

socket::socket(xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) {
  data_ = xtd::new_sptr<socket::data>();
  data_->address_family = address_family;
  data_->socket_type = socket_type;
  data_->protocol_type = protocol_type;
  data_->handle = native::socket::create(static_cast<int32>(address_family), static_cast<int32>(socket_type), static_cast<int32>(protocol_type));
  debug::write_if(show_debug_socket.enabled(), string::format("socket::socket(handle) : socket=[{}] address_family=[{}] socket_type=[{}] protocol_type=[{}]", data_->handle, data_->address_family, data_->socket_type, data_->protocol_type));
  if (data_->handle == static_cast<intptr>(-1)) {
    debug::write_line_if(show_debug_socket.enabled(), string::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_());
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
}

socket::~socket() {
  if (data_.use_count() == 1) {
    if (data_->handle != 0 && data_->is_connected) shutdown(xtd::net::sockets::socket_shutdown::both);
    close();
  }
}

bool socket::equals(const object& obj) const noexcept {
  return is<socket>(obj) && equals(static_cast<const socket&>(obj));
}

bool socket::equals(const socket& other) const noexcept {
  return data_ == other.data_;
}

address_family socket::address_family() const noexcept {
  return data_->address_family;
}

size_t socket::available() const {
  if (data_->handle == 0) throw object_closed_exception {};
  auto available = native::socket::get_available(data_->handle);
  if (available == static_cast<size_t>(-1)) throw socket_exception(get_last_error_());
  return available;
}

bool socket::blocking() const {
  if (data_->handle == 0) throw object_closed_exception {};
  return data_->will_block;
}

socket& socket::blocking(bool value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (native::socket::set_blocking(data_->handle, value) != 0) throw socket_exception(get_last_error_());
  data_->will_block = value;
  return *this;
}

bool socket::connected() const noexcept {
  return data_->is_connected;
}

bool socket::dont_fragment() const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family != address_family::inter_network) throw not_supported_exception {};
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::dont_fragment));
}

socket& socket::dont_fragment(bool value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family != address_family::inter_network) throw not_supported_exception {};
  set_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::dont_fragment, value);
  return *this;
}

bool socket::dual_mode() const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family != address_family::inter_network_v6) throw not_supported_exception {};
  return !as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_v6_only));
}

socket& socket::dual_mode(bool value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family != address_family::inter_network_v6) throw not_supported_exception {};
  set_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_v6_only, !value);
  return *this;
}

bool socket::enable_broadcast() const {
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::broadcast));
}

socket& socket::enable_broadcast(bool value) {
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::broadcast, value);
  return *this;
}

bool socket::exclusive_address_use() const {
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::exclusive_address_use));
}

socket& socket::exclusive_address_use(bool value) {
  if (data_->is_bound) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::exclusive_address_use, value);
  return *this;
}

intptr socket::handle() const noexcept {
  return data_->handle;
}

bool socket::is_bound() const noexcept {
  return data_->is_bound;
}

xtd::net::sockets::linger_option socket::linger_state() const {
  return get_socket_linger_option();
}

socket& socket::linger_state(const xtd::net::sockets::linger_option& value) {
  set_socket_option(value);
  return *this;
}

xtd::sptr<xtd::net::end_point> socket::local_end_point() const {
  if (data_->handle == 0) throw object_closed_exception {};
  return data_->local_end_point;
}

bool socket::multicast_loopback() const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family != address_family::inter_network && data_->address_family != address_family::inter_network_v6) throw not_supported_exception {};
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::multicast_loopback));
}

socket& socket::multicast_loopback(bool value) {
  if (data_->address_family != address_family::inter_network && data_->address_family != address_family::inter_network_v6) throw not_supported_exception {};
  set_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::multicast_loopback, value);
  return *this;
}

bool socket::no_delay() const {
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::tcp, xtd::net::sockets::socket_option_name::no_delay));
}

socket& socket::no_delay(bool value) {
  set_socket_option(xtd::net::sockets::socket_option_level::tcp, xtd::net::sockets::socket_option_name::no_delay, value);
  return *this;
}

bool socket::os_supports_ip_v4() noexcept {
  return native::socket::get_os_supports_ip_v4();
}

bool socket::os_supports_ip_v6() noexcept {
  return native::socket::get_os_supports_ip_v6();
}

xtd::net::sockets::protocol_type socket::protocol_type() const noexcept {
  return data_->protocol_type;
}

size_t socket::receive_buffer_size() const {
  return as<size_t>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_buffer));
}

socket& socket::receive_buffer_size(size_t value) {
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_buffer, as<int32>(value));
  return *this;
}

int32 socket::receive_timeout() const {
  return get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_timeout);
}

socket& socket::receive_timeout(int32 value) {
  if (value < -1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_timeout, value);
  return *this;
}

xtd::sptr<xtd::net::end_point> socket::remote_end_point() const {
  if (data_->handle == 0) throw object_closed_exception {};
  return data_->remote_end_point;
}

size_t socket::send_buffer_size() const {
  return as<size_t>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_buffer));
}

socket& socket::send_buffer_size(size_t value) {
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_buffer, as<int32>(value));
  return *this;
}

int32 socket::send_timeout() const {
  return get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_timeout);
}

socket& socket::send_timeout(int32 value) {
  if (value < -1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (value >= 1 && value <= 499) value = 500;
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_timeout, value);
  return *this;
}

xtd::net::sockets::socket_type socket::socket_type() const noexcept {
  return data_->socket_type;
}

xtd::byte socket::ttl() const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family == address_family::inter_network) return as<xtd::byte>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::ip_time_to_live));
  if (data_->address_family == address_family::inter_network_v6) return as<xtd::byte>(get_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_time_to_live));
  throw not_supported_exception {};
}

socket& socket::ttl(xtd::byte value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->address_family == address_family::inter_network) set_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::ip_time_to_live, as<int32>(value));
  else if (data_->address_family == address_family::inter_network_v6) set_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_time_to_live, as<int32>(value));
  else throw not_supported_exception {};
  return *this;
}

socket socket::accept() {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->is_bound == false || data_->is_listening == false) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  
  auto address = socket_address {data_->address_family};
  auto new_socket_handle = native::socket::accept(data_->handle, address.bytes_);
  if (new_socket_handle == static_cast<intptr>(-1)) throw socket_exception(get_last_error_());
  
  auto new_socket = socket {new_socket_handle};
  new_socket.data_->address_family = data_->address_family;
  new_socket.data_->is_connected = true;
  new_socket.data_->local_end_point = data_->local_end_point->create(address);
  new_socket.data_->protocol_type = data_->protocol_type;
  new_socket.data_->socket_type = data_->socket_type;
  return new_socket;
}

bool socket::accept_async(xtd::net::sockets::socket_async_event_args& e) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->is_bound == false || data_->is_listening == false) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  
  auto operation_thread = std::thread {[](xtd::net::sockets::socket_async_event_args * e, xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) {
    if (e->accept_socket_.data_->address_family == xtd::net::sockets::address_family::unknown && e->accept_socket_.data_->socket_type == xtd::net::sockets::socket_type::unknown && e->accept_socket_.data_->protocol_type == xtd::net::sockets::protocol_type::unknown) {
      e->accept_socket_.data_->address_family = address_family;
      e->accept_socket_.data_->socket_type = socket_type;
      e->accept_socket_.data_->protocol_type = protocol_type;
      e->connect_socket_ = e->accept_socket_.accept();
      e->on_complete(*e);
    }
  }, &e, data_->address_family, data_->socket_type, data_->protocol_type};
  operation_thread.detach();
  return false;
}

xtd::sptr<xtd::iasync_result> socket::begin_accept(xtd::async_callback callback, const std::any& state) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->is_bound == false || data_->is_listening == false) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  
  auto ar = xtd::new_sptr<async_result_accept>(state);
  auto operation_thread = std::thread {[](socket s, xtd::sptr<async_result_accept> ar, xtd::async_callback callback) {
    try {
      ar->socket_ = s.accept();
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_connect(const xtd::net::ip_address& address, uint16 port, xtd::async_callback callback, const std::any& state) {
  return begin_connect_(xtd::new_uptr<ip_end_point>(ip_end_point(address, port)), callback, state);
}

xtd::sptr<xtd::iasync_result> socket::begin_connect(const array<xtd::net::ip_address>& addresses, uint16 port, xtd::async_callback callback, const std::any& state) {
  for (auto address : addresses) {
    if (data_->is_connected == false)
      return begin_connect(address, port, callback, state);
  }
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
}

xtd::sptr<xtd::iasync_result> socket::begin_connect(const xtd::string& host, uint16 port, xtd::async_callback callback, const std::any& state) {
  return begin_connect(dns::get_host_addresses(host), port, callback, state);
}

xtd::sptr<xtd::iasync_result> socket::begin_disconnect(bool reuse_socket, xtd::async_callback callback, const std::any& state) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw object_closed_exception {};
  
  auto ar = xtd::new_sptr<async_result_disconnect>(state);
  auto operation_thread = std::thread {[](socket s, bool reuse_socket, xtd::sptr<async_result_disconnect> ar, xtd::async_callback callback) {
    try {
      s.disconnect(reuse_socket);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, reuse_socket, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_receive(array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected);
  
  auto ar = xtd::new_sptr<async_result_receive>(state);
  auto operation_thread = std::thread {[](socket s, array<xtd::byte>* buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::sptr<async_result_receive> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_received_ = s.receive(*buffer, offset, size, socket_flags);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, &buffer, offset, size, socket_flags, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_receive(array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error_code, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected);
  
  auto ar = xtd::new_sptr<async_result_receive>(state);
  auto operation_thread = std::thread {[](socket s, array<xtd::byte>* buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::sptr<async_result_receive> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_received_ = s.receive(*buffer, offset, size, socket_flags, ar->error_code_);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, &buffer, offset, size, socket_flags, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_receive_from(array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  
  auto ar = xtd::new_sptr<async_result_receive_from>(state);
  auto operation_thread = std::thread {[](socket s, array<xtd::byte>* buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::sptr<async_result_receive_from> ar, xtd::async_callback callback) {
    try {
      ar->end_point_ = xtd::new_sptr<ip_end_point>();
      ar->number_of_bytes_received_ = s.receive_from(*buffer, offset, size, socket_flags, *ar->end_point_);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, &buffer, offset, size, socket_flags, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_receive_message_from(array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  
  auto ar = xtd::new_sptr<async_result_receive_message_from>(state);
  ar->socket_flags_ = socket_flags;
  auto operation_thread = std::thread {[](socket s, array<xtd::byte>* buffer, size_t offset, size_t size, xtd::sptr<async_result_receive_message_from> ar, xtd::async_callback callback) {
    try {
      ar->end_point_ = xtd::new_sptr<ip_end_point>();
      ar->number_of_bytes_received_ = s.receive_message_from(*buffer, offset, size, ar->socket_flags_, *ar->end_point_, ar->ip_packet_information_);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, &buffer, offset, size, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_send(const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected);
  
  auto ar = xtd::new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](socket s, const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::sptr<async_result_send> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = s.send(buffer, offset, size, socket_flags);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, buffer, offset, size, socket_flags, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_send(const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected);
  
  auto ar = xtd::new_sptr<async_result_send>(state);
  auto operation_thread = std::thread {[](socket s, const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::sptr<async_result_send> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = s.send(buffer, offset, size, socket_flags, ar->error_code_);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, buffer, offset, size, socket_flags, ar, callback};
  operation_thread.detach();
  return ar;
}

xtd::sptr<xtd::iasync_result> socket::begin_send_to(const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  
  auto ar = xtd::new_sptr<async_result_send_to>(state);
  auto operation_thread = std::thread {[](socket s, const array<xtd::byte>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point & remote_end_point, xtd::sptr<async_result_send_to> ar, xtd::async_callback callback) {
    try {
      ar->number_of_bytes_sent_ = s.send_to(buffer, offset, size, socket_flags, remote_end_point);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, buffer, offset, size, socket_flags, remote_end_point, ar, callback};
  operation_thread.detach();
  return ar;
}

void socket::close() {
  debug::write_if(show_debug_socket.enabled(), string::format("socket::close() : socket=[{}]", data_->handle));
  if (data_->handle != 0 && native::socket::destroy(data_->handle) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), string::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_());
  }
  data_->address_family = xtd::net::sockets::address_family::unspecified;
  data_->will_block = true;
  data_->is_connected = false;
  data_->handle = 0;
  data_->is_bound = false;
  data_->is_listening = false;
  data_->local_end_point.reset();
  data_->protocol_type = xtd::net::sockets::protocol_type::unspecified;
  data_->remote_end_point.reset();
  data_->socket_type = xtd::net::sockets::socket_type::unknown;
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
}

void socket::connect(const xtd::net::ip_address& address, uint16 port) {
  connect_(xtd::new_uptr<ip_end_point>(ip_end_point(address, port)));
}

void socket::connect(const array<ip_address>& addresses, uint16 port) {
  for (ip_address address : addresses) {
    if (data_->is_connected == false)
      connect(address, port);
  }
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
}

void socket::connect(const xtd::string& host, uint16 port) {
  connect(dns::get_host_addresses(host), port);
}

void socket::disconnect(bool reuse_socket) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw object_closed_exception {};
  
  data_->is_bound = false;
  data_->is_connected = false;
  data_->is_disconnected = true;
  data_->remote_end_point.reset();
  
  if (reuse_socket == false) {
    close();
    data_->handle = native::socket::create(static_cast<int32>(data_->address_family), static_cast<int32>(data_->socket_type), static_cast<int32>(data_->protocol_type));
    if (data_->handle == static_cast<intptr>(-1)) throw socket_exception(get_last_error_());
  }
}

socket socket::end_accept(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_accept>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_accept>(ar)->exception_) rethrow_exception(as<async_result_accept>(ar)->exception_);
  return as<socket>(as<async_result_accept>(ar)->socket_);
}

void socket::end_connect(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_connect>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_connect>(ar)->exception_) rethrow_exception(as<async_result_connect>(ar)->exception_);
}

void socket::end_disconnect(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_disconnect>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_disconnect>(ar)->exception_) rethrow_exception(as<async_result_disconnect>(ar)->exception_);
}

size_t socket::end_receive(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_receive>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_receive>(ar)->exception_) rethrow_exception(as<async_result_receive>(ar)->exception_);
  return as<async_result_receive>(ar)->number_of_bytes_received_;
}

size_t socket::end_receive(xtd::sptr<xtd::iasync_result> ar, xtd::net::sockets::socket_error& error) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_receive>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_receive>(ar)->exception_) rethrow_exception(as<async_result_receive>(ar)->exception_);
  error = as<async_result_receive>(ar)->error_code_;
  return as<async_result_receive>(ar)->number_of_bytes_received_;
}

size_t socket::end_receive_from(xtd::sptr<xtd::iasync_result> ar, xtd::sptr<xtd::net::end_point>& end_point) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_receive_from>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_receive_from>(ar)->exception_) rethrow_exception(as<async_result_receive_from>(ar)->exception_);
  end_point = as<async_result_receive_from>(ar)->end_point_;
  return as<async_result_receive_from>(ar)->number_of_bytes_received_;
}

size_t socket::end_receive_message_from(xtd::sptr<xtd::iasync_result> ar, xtd::net::sockets::socket_flags& socket_flags, xtd::sptr<xtd::net::end_point>& end_point, ip_packet_information& ip_packet_information) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_receive_message_from>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_receive_message_from>(ar)->exception_) rethrow_exception(as<async_result_receive_message_from>(ar)->exception_);
  end_point = as<async_result_receive_message_from>(ar)->end_point_;
  socket_flags = as<async_result_receive_message_from>(ar)->socket_flags_;
  ip_packet_information = as<async_result_receive_message_from>(ar)->ip_packet_information_;
  return as<async_result_receive_message_from>(ar)->number_of_bytes_received_;
}

size_t socket::end_send(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_send>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_send>(ar)->exception_) rethrow_exception(as<async_result_send>(ar)->exception_);
  return as<async_result_send>(ar)->number_of_bytes_sent_;
}

size_t socket::end_send(xtd::sptr<xtd::iasync_result> ar, xtd::net::sockets::socket_error& error) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_send>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_send>(ar)->exception_) rethrow_exception(as<async_result_send>(ar)->exception_);
  error = as<async_result_send>(ar)->error_code_;
  return as<async_result_send>(ar)->number_of_bytes_sent_;
}

size_t socket::end_send_to(xtd::sptr<xtd::iasync_result> ar) {
  if (ar == nullptr) throw argument_null_exception {};
  if (!is<async_result_send_to>(ar)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  ar->async_wait_handle().wait_one();
  if (as<async_result_send_to>(ar)->exception_) rethrow_exception(as<async_result_send_to>(ar)->exception_);
  return as<async_result_send_to>(ar)->number_of_bytes_sent_;
}

size_t socket::get_raw_socket_option(int32 socket_option_level, int32 socket_option_name, intptr option_value, size_t size_option_value) const {
  if (data_->handle == 0) throw object_closed_exception {};
  auto size = 0_z;
  if (native::socket::get_raw_socket_option(data_->handle, socket_option_level, socket_option_name, option_value, size) != 0) throw socket_exception(get_last_error_());
  return size;
}

int32 socket::get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  auto result = 0;
  auto size = sizeof(int32);
  if (native::socket::get_socket_option(data_->handle, as<int32>(socket_option_level), as<int32>(socket_option_name), reinterpret_cast<intptr>(&result), size) != 0) throw socket_exception(get_last_error_());
  return result;
}

xtd::net::sockets::linger_option socket::get_socket_linger_option() const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  auto enabled = false;
  auto linger_time = 0_u32;
  if (native::socket::get_socket_linger_option(data_->handle, enabled, linger_time) != 0) throw socket_exception(get_last_error_());
  return linger_option(enabled, linger_time);
}

xtd::net::sockets::multicast_option socket::get_socket_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  auto multicast_address = 0_u32;
  auto interface_index = 0_u32;
  if (native::socket::get_socket_multicast_option(data_->handle, static_cast<int32>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_());
  //if (!bit_converter::is_little_endian) {
  //  //multicast_address = ((multicast_address << 24) | ((multicast_address & 0x0000FF00) << 8) | ((multicast_address >> 8) & 0x0000FF00) | (multicast_address >> 24));
  //  //interface_index = ((interface_index << 24) | ((interface_index & 0x0000FF00) << 8) | ((interface_index >> 8) & 0x0000FF00) | (interface_index >> 24));
  //}
  multicast_address = ip_address::network_to_host_order(multicast_address);
  interface_index = ip_address::network_to_host_order(interface_index);
  return multicast_option(ip_address(multicast_address), interface_index);
}

xtd::net::sockets::ip_v6_multicast_option socket::get_socket_ip_v6_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  auto multicast_address = array<xtd::byte> {};
  auto interface_index = 0_u64;
  if (native::socket::get_socket_ip_v6_multicast_option(data_->handle, static_cast<int32>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_());
  return ip_v6_multicast_option(ip_address(multicast_address), interface_index);
}

size_t socket::io_control(int32 io_control_code, array<xtd::byte>& option_in_value, array<xtd::byte>& option_out_value) {
  if (data_->handle == 0) throw object_closed_exception {};
  auto result = native::socket::io_control(data_->handle, io_control_code, option_in_value, option_out_value);
  if (result == -1)  throw socket_exception(get_last_error_());
  return static_cast<size_t>(result);
}

size_t socket::io_control(xtd::net::sockets::io_control_code io_control_code, array<xtd::byte>& option_in_value, array<xtd::byte>& option_out_value) {
  return io_control(static_cast<int32>(io_control_code), option_in_value, option_out_value);
}

void socket::listen(size_t backlog) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->is_bound == false) throw socket_exception(socket_error::not_connected);
  if (native::socket::listen(data_->handle, backlog) != 0) throw socket_exception(get_last_error_());
  data_->is_listening = true;
}

void socket::listen() {
  listen(static_cast<size_t>(-1));
}

bool socket::poll(int32 micro_seconds, xtd::net::sockets::select_mode mode) {
  if (data_->handle == 0) throw object_closed_exception {};
  auto result = native::socket::poll(data_->handle, micro_seconds, static_cast<int32>(mode));
  if (result == -1) throw socket_exception(get_last_error_());
  return result;
}

size_t socket::receive(array<xtd::byte>& buffer) {
  return receive(buffer, 0, buffer.size(), socket_flags::none);
}

size_t socket::receive(array<xtd::byte>& buffer, socket_flags socket_flags) {
  return receive(buffer, 0, buffer.size(), socket_flags);
}

size_t socket::receive(array<xtd::byte>& buffer, size_t size, socket_flags socket_flags) {
  return receive(buffer, 0, size, socket_flags);
}

size_t socket::receive(array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags) {
  socket_error error_code = socket_error::success;
  auto number_of_bytes_received = receive(buffer, offset, size, socket_flags, error_code);
  if (error_code != socket_error::success) throw socket_exception(error_code);
  return number_of_bytes_received;
}

size_t socket::receive(array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags, socket_error& error_code) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected);
  
  auto number_of_bytes_received = native::socket::receive(data_->handle, buffer, offset, size, static_cast<int32>(socket_flags));
  error_code = number_of_bytes_received > 0 ? get_last_error_() : socket_error::success;
  return static_cast<size_t>(number_of_bytes_received);
}

size_t socket::receive_from(array<xtd::byte>& buffer, end_point& remote_end_point) {
  return receive_from(buffer, 0, buffer.size(), socket_flags::none, remote_end_point);
}

size_t socket::receive_from(array<xtd::byte>& buffer, socket_flags socket_flags, end_point& remote_end_point) {
  return receive_from(buffer, 0, buffer.size(), socket_flags, remote_end_point);
}

size_t socket::receive_from(array<xtd::byte>& buffer, size_t size, socket_flags socket_flags, end_point& remote_end_point) {
  return receive_from(buffer, 0, size, socket_flags, remote_end_point);
}

size_t socket::receive_from(array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags, end_point& remote_end_point) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  auto socket_address = remote_end_point.serialize();
  auto number_of_bytes_received = native::socket::receive_from(data_->handle, buffer, offset, size, static_cast<int32>(socket_flags), socket_address.bytes_);
  if (number_of_bytes_received == -1) throw socket_exception(get_last_error_());
  return static_cast<size_t>(number_of_bytes_received);
}

size_t socket::receive_message_from(array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags, end_point& remote_end_point, ip_packet_information& ip_packet_information) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  auto socket_address = remote_end_point.serialize();
  auto number_of_bytes_received = native::socket::receive_from(data_->handle, buffer, offset, size, static_cast<int32>(socket_flags), socket_address.bytes_);
  if (number_of_bytes_received == -1) throw socket_exception(get_last_error_());
  
  if (data_->address_family == address_family::inter_network)
    ip_packet_information.address_ = ip_address(array<xtd::byte>(socket_address.bytes_.begin() + 4, socket_address.bytes_.begin() + 8));
  if (data_->address_family == address_family::inter_network_v6)
    ip_packet_information.address_ = ip_address(array<xtd::byte>(socket_address.bytes_.begin() + 8, socket_address.bytes_.begin() + 24), bit_converter::to_uint32(socket_address.bytes_, 25));
    
  return static_cast<size_t>(number_of_bytes_received);
}

size_t socket::select(ilist<socket>& check_read, ilist<socket>& check_write, ilist<socket>& check_error, int32 microseconds) {
  if (check_read.count() == 0 && check_write.count() == 0 && check_error.count() == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  
  auto check_read_handles = list<intptr> {};
  std::for_each(check_read.begin(), check_read.end(), [&](auto s) {check_read_handles.add(s.data_->handle);});
  
  auto check_write_handles = list<intptr> {};
  std::for_each(check_write.begin(), check_write.end(), [&](auto s) {check_write_handles.add(s.data_->handle);});
  
  auto check_error_handles = list<intptr> {};
  std::for_each(check_error.begin(), check_error.end(), [&](auto s) {check_error_handles.add(s.data_->handle);});
  
  auto status = native::socket::select(check_read_handles, check_write_handles, check_error_handles, microseconds);
  if (status < 0) throw socket_exception(get_last_error_());
  
  auto update_check_sockets = [](auto & sockets, auto & handles) {
    for (auto i = 0_z, j = 0_z; i < handles.size() && j < sockets.count(); ++i, ++j)
      if (handles[i] == 0)
        sockets.remove_at(j--);
  };
  
  update_check_sockets(check_read, check_read_handles);
  update_check_sockets(check_write, check_write_handles);
  update_check_sockets(check_error, check_error_handles);
  
  return static_cast<size_t>(status);
}

size_t socket::send(const array<xtd::byte>& buffer) {
  return send(buffer, 0, buffer.size(), socket_flags::none);
}

size_t socket::send(const array<xtd::byte>& buffer, socket_flags socket_flags) {
  return send(buffer, 0, buffer.size(), socket_flags);
}

size_t socket::send(const array<xtd::byte>& buffer, size_t size, socket_flags socket_flags) {
  return send(buffer, 0, size, socket_flags);
}

size_t socket::send(const array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags) {
  auto error_code = socket_error::success;
  auto number_of_bytes_sent = send(buffer, offset, size, socket_flags, error_code);
  if (error_code != socket_error::success) throw socket_exception(get_last_error_());
  return number_of_bytes_sent;
}

size_t socket::send(const array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags, socket_error& error_code) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  auto number_of_bytes_sent = native::socket::send(data_->handle, buffer, offset, size, static_cast<int32>(socket_flags));
  error_code = number_of_bytes_sent == -1 ? get_last_error_() : socket_error::success;
  return static_cast<size_t>(number_of_bytes_sent);
}

size_t socket::send_to(const array<xtd::byte>& buffer, const end_point& remote_end_point) {
  return send_to(buffer, 0, buffer.size(), socket_flags::none, remote_end_point);
}

size_t socket::send_to(const array<xtd::byte>& buffer, socket_flags socket_flags, const end_point& remote_end_point) {
  return send_to(buffer, 0, buffer.size(), socket_flags, remote_end_point);
}

size_t socket::send_to(const array<xtd::byte>& buffer, size_t size, socket_flags socket_flags, const end_point& remote_end_point) {
  return send_to(buffer, 0, size, socket_flags, remote_end_point);
}

size_t socket::send_to(const array<xtd::byte>& buffer, size_t offset, size_t size, socket_flags socket_flags, const end_point& remote_end_point) {
  if (offset + size > buffer.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->handle == 0) throw object_closed_exception {};
  auto socket_address = remote_end_point.serialize();
  auto number_of_bytes_sent = native::socket::send_to(data_->handle, buffer, offset, size, static_cast<int32>(socket_flags), socket_address.bytes_);
  if (number_of_bytes_sent == -1) throw socket_exception(get_last_error_());
  return static_cast<int32>(number_of_bytes_sent);
}

void socket::set_ip_protection_level(ip_protection_level level) {
  if (level == ip_protection_level::unspecified) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (data_->address_family == address_family::inter_network_v6) set_socket_option(socket_option_level::ip_v6, socket_option_name::ip_protection_level, static_cast<int32>(level));
  else if (data_->address_family == address_family::inter_network) set_socket_option(socket_option_level::ip, socket_option_name::ip_protection_level, static_cast<int32>(level));
  else throw not_supported_exception {};
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value) {
  set_socket_option(socket_option_level, socket_option_name, as<int32>(option_value));
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32 option_value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (native::socket::set_socket_option(data_->handle, static_cast<int32>(socket_option_level), static_cast<int32>(socket_option_name), reinterpret_cast<intptr>(&option_value), sizeof(int32)) != 0) throw socket_exception(get_last_error_());
}

void socket::set_socket_option(xtd::net::sockets::linger_option option_value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported);
  if (native::socket::set_socket_linger_option(data_->handle, option_value.enabled(), option_value.linger_time()) != 0) throw socket_exception(get_last_error_());
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, const xtd::net::sockets::multicast_option& option_value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  auto multicast_address = option_value.group().address_or_scope_id_;
  auto interface_index = option_value.local_address() != ip_address::none ? option_value.local_address().address_or_scope_id_ : ip_address::host_to_network_order(option_value.interface_index());
  if (native::socket::set_socket_multicast_option(data_->handle, static_cast<int32>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_());
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, const xtd::net::sockets::ip_v6_multicast_option& option_value) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (native::socket::set_socket_ip_v6_multicast_option(data_->handle, static_cast<int32>(socket_option_name), option_value.group().get_address_bytes(), option_value.interface_index()) != 0) throw socket_exception(get_last_error_());
}

void socket::set_raw_socket_option(int32 socket_option_level, int32 socket_option_name, intptr option_value, size_t option_value_size) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (native::socket::set_raw_socket_option(data_->handle, socket_option_level, socket_option_name, reinterpret_cast<intptr>(&option_value), option_value_size) != 0) throw socket_exception(get_last_error_());
}

void socket::shutdown(socket_shutdown how) {
  if (data_->handle == 0) throw object_closed_exception {};
  if (native::socket::shutdown(data_->handle, static_cast<int32>(how)) != 0) throw socket_exception(get_last_error_());
  data_->is_connected = false;
  data_->is_disconnected = true;
}

xtd::sptr<xtd::iasync_result> socket::begin_connect_(xtd::sptr<xtd::net::end_point> remote_end_point, xtd::async_callback callback, const std::any& state) {
  if (data_->handle == 0) throw object_closed_exception {};
  
  auto ar = xtd::new_sptr<async_result_connect>(state);
  auto operation_thread = std::thread {[](socket s, xtd::sptr<xtd::net::end_point> remote_end_point, xtd::sptr<async_result_connect> ar, xtd::async_callback callback) {
    try {
      s.connect_(remote_end_point);
      ar->is_completed_ = true;
      as<xtd::threading::manual_reset_event>(ar->async_wait_handle()).set();
      callback(ar);
    } catch (...) {
      ar->error_code_ = s.get_last_error_();
      ar->exception_ = std::current_exception();
    }
  }, *this, remote_end_point, ar, callback};
  operation_thread.detach();
  return ar;
}

void socket::bind_(xtd::sptr<xtd::net::end_point> local_end_point) {
  debug::write_if(show_debug_socket.enabled(), string::format("socket::bind() : socket=[{}] local_end_point=[{}]", data_->handle, *local_end_point));
  if (data_->handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[object_close]");
    throw object_closed_exception {};
  }
  data_->local_end_point = local_end_point;
  auto socket_address = data_->local_end_point->serialize();
  if (native::socket::bind(data_->handle, socket_address.bytes_) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), string::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_());
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
  data_->is_bound = true;
}

void socket::connect_(xtd::sptr<xtd::net::end_point> remote_end_point) {
  debug::write_if(show_debug_socket.enabled(), string::format("socket::connect() : socket=[{}] remote_end_point=[{}]", data_->handle, *remote_end_point));
  if (data_->handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[object_close]");
    throw object_closed_exception {};
  }
  
  data_->remote_end_point = remote_end_point;
  auto socket_address = data_->remote_end_point->serialize();
  if (native::socket::connect(data_->handle, socket_address.bytes_) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), string::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_());
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
  data_->is_connected = true;
}

socket_error socket::get_last_error_() {
  return static_cast<socket_error>(native::socket::get_last_error());
}
