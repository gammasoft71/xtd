#include "ball_form.hpp"
#include <xtd/drawing/drawing_2d/radial_gradient_brush>

using namespace ball;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

ball_form::ball_form() {
  form_border_style(forms::form_border_style::none);
  double_buffered(true);
  size({300, 300});
}

const class color& ball_form::color() const noexcept {
  return color_;
}

ball_form& ball_form::color(const class color& value) noexcept {
  if (color_ == value) return *this;
  color_ = value;
  invalidate();
  return *this;
}

const drawing::color& ball_form::light_point_color() const noexcept {
  return light_point_color_;
}

ball_form& ball_form::light_point_color(const drawing::color& value) noexcept {
  if (light_point_color_ == value) return *this;
  light_point_color_ = value;
  invalidate();
  return *this;
}

drawing::size ball_form::size() const noexcept {
  return client_size();
}

control& ball_form::size(const drawing::size& value) {
  if (client_size() == value) return *this;
  client_size(value);
  
  // Create a circular region
  auto path = graphics_path {};
  path.add_ellipse(client_rectangle());
  region(drawing::region(path));
  return *this;
}

void ball_form::on_paint(paint_event_args& e) {
  form::on_paint(e);

  // Radial gradient
  auto left = e.clip_rectangle().width * 2 / 5;
  auto top = e.clip_rectangle().height * 35 /100;
  auto radius = e.clip_rectangle().width * 55_f / 100;
  auto brush = radial_gradient_brush {point {left, top}, light_point_color_, color_, radius};
  e.graphics().fill_rectangle(brush, e.clip_rectangle());
}
