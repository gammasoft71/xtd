#include "../../../../include/xtd/net/sockets/ip_v6_multicast_option.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group) : group_ {group} {
}

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group, uint64 interface_index) : group_ {group}, interface_index_ {interface_index} {
  if (interface_index > 0x00000000FFFFFFFF) throw_helper::throws(exception_case::argument_out_of_range);
}

auto ip_v6_multicast_option::group() const noexcept -> const xtd::net::ip_address& {
  return group_;
}

auto ip_v6_multicast_option::group(const xtd::net::ip_address& value) noexcept -> ip_v6_multicast_option& {
  group_ = value;
  return *this;
}

auto ip_v6_multicast_option::interface_index() const noexcept -> uint64 {
  return interface_index_;
}

auto ip_v6_multicast_option::interface_index(uint64 value) -> ip_v6_multicast_option& {
  if (value > 0x00000000FFFFFFFF) throw_helper::throws(exception_case::argument_out_of_range);
  interface_index_ = value;
  return *this;
}

auto ip_v6_multicast_option::equals(const object& obj) const noexcept -> bool {
  return is<ip_v6_multicast_option>(obj) && equals(static_cast<const ip_v6_multicast_option&>(obj));
}

auto ip_v6_multicast_option::equals(const ip_v6_multicast_option& other) const noexcept -> bool {
  return group_ == other.group_ && interface_index_ == other.interface_index_;
}

auto ip_v6_multicast_option::get_hash_code() const noexcept -> usize {
  return hash_code::combine(group_, interface_index_);
}
