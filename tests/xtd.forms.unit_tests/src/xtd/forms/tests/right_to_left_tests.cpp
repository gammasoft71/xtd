#include <xtd/forms/right_to_left.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(right_to_left_tests) {
  public:
    void test_method_(no) {
      assert::are_equal(0, enum_object<>::to_int32(right_to_left::no), csf_);
      assert::are_equal("no", enum_object<>::to_string(right_to_left::no), csf_);
      assert::are_equal(right_to_left::no, enum_object<>::parse<right_to_left>("no"), csf_);
    }
    
    void test_method_(yes) {
      assert::are_equal(1, enum_object<>::to_int32(right_to_left::yes), csf_);
      assert::are_equal("yes", enum_object<>::to_string(right_to_left::yes), csf_);
      assert::are_equal(right_to_left::yes, enum_object<>::parse<right_to_left>("yes"), csf_);
    }
    
    void test_method_(inherit) {
      assert::are_equal(2, enum_object<>::to_int32(right_to_left::inherit), csf_);
      assert::are_equal("inherit", enum_object<>::to_string(right_to_left::inherit), csf_);
      assert::are_equal(right_to_left::inherit, enum_object<>::parse<right_to_left>("inherit"), csf_);
    }
  };
}

