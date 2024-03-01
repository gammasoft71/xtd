#include "../../../include/xtd/forms/box_renderer.h"
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/color_transformer>
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/is>
#include <xtd/math>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

dash_style box_renderer::border_type_to_dash_style(border_type value) {
  if (value == border_type::solid) return dash_style::solid;
  if (value == border_type::dashed) return dash_style::dash;
  if (value == border_type::dotted) return dash_style::dot;
  if (value == border_type::dot_dash) return dash_style::dash_dot;
  if (value == border_type::dot_dot_dash) return dash_style::dash_dot_dot;
  return dash_style::solid;
}

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  auto fill_rect = box_model.get_fill_rectangle(bounds);
  auto image_brush = background_image::make_brush(box_model.background_image(), fill_rect);
  fill_box(graphics, solid_brush(box_model.background_color()), bounds, box_model);
  if (image_brush) fill_box(graphics, *image_brush, bounds, box_model);
  
  auto border_rect = box_model.get_border_rectangle(bounds);
  draw_line_top(graphics, border_rect, box_model.border_color(), box_model.border_radius(), box_model.border_style(), box_model.border_width());
  draw_line_left(graphics, border_rect, box_model.border_color(), box_model.border_radius(), box_model.border_style(), box_model.border_width());
  draw_line_bottom(graphics, border_rect, box_model.border_color(), box_model.border_radius(), box_model.border_style(), box_model.border_width());
  draw_line_right(graphics, border_rect, box_model.border_color(), box_model.border_radius(), box_model.border_style(), box_model.border_width());
  
  auto outline_rect = box_model.get_outline_rectangle(bounds);
  draw_line_top(graphics, outline_rect, box_model.outline_color(), box_model.outline_radius(), box_model.outline_style(), box_model.outline_width());
  draw_line_left(graphics, outline_rect, box_model.outline_color(), box_model.outline_radius(), box_model.outline_style(), box_model.outline_width());
  draw_line_bottom(graphics, outline_rect, box_model.outline_color(), box_model.outline_radius(), box_model.outline_style(), box_model.outline_width());
  draw_line_right(graphics, outline_rect, box_model.outline_color(), box_model.outline_radius(), box_model.outline_style(), box_model.outline_width());
}

void box_renderer::draw_line_top(graphics& graphics, const rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width) {
  if (border_width.top().get_pixels(bounds) == 0 || border_style.top() == border_type::none || border_style.top() == border_type::hidden) return;
  
  auto color1 = border_color.top();
  auto color2 = border_color.top();
  if (border_style.top() == border_type::inset || border_style.top() == border_type::groove) {
    color1 = color_transformer::dark(color1);
    color2 = color_transformer::light(color2);
  } else if (border_style.top() == border_type::outset || border_style.top() == border_type::ridge || border_style.top() == border_type::theme) {
    color1 = color_transformer::light(color1);
    color2 = color_transformer::dark(color2);
  }
  
  auto pen_width1 = as<float>(border_width.top().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (border_style.top() == border_type::double_border) {
    pen_width1 = as<float>(border_width.top().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(border_width.top().get_pixels(bounds)) / 3;
  } else if (border_style.top() == border_type::theme || border_style.top() == border_type::groove || border_style.top() == border_type::ridge) {
    pen_width1 = as<float>(border_width.top().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(border_width.top().get_pixels(bounds)) / 2;
  }
  
  auto pen1 = pen {color1, pen_width1}.dash_style(border_type_to_dash_style(border_style.top()));
  auto pen2 = pen {color2, pen_width2}.dash_style(border_type_to_dash_style(border_style.top()));
  
  auto border_rect1 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1});
  auto border_rect2 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2});
  
  if (border_style.top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32>(pen_width1), -as<int32>(pen_width1)});
    
  auto radius_top_left1 = border_radius.top_left().get_pixels(bounds);
  auto radius_top_left2 = border_radius.top_left().get_pixels(bounds) - as<int32>(pen_width1);
  auto radius_top_right1 = border_radius.top_right().get_pixels(bounds);
  auto radius_top_right2 = border_radius.top_right().get_pixels(bounds) - as<int32>(pen_width1);
  if (radius_top_left1 < 0) radius_top_left1 = 0;
  if (radius_top_left2 < 0) radius_top_left2 = 0;
  if (radius_top_right1 < 0) radius_top_right1 = 0;
  if (radius_top_right2 < 0) radius_top_right2 = 0;
  
  // top
  graphics.draw_line(pen1, border_rect1.left() + radius_top_left1, border_rect1.top(), border_rect1.right() - radius_top_right1, border_rect1.top());
  // top-left
  if (radius_top_left1) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), radius_top_left1 * 2, radius_top_left1 * 2, 225, 45);
  // top-right
  if (radius_top_right1) graphics.draw_arc(pen1, border_rect1.right() - radius_top_right1 * 2, border_rect1.top(), radius_top_right1 * 2, radius_top_right1 * 2, 270, 45);
  
  if (pen_width2 != 0) {
    // top
    graphics.draw_line(pen2, border_rect2.left() + radius_top_left2, border_rect2.top(), border_rect2.right() - radius_top_right2, border_rect2.top());
    // top-left
    if (radius_top_left2) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.top(), radius_top_left2 * 2, radius_top_left2 * 2, 225, 45);
    // top-right
    if (radius_top_right2) graphics.draw_arc(pen2, border_rect2.right() - radius_top_right2 * 2, border_rect2.top(), radius_top_right2 * 2, radius_top_right2 * 2, 270, 45);
  }
}

void box_renderer::draw_line_right(graphics& graphics, const rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width) {
  if (border_width.right().get_pixels(bounds) == 0 || border_style.right() == border_type::none || border_style.right() == border_type::hidden) return;
  
  auto color1 = border_color.right();
  auto color2 = border_color.right();
  if (border_style.right() == border_type::inset || border_style.right() == border_type::groove || border_style.right() == border_type::theme) {
    color1 = color_transformer::light(color1);
    color2 = color_transformer::dark(color2);
  } else if (border_style.right() == border_type::outset || border_style.right() == border_type::ridge) {
    color1 = color_transformer::dark(color1);
    color2 = color_transformer::light(color2);
  }
  
  auto pen_width1 = as<float>(border_width.right().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (border_style.right() == border_type::double_border) {
    pen_width1 = as<float>(border_width.right().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(border_width.right().get_pixels(bounds)) / 3;
  } else if (border_style.right() == border_type::theme || border_style.right() == border_type::groove || border_style.right() == border_type::ridge) {
    pen_width1 = as<float>(border_width.right().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(border_width.right().get_pixels(bounds)) / 2;
  }
  
  auto pen1 = pen {color1, pen_width1}.dash_style(border_type_to_dash_style(border_style.right()));
  auto pen2 = pen {color2, pen_width2}.dash_style(border_type_to_dash_style(border_style.right()));
  
  auto border_rect1 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1});
  auto border_rect2 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2});
  
  if (border_style.top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32>(pen_width1), -as<int32>(pen_width1)});
    
  auto radius_top_right1 = border_radius.top_right().get_pixels(bounds);
  auto radius_top_right2 = border_radius.top_right().get_pixels(bounds) - as<int32>(pen_width1);
  auto radius_bottom_right1 = border_radius.bottom_right().get_pixels(bounds);
  auto radius_bottom_right2 = border_radius.bottom_right().get_pixels(bounds) - as<int32>(pen_width1);
  if (radius_top_right1 < 0) radius_top_right1 = 0;
  if (radius_top_right2 < 0) radius_top_right2 = 0;
  if (radius_bottom_right1 < 0) radius_bottom_right1 = 0;
  if (radius_bottom_right2 < 0) radius_bottom_right2 = 0;
  
  // right
  graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + radius_top_right1, border_rect1.right(), border_rect1.bottom() - radius_bottom_right1);
  // top-right
  if (radius_top_right1) graphics.draw_arc(pen1, border_rect1.right() - radius_top_right1 * 2, border_rect1.top(), radius_top_right1 * 2, radius_top_right1 * 2, 315, 45);
  // bottom-right
  if (radius_bottom_right1) graphics.draw_arc(pen1, border_rect1.right() - radius_bottom_right1 * 2, border_rect1.bottom() - radius_bottom_right1 * 2, radius_bottom_right1 * 2, radius_bottom_right1 * 2, 0, 45);
  
  if (pen_width2 != 0) {
    // right
    graphics.draw_line(pen2, border_rect2.right(), border_rect2.top() + radius_top_right2, border_rect2.right(), border_rect2.bottom() - radius_bottom_right2);
    // top-right
    if (radius_top_right2) graphics.draw_arc(pen2, border_rect2.right() - radius_top_right2 * 2, border_rect2.top(), radius_top_right2 * 2, radius_top_right2 * 2, 315, 45);
    // bottom-right
    if (radius_bottom_right2) graphics.draw_arc(pen2, border_rect2.right() - radius_bottom_right2 * 2, border_rect2.bottom() - radius_bottom_right2 * 2, radius_bottom_right2 * 2, radius_bottom_right2 * 2, 0, 45);
  }
}

void box_renderer::draw_line_bottom(graphics& graphics, const rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width) {
  if (border_width.bottom().get_pixels(bounds) == 0 || border_style.bottom() == border_type::none || border_style.bottom() == border_type::hidden) return;
  
  auto color1 = border_color.bottom();
  auto color2 = border_color.bottom();
  if (border_style.bottom() == border_type::inset || border_style.bottom() == border_type::groove || border_style.top() == border_type::theme) {
    color1 = color_transformer::light(color1);
    color2 = color_transformer::dark(color2);
  } else if (border_style.bottom() == border_type::outset || border_style.bottom() == border_type::ridge) {
    color1 = color_transformer::dark(color1);
    color2 = color_transformer::light(color2);
  }
  
  auto pen_width1 = as<float>(border_width.bottom().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (border_style.bottom() == border_type::double_border) {
    pen_width1 = as<float>(border_width.bottom().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(border_width.bottom().get_pixels(bounds)) / 3;
  } else if (border_style.top() == border_type::theme || border_style.bottom() == border_type::groove || border_style.bottom() == border_type::ridge) {
    pen_width1 = as<float>(border_width.bottom().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(border_width.bottom().get_pixels(bounds)) / 2;
  }
  
  auto pen1 = pen {color1, pen_width1}.dash_style(border_type_to_dash_style(border_style.bottom()));
  auto pen2 = pen {color2, pen_width2}.dash_style(border_type_to_dash_style(border_style.bottom()));
  
  auto border_rect1 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1});
  auto border_rect2 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2});
  
  if (border_style.top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32>(pen_width1), -as<int32>(pen_width1)});
    
  auto radius_bottom_right1 = border_radius.bottom_right().get_pixels(bounds);
  auto radius_bottom_right2 = border_radius.bottom_right().get_pixels(bounds) - as<int32>(pen_width1);
  auto radius_bottom_left1 = border_radius.bottom_left().get_pixels(bounds);
  auto radius_bottom_left2 = border_radius.bottom_left().get_pixels(bounds) - as<int32>(pen_width1);
  if (radius_bottom_right1 < 0) radius_bottom_right1 = 0;
  if (radius_bottom_right2 < 0) radius_bottom_right2 = 0;
  if (radius_bottom_left1 < 0) radius_bottom_left1 = 0;
  if (radius_bottom_left2 < 0) radius_bottom_left2 = 0;
  
  // bottom
  graphics.draw_line(pen1, border_rect1.left() + radius_bottom_left1, border_rect1.bottom(), border_rect1.right() - radius_bottom_right1, border_rect1.bottom());
  // bottom-left
  if (radius_bottom_left1) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - radius_bottom_left1 * 2, radius_bottom_left1 * 2, radius_bottom_left1 * 2, 90, 45);
  // bottom-right
  if (radius_bottom_right1) graphics.draw_arc(pen1, border_rect1.right() - radius_bottom_right1 * 2, border_rect1.bottom() - radius_bottom_right1 * 2, radius_bottom_right1 * 2, radius_bottom_right1 * 2, 45, 45);
  
  if (pen_width2 != 0) {
    // bottom
    graphics.draw_line(pen2, border_rect2.left() + radius_bottom_left2, border_rect2.bottom(), border_rect2.right() - radius_bottom_right2, border_rect2.bottom());
    // bottom-left
    if (radius_bottom_left2) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.bottom() - radius_bottom_left2 * 2, radius_bottom_left2 * 2, radius_bottom_left2 * 2, 90, 45);
    // bottom-right
    if (radius_bottom_right2) graphics.draw_arc(pen2, border_rect2.right() - radius_bottom_right2 * 2, border_rect2.bottom() - radius_bottom_right2 * 2, radius_bottom_right2 * 2, radius_bottom_right2 * 2, 45, 45);
  }
}

void box_renderer::draw_line_left(graphics& graphics, const rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width) {
  if (border_width.left().get_pixels(bounds) == 0 || border_style.left() == border_type::none || border_style.left() == border_type::hidden) return;
  
  auto color1 = border_color.left();
  auto color2 = border_color.left();
  if (border_style.left() == border_type::inset || border_style.left() == border_type::groove) {
    color1 = color_transformer::dark(color1);
    color2 = color_transformer::light(color2);
  } else if (border_style.left() == border_type::outset || border_style.left() == border_type::ridge || border_style.left() == border_type::theme) {
    color1 = color_transformer::light(color1);
    color2 = color_transformer::dark(color2);
  }
  
  auto pen_width1 = as<float>(border_width.left().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (border_style.left() == border_type::double_border) {
    pen_width1 = as<float>(border_width.left().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(border_width.left().get_pixels(bounds)) / 3;
  } else if (border_style.left() == border_type::theme || border_style.left() == border_type::groove || border_style.left() == border_type::ridge) {
    pen_width1 = as<float>(border_width.left().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(border_width.left().get_pixels(bounds)) / 2;
  }
  
  auto pen1 = pen {color1, pen_width1}.dash_style(border_type_to_dash_style(border_style.left()));
  auto pen2 = pen {color2, pen_width2}.dash_style(border_type_to_dash_style(border_style.left()));
  
  auto border_rect1 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1});
  auto border_rect2 = rectangle::truncate(rectangle_f {bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2});
  
  if (border_style.top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32>(pen_width1), -as<int32>(pen_width1)});
    
  auto radius_bottom_left1 = border_radius.bottom_left().get_pixels(bounds);
  auto radius_bottom_left2 = border_radius.bottom_left().get_pixels(bounds) - as<int32>(pen_width1);
  auto radius_top_left1 = border_radius.top_left().get_pixels(bounds);
  auto radius_top_left2 = border_radius.top_left().get_pixels(bounds) - as<int32>(pen_width1);
  if (radius_bottom_left1 < 0) radius_bottom_left1 = 0;
  if (radius_bottom_left2 < 0) radius_bottom_left2 = 0;
  if (radius_top_left1 < 0) radius_top_left1 = 0;
  if (radius_top_left2 < 0) radius_top_left2 = 0;
  
  // left
  graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + radius_top_left1, border_rect1.x(), border_rect1.bottom() - radius_bottom_left1);
  // top-left
  if (radius_top_left1) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), radius_top_left1 * 2, radius_top_left1 * 2, 180, 45);
  // bottom-left
  if (radius_bottom_left1) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - radius_bottom_left1 * 2, radius_bottom_left1 * 2, radius_bottom_left1 * 2, 135, 45);
  
  if (pen_width2 != 0) {
    // left
    graphics.draw_line(pen2, border_rect2.left(), border_rect2.top() + radius_top_left2, border_rect2.x(), border_rect2.bottom() - radius_bottom_left2);
    // top-left
    if (radius_top_left2) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.top(), radius_top_left2 * 2, radius_top_left2 * 2, 180, 45);
    // bottom-left
    if (radius_bottom_left2) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.bottom() - radius_bottom_left2 * 2, radius_bottom_left2 * 2, radius_bottom_left2 * 2, 135, 45);
  }
}

void box_renderer::fill_box(xtd::drawing::graphics& graphics, const xtd::drawing::brush& brush, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::ibox_model& box_model) {
  auto path = graphics_path {};
  auto fill_rect = box_model.get_fill_rectangle(bounds);
  auto radius_top_left = box_model.border_radius().top_left().get_pixels(bounds) - box_model.border_width().top().get_pixels(bounds);
  auto radius_top_right = box_model.border_radius().top_right().get_pixels(bounds) - box_model.border_width().top().get_pixels(bounds);

  if (radius_top_left < 0) radius_top_left = 0;
  if (radius_top_right < 0) radius_top_right = 0;
  
  path.add_line(fill_rect.left() + radius_top_left, fill_rect.top(), fill_rect.right() - radius_top_right, fill_rect.top());
  if (radius_top_right) path.add_arc(fill_rect.right() - radius_top_right * 2, fill_rect.top(), radius_top_right * 2, radius_top_right * 2, 270, 45);
  
  radius_top_right = box_model.border_radius().top_right().get_pixels(bounds) - box_model.border_width().right().get_pixels(bounds);
  auto radius_bottom_right = box_model.border_radius().bottom_right().get_pixels(bounds) - box_model.border_width().right().get_pixels(bounds);
  if (radius_top_right < 0) radius_top_right = 0;
  if (radius_bottom_right < 0) radius_bottom_right = 0;
  
  if (radius_top_right) path.add_arc(fill_rect.right() - radius_top_right * 2, fill_rect.top(), radius_top_right * 2, radius_top_right * 2, 315, 45);
  path.add_line(fill_rect.right(), fill_rect.top() + radius_top_right, fill_rect.right(), fill_rect.bottom() - radius_bottom_right);
  if (radius_bottom_right) path.add_arc(fill_rect.right() - radius_bottom_right * 2, fill_rect.bottom() - radius_bottom_right * 2, radius_bottom_right * 2, radius_bottom_right * 2, 0, 45);
  
  radius_bottom_right = box_model.border_radius().bottom_right().get_pixels(bounds) - box_model.border_width().bottom().get_pixels(bounds);
  auto radius_bottom_left = box_model.border_radius().bottom_left().get_pixels(bounds) - box_model.border_width().bottom().get_pixels(bounds);
  if (radius_bottom_right < 0) radius_bottom_right = 0;
  if (radius_bottom_left < 0) radius_bottom_left = 0;
  
  if (radius_bottom_right) path.add_arc(fill_rect.right() - radius_bottom_right * 2, fill_rect.bottom() - radius_bottom_right * 2, radius_bottom_right * 2, radius_bottom_right * 2, 45, 45);
  path.add_line(fill_rect.right() - radius_bottom_right, fill_rect.bottom(), fill_rect.left() + radius_bottom_left, fill_rect.bottom());
  if (radius_bottom_left) path.add_arc(fill_rect.left(), fill_rect.bottom() - radius_bottom_left * 2, radius_bottom_left * 2, radius_bottom_left * 2, 90, 45);
  
  radius_bottom_left = box_model.border_radius().bottom_left().get_pixels(bounds) - box_model.border_width().left().get_pixels(bounds);
  radius_top_left = box_model.border_radius().top_left().get_pixels(bounds) - box_model.border_width().left().get_pixels(bounds);
  if (radius_bottom_left < 0) radius_bottom_left = 0;
  if (radius_top_left < 0) radius_top_left = 0;
  
  if (radius_bottom_left) path.add_arc(fill_rect.left(), fill_rect.bottom() - radius_bottom_left * 2, radius_bottom_left * 2, radius_bottom_left * 2, 135, 45);
  path.add_line(fill_rect.left(), fill_rect.bottom() - radius_bottom_left, fill_rect.left(), fill_rect.top() + radius_top_left);
  if (radius_top_left) path.add_arc(fill_rect.left(), fill_rect.top(), radius_top_left * 2, radius_top_left * 2, 180, 45);
  
  radius_top_left = box_model.border_radius().top_left().get_pixels(bounds) - box_model.border_width().top().get_pixels(bounds);
  if (radius_top_left < 0) radius_top_left = 0;
  
  if (radius_top_left) path.add_arc(fill_rect.left(), fill_rect.top(), radius_top_left * 2, radius_top_left * 2, 225, 45);
  
  graphics.fill_path(brush, path);
}
