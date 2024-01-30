#include <xtd/forms/left_right_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(left_right_alignment_tests) {
  public:
    void test_method_(left) {
      assert::are_equal(0, enum_object<>::to_int32(left_right_alignment::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(left_right_alignment::left), csf_);
      assert::are_equal(left_right_alignment::left, enum_object<>::parse<left_right_alignment>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(1, enum_object<>::to_int32(left_right_alignment::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(left_right_alignment::right), csf_);
      assert::are_equal(left_right_alignment::right, enum_object<>::parse<left_right_alignment>("right"), csf_);
    }
  };
}
