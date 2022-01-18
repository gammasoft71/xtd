#include "../../../../include/xtd/forms/style_sheets/label_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

void label_renderer::draw_label(graphics& graphics, const rectangle& bounds) {
  draw_label(graphics, bounds, flat_style::standard, label_state::normal, nullopt);
}

void label_renderer::draw_label(graphics& graphics, const rectangle& bounds, flat_style label_style) {
  draw_label(graphics, bounds, label_style, label_state::normal, nullopt);
}

void label_renderer::draw_label(graphics& graphics, const rectangle& bounds, flat_style label_style, label_state label_state) {
  draw_label(graphics, bounds, label_style, label_state, nullopt);
}

void label_renderer::draw_label(graphics& graphics, const rectangle& bounds, xtd::forms::flat_style label_style, label_state label_state, const optional<color>& back_color) {
  array<border_data, 4> borders = {
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
    border_data {std::make_shared<solid_brush>(color::black), border_style::none, 0, 0},
  };
  box_data data(padding(0), borders, padding(0), make_shared<solid_brush>(back_color.value_or(color::light_gray)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
}
