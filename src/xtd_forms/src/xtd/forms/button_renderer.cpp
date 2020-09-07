#include "../../../include/xtd/forms/button_renderer.h"
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
    
    if ((flags & text_format_flags::left) == text_format_flags::top) string_format.alignment(string_alignment::near);
    if ((flags & text_format_flags::horizontal_center) == text_format_flags::horizontal_center) string_format.alignment(string_alignment::center);
    if ((flags & text_format_flags::rigth) == text_format_flags::rigth) string_format.alignment(string_alignment::far);
   
    if ((flags & text_format_flags::top) == text_format_flags::top) string_format.line_alignment(string_alignment::near);
    if ((flags & text_format_flags::vertical_center) == text_format_flags::vertical_center) string_format.line_alignment(string_alignment::center);
    if ((flags & text_format_flags::bottom) == text_format_flags::bottom) string_format.line_alignment(string_alignment::far);
    
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

void button_renderer::draw_button(const string& theme, graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "gnome") draw_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (dark)") draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (light)") draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde") draw_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (dark)") draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (light)") draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (dark)") draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (light)") draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (dark)") draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (light)") draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (dark)") draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (light)") draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (dark)") draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (light)") draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
    auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
    auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
    auto active_border_color = xtd::forms::theme_colors::current_theme().control_dark();
    auto button_color = background_color;
    auto text_color = foreground_color;

    if (state == xtd::forms::visual_styles::push_button_state::pressed) {
      button_color = xtd::forms::theme_colors::current_theme().control_dark();
    } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
      text_color = xtd::forms::theme_colors::current_theme().gray_text();
    } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::forms::theme_colors::current_theme().accent());

    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height() , 4);
    g.draw_rounded_rectangle(pen(active_border_color, 1), bounds.x(), bounds.y(), bounds.width()-1, bounds.height()-1, 4);
    if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
    else if (image != image::empty) g.draw_image(image, image_bounds.location());
    draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_gnome_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
    auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
    auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
    auto active_border_color = xtd::forms::theme_colors::current_theme().control_dark();
    auto button_color = background_color;
    auto text_color = foreground_color;

    if (state == xtd::forms::visual_styles::push_button_state::pressed) {
      button_color = xtd::forms::theme_colors::current_theme().control_dark();
    } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
      text_color = xtd::forms::theme_colors::current_theme().gray_text();
    } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::forms::theme_colors::current_theme().accent());

    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height() , 4);
    g.draw_rounded_rectangle(pen(active_border_color, 1), bounds.x(), bounds.y(), bounds.width()-1, bounds.height()-1, 4);
    if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
    else if (image != image::empty) g.draw_image(image, image_bounds.location());
    draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_kde(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_kde_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_kde_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_macos(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_macos_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::darker(background_color, 0.95);
  auto button_color = xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = color::lighter(foreground_color, 0.90);
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed)
    button_color = bounds.height() <= 25 ? border_color = xtd::forms::theme_colors::current_theme().accent() : color::from_argb(85, xtd::forms::theme_colors::current_theme().button_face());
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = color::from_argb(30, xtd::forms::theme_colors::current_theme().button_face());
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    if (bounds.height() <= 25) button_color = color::darker(xtd::forms::theme_colors::current_theme().accent(), 0.85);
  
  auto button_rect = rectangle_f(bounds.x(), bounds.y() + 2, bounds.width(), bounds.height() - 4);
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect, 3.);
  g.fill_rounded_rectangle(solid_brush(button_color), button_rect, 3.);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect, 3.);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, button_rect, flags);
}

void button_renderer::draw_button_macos_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = back_color.has_value() ? color::from_argb(150, 255, 255, 255) : xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    if (bounds.height() <= 25) {
      button_color = xtd::forms::theme_colors::current_theme().accent();
      text_color = xtd::forms::theme_colors::current_theme().accent_text();
    } else button_color = color::from_argb(240, 240, 240);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = back_color.has_value() ? color::from_argb(210, 255, 255, 255) : color::darker(button_color, 0.96);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    if (bounds.height() <= 25) button_color = color::lighter(xtd::forms::theme_colors::current_theme().accent(), 0.85);
  }
  
  auto button_rect = rectangle_f(bounds.x(), bounds.y() + 2, bounds.width(), bounds.height() - 4);
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect, 3.);
  g.fill_rounded_rectangle(solid_brush(button_color), button_rect, 3.);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect, 3.);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, button_rect, flags);
}

void button_renderer::draw_button_symbolic(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_symbolic_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = color::lighter(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = color::lighter(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::forms::theme_colors::current_theme().accent());
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_symbolic_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = color::darker(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().active_border());
    button_color = color::darker(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::forms::theme_colors::current_theme().accent());
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_windows(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_windows_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto border_color = background_color;
  auto button_color = background_color;
  auto text_color = foreground_color;
  if (state == push_button_state::hot) {
    active_border_color = xtd::forms::theme_colors::current_theme().accent();
    border_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = xtd::forms::theme_colors::current_theme().accent();
    border_color = xtd::forms::theme_colors::current_theme().accent();
    button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = xtd::forms::theme_colors::current_theme().active_border();
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = xtd::forms::theme_colors::current_theme().highlight();
    border_color = xtd::forms::theme_colors::current_theme().highlight();
  }
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_windows_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto border_color = xtd::forms::theme_colors::current_theme().button_face();
  auto button_color = background_color;
  auto text_color = foreground_color;
  if (state == push_button_state::hot) {
    active_border_color = xtd::forms::theme_colors::current_theme().accent();
    border_color = color::from_argb(232, 243, 251);
    if (!back_color.has_value()) button_color = color::from_argb(232, 243, 251);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = xtd::forms::theme_colors::current_theme().highlight();
    border_color = xtd::forms::theme_colors::current_theme().accent();
    if (!back_color.has_value()) button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = xtd::forms::theme_colors::current_theme().active_border();
    if (!back_color.has_value()) button_color = color::from_argb(204, 204, 204);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = xtd::forms::theme_colors::current_theme().highlight();
    border_color = xtd::forms::theme_colors::current_theme().highlight();
  }
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_button_xtd(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_flat_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_flat_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_flat_button_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::lighter(background_color, .95);
  auto button_color = color::lighter(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::lighter(background_color, .8);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::lighter(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_flat_button_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::darker(background_color, .95);
  auto button_color = color::darker(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::darker(background_color, .8);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::darker(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_popup_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_popup_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_popup_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_popup_button_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::lighter(background_color, .95);
  auto button_color = color::lighter(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::lighter(background_color, .8);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::lighter(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = color::lighter(xtd::forms::theme_colors::current_theme().control_text(), .8);
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}

void button_renderer::draw_popup_button_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::darker(background_color, .95);
  auto button_color = color::darker(background_color, .95);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::darker(background_color, .8);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
    button_color = color::darker(background_color, .9);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = color::darker(xtd::forms::theme_colors::current_theme().control_text(), .8);
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) g.draw_image_disabled(image, image_bounds.location(), 1.0);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), flags);
}
