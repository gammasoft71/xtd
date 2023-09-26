#include "../../../../include/xtd/drawing/drawing_2d/conical_gradient_brush"
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

struct conical_gradient_brush::data {
  xtd::drawing::point_f center_point;
  float angle = 0;
  xtd::drawing::drawing_2d::gradient_stop_collection conical_colors;
};

conical_gradient_brush::conical_gradient_brush() : conical_gradient_brush(point_f(.0f, .0f), {color::transparent, color::transparent}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2) : conical_gradient_brush(center, {color1, color2}, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), {color1, color2}, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const xtd::drawing::color& color1, const xtd::drawing::color& color2, float angle) : conical_gradient_brush(center, {color1, color2}, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), conical_colors) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors) : conical_gradient_brush(center, conical_colors, .0f) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point& center, const std::vector<xtd::drawing::color>& conical_colors,  float angle) : conical_gradient_brush(point_f(as<float>(center.x()), as<float>(center.y())), conical_colors, angle) {
}

conical_gradient_brush::conical_gradient_brush(const xtd::drawing::point_f& center, const std::vector<xtd::drawing::color>& conical_colors, float angle) : data_(std::make_shared<data>()) {
  if (conical_colors.size() < 2) throw argument_exception {csf_};
  
  data_->center_point = center;
  data_->angle = angle;
  auto pos = .0f;
  auto increment = 1.0f / (conical_colors.size() - 1);
  for (auto color : conical_colors) {
    data_->conical_colors.push_back({color, pos});
    pos += increment;
  }
  recreate_handle();
}

conical_gradient_brush& conical_gradient_brush::operator =(const conical_gradient_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
}

float conical_gradient_brush::angle() const noexcept {
  return data_->angle;
}

conical_gradient_brush& conical_gradient_brush::angle(float value) noexcept {
  if (data_->angle != value) {
    data_->angle = value;
    recreate_handle();
  }
  return *this;
}

conical_gradient_brush& conical_gradient_brush::conical_colors(const gradient_stop_collection& value) {
  if (data_->conical_colors != value) {
    if (value.size() < 2) throw argument_exception {csf_};
    data_->conical_colors = value;
    recreate_handle();
  }
  return *this;
}

const gradient_stop_collection& conical_gradient_brush::conical_colors() const noexcept {
  return data_->conical_colors;
}

xtd::drawing::point_f conical_gradient_brush::center_point() const noexcept {
  return data_->center_point;
}

conical_gradient_brush& conical_gradient_brush::center_point(const point_f& value) noexcept {
  if (data_->center_point != value) {
    data_->center_point = value;
    recreate_handle();
  }
  return *this;
}

conical_gradient_brush& conical_gradient_brush::center_point(const point& value) noexcept {
  return center_point(point_f(as<float>(value.x()), as<float>(value.y())));
}

bool conical_gradient_brush::equals(const conical_gradient_brush& value) const noexcept {
  return data_ == value.data_;
}

void conical_gradient_brush::recreate_handle() {
  auto colors = vector<tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte, float>> {};
  for_each(data_->conical_colors.begin(), data_->conical_colors.end(), [&](auto color) {colors.emplace_back(color.first.r(), color.first.g(), color.first.b(), color.first.a(), color.second);});
  native::brush::conical_gradient(handle(), as<int32>(data_->center_point.x()), as<int32>(data_->center_point.y()), colors, data_->angle);
}

conical_gradient_brush::conical_gradient_brush(const conical_gradient_brush& value) : brush(value), data_(value.data_) {
}
