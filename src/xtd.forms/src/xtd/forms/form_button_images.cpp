#include "../../../include/xtd/forms/form_button_images.h"

using namespace xtd;
using namespace xtd::forms;

xtd::drawing::image form_button_images::close() {
  return close(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::close(bool maximized_form) {
  return close(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::close(const xtd::ustring& theme) {
  return close(theme, size());
}

xtd::drawing::image form_button_images::close(const xtd::ustring& theme, bool maximized_form) {
  return close(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::close(const xtd::drawing::size& size) {
  return close(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::close(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-close", size);
}

xtd::drawing::image form_button_images::close_hovered() {
  return close_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::close_hovered(bool maximized_form) {
  return close_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::close_hovered(const xtd::ustring& theme) {
  return close_hovered(theme, size());
}

xtd::drawing::image form_button_images::close_hovered(const xtd::ustring& theme, bool maximized_form) {
  return close_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::close_hovered(const xtd::drawing::size& size) {
  return close_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::close_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-close-hovered", size);
}

xtd::drawing::image form_button_images::fullscreen() {
  return fullscreen(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::fullscreen(bool maximized_form) {
  return fullscreen(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::fullscreen(const xtd::ustring& theme) {
  return fullscreen(theme, size());
}

xtd::drawing::image form_button_images::fullscreen(const xtd::ustring& theme, bool maximized_form) {
  return fullscreen(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::fullscreen(const xtd::drawing::size& size) {
  return fullscreen(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::fullscreen(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-fullscreen", size);
}

xtd::drawing::image form_button_images::fullscreen_hovered() {
  return fullscreen_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::fullscreen_hovered(bool maximized_form) {
  return fullscreen_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::fullscreen_hovered(const xtd::ustring& theme) {
  return fullscreen_hovered(theme, size());
}

xtd::drawing::image form_button_images::fullscreen_hovered(const xtd::ustring& theme, bool maximized_form) {
  return fullscreen_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::fullscreen_hovered(const xtd::drawing::size& size) {
  return fullscreen_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::fullscreen_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-fullscreen-hovered", size);
}

xtd::drawing::image form_button_images::maximize() {
  return maximize(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::maximize(bool maximized_form) {
  return maximize(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::maximize(const xtd::ustring& theme) {
  return maximize(theme, size());
}

xtd::drawing::image form_button_images::maximize(const xtd::ustring& theme, bool maximized_form) {
  return maximize(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::maximize(const xtd::drawing::size& size) {
  return maximize(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::maximize(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-maximize", size);
}

xtd::drawing::image form_button_images::maximize_hovered() {
  return maximize_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::maximize_hovered(bool maximized_form) {
  return maximize_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::maximize_hovered(const xtd::ustring& theme) {
  return maximize_hovered(theme, size());
}

xtd::drawing::image form_button_images::maximize_hovered(const xtd::ustring& theme, bool maximized_form) {
  return maximize_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::maximize_hovered(const xtd::drawing::size& size) {
  return maximize_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::maximize_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-maximize-hovered", size);
}

xtd::drawing::image form_button_images::minimize() {
  return minimize(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::minimize(bool maximized_form) {
  return minimize(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::minimize(const xtd::ustring& theme) {
  return minimize(theme, size());
}

xtd::drawing::image form_button_images::minimize(const xtd::ustring& theme, bool maximized_form) {
  return minimize(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::minimize(const xtd::drawing::size& size) {
  return minimize(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::minimize(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-minimize", size);
}

xtd::drawing::image form_button_images::minimize_hovered() {
  return minimize_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::minimize_hovered(bool maximized_form) {
  return minimize_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::minimize_hovered(const xtd::ustring& theme) {
  return minimize_hovered(theme, size());
}

xtd::drawing::image form_button_images::minimize_hovered(const xtd::ustring& theme, bool maximized_form) {
  return minimize_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::minimize_hovered(const xtd::drawing::size& size) {
  return minimize_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::minimize_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-minimize-hovered", size);
}

xtd::drawing::image form_button_images::restore() {
  return restore(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::restore(bool maximized_form) {
  return restore(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::restore(const xtd::ustring& theme) {
  return restore(theme, size());
}

xtd::drawing::image form_button_images::restore(const xtd::ustring& theme, bool maximized_form) {
  return restore(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::restore(const xtd::drawing::size& size) {
  return restore(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::restore(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-restore", size);
}

xtd::drawing::image form_button_images::restore_hovered() {
  return restore_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::restore_hovered(bool maximized_form) {
  return restore_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::restore_hovered(const xtd::ustring& theme) {
  return restore_hovered(theme, size());
}

xtd::drawing::image form_button_images::restore_hovered(const xtd::ustring& theme, bool maximized_form) {
  return restore_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::restore_hovered(const xtd::drawing::size& size) {
  return restore_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::restore_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-restore-hovered", size);
}

xtd::drawing::image form_button_images::system_menu() {
  return system_menu(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::system_menu(bool maximized_form) {
  return system_menu(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::system_menu(const xtd::ustring& theme) {
  return system_menu(theme, size());
}

xtd::drawing::image form_button_images::system_menu(const xtd::ustring& theme, bool maximized_form) {
  return system_menu(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::system_menu(const xtd::drawing::size& size) {
  return system_menu(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::system_menu(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-system-menu", size);
}

xtd::drawing::image form_button_images::system_menu_hovered() {
  return system_menu_hovered(xtd::forms::application::style_sheet().theme().name(), size());
}

xtd::drawing::image form_button_images::system_menu_hovered(bool maximized_form) {
  return system_menu_hovered(xtd::forms::application::style_sheet().theme().name(), size(maximized_form));
}

xtd::drawing::image form_button_images::system_menu_hovered(const xtd::ustring& theme) {
  return system_menu_hovered(theme, size());
}

xtd::drawing::image form_button_images::system_menu_hovered(const xtd::ustring& theme, bool maximized_form) {
  return system_menu_hovered(theme, size(maximized_form));
}

xtd::drawing::image form_button_images::system_menu_hovered(const xtd::drawing::size& size) {
  return system_menu_hovered(xtd::forms::application::style_sheet().theme().name(), size);
}

xtd::drawing::image form_button_images::system_menu_hovered(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "window-system-menu-hovered", size);
}

xtd::drawing::size form_button_images::size() {
  return size(false);
}

xtd::drawing::size form_button_images::size(bool maximized_form) {
  static auto is_windows = environment::os_version().is_windows_platform();
  static auto is_macos = environment::os_version().is_macos_platform();
  static auto is_unix = environment::os_version().is_unix_platform();
  if (is_windows) return {90, maximized_form ? 42 : 58};
  if (is_macos) return {24, 24};
  if (is_unix) return {64, 64};
  return {32, 32};
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& name) {
  return from_name(name, size());
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& theme, const xtd::ustring& name) {
  return from_name(theme, name, size());
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& name, const xtd::drawing::size& size) {
  return from_name(xtd::forms::application::style_sheet().theme().name(), name, size);
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size) {
  return images::from_name(theme, name, size);
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& name, bool maximized_form) {
  return from_name(name, size(maximized_form));
}

xtd::drawing::image form_button_images::from_name(const xtd::ustring& theme, const xtd::ustring& name, bool maximized_form) {
  return from_name(theme, name, size(maximized_form));
}
