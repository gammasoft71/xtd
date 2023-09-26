#include "../../../../include/xtd/forms/style_sheets/length"
#include <xtd/as>
#include <xtd/is>
#include <xtd/math>

using namespace xtd;
using namespace xtd::forms::style_sheets;

const length length::empty;

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

bool length::equals(const length& other) const noexcept {
  return value_ == other.value_ && unit_ == other.unit_;
}

int32 length::get_pixels(const xtd::drawing::rectangle& rect) const noexcept {
  switch (unit()) {
    case length_unit::centimeters: return as<int32>(value() / 2.54 * 96.0);
    case length_unit::millimeters: return as<int32>(value() / 2.54 * 96.0 * 1000.0);
    case length_unit::inches: return as<int32>(value() * 96.0);
    case length_unit::pixels: return as<int32>(value());
    case length_unit::points: return as<int32>(value() / 96.0 * 72.0);
    case length_unit::picas: return as<int32>(value() * 12.0 / 96.0 * 72.0);
    case length_unit::element: return as<int32>(rect.width() / 100.0 * value());
    case length_unit::element_x_height: return as<int32>(rect.height() / 100.0 * value());
    case length_unit::chase: return as<int32>(rect.height() / 100.0 * value());
    case length_unit::root_element: return as<int32>(rect.width() / 100.0 * value());
    case length_unit::viewport_width: return as<int32>(rect.width() / 100.0 * value());
    case length_unit::viewport_height: return as<int32>(rect.height() / 100.0 * value());
    case length_unit::viewport_min: return as<int32>(math::min(rect.width(), rect.height()) / 100.0 * value());
    case length_unit::viewport_max: return as<int32>(math::max(rect.width(), rect.height()) / 100.0 * value());
    case length_unit::percent: return as<int32>(rect.height() / 100.0 * value());
  }
  return 0;
}

xtd::ustring length::to_string() const noexcept {
  return ustring::format("{} {}", value(), unit());
}
