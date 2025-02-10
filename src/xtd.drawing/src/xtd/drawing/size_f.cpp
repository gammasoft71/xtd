#include "../../../include/xtd/drawing/point_f.hpp"
#include "../../../include/xtd/drawing/size_f.hpp"
#include "../../../include/xtd/drawing/size.hpp"
#include <xtd/as>

using namespace xtd::drawing;

const size_f size_f::empty;

size_f::size_f(const point_f& point) noexcept : height(point.y), width(point.x) {
}

size_f::size_f(float width, float height) noexcept : height(height), width(width) {
}

bool size_f::is_empty() const noexcept {
  return *this == size_f::empty;
}

size_f size_f::add(const size_f& size1, const size_f& size2) noexcept {
  return size1 + size2;
}

bool size_f::equals(const object& obj) const noexcept {
  return is<size_f>(obj) && equals(static_cast<const size_f&>(obj));
}

bool size_f::equals(const xtd::drawing::size_f& value) const noexcept {
  return width == value.width && height == value.height;
}

xtd::size size_f::get_hash_code() const noexcept {
  return hash_code::combine(width, height);
}

size_f size_f::subtract(const size_f& size1, const size_f& size2) noexcept {
  return size1 - size2;
}

xtd::string size_f::to_string() const noexcept {
  return string::format("{{width={}, height={}}}", width, height);
}

size_f size_f::operator +(const size_f& size) const noexcept {
  return {width + size.width, height + size.height};
}

size_f size_f::operator +(const size& size) const noexcept {
  return {width + as<float>(size.width), height + as<float>(size.height)};
}

size_f& size_f::operator +=(const size_f& size) noexcept {
  width += size.width;
  height += size.height;
  return *this;
}

size_f& size_f::operator +=(const size& size) noexcept {
  width += as<float>(size.width);
  height += as<float>(size.height);
  return *this;
}

size_f size_f::operator -(const size_f& size) const noexcept {
  return {width - size.width, height - size.height};
}

size_f size_f::operator -(const size& size) const noexcept {
  return {width - as<float>(size.width), height - as<float>(size.height)};
}

size_f& size_f::operator -=(const size_f& size) noexcept {
  width -= size.width;
  height -= size.height;
  return *this;
}

size_f& size_f::operator -=(const size& size) noexcept {
  width -= as<float>(size.width);
  height -= as<float>(size.height);
  return *this;
}
