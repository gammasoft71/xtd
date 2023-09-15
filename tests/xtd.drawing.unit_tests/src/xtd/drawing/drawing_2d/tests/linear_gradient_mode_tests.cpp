#include <xtd/drawing/drawing_2d/linear_gradient_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(linear_gradient_mode_tests) {
  public:
    void test_method_(horizontal) {
      assert::are_equal(0, enum_object<>::to_int32(linear_gradient_mode::horizontal), csf_);
      assert::are_equal("horizontal", enum_object<>::to_string(linear_gradient_mode::horizontal), csf_);
      assert::are_equal(linear_gradient_mode::horizontal, enum_object<>::parse<linear_gradient_mode>("horizontal"), csf_);
    }
    
    void test_method_(vertical) {
      assert::are_equal(1, enum_object<>::to_int32(linear_gradient_mode::vertical), csf_);
      assert::are_equal("vertical", enum_object<>::to_string(linear_gradient_mode::vertical), csf_);
      assert::are_equal(linear_gradient_mode::vertical, enum_object<>::parse<linear_gradient_mode>("vertical"), csf_);
    }
    
    void test_method_(forward_diagonal) {
      assert::are_equal(2, enum_object<>::to_int32(linear_gradient_mode::forward_diagonal), csf_);
      assert::are_equal("forward_diagonal", enum_object<>::to_string(linear_gradient_mode::forward_diagonal), csf_);
      assert::are_equal(linear_gradient_mode::forward_diagonal, enum_object<>::parse<linear_gradient_mode>("forward_diagonal"), csf_);
    }
    
    void test_method_(backward_diagonal) {
      assert::are_equal(3, enum_object<>::to_int32(linear_gradient_mode::backward_diagonal), csf_);
      assert::are_equal("backward_diagonal", enum_object<>::to_string(linear_gradient_mode::backward_diagonal), csf_);
      assert::are_equal(linear_gradient_mode::backward_diagonal, enum_object<>::parse<linear_gradient_mode>("backward_diagonal"), csf_);
    }
  };
}

