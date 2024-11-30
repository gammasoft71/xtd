#include "../../../../include/xtd/net/sockets/multicast_option.hpp"
#include "../../../../include/xtd/argument_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

multicast_option::multicast_option(const xtd::net::ip_address& group, const xtd::net::ip_address& local_address) : group_(group), local_address_(local_address) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group) : group_(group), local_address_(ip_address::any) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group, uint32 interface_index) : group_(group), interface_index_(interface_index) {
  if (interface_index > 0x00FFFFFF) throw argument_out_of_range_exception {};
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

multicast_option& multicast_option::interface_index(uint32 value) {
  if (value > 0x00FFFFFF) throw argument_out_of_range_exception {};
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
