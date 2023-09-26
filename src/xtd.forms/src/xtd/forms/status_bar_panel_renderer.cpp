#include "../../../include/xtd/forms/style_sheets/status_bar_panel"
#include "../../../include/xtd/forms/style_sheets/pseudo_state"
#include "../../../include/xtd/forms/style_sheets/style_sheet"
#include "../../../include/xtd/forms/image_renderer"
#include "../../../include/xtd/forms/status_bar_panel_renderer"
#include "../../../include/xtd/forms/text_renderer"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;
using namespace xtd::forms::style_sheets;

void status_bar_panel_renderer::draw_status_bar_panel(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, const optional<color>& back_color, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  
  auto current_style_sheet = style_sheet.status_bar_panel(pseudo_state_base);
  if (back_color.has_value()) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value()) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, true, current_style_sheet.get_solid_background_color(), current_style_sheet);
  if (current_style_sheet.text_alignment() == content_alignment::middle_left && image != drawing::image::empty)
    content_rectangle = rectangle::offset(content_rectangle, drawing::point(image.size().width() + 4, 0));
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}
