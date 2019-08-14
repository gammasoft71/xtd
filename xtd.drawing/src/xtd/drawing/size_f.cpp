#include "../../../include/xtd/drawing/point_f.hpp"
#include "../../../include/xtd/drawing/size_f.hpp"

const xtd::drawing::size xtd::drawing::size_f::empty;

xtd::drawing::size::size_f(const xtd::drawing::point_f& point) : width_(point.x()), height_(point.y()) {
}

xtd::drawing::size xtd::drawing::size_f::operator+(const xtd::drawing::size_f& size) const {
  return {this->width_ + size.width_, this->height_ + size.height_};
}

xtd::drawing::size xtd::drawing::size_f::operator-(const xtd::drawing::size_f& size) const {
  return {this->width_ - size.width_, this->height_ - size.height_};
}

xtd::drawing::size& xtd::drawing::size_f::operator+=(const xtd::drawing::size_f& size) {
  this->width_ += size.width_;
  this->height_ += size.height_;
  return *this;
}

xtd::drawing::size& xtd::drawing::size_f::operator-=(const xtd::drawing::size_f& size) {
  this->width_ -= size.width_;
  this->height_ -= size.height_;
  return *this;
}

xtd::drawing::size xtd::drawing::size_f::add(const xtd::drawing::size_f& size1, const xtd::drawing::size_f& size2) {
  return size1 + size2;
}

xtd::drawing::size xtd::drawing::size_f::subtract(const xtd::drawing::size_f& size1, const xtd::drawing::size_f& size2) {
  return size1 - size2;
}
