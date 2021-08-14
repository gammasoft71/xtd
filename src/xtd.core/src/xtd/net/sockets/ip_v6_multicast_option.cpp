#include "../../../../include/xtd/net/sockets/ip_v6_multicast_option.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_v6_multicast_option::ip_v6_multicast_option(const xtd::net::ip_address& group) : group_(group) {
}

ip_v6_multicast_option::ip_v6_multicast_option(const xtd::net::ip_address& group, uint32_t interface_index) : group_(group), interface_index_(interface_index) {
}

const xtd::net::ip_address& ip_v6_multicast_option::group() const noexcept {
  return group_;
}

ip_v6_multicast_option& ip_v6_multicast_option::group(const xtd::net::ip_address& value) noexcept {
  group_ = value;
  return *this;
}

uint32_t ip_v6_multicast_option::interface_index() const noexcept {
  return interface_index_;
}

ip_v6_multicast_option& ip_v6_multicast_option::interface_index(uint32_t value) noexcept {
  interface_index_ = value;
  return *this;
}
