#include "../../../include/xtd/forms/check_box_renderer.h"
#include <map>
#include <xtd/environment.h>
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

namespace {
  string_format to_string_format(text_format_flags flags) {
    string_format string_format;
    string_format.line_alignment(string_alignment::center);
    string_format.alignment(string_alignment::center);
    
    if ((flags & text_format_flags::horizontal_center) == text_format_flags::horizontal_center) string_format.alignment(string_alignment::center);
    else if ((flags & text_format_flags::rigth) == text_format_flags::rigth) string_format.alignment(string_alignment::far);
    else string_format.alignment(string_alignment::near);
    
    if ((flags & text_format_flags::vertical_center) == text_format_flags::vertical_center) string_format.line_alignment(string_alignment::center);
    else if ((flags & text_format_flags::bottom) == text_format_flags::bottom) string_format.line_alignment(string_alignment::far);
    else string_format.line_alignment(string_alignment::near);
    
    if ((flags & text_format_flags::no_prefix) == text_format_flags::no_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::none);
    else if ((flags & text_format_flags::hide_prefix) == text_format_flags::hide_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::hide);
    else string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::show);
    
    return string_format;
  }

  std::string get_hotkey_prefix_locations(const std::string& str, std::vector<size_t>& locations) {
    size_t offset = 0;
    for (auto index = 0; index < str.size(); index++) {
      if (str[index] == '&' && str[index+1] != '&') {
        locations.push_back(index + offset);
      } else if (str[index] == '&' && str[index+1] == '&') {
        offset-=2;
        ++index;
      }
    }
    auto new_str = xtd::strings::replace(str, "&&", "&");
    for (int index = 0; index < locations.size(); ++index)
      new_str = xtd::strings::remove(new_str, locations[index], 1);
    return new_str;
  }

  void draw_string(graphics g, const string& text, const font& font, const color& text_color, const rectangle_f& button_rect, text_format_flags flags) {
    vector<size_t> hotkey_prefix_locations;
    string text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(strings::substring(text_without_hotkey_prefix, hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, to_string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, to_string_format(flags));
  }
}

void check_box_renderer::draw_check_box(const string& theme, graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "gnome") draw_check_box_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (dark)") draw_check_box_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (light)") draw_check_box_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde") draw_check_box_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (dark)") draw_check_box_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (light)") draw_check_box_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_check_box_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (dark)") draw_check_box_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (light)") draw_check_box_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_check_box_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (dark)") draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (light)") draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_check_box_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (dark)") draw_check_box_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (light)") draw_check_box_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_check_box_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (dark)") draw_check_box_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (light)") draw_check_box_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_check_box_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_gnome(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_gnome_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_gnome_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_kde(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_kde_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_kde_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_macos(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_macos_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::darker(back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control(), 0.95);
  auto button_color = xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = color::lighter(foreground_color, 0.90);
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed) {
    button_color = color::darker(xtd::forms::theme_colors::current_theme().accent(), 0.85);
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
    button_color = color::darker(xtd::forms::theme_colors::current_theme().button_face(), 0.3);
  }
  
  rectangle button_rectangle = {bounds.x() + 1, (bounds.height() - bounds.y()) / 2 - 7, 15, 15};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rectangle, 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_macos_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = back_color.has_value() ? color::from_argb(128, xtd::forms::theme_colors::current_theme().control()) : xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_pressed) {
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
    button_color = back_color.has_value() ? color::from_argb(210, 255, 255, 255) : color::darker(button_color, 0.96);
  }
  
  rectangle button_rectangle = {bounds.x() + 1, (bounds.height() - bounds.y()) / 2 - 7, 15, 15};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rectangle, 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) g.draw_image_disabled(image, image_bounds.location());
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);

}

void check_box_renderer::draw_check_box_symbolic(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_symbolic_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = color::lighter(background_color, .95);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();

  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = color::lighter(background_color, .9);
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled) {
    border_color = color::from_argb(85, 85, 55);
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_normal) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, (bounds.height() - bounds.y()) / 2 - 7, 15, 15};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rectangle, 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_symbolic_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = color::darker(background_color, .95);
  auto text_color = foreground_color;
  auto mark_color = xtd::forms::theme_colors::current_theme().accent_text();
  
  if (state == xtd::forms::visual_styles::check_box_state::unchecked_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = color::darker(background_color, .9);
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_normal) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_hot) {
    border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_pressed) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = xtd::forms::theme_colors::current_theme().gray_text();
  }
  
  rectangle button_rectangle = {bounds.x() + 1, (bounds.height() - bounds.y()) / 2 - 7, 15, 15};
  g.fill_rounded_rectangle(solid_brush(button_color), button_rectangle, 3);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rectangle, 3);
  rectangle string_rectangle = {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::check_box_state::checked_normal || state == xtd::forms::visual_styles::check_box_state::checked_hot || state == xtd::forms::visual_styles::check_box_state::checked_pressed || state == xtd::forms::visual_styles::check_box_state::checked_disabled) {
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4);
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + button_rectangle.width() / 2, button_rectangle.y() + button_rectangle.height() - 4, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + 4);
  } else if (state == xtd::forms::visual_styles::check_box_state::mixed_normal || state == xtd::forms::visual_styles::check_box_state::mixed_hot || state == xtd::forms::visual_styles::check_box_state::mixed_pressed || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)
    g.draw_line(pen(mark_color, 2), button_rectangle.x() + 4, button_rectangle.y() + button_rectangle.height() / 2, button_rectangle.x() + button_rectangle.width() - 4, button_rectangle.y() + button_rectangle.height() / 2);
  if (image != image::empty && (state == xtd::forms::visual_styles::check_box_state::unchecked_disabled || state == xtd::forms::visual_styles::check_box_state::checked_disabled || state == xtd::forms::visual_styles::check_box_state::mixed_disabled)) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void check_box_renderer::draw_check_box_windows(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_windows_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_windows_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_xtd(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_check_box_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_check_box_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_xtd_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_check_box_xtd_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_check_box_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_flat_check_box(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_flat_check_box_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_flat_check_box_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_flat_check_box_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_flat_check_box_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_popup_check_box(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_popup_check_box_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_popup_check_box_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void check_box_renderer::draw_popup_check_box_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void check_box_renderer::draw_popup_check_box_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, check_box_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}
