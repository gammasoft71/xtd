#include "../../../include/xtd/forms/box_renderer.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds) {
  draw_box(graphics, bounds, box_data());
}

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds, const box_data& data) {
  draw_line_top(graphics, bounds, data);
  draw_line_left(graphics, bounds, data);
  draw_line_bottom(graphics, bounds, data);
  draw_line_right(graphics, bounds, data);

  auto fill_rect = data.get_fill_rectangle(bounds);
  graphics.fill_rounded_rectangle(solid_brush(data.background_color()), fill_rect, data.border_radius().top_left());
  auto image_brush = background_image::make_brush(data.background_image(), fill_rect);
  if (image_brush) graphics.fill_rounded_rectangle(*image_brush, fill_rect, data.border_radius().top_left());
}

void box_renderer::draw_line_top(graphics& graphics, const rectangle& bounds, const box_data& data) {
  auto pen_width1 = data.border_width().top();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(data.border_color().top());
  
  if (data.border_style().top() == border_type::inset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  if (data.border_style().top() == border_type::outset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(data.border_style().top()));
  // top
  graphics.draw_line(pen1, border_rect1.left() + data.border_radius().top_left(), border_rect1.top(), border_rect1.right() - data.border_radius().top_right(), border_rect1.top());
  // top-left
  if (data.border_radius().top_left()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data.border_radius().top_left() * 2, data.border_radius().top_left() * 2, 225, 45);
  // top-right
  if (data.border_radius().top_right()) graphics.draw_arc(pen1, border_rect1.right() - data.border_radius().top_right() * 2, border_rect1.top(), data.border_radius().top_right() * 2, data.border_radius().top_right() * 2, 270, 45);
}

void box_renderer::draw_line_right(graphics& graphics, const rectangle& bounds, const box_data& data) {
  auto pen_width1 = data.border_width().right();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(data.border_color().right());
  
  if (data.border_style().right() == border_type::inset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  if (data.border_style().right() == border_type::outset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(data.border_style().right()));
  // right
  graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + data.border_radius().top_right(), border_rect1.right(), border_rect1.bottom() - data.border_radius().bottom_right());
  // top-right
  if (data.border_radius().top_right()) graphics.draw_arc(pen1, border_rect1.right() - data.border_radius().top_right() * 2, border_rect1.top(), data.border_radius().top_right() * 2, data.border_radius().top_right() * 2, 315, 45);
  // bottom-right
  if (data.border_radius().bottom_right()) graphics.draw_arc(pen1, border_rect1.right() - data.border_radius().bottom_right() * 2, border_rect1.bottom() - data.border_radius().bottom_right() * 2, data.border_radius().bottom_right() * 2, data.border_radius().bottom_right() * 2, 0, 45);
}

void box_renderer::draw_line_bottom(graphics& graphics, const rectangle& bounds, const box_data& data) {
  auto pen_width1 = data.border_width().bottom();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(data.border_color().bottom());
  
  if (data.border_style().bottom() == border_type::inset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  if (data.border_style().bottom() == border_type::outset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(data.border_style().bottom()));
  // bottom
  graphics.draw_line(pen1, border_rect1.left() + data.border_radius().bottom_left(), border_rect1.bottom(), border_rect1.right() - data.border_radius().bottom_right(), border_rect1.bottom());
  // bottom-left
  if (data.border_radius().bottom_left()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data.border_radius().bottom_left() * 2, data.border_radius().bottom_left() * 2, data.border_radius().bottom_left() * 2, 90, 45);
  // bottom-right
  if (data.border_radius().bottom_right()) graphics.draw_arc(pen1, border_rect1.right() - data.border_radius().bottom_right() * 2, border_rect1.bottom() - data.border_radius().bottom_right() * 2, data.border_radius().bottom_right() * 2, data.border_radius().bottom_right() * 2, 45, 45);
}

void box_renderer::draw_line_left(graphics& graphics, const rectangle& bounds, const box_data& data) {
  auto pen_width1 = data.border_width().left();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(data.border_color().left());
  
  if (data.border_style().left() == border_type::inset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  if (data.border_style().left() == border_type::outset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(data.border_style().left()));
  // left
  graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + data.border_radius().top_left(), border_rect1.x(), border_rect1.bottom() - data.border_radius().bottom_left());
  // top-left
  if (data.border_radius().top_left()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data.border_radius().top_left() * 2, data.border_radius().top_left() * 2, 180, 45);
  // bottom-left
  if (data.border_radius().bottom_left()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data.border_radius().bottom_left() * 2, data.border_radius().bottom_left() * 2, data.border_radius().bottom_left() * 2, 135, 45);
}

dash_style box_renderer::border_type_to_dash_style(border_type value) {
  if (value == border_type::solid) return dash_style::solid;
  if (value == border_type::dashed) return dash_style::dash;
  if (value == border_type::dotted) return dash_style::dot;
  if (value == border_type::dot_dash) return dash_style::dash_dot;
  if (value == border_type::dot_dot_dash) return dash_style::dash_dot_dot;
  return dash_style::solid;
}
