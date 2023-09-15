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
  class test_class_(style_sheet_windows_light_tests) {
  public:
    void test_method_(theme) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("Windows (light)")->second;
      assert::are_equal("Windows (light)", style.theme().name(), csf_);
      assert::are_equal("Contains Windows (light) theme.", style.theme().description(), csf_);
      assert::are_equal("Gammasoft", style.theme().authors(), csf_);
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.theme().website().to_string(), csf_);
    }
  };
}
