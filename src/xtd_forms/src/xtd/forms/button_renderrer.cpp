#include "../../../include/xtd/forms/button_renderrer.h"
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

namespace {
  string_format to_string_format(text_format_flags flags) {
    xtd::drawing::string_format string_format;
    string_format.line_alignment(xtd::drawing::string_alignment::center);
    string_format.alignment(xtd::drawing::string_alignment::center);
    
    /*
     switch (text_align_) {
     case content_alignment::top_left: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::near); break;
     case content_alignment::top_center: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::center); break;
     case content_alignment::top_right: string_format.line_alignment(xtd::drawing::string_alignment::near); string_format.alignment(xtd::drawing::string_alignment::far); break;
     case content_alignment::middle_left: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::near); break;
     case content_alignment::middle_center: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::center); break;
     case content_alignment::middle_right: string_format.line_alignment(xtd::drawing::string_alignment::center); string_format.alignment(xtd::drawing::string_alignment::far); break;
     case content_alignment::bottom_left: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::near); break;
     case content_alignment::bottom_center: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::center); break;
     case content_alignment::bottom_right: string_format.line_alignment(xtd::drawing::string_alignment::far); string_format.alignment(xtd::drawing::string_alignment::far); break;
     default: break;
     }
     */
    return string_format;
  }
}

void button_renderrer::draw_button(const string& theme, graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const color& back_color, const color& fore_color) {
  if (theme == "kde") draw_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome") draw_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_kde(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const color& back_color, const color& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_gnome(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const color& back_color, const color& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderrer::draw_button_macos(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const color& back_color, const color& fore_color) {
  auto active_border_color = system_colors::window().get_lightness() < 0.5 ? color::average(back_color, color::black, .95) : color::from_argb(200, 200, 200);
  auto button_color = system_colors::window().get_lightness() < 0.5 ? color::from_argb(65, color::white) : color::white;
  auto text_color = fore_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    active_border_color = button_color = xtd::drawing::system_colors::menu_highlight();
    if (system_colors::window().get_lightness() >= 0.5) text_color = color::white;
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) active_border_color = xtd::drawing::color::from_argb(85, 85, 55);
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::drawing::system_colors::menu_highlight());
  
  g.fill_rounded_rectangle(xtd::drawing::solid_brush(button_color), bounds.x(), bounds.y() + 2, bounds.width(), bounds.height() - 4, 3);
  g.draw_rounded_rectangle(xtd::drawing::pen(active_border_color, 1), bounds.x(), bounds.y() + 2, bounds.width(), bounds.height() - 4, 3);
  if (image != xtd::drawing::image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, xtd::drawing::solid_brush(text_color), xtd::drawing::rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), to_string_format(flags));
}

void button_renderrer::draw_button_symbolic(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const color& back_color, const color& fore_color) {
  auto active_border_color = system_colors::active_border();
  auto button_color = system_colors::window().get_lightness() < 0.5 ? color::lighter(back_color) : color::darker(back_color);
  auto text_color = fore_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) active_border_color = color::lighter(system_colors::active_border());
  else if (state == xtd::forms::visual_styles::push_button_state::pressed) active_border_color = button_color = xtd::drawing::system_colors::menu_highlight();
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) active_border_color = xtd::drawing::color::from_argb(85, 85, 55);
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = color::darker(xtd::drawing::system_colors::menu_highlight());
  
  g.fill_rounded_rectangle(xtd::drawing::solid_brush(button_color), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  g.draw_rounded_rectangle(xtd::drawing::pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != xtd::drawing::image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, xtd::drawing::solid_brush(text_color), xtd::drawing::rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), to_string_format(flags));
}

void button_renderrer::draw_button_windows(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {
  auto active_border_color = xtd::drawing::color::from_argb(180, 180, 180); // xtd::drawing::system_colors::active_border();
  auto border_color = xtd::drawing::color::from_argb(229, 229, 229); // xtd::drawing::system_colors::control(); ??
  auto button_color = back_color;
  auto text_color = fore_color;
  if (state == xtd::forms::visual_styles::push_button_state::normal) {
    if (system_colors::window().get_lightness() < 0.5) {
      active_border_color = xtd::drawing::color::from_argb(85, 85, 55);
      border_color = back_color;
      button_color = back_color;
    } else {
      active_border_color = xtd::drawing::color::from_argb(180, 180, 180); // xtd::drawing::system_colors::active_border();
      border_color = xtd::drawing::color::from_argb(232, 243, 251);
      button_color = back_color;
    }
  } else if (state == xtd::forms::visual_styles::push_button_state::hot) {
    if (system_colors::window().get_lightness() < 0.5) {
      active_border_color = xtd::drawing::color::from_argb(0, 160, 250);
      border_color = back_color;
      button_color = back_color;
    } else {
      active_border_color = xtd::drawing::color::from_argb(0, 120, 215); // active_border_color = xtd::drawing::system_colors::highlight();
      border_color = xtd::drawing::color::from_argb(232, 243, 251);
      button_color = xtd::drawing::color::from_argb(232, 243, 251);
    }
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed) {
    if (system_colors::window().get_lightness() < 0.5) {
      active_border_color = xtd::drawing::color::from_argb(0, 160, 250);
      border_color = xtd::drawing::color::from_argb(0, 160, 250);
      button_color = xtd::drawing::color::from_argb(0, 160, 250);
    } else {
      active_border_color = xtd::drawing::color::from_argb(0, 120, 215); // active_border_color = xtd::drawing::system_colors::highlight();
      border_color = xtd::drawing::color::from_argb(210, 232, 248);
      button_color = xtd::drawing::color::from_argb(210, 232, 248);
    }
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = xtd::drawing::color::from_argb(85, 85, 55);
    border_color = back_color;
    text_color = xtd::drawing::color::from_argb(120, 120, 120);
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = xtd::drawing::color::from_argb(0, 120, 215); // active_border_color = xtd::drawing::system_colors::highlight();
    if (system_colors::window().get_lightness() < 0.5) {
      border_color = back_color;
      button_color = back_color;
    } else {
      border_color = xtd::drawing::color::from_argb(0, 120, 215); // border_color = xtd::drawing::system_colors::highlight();
      button_color = back_color;
    }
  }
  
  g.draw_rectangle(xtd::drawing::pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 1, bounds.width() - 2, bounds.height() - 2);
  g.draw_rectangle(xtd::drawing::pen(border_color, 1), bounds.x() + 2, bounds.y() + 2, bounds.width() - 4, bounds.height() - 4);
  g.fill_rectangle(xtd::drawing::solid_brush(button_color), bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
  if (image != xtd::drawing::image::empty) g.draw_image(image, image_bounds.location());
  g.draw_string(text, font, xtd::drawing::solid_brush(text_color), xtd::drawing::rectangle_f(bounds.x(), bounds.y(), bounds.width(), bounds.height()), to_string_format(flags));
}

void button_renderrer::draw_button_xtd(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {
  draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}
