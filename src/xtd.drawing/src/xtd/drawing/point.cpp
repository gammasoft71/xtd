#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/size.h"
#include <cmath>

using namespace xtd;
using namespace xtd::drawing;

const point point::empty;

point::point(int32_t dw) noexcept : x_(dw & 0x0000FFFF), y_((dw & 0xFFFF0000) >> 16) {
}

point::point(int32_t x, int32_t y) noexcept : x_(x), y_(y) {
}

point::point(const size& size) noexcept : x_(size.width()), y_(size.height()) {
}

point::operator point_f() const noexcept {
  return point_f(static_cast<float>(x_), static_cast<float>(y_));
}

bool point::is_empty() const noexcept {
  return *this == point::empty;
}

int32_t point::x() const noexcept {
  return x_;
}

void point::x(int32_t x) noexcept {
  x_ = x;
}

int32_t point::y() const noexcept {
  return y_;
}

void point::y(int32_t y) noexcept {
  y_ = y;
}

point point::add(const point& pt, const size& sz) noexcept {
  return {pt.x_ + sz.width(), pt.y_ + sz.height()};
}

point point::add(const point& pt1, const point& pt2) noexcept {
  return pt1 + size(pt2);
}

point point::ceiling(const point_f& value) noexcept {
  return {int32_t(std::ceil(value.x())), int32_t(std::ceil(value.y()))};
}

void point::offset(int32_t dx, int32_t dy) noexcept {
  x_ += dx;
  y_ += dy;
}

void point::offset(const point& p) noexcept {
  offset(p.x_, p.y_);
}

point point::round(const point_f& value) noexcept {
  return {int32_t(std::round(value.x())), int32_t(std::round(value.y()))};
}

point point::subtract(const point& pt, const size& sz) noexcept {
  return {pt.x_ - sz.width(), pt.y_ - sz.height()};
}

point point::subtract(const point& pt1, const point& pt2) noexcept {
  return pt1 - size(pt2);
}

xtd::ustring point::to_string() const noexcept {
  return  ustring::format("{{x={}, y={}}}", x_, y_);
}

point point::truncate(const point_f& value) noexcept {
  return {int32_t(std::trunc(value.x())), int32_t(std::trunc(value.y()))};
}

bool point::operator ==(const point& value) const noexcept {
  return x_ == value.x_ && y_ == value.y_;
}

bool point::operator !=(const point& value) const noexcept {
  return !operator ==(value);
}

point point::operator +(const size& sz) const noexcept {
  return add(*this, sz);
}

point point::operator +(const point& pt) const noexcept {
  return add(*this, pt);
}

point& point::operator +=(const size& sz) noexcept {
  *this = add(*this, sz);
  return *this;
}

point& point::operator +=(const point& pt) noexcept {
  *this = add(*this, pt);
  return *this;
}

point point::operator -(const size& sz) const noexcept {
  return subtract(*this, sz);
}

point point::operator -(const point& pt) const noexcept {
  return subtract(*this, pt);
}

point& point::operator -=(const size& sz) noexcept {
  *this = subtract(*this, sz);
  return *this;
}

point& point::operator -=(const point& pt) noexcept {
  *this = subtract(*this, pt);
  return *this;
}
