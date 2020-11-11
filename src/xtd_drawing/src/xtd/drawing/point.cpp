#include "../../../include/xtd/drawing/point.h"
#include "../../../include/xtd/drawing/size.h"
#include <cmath>

using namespace xtd;
using namespace xtd::drawing;

const point point::empty;

point::point(const size& size) : x_(size.width()), y_(size.height()) {
}

point point::add(const point& pt, const size& sz) {
  return {pt.x_ + sz.width(), pt.y_ + sz.height()};
}

point point::add(const point& pt1, const point& pt2) {
  return pt1 + size(pt2);
}

point point::ceiling(const point_f& value) {
  return {int32_t(std::ceil(value.x())), int32_t(std::ceil(value.y()))};
}

point point::round(const point_f& value) {
  return {int32_t(std::round(value.x())), int32_t(std::round(value.y()))};
}

point point::subtract(const point& pt, const size& sz) {
  return {pt.x_ - sz.width(), pt.y_ - sz.height()};
}

point point::subtract(const point& pt1, const point& pt2) {
  return pt1 - size(pt2);
}

point point::truncate(const point_f& value) {
  return {int32_t(std::trunc(value.x())), int32_t(std::trunc(value.y()))};
}

point point::operator+(const size& sz) const {
  return add(*this, sz);
}

point point::operator+(const point& pt) const {
  return add(*this, pt);
}

point& point::operator+=(const size& sz) {
  *this = add(*this, sz);
  return *this;
}

point& point::operator+=(const point& pt) {
  *this = add(*this, pt);
  return *this;
}

point point::operator-(const size& sz) const {
  return subtract(*this, sz);
}

point point::operator-(const point& pt) const {
  return subtract(*this, pt);
}

point& point::operator-=(const size& sz) {
  *this = subtract(*this, sz);
  return *this;
}

point& point::operator-=(const point& pt) {
  *this = subtract(*this, pt);
  return *this;
}
