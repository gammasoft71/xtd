#include "../../../../include/xtd/net/sockets/linger_option.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32_t linger_time) : enabledd_(enabled), linger_time_(linger_time) {
}

bool linger_option::enabled() const noexcept {
  return enabledd_;
}

linger_option& linger_option::enabled(bool value) noexcept {
  enabledd_ = value;
  return *this;
}

uint32_t linger_option::linger_time() const noexcept {
  return linger_time_;
}

linger_option& linger_option::linger_time(uint32_t value) noexcept {
  linger_time_ = value;
  return *this;
}
