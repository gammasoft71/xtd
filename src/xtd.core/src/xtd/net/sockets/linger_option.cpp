#include "../../../../include/xtd/net/sockets/linger_option.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

linger_option::linger_option(bool enabled, uint32 linger_time) : enabled_ {enabled}, linger_time_ {linger_time} {
}

auto linger_option::enabled() const noexcept -> bool {
  return enabled_;
}

auto linger_option::enabled(bool value) noexcept -> linger_option& {
  enabled_ = value;
  return *this;
}

auto linger_option::linger_time() const noexcept -> uint32 {
  return linger_time_;
}

auto linger_option::linger_time(uint32 value) noexcept -> linger_option& {
  linger_time_ = value;
  return *this;
}

auto linger_option::equals(const object& obj) const noexcept -> bool {
  return is<linger_option>(obj) && equals(static_cast<const linger_option&>(obj));
}

auto linger_option::equals(const linger_option& other) const noexcept -> bool {
  return enabled_ == other.enabled_ && linger_time_ == other.linger_time_;
}

auto linger_option::get_hash_code() const noexcept -> usize {
  return hash_code::combine(enabled_, linger_time_);
}
