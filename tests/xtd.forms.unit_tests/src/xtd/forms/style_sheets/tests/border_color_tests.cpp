#include <xtd/forms/style_sheets/border_color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(border_color_tests) {
    void test_method_(create_default) {
      border_color b;
      assert::are_equal(color::black, b.all(), csf_);
    }
    
    void test_method_(create_with_specified_all_color) {
      border_color b(color::red);
      assert::are_equal(color::red, b.all(), csf_);
    }
    
    void test_method_(create_with_specified_left_top_right_bottom_color) {
      border_color b(color::red, color::green, color::blue, color::yellow);
      assert::are_equal(color::empty, b.all(), csf_);
      assert::are_equal(color::red, b.left(), csf_);
      assert::are_equal(color::green, b.top(), csf_);
      assert::are_equal(color::blue, b.right(), csf_);
      assert::are_equal(color::yellow, b.bottom(), csf_);
    }
  };
}
