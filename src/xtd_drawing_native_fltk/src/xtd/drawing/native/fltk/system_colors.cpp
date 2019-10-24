#include <xtd/drawing/native/system_colors.hpp>
#include <cstdint>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

using namespace xtd::drawing::native;

namespace {
  uint32_t to_argb(Fl_Color color) {
    return static_cast<uint32_t>(color) >> 8;
  }
}

uint32_t system_colors::to_argb(intptr_t color){
  return static_cast<uint32_t>(color);
}

intptr_t system_colors::active_border() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}

intptr_t system_colors::active_caption() {
  return ::to_argb(FL_SELECTION_COLOR);
}

intptr_t system_colors::active_caption_text() {
  return ::to_argb(FL_WHITE);
}

intptr_t system_colors::app_workspace() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::button_face() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::button_highlight() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::button_shadow() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::control() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::control_dark() {
  return ::to_argb(fl_darker(FL_BACKGROUND_COLOR));
}

intptr_t system_colors::control_dark_dark() {
  return ::to_argb(fl_darker(fl_darker(FL_BACKGROUND_COLOR)));
}

intptr_t system_colors::control_light() {
  return ::to_argb(fl_lighter(FL_BACKGROUND_COLOR));
}

intptr_t system_colors::control_light_light() {
  return ::to_argb(fl_lighter(fl_lighter(FL_BACKGROUND_COLOR)));
}

intptr_t system_colors::control_text() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}

intptr_t system_colors::desktop() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::gradient_active_caption() {
  return ::to_argb(FL_SELECTION_COLOR);
}

intptr_t system_colors::gradient_inactive_caption() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::gray_text() {
  return ::to_argb(FL_INACTIVE_COLOR);
}

intptr_t system_colors::highlight() {
  return ::to_argb(FL_SELECTION_COLOR);
}

intptr_t system_colors::highlight_text() {
  return ::to_argb(FL_WHITE);
}

intptr_t system_colors::hot_track() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::inactive_border() {
  return ::to_argb(FL_INACTIVE_COLOR);
}

intptr_t system_colors::inactive_caption() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::inactive_caption_text() {
  return ::to_argb(FL_INACTIVE_COLOR);
}

intptr_t system_colors::info() {
  return ::to_argb(FL_YELLOW);
}

intptr_t system_colors::info_text() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}

intptr_t system_colors::menu() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::menu_bar() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::menu_highlight() {
  return ::to_argb(FL_SELECTION_COLOR);
}

intptr_t system_colors::menu_text() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}

intptr_t system_colors::scroll_bar() {
  return ::to_argb(FL_BACKGROUND_COLOR);
}

intptr_t system_colors::window() {
  return ::to_argb(FL_BACKGROUND2_COLOR);
}

intptr_t system_colors::window_frame() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}

intptr_t system_colors::window_text() {
  return ::to_argb(FL_FOREGROUND_COLOR);
}
