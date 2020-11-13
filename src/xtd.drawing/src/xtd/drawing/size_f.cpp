#include "../../../include/xtd/drawing/point_f.h"
#include "../../../include/xtd/drawing/size_f.h"

using namespace xtd::drawing;

const size_f size_f::empty;

size_f::size_f(const point_f& point) : width_(point.x()), height_(point.y()) {
}

size_f size_f::operator+(const size_f& size) const {
  return {this->width_ + size.width_, this->height_ + size.height_};
}

size_f size_f::operator-(const size_f& size) const {
  return {this->width_ - size.width_, this->height_ - size.height_};
}

size_f& size_f::operator+=(const size_f& size) {
  this->width_ += size.width_;
  this->height_ += size.height_;
  return *this;
}

size_f& size_f::operator-=(const size_f& size) {
  this->width_ -= size.width_;
  this->height_ -= size.height_;
  return *this;
}

size_f size_f::add(const size_f& size1, const size_f& size2) {
  return size1 + size2;
}

size_f size_f::subtract(const size_f& size1, const size_f& size2) {
  return size1 - size2;
}
