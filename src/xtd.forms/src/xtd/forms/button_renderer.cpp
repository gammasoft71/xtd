#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/text_renderer.h"
#include "../../../include/xtd/forms/style_sheets/button.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <map>
#include <xtd/environment.h>
#include <xtd/invalid_operation_exception.h>
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing_2d/linear_gradient_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;
using namespace xtd::forms::style_sheets;

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds) {
  draw_button(style_sheet, graphics, bounds, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button) {
  draw_button(style_sheet, graphics, bounds, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, button_state, default_button, back_color, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color) {
  draw_button(style_sheet, graphics, bounds, button_state, default_button, back_color, "", nullopt, nullopt, nullopt, image::empty, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, button_state, default_button, back_color, text, text_align, fore_color, font, image::empty, nullopt);
}

void button_renderer::draw_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, button_state, default_button, back_color, text, text_align, fore_color, font, image::empty, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<xtd::forms::content_alignment>& image_align) {
  draw_button(style_sheet::current_style_sheet(), graphics, bounds, button_state, default_button, back_color, text, text_align, fore_color, font, image, image_align);
}

void button_renderer::draw_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  if (default_button) pseudo_state_base += pseudo_state::default_state;
  
  xtd::forms::style_sheets::button current_style_sheet;
  switch (button_state) {
    case push_button_state::normal: current_style_sheet = style_sheet.button(pseudo_state_base); break;
    case push_button_state::hot: current_style_sheet = style_sheet.button(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: current_style_sheet = style_sheet.button(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: current_style_sheet = style_sheet.button(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: current_style_sheet = style_sheet.button(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: current_style_sheet = style_sheet.button(pseudo_state_base | pseudo_state::default_state); break;
  }
  if (back_color.has_value() && (button_state == push_button_state::normal || button_state == push_button_state::default_state)) current_style_sheet.background_color(back_color.value());
  if (text_align.has_value()) current_style_sheet.text_alignment(text_align.value());
  if (fore_color.has_value() && button_state != push_button_state::disabled) current_style_sheet.color(fore_color.value());
  if (font.has_value()) current_style_sheet.font(font.value());
  if (image_align.has_value()) current_style_sheet.image_alignment(image_align.value());
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
  auto content_rectangle = current_style_sheet.get_content_rectangle(bounds);
  image_renderer::draw_image(graphics, content_rectangle, image, button_state != push_button_state::disabled, current_style_sheet.get_solid_background_color(), current_style_sheet);
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}

void button_renderer::draw_flat_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const flat_button_appearance& appearance, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  if (default_button) pseudo_state_base += pseudo_state::default_state;
  
  xtd::forms::style_sheets::button current_style_sheet;
  switch (button_state) {
    case push_button_state::normal: current_style_sheet = style_sheet.flat_button(pseudo_state_base); break;
    case push_button_state::hot: current_style_sheet = style_sheet.flat_button(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: current_style_sheet = style_sheet.flat_button(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: current_style_sheet = style_sheet.flat_button(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: current_style_sheet = style_sheet.flat_button(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: current_style_sheet = style_sheet.flat_button(pseudo_state_base | pseudo_state::default_state); break;
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
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}

void button_renderer::draw_popup_button(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, push_button_state button_state, bool default_button, const optional<color>& back_color, const flat_button_appearance& appearance, const ustring& text, const optional<content_alignment>& text_align, const optional<color>& fore_color, const optional<font>& font, const xtd::drawing::image& image, const optional<content_alignment>& image_align) {
  auto pseudo_state_base = pseudo_state::standard;
  if (default_button) pseudo_state_base += pseudo_state::default_state;
  
  xtd::forms::style_sheets::button current_style_sheet;
  switch (button_state) {
    case push_button_state::normal: current_style_sheet = style_sheet.popup_button(pseudo_state_base); break;
    case push_button_state::hot: current_style_sheet = style_sheet.popup_button(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: current_style_sheet = style_sheet.popup_button(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: current_style_sheet = style_sheet.popup_button(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: current_style_sheet = style_sheet.popup_button(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: current_style_sheet = style_sheet.popup_button(pseudo_state_base | pseudo_state::default_state); break;
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
  text_renderer::draw_text(graphics, content_rectangle, text, current_style_sheet);
}

namespace {
  xtd::ustring get_hotkey_prefix_locations(const xtd::ustring& str, std::vector<size_t>& locations) {
    auto offset = 0_sz;
    for (auto index = 0_sz; index < str.size(); index++) {
      if (str[index] == '&' && str[index + 1] != '&')
        locations.push_back(index + offset);
      else if (str[index] == '&' && str[index + 1] == '&') {
        offset -= 2;
        ++index;
      }
    }
    auto new_str = str.replace("&&", "&");
    for (auto index = 0_sz; index < locations.size(); ++index)
      new_str = new_str.remove(locations[index], 1);
    return new_str;
  }
  
  void draw_string(graphics g, const ustring& text, const font& font, const color& text_color, const rectangle_f& button_rect, text_format_flags flags) {
    vector<size_t> hotkey_prefix_locations;
    ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void button_renderer::draw_button(const ustring& theme, graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme.to_lower() == "gnome") draw_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "gnome (dark)") draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "gnome (light)") draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde") draw_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde (dark)") draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde (light)") draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos") draw_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos (dark)") draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos (light)") draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic") draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic (dark)") draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic (light)") draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows") draw_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows (dark)") draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows (light)") draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd") draw_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd (dark)") draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd (light)") draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::dark(background_color, 0.1);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.02);
  else if (state == visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = application::style_sheet().system_colors().control_dark();
  else if (state == visual_styles::push_button_state::disabled)
    text_color = application::style_sheet().system_colors().gray_text();
  else if (state == visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(application::style_sheet().system_colors().accent(), 2.0 / 3);
    
  if (state == visual_styles::push_button_state::pressed)
    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  else
    g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.05), button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_gnome_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::light(background_color, 0.05);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.5);
  else if (state == visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = application::style_sheet().system_colors().control_dark();
  else if (state == visual_styles::push_button_state::disabled)
    text_color = application::style_sheet().system_colors().gray_text();
  else if (state == visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(application::style_sheet().system_colors().accent(), 2.0 / 3);
    
  if (state == visual_styles::push_button_state::pressed)
    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  else
    g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.25), button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_kde(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_kde_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32 offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    offset += 1;
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = application::style_sheet().system_colors().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  }
  
  if (focused) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  }
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + offset, bounds.y() + offset, bounds.width() - 1, bounds.height() - 1, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x() + offset, bounds.y() + offset, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + offset + 5, bounds.y() + offset + 3, bounds.width() - 11, bounds.height() - 8);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_kde_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32 offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    offset += 1;
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = application::style_sheet().system_colors().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  }
  
  if (focused) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  }
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + offset, bounds.y() + offset, bounds.width() - 1, bounds.height() - 1, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x() + offset, bounds.y() + offset, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + offset + 5, bounds.y() + offset + 3, bounds.width() - 11, bounds.height() - 8);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_macos(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_macos_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto border_color = xtd::drawing::color::from_argb(35, 0, 0, 0);
  auto button_color = application::style_sheet().system_colors().button_face();
  auto text_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = color::from_argb(93, application::style_sheet().system_colors().button_face());
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = color::from_argb(30, application::style_sheet().system_colors().button_face());
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    button_color = control_paint::dark(application::style_sheet().system_colors().accent(), 0.15);
    
  auto button_rect = bounds;
  if (bounds.height() > 25) {
    button_rect.offset({1, 0});
    button_rect.add({-2, -1});
  }
  
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, button_color, button_color), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_macos_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = application::style_sheet().system_colors().button_face();
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = color::from_argb(240, 240, 240);
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = back_color.has_value() ? color::from_argb(210, 255, 255, 255) : control_paint::dark(button_color, 0.04);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    if (bounds.height() <= 25) {
      button_color = control_paint::light(application::style_sheet().system_colors().accent(), 0.15);
      if (!fore_color.has_value()) text_color = application::style_sheet().system_colors().accent_text();
    }
  }
  
  auto button_rect = bounds;
  if (bounds.height() > 25) {
    button_rect.offset({1, 0});
    button_rect.add({-2, -1});
  }
  
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 5);
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, button_color, control_paint::dark(button_color, .01)), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_symbolic(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_symbolic_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(application::style_sheet().system_colors().accent(), 2.0 / 3);
    
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, .1), control_paint::dark(button_color)), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_symbolic_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = button_color = application::style_sheet().system_colors().accent();
    text_color = application::style_sheet().system_colors().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(application::style_sheet().system_colors().accent(), 2.0 / 3);
    
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, .1), control_paint::dark(button_color)), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_windows(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_windows_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().active_border();
  auto border_color = background_color;
  auto button_color = background_color;
  auto text_color = foreground_color;
  
  if (state == push_button_state::hot)
    active_border_color = border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    active_border_color = border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = application::style_sheet().system_colors().active_border();
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    active_border_color = border_color = control_paint::dark(application::style_sheet().system_colors().accent());
    
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 2, bounds.width() - 2, bounds.height() - 4);
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 2, bounds.width() - 3, bounds.height() - 5);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 3, bounds.width() - 5, bounds.height() - 7);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_windows_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().active_border();
  auto border_color = application::style_sheet().system_colors().button_face();
  auto button_color = background_color;
  auto text_color = foreground_color;
  if (state == push_button_state::hot) {
    active_border_color = application::style_sheet().system_colors().accent();
    border_color = color::from_argb(232, 243, 251);
    if (!back_color.has_value()) button_color = color::from_argb(232, 243, 251);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    active_border_color = application::style_sheet().system_colors().highlight();
    border_color = application::style_sheet().system_colors().accent();
    if (!back_color.has_value()) button_color = application::style_sheet().system_colors().accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = application::style_sheet().system_colors().active_border();
    if (!back_color.has_value()) button_color = color::from_argb(204, 204, 204);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = application::style_sheet().system_colors().highlight();
    border_color = application::style_sheet().system_colors().highlight();
    auto text_rect = rectangle(bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
    draw_string(g, text, font, text_color, text_rect, flags);
  }
  
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 2, bounds.width() - 2, bounds.height() - 4);
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 2, bounds.width() - 3, bounds.height() - 5);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 3, bounds.width() - 5, bounds.height() - 7);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_xtd(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_flat_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
  else  draw_flat_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_flat_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.value_or(application::style_sheet().system_colors().control());
  auto foreground_color = fore_color.value_or(application::style_sheet().system_colors().control_text());
  auto active_border_color = flat_appearance.border_color().value_or(application::style_sheet().system_colors().control_text());
  auto border_color = flat_appearance.border_color().value_or(application::style_sheet().system_colors().control_text());
  auto button_color = background_color;
  auto text_color = foreground_color;
  
  if (environment::os_version().is_macos_platform()) {
    background_color = back_color.value_or(color::transparent);
    button_color = back_color.value_or(color::transparent);
  }
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    button_color = flat_appearance.mouse_over_back_color().value_or(application::style_sheet().system_colors().accent());
  else if (state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = flat_appearance.checked_back_color().value_or(application::style_sheet().system_colors().accent());
  else if (state == xtd::forms::visual_styles::push_button_state::pressed)
    button_color = flat_appearance.mouse_down_back_color().value_or(background_color);
  else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = application::style_sheet().system_colors().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, environment::os_version().is_windows_platform() ? 0 : 4);
  if (flat_appearance.border_size()) g.draw_rounded_rectangle(pen(border_color, static_cast<float>(flat_appearance.border_size().value_or(1))), rectangle::add(bounds, -1, -1), environment::os_version().is_windows_platform() ? 0 : 4);
  if (focused) g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::offset(rectangle::add(bounds, drawing::size(flat_appearance.border_size().value_or(1) - 2, flat_appearance.border_size().value_or(1) - 2)), drawing::point(drawing::size(flat_appearance.border_size().value_or(1), flat_appearance.border_size().value_or(1)))), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void button_renderer::draw_flat_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_popup_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_popup_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
  else  draw_popup_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_popup_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::light(background_color, .05);
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-2, 2}), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void button_renderer::draw_popup_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(background_color, .05);
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-2, -2}), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}
