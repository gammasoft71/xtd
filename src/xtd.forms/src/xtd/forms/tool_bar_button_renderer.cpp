#include "../../../include/xtd/forms/style_sheets/tool_bar_button.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"
#include "../../../include/xtd/forms/tool_bar_button_renderer.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/text_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;
using namespace xtd::forms::style_sheets;

void tool_bar_button_renderer::draw_tool_bar_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, const optional<color>& back_color, const flat_button_appearance& appearance, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  
  auto current_style_sheet = tool_bar_button {};
  switch (button_state) {
    case push_button_state::normal: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base); break;
    case push_button_state::hot: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: current_style_sheet = style_sheet.tool_bar_button(pseudo_state_base | pseudo_state::default_state); break;
  }
  if (back_color.has_value() && (button_state == push_button_state::normal || button_state == push_button_state::default_state)) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && button_state != push_button_state::disabled) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  
  if (appearance.border_radius().has_value()) current_style_sheet.border_radius(xtd::forms::style_sheets::border_radius(length(appearance.border_radius().value())));
  if (appearance.border_size().has_value()) current_style_sheet.border_width(xtd::forms::style_sheets::border_width(length(appearance.border_size().value())));
  if (appearance.border_color().has_value()) current_style_sheet.border_color(xtd::forms::style_sheets::border_color(appearance.border_color().value()));
  if (appearance.checked_back_color().has_value() && button_state == push_button_state::checked) current_style_sheet.background_color(appearance.checked_back_color().value());
  if (appearance.mouse_down_back_color().has_value() && button_state == push_button_state::pressed) current_style_sheet.background_color(appearance.mouse_down_back_color().value());
  if (appearance.mouse_over_back_color().has_value() && button_state == push_button_state::hot) current_style_sheet.background_color(appearance.mouse_over_back_color().value());
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, button_state != push_button_state::disabled, current_style_sheet.get_solid_background_color(), current_style_sheet);
  if (current_style_sheet.text_alignment() == content_alignment::middle_left && image != drawing::image::empty)
    content_rectangle = rectangle::offset(content_rectangle, drawing::point(image.size().width() + 4, 0));
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}
