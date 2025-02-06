#include "../../../../include/xtd/net/sockets/ip_v6_multicast_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group) : group {group} {
}

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group, uint32 interface_index) : group {group}, interface_index {interface_index} {
}

bool ip_v6_multicast_option::equals(const object& obj) const noexcept {
  return is<ip_v6_multicast_option>(obj) && equals(static_cast<const ip_v6_multicast_option&>(obj));
}

bool ip_v6_multicast_option::equals(const ip_v6_multicast_option& other) const noexcept {
  return group == other.group && interface_index == other.interface_index;
}

size ip_v6_multicast_option::get_hash_code() const noexcept {
  return hash_code::combine(group, interface_index);
}
