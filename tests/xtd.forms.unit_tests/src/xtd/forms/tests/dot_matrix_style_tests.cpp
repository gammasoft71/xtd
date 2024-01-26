#include <xtd/forms/dot_matrix_style.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(dot_matrix_style_tests) {
  public:
    void test_method_(standard) {
      assert::are_equal(0, enum_object<>::to_int32(dot_matrix_style::standard), csf_);
      assert::are_equal("standard", enum_object<>::to_string(dot_matrix_style::standard), csf_);
      assert::are_equal(dot_matrix_style::standard, enum_object<>::parse<dot_matrix_style>("standard"), csf_);
    }
    
    void test_method_(square) {
      assert::are_equal(1, enum_object<>::to_int32(dot_matrix_style::square), csf_);
      assert::are_equal("square", enum_object<>::to_string(dot_matrix_style::square), csf_);
      assert::are_equal(dot_matrix_style::square, enum_object<>::parse<dot_matrix_style>("square"), csf_);
    }
  };
}

