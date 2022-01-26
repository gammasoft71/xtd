#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_style_sheet) {
  public:
    void test_method_(style_sheets) {
      auto styles = style_sheet::style_sheets();
      assert::are_not_equal(styles.end(), styles.find("macOS (dark)"));
    }
  };
}
