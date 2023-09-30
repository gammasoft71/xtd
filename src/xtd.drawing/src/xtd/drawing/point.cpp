#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/size.h"
#include <xtd/as>
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;

const point point::empty;

point::point(int32 dw) noexcept : x_(dw & 0x0000FFFF), y_((dw & 0xFFFF0000) >> 16) {
}

point::point(int32 x, int32 y) noexcept : x_(x), y_(y) {
}

point::point(const size& size) noexcept : x_(size.width()), y_(size.height()) {
}

point::operator point_f() const noexcept {
  return point_f(as<float>(x_), as<float>(y_));
}

bool point::is_empty() const noexcept {
  return *this == point::empty;
}

int32 point::x() const noexcept {
  return x_;
}

void point::x(int32 x) noexcept {
  x_ = x;
}

int32 point::y() const noexcept {
  return y_;
}

void point::y(int32 y) noexcept {
  y_ = y;
}

point point::add(const point& pt, const size& sz) noexcept {
  return {pt.x_ + sz.width(), pt.y_ + sz.height()};
}

point point::add(const point& pt1, const point& pt2) noexcept {
  return pt1 + size {pt2};
}

point point::ceiling(const point_f& value) noexcept {
  return {as<int32>(math::ceiling(value.x())), as<int32>(math::ceiling(value.y()))};
}

bool point::equals(const point& value) const noexcept {
  return x_ == value.x_ && y_ == value.y_;
}

void point::offset(int32 dx, int32 dy) noexcept {
  x_ += dx;
  y_ += dy;
}

void point::offset(const point& p) noexcept {
  offset(p.x_, p.y_);
}

point point::round(const point_f& value) noexcept {
  return {as<int32>(math::round(value.x())), as<int32>(math::round(value.y()))};
}

point point::subtract(const point& pt, const size& sz) noexcept {
  return {pt.x_ - sz.width(), pt.y_ - sz.height()};
}

point point::subtract(const point& pt1, const point& pt2) noexcept {
  return pt1 - size {pt2};
}

xtd::ustring point::to_string() const noexcept {
  return  ustring::format("{{x={}, y={}}}", x_, y_);
}

point point::truncate(const point_f& value) noexcept {
  return {as<int32>(math::truncate(value.x())), as<int32>(math::truncate(value.y()))};
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
