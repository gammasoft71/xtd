#include <thread>
#include "../../../../include/xtd/bit_converter.h"
#include "../../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../../include/xtd/invalid_operation_exception.h"
#include "../../../../include/xtd/object_closed_exception.h"
#include "../../../../include/xtd/diagnostics/boolean_switch.h"
#include "../../../../include/xtd/diagnostics/debug.h"
#include "../../../../include/xtd/net/dns.h"
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
  intptr_t handle = 0;
  bool is_bound = false;
  bool is_listening = false;
  std::unique_ptr<xtd::net::end_point> local_end_point;
  xtd::net::sockets::protocol_type protocol_type = xtd::net::sockets::protocol_type::unspecified;
  std::unique_ptr<xtd::net::end_point> remote_end_point;
  std::unique_ptr<xtd::net::sockets::socket_async_event_args> socket_aync_event_args;
  xtd::net::sockets::socket_type socket_type = xtd::net::sockets::socket_type::unknown;
};

socket::socket() {
  data_ = std::make_shared<data>();
}
socket::socket(intptr_t handle) {
  debug::write_if(show_debug_socket.enabled(), ustring::format("socket::socket(handle) : socket=[{}]", handle));
  if (handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[handle_invalid]");
    throw argument_exception(csf_);
  }
  data_ = std::make_shared<data>();
  data_->handle = handle;
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
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
  debug::write_if(show_debug_socket.enabled(), ustring::format("socket::socket(handle) : socket=[{}] address_family=[{}] socket_type=[{}] protocol_type=[{}]", data_->handle, data_->address_family, data_->socket_type, data_->protocol_type));
  if (data_->handle == static_cast<intptr_t>(-1)) {
    debug::write_line_if(show_debug_socket.enabled(), ustring::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_(), csf_);
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
}

socket::~socket() {
  if (data_.use_count() == 1) {
    if (data_->handle != 0 && data_->is_connected) shutdown(xtd::net::sockets::socket_shutdown::both);
    close();
  }
}

address_family socket::address_family() const noexcept {
  return data_->address_family;
}

size_t socket::available() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  auto available = native::socket::get_available(data_->handle);
  if (available == static_cast<size_t>(-1)) throw socket_exception(get_last_error_(), csf_);
  return available;
}

bool socket::blocking() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  return data_->will_block;
}

socket& socket::blocking(bool value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::set_blocking(data_->handle, value) != 0) throw socket_exception(get_last_error_(), csf_);
  data_->will_block = value;
  return *this;
}

bool socket::connected() const noexcept {
  return data_->is_connected;
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
  if (data_->is_bound == false || data_->is_listening == false) throw invalid_operation_exception(csf_);
  
  socket_address address(data_->address_family);
  intptr_t new_socket_handle = native::socket::accept(data_->handle, address.bytes_);
  if (new_socket_handle == static_cast<intptr_t>(-1)) throw socket_exception(get_last_error_(), csf_);
  
  socket new_socket(new_socket_handle);
  new_socket.data_->address_family = data_->address_family;
  new_socket.data_->is_connected = true;
  new_socket.data_->local_end_point = data_->local_end_point->create(address);
  new_socket.data_->protocol_type = data_->protocol_type;
  new_socket.data_->socket_type = data_->socket_type;
  return new_socket;
}

bool socket::accept_async(xtd::net::sockets::socket_async_event_args& e) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->is_bound == false || data_->is_listening == false) throw invalid_operation_exception(csf_);
  
  std::thread thread([](xtd::net::sockets::socket_async_event_args* e, xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type) {
    if (e->accept_socket_.data_->address_family == xtd::net::sockets::address_family::unknown && e->accept_socket_.data_->socket_type == xtd::net::sockets::socket_type::unknown && e->accept_socket_.data_->protocol_type == xtd::net::sockets::protocol_type::unknown) {
      e->accept_socket_.data_->address_family = address_family;
      e->accept_socket_.data_->socket_type = socket_type;
      e->accept_socket_.data_->protocol_type = protocol_type;
      e->connect_socket_ = e->accept_socket_.accept();
       e->on_complet(*e);
    }
  }, &e, data_->address_family, data_->socket_type, data_->protocol_type);
  thread.detach();
  return false;
}

void socket::close() {
  debug::write_if(show_debug_socket.enabled(), ustring::format("socket::close() : socket=[{}]", data_->handle));
  if (data_->handle != 0 && native::socket::destroy(data_->handle) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), ustring::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_(), csf_);
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

void socket::connect(const xtd::net::ip_address& address, uint16_t port) {
  connect_(make_unique<ip_end_point>(ip_end_point(address, port)));
}

void socket::connect(const std::vector<ip_address>& addresses, uint16_t port) {
  for (ip_address address : addresses) {
    if (data_->is_connected == false)
      connect(address, port);
  }
}

void socket::connect(const xtd::ustring& host, uint16_t port) {
  connect(dns::get_host_addresses(host), port);
}

void socket::disconnect(bool reuse_socket) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (!data_->is_connected) throw object_closed_exception(csf_);

  data_->is_bound = false;
  data_->is_connected = false;
  data_->is_disconnected = true;
  data_->remote_end_point.reset();

  if (reuse_socket == false) {
    close();
    data_->handle = native::socket::create(static_cast<int32_t>(data_->address_family), static_cast<int32_t>(data_->socket_type), static_cast<int32_t>(data_->protocol_type));
    if (data_->handle == static_cast<intptr_t>(-1)) throw socket_exception(get_last_error_(), csf_);
  }
}

size_t socket::get_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t size_option_value) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  size_t size  = 0;
  if (native::socket::get_raw_socket_option(data_->handle, socket_option_level, socket_option_name, option_value, size) != 0) throw socket_exception(get_last_error_(), csf_);
  return size;
}

int32_t socket::get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  int32_t result = 0;
  size_t size = sizeof(int32_t);
  if (native::socket::get_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), reinterpret_cast<intptr_t>(&result), size) != 0) throw socket_exception(get_last_error_(), csf_);
  return result;
}

xtd::net::sockets::linger_option socket::get_socket_linger_option() const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  bool enabled = false;
  uint32_t linger_time = 0;
  if (native::socket::get_socket_linger_option(data_->handle, enabled, linger_time) != 0) throw socket_exception(get_last_error_(), csf_);
  return linger_option(enabled, linger_time);
}

xtd::net::sockets::multicast_option socket::get_socket_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  uint32_t multicast_address = 0;
  uint32_t interface_index = 0;
  if (native::socket::get_socket_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_(), csf_);
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
  if (native::socket::get_socket_ip_v6_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_(), csf_);
  return ip_v6_multicast_option(ip_address(multicast_address), interface_index);
}

size_t socket::io_control(int32_t io_control_code, std::vector<uint8_t>& option_in_value, std::vector<uint8_t>& option_out_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  int32_t result = native::socket::io_control(data_->handle, io_control_code, option_in_value, option_out_value);
  if (result == -1)  throw socket_exception(get_last_error_(), csf_);
  return static_cast<size_t>(result);
}

size_t socket::io_control(xtd::net::sockets::io_control_code io_control_code, std::vector<uint8_t>& option_in_value, std::vector<uint8_t>& option_out_value) {
  return io_control(static_cast<int32_t>(io_control_code), option_in_value, option_out_value);
}

void socket::listen(size_t backlog) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->is_bound == false) throw socket_exception(socket_error::not_connected, csf_);
  if (native::socket::listen(data_->handle, backlog) != 0) throw socket_exception(get_last_error_(), csf_);
  data_->is_listening = true;
}

bool socket::pool(int32_t micro_seconds, xtd::net::sockets::select_mode mode) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  int32_t result = native::socket::poll(data_->handle, micro_seconds, static_cast<int32_t>(mode));
  if (result == -1) throw socket_exception(get_last_error_(), csf_);
  return result;
}

size_t socket::receive(vector<byte_t>& buffer) {
  return receive(buffer, 0, buffer.size(), socket_flags::none);
}

size_t socket::receive(vector<byte_t>& buffer, socket_flags socket_flags) {
  return receive(buffer, 0, buffer.size(), socket_flags);
}

size_t socket::receive(vector<byte_t>& buffer, size_t size, socket_flags socket_flags) {
  return receive(buffer, 0, size, socket_flags);
}

size_t socket::receive(vector<byte_t>& buffer, size_t offset, size_t size, socket_flags socket_flags) {
  socket_error error_code = socket_error::success;
  auto number_of_bytes_received = receive(buffer, offset, size, socket_flags, error_code);
  if (error_code != socket_error::success) throw socket_exception(error_code, csf_);
  return number_of_bytes_received;
}

size_t socket::receive(vector<byte_t>& buffer, size_t offset, size_t size, socket_flags socket_flags, socket_error& error_code) {
  if (offset + size > buffer.size()) throw argument_out_of_range_exception(csf_);
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (!data_->is_connected) throw socket_exception(socket_error::not_connected, csf_);
  auto number_of_bytes_received = native::socket::receive(data_->handle, buffer, offset, size, static_cast<int32_t>(socket_flags));
  error_code = number_of_bytes_received > 0 ? get_last_error_() : socket_error::success;
  return static_cast<size_t>(number_of_bytes_received);
}

size_t socket::receive_from(vector<byte_t>& buffer, end_point& remote_end_point) {
  return receive_from(buffer, 0, buffer.size(), socket_flags::none, remote_end_point);
}

size_t socket::receive_from(vector<byte_t>& buffer, socket_flags socket_flags, end_point& remote_end_point) {
  return receive_from(buffer, 0, buffer.size(), socket_flags, remote_end_point);
}

size_t socket::receive_from(vector<byte_t>& buffer, size_t size, socket_flags socket_flags, end_point& remote_end_point) {
  return receive_from(buffer, 0, size, socket_flags, remote_end_point);
}

size_t socket::receive_from(vector<byte_t>& buffer, size_t offset, size_t size, socket_flags socket_flags, end_point& remote_end_point) {
  if (offset + size > buffer.size()) throw argument_out_of_range_exception(csf_);
  if (data_->handle == 0) throw object_closed_exception(csf_);
  
  socket_address socket_address = remote_end_point.serialize();
  int32_t number_of_bytes_received = native::socket::receive_from(data_->handle, buffer, offset, size, static_cast<int32_t>(socket_flags), socket_address.bytes_);
  if (number_of_bytes_received == -1) throw socket_exception(get_last_error_(), csf_);
  return static_cast<size_t>(number_of_bytes_received);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value) {
  set_socket_option(socket_option_level, socket_option_name, as<int32_t>(option_value));
}

void socket::set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32_t option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::broadcast && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::multicast_loopback && data_->socket_type != xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (socket_option_name == xtd::net::sockets::socket_option_name::linger || socket_option_name == xtd::net::sockets::socket_option_name::add_membership || socket_option_name == xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  if (native::socket::set_socket_option(data_->handle, static_cast<int32_t>(socket_option_level), static_cast<int32_t>(socket_option_name), reinterpret_cast<intptr_t>(&option_value), sizeof(int32_t)) != 0) throw socket_exception(get_last_error_(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::linger_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (data_->socket_type == xtd::net::sockets::socket_type::dgram) throw socket_exception(socket_error::protocol_not_supported, csf_);
  if (native::socket::set_socket_linger_option(data_->handle, option_value.enabled(), option_value.linger_time()) != 0) throw socket_exception(get_last_error_(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::multicast_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  uint32_t multicast_address = option_value.group().address_;
  uint32_t interface_index = option_value.local_adress() != ip_address::none ? option_value.local_adress().address_ : ip_address::host_to_network_order(option_value.interface_index());
  if (native::socket::set_socket_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), multicast_address, interface_index) != 0) throw socket_exception(get_last_error_(), csf_);
}

void socket::set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::ip_v6_multicast_option option_value) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (socket_option_name != xtd::net::sockets::socket_option_name::add_membership && socket_option_name != xtd::net::sockets::socket_option_name::drop_membership) throw argument_exception(csf_);
  if (native::socket::set_socket_ip_v6_multicast_option(data_->handle, static_cast<int32_t>(socket_option_name), option_value.group().get_address_bytes(), option_value.interface_index()) != 0) throw socket_exception(get_last_error_(), csf_);
}

void socket::set_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t option_value_size) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::set_raw_socket_option(data_->handle, socket_option_level, socket_option_name, reinterpret_cast<intptr_t>(&option_value), option_value_size) != 0) throw socket_exception(get_last_error_(), csf_);
}

void socket::shutdown(socket_shutdown how) {
  if (data_->handle == 0) throw object_closed_exception(csf_);
  if (native::socket::shutdown(data_->handle, static_cast<int32_t>(how)) != 0) throw socket_exception(get_last_error_(), csf_);
  data_->is_connected = false;
  data_->is_disconnected = true;
}

void socket::bind_(std::unique_ptr<xtd::net::end_point> local_end_point) {
  debug::write_if(show_debug_socket.enabled(), ustring::format("socket::bind() : socket=[{}] local_end_point=[{}]", data_->handle, *local_end_point));
  if (data_->handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[object_close]");
    throw object_closed_exception(csf_);
  }
  data_->local_end_point = std::move(local_end_point);
  xtd::net::socket_address socket_address = data_->local_end_point->serialize();
  if (native::socket::bind(data_->handle, socket_address.bytes_) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), ustring::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_(), csf_);
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
  data_->is_bound = true;
}

void socket::connect_(std::unique_ptr<xtd::net::end_point> remote_end_point) {
  debug::write_if(show_debug_socket.enabled(), ustring::format("socket::connect() : socket=[{}] remote_end_point=[{}]", data_->handle, *remote_end_point));
  if (data_->handle == 0) {
    debug::write_line_if(show_debug_socket.enabled(), " error=[object_close]");
    throw object_closed_exception(csf_);
  }
  data_->remote_end_point = std::move(remote_end_point);
  xtd::net::socket_address socket_address = data_->remote_end_point->serialize();
  if (native::socket::connect(data_->handle, socket_address.bytes_) != 0) {
    debug::write_line_if(show_debug_socket.enabled(), ustring::format(" error=[{}]", get_last_error_()));
    throw socket_exception(get_last_error_(), csf_);
  }
  debug::write_line_if(show_debug_socket.enabled(), " succeed");
  data_->is_connected = true;
}

socket_error socket::get_last_error_() {
  return static_cast<socket_error>(native::socket::get_last_error());
}
