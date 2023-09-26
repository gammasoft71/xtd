#include "../../../include/xtd/drawing/point"
#include "../../../include/xtd/drawing/size"
#include <xtd/as>
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;

const drawing::size drawing::size::empty;

drawing::size::size(const point& point) noexcept : width_(point.x()), height_(point.y()) {
}

drawing::size::size(int32 width, int32 height) noexcept : width_(width), height_(height) {
}

drawing::size::operator size_f() const noexcept {
  return size_f(static_cast<float>(width_), static_cast<float>(height_));
}

int32 drawing::size::height() const noexcept {
  return height_;
}

void drawing::size::height(int32 value) noexcept {
  height_ = value;
}

bool drawing::size::is_empty() const noexcept {
  return *this == size::empty;
}

int32 drawing::size::width() const noexcept {
  return width_;
}

void drawing::size::width(int32 value) noexcept {
  width_ = value;
}

drawing::size drawing::size::add(const drawing::size& size1, const drawing::size& size2) noexcept {
  return size1 + size2;
}

drawing::size drawing::size::ceiling(const size_f& value) noexcept {
  return {as<int32>(math::ceiling(value.width())), as<int32>(math::ceiling(value.height()))};
}

bool drawing::size::equals(const xtd::drawing::size& value) const noexcept {
  return width_ == value.width_ && height_ == value.height_;
}

drawing::size drawing::size::round(const size_f& value) noexcept {
  return {as<int32>(math::round(value.width())), as<int32>(math::round(value.height()))};
}

drawing::size drawing::size::truncate(const size_f& value)  noexcept {
  return {as<int32>(math::truncate(value.width())), as<int32>(math::truncate(value.height()))};
}

drawing::size drawing::size::subtract(const drawing::size& size1, const drawing::size& size2) noexcept {
  return size1 - size2;
}

xtd::ustring drawing::size::to_string() const noexcept {
  return ustring::format("{{width={}, height={}}}", width(), height());
}

drawing::size drawing::size::operator +(const drawing::size& size) const noexcept {
  return {width_ + size.width_, height_ + size.height_};
}

drawing::size& drawing::size::operator +=(const drawing::size& size) noexcept {
  width_ += size.width_;
  height_ += size.height_;
  return *this;
}

drawing::size drawing::size::operator -(const drawing::size& size) const noexcept {
  return {width_ - size.width_, height_ - size.height_};
}

drawing::size& drawing::size::operator -=(const drawing::size& size) noexcept {
  width_ -= size.width_;
  height_ -= size.height_;
  return *this;
}
