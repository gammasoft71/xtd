#include <xtd/drawing/drawing_2d/matrix_order>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(matrix_order_tests) {
    void test_method_(prepend) {
      assert::are_equal(0, enum_object<>::to_int32(matrix_order::prepend), csf_);
      assert::are_equal("prepend", enum_object<>::to_string(matrix_order::prepend), csf_);
      assert::are_equal(matrix_order::prepend, enum_object<>::parse<matrix_order>("prepend"), csf_);
    }
    
    void test_method_(append) {
      assert::are_equal(1, enum_object<>::to_int32(matrix_order::append), csf_);
      assert::are_equal("append", enum_object<>::to_string(matrix_order::append), csf_);
      assert::are_equal(matrix_order::append, enum_object<>::parse<matrix_order>("append"), csf_);
    }
  };
}
