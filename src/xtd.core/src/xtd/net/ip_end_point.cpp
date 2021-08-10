#include "../../../include/xtd/argument_exception.h"
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
  
  uint16_t port = static_cast<uint16_t>((socket_address[2] << 8 & 0xFF00) | (socket_address[3]));
  
  if (address_family_ == address_family::inter_network) {
    vector<byte_t> address(8);
    for (auto i = 0U; i < address.size(); i++)
      address[i] = socket_address[i + 8];
    uint32_t scope = static_cast<uint32_t>((socket_address[27] << 24) + (socket_address[26] << 16) + (socket_address[25] << 8) + (socket_address[24]));
    return make_unique<ip_end_point>(ip_address(address, scope), port);
  }
  
  uint32_t address = static_cast<uint32_t>((socket_address[4] & 0x000000FF) | (socket_address[5] << 8 & 0x0000FF00) | (socket_address[6] << 16 & 0x00FF0000) | (socket_address[7] << 24)) & 0x00000000FFFFFFFF;
  return make_unique<ip_end_point>(ip_address(address), port);
}

socket_address ip_end_point::serialize() const {
  socket_address result(address_family_, address_family_ == address_family::inter_network ? 16 : 28);
  result[2] = static_cast<byte_t>(port_ >> 8);
  result[3] = static_cast<byte_t>(port_);
  
  if (address_.address_family() == address_family::inter_network_v6) {
    result[24] = static_cast<byte_t>(address_.scope_id());
    result[25] = static_cast<byte_t>(address_.scope_id() >> 8);
    result[26] = static_cast<byte_t>(address_.scope_id() >> 16);
    result[27] = static_cast<byte_t>(address_.scope_id() >> 24);
    auto address_bytes = address_.get_address_bytes();
    for (auto i = 0U; i < address_bytes.size(); i++)
      result[8 + i] = address_bytes[i];
  } else {
    auto address_bytes = address_.get_address_bytes();
    for (auto i = 0U; i < address_bytes.size(); i++)
      result[4 + i] = address_bytes[i];
  }
  
  return result;
}

ustring ip_end_point::to_string() const noexcept {
  if (address_family_ == address_family::inter_network_v6) return ustring::format("[{}] :{}", address_, port_);
  return ustring::format("{}:{}", address_, port_);
}
