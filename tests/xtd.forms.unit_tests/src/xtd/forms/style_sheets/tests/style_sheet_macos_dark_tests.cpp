#include <xtd/forms/style_sheets/style_sheet>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(style_sheet_macos_dark_tests) {
    auto test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("macOS (dark)", style.theme().name());
      assert::are_equal("Contains macOS (dark) theme.", style.theme().description());
      assert::are_equal("Gammasoft", style.theme().authors());
      assert::are_equal("https://gammasoft71.github.io/", style.theme().website().to_string());
    }
    
    auto test_method_(system_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF007AFF), style.system_colors().accent());
      assert::are_equal(color::white, style.system_colors().accent_text());
      assert::are_equal(color::from_argb(0xFFB4B4B4), style.system_colors().active_border());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().active_caption());
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().active_caption_text());
      assert::are_equal(color::from_argb(0xFF262626), style.system_colors().app_workspace());
      assert::are_equal(color::from_argb(64, 255, 255, 255), style.system_colors().button_face());
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().button_highlight());
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().button_shadow());
      assert::are_equal(color::from_argb(0xFF323232), style.system_colors().control());
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark());
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark_dark());
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().control_light());
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().control_light_light());
      assert::are_equal(color::from_argb(0xFFFFFFFF), style.system_colors().control_text());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().desktop());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().gradient_active_caption());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().gradient_inactive_caption());
      assert::are_equal(color::from_argb(63, 255, 255, 255), style.system_colors().gray_text());
      assert::are_equal(color::from_argb(0xFF314F78), style.system_colors().highlight());
      assert::are_equal(color::white, style.system_colors().highlight_text());
      assert::are_equal(color::from_argb(0xFF3586FF), style.system_colors().hot_track());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().inactive_border());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().inactive_caption());
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().inactive_caption_text());
      assert::are_equal(color::from_argb(0xFF262626), style.system_colors().info());
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().info_text());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().menu());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().menu_bar());
      assert::are_equal(color::from_argb(0xFF345DF1), style.system_colors().menu_highlight());
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().menu_text());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().scroll_bar());
      assert::are_equal(color::from_argb(16, 255, 255, 255), style.system_colors().text_box());
      assert::are_equal(color::white, style.system_colors().text_box_text());
      assert::are_equal(color::from_argb(0xFF171717), style.system_colors().window());
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().window_frame());
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().window_text());
    }
    
    auto test_method_(button_standard) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(margin({length(0), length(2), length(0), length(1)}), style.button(pseudo_state::standard).margin());
      assert::are_equal(style_sheets::border_style(border_type::outset), style.button(pseudo_state::standard).border_style());
      assert::are_equal(border_color(style.system_colors().control_dark()), style.button(pseudo_state::standard).border_color());
      assert::are_equal(border_width(length(1)), style.button(pseudo_state::standard).border_width());
    }
  };
}
