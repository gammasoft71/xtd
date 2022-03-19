#include "../../../include/xtd/forms/box_renderer.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/math.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
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
  if (image_brush) fill_box(graphics, *image_brush, bounds, box_model);
  else fill_box(graphics, solid_brush(box_model.background_color()), bounds, box_model);

  auto border_rect = box_model.get_border_rectangle(bounds);
  draw_line_top(graphics, border_rect, box_model);
  draw_line_left(graphics, border_rect, box_model);
  draw_line_bottom(graphics, border_rect, box_model);
  draw_line_right(graphics, border_rect, box_model);
}

void box_renderer::draw_line_top(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().top().get_pixels(bounds) == 0 || box_model.border_style().top() == border_type::none || box_model.border_style().top() == border_type::hidden) return;

  auto color1 = box_model.border_color().top();
  auto color2 = box_model.border_color().top();
  if (box_model.border_style().top() == border_type::inset || box_model.border_style().top() == border_type::groove) {
    color1 = color::dark(color1);
    color2 = color::light(color2);
  } else if (box_model.border_style().top() == border_type::outset || box_model.border_style().top() == border_type::ridge || box_model.border_style().top() == border_type::theme) {
    color1 = color::light(color1);
    color2 = color::dark(color2);
  }

  auto pen_width1 = as<float>(box_model.border_width().top().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (box_model.border_style().top() == border_type::double_border) {
    pen_width1 = as<float>(box_model.border_width().top().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(box_model.border_width().top().get_pixels(bounds)) / 3;
  } else if (box_model.border_style().top() == border_type::theme || box_model.border_style().top() == border_type::groove || box_model.border_style().top() == border_type::ridge) {
    pen_width1 = as<float>(box_model.border_width().top().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(box_model.border_width().top().get_pixels(bounds)) / 2;
  }

  auto pen1 = pen(color1, pen_width1).dash_style(border_type_to_dash_style(box_model.border_style().top()));
  auto pen2 = pen(color2, pen_width2).dash_style(border_type_to_dash_style(box_model.border_style().top()));

  auto border_rect1 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1));
  auto border_rect2 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2));

  if (box_model.border_style().top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32_t>(pen_width1), -as<int32_t>(pen_width1)});

  // top
  graphics.draw_line(pen1, border_rect1.left() + box_model.border_radius().top_left().get_pixels(bounds), border_rect1.top(), border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds), border_rect1.top());
  // top-left
  if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), box_model.border_radius().top_left().get_pixels(bounds) * 2, box_model.border_radius().top_left().get_pixels(bounds) * 2, 225, 45);
  // top-right
  if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds) * 2, border_rect1.top(), box_model.border_radius().top_right().get_pixels(bounds) * 2, box_model.border_radius().top_right().get_pixels(bounds) * 2, 270, 45);

  if (pen_width2 != 0) {
    // top
    graphics.draw_line(pen2, border_rect2.left() + box_model.border_radius().top_left().get_pixels(bounds) / 2, border_rect2.top(), border_rect2.right() - box_model.border_radius().top_right().get_pixels(bounds)  /2, border_rect2.top());
    // top-left
    if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.top(), box_model.border_radius().top_left().get_pixels(bounds), box_model.border_radius().top_left().get_pixels(bounds), 225, 45);
    // top-right
    if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.right() - box_model.border_radius().top_right().get_pixels(bounds), border_rect2.top(), box_model.border_radius().top_right().get_pixels(bounds), box_model.border_radius().top_right().get_pixels(bounds), 270, 45);
  }
}

void box_renderer::draw_line_right(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().right().get_pixels(bounds) == 0 || box_model.border_style().right() == border_type::none || box_model.border_style().right() == border_type::hidden) return;

  auto color1 = box_model.border_color().right();
  auto color2 = box_model.border_color().right();
  if (box_model.border_style().right() == border_type::inset || box_model.border_style().right() == border_type::groove || box_model.border_style().right() == border_type::theme) {
    color1 = color::light(color1);
    color2 = color::dark(color2);
  } else if (box_model.border_style().right() == border_type::outset || box_model.border_style().right() == border_type::ridge) {
    color1 = color::dark(color1);
    color2 = color::light(color2);
  }

  auto pen_width1 = as<float>(box_model.border_width().right().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (box_model.border_style().right() == border_type::double_border) {
    pen_width1 = as<float>(box_model.border_width().right().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(box_model.border_width().right().get_pixels(bounds)) / 3;
  } else if (box_model.border_style().right() == border_type::theme || box_model.border_style().right() == border_type::groove || box_model.border_style().right() == border_type::ridge) {
    pen_width1 = as<float>(box_model.border_width().right().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(box_model.border_width().right().get_pixels(bounds)) / 2;
  }

  auto pen1 = pen(color1, pen_width1).dash_style(border_type_to_dash_style(box_model.border_style().right()));
  auto pen2 = pen(color2, pen_width2).dash_style(border_type_to_dash_style(box_model.border_style().right()));

  auto border_rect1 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1));
  auto border_rect2 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2));
  
  if (box_model.border_style().top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32_t>(pen_width1), -as<int32_t>(pen_width1)});

  // right
  graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + box_model.border_radius().top_right().get_pixels(bounds), border_rect1.right(), border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds));
  // top-right
  if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds) * 2, border_rect1.top(), box_model.border_radius().top_right().get_pixels(bounds) * 2, box_model.border_radius().top_right().get_pixels(bounds) * 2, 315, 45);
  // bottom-right
  if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, 0, 45);

  if (pen_width2 != 0) {
    // right
    graphics.draw_line(pen2, border_rect2.right(), border_rect2.top() + box_model.border_radius().top_right().get_pixels(bounds) / 2, border_rect2.right(), border_rect2.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds) / 2);
    // top-right
    if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.right() - box_model.border_radius().top_right().get_pixels(bounds), border_rect2.top(), box_model.border_radius().top_right().get_pixels(bounds), box_model.border_radius().top_right().get_pixels(bounds), 315, 45);
    // bottom-right
    if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.right() - box_model.border_radius().bottom_right().get_pixels(bounds), border_rect2.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds), box_model.border_radius().bottom_right().get_pixels(bounds), box_model.border_radius().bottom_right().get_pixels(bounds), 0, 45);
  }
}

void box_renderer::draw_line_bottom(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().bottom().get_pixels(bounds) == 0 || box_model.border_style().bottom() == border_type::none || box_model.border_style().bottom() == border_type::hidden) return;
    
  auto color1 = box_model.border_color().bottom();
  auto color2 = box_model.border_color().bottom();
  if (box_model.border_style().bottom() == border_type::inset || box_model.border_style().bottom() == border_type::groove || box_model.border_style().top() == border_type::theme) {
    color1 = color::light(color1);
    color2 = color::dark(color2);
  } else if (box_model.border_style().bottom() == border_type::outset || box_model.border_style().bottom() == border_type::ridge) {
    color1 = color::dark(color1);
    color2 = color::light(color2);
  }

  auto pen_width1 = as<float>(box_model.border_width().bottom().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (box_model.border_style().bottom() == border_type::double_border) {
    pen_width1 = as<float>(box_model.border_width().bottom().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(box_model.border_width().bottom().get_pixels(bounds)) / 3;
  } else if (box_model.border_style().top() == border_type::theme || box_model.border_style().bottom() == border_type::groove || box_model.border_style().bottom() == border_type::ridge) {
    pen_width1 = as<float>(box_model.border_width().bottom().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(box_model.border_width().bottom().get_pixels(bounds)) / 2;
  }

  auto pen1 = pen(color1, pen_width1).dash_style(border_type_to_dash_style(box_model.border_style().bottom()));
  auto pen2 = pen(color2, pen_width2).dash_style(border_type_to_dash_style(box_model.border_style().bottom()));

  auto border_rect1 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1));
  auto border_rect2 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2));
  
  if (box_model.border_style().top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32_t>(pen_width1), -as<int32_t>(pen_width1)});

  // bottom
  graphics.draw_line(pen1, border_rect1.left() + box_model.border_radius().bottom_left().get_pixels(bounds), border_rect1.bottom(), border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds), border_rect1.bottom());
  // bottom-left
  if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, 90, 45);
  // bottom-right
  if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, 45, 45);
  
  if (pen_width2 != 0) {
    // bottom
    graphics.draw_line(pen2, border_rect2.left() + box_model.border_radius().bottom_left().get_pixels(bounds) / 2, border_rect2.bottom(), border_rect2.right() - box_model.border_radius().bottom_right().get_pixels(bounds) / 2, border_rect2.bottom());
    // bottom-left
    if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds), box_model.border_radius().bottom_left().get_pixels(bounds), box_model.border_radius().bottom_left().get_pixels(bounds), 90, 45);
    // bottom-right
    if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.right() - box_model.border_radius().bottom_right().get_pixels(bounds), border_rect2.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds), box_model.border_radius().bottom_right().get_pixels(bounds), box_model.border_radius().bottom_right().get_pixels(bounds), 45, 45);
  }
}

void box_renderer::draw_line_left(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().left().get_pixels(bounds) == 0 || box_model.border_style().left() == border_type::none || box_model.border_style().left() == border_type::hidden) return;

  auto color1 = box_model.border_color().left();
  auto color2 = box_model.border_color().left();
  if (box_model.border_style().left() == border_type::inset || box_model.border_style().left() == border_type::groove) {
    color1 = color::dark(color1);
    color2 = color::light(color2);
  } else if (box_model.border_style().left() == border_type::outset || box_model.border_style().left() == border_type::ridge || box_model.border_style().left() == border_type::theme) {
    color1 = color::light(color1);
    color2 = color::dark(color2);
  }

  auto pen_width1 = as<float>(box_model.border_width().left().get_pixels(bounds));
  auto pen_width2 = 0.0f;
  if (box_model.border_style().left() == border_type::double_border) {
    pen_width1 = as<float>(box_model.border_width().left().get_pixels(bounds)) / 3;
    pen_width2 = as<float>(box_model.border_width().left().get_pixels(bounds)) / 3;
  } else if (box_model.border_style().left() == border_type::theme || box_model.border_style().left() == border_type::groove || box_model.border_style().left() == border_type::ridge) {
    pen_width1 = as<float>(box_model.border_width().left().get_pixels(bounds)) / 2;
    pen_width2 = as<float>(box_model.border_width().left().get_pixels(bounds)) / 2;
  }

  auto pen1 = pen(color1, pen_width1).dash_style(border_type_to_dash_style(box_model.border_style().left()));
  auto pen2 = pen(color2, pen_width2).dash_style(border_type_to_dash_style(box_model.border_style().left()));

  auto border_rect1 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 / 2.0f, bounds.top() + pen_width1 / 2.0f, bounds.width() - pen_width1, bounds.height() - pen_width1));
  auto border_rect2 = rectangle::truncate(rectangle_f(bounds.left() + pen_width1 + pen_width2 / 2.0f,  bounds.top() + pen_width1 + pen_width2 / 2.0f, bounds.width() -  2 * pen_width1 - pen_width2, bounds.height() - 2 * pen_width1 - pen_width2));
  
  if (box_model.border_style().top() == border_type::double_border)
    border_rect2 = rectangle::inflate(border_rect2, {-as<int32_t>(pen_width1), -as<int32_t>(pen_width1)});

  // left
  graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + box_model.border_radius().top_left().get_pixels(bounds), border_rect1.x(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds));
  // top-left
  if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), box_model.border_radius().top_left().get_pixels(bounds) * 2, box_model.border_radius().top_left().get_pixels(bounds) * 2, 180, 45);
  // bottom-left
  if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, 135, 45);
  
  if (pen_width2 != 0) {
    // left
    graphics.draw_line(pen2, border_rect2.left(), border_rect2.top() + box_model.border_radius().top_left().get_pixels(bounds) / 2, border_rect2.x(), border_rect2.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds) / 2);
    // top-left
    if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.top(), box_model.border_radius().top_left().get_pixels(bounds), box_model.border_radius().top_left().get_pixels(bounds), 180, 45);
    // bottom-left
    if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen2, border_rect2.left(), border_rect2.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds), box_model.border_radius().bottom_left().get_pixels(bounds), box_model.border_radius().bottom_left().get_pixels(bounds), 135, 45);
  }
}

void box_renderer::fill_box(xtd::drawing::graphics& graphics, const xtd::drawing::brush& brush, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::ibox_model& box_model) {
  graphics_path path;

  auto fill_rect = box_model.get_fill_rectangle(bounds);
  int radius_top_left = box_model.border_radius().top_left().get_pixels(bounds);
  int radius_top_right = box_model.border_radius().top_right().get_pixels(bounds);
  int radius_bottom_right = box_model.border_radius().bottom_right().get_pixels(bounds);
  int radius_bottom_left = box_model.border_radius().bottom_left().get_pixels(bounds);
  
  if (box_model.border_style().top() == border_type::groove || box_model.border_style().top() == border_type::ridge || box_model.border_style().top() == border_type::theme ||box_model.border_style().top() == border_type::double_border)
    radius_top_left /= 3;
  else
    radius_top_left /= 2;
  
  if (box_model.border_style().right() == border_type::groove || box_model.border_style().right() == border_type::ridge || box_model.border_style().right() == border_type::theme ||box_model.border_style().right() == border_type::double_border)
    radius_top_right /= 3;
  else
    radius_top_right /= 2;
  
  if (box_model.border_style().bottom() == border_type::groove || box_model.border_style().bottom() == border_type::ridge || box_model.border_style().bottom() == border_type::theme ||box_model.border_style().bottom() == border_type::double_border)
    radius_bottom_right /= 3;
  else
    radius_bottom_right /= 2;
  
  if (box_model.border_style().left() == border_type::groove || box_model.border_style().left() == border_type::ridge || box_model.border_style().left() == border_type::theme ||box_model.border_style().left() == border_type::double_border)
    radius_bottom_left /= 3;
  else
    radius_bottom_left /= 2;
  
  path.add_line(fill_rect.left() + radius_top_left, fill_rect.top(), fill_rect.right() - radius_top_right, fill_rect.top());
  if (radius_top_right != 0) path.add_arc(fill_rect.right() - radius_top_right * 2, fill_rect.top(), radius_top_right * 2, radius_top_right * 2, 270, 90);
  path.add_line(fill_rect.right(), fill_rect.top() + radius_top_right, fill_rect.right(), fill_rect.bottom() - radius_bottom_right);
  if (radius_bottom_right != 0) path.add_arc(fill_rect.right() - radius_bottom_right * 2, fill_rect.bottom() - radius_bottom_right * 2, radius_bottom_right * 2, radius_bottom_right * 2, 0, 90);
  path.add_line(fill_rect.right() - radius_bottom_right, fill_rect.bottom(), fill_rect.left() + radius_bottom_left, fill_rect.bottom());
  if (radius_bottom_left != 0) path.add_arc(fill_rect.left(), fill_rect.bottom() - radius_bottom_left * 2, radius_bottom_left * 2, radius_bottom_left * 2, 90, 90);
  path.add_line(fill_rect.left(), fill_rect.bottom() - radius_bottom_left, fill_rect.left(), fill_rect.top() + radius_top_left);
  if (radius_top_left != 0) path.add_arc(fill_rect.left(), fill_rect.top(), radius_top_left * 2, radius_top_left * 2, 180, 90);
  graphics.fill_path(brush, path);
}
