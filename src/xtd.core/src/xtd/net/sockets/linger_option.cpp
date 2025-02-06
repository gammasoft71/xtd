#include "../../../../include/xtd/net/sockets/linger_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32 linger_time) : enabled {enabled}, linger_time {linger_time} {
}

bool linger_option::equals(const object& obj) const noexcept {
  return is<linger_option>(obj) && equals(static_cast<const linger_option&>(obj));
}

bool linger_option::equals(const linger_option& other) const noexcept {
  return enabled == other.enabled && linger_time == other.linger_time;
}

size linger_option::get_hash_code() const noexcept {
  return hash_code::combine(enabled, linger_time);
}
