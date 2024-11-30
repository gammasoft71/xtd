#include "../../../../include/xtd/net/sockets/ip_packet_information.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

const xtd::net::ip_address& ip_packet_information::address() const noexcept {
  return address_;
}

int32 ip_packet_information::interface() const noexcept {
  return address_interface_;
}
