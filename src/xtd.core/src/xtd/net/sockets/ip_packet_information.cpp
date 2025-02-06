#include "../../../../include/xtd/net/sockets/ip_packet_information.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

const ip_address& ip_packet_information::address() const noexcept {
  return address_;
}

int32 ip_packet_information::interface() const noexcept {
  return address_interface_;
}

bool ip_packet_information::equals(const object& obj) const noexcept {
  return is<ip_packet_information>(obj) && equals(static_cast<const ip_packet_information&>(obj));
}

bool ip_packet_information::equals(const ip_packet_information& other) const noexcept {
  return address_ == other.address_ && address_interface_ == other.address_interface_;
}

size ip_packet_information::get_hash_code() const noexcept {
  return hash_code::combine(address_, address_interface_);
}
