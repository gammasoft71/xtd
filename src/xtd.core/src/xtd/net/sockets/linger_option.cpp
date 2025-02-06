#include "../../../../include/xtd/net/sockets/linger_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32 linger_time) : enabled_ {enabled}, linger_time_ {linger_time} {
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

bool linger_option::equals(const object& obj) const noexcept {
  return is<linger_option>(obj) && equals(static_cast<const linger_option&>(obj));
}

bool linger_option::equals(const linger_option& other) const noexcept {
  return enabled_ == other.enabled_ && linger_time_ == other.linger_time_;
}

size linger_option::get_hash_code() const noexcept {
  return hash_code::combine(enabled_, linger_time_);
}
