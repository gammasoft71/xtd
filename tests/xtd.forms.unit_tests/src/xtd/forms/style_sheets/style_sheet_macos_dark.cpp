#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_style_sheet_macos_dark) {
  public:
    void test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("macOS (dark)", style.theme().name(), csf_);
      assert::are_equal("Contains macOS (dark) theme.", style.theme().description(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website(), csf_);
    }
    
    void test_method_(system_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF007AFF), style.system_colors().accent(), csf_);
      assert::are_equal(color::white, style.system_colors().accent_text(), csf_);
      assert::are_equal(color::from_argb(0xFFB4B4B4), style.system_colors().active_border(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().active_caption(), csf_);
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().active_caption_text(), csf_);
      assert::are_equal(color::from_argb(0xFF262626), style.system_colors().app_workspace(), csf_);
      assert::are_equal(color::from_argb(64, 255, 255, 255), style.system_colors().button_face(), csf_);
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().button_highlight(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().button_shadow(), csf_);
      assert::are_equal(color::from_argb(0xFF323232), style.system_colors().control(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark(), csf_);
      assert::are_equal(color::from_argb(68, 0, 0, 0), style.system_colors().control_dark_dark(), csf_);
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().control_light(), csf_);
      assert::are_equal(color::from_argb(25, 255, 255, 255), style.system_colors().control_light_light(), csf_);
      assert::are_equal(color::from_argb(216, 255, 255, 255), style.system_colors().control_text(), csf_);
      assert::are_equal(color::from_argb(0xFF9A9A9A), style.system_colors().desktop(), csf_);
    }
  };
}
