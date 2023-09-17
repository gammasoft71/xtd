#include "../../../include/xtd/forms/switch_button_renderer.h"
#include "../../../include/xtd/forms/control_paint.h"
#include <map>
#include <xtd/environment.h>
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>

#include <xtd/drawing/drawing_2d/linear_gradient_brush.h>

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
    vector<size_t> hotkey_prefix_locations;
    ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void switch_button_renderer::draw_button(const ustring& theme, graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
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

void switch_button_renderer::draw_button_gnome(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_gnome_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::dark(background_color, 0.1);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.02);
  else if (state == visual_styles::push_button_state::pressed)
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

void switch_button_renderer::draw_button_gnome_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = control_paint::light(background_color, 0.05);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.5);
  else if (state == visual_styles::push_button_state::pressed)
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

void switch_button_renderer::draw_button_kde(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_kde_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32 offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
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

void switch_button_renderer::draw_button_kde_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32 offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
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

void switch_button_renderer::draw_button_macos(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_macos_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control(), 0.05);
  auto button_color = application::style_sheet().system_colors().button_face();
  auto text_color = control_paint::light(foreground_color, 0.1);
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed)
    button_color = bounds.height() <= 25 ? application::style_sheet().system_colors().accent() : color::from_argb(85, application::style_sheet().system_colors().button_face());
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = color::from_argb(30, application::style_sheet().system_colors().button_face());
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    if (bounds.height() <= 25) button_color = control_paint::dark(application::style_sheet().system_colors().accent(), 0.15);
    
  auto button_rect = bounds;
  if (bounds.height() > 25) {
    button_rect.offset({2, 0});
    button_rect.add({-4, -1});
  }
  
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 4);
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, control_paint::light(button_color, .03), button_color), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 5, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void switch_button_renderer::draw_button_macos_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = back_color.has_value() ? color::from_argb(128, application::style_sheet().system_colors().control()) : application::style_sheet().system_colors().button_face();
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    if (bounds.height() <= 25) {
      button_color = application::style_sheet().system_colors().accent();
      text_color = application::style_sheet().system_colors().accent_text();
    } else button_color = color::from_argb(240, 240, 240);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
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
    button_rect.offset({2, 0});
    button_rect.add({-4, -1});
  }
  
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 4);
  g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, button_color, control_paint::dark(button_color, .03)), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 5, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void switch_button_renderer::draw_button_symbolic(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_symbolic_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
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

void switch_button_renderer::draw_button_symbolic_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto border_color = application::style_sheet().system_colors().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(application::style_sheet().system_colors().active_border(), 2.0 / 3);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
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

void switch_button_renderer::draw_button_windows(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_windows_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().active_border();
  auto border_color = background_color;
  auto button_color = background_color;
  auto text_color = foreground_color;
  
  if (state == push_button_state::hot)
    active_border_color = border_color = application::style_sheet().system_colors().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed)
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

void switch_button_renderer::draw_button_windows_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
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
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
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

void switch_button_renderer::draw_button_xtd(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_xtd_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_button_xtd_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_flat_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_flat_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_flat_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::light(background_color, .05);
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height());
  g.draw_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-1, -1}));
  g.draw_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}));
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void switch_button_renderer::draw_flat_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(background_color, .05);
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height());
  g.draw_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-1, -1}));
  g.draw_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}));
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void switch_button_renderer::draw_popup_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (application::style_sheet().system_colors().window().get_lightness() < 0.5) draw_popup_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_popup_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void switch_button_renderer::draw_popup_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::light(background_color, .05);
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::light(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height());
  g.draw_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-1, -1}));
  g.draw_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}));
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void switch_button_renderer::draw_popup_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : application::style_sheet().system_colors().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : application::style_sheet().system_colors().control_text();
  auto active_border_color = application::style_sheet().system_colors().control_text();
  auto border_color = control_paint::dark(background_color, .05);
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    border_color = active_border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = application::style_sheet().system_colors().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::dark(application::style_sheet().system_colors().control_text(), .2);
  
  g.fill_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height());
  g.draw_rectangle(pen(active_border_color, 1), rectangle::add(bounds, {-1, -1}));
  g.draw_rectangle(pen(border_color, 1), rectangle::offset(rectangle::add(bounds, {-3, -3}), {1, 1}));
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}
