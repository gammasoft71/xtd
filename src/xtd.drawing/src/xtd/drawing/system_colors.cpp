#include "../../../include/xtd/drawing/system_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color xtd::drawing::system_colors::accent() {
  return color::from_known_color(xtd::drawing::known_color::accent);
}

color xtd::drawing::system_colors::accent_text() {
  return color::from_known_color(xtd::drawing::known_color::accent_text);
}

color xtd::drawing::system_colors::active_border() {
  return color::from_known_color(xtd::drawing::known_color::active_border);
}

color xtd::drawing::system_colors::active_caption() {
  return color::from_known_color(xtd::drawing::known_color::active_caption);
}

color xtd::drawing::system_colors::active_caption_text() {
  return color::from_known_color(xtd::drawing::known_color::active_caption_text);
}

color xtd::drawing::system_colors::active_text() {
  return color::from_known_color(xtd::drawing::known_color::active_text);
}

color xtd::drawing::system_colors::app_workspace() {
  return color::from_known_color(xtd::drawing::known_color::app_workspace);
}

color xtd::drawing::system_colors::button_face() {
  return color::from_known_color(xtd::drawing::known_color::button_face);
}

color xtd::drawing::system_colors::button_highlight() {
  return color::from_known_color(xtd::drawing::known_color::button_highlight);
}

color xtd::drawing::system_colors::button_shadow() {
  return color::from_known_color(xtd::drawing::known_color::button_shadow);
}

color xtd::drawing::system_colors::control() {
  return color::from_known_color(xtd::drawing::known_color::control);
}

color xtd::drawing::system_colors::control_dark() {
  return color::from_known_color(xtd::drawing::known_color::control_dark);
}

color xtd::drawing::system_colors::control_dark_dark() {
  return color::from_known_color(xtd::drawing::known_color::control_dark_dark);
}

color xtd::drawing::system_colors::control_light() {
  return color::from_known_color(xtd::drawing::known_color::control_light);
}

color xtd::drawing::system_colors::control_light_light() {
  return color::from_known_color(xtd::drawing::known_color::control_light_light);
}

color xtd::drawing::system_colors::control_text() {
  return color::from_known_color(xtd::drawing::known_color::control_text);
}

color xtd::drawing::system_colors::desktop() {
  return color::from_known_color(xtd::drawing::known_color::desktop);
}

color xtd::drawing::system_colors::gradient_active_caption() {
  return color::from_known_color(xtd::drawing::known_color::gradient_active_caption);
}

color xtd::drawing::system_colors::gradient_inactive_caption() {
  return color::from_known_color(xtd::drawing::known_color::gradient_inactive_caption);
}

color xtd::drawing::system_colors::gray_text() {
  return color::from_known_color(xtd::drawing::known_color::gray_text);
}

color xtd::drawing::system_colors::highlight() {
  return color::from_known_color(xtd::drawing::known_color::highlight);
}

color xtd::drawing::system_colors::highlight_text() {
  return color::from_known_color(xtd::drawing::known_color::highlight_text);
}

color xtd::drawing::system_colors::hot_track() {
  return color::from_known_color(xtd::drawing::known_color::hot_track);
}

color xtd::drawing::system_colors::inactive_border() {
  return color::from_known_color(xtd::drawing::known_color::inactive_border);
}

color xtd::drawing::system_colors::inactive_caption() {
  return color::from_known_color(xtd::drawing::known_color::inactive_caption);
}

color xtd::drawing::system_colors::inactive_caption_text() {
  return color::from_known_color(xtd::drawing::known_color::inactive_caption_text);
}

color xtd::drawing::system_colors::info() {
  return color::from_known_color(xtd::drawing::known_color::info);
}

color xtd::drawing::system_colors::info_text() {
  return color::from_known_color(xtd::drawing::known_color::info_text);
}

color xtd::drawing::system_colors::link_text() {
  return color::from_known_color(xtd::drawing::known_color::link_text);
}

color xtd::drawing::system_colors::menu() {
  return color::from_known_color(xtd::drawing::known_color::menu);
}

color xtd::drawing::system_colors::menu_bar() {
  return color::from_known_color(xtd::drawing::known_color::menu_bar);
}

color xtd::drawing::system_colors::menu_highlight() {
  return color::from_known_color(xtd::drawing::known_color::menu_highlight);
}

color xtd::drawing::system_colors::menu_text() {
  return color::from_known_color(xtd::drawing::known_color::menu_text);
}

color xtd::drawing::system_colors::scroll_bar() {
  return color::from_known_color(xtd::drawing::known_color::scroll_bar);
}

color xtd::drawing::system_colors::shadow_text() {
  return color::from_known_color(xtd::drawing::known_color::shadow_text);
}

color xtd::drawing::system_colors::text_box() {
  return color::from_known_color(xtd::drawing::known_color::text_box);
}

color xtd::drawing::system_colors::text_box_text() {
  return color::from_known_color(xtd::drawing::known_color::text_box_text);
}

color xtd::drawing::system_colors::visited_text() {
  return color::from_known_color(xtd::drawing::known_color::visited_text);
}

color xtd::drawing::system_colors::window() {
  return color::from_known_color(xtd::drawing::known_color::window);
}

color xtd::drawing::system_colors::window_frame() {
  return color::from_known_color(xtd::drawing::known_color::window_frame);
}

color xtd::drawing::system_colors::window_text() {
  return color::from_known_color(xtd::drawing::known_color::window_text);
}

const vector<color>& system_colors::get_colors() noexcept {
  static auto colors = vector {system_colors::accent(), system_colors::accent_text(), system_colors::active_border(), system_colors::active_caption(), system_colors::active_caption_text(), system_colors::active_text(), system_colors::app_workspace(), system_colors::button_face(), system_colors::button_highlight(), system_colors::button_shadow(), system_colors::control(), system_colors::control_dark(), system_colors::control_dark_dark(), system_colors::control_light(), system_colors::control_light_light(), system_colors::control_text(), system_colors::desktop(), system_colors::gradient_active_caption(), system_colors::gradient_inactive_caption(), system_colors::gray_text(), system_colors::highlight(), system_colors::highlight_text(), system_colors::hot_track(), system_colors::inactive_border(), system_colors::inactive_caption(), system_colors::inactive_caption_text(), system_colors::info(), system_colors::info_text(), system_colors::link_text(), system_colors::menu(), system_colors::menu_bar(), system_colors::menu_highlight(), system_colors::menu_text(), system_colors::scroll_bar(), system_colors::text_box(), system_colors::text_box_text(), system_colors::visited_text(), system_colors::window(), system_colors::window_frame(), system_colors::window_text(),};
  return colors;
}

const vector<ustring>& system_colors::get_color_names() noexcept {
  static auto color_names = vector {system_colors::accent().name(), system_colors::accent_text().name(), system_colors::active_border().name(), system_colors::active_caption().name(), system_colors::active_caption_text().name(), system_colors::active_text().name(), system_colors::app_workspace().name(), system_colors::button_face().name(), system_colors::button_highlight().name(), system_colors::button_shadow().name(), system_colors::control().name(), system_colors::control_dark().name(), system_colors::control_dark_dark().name(), system_colors::control_light().name(), system_colors::control_light_light().name(), system_colors::control_text().name(), system_colors::desktop().name(), system_colors::gradient_active_caption().name(), system_colors::gradient_inactive_caption().name(), system_colors::gray_text().name(), system_colors::highlight().name(), system_colors::highlight_text().name(), system_colors::hot_track().name(), system_colors::inactive_border().name(), system_colors::inactive_caption().name(), system_colors::inactive_caption_text().name(), system_colors::info().name(), system_colors::info_text().name(), system_colors::link_text().name(), system_colors::menu().name(), system_colors::menu_bar().name(), system_colors::menu_highlight().name(), system_colors::menu_text().name(), system_colors::scroll_bar().name(), system_colors::text_box().name(), system_colors::text_box_text().name(), system_colors::visited_text().name(), system_colors::window().name(), system_colors::window_frame().name(), system_colors::window_text().name(),};
  return color_names;
}
