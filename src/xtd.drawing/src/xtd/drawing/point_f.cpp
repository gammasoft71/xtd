#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/point_f.h"
#include "../../../include/xtd/drawing/size.h"
#include "../../../include/xtd/drawing/size_f.h"
#include <xtd/as>
#include <xtd/ustring>

using namespace xtd::drawing;

const point_f point_f::empty;

point_f::point_f(float x, float y) noexcept : x_(x), y_(y) {
}

point_f::point_f(const size_f& size) noexcept : x_(size.width()), y_(size.height()) {
}

bool point_f::is_empty() const noexcept {
  return *this == point_f::empty;
}

float point_f::x() const noexcept {
  return x_;
}

void point_f::x(float x) noexcept {
  x_ = x;
}

float point_f::y() const noexcept {
  return y_;
}

void point_f::y(float y) noexcept {
  y_ = y;
}

point_f point_f::add(const point_f& pt, const size& sz) noexcept {
  return {pt.x() + as<float>(sz.width()), pt.y() + as<float>(sz.height())};
}

point_f point_f::add(const point_f& pt, const size_f& sz) noexcept {
  return {pt.x() + sz.width(), pt.y() + sz.height()};
}

point_f point_f::add(const point_f& pt1, const point& pt2) noexcept {
  return {pt1.x() + as<float>(pt2.x()), pt1.y() + as<float>(pt2.y())};
}

point_f point_f::add(const point_f& pt1, const point_f& pt2) noexcept {
  return {pt1.x() + pt2.x(), pt1.y() + pt2.y()};
}

bool point_f::equals(const point_f& value) const noexcept {
  return x_ == value.x_ && y_ == value.y_;
}

void point_f::offset(float dx, float dy) noexcept {
  x_ += dx;
  y_ += dy;
}

void point_f::offset(const point_f& pt) noexcept {
  offset(pt.x_, pt.y_);
}

point_f point_f::subtract(const point_f& pt, const size& sz) noexcept {
  return {pt.x() - as<float>(sz.width()), pt.y() - as<float>(sz.height())};
}

point_f point_f::subtract(const point_f& pt, const size_f& sz) noexcept {
  return {pt.x() - sz.width(), pt.y() - sz.height()};
}

point_f point_f::subtract(const point_f& pt1, const point& pt2) noexcept {
  return {pt1.x() - as<float>(pt2.x()), pt1.y() - as<float>(pt2.y())};
}

point_f point_f::subtract(const point_f& pt1, const point_f& pt2) noexcept {
  return {pt1.x() - pt2.x(), pt1.y() - pt2.y()};
}

xtd::ustring point_f::to_string() const noexcept {
  return  ustring::format("{{x={}, y={}}}", x_, y_);
}

point_f point_f::operator +(const size& sz) const noexcept {
  return add(*this, sz);
}

point_f point_f::operator +(const size_f& sz) const noexcept {
  return add(*this, sz);
}

point_f point_f::operator +(const point& pt) const noexcept {
  return add(*this, pt);
}

point_f point_f::operator +(const point_f& pt) const noexcept {
  return add(*this, pt);
}

point_f& point_f::operator +=(const size& sz) noexcept {
  *this = add(*this, sz);
  return *this;
}

point_f& point_f::operator +=(const size_f& sz) noexcept {
  *this = add(*this, sz);
  return *this;
}

point_f& point_f::operator +=(const point& pt) noexcept {
  *this = add(*this, pt);
  return *this;
}

point_f& point_f::operator +=(const point_f& pt) noexcept {
  *this = add(*this, pt);
  return *this;
}

point_f point_f::operator -(const size& sz) const noexcept {
  return subtract(*this, sz);
}

point_f point_f::operator -(const size_f& sz) const noexcept {
  return subtract(*this, sz);
}

point_f point_f::operator -(const point& pt) const noexcept {
  return subtract(*this, pt);
}

point_f point_f::operator -(const point_f& pt) const noexcept {
  return subtract(*this, pt);
}

point_f& point_f::operator -=(const size& sz) noexcept {
  *this = subtract(*this, sz);
  return *this;
}

point_f& point_f::operator -=(const size_f& sz) noexcept {
  *this = subtract(*this, sz);
  return *this;
}

point_f& point_f::operator -=(const point& pt) noexcept {
  *this = subtract(*this, pt);
  return *this;
}

point_f& point_f::operator -=(const point_f& pt) noexcept {
  *this = subtract(*this, pt);
  return *this;
}
