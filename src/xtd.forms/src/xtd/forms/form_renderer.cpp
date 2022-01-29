#include "../../../include/xtd/forms/form_renderer.h"
#include "../../../include/xtd/forms/style_sheets/form.h"

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
  //form current_form_selector(padding(0), border_style(border_type::none), border_color(color::black), border_width(0), border_radius(0), padding(0), back_color.value_or(color::light_gray), std::nullopt, std::nullopt, back_color, content_alignment::middle_center, system_fonts::default_font());
  //bbox_renderer::draw_box(graphics, bounds, current_form_selector);
}
