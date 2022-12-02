#include "../../include/xtd/random.h"

using namespace xtd;

random::random() : generator_(static_cast<uint32_t>(environment::tick_count().count())) {
}

random::random(uint32_t seed) : generator_(seed + 1) {
}

random::random(std::random_device& random_device) : generator_(random_device()) {
}

std::default_random_engine random::generator() const noexcept {
  return generator_;
}

int32_t random::next() const {
  return next(std::numeric_limits<int32_t>::max());
}

int32_t random::next(int32_t max_value) const {
  return next(0, max_value);
}

int32_t random::next(int32_t min_value, int32_t max_value) const {
  if (min_value > max_value) throw argument_out_of_range_exception(current_stack_frame_);
  if (min_value == max_value) return min_value;
  return min_value + static_cast<int32_t>(std::round(sample() * std::numeric_limits<int32_t>::max())) % ((max_value - 1) - min_value + 1);
}

void random::next_bytes(std::vector<uint8_t>& buffer) const {
  next_bytes(buffer.data(), buffer.size());
}

void random::next_bytes(uint8_t* buffer, size_t buffer_size) const {
  if (buffer == nullptr) throw argument_null_exception(current_stack_frame_);
  for (size_t index = 0; index < buffer_size; index++)
    buffer[index] = next<uint8_t>(0, std::numeric_limits<uint8_t>::max());
}

double random::next_double() const {
  return sample();
}

double random::sample() const {
  static std::uniform_real_distribution<> distribution_(0, 1);
  return distribution_(generator_);
}
