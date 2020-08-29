#include "../../../include/xtd/forms/theme_color.h"
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  string system_theme_name() {
    auto desktop_environment = environment::os_version().desktop_environment();
    if (desktop_environment == "") return "symbolic";
    return desktop_environment;
  }

  color system_kown_themed_color_to_color(known_themed_color color) {
    switch (color) {
      case known_themed_color::accent: return system_colors::accent();
      case known_themed_color::accent_text: return system_colors::accent_text();
      case known_themed_color::active_border: return system_colors::active_border();
      case known_themed_color::active_caption: return system_colors::active_caption();
      case known_themed_color::active_caption_text: return system_colors::active_caption_text();
      case known_themed_color::app_workspace: return system_colors::app_workspace();
      case known_themed_color::button_face: return system_colors::button_face();
      case known_themed_color::button_highlight: return system_colors::button_highlight();
      case known_themed_color::button_shadow: return system_colors::button_shadow();
      case known_themed_color::control: return system_colors::control();
      case known_themed_color::control_dark: return system_colors::control_dark();
      case known_themed_color::control_dark_dark: return system_colors::control_dark_dark();
      case known_themed_color::control_light: return system_colors::control_light();
      case known_themed_color::control_light_light: return system_colors::control_light_light();
      case known_themed_color::control_text: return system_colors::control_text();
      case known_themed_color::desktop: return system_colors::desktop();
      case known_themed_color::gradient_active_caption: return system_colors::gradient_active_caption();
      case known_themed_color::gradient_inactive_caption: return system_colors::gradient_inactive_caption();
      case known_themed_color::gray_text: return system_colors::gray_text();
      case known_themed_color::highlight: return system_colors::highlight();
      case known_themed_color::highlight_text: return system_colors::highlight_text();
      case known_themed_color::hot_track: return system_colors::hot_track();
      case known_themed_color::inactive_border: return system_colors::inactive_border();
      case known_themed_color::inactive_caption: return system_colors::inactive_caption();
      case known_themed_color::inactive_caption_text: return system_colors::inactive_caption_text();
      case known_themed_color::info: return system_colors::info();
      case known_themed_color::info_text: return system_colors::info_text();
      case known_themed_color::menu: return system_colors::menu();
      case known_themed_color::menu_text: return system_colors::menu_text();
      case known_themed_color::menu_bar: return system_colors::menu_bar();
      case known_themed_color::menu_highlight: return system_colors::menu_highlight();
      case known_themed_color::scroll_bar: return system_colors::scroll_bar();
      case known_themed_color::text_box: return system_colors::text_box();
      case known_themed_color::text_box_text: return system_colors::text_box_text();
      case known_themed_color::window: return system_colors::window();
      case known_themed_color::window_frame: return system_colors::window_frame();
      case known_themed_color::window_text: return system_colors::window_text();
      default: throw std::invalid_argument("unknown know_color");
    }
  }
}

const theme_color theme_color::empty {};
theme_color theme_color::current_theme_color_;

theme_color theme_color::current_theme_color() {
  if (current_theme_color_ == theme_color::empty) current_theme_color_ = theme_color(system_theme_name(), theme_style::system_auto, {system_kown_themed_color_to_color}, true);
  return current_theme_color_;
}

void theme_color::current_theme_color(const theme_color& theme_color) {
  current_theme_color_ = theme_color;
}

theme_color theme_color::default_theme_color() {
  return theme_color(system_theme_name(), theme_style::system_auto, {system_kown_themed_color_to_color}, true);
}

xtd::drawing::color theme_color::from_known_themed_color(xtd::forms::known_themed_color known_themed_color) {
  return current_theme_color().kown_themed_color_to_color_(known_themed_color);
}

theme_color::theme_color_collection& theme_color::theme_colors() {
  static theme_color_collection theme_colors;
  if (theme_colors.size() == 0) {
    theme_colors.push_back(default_theme_color());
  }
  return theme_colors;
}
