#include <xtd/drawing/applications_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(applications_system_images_tests) {
    void test_method_(default_size) {
      auto s = applications_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(accessories_calculator) {
      auto i = applications_system_images::accessories_calculator();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-calculator"), i, csf_);
    }

    void test_method_(accessories_calculator_with_specified_size) {
      auto i = applications_system_images::accessories_calculator({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-calculator", size {64, 64}), i, csf_);
    }

    void test_method_(accessories_character_map) {
      auto i = applications_system_images::accessories_character_map();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-character-map"), i, csf_);
    }

    void test_method_(accessories_character_map_with_specified_size) {
      auto i = applications_system_images::accessories_character_map({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-character-map", size {64, 64}), i, csf_);
    }

    void test_method_(accessories_dictionary) {
      auto i = applications_system_images::accessories_dictionary();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-dictionary"), i, csf_);
    }

    void test_method_(accessories_dictionary_with_specified_size) {
      auto i = applications_system_images::accessories_dictionary({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-dictionary", size {64, 64}), i, csf_);
    }

    void test_method_(accessories_text_editor) {
      auto i = applications_system_images::accessories_text_editor();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-text-editor"), i, csf_);
    }

    void test_method_(accessories_text_editor_with_specified_size) {
      auto i = applications_system_images::accessories_text_editor({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("accessories-text-editor", size {64, 64}), i, csf_);
    }

    void test_method_(help_browser) {
      auto i = applications_system_images::help_browser();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-browser"), i, csf_);
    }

    void test_method_(help_browser_with_specified_size) {
      auto i = applications_system_images::help_browser({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-browser", size {64, 64}), i, csf_);
    }

    void test_method_(help) {
      auto i = applications_system_images::help();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help"), i, csf_);
    }

    void test_method_(help_with_specified_size) {
      auto i = applications_system_images::help({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help", size {64, 64}), i, csf_);
    }

    void test_method_(multimedia_volume_control) {
      auto i = applications_system_images::multimedia_volume_control();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("multimedia-volume-control"), i, csf_);
    }

    void test_method_(multimedia_volume_control_with_specified_size) {
      auto i = applications_system_images::multimedia_volume_control({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("multimedia-volume-control", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_accessibility) {
      auto i = applications_system_images::preferences_desktop_accessibility();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-accessibility"), i, csf_);
    }

    void test_method_(preferences_desktop_accessibility_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_accessibility({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-accessibility", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_font) {
      auto i = applications_system_images::preferences_desktop_font();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-font"), i, csf_);
    }

    void test_method_(preferences_desktop_font_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_font({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-font", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_keyboard) {
      auto i = applications_system_images::preferences_desktop_keyboard();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-keyboard"), i, csf_);
    }

    void test_method_(preferences_desktop_keyboard_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_keyboard({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-keyboard", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_locale) {
      auto i = applications_system_images::preferences_desktop_locale();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-locale"), i, csf_);
    }

    void test_method_(preferences_desktop_locale_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_locale({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-locale", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_screensaver) {
      auto i = applications_system_images::preferences_desktop_screensaver();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-screensaver"), i, csf_);
    }

    void test_method_(preferences_desktop_screensaver_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_screensaver({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-screensaver", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_theme) {
      auto i = applications_system_images::preferences_desktop_theme();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-theme"), i, csf_);
    }

    void test_method_(preferences_desktop_theme_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_theme({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-theme", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_wallpaper) {
      auto i = applications_system_images::preferences_desktop_wallpaper();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-wallpaper"), i, csf_);
    }

    void test_method_(preferences_desktop_wallpaper_with_specified_size) {
      auto i = applications_system_images::preferences_desktop_wallpaper({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-wallpaper", size {64, 64}), i, csf_);
    }

    void test_method_(system_file_manager) {
      auto i = applications_system_images::system_file_manager();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-file-manager"), i, csf_);
    }

    void test_method_(system_file_manager_with_specified_size) {
      auto i = applications_system_images::system_file_manager({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-file-manager", size {64, 64}), i, csf_);
    }

    void test_method_(system_software_install) {
      auto i = applications_system_images::system_software_install();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-software-install"), i, csf_);
    }

    void test_method_(system_software_install_with_specified_size) {
      auto i = applications_system_images::system_software_install({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-software-install", size {64, 64}), i, csf_);
    }

    void test_method_(system_software_update) {
      auto i = applications_system_images::system_software_update();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-software-update"), i, csf_);
    }

    void test_method_(system_software_update_with_specified_size) {
      auto i = applications_system_images::system_software_update({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-software-update", size {64, 64}), i, csf_);
    }

    void test_method_(utilities_system_monitor) {
      auto i = applications_system_images::utilities_system_monitor();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("utilities-system-monitor"), i, csf_);
    }

    void test_method_(utilities_system_monitor_with_specified_size) {
      auto i = applications_system_images::utilities_system_monitor({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("utilities-system-monitor", size {64, 64}), i, csf_);
    }

    void test_method_(utilities_terminal) {
      auto i = applications_system_images::utilities_terminal();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("utilities-terminal"), i, csf_);
    }

    void test_method_(utilities_terminal_with_specified_size) {
      auto i = applications_system_images::utilities_terminal({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("utilities-terminal", size {64, 64}), i, csf_);
    }
  };
}
