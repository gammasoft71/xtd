#include "../../include/xtd/as.hpp"
#include "../../include/xtd/byte_object.hpp"
#include "../../include/xtd/int32_object.hpp"
#include "../../include/xtd/random.hpp"

using namespace xtd;
using namespace xtd::helpers;

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
  if (min_value > max_value) throw_helper::throws(exception_case::argument_out_of_range);
  if (min_value == max_value) return min_value;
  return min_value + as<int32>(math::round(sample() * int32_object::max_value)) % ((max_value - 1) - min_value + 1);
}

decimal random::next(decimal max_value) const {
  return next(decimal {.0}, max_value);
}

double random::next(double max_value) const {
  return next(.0, max_value);
}

float random::next(float max_value) const {
  return next(.0f, max_value);
}

decimal random::next(decimal min_value, decimal max_value) const {
  if (min_value > max_value) throw_helper::throws(exception_case::argument_out_of_range);
  if (min_value == max_value) return min_value;
  return min_value + (sample() * (max_value - min_value));
}

double random::next(double min_value, double max_value) const {
  if (min_value > max_value) throw_helper::throws(exception_case::argument_out_of_range);
  if (min_value == max_value) return min_value;
  return min_value + (sample() * (max_value - min_value));
}

float random::next(float min_value, float max_value) const {
  if (min_value > max_value) throw_helper::throws(exception_case::argument_out_of_range);
  if (min_value == max_value) return min_value;
  return static_cast<float>(min_value + (sample() * (max_value - min_value)));
}

void random::next_bytes(std::vector<xtd::byte>& buffer) const {
  next_bytes(buffer.data(), buffer.size());
}

void random::next_bytes(xtd::byte* buffer, size_t buffer_size) const {
  if (buffer == nullptr) throw_helper::throws(exception_case::argument_null);
  for (auto index = 0_z; index < buffer_size; index++)
    buffer[index] = next<xtd::byte>(0, byte_object::max_value);
}

double random::next_double() const {
  return sample();
}

double random::sample() const {
  static auto distribution_ = std::uniform_real_distribution<> {0, 1};
  return distribution_(generator_);
}
