#include "../../../../include/xtd/forms/style_sheets/form_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

void form_renderer::draw_form(graphics& graphics, const rectangle& bounds) {
  draw_form(graphics, bounds, flat_style::standard, form_state::normal, nullopt);
}

void form_renderer::draw_form(graphics& graphics, const rectangle& bounds, flat_style form_style) {
  draw_form(graphics, bounds, form_style, form_state::normal, nullopt);
}

void form_renderer::draw_form(graphics& graphics, const rectangle& bounds, flat_style form_style, form_state form_state) {
  draw_form(graphics, bounds, form_style, form_state, nullopt);
}

void form_renderer::draw_form(graphics& graphics, const rectangle& bounds, xtd::forms::flat_style form_style, form_state form_state, const optional<color>& back_color) {
  array<border_data, 4> borders = {
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
  };
  box_data data(padding(0), borders, padding(0), make_shared<solid_brush>(back_color.value_or(color::light_gray)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
}
