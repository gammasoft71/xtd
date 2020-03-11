#include "../../../include/xtd/drawing/solid_brush.h"
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;

solid_brush::solid_brush() {
  this->color(drawing::color::black);
}
  
solid_brush& solid_brush::color(const drawing::color& color) {
  if (this->data_->color_ != color) {
    this->data_->color_ = color;
    native::brush::color(this->brush::data_->handle_, this->data_->color_.a(), this->data_->color_.r(), this->data_->color_.g(), this->data_->color_.b());
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
