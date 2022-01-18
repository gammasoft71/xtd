#include "../../../../include/xtd/forms/style_sheets/border_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

namespace {
  static constexpr size_t top_index = 0;
  static constexpr size_t right_index = 1;
  static constexpr size_t bottom_index = 2;
  static constexpr size_t left_index = 3;

  static constexpr size_t top_left_index = 0;
  static constexpr size_t top_right_index = 1;
  static constexpr size_t bottom_right_index = 2;
  static constexpr size_t bottom_left_index = 3;
}

void border_renderer::draw_border(graphics& graphics, const rectangle& bounds) {
  draw_border(graphics,bounds, {border_data(), border_data(), border_data(), border_data()});
}

void border_renderer::draw_border(graphics& graphics, const rectangle& bounds, const border_data& data) {
  draw_border(graphics,bounds, {data, data, data, data});
}

void border_renderer::draw_border(graphics& graphics, const rectangle& bounds, const array<border_data, 4>& data) {
  draw_line_top(graphics, bounds, data);
  draw_line_left(graphics, bounds, data);
  draw_line_bottom(graphics, bounds, data);
  draw_line_right(graphics, bounds, data);
}

void border_renderer::draw_line_top(graphics& graphics, const rectangle& bounds, const array<border_data, 4>& data) {
  auto pen_width1 = data[top_index].width();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = data[top_index].color() ? data[top_index].color() : make_shared<solid_brush>(color::black);
  
  if (is<solid_brush>(color1) && data[top_index].style() == border_style::inset && as<solid_brush>(color1)->color().is_light())
    color1 = make_shared<solid_brush>(color::dark(as<solid_brush>(color1)->color()));
  if (is<solid_brush>(color1) && data[top_index].style() == border_style::outset && as<solid_brush>(color1)->color().is_dark())
    color1 = make_shared<solid_brush>(color::light(as<solid_brush>(color1)->color()));
  
  auto pen1 = pen(*color1, as<float>(pen_width1));
  pen1.dash_style(border_style_to_dash_style(data[top_index].style()));
  // top
  graphics.draw_line(pen1, border_rect1.left() + data[top_left_index].radius(), border_rect1.top(), border_rect1.right() - data[top_right_index].radius(), border_rect1.top());
  // top-left
  if ( data[top_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data[top_left_index].radius() * 2, data[top_left_index].radius() * 2, 225, 45);
  // top-right
  if ( data[top_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[top_right_index].radius() * 2, border_rect1.top(), data[top_right_index].radius() * 2, data[top_right_index].radius() * 2, 270, 45);
}

void border_renderer::draw_line_right(graphics& graphics, const rectangle& bounds, const array<border_data, 4>& data) {
  auto pen_width1 = data[right_index].width();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = data[right_index].color() ? data[right_index].color() : make_shared<solid_brush>(color::black);
  
  if (is<solid_brush>(color1) && data[right_index].style() == border_style::inset && as<solid_brush>(color1)->color().is_dark())
    color1 = make_shared<solid_brush>(color::light(as<solid_brush>(color1)->color()));
  if (is<solid_brush>(color1) && data[right_index].style() == border_style::outset && as<solid_brush>(color1)->color().is_light())
    color1 = make_shared<solid_brush>(color::dark(as<solid_brush>(color1)->color()));
  
  auto pen1 = pen(*color1, as<float>(pen_width1));
  pen1.dash_style(border_style_to_dash_style(data[right_index].style()));
  // right
  graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + data[top_right_index].radius(), border_rect1.right(), border_rect1.bottom() - data[bottom_right_index].radius());
  // top-right
  if ( data[top_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[top_right_index].radius() * 2, border_rect1.top(), data[top_right_index].radius() * 2, data[top_right_index].radius() * 2, 315, 45);
  // bottom-right
  if ( data[bottom_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[bottom_right_index].radius() * 2, border_rect1.bottom() - data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, 0, 45);
}

void border_renderer::draw_line_bottom(graphics& graphics, const rectangle& bounds, const array<border_data, 4>& data) {
  auto pen_width1 = data[bottom_index].width();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = data[bottom_index].color() ? data[bottom_index].color() : make_shared<solid_brush>(color::black);
  
  if (is<solid_brush>(color1) && data[bottom_index].style() == border_style::inset && as<solid_brush>(color1)->color().is_dark())
    color1 = make_shared<solid_brush>(color::light(as<solid_brush>(color1)->color()));
  if (is<solid_brush>(color1) && data[bottom_index].style() == border_style::outset && as<solid_brush>(color1)->color().is_light())
    color1 = make_shared<solid_brush>(color::dark(as<solid_brush>(color1)->color()));
  
  auto pen1 = pen(*color1, as<float>(pen_width1));
  pen1.dash_style(border_style_to_dash_style(data[bottom_index].style()));
  // bottom
  graphics.draw_line(pen1, border_rect1.left() + data[bottom_left_index].radius(), border_rect1.bottom(), border_rect1.right() - data[bottom_right_index].radius(), border_rect1.bottom());
  // bottom-left
  if ( data[bottom_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, 90, 45);
  // bottom-right
  if ( data[bottom_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[bottom_right_index].radius() * 2, border_rect1.bottom() - data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, 45, 45);
}

void border_renderer::draw_line_left(graphics& graphics, const rectangle& bounds, const array<border_data, 4>& data) {
  auto pen_width1 = data[left_index].width();
  auto border_rect1 = rectangle::inflate(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = data[left_index].color() ? data[left_index].color() : make_shared<solid_brush>(color::black);
  
  if (is<solid_brush>(color1) && data[left_index].style() == border_style::inset && as<solid_brush>(color1)->color().is_light())
    color1 = make_shared<solid_brush>(color::dark(as<solid_brush>(color1)->color()));
  if (is<solid_brush>(color1) && data[left_index].style() == border_style::outset && as<solid_brush>(color1)->color().is_dark())
    color1 = make_shared<solid_brush>(color::light(as<solid_brush>(color1)->color()));
  
  auto pen1 = pen(*color1, as<float>(pen_width1));
  pen1.dash_style(border_style_to_dash_style(data[left_index].style()));
  // left
  graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + data[top_left_index].radius(), border_rect1.x(), border_rect1.bottom() - data[bottom_left_index].radius());
  // top-left
  if ( data[top_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data[top_left_index].radius() * 2, data[top_left_index].radius() * 2, 180, 45);
  // bottom-left
  if ( data[bottom_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, 135, 45);
}

dash_style border_renderer::border_style_to_dash_style(border_style value) {
  if (value == border_style::solid) return dash_style::solid;
  if (value == border_style::dashed) return dash_style::dash;
  if (value == border_style::dotted) return dash_style::dot;
  if (value == border_style::dot_dash) return dash_style::dash_dot;
  if (value == border_style::dot_dot_dash) return dash_style::dash_dot_dot;
  return dash_style::solid;
}
