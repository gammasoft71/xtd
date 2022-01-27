#include <xtd/forms/style_sheets/border_color_property.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_border_color_property) {
  public:
    void test_method_(create_default) {
      border_color_property b;
      assert::are_equal(color::black, b.all().color(), csf_);
    }
  };
}
