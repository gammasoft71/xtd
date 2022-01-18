#include "../../../../include/xtd/forms/style_sheets/control_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds) {
  draw_control(graphics, bounds, flat_style::standard, control_state::normal, nullopt);
}

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds, flat_style control_style) {
  draw_control(graphics, bounds, control_style, control_state::normal, nullopt);
}

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds, flat_style control_style, control_state control_state) {
  draw_control(graphics, bounds, control_style, control_state, nullopt);
}

void control_renderer::draw_control(graphics& graphics, const rectangle& bounds, xtd::forms::flat_style control_style, control_state control_state, const optional<color>& back_color) {
  array<border_data, 4> borders = {
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
  };
  box_data data(padding(0), borders, padding(0), make_shared<solid_brush>(back_color.value_or(color::light_gray)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
}
