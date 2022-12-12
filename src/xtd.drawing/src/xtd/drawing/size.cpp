#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/size.h"

using namespace xtd;
using namespace xtd::drawing;

const size size::empty;

size::size(const point& point) noexcept : width_(point.x()), height_(point.y()) {
}

size::size(int32 width, int32 height) noexcept : width_(width), height_(height) {
}

size::operator size_f() const noexcept {
  return size_f(static_cast<float>(width_), static_cast<float>(height_));
}

int32 size::height() const noexcept {
  return height_;
}

void size::height(int32 value) noexcept {
  height_ = value;
}

bool size::is_empty() const noexcept {
  return *this == size::empty;
}

int32 size::width() const noexcept {
  return width_;
}

void size::width(int32 value) noexcept {
  width_ = value;
}

size size::add(const size& size1, const size& size2) noexcept {
  return size1 + size2;
}

size size::ceiling(const size_f& value) noexcept {
  return {int32(std::ceil(value.width())), int32(std::ceil(value.height()))};
}

bool size::equals(const xtd::drawing::size& value) const noexcept {
  return width_ == value.width_ && height_ == value.height_;
}

size size::round(const size_f& value) noexcept {
  return {int32(std::round(value.width())), int32(std::round(value.height()))};
}

size size::truncate(const size_f& value)  noexcept {
  return {int32(std::trunc(value.width())), int32(std::trunc(value.height()))};
}

size size::subtract(const size& size1, const size& size2) noexcept {
  return size1 - size2;
}

xtd::ustring size::to_string() const noexcept {
  return ustring::format("{{width={}, height={}}}", width(), height());
}

size size::operator +(const size& size) const noexcept {
  return {width_ + size.width_, height_ + size.height_};
}

size& size::operator +=(const size& size) noexcept {
  width_ += size.width_;
  height_ += size.height_;
  return *this;
}

size size::operator -(const size& size) const noexcept {
  return {width_ - size.width_, height_ - size.height_};
}

size& size::operator -=(const size& size) noexcept {
  width_ -= size.width_;
  height_ -= size.height_;
  return *this;
}
