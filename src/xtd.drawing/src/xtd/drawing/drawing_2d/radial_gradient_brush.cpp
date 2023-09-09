#include "../../../../include/xtd/drawing/drawing_2d/radial_gradient_brush.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <tuple>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct radial_gradient_brush::data {
  xtd::drawing::point_f center_point;
  xtd::drawing::point_f focal_point;
  float radius = 0;
  xtd::drawing::drawing_2d::gradient_stop_collection radial_colors;
};

radial_gradient_brush::radial_gradient_brush() : radial_gradient_brush(point_f(.0f, .0f), {color::transparent, color::transparent}, .0f) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : radial_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, .0f) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : radial_gradient_brush(center, {color1, color2}, .0f) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius) : radial_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float radius) : radial_gradient_brush(center, {color1, color2}, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& radial_colors) : radial_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), radial_colors) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& radial_colors) : radial_gradient_brush(center, radial_colors, .0f) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& radial_colors,  float radius) : radial_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), radial_colors, radius) {
}

radial_gradient_brush::radial_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& radial_colors, float radius) : data_(std::make_shared<data>()) {
  if (radial_colors.size() < 2) throw argument_exception {csf_};
  
  data_->center_point = center;
  data_->focal_point = center;
  data_->radius = radius;
  float pos = 0;
  float increment = 1.0f / (radial_colors.size() - 1);
  for (auto color : radial_colors) {
    data_->radial_colors.push_back({color, pos});
    pos += increment;
  }
  recreate_handle();
}

radial_gradient_brush& radial_gradient_brush::operator =(const radial_gradient_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
}

xtd::drawing::point_f radial_gradient_brush::center_point() const noexcept {
  return data_->center_point;
}

radial_gradient_brush& radial_gradient_brush::center_point(const point_f& value) noexcept {
  if (data_->center_point != value) {
    data_->center_point = value;
    recreate_handle();
  }
  return *this;
}

radial_gradient_brush& radial_gradient_brush::center_point(const point& value) noexcept {
  return center_point(point_f(as<float>(value.x()), as<float>(value.y())));
}

xtd::drawing::point_f radial_gradient_brush::focal_point() const noexcept {
  return data_->focal_point;
}

radial_gradient_brush& radial_gradient_brush::focal_point(const point_f& value) noexcept {
  if (data_->focal_point != value) {
    data_->focal_point = value;
    recreate_handle();
  }
  return *this;
}

radial_gradient_brush& radial_gradient_brush::focal_point(const point& value) noexcept {
  return focal_point(point_f(as<float>(value.x()), as<float>(value.y())));
}

radial_gradient_brush& radial_gradient_brush::radial_colors(const gradient_stop_collection& value) {
  if (data_->radial_colors != value) {
    if (value.size() < 2) throw argument_exception {csf_};
    data_->radial_colors = value;
    recreate_handle();
  }
  return *this;
}

const gradient_stop_collection& radial_gradient_brush::radial_colors() const noexcept {
  return data_->radial_colors;
}

float radial_gradient_brush::radius() const noexcept {
  return data_->radius;
}

radial_gradient_brush& radial_gradient_brush::radius(float value) noexcept {
  if (data_->radius != value) {
    data_->radius = value;
    recreate_handle();
  }
  return *this;
}

bool radial_gradient_brush::equals(const radial_gradient_brush& value) const noexcept {
  return data_ == value.data_;
}

void radial_gradient_brush::recreate_handle() {
  vector<tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte, float>> colors;
  
  for_each(data_->radial_colors.begin(), data_->radial_colors.end(), [&](auto color) {colors.emplace_back(color.first.r(), color.first.g(), color.first.b(), color.first.a(), color.second);});
  
  native::brush::radial_gradient(handle(), as<int32>(data_->center_point.x()), as<int32>(data_->center_point.y()), as<int32>(data_->focal_point.x()), as<int32>(data_->focal_point.y()), colors, data_->radius);
}

radial_gradient_brush::radial_gradient_brush(const radial_gradient_brush& value) : brush(value), data_(value.data_) {
}
