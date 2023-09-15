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
  class test_class_(style_sheet_macos_light_tests) {
  public:
    void test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (light)")->second;
      assert::are_equal("macOS (light)", style.theme().name(), csf_);
      assert::are_equal("Contains macOS (light) theme.", style.theme().description(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website().to_string(), csf_);
    }
    
    void test_method_(system_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (light)")->second;
      assert::are_equal(color::from_argb(0xFF007AFF), style.system_colors().accent(), csf_);
      assert::are_equal(color::white, style.system_colors().accent_text(), csf_);
      assert::are_equal(color::white, style.system_colors().active_border(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().active_caption(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().active_caption_text(), csf_);
      assert::are_equal(color::from_argb(0xFFE7E7E7), style.system_colors().app_workspace(), csf_);
      assert::are_equal(color::from_argb(180, 255, 255, 255), style.system_colors().button_face(), csf_);
      assert::are_equal(color::white, style.system_colors().button_highlight(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().button_shadow(), csf_);
      assert::are_equal(color::from_argb(0xFFECECEC), style.system_colors().control(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark_dark(), csf_);
      assert::are_equal(color::white, style.system_colors().control_light(), csf_);
      assert::are_equal(color::white, style.system_colors().control_light_light(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().control_text(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().desktop(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().gradient_active_caption(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().gradient_inactive_caption(), csf_);
      assert::are_equal(color::from_argb(63, 0, 0, 0), style.system_colors().gray_text(), csf_);
      assert::are_equal(color::from_argb(0xFFA5CDFF), style.system_colors().highlight(), csf_);
      assert::are_equal(color::black, style.system_colors().highlight_text(), csf_);
      assert::are_equal(color::from_argb(0xFF094FD1), style.system_colors().hot_track(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().inactive_border(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().inactive_caption(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().inactive_caption_text(), csf_);
      assert::are_equal(color::from_argb(0xFFE7E7E7), style.system_colors().info(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().info_text(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().menu(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().menu_bar(), csf_);
      assert::are_equal(color::from_argb(0xFF345DF1), style.system_colors().menu_highlight(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().menu_text(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().scroll_bar(), csf_);
      assert::are_equal(color::white, style.system_colors().text_box(), csf_);
      assert::are_equal(color::black, style.system_colors().text_box_text(), csf_);
      assert::are_equal(color::white, style.system_colors().window(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().window_frame(), csf_);
      assert::are_equal(color::from_argb(216, 0, 0, 0), style.system_colors().window_text(), csf_);
    }
  };
}
