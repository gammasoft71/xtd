#include "../../../include/xtd/drawing/point.hpp"
#include "../../../include/xtd/drawing/size.hpp"

using namespace xtd::drawing;

const size size::empty;

size::size(const point& point) : width_(point.x()), height_(point.y()) {
}

size size::operator+(const size& size) const {
  return {this->width_ + size.width_, this->height_ + size.height_};
}

size size::operator-(const size& size) const {
  return {this->width_ - size.width_, this->height_ - size.height_};
}

size& size::operator+=(const size& size) {
  this->width_ += size.width_;
  this->height_ += size.height_;
  return *this;
}

size& size::operator-=(const size& size) {
  this->width_ -= size.width_;
  this->height_ -= size.height_;
  return *this;
}

size size::add(const size& size1, const size& size2) {
  return size1 + size2;
}

size size::subtract(const size& size1, const size& size2) {
  return size1 - size2;
}
