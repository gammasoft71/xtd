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

namespace {
  static void fill_box(xtd::drawing::graphics& graphics, const xtd::drawing::brush& brush, const xtd::drawing::rectangle& fill_rect, int radius_top_left, int radius_top_right, int radius_bottom_right, int radius_bottom_left) {
    /*
     graphics_path path;
     if (radius_top_left != 0) path.add_arc(fill_rect.left(), fill_rect.top(), radius_top_left * 2, radius_top_left * 2, 180, 90);
     path.add_line(fill_rect.left() + radius_top_left / 2, fill_rect.top(), fill_rect.right() - radius_top_right / 2, fill_rect.top());
     if (radius_top_right != 0) path.add_arc(fill_rect.right() - radius_top_right * 2, fill_rect.top(), radius_top_right * 2, radius_top_right * 2, 270, 90);
     path.add_line(fill_rect.right(), fill_rect.top() + radius_top_right / 2, fill_rect.right(), fill_rect.bottom() - radius_bottom_right / 2);
     if (radius_bottom_right != 0) path.add_arc(fill_rect.right() - radius_bottom_right * 2, fill_rect.bottom() - radius_bottom_right * 2, radius_bottom_right * 2, radius_bottom_right * 2, 0, 90);
     path.add_line(fill_rect.right() - radius_bottom_right  /2, fill_rect.bottom(), fill_rect.left() + radius_bottom_left / 2, fill_rect.bottom());
     if (radius_bottom_left != 0) path.add_arc(fill_rect.left(), fill_rect.bottom() - radius_bottom_left * 2, radius_bottom_left * 2, radius_bottom_left * 2, 90, 90);
     path.add_line(fill_rect.left(), fill_rect.bottom() - radius_bottom_left  /2, fill_rect.left(), fill_rect.top() + radius_top_left / 2);
     path.close_all_figures();
     graphics.fill_path(brush, path);
     */
    
    xtd::drawing::region region;
    region.make_empty();
    
    if (radius_top_left != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.left(), fill_rect.top(), radius_top_left * 2, radius_top_left * 2, 180, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_top_right != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.right() - radius_top_right * 2, fill_rect.top(), radius_top_right * 2, radius_top_right * 2, 270, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_bottom_right != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.right() - radius_bottom_right * 2, fill_rect.bottom() - radius_bottom_right * 2, radius_bottom_right * 2, radius_bottom_right * 2, 0, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_bottom_left != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.left(), fill_rect.bottom() - radius_bottom_left * 2, radius_bottom_left * 2, radius_bottom_left * 2, 90, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    region.make_union(rectangle(fill_rect.left() + radius_top_left, fill_rect.top() + xtd::math::max(radius_top_left, radius_top_right), fill_rect.width() - radius_top_left - radius_top_right, fill_rect.height() - xtd::math::max(radius_top_left, radius_top_right) - xtd::math::max(radius_bottom_left, radius_bottom_right)));
    
    region.make_union(rectangle(fill_rect.left() + radius_top_left, fill_rect.top(), fill_rect.width() - radius_top_left - radius_top_right, xtd::math::max(radius_top_left, radius_top_right)));
    region.make_union(rectangle(fill_rect.left() + radius_bottom_left, fill_rect.bottom() - 1, fill_rect.width() - radius_bottom_left - radius_bottom_right, -math::max(radius_bottom_left, radius_bottom_right) - 1));
    
    region.make_union(rectangle(fill_rect.left(), fill_rect.top() + radius_top_left, xtd::math::max(radius_top_left, radius_bottom_left), fill_rect.height() - radius_top_left - radius_bottom_left));
    region.make_union(rectangle(fill_rect.right() - 1 - xtd::math::max(radius_top_right, radius_bottom_right), fill_rect.top() + radius_top_right, xtd::math::max(radius_top_right, radius_bottom_right) + 1, fill_rect.height() - radius_top_right - radius_bottom_right));
    
    graphics.fill_region(brush, region);
  }
}

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  auto border_rect = box_model.get_border_rectangle(bounds);
  draw_line_top(graphics, border_rect, box_model);
  draw_line_left(graphics, border_rect, box_model);
  draw_line_bottom(graphics, border_rect, box_model);
  draw_line_right(graphics, border_rect, box_model);
  
  auto fill_rect = box_model.get_fill_rectangle(bounds);
  graphics.fill_rounded_rectangle(solid_brush(box_model.background_color()), fill_rect, box_model.border_radius().top_left().get_pixels(bounds));
  auto image_brush = background_image::make_brush(box_model.background_image(), fill_rect);
  if (image_brush) fill_box(graphics, *image_brush, fill_rect, box_model.border_radius().top_left().get_pixels(bounds), box_model.border_radius().top_right().get_pixels(bounds), box_model.border_radius().bottom_right().get_pixels(bounds), box_model.border_radius().bottom_left().get_pixels(bounds));
}

void box_renderer::draw_line_top(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().top().get_pixels(bounds) == 0) return;
  auto pen_width1 = box_model.border_width().top().get_pixels(bounds);
  auto border_rect1 = rectangle::add(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(box_model.border_color().top());
  
  if (box_model.border_style().top() == border_type::inset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  if (box_model.border_style().top() == border_type::outset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
    
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(box_model.border_style().top()));
  // top
  graphics.draw_line(pen1, border_rect1.left() + box_model.border_radius().top_left().get_pixels(bounds), border_rect1.top(), border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds), border_rect1.top());
  // top-left
  if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), box_model.border_radius().top_left().get_pixels(bounds) * 2, box_model.border_radius().top_left().get_pixels(bounds) * 2, 225, 45);
  // top-right
  if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds) * 2, border_rect1.top(), box_model.border_radius().top_right().get_pixels(bounds) * 2, box_model.border_radius().top_right().get_pixels(bounds) * 2, 270, 45);
}

void box_renderer::draw_line_right(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().right().get_pixels(bounds) == 0) return;
  auto pen_width1 = box_model.border_width().right().get_pixels(bounds);
  auto border_rect1 = rectangle::add(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(box_model.border_color().right());
  
  if (box_model.border_style().right() == border_type::inset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  if (box_model.border_style().right() == border_type::outset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
    
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(box_model.border_style().right()));
  // right
  graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + box_model.border_radius().top_right().get_pixels(bounds), border_rect1.right(), border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds));
  // top-right
  if (box_model.border_radius().top_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().top_right().get_pixels(bounds) * 2, border_rect1.top(), box_model.border_radius().top_right().get_pixels(bounds) * 2, box_model.border_radius().top_right().get_pixels(bounds) * 2, 315, 45);
  // bottom-right
  if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, 0, 45);
}

void box_renderer::draw_line_bottom(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().bottom().get_pixels(bounds) == 0) return;
  auto pen_width1 = box_model.border_width().bottom().get_pixels(bounds);
  auto border_rect1 = rectangle::add(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(box_model.border_color().bottom());
  
  if (box_model.border_style().bottom() == border_type::inset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
  if (box_model.border_style().bottom() == border_type::outset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
    
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(box_model.border_style().bottom()));
  // bottom
  graphics.draw_line(pen1, border_rect1.left() + box_model.border_radius().bottom_left().get_pixels(bounds), border_rect1.bottom(), border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds), border_rect1.bottom());
  // bottom-left
  if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, 90, 45);
  // bottom-right
  if (box_model.border_radius().bottom_right().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.right() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, border_rect1.bottom() - box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, box_model.border_radius().bottom_right().get_pixels(bounds) * 2, 45, 45);
}

void box_renderer::draw_line_left(graphics& graphics, const rectangle& bounds, const ibox_model& box_model) {
  if (box_model.border_width().left().get_pixels(bounds) == 0) return;
  auto pen_width1 = box_model.border_width().left().get_pixels(bounds);
  auto border_rect1 = rectangle::add(rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
  auto color1 = solid_brush(box_model.border_color().left());
  
  if (box_model.border_style().left() == border_type::inset && color1.color().is_light())
    color1 = solid_brush(color::dark(color1.color()));
  if (box_model.border_style().left() == border_type::outset && color1.color().is_dark())
    color1 = solid_brush(color::light(color1.color()));
    
  auto pen1 = pen(color1, as<float>(pen_width1));
  pen1.dash_style(border_type_to_dash_style(box_model.border_style().left()));
  // left
  graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + box_model.border_radius().top_left().get_pixels(bounds), border_rect1.x(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds));
  // top-left
  if (box_model.border_radius().top_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), box_model.border_radius().top_left().get_pixels(bounds) * 2, box_model.border_radius().top_left().get_pixels(bounds) * 2, 180, 45);
  // bottom-left
  if (box_model.border_radius().bottom_left().get_pixels(bounds)) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, box_model.border_radius().bottom_left().get_pixels(bounds) * 2, 135, 45);
}

dash_style box_renderer::border_type_to_dash_style(border_type value) {
  if (value == border_type::solid) return dash_style::solid;
  if (value == border_type::dashed) return dash_style::dash;
  if (value == border_type::dotted) return dash_style::dot;
  if (value == border_type::dot_dash) return dash_style::dash_dot;
  if (value == border_type::dot_dot_dash) return dash_style::dash_dot_dot;
  return dash_style::solid;
}
