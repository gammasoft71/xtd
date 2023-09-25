#include "../../../../include/xtd/net/sockets/linger_option"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32 linger_time) : enabled_(enabled), linger_time_(linger_time) {
}

bool linger_option::enabled() const noexcept {
  return enabled_;
}

linger_option& linger_option::enabled(bool value) noexcept {
  enabled_ = value;
  return *this;
}

uint32 linger_option::linger_time() const noexcept {
  return linger_time_;
}

linger_option& linger_option::linger_time(uint32 value) noexcept {
  linger_time_ = value;
  return *this;
}
