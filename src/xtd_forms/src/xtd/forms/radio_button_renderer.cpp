#include "../../../include/xtd/forms/radio_button_renderer.h"
#include "../../../include/xtd/forms/control_paint.h"
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
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(strings::substring(text_without_hotkey_prefix, hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void radio_button_renderer::draw_radio_button(const string& theme, graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "gnome") draw_radio_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (dark)") draw_radio_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (light)") draw_radio_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde") draw_radio_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (dark)") draw_radio_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (light)") draw_radio_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_radio_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (dark)") draw_radio_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (light)") draw_radio_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_radio_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (dark)") draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (light)") draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_radio_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (dark)") draw_radio_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (light)") draw_radio_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_radio_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (dark)") draw_radio_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (light)") draw_radio_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_gnome(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_gnome_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_gnome_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_kde(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_kde_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_kde_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_macos(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_macos_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_macos_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_symbolic(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_symbolic_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_radio_button_symbolic_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_radio_button_windows(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_windows_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_windows_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_xtd(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_radio_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_radio_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_xtd_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_xtd_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_flat_radio_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_flat_radio_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_flat_radio_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_flat_radio_button_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_flat_radio_button_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_popup_radio_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_popup_radio_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_popup_radio_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_popup_radio_button_dark(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_popup_radio_button_light(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}
