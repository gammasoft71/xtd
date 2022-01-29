#include "../../../include/xtd/forms/control_renderer.h"
#include "../../../include/xtd/forms/style_sheets/control_selector.h"

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
  //control_selector current_control_selector(padding(0), border_style(border_type::none), border_color(color::black), border_width(0), border_radius(0), padding(0), back_color.value_or(color::light_gray), std::nullopt, std::nullopt, back_color, content_alignment::middle_center, system_fonts::default_font());
  //box_renderer::draw_box(graphics, bounds, current_control_selector);
}
