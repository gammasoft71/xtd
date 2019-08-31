#include "../../../include/xtd/drawing/solid_brush.hpp"
#include <xtd/drawing/native/brush.hpp>

using namespace xtd;
using namespace xtd::drawing;

solid_brush& solid_brush::color(const drawing::color& color) {
  if (this->data_->color_ != color) {
    this->data_->color_ = color;
    native::brush::color(this->brush::data_->handle_, color.a(), color.r(), color.g(), color.b());
  }
  return *this;
}

solid_brush::solid_brush(const solid_brush& value) : brush(value) {
  this->data_ = value.data_;
}

solid_brush& solid_brush::operator=(const solid_brush& value) {
  this->brush::operator=(value);
  this->data_ = value.data_;
  return *this;
}
