#include "../include/xtd/point.hpp"
#include "../include/xtd/size.hpp"

const xtd::drawing::size xtd::drawing::size::empty;

xtd::drawing::size::size(const xtd::drawing::point& point) : width_(point.x()), height_(point.y()) {
}

xtd::drawing::size xtd::drawing::size::operator+(const xtd::drawing::size& size) const {
  return {this->width_ + size.width_, this->height_ + size.height_};
}

xtd::drawing::size xtd::drawing::size::operator-(const xtd::drawing::size& size) const {
  return {this->width_ - size.width_, this->height_ - size.height_};
}

xtd::drawing::size& xtd::drawing::size::operator+=(const xtd::drawing::size& size) {
  this->width_ += size.width_;
  this->height_ += size.height_;
  return *this;
}

xtd::drawing::size& xtd::drawing::size::operator-=(const xtd::drawing::size& size) {
  this->width_ -= size.width_;
  this->height_ -= size.height_;
  return *this;
}

xtd::drawing::size xtd::drawing::size::add(const xtd::drawing::size& size1, const xtd::drawing::size& size2) {
  return size1 + size2;
}

xtd::drawing::size xtd::drawing::size::subtract(const xtd::drawing::size& size1, const xtd::drawing::size& size2) {
  return size1 - size2;
}
