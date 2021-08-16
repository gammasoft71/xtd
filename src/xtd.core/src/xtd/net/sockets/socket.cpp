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

class __using_socket__ {
public:
  __using_socket__() {native::socket::startup();}
  ~__using_socket__() {native::socket::cleanup();}
} __using_socket_instance__;

socket::socket(xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) : socket(native::socket::get_os_supports_ip_v6() ? address_family::inter_network_v6 : address_family::inter_network, socket_type, protocol_type)  {
  if (data_->address_family == address_family::inter_network_v6) dual_mode(true);
}

socket::socket(xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) {
  data_->address_family = address_family;
  data_->socket_type = socket_type;
  data_->protocol_type = protocol_type;
  data_->handle = native::socket::create(static_cast<int32_t>(address_family), static_cast<int32_t>(socket_type), static_cast<int32_t>(protocol_type));
  if (data_->handle == static_cast<intptr_t>(-1)) throw socket_exception(get_last_error(), csf_);
}

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
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::dont_fragment));
}

socket& socket::dont_fragment(bool value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network) throw not_supported_exception(csf_);
  set_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::dont_fragment, value);
  return *this;
}

bool socket::dual_mode() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network_v6) throw not_supported_exception(csf_);
  return !as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_v6_only));
}

socket& socket::dual_mode(bool value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network_v6) throw not_supported_exception(csf_);
  set_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_v6_only, !value);
  return *this;
}

bool socket::enable_broadcast() const {
  return !as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::broadcast));
}

socket& socket::enable_broadcast(bool value) {
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::broadcast, !value);
  return *this;
}

intptr_t socket::handle() const noexcept {
  return data_->handle;
}

bool socket::os_supports_ip_v4() const noexcept {
  return native::socket::get_os_supports_ip_v4();
}

bool socket::os_supports_ip_v6() const noexcept {
  return native::socket::get_os_supports_ip_v6();
}

int32_t socket::get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  int32_t result = 0;
  size_t size  = sizeof(int32_t);
  if (native::socket::get_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), &result, size) != 0) throw socket_exception(get_last_error(), csf_);
  return result;
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value) {
  set_socket_option(socket_option_level, socket_option_name, as<int32_t>(option_value));
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32_t option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::set_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), &option_value, sizeof(int32_t)) != 0) throw socket_exception(get_last_error(), csf_);
}

socket_error socket::get_last_error() {
  return static_cast<socket_error>(native::socket::get_last_error());
}
