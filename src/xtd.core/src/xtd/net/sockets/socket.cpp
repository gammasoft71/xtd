#include "../../../../include/xtd/bit_converter.h"
#include "../../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../../include/xtd/invalid_operation_exception.h"
#include "../../../../include/xtd/object_closed_exception.h"
#include "../../../../include/xtd/net/ip_end_point.h"
#include "../../../../include/xtd/net/sockets/socket.h"
#include "../../../../include/xtd/net/sockets/socket_async_event_args.h"
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

struct socket::data {
  xtd::net::sockets::address_family address_family = xtd::net::sockets::address_family::unspecified;
  bool blocking = true;
  bool connected = false;
  intptr_t handle = 0;
  bool is_bound = false;
  bool listening = false;
  std::unique_ptr<xtd::net::end_point> local_end_point;
  xtd::net::sockets::protocol_type protocol_type = xtd::net::sockets::protocol_type::unspecified;
  std::unique_ptr<xtd::net::end_point> remote_end_point;
  xtd::net::sockets::socket_aync_event_args socket_aync_event_args;
  xtd::net::sockets::socket_type socket_type = xtd::net::sockets::socket_type::unknown;
};

socket::socket() {
  data_ = std::make_shared<data>();
}
socket::socket(intptr_t handle) {
  data_ = std::make_shared<data>();
  if (handle == 0) throw argument_exception(csf_);
  data_->handle = handle;
}

socket::socket(const socket_information& socket_information) {
  data_ = std::make_shared<data>();
  throw not_implemented_exception(csf_);
}

socket::socket(xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) : socket(native::socket::get_os_supports_ip_v6() ? address_family::inter_network_v6 : address_family::inter_network, socket_type, protocol_type)  {
  if (data_->address_family == address_family::inter_network_v6) dual_mode(true);
}

socket::socket(xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) {
  data_ = std::make_shared<data>();
  data_->address_family = address_family;
  data_->socket_type = socket_type;
  data_->protocol_type = protocol_type;
  data_->handle = native::socket::create(static_cast<int32_t>(address_family), static_cast<int32_t>(socket_type), static_cast<int32_t>(protocol_type));
  if (data_->handle == static_cast<intptr_t>(-1)) throw socket_exception(get_last_error(), csf_);
}

socket::~socket() {
  if (data_.use_count() == 1) close();
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
  if (data_->is_bound) throw invalid_operation_exception(csf_);
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::exclusive_address_use, value);
  return *this;
}

intptr_t socket::handle() const noexcept {
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

const std::unique_ptr<xtd::net::end_point>& socket::local_end_point() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  return data_->local_end_point;
}

bool socket::multicast_loopback() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family != address_family::inter_network && data_->address_family != address_family::inter_network_v6) throw not_supported_exception(csf_);
  return as<bool>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::multicast_loopback));
}

socket& socket::multicast_loopback(bool value) {
  if (data_->address_family != address_family::inter_network && data_->address_family != address_family::inter_network_v6) throw not_supported_exception(csf_);
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
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_buffer, as<int32_t>(value));
  return *this;
}

int32_t socket::receive_timeout() const {
  return get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_timeout);
}

socket& socket::receive_timeout(int32_t value) {
  if (value < -1) throw argument_out_of_range_exception(csf_);
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::receive_timeout, value);
  return *this;
}

const std::unique_ptr<xtd::net::end_point>& socket::remote_end_point() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  return data_->remote_end_point;
}

size_t socket::send_buffer_size() const {
  return as<size_t>(get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_buffer));
}

socket& socket::send_buffer_size(size_t value) {
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_buffer, as<int32_t>(value));
  return *this;
}

int32_t socket::send_timeout() const {
  return get_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_timeout);
}

socket& socket::send_timeout(int32_t value) {
  if (value < -1) throw argument_out_of_range_exception(csf_);
  if (value >= 1 && value <= 499) value = 500;
  set_socket_option(xtd::net::sockets::socket_option_level::socket, xtd::net::sockets::socket_option_name::send_timeout, value);
  return *this;
}

xtd::net::sockets::socket_type socket::socket_type() const noexcept {
  return data_->socket_type;
}

byte_t socket::ttl() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family == address_family::inter_network) return as<byte_t>(get_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::ip_time_to_live));
  if (data_->address_family == address_family::inter_network_v6) return as<byte_t>(get_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_time_to_live));
  throw not_supported_exception(csf_);
}

socket& socket::ttl(byte_t value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->address_family == address_family::inter_network) set_socket_option(xtd::net::sockets::socket_option_level::ip, xtd::net::sockets::socket_option_name::ip_time_to_live, as<int32_t>(value));
  else if (data_->address_family == address_family::inter_network_v6) set_socket_option(xtd::net::sockets::socket_option_level::ip_v6, xtd::net::sockets::socket_option_name::ip_time_to_live, as<int32_t>(value));
  else throw not_supported_exception(csf_);
  return *this;
}

socket socket::accept() {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->is_bound == false || data_->listening == false) throw invalid_operation_exception(csf_);
  
  socket_address address(data_->address_family);
  intptr_t new_socket_handle = native::socket::accept(data_->handle, address.bytes_);
  if (new_socket_handle == static_cast<intptr_t>(-1)) throw socket_exception(get_last_error(), csf_);
  
  data_->connected = true;

  socket new_socket(new_socket_handle);
  new_socket.data_->address_family = data_->address_family;
  new_socket.data_->connected = true;
  new_socket.data_->local_end_point = ip_end_point(0, 0).create(address);
  new_socket.data_->protocol_type = data_->protocol_type;
  new_socket.data_->socket_type = data_->socket_type;
  return new_socket;
}

void socket::close() {
  data_->connected = false;
  if (data_->handle != 0 && native::socket::destroy(data_->handle) != 0) throw socket_exception(get_last_error(), csf_);
  data_->address_family = xtd::net::sockets::address_family::unspecified;
  data_->blocking = true;
  data_->connected = false;
  data_->handle = 0;
  data_->is_bound = false;
  data_->listening = false;
  data_->local_end_point.reset();
  data_->protocol_type = xtd::net::sockets::protocol_type::unspecified;
  data_->remote_end_point.reset();
  data_->socket_type = xtd::net::sockets::socket_type::unknown;
}

size_t socket::get_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t size_option_value) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  size_t size  = 0;
  if (native::socket::get_raw_socket_option(data_->handle, socket_option_level, socket_option_name, option_value, size) != 0) throw socket_exception(get_last_error(), csf_);
  return size;
}

int32_t socket::get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  int32_t result = 0;
  size_t size = sizeof(int32_t);
  if (native::socket::get_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), reinterpret_cast<intptr_t>(&result), size) != 0) throw socket_exception(get_last_error(), csf_);
  return result;
}

xtd::net::sockets::linger_option socket::get_socket_linger_option() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  bool enabled = false;
  uint32_t linger_time = 0;
  if (native::socket::get_socket_linger_option(data_->handle, enabled, linger_time) != 0) throw socket_exception(get_last_error(), csf_);
  return linger_option(enabled, linger_time);
}

xtd::net::sockets::multicast_option socket::get_socket_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  uint32_t multicast_address = 0;
  uint32_t interface_index = 0;
  if (native::socket::get_socket_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error(), csf_);
  //if (!bit_converter::is_little_endian) {
  //  //multicast_address = ((multicast_address << 24) | ((multicast_address & 0x0000FF00) << 8) | ((multicast_address >> 8) & 0x0000FF00) | (multicast_address >> 24));
  //  //interface_index = ((interface_index << 24) | ((interface_index & 0x0000FF00) << 8) | ((interface_index >> 8) & 0x0000FF00) | (interface_index >> 24));
  //}
  multicast_address = ip_address::network_to_host_order(multicast_address);
  interface_index = ip_address::network_to_host_order(interface_index);
  return multicast_option(ip_address(multicast_address), interface_index);
}

xtd::net::sockets::ip_v6_multicast_option socket::get_socket_ip_v6_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  vector<uint8_t> multicast_address;
  uint32_t interface_index = 0;
  if (native::socket::get_socket_ip_v6_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error(), csf_);
  return ip_v6_multicast_option(ip_address(multicast_address), interface_index);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value) {
  set_socket_option(socket_option_level, socket_option_name, as<int32_t>(option_value));
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32_t option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  if (native::socket::set_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), reinterpret_cast<intptr_t>(&option_value), sizeof(int32_t)) != 0) throw socket_exception(get_last_error(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::linger_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (native::socket::set_socket_linger_option(data_->handle, option_value.enabled(), option_value.linger_time()) != 0) throw socket_exception(get_last_error(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::multicast_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  uint32_t multicast_address = option_value.group().address_;
  uint32_t interface_index = option_value.local_adress() != ip_address::none ? option_value.local_adress().address_ : ip_address::host_to_network_order(option_value.interface_index());
  if (native::socket::set_socket_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::ip_v6_multicast_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  if (native::socket::set_socket_ip_v6_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), option_value.group().get_address_bytes(), option_value.interface_index()) != 0) throw socket_exception(get_last_error(), csf_);
}

void socket::set_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t option_value_size) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::set_raw_socket_option(data_->handle, socket_option_level, socket_option_name, reinterpret_cast<intptr_t>(&option_value), option_value_size) != 0) throw socket_exception(get_last_error(), csf_);
}

socket_error socket::get_last_error() {
  return static_cast<socket_error>(native::socket::get_last_error());
}
