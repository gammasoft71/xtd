#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/bit_converter.h"
#include "../../../include/xtd/net/ip_end_point.h"
#include "../../../include/xtd/net/sockets/socket_exception.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_end_point::ip_end_point(uint32_t address, uint16_t port) : ip_end_point(ip_address(address), port) {
}

ip_end_point::ip_end_point(const ip_address& address, uint16_t port) : address_(address), port_(port) {
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

uint16_t ip_end_point::port() const noexcept {
  return port_;
}

ip_end_point& ip_end_point::port(uint16_t port) {
  port_ = port;
  return *this;
}

unique_ptr<end_point> ip_end_point::create(const socket_address& socket_address) const {
  if (socket_address.address_family() != address_family_ || socket_address.size() < 8) throw argument_exception(csf_);
  if (address_family_ != address_family::inter_network && address_family_ != address_family::inter_network_v6) throw socket_exception(socket_error::address_family_not_supported, csf_);
  
  uint16_t port = ip_address::network_to_host_order(bit_converter::to_uint16(socket_address.bytes_, 2)); // static_cast<uint16_t>((socket_address[2] << 8 & 0xFF00) | (socket_address[3]));
  
  if (address_family_ == address_family::inter_network_v6) {
    vector<byte_t> address(16);
    for (auto i = 0U; i < address.size(); i++)
      address[i] = socket_address[i + 8];
    //uint32_t scope = ip_address::network_to_host_order(bit_converter::to_uint32(socket_address.bytes_, 24));
    uint32_t scope = bit_converter::to_uint32(socket_address.bytes_, 24);
    return make_unique<ip_end_point>(ip_address(address, scope), port);
  }
  
  uint32_t address = bit_converter::to_uint32(socket_address.bytes_, 4);
  return make_unique<ip_end_point>(ip_address(address), port);
}

socket_address ip_end_point::serialize() const {
  socket_address result(address_family_, address_family_ == address_family::inter_network ? 16 : 28);
  size_t index = 2;
  for (byte_t b : bit_converter::get_bytes(ip_address::host_to_network_order(port_)))
    result[index++] = b;
  
  if (address_.address_family() == address_family::inter_network_v6) {
    index = 8;
    for (byte_t b : address_.get_address_bytes())
      result[index++] = b;
    //for (byte b : bit_converter::get_bytes(ip_address::host_to_network_order(address_.scope_id())))
    for (byte_t b : bit_converter::get_bytes(address_.scope_id()))
      result[index++] = b;
  } else {
    index = 4;
    for (byte_t b : address_.get_address_bytes())
      result[index++] = b;
  }
  
  if (index > result.size()) throw argument_out_of_range_exception(csf_);
  
  return result;
}

ustring ip_end_point::to_string() const noexcept {
  if (address_family_ == address_family::inter_network_v6) return ustring::format("[{}]:{:D}", address_, port_);
  return ustring::format("{}:{:D}", address_, port_);
}
