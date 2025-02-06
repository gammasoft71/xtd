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

const xtd::net::ip_address& multicast_option::group() const noexcept {
  return group_;
}

multicast_option& multicast_option::group(const xtd::net::ip_address& value) noexcept {
  group_ = value;
  return *this;
}

uint32 multicast_option::interface_index() const noexcept {
  return interface_index_;
}

multicast_option& multicast_option::interface_index(uint32 value) noexcept {
  interface_index_ = value;
  local_address_ = ip_address::none;
  return *this;
}

const xtd::net::ip_address& multicast_option::local_address() const noexcept {
  return local_address_;
}

multicast_option& multicast_option::local_address(const xtd::net::ip_address& value) noexcept {
  interface_index_ = 0;
  local_address_ = value;
  return *this;
}

bool multicast_option::equals(const object& obj) const noexcept {
  return is<multicast_option>(obj) && equals(static_cast<const multicast_option&>(obj));
}

bool multicast_option::equals(const multicast_option& other) const noexcept {
  return group_ == other.group_ && interface_index_ == other.interface_index_ && local_address_ == other.local_address_;
}

size multicast_option::get_hash_code() const noexcept {
  return hash_code::combine(group_, interface_index_, local_address_);
}
