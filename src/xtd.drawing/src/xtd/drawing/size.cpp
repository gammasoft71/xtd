#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/size.h"

using namespace xtd::drawing;

const size size::empty;

size::size(const point& point) noexcept : width_(point.x()), height_(point.y()) {
}

size::size(int32_t width, int32_t height) noexcept : width_(width), height_(height) {
}

bool size::operator ==(const xtd::drawing::size& value) const noexcept {
  return width_ == value.width_ && height_ == value.height_;
}

bool size::operator !=(const xtd::drawing::size& value) const noexcept {
  return !operator ==(value);
}

size size::operator +(const size& size) const noexcept {
  return {width_ + size.width_, height_ + size.height_};
}

size size::operator -(const size& size) const noexcept {
  return {width_ - size.width_, height_ - size.height_};
}

size& size::operator +=(const size& size) noexcept {
  width_ += size.width_;
  height_ += size.height_;
  return *this;
}

size& size::operator -=(const size& size) noexcept {
  width_ -= size.width_;
  height_ -= size.height_;
  return *this;
}

size::operator size_f() const noexcept {
  return size_f(static_cast<float>(width_), static_cast<float>(height_));
}

int32_t size::height() const noexcept {
  return height_;
}

void size::height(int32_t value) noexcept {
  height_ = value;
}

bool size::is_empty() const noexcept {
  return *this == size::empty;
}

int32_t size::width() const noexcept {
  return width_;
}

void size::width(int32_t value) noexcept {
  width_ = value;
}

size size::add(const size& size1, const size& size2) noexcept {
  return size1 + size2;
}

size size::ceiling(const size_f& value) noexcept {
  return {int32_t(std::ceil(value.width())), int32_t(std::ceil(value.height()))};
}

size size::round(const size_f& value) noexcept {
  return {int32_t(std::round(value.width())), int32_t(std::round(value.height()))};
}

size size::truncate(const size_f& value)  noexcept {
  return {int32_t(std::trunc(value.width())), int32_t(std::trunc(value.height()))};
}

size size::subtract(const size& size1, const size& size2) noexcept {
  return size1 - size2;
}

xtd::ustring size::to_string() const noexcept {
  return ustring::format("{{width={}, height={}}}", width(), height());
}
