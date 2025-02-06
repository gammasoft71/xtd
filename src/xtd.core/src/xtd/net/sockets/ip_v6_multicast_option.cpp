#include "../../../../include/xtd/net/sockets/ip_v6_multicast_option.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group) : group_ {group} {
}

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group, uint64 interface_index) : group_ {group}, interface_index_ {interface_index} {
  if (interface_index > 0x00000000FFFFFFFF) throw argument_out_of_range_exception {};
}

const xtd::net::ip_address& ip_v6_multicast_option::group() const noexcept {
  return group_;
}

ip_v6_multicast_option& ip_v6_multicast_option::group(const xtd::net::ip_address& value) noexcept {
  group_ = value;
  return *this;
}

uint64 ip_v6_multicast_option::interface_index() const noexcept {
  return interface_index_;
}

ip_v6_multicast_option& ip_v6_multicast_option::interface_index(uint64 value) {
  if (value > 0x00000000FFFFFFFF) throw argument_out_of_range_exception {};
  interface_index_ = value;
  return *this;
}

bool ip_v6_multicast_option::equals(const object& obj) const noexcept {
  return is<ip_v6_multicast_option>(obj) && equals(static_cast<const ip_v6_multicast_option&>(obj));
}

bool ip_v6_multicast_option::equals(const ip_v6_multicast_option& other) const noexcept {
  return group_ == other.group_ && interface_index_ == other.interface_index_;
}

size ip_v6_multicast_option::get_hash_code() const noexcept {
  return hash_code::combine(group_, interface_index_);
}
