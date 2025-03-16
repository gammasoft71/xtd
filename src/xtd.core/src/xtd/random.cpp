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

const std::default_random_engine& random::generator() const noexcept {
  return generator_;
}

std::default_random_engine& random::generator() noexcept {
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
  return min_value + static_cast<int32>(math::round(sample() * (max_value - 1 - min_value)));
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

void random::next_bytes(span<byte>& buffer) const {
  for (auto index = 0_z; index < buffer.size(); index++)
    buffer[index] = next<byte>(0, byte_object::max_value);
}

void random::next_bytes(array<byte>& buffer) const {
  auto span_buffer = span<byte> {buffer};
  next_bytes(span_buffer);
}

double random::next_double() const {
  return sample();
}

int64 random::next_int64() const {
  return next_int64(int64_object::max_value);
}

int64 random::next_int64(int64 max_value) const {
  return next_int64(0_s64, max_value);
}

int64 random::next_int64(int64 min_value, int64 max_value) const {
  if (min_value > max_value) throw_helper::throws(exception_case::argument_out_of_range);
  if (min_value == max_value) return min_value;
  return min_value + static_cast<int64>(math::round(sample() * (max_value - 1 - min_value)));
}

single random::next_single() const {
  return as<single>(sample());
}

double random::sample() const {
  auto distribution_ = std::uniform_real_distribution<> {0, 1};
  return distribution_(generator_);
}
