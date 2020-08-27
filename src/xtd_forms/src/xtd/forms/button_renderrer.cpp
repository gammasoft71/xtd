#include "../../../include/xtd/forms/button_renderrer.h"
#include <map>
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

    return string_format;
  }
}

void button_renderrer::draw_button(const string& theme, graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "kde") draw_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome") draw_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_kde(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_gnome(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_macos(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : system_colors::control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : system_colors::control_text();
  auto border_color = system_colors::window().get_lightness() < 0.5 ? color::darker(background_color, 0.95) : color::from_argb(200, 200, 200);
  auto button_color = system_colors::button_face();
  auto text_color = system_colors::window().get_lightness() < 0.5 ? color::lighter(foreground_color, 0.90) : foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = button_color = system_colors::accent();
    if (system_colors::window().get_lightness() >= 0.5) text_color = system_colors::accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = system_colors::window().get_lightness() < 0.5 ? color::from_argb(30, system_colors::button_face()) : color::darker(system_colors::button_face(), 0.96);
    text_color = system_colors::gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    border_color = button_color = color::darker(system_colors::accent(), 0.85);
    if (system_colors::window().get_lightness() >= 0.5) text_color = system_colors::accent_text();
  }
  
  auto button_rect = rectangle_f(bounds.x(), bounds.y() + 2, bounds.width(), bounds.height() - 4);
  g.fill_rounded_rectangle(solid_brush(background_color), button_rect, 3.);
  g.fill_rounded_rectangle(solid_brush(button_color), button_rect, 3.);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect, 3.);
  if (image != image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, solid_brush(text_color), button_rect, to_string_format(flags));
}

void button_renderrer::draw_button_symbolic(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : system_colors::control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : system_colors::control_text();
  auto active_border_color = system_colors::active_border();
  auto button_color = system_colors::window().get_lightness() < 0.5 ? color::lighter(background_color) : color::darker(background_color);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) active_border_color = color::lighter(system_colors::active_border());
  else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = button_color = system_colors::accent();
    text_color = color::white;
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = system_colors::gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(system_colors::accent());
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, solid_brush(text_color), rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), to_string_format(flags));
}

void button_renderrer::draw_button_windows(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : system_colors::button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : system_colors::control_text();
  auto active_border_color = system_colors::active_border();
  auto border_color = system_colors::window().get_lightness() < 0.5 ? background_color : system_colors::button_face();
  auto button_color = background_color;
  auto text_color = foreground_color;
  if (state == push_button_state::hot) {
    active_border_color = system_colors::accent();
    border_color = system_colors::window().get_lightness() < 0.5 ? system_colors::accent() : color::from_argb(232, 243, 251);
    if (system_colors::window().get_lightness() >= 0.5 && !back_color.has_value()) button_color = color::from_argb(232, 243, 251);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = system_colors::window().get_lightness() < 0.5 ? system_colors::accent() : system_colors::highlight();
    border_color = system_colors::accent();
    if (system_colors::window().get_lightness() < 0.5 || (system_colors::window().get_lightness() >= 0.5 && !back_color.has_value())) button_color = system_colors::accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = system_colors::active_border();
    if (system_colors::window().get_lightness() < 0.5  && !back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    else if (system_colors::window().get_lightness() >= 0.5 && !back_color.has_value()) button_color = color::from_argb(204, 204, 204);
    text_color = system_colors::gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = system_colors::highlight();
    border_color = system_colors::highlight();
  }
  
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, solid_brush(text_color), rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), to_string_format(flags));
}

void button_renderrer::draw_button_xtd(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}
