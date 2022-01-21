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
  draw_button(graphics, bounds, flat_style::standard, push_button_state::normal, nullopt, "", nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style) {
  draw_button(graphics, bounds, button_style, push_button_state::normal, nullopt, "", nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state) {
  draw_button(graphics, bounds, button_style, button_state, nullopt, "", nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, const optional<color>& back_color) {
  draw_button(graphics, bounds, button_style, button_state, nullopt, "", nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, const optional<color>& back_color, const ustring& text, const optional<color>& fore_color, const optional<font>& font) {
  auto box_data = style_sheets::box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(35, 0, 0, 0)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(64, 255, 255, 255), color::from_argb(64, 255, 255, 255)}, 180), std::nullopt, std::nullopt);
  if (button_state == push_button_state::pressed) box_data = style_sheets::box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(35, 0, 0, 0)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(80, 255, 255, 255), color::from_argb(80, 255, 255, 255)}, 180), std::nullopt, std::nullopt);
  //if (button_state == push_button_state::hot) box_data = style_sheets::box_data(padding(0, 1, 0, 1), {color_data(color::from_argb(35, 0, 0, 0)), border_style::outset, 1, 5}, padding(1), color_data(color_style::linear_gradient, {color::from_argb(0x50FFFFFF), color::from_argb(0x50AAAAAA)}, 180), std::nullopt, std::nullopt);
  box_renderer::draw_box(graphics, bounds, box_data);
  
  auto text_data = style_sheets::text_data(color_data(color::from_argb(216, 255, 255, 255)), content_alignment::middle_center, system_fonts::default_font());
  text_renderer::draw_text(graphics, box_data.get_content_rectangle(bounds), text, text_data);
}
