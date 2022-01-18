#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
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
  array<border_data, 4> borders = {
    border_data {std::make_shared<solid_brush>(color::black), border_style::outset, 20, 10},
    border_data {std::make_shared<solid_brush>(color::black), border_style::outset, 20, 10},
    border_data {std::make_shared<solid_brush>(color::black), border_style::outset, 20, 10},
    border_data {std::make_shared<solid_brush>(color::black), border_style::outset, 20, 10},
  };
  box_data data(padding(3, 5, 3, 0), borders, padding(1), make_shared<solid_brush>(back_color.value_or(color::light_gray)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
}
