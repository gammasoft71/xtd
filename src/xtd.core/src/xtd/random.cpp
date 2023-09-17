#include "../../include/xtd/as.h"
#include "../../include/xtd/byte_object.h"
#include "../../include/xtd/int32_object.h"
#include "../../include/xtd/math.h"
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
  return next(int32_object::max_value);
}

int32 random::next(int32 max_value) const {
  return next(0, max_value);
}

int32 random::next(int32 min_value, int32 max_value) const {
  if (min_value > max_value) throw argument_out_of_range_exception {csf_};
  if (min_value == max_value) return min_value;
  return min_value + as<int32>(math::round(sample() * int32_object::max_value)) % ((max_value - 1) - min_value + 1);
}

void random::next_bytes(std::vector<xtd::byte>& buffer) const {
  next_bytes(buffer.data(), buffer.size());
}

void random::next_bytes(xtd::byte* buffer, size_t buffer_size) const {
  if (buffer == nullptr) throw argument_null_exception {csf_};
  for (auto index = 0_sz; index < buffer_size; index++)
    buffer[index] = next<xtd::byte>(0, byte_object::max_value);
}

double random::next_double() const {
  return sample();
}

double random::sample() const {
  static auto distribution_ = std::uniform_real_distribution<> {0, 1};
  return distribution_(generator_);
}
