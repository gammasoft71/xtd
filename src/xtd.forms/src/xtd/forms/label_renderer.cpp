#include "../../../include/xtd/forms/label_renderer.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/text_renderer.h"
#include "../../../include/xtd/forms/style_sheets/label.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void label_renderer::draw_label(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::label_state label_state, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  
  label current_label_style_sheet;
  switch (label_state) {
    case label_state::normal: current_label_style_sheet = style_sheet.label(pseudo_state_base); break;
    case label_state::hot: current_label_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::hover); break;
    case label_state::pressed: current_label_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::pressed); break;
    case label_state::disabled: current_label_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::disabled); break;
  }
  if (back_color.has_value() && label_state == label_state::normal) current_label_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_label_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && label_state != label_state::disabled) current_label_style_sheet.color(fore_color.value());
  if (font.has_value()) current_label_style_sheet.font(font.value());
  if (image_align.has_value()) current_label_style_sheet.image_alignment(image_align.value());
  
  box_renderer::draw_box(graphics, bounds, current_label_style_sheet);
  auto content_rectangle = current_label_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, label_state != label_state::disabled, current_label_style_sheet.get_solid_background_color(), current_label_style_sheet);
  text_renderer::draw_text(graphics, content_rectangle, text, current_label_style_sheet);
}
