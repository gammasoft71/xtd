#include "../../../include/xtd/forms/style_sheets/status_bar"
#include "../../../include/xtd/forms/style_sheets/pseudo_state"
#include "../../../include/xtd/forms/style_sheets/style_sheet"
#include "../../../include/xtd/forms/status_bar_renderer"
#include "../../../include/xtd/forms/text_renderer"
#include <tuple>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void status_bar_renderer::draw_status_bar(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::form_state form_state, const std::optional<xtd::drawing::color>& back_color, const std::optional<border_style>& border, xtd::forms::border_sides sides) {
  auto current_style_sheet = style_sheet.status_bar(style_sheets::pseudo_state::standard);
  
  if (back_color) current_style_sheet.background_color(back_color.value());
  if (border) {
    if (current_style_sheet.background_color() == color::transparent) current_style_sheet.border_color(xtd::forms::style_sheets::border_color(style_sheet::current_style_sheet().status_bar().color()));
    else current_style_sheet.border_color(border_color(current_style_sheet.background_color().is_dark() ? color::light(current_style_sheet.background_color(), 2.0 / 3) : color::dark(current_style_sheet.background_color(), 1.0 / 3)));
    auto [border_type, border_width, border_radius] = style_sheets::style_sheet::to_border_type(border.value());
    current_style_sheet.border_style(style_sheets::border_style((sides & border_sides::left) == border_sides::left ? border_type : style_sheets::border_type::none, (sides & border_sides::top) == border_sides::top ? border_type : style_sheets::border_type::none, (sides & border_sides::right) == border_sides::right ? border_type : style_sheets::border_type::none, (sides & border_sides::bottom) == border_sides::bottom ? border_type : style_sheets::border_type::none));
    current_style_sheet.border_width(style_sheets::border_width(length(border_width)));
    current_style_sheet.border_radius(style_sheets::border_radius(length(border_radius)));
  }
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
}

void status_bar_renderer::draw_text_status_bar(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font) {
  auto current_style_sheet = style_sheet.status_bar(pseudo_state::standard);
  
  if (fore_color.has_value()) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}
