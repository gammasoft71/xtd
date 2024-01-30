#include <xtd/forms/check_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(check_state_tests) {
  public:
    void test_method_(unchecked) {
      assert::are_equal(0, enum_object<>::to_int32(check_state::unchecked), csf_);
      assert::are_equal("unchecked", enum_object<>::to_string(check_state::unchecked), csf_);
      assert::are_equal(check_state::unchecked, enum_object<>::parse<check_state>("unchecked"), csf_);
    }
    
    void test_method_(checked) {
      assert::are_equal(1, enum_object<>::to_int32(check_state::checked), csf_);
      assert::are_equal("checked", enum_object<>::to_string(check_state::checked), csf_);
      assert::are_equal(check_state::checked, enum_object<>::parse<check_state>("checked"), csf_);
    }
    
    void test_method_(indeterminate) {
      assert::are_equal(2, enum_object<>::to_int32(check_state::indeterminate), csf_);
      assert::are_equal("indeterminate", enum_object<>::to_string(check_state::indeterminate), csf_);
      assert::are_equal(check_state::indeterminate, enum_object<>::parse<check_state>("indeterminate"), csf_);
    }
  };
}

