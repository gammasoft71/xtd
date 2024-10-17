#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/bit_converter.h"
#include "../../../include/xtd/net/ip_end_point.h"
#include "../../../include/xtd/net/sockets/socket_exception.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_end_point::ip_end_point(uint32 address, uint16 port) : ip_end_point(ip_address(address), port) {
}

ip_end_point::ip_end_point(const ip_address& address, uint16 port) : address_(address), port_(port) {
  address_family_ = address_.address_family();
}

const xtd::net::ip_address& ip_end_point::address() const noexcept {
  return address_;
}

ip_end_point& ip_end_point::address(const ip_address& address) {
  address_family_ = address.address_family();
  address_ = address;
  return *this;
}

uint16 ip_end_point::port() const noexcept {
  return port_;
}

ip_end_point& ip_end_point::port(uint16 port) {
  port_ = port;
  return *this;
}

xtd::uptr<end_point> ip_end_point::create(const socket_address& socket_address) const {
  if (socket_address.address_family() != address_family_ || socket_address.size() < 8) throw argument_exception {};
  if (address_family_ != address_family::inter_network && address_family_ != address_family::inter_network_v6) throw socket_exception(socket_error::address_family_not_supported);
  
  uint16 current_port = ip_address::network_to_host_order(bit_converter::to_uint16(socket_address.bytes_, 2)); // static_cast<uint16>((socket_address[2] << 8 & 0xFF00) | (socket_address[3]));
  
  if (address_family_ == address_family::inter_network_v6) {
    std::vector<xtd::byte> current_address(16);
    for (auto i = 0_z; i < current_address.size(); i++)
      current_address[i] = socket_address[i + 8];
    //uint32 scope = ip_address::network_to_host_order(bit_converter::to_uint32(socket_address.bytes_, 24));
    uint32 scope = bit_converter::to_uint32(socket_address.bytes_, 24);
    return xtd::new_uptr<ip_end_point>(ip_address(current_address, scope), current_port);
  }
  
  uint32 current_address = bit_converter::to_uint32(socket_address.bytes_, 4);
  return xtd::new_uptr<ip_end_point>(ip_address(current_address), current_port);
}

socket_address ip_end_point::serialize() const {
  socket_address result(address_family_, address_family_ == address_family::inter_network ? 16 : 28);
  size_t index = 2;
  for (xtd::byte b : bit_converter::get_bytes(ip_address::host_to_network_order(port_)))
    result[index++] = b;
    
  if (address_.address_family() == address_family::inter_network_v6) {
    index = 8;
    for (xtd::byte b : address_.get_address_bytes())
      result[index++] = b;
    //for (byte b : bit_converter::get_bytes(ip_address::host_to_network_order(address_.scope_id())))
    for (xtd::byte b : bit_converter::get_bytes(address_.scope_id()))
      result[index++] = b;
  } else {
    index = 4;
    for (xtd::byte b : address_.get_address_bytes())
      result[index++] = b;
  }
  
  if (index > result.size()) throw argument_out_of_range_exception {};
  
  return result;
}

string ip_end_point::to_string() const noexcept {
  if (address_family_ == address_family::inter_network_v6) return string::format("[{}]:{:D}", address_, port_);
  return string::format("{}:{:D}", address_, port_);
}
