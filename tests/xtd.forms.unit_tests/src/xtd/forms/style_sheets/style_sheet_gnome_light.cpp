#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_style_sheet_gnome_light) {
  public:
    void test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("GNOME (light)")->second;
      assert::are_equal("GNOME (light)", style.theme().name(), csf_);
      assert::are_equal("Contains GNOME (light) theme.", style.theme().description(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website().to_string(), csf_);

    }
  };
}
