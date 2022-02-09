#include "../../../../include/xtd/drawing/drawing2d/radial_gradient_brush.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <tuple>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : radial_gradient_brush(point_f(as<float>(point1.x()), as<float>(point1.y())), point_f(as<float>(point2.x()), as<float>(point2.y())), {color1, color2}) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : radial_gradient_brush(rectangle_f::from_ltrb(point1.x(), point1.y(), point2.x(), point2.y()), {color1, color2}, .0) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius): radial_gradient_brush(rectangle_f(rect), {color1, color2}, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius) : radial_gradient_brush(rect, {color1, color2}, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : radial_gradient_brush(rect, {color1, color2}, .0) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2)  : radial_gradient_brush(rect, {color1, color2}, .0) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const std::vector<xtd::drawing::color>& radial_colors) : radial_gradient_brush(point_f(as<float>(point1.x()), as<float>(point1.y())), point_f(as<float>(point2.x()), as<float>(point2.y())), radial_colors) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const std::vector<xtd::drawing::color>& radial_colors) : radial_gradient_brush(rectangle_f::from_ltrb(point1.x(), point1.y(), point2.x(), point2.y()), radial_colors, .0) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& radial_colors, float radius): radial_gradient_brush(rectangle_f(rect), radial_colors, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& radial_colors, float radius) {
  if (radial_colors.size() < 2) throw argument_exception(csf_);
  
  data_->rect = rect;
  data_->radius = radius;
  data_->radial_colors = radial_colors;
  recreate_handle();
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& radial_colors) : radial_gradient_brush(rect, radial_colors, .0) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& radial_colors)  : radial_gradient_brush(rect, radial_colors, .0) {
}

radial_gradient_brush::radial_gradient_brush() {
}

radial_gradient_brush& radial_gradient_brush::radial_colors(const std::vector<xtd::drawing::color>& radial_colors) {
  if (data_->radial_colors != radial_colors) {
    if (radial_colors.size() < 2) throw argument_exception(csf_);
    data_->radial_colors = radial_colors;
    recreate_handle();
  }
  return *this;
}

const std::vector<xtd::drawing::color>& radial_gradient_brush::radial_colors() const noexcept {
  return data_->radial_colors;
}

xtd::drawing::rectangle_f radial_gradient_brush::rectangle() const noexcept {
  return data_->rect;
}

void radial_gradient_brush::recreate_handle() {
  vector<tuple<uint8_t, uint8_t, uint8_t, uint8_t>> colors;
  
  for (auto color : data_->radial_colors)
    colors.push_back(make_tuple(color.r(), color.g(), color.b(), color.a()));
  
  native::brush::radial_gradient(brush::data_->handle_, as<int32_t>(data_->rect.left()), as<int32_t>(data_->rect.top()), as<int32_t>(data_->rect.right()), as<int32_t>(data_->rect.bottom()), colors, data_->radius);
}

radial_gradient_brush::radial_gradient_brush(const radial_gradient_brush& value) : brush(value), data_(value.data_) {
}

radial_gradient_brush& radial_gradient_brush::operator=(const radial_gradient_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}
