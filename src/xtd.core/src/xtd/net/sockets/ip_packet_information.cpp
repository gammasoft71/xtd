#include "../../../../include/xtd/net/sockets/ip_packet_information.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto ip_packet_information::address() const noexcept -> const ip_address& {
  return address_;
}

auto ip_packet_information::interface() const noexcept -> int32 {
  return address_interface_;
}

auto ip_packet_information::equals(const object& obj) const noexcept -> bool {
  return is<ip_packet_information>(obj) && equals(static_cast<const ip_packet_information&>(obj));
}

auto ip_packet_information::equals(const ip_packet_information& other) const noexcept -> bool {
  return address_ == other.address_ && address_interface_ == other.address_interface_;
}

auto ip_packet_information::get_hash_code() const noexcept -> size {
  return hash_code::combine(address_, address_interface_);
}
