#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>

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
  border_data border(std::make_shared<solid_brush>(color::from_argb(0x35000000)), border_style::solid, 1, 5);
  box_data data(padding(3, 5, 3, 0), border, padding(1), make_shared<linear_gradient_brush>(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, color::from_argb(0x40FFFFFF), color::from_argb(0x40FFFFFF)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
}
