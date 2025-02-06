#include "../../../../include/xtd/net/sockets/linger_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32 linger_time) : enabled {enabled}, linger_time {linger_time} {
}
