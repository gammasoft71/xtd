#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, const xtd::ustring& text, text_format_flags text_format, const image& image, const rectangle& image_bounds) {
  draw_button(graphics, bounds, button_style, text, text_format, image, image_bounds, false, push_button_state::normal);
}
void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, const ustring& text, text_format_flags text_format, const image& image, const rectangle& image_bounds, bool focused, push_button_state button_state) {
  draw_button(graphics, bounds, button_style, text, text_format, image, image_bounds, focused, button_state, nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, const xtd::ustring& text, text_format_flags text_format, const image& image, const rectangle& image_bounds, bool focused, push_button_state button_state, const optional<font>& font, const optional<color>& back_color, const optional<color>& fore_color) {
  std::array<style_sheets::border_data, 4> borders = {
    style_sheets::border_data {std::make_shared<solid_brush>(color::black), style_sheets::border_style::outset, 20, 10},
    style_sheets::border_data {std::make_shared<solid_brush>(color::black), style_sheets::border_style::outset, 20, 10},
    style_sheets::border_data {std::make_shared<solid_brush>(color::black), style_sheets::border_style::outset, 20, 10},
    style_sheets::border_data {std::make_shared<solid_brush>(color::black), style_sheets::border_style::outset, 20, 10},
  };
  box_data data(padding(3, 5, 3, 0), borders, padding(1), std::make_shared<solid_brush>(back_color.value_or(color::light_gray)), std::nullopt, std::nullopt);
  
  box_renderer::draw_box(graphics, bounds, data);
  //style_sheets::text_renderer::draw_text(graphics, text, font, color::white, rect, text_format);
  }
