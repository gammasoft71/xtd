#include "ball_form.hpp"
#include <xtd/drawing/drawing_2d/radial_gradient_brush>

using namespace ball;

ball_form::ball_form() {
  back_color(color::transparent);
  form_border_style(forms::form_border_style::none);
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
  auto path = drawing_2d::graphics_path {};
  path.add_ellipse(client_rectangle());
  region(drawing::region(path));
  return *this;
}

void ball_form::on_paint(paint_event_args& e) {
  form::on_paint(e);
  
  // Main gradient (sphere)
  auto left = e.clip_rectangle().width * 2 / 5;
  auto top = e.clip_rectangle().height * 35 / 100;
  auto radius = e.clip_rectangle().width * 55_f / 100;
  auto brush = drawing_2d::radial_gradient_brush {point {left, top}, light_point_color_, color_, radius};
  e.graphics().fill_ellipse(brush, e.clip_rectangle());
  
  // Dark contour (shading)
  auto pen = drawing::pen {drawing::color::from_argb(80, 0, 0, 0), 4};
  e.graphics().draw_ellipse(pen, e.clip_rectangle());
  
  // Secondary highlight (light reflection)
  auto highlight = drawing_2d::radial_gradient_brush(point {client_size().width / 3, client_size().height / 3}, drawing::color::from_argb(150, 255, 255, 255), drawing::color::from_argb(0, 255, 255, 255), client_size().width / 6);
  e.graphics().fill_ellipse(highlight, rectangle {client_size().width / 4, client_size().height / 4, client_size().width / 2, client_size().height / 2});
  
  // Glossy reflection (upper dome)
  auto glossy = drawing_2d::linear_gradient_brush {point {0, 0}, point {0, client_size().height / 2}, drawing::color::from_argb(120, 255, 255, 255), drawing::color::from_argb(0, 255, 255, 255)};
  e.graphics().fill_pie(glossy, rectangle {0, 0, client_size().width, client_size().height}, 180, 180);
}
