#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/console.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds) {
  draw_button(graphics, bounds, flat_style::standard, push_button_state::normal, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style) {
  draw_button(graphics, bounds, button_style, push_button_state::normal, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state) {
  draw_button(graphics, bounds, button_style, button_state, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, xtd::forms::flat_style button_style, push_button_state button_state, const optional<color>& back_color) {
  //border_data border(color_data(color::from_argb(0x23000000)), border_style::solid, 1, 5);
  //static box_data previous_state = box_data(padding(3, 5, 3, 0), {color_data(color::from_argb(0x23000000)), border_style::solid, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(0x40FFFFFF), color::from_argb(0x40FFFFFF)}, 180), std::nullopt, std::nullopt);

  //box_data data = previous_state;

  box_data data = box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(0x23000000)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(0x40FFFFFF), color::from_argb(0x40AAAAAA)}, 180), std::nullopt, std::nullopt);
  if (button_state == push_button_state::pressed) data = box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(0x32000000)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(0x50FFFFFF), color::from_argb(0x50AAAAAA)}, 180), std::nullopt, std::nullopt);
  //if (button_state == push_button_state::hot) data = box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(0x32000000)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(0x50FFFFFF), color::from_argb(0x50AAAAAA)}, 180), std::nullopt, std::nullopt);

  //previous_state = data;
  box_renderer::draw_box(graphics, bounds, data);
}
