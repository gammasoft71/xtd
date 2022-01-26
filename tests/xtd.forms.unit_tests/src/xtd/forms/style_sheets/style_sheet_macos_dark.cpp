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
    void test_method_(style_sheets_theme_macos_dark) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("macOS (dark)", style.theme().name().text(), csf_);
      assert::are_equal("Contains macOS (dark) theme.", style.theme().description().text(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors().text(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website().url(), csf_);
    }
    
    void test_method_(style_sheets_system_colors_macos_dark) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color_data(color::from_argb(0xFF007AFF)), style.system_colors().accent(), csf_);
      assert::are_equal(color_data(color::white), style.system_colors().accent_text(), csf_);
    }
  };
}
