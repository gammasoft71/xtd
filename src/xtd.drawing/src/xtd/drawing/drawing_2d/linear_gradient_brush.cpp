#include "../../../../include/xtd/drawing/drawing_2d/linear_gradient_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <tuple>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct linear_gradient_brush::data {
  xtd::drawing::rectangle_f rect;
  float angle = 0;
  xtd::drawing::drawing_2d::gradient_stop_collection linear_colors;
};

linear_gradient_brush::linear_gradient_brush() : linear_gradient_brush(rectangle_f(.0f, .0f, .0f, .0f), {color::transparent, color::transparent}) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(point_f(as<float>(point1.x()), as<float>(point1.y())), point_f(as<float>(point2.x()), as<float>(point2.y())), {color1, color2}) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rectangle_f::from_ltrb(point1.x(), point1.y(), point2.x(), point2.y()), {color1, color2}, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rectangle_f(rect), {color1, color2}, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle): linear_gradient_brush(rectangle_f(rect), {color1, color2}, angle) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rect, {color1, color2}, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) : linear_gradient_brush(rect, {color1, color2}, angle) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : linear_gradient_brush(rect, {color1, color2}, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const xtd::drawing::color& color1, const xtd::drawing::color& color2)  : linear_gradient_brush(rect, {color1, color2}, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point& point1, const xtd::drawing::point& point2, const std::vector<xtd::drawing::color>& linear_colors) : linear_gradient_brush(point_f(as<float>(point1.x()), as<float>(point1.y())), point_f(as<float>(point2.x()), as<float>(point2.y())), linear_colors) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::point_f& point1, const xtd::drawing::point_f& point2, const std::vector<xtd::drawing::color>& linear_colors) : linear_gradient_brush(rectangle_f::from_ltrb(point1.x(), point1.y(), point2.x(), point2.y()), linear_colors, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rectangle_f(rect), linear_colors, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors, float angle): linear_gradient_brush(rectangle_f(rect), linear_colors, angle) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors, xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode) : linear_gradient_brush(rect, linear_colors, linear_gradient_mode_to_angle(linear_gradient_mode)) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors, float angle) : data_(std::make_shared<data>()) {
  if (linear_colors.size() < 2) throw argument_exception {csf_};
  while (angle < 0)
    angle = 360 - angle;
  while (angle >= 360)
    angle = angle - 360;
    
  data_->rect = rect;
  data_->angle = angle;
  
  auto pos = .0f;
  auto increment = 1.0f / (linear_colors.size() - 1);
  for (auto color : linear_colors) {
    data_->linear_colors.push_back({color, pos});
    pos += increment;
  }
  recreate_handle();
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::color>& linear_colors) : linear_gradient_brush(rect, linear_colors, .0) {
}

linear_gradient_brush::linear_gradient_brush(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::color>& linear_colors)  : linear_gradient_brush(rect, linear_colors, .0) {
}

linear_gradient_brush& linear_gradient_brush::operator =(const linear_gradient_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
}

float linear_gradient_brush::angle() const noexcept {
  return data_->angle;
}

linear_gradient_brush& linear_gradient_brush::angle(float value) noexcept {
  if (data_->angle != value) {
    data_->angle = value;
    recreate_handle();
  }
  return *this;
}

const gradient_stop_collection& linear_gradient_brush::linear_colors() const noexcept {
  return data_->linear_colors;
}

linear_gradient_brush& linear_gradient_brush::linear_colors(const gradient_stop_collection& value) {
  if (data_->linear_colors != value) {
    if (value.size() < 2) throw argument_exception {csf_};
    data_->linear_colors = value;
    recreate_handle();
  }
  return *this;
}

const rectangle_f& linear_gradient_brush::rectangle() const noexcept {
  return data_->rect;
}

linear_gradient_brush& linear_gradient_brush::rectangle(const rectangle_f& value) noexcept {
  if (data_->rect != value) {
    data_->rect = value;
    recreate_handle();
  }
  return *this;
}

bool linear_gradient_brush::equals(const linear_gradient_brush& value) const noexcept {
  return data_ == value.data_;
}

float linear_gradient_brush::linear_gradient_mode_to_angle(xtd::drawing::drawing_2d::linear_gradient_mode linear_gradient_mode) {
  switch (linear_gradient_mode) {
    case drawing_2d::linear_gradient_mode::horizontal : return 0.0;
    case drawing_2d::linear_gradient_mode::vertical : return 90.0;
    case drawing_2d::linear_gradient_mode::forward_diagonal : return 45.0;
    case drawing_2d::linear_gradient_mode::backward_diagonal : return 315.0;
  }
  throw argument_exception {csf_};
}

void linear_gradient_brush::recreate_handle() {
  auto colors = vector<tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte, float>> {};
  for_each(data_->linear_colors.begin(), data_->linear_colors.end(), [&](auto color) {colors.emplace_back(color.first.r(), color.first.g(), color.first.b(), color.first.a(), color.second);});
  native::brush::linear_gradient(handle(), as<int32>(data_->rect.left()), as<int32>(data_->rect.top()), as<int32>(data_->rect.right()), as<int32>(data_->rect.bottom()), colors, data_->angle);
}

linear_gradient_brush::linear_gradient_brush(const linear_gradient_brush& value) : brush(value), data_(value.data_) {
}
