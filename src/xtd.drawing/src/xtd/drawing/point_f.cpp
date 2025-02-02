#include "../../../include/xtd/drawing/point.hpp"
#include "../../../include/xtd/drawing/point_f.hpp"
#include "../../../include/xtd/drawing/size.hpp"
#include "../../../include/xtd/drawing/size_f.hpp"
#include <xtd/as>
#include <xtd/string>

using namespace xtd::drawing;

const point_f point_f::empty;

point_f::point_f(float x, float y) noexcept : x(x), y(y) {
}

point_f::point_f(const size_f& size) noexcept : x(size.width()), y(size.height()) {
}

bool point_f::is_empty() const noexcept {
  return *this == point_f::empty;
}

point_f point_f::add(const point_f& pt, const size& sz) noexcept {
  return {pt.x + as<float>(sz.width), pt.y + as<float>(sz.height)};
}

point_f point_f::add(const point_f& pt, const size_f& sz) noexcept {
  return {pt.x + sz.width(), pt.y + sz.height()};
}

point_f point_f::add(const point_f& pt1, const point& pt2) noexcept {
  return {pt1.x + as<float>(pt2.x), pt1.y + as<float>(pt2.y)};
}

point_f point_f::add(const point_f& pt1, const point_f& pt2) noexcept {
  return {pt1.x + pt2.x, pt1.y + pt2.y};
}

bool point_f::equals(const point_f& value) const noexcept {
  return x == value.x && y == value.y;
}

void point_f::offset(float dx, float dy) noexcept {
  x += dx;
  y += dy;
}

void point_f::offset(const point_f& pt) noexcept {
  offset(pt.x, pt.y);
}

point_f point_f::subtract(const point_f& pt, const size& sz) noexcept {
  return {pt.x - as<float>(sz.width), pt.y - as<float>(sz.height)};
}

point_f point_f::subtract(const point_f& pt, const size_f& sz) noexcept {
  return {pt.x - sz.width(), pt.y - sz.height()};
}

point_f point_f::subtract(const point_f& pt1, const point& pt2) noexcept {
  return {pt1.x - as<float>(pt2.x), pt1.y - as<float>(pt2.y)};
}

point_f point_f::subtract(const point_f& pt1, const point_f& pt2) noexcept {
  return {pt1.x - pt2.x, pt1.y - pt2.y};
}

xtd::string point_f::to_string() const noexcept {
  return  string::format("{{x={}, y={}}}", x, y);
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
