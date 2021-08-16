#include "../../../../include/xtd/object_closed_exception.h"
#include "../../../../include/xtd/net/sockets/socket.h"
#include "../../../../include/xtd/net/sockets/socket_error.h"
#include "../../../../include/xtd/net/sockets/socket_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

address_family socket::address_family() const noexcept {
  return data_->address_family;
}

size_t socket::available() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  auto available = native::socket::get_available(data_->handle);
  if (available == static_cast<size_t>(-1)) throw socket_exception(get_last_error(), csf_);
  return available;
}

bool socket::blocking() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  return data_->blocking;
}

socket& socket::blocking(bool value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::set_blocking(data_->handle, value) != 0) throw socket_exception(get_last_error(), csf_);
  data_->blocking = value;
  return *this;
}

bool socket::connected() const noexcept {
  return data_->connected;
}

bool socket::dont_fragment() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network) throw not_supported_exception(csf_);
  return as<bool>(get_socket_option<bool>(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::dont_fragment));
}

socket& socket::dont_fragment(bool value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network) throw not_supported_exception(csf_);
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::dont_fragment, value);
  return *this;
}

int32_t socket::get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  int32_t result = 0;
  size_t size  = sizeof(int32_t);
  if (native::socket::get_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), &result, size) != 0) throw socket_exception(get_last_error(), csf_);
  if (size > sizeof(int32_t))  throw argument_exception(csf_);
  return result;
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value) {
  set_socket_option(socket_option_level, socket_option_name, as<int32_t>(option_value));
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32_t option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  check_set_option_permisson(socket_option_level::socket, socket_option_name);
  if (native::socket::set_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), reinterpret_cast<intptr_t>(&option_value), sizeof(int32_t)) != 0) throw socket_exception(get_last_error(), csf_);
}

void socket::check_set_option_permisson(xtd::net::sockets::socket_option_level option_level, xtd::net::sockets::socket_option_name option_name) {
  if (!(option_level == socket_option_level::tcp && (option_name == socket_option_name::no_delay || option_name == socket_option_name::bsd_urgent || option_name == socket_option_name::expedited)) &&
      !(option_level == socket_option_level::udp && (option_name == socket_option_name::no_checksum || option_name == socket_option_name::checksum_coverage)) &&
      !(option_level == socket_option_level::socket && (option_name == socket_option_name::keep_alive || option_name == socket_option_name::linger || option_name == socket_option_name::dont_linger || option_name == socket_option_name::send_buffer || option_name == socket_option_name::receive_buffer || option_name == socket_option_name::send_timeout || option_name == socket_option_name::exclusive_address_use || option_name == socket_option_name::receive_timeout)) &&
      !(option_level == socket_option_level::ip_v6 && option_name == static_cast<socket_option_name>(23)))
    throw argument_exception(csf_);
}

socket_error socket::get_last_error() {
  return static_cast<socket_error>(native::socket::get_last_error());
}
