#include "../../../../include/xtd/drawing/drawing2d/linear_gradient_brush.h"
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

linear_gradient_brush::linear_gradient_brush() {
  data_->linear_colors_ = {color::black, color::black};
  recreate_handle();
}

linear_gradient_brush& linear_gradient_brush::rectangle(const drawing::rectangle_f& rect) {
  if (data_->rect_ != rect) {
    data_->rect_ = rect;
    recreate_handle();
  }
  return *this;
}

linear_gradient_brush& linear_gradient_brush::linear_colors(const std::array<xtd::drawing::color, 2>& linear_colors) {
  if (data_->linear_colors_ != linear_colors) {
    data_->linear_colors_ = linear_colors;
    recreate_handle();
  }
  return *this;
}

void linear_gradient_brush::recreate_handle() {
  native::brush::linear_gradient(brush::data_->handle_, static_cast<int32_t>(data_->rect_.x()), static_cast<int32_t>(data_->rect_.y()), static_cast<int32_t>(data_->rect_.right()), static_cast<int32_t>(data_->rect_.bottom()), data_->linear_colors_[0].a(), data_->linear_colors_[0].r(), data_->linear_colors_[0].g(), data_->linear_colors_[0].b(), data_->linear_colors_[1].a(), data_->linear_colors_[1].r(), data_->linear_colors_[1].g(), data_->linear_colors_[1].b());
}

linear_gradient_brush::linear_gradient_brush(const linear_gradient_brush& value) : brush(value) {
  data_ = value.data_;
}

linear_gradient_brush& linear_gradient_brush::operator=(const linear_gradient_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}

