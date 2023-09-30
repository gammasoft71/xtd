#include "../../../include/xtd/forms/label_renderer.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/text_renderer.h"
#include "../../../include/xtd/forms/style_sheets/label.h"
#include "../../../include/xtd/forms/style_sheets/link_label.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/unused>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void label_renderer::draw_label(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::label_state label_state, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides, const std::vector<xtd::forms::shadow>& shadows, bool auto_ellipsis) {
  auto pseudo_state_base = pseudo_state::standard;
  
  auto current_style_sheet = label {};
  switch (label_state) {
    case label_state::normal: current_style_sheet = style_sheet.label(pseudo_state_base); break;
    case label_state::hot: current_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::hover); break;
    case label_state::pressed: current_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::pressed); break;
    case label_state::disabled: current_style_sheet = style_sheet.label(pseudo_state_base | pseudo_state::disabled); break;
  }
  if (back_color.has_value()) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && label_state != label_state::disabled) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  if (border) {
    if (current_style_sheet.background_color() == color::transparent) current_style_sheet.border_color(xtd::forms::style_sheets::border_color(style_sheet::current_style_sheet().label().color()));
    else current_style_sheet.border_color(border_color(current_style_sheet.background_color().is_dark() ? color::light(current_style_sheet.background_color(), 2.0 / 3) : color::dark(current_style_sheet.background_color(), 1.0 / 3)));
    auto [border_type, border_width, border_radius] = style_sheets::style_sheet::to_border_type(border.value());
    current_style_sheet.border_style(style_sheets::border_style((sides & border_sides::left) == border_sides::left ? border_type : style_sheets::border_type::none, (sides & border_sides::top) == border_sides::top ? border_type : style_sheets::border_type::none, (sides & border_sides::right) == border_sides::right ? border_type : style_sheets::border_type::none, (sides & border_sides::bottom) == border_sides::bottom ? border_type : style_sheets::border_type::none));
    current_style_sheet.border_width(style_sheets::border_width(length(border_width)));
    current_style_sheet.border_radius(style_sheets::border_radius(length(border_radius)));
  }
  current_style_sheet.auto_ellipsis(auto_ellipsis);
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, label_state != label_state::disabled, current_style_sheet.get_solid_background_color(), current_style_sheet);
  //text_renderer::draw_shadow_text(graphics, content_rectangle, text, current_style_sheet, current_style_sheet);
  if (shadows.empty())  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
  else text_renderer::draw_shadow_text(graphics, content_rectangle, text, current_style_sheet, current_style_sheet);
}

void label_renderer::draw_link_label(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::link_label_state link_label_state, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::vector<xtd::forms::link>& links, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::color>& link_color, const std::optional<xtd::drawing::color>& visited_link_color, const std::optional<xtd::drawing::font>& font, xtd::forms::link_behavior link_behavior, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides, const std::vector<xtd::forms::shadow>& shadows, bool auto_ellipsis) {
  auto pseudo_state_base = pseudo_state::standard;
  
  auto current_style_sheet = style_sheet.link_label(pseudo_state_base), hot_style_sheet = style_sheet.link_label(pseudo_state_base | pseudo_state::hover), pressed_style_sheet = style_sheet.link_label(pseudo_state_base | pseudo_state::active);
  unused_(hot_style_sheet); /// @todo Remove when used...
  unused_(pressed_style_sheet); /// @todo Remove when used...
  
  if (link_label_state == link_label_state::disabled) current_style_sheet = style_sheet.link_label(pseudo_state_base | pseudo_state::disabled);
  
  if (back_color.has_value()) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && link_label_state != link_label_state::disabled) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  if (border) {
    if (current_style_sheet.background_color() == color::transparent) current_style_sheet.border_color(xtd::forms::style_sheets::border_color(style_sheet::current_style_sheet().label().color()));
    else current_style_sheet.border_color(border_color(current_style_sheet.background_color().is_dark() ? color::light(current_style_sheet.background_color(), 2.0 / 3) : color::dark(current_style_sheet.background_color(), 1.0 / 3)));
    auto [border_type, border_width, border_radius] = style_sheets::style_sheet::to_border_type(border.value());
    current_style_sheet.border_style(style_sheets::border_style((sides & border_sides::left) == border_sides::left ? border_type : style_sheets::border_type::none, (sides & border_sides::top) == border_sides::top ? border_type : style_sheets::border_type::none, (sides & border_sides::right) == border_sides::right ? border_type : style_sheets::border_type::none, (sides & border_sides::bottom) == border_sides::bottom ? border_type : style_sheets::border_type::none));
    current_style_sheet.border_width(style_sheets::border_width(length(border_width)));
    current_style_sheet.border_radius(style_sheets::border_radius(length(border_radius)));
  }
  current_style_sheet.auto_ellipsis(auto_ellipsis);
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, link_label_state != link_label_state::disabled, current_style_sheet.get_solid_background_color(), current_style_sheet);
  text_renderer::draw_shadow_text_and_links(graphics, content_rectangle, text, current_style_sheet, current_style_sheet);
  //if (shadow) text_renderer::draw_shadow_text_and_links(graphics, content_rectangle, text, current_style_sheet, current_style_sheet);
  //else text_renderer::draw_text_and_links(graphics, content_rectangle, text, current_style_sheet);
}
