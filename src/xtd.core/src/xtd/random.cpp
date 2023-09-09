#include "../../include/xtd/random.h"

using namespace xtd;

random::random() : generator_(static_cast<uint32>(environment::tick_count().count())) {
}

random::random(uint32 seed) : generator_(seed + 1) {
}

random::random(std::random_device& random_device) : generator_(random_device()) {
}

std::default_random_engine random::generator() const noexcept {
  return generator_;
}

int32 random::next() const {
  return next(std::numeric_limits<int32>::max());
}

int32 random::next(int32 max_value) const {
  return next(0, max_value);
}

int32 random::next(int32 min_value, int32 max_value) const {
  if (min_value > max_value) throw argument_out_of_range_exception {csf_};
  if (min_value == max_value) return min_value;
  return min_value + static_cast<int32>(std::round(sample() * std::numeric_limits<int32>::max())) % ((max_value - 1) - min_value + 1);
}

void random::next_bytes(std::vector<xtd::byte>& buffer) const {
  next_bytes(buffer.data(), buffer.size());
}

void random::next_bytes(xtd::byte* buffer, size_t buffer_size) const {
  if (buffer == nullptr) throw argument_null_exception {csf_};
  for (size_t index = 0; index < buffer_size; index++)
    buffer[index] = next<xtd::byte>(0, std::numeric_limits<xtd::byte>::max());
}

double random::next_double() const {
  return sample();
}

double random::sample() const {
  static std::uniform_real_distribution<> distribution_(0, 1);
  return distribution_(generator_);
}
