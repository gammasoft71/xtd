#include "../../../include/xtd/forms/label_renderer.h"
#include "../../../include/xtd/forms/style_sheets/label.h"

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
  //label currrent_label_selector(padding(0), border_style(border_type::none), border_color(color::black), border_width(0), border_radius(0), padding(0), back_color.value_or(color::light_gray), std::nullopt, std::nullopt, back_color, content_alignment::top_left, system_fonts::default_font());
  //box_renderer::draw_box(graphics, bounds, currrent_label_selector);
  //text_renderer::draw_text(graphics, currrent_label_selector.get_content_rectangle(bounds), "text", currrent_label_selector);
}
