#include "../../../include/xtd/drawing/applications_system_images"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size applications_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image applications_system_images::accessories_calculator() noexcept {
  return accessories_calculator(default_size());
}

image applications_system_images::accessories_calculator(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("accessories-calculator", size);
}

image applications_system_images::accessories_character_map() noexcept {
  return accessories_character_map(default_size());
}

image applications_system_images::accessories_character_map(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("accessories-character-map", size);
}

image applications_system_images::accessories_dictionary() noexcept {
  return accessories_dictionary(default_size());
}

image applications_system_images::accessories_dictionary(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("accessories-dictionary", size);
}

image applications_system_images::accessories_text_editor() noexcept {
  return accessories_text_editor(default_size());
}

image applications_system_images::accessories_text_editor(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("accessories-text-editor", size);
}

image applications_system_images::help_browser() noexcept {
  return help_browser(default_size());
}

image applications_system_images::help_browser(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("help-browser", size);
}

image applications_system_images::help() noexcept {
  return help(default_size());
}

image applications_system_images::help(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("help", size);
}

image applications_system_images::multimedia_volume_control() noexcept {
  return multimedia_volume_control(default_size());
}

image applications_system_images::multimedia_volume_control(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("multimedia-volume-control", size);
}

image applications_system_images::preferences_desktop_accessibility() noexcept {
  return preferences_desktop_accessibility(default_size());
}

image applications_system_images::preferences_desktop_accessibility(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-accessibility", size);
}

image applications_system_images::preferences_desktop_font() noexcept {
  return preferences_desktop_font(default_size());
}

image applications_system_images::preferences_desktop_font(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-font", size);
}

image applications_system_images::preferences_desktop_keyboard() noexcept {
  return preferences_desktop_keyboard(default_size());
}

image applications_system_images::preferences_desktop_keyboard(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-keyboard", size);
}

image applications_system_images::preferences_desktop_locale() noexcept {
  return preferences_desktop_locale(default_size());
}

image applications_system_images::preferences_desktop_locale(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-locale", size);
}

image applications_system_images::preferences_desktop_screensaver() noexcept {
  return preferences_desktop_screensaver(default_size());
}

image applications_system_images::preferences_desktop_screensaver(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-screensaver", size);
}

image applications_system_images::preferences_desktop_theme() noexcept {
  return preferences_desktop_theme(default_size());
}

image applications_system_images::preferences_desktop_theme(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-theme", size);
}

image applications_system_images::preferences_desktop_wallpaper() noexcept {
  return preferences_desktop_wallpaper(default_size());
}

image applications_system_images::preferences_desktop_wallpaper(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("preferences-desktop-wallpaper", size);
}

image applications_system_images::system_file_manager() noexcept {
  return system_file_manager(default_size());
}

image applications_system_images::system_file_manager(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("system-file-manager", size);
}

image applications_system_images::system_software_install() noexcept {
  return system_software_install(default_size());
}

image applications_system_images::system_software_install(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("system-software-install", size);
}

image applications_system_images::system_software_update() noexcept {
  return system_software_update(default_size());
}

image applications_system_images::system_software_update(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("system-software-update", size);
}

image applications_system_images::utilities_system_monitor() noexcept {
  return utilities_system_monitor(default_size());
}

image applications_system_images::utilities_system_monitor(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("utilities-system-monitor", size);
}

image applications_system_images::utilities_terminal() noexcept {
  return utilities_terminal(default_size());
}

image applications_system_images::utilities_terminal(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("utilities-terminal", size);
}

const vector<image>& applications_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> applications_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {accessories_calculator(size), accessories_character_map(size), accessories_dictionary(size), accessories_text_editor(size), help_browser(size), help(size), multimedia_volume_control(size), preferences_desktop_accessibility(size), preferences_desktop_font(size), preferences_desktop_keyboard(size), preferences_desktop_locale(size), preferences_desktop_screensaver(size), preferences_desktop_theme(size), preferences_desktop_wallpaper(size), system_file_manager(size), system_software_install(size), system_software_update(size), utilities_system_monitor(size), utilities_terminal(size), };
}

const vector<ustring>& applications_system_images::get_image_names() noexcept {
  static auto names = vector {"accessories-calculator"_s, "accessories-character-map"_s, "accessories-dictionary"_s, "accessories-text-editor"_s, "help-browser"_s, "help"_s, "multimedia-volume-control"_s, "preferences-desktop-accessibility"_s, "preferences-desktop-font"_s, "preferences-desktop-keyboard"_s, "preferences-desktop-locale"_s, "preferences-desktop-screensaver"_s, "preferences-desktop-theme"_s, "preferences-desktop-wallpaper"_s, "system-file-manager"_s, "system-software-install"_s, "system-software-update"_s, "utilities-system-monitor"_s, "utilities-terminal"_s, };
  return names;
}
