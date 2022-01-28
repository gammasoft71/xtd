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

    void test_method_(create_with_specified_all_color) {
      border_color_property b(color_property {color::red});
      assert::are_equal(color::red, b.all().color(), csf_);
    }

    void test_method_(create_with_specified_left_top_right_bottom_color) {
      border_color_property b(color_property {color::red}, color_property {color::green}, color_property {color::blue}, color_property {color::yellow});
      assert::are_equal(color_property::empty, b.all(), csf_);
      assert::are_equal(color::red, b.left().color(), csf_);
      assert::are_equal(color::green, b.top().color(), csf_);
      assert::are_equal(color::blue, b.right().color(), csf_);
      assert::are_equal(color::yellow, b.bottom().color(), csf_);
    }
  };
}
