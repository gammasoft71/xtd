#include "../../../../include/xtd/net/sockets/ip_v6_multicast_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group) : group {group} {
}

ip_v6_multicast_option::ip_v6_multicast_option(const ip_address& group, uint32 interface_index) : group {group}, interface_index {interface_index} {
}
