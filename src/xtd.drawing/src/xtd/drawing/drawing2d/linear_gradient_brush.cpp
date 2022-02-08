#include "../../../../include/xtd/drawing/drawing2d/linear_gradient_brush.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(point_f(as<float>(point1.x()), as<float>(point1.y())), point_f(as<float>(point2.x()), as<float>(point2.y())), color1, color2) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rectangle_f::from_ltrb(point1.x(), point1.y(), point2.x(), point2.y()), color1, color2, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rectangle_f(rect), color1, color2, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle): linear_gradient_brush(rectangle_f(rect), color1, color2, angle) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rect, color1, color2, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) {
  while (angle < 0)
    angle = 360 - angle;
  while (angle >= 360)
    angle = angle - 360;
  
  data_->rect = rect;
  data_->angle = angle;
  data_->linear_colors_ = {color1, color2};
  recreate_handle();
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rect, color1, color2, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2)  : linear_gradient_brush(rect, color1, color2, .0) {
}

linear_gradient_brush::linear_gradient_brush() {
}

linear_gradient_brush& linear_gradient_brush::linear_colors(const std::array<xtd::drawing::color, 2>& linear_colors) {
  if (data_->linear_colors_ != linear_colors) {
    data_->linear_colors_ = linear_colors;
    recreate_handle();
  }
  return *this;
}

const std::array<xtd::drawing::color, 2>& linear_gradient_brush::linear_colors() const noexcept {
  return data_->linear_colors_;
}

std::array<xtd::drawing::color, 2>& linear_gradient_brush::linear_colors() noexcept {
  return data_->linear_colors_;
}

xtd::drawing::rectangle_f linear_gradient_brush::rectangle() const noexcept {
  return data_->rect;
}

float linear_gradient_brush::linear_gradient_mode_to_angle(xtd::drawing::drawing2d::linear_gradient_mode linear_gradient_mode) {
  switch (linear_gradient_mode) {
    case drawing2d::linear_gradient_mode::horizontal : return 0.0;
    case drawing2d::linear_gradient_mode::vertical : return 90.0;
    case drawing2d::linear_gradient_mode::forward_diagonal : return 45.0;
    case drawing2d::linear_gradient_mode::backward_diagonal : return 315.0;
  }
  throw argument_exception(csf_);
}

void linear_gradient_brush::recreate_handle() {
  native::brush::linear_gradient(brush::data_->handle_, as<int32_t>(data_->rect.left()), as<int32_t>(data_->rect.top()), as<int32_t>(data_->rect.right()), as<int32_t>(data_->rect.bottom()), data_->linear_colors_[0].a(), data_->linear_colors_[0].r(), data_->linear_colors_[0].g(), data_->linear_colors_[0].b(), data_->linear_colors_[1].a(), data_->linear_colors_[1].r(), data_->linear_colors_[1].g(), data_->linear_colors_[1].b(), data_->angle);
}

linear_gradient_brush::linear_gradient_brush(const linear_gradient_brush& value) : brush(value), data_(value.data_) {
}

linear_gradient_brush& linear_gradient_brush::operator=(const linear_gradient_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}
