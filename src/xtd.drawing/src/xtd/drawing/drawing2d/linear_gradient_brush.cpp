#include "../../../../include/xtd/drawing/drawing2d/linear_gradient_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

linear_gradient_brush::linear_gradient_brush() {
  data_->linear_colors_ = {color::black, color::black};
  recreate_handle();
}

linear_gradient_brush& linear_gradient_brush::linear_colors(const std::array<xtd::drawing::color, 2>& linear_colors) {
  if (data_->linear_colors_ != linear_colors) {
    data_->linear_colors_ = linear_colors;
    recreate_handle();
  }
  return *this;
}

xtd::drawing::rectangle_f linear_gradient_brush::rectangle() const {
  auto x = std::min(data_->point1_.x(), data_->point2_.x());
  auto y = std::min(data_->point1_.y(), data_->point2_.y());
  auto width = std::max(data_->point1_.x(), data_->point2_.x()) - x;
  auto height = std::max(data_->point1_.y(), data_->point2_.y()) - y;
  if (width == 0) width = height;
  if (height == 0) height = width;
  return xtd::drawing::rectangle_f(x, y, width, height);
}

void linear_gradient_brush::recreate_handle() {
  native::brush::linear_gradient(brush::data_->handle_, static_cast<int32_t>(data_->point1_.x()), static_cast<int32_t>(data_->point1_.y()), static_cast<int32_t>(data_->point2_.x()), static_cast<int32_t>(data_->point2_.y()), data_->linear_colors_[0].a(), data_->linear_colors_[0].r(), data_->linear_colors_[0].g(), data_->linear_colors_[0].b(), data_->linear_colors_[1].a(), data_->linear_colors_[1].r(), data_->linear_colors_[1].g(), data_->linear_colors_[1].b());
}

linear_gradient_brush::linear_gradient_brush(const linear_gradient_brush& value) : brush(value) {
  data_ = value.data_;
}

linear_gradient_brush& linear_gradient_brush::operator=(const linear_gradient_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}
