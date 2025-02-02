#include "../../../include/xtd/drawing/point.hpp"
#include "../../../include/xtd/drawing/size.hpp"
#include <xtd/as>
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;

const drawing::size drawing::size::empty;

drawing::size::size(const point& point) noexcept : height(point.y), width(point.x) {
}

drawing::size::size(int32 width, int32 height) noexcept : height(height), width(width) {
}

drawing::size::operator size_f() const noexcept {
  return size_f(static_cast<float>(width), static_cast<float>(height));
}

bool drawing::size::is_empty() const noexcept {
  return *this == size::empty;
}

drawing::size drawing::size::add(const drawing::size& size1, const drawing::size& size2) noexcept {
  return size1 + size2;
}

drawing::size drawing::size::ceiling(const size_f& value) noexcept {
  return {as<int32>(math::ceiling(value.width)), as<int32>(math::ceiling(value.height))};
}

bool drawing::size::equals(const xtd::drawing::size& value) const noexcept {
  return width == value.width && height == value.height;
}

drawing::size drawing::size::round(const size_f& value) noexcept {
  return {as<int32>(math::round(value.width)), as<int32>(math::round(value.height))};
}

drawing::size drawing::size::truncate(const size_f& value)  noexcept {
  return {as<int32>(math::truncate(value.width)), as<int32>(math::truncate(value.height))};
}

drawing::size drawing::size::subtract(const drawing::size& size1, const drawing::size& size2) noexcept {
  return size1 - size2;
}

xtd::string drawing::size::to_string() const noexcept {
  return string::format("{{width={}, height={}}}", width, height);
}

drawing::size drawing::size::operator +(const drawing::size& size) const noexcept {
  return {width + size.width, height + size.height};
}

drawing::size& drawing::size::operator +=(const drawing::size& size) noexcept {
  width += size.width;
  height += size.height;
  return *this;
}

drawing::size drawing::size::operator -(const drawing::size& size) const noexcept {
  return {width - size.width, height - size.height};
}

drawing::size& drawing::size::operator -=(const drawing::size& size) noexcept {
  width -= size.width;
  height -= size.height;
  return *this;
}
