#include "../../../../include/xtd/drawing/drawing2d/linear_gradient_brush.h"
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

linear_gradient_brush::linear_gradient_brush() {
  data_->color1_ = color::black;
  data_->color2_ = color::black;
  recreate_handle();
}

linear_gradient_brush& linear_gradient_brush::point1(const drawing::point& point1) {
  if (data_->point1_ != point1) {
    data_->point1_ = point1;
    recreate_handle();
  }
  return *this;
}

linear_gradient_brush& linear_gradient_brush::point2(const drawing::point& point2) {
  if (data_->point2_ != point2) {
    data_->point2_ = point2;
    recreate_handle();
  }
  return *this;
}

linear_gradient_brush& linear_gradient_brush::color1(const drawing::color& color1) {
  if (data_->color1_ != color1) {
    data_->color1_ = color1;
    recreate_handle();
  }
  return *this;
}

linear_gradient_brush& linear_gradient_brush::color2(const drawing::color& color2) {
  if (data_->color2_ != color2) {
    data_->color2_ = color2;
    recreate_handle();
  }
  return *this;
}

void linear_gradient_brush::recreate_handle() {
  native::brush::linear_gradient(brush::data_->handle_, data_->point1_.x(), data_->point1_.y(), data_->point2_.x(), data_->point2_.y(), data_->color1_.a(), data_->color1_.r(), data_->color1_.g(), data_->color1_.b(), data_->color2_.a(), data_->color2_.r(), data_->color2_.g(), data_->color2_.b());
}

linear_gradient_brush::linear_gradient_brush(const linear_gradient_brush& value) : brush(value) {
  this->data_ = value.data_;
}

linear_gradient_brush& linear_gradient_brush::operator=(const linear_gradient_brush& value) {
  this->brush::operator=(value);
  this->data_ = value.data_;
  return *this;
}

