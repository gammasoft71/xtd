#include "../../../../include/xtd/forms/style_sheets/length.h"
#include <xtd/as.h>
#include <xtd/is.h>

using namespace xtd;
using namespace xtd::forms::style_sheets;

length::length(double value) : value_(value) {
}

length::length(double value, length_unit unit) : value_(value), unit_(unit) {
}

double length::value() const noexcept {
  return value_;
}

void length::value(double value) noexcept {
  value_ = value;
}

length_unit length::unit() const noexcept {
  return unit_;
}

void length::unit(length_unit value) noexcept {
  unit_ = value;
}

bool length::equals(const object& other) const noexcept {
  return is<length>(other) ? equals(static_cast<const length&>(other)) : false;
}

bool length::equals(const length& other) const noexcept {
  return value_ == other.value_ && unit_ == other.unit_;
}

int32_t length::get_pixels(const xtd::drawing::rectangle& rect) const noexcept {
  if (unit() == length_unit::centimeters) return as<int32_t>(value() / 2.54 * 96.0);
  if (unit() == length_unit::millimeters) return as<int32_t>(value() / 2.54 * 96.0 * 1000.0);
  if (unit() == length_unit::inches) return as<int32_t>(value() * 96.0);
  if (unit() == length_unit::pixels) return as<int32_t>(value());
  if (unit() == length_unit::points) return as<int32_t>(value() / 96.0 * 72.0);
  if (unit() == length_unit::picas) return as<int32_t>(value() * 12.0 / 96.0 * 72.0);
  return 0;
}
