#include "../../../include/xtd/forms/radio_button_renderer"
#include "../../../include/xtd/forms/control_paint"
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/pen>
#include <xtd/drawing/solid_brush>
#include <xtd/environment>
#include <map>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

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
    auto hotkey_prefix_locations = vector<size_t> {};
    auto text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void radio_button_renderer::draw_radio_button(const ustring& theme, graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme.to_lower() == "gnome") draw_radio_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "gnome (dark)") draw_radio_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "gnome (light)") draw_radio_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde") draw_radio_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde (dark)") draw_radio_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "kde (light)") draw_radio_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos") draw_radio_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos (dark)") draw_radio_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "macos (light)") draw_radio_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic") draw_radio_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic (dark)") draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "symbolic (light)") draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows") draw_radio_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows (dark)") draw_radio_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "windows (light)") draw_radio_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd") draw_radio_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd (dark)") draw_radio_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme.to_lower() == "xtd (light)") draw_radio_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_gnome(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_gnome_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().accent_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed)
    button_color = control_paint::light(button_color, 0.1);
  else if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 8, 17, 17};
  g.fill_ellipse(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.15), button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 21, bounds.y(), bounds.width() - 21, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-9, -9}), {4, 4}));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_gnome_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::light(background_color, 0.25);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().accent_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed)
    button_color = control_paint::dark(button_color, 0.1);
  else if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 8, 17, 17};
  g.fill_ellipse(drawing_2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.5), button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 21, bounds.y(), bounds.width() - 21, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-9, -9}), {4, 4}));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_kde(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_kde_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_kde_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_macos(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_macos_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control(), 0.05);
  auto button_color = application::style_sheet().system_colors().button_face();
  auto text_color = control_paint::light(foreground_color, 0.1);
  auto mark_color = control_paint::dark(application::style_sheet().system_colors().accent_text(), 0.15);
  
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    button_color = control_paint::dark(application::style_sheet().system_colors().accent(), 0.15);
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = application::style_sheet().system_colors().gray_text();
    button_color = control_paint::dark(application::style_sheet().system_colors().button_face(), 0.7);
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_normal || state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled) {
    g.fill_ellipse(drawing_2d::linear_gradient_brush(point {button_rectangle.x(), button_rectangle.top()}, point {button_rectangle.x(), button_rectangle.bottom()}, control_paint::dark(button_color, .5), button_color), button_rectangle);
    g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  } else
    g.fill_ellipse(solid_brush(button_color), button_rectangle);
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-10, -10}), {5, 5}));
  }
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_macos_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control(), 0.05);
  auto button_color = application::style_sheet().system_colors().button_face();
  auto text_color = control_paint::light(foreground_color, 0.1);
  auto mark_color = control_paint::light(application::style_sheet().system_colors().accent_text(), 0.15);
  
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = application::style_sheet().system_colors().gray_text();
    button_color = control_paint::light(application::style_sheet().system_colors().button_face(), 0.7);
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_normal || state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled) {
    g.fill_ellipse(drawing_2d::linear_gradient_brush(point {button_rectangle.x(), button_rectangle.top()}, point {button_rectangle.x(), button_rectangle.bottom()}, control_paint::dark(button_color, .5), button_color), button_rectangle);
    g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  } else
    g.fill_ellipse(solid_brush(button_color), button_rectangle);
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-10, -10}), {5, 5}));
  }
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_symbolic(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_symbolic_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().accent_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::radio_button_state::checked_hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = application::style_sheet().system_colors().accent();
  } else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 8, 16, 16};
  g.fill_ellipse(solid_brush(button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-10, -10}), {5, 5}));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_symbolic_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().accent_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot) {
    border_color = control_paint::dark(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::radio_button_state::checked_hot) {
    border_color = control_paint::dark(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = application::style_sheet().system_colors().accent();
  } else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    border_color = color::from_argb(85, 85, 55);
    mark_color = text_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 16, 16};
  g.fill_ellipse(solid_brush(button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle::offset(rectangle::add(button_rectangle, {-10, -10}), {5, 5}));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_windows(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_windows_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().accent_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_hot)
    border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = button_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = mark_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 7, 14, 14};
  g.fill_ellipse(solid_brush(button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 19, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle(button_rectangle.x() + 3, button_rectangle.y() + 3, button_rectangle.width() - 6, button_rectangle.height() - 6));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
}

void radio_button_renderer::draw_radio_button_windows_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_text();
  auto button_color = control_paint::light(background_color, .2);
  auto text_color = foreground_color;
  auto mark_color = application::style_sheet().system_colors().control_text();
  
  if (state == xtd::forms::visual_styles::radio_button_state::unchecked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_hot)
    border_color = mark_color = application::style_sheet().system_colors().highlight();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_pressed)
    border_color = mark_color = application::style_sheet().system_colors().highlight();
  else if (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled) {
    if (!back_color.has_value()) border_color = application::style_sheet().system_colors().gray_text();
    text_color = mark_color = application::style_sheet().system_colors().gray_text();
  }
  
  auto button_rectangle = rectangle {bounds.x() + 1, bounds.y() + bounds.height() / 2 - 6, 12, 12};
  g.fill_ellipse(solid_brush(button_color), button_rectangle);
  g.draw_ellipse(pen(border_color, 1), rectangle::add(button_rectangle, {-1, -1}));
  auto string_rectangle = rectangle {bounds.x() + 19, bounds.y(), bounds.width() - 14, bounds.height()};
  if (state == xtd::forms::visual_styles::radio_button_state::checked_normal || state == xtd::forms::visual_styles::radio_button_state::checked_hot || state == xtd::forms::visual_styles::radio_button_state::checked_pressed || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)
    g.fill_ellipse(solid_brush(mark_color), rectangle(button_rectangle.x() + 3, button_rectangle.y() + 3, button_rectangle.width() - 6, button_rectangle.height() - 6));
  if (image != image::empty && (state == xtd::forms::visual_styles::radio_button_state::unchecked_disabled || state == xtd::forms::visual_styles::radio_button_state::checked_disabled)) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, string_rectangle, flags);
  
}

void radio_button_renderer::draw_radio_button_xtd(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_radio_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_radio_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_xtd_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_radio_button_xtd_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_radio_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_flat_radio_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_flat_radio_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_flat_radio_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_flat_radio_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_flat_radio_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_popup_radio_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_popup_radio_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_popup_radio_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void radio_button_renderer::draw_popup_radio_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}

void radio_button_renderer::draw_popup_radio_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
}
