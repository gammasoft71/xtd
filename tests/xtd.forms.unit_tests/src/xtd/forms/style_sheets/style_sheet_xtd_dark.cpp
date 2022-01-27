#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_style_sheet_xtd_dark) {
  public:
    void test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("xtd (dark)")->second;
      assert::are_equal("xtd (dark)", style.theme().name().text(), csf_);
      assert::are_equal("Contains xtd (dark) theme.", style.theme().description().text(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors().text(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website().url(), csf_);
    }
  };
}
