#include "../../../../include/xtd/net/sockets/multicast_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

multicast_option::multicast_option(const xtd::net::ip_address& group, const xtd::net::ip_address& local_address) : group_(group), local_address_(local_address) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group) : group_(group), local_address_(ip_address::any) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group, uint32 interface_index) : group_(group), interface_index_(interface_index) {
}

auto multicast_option::group() const noexcept -> const xtd::net::ip_address& {
  return group_;
}

auto multicast_option::group(const xtd::net::ip_address& value) noexcept -> multicast_option& {
  group_ = value;
  return *this;
}

auto multicast_option::interface_index() const noexcept -> uint32 {
  return interface_index_;
}

auto multicast_option::interface_index(uint32 value) noexcept -> multicast_option& {
  interface_index_ = value;
  local_address_ = ip_address::none;
  return *this;
}

auto multicast_option::local_address() const noexcept -> const xtd::net::ip_address& {
  return local_address_;
}

auto multicast_option::local_address(const xtd::net::ip_address& value) noexcept -> multicast_option& {
  interface_index_ = 0;
  local_address_ = value;
  return *this;
}

auto multicast_option::equals(const object& obj) const noexcept -> bool {
  return is<multicast_option>(obj) && equals(static_cast<const multicast_option&>(obj));
}

auto multicast_option::equals(const multicast_option& other) const noexcept -> bool {
  return group_ == other.group_ && interface_index_ == other.interface_index_ && local_address_ == other.local_address_;
}

auto multicast_option::get_hash_code() const noexcept -> usize {
  return hash_code::combine(group_, interface_index_, local_address_);
}
