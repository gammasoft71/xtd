#include <xtd/forms/power_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(power_state_tests) {
  public:
    void test_method_(suspend) {
      assert::are_equal(0, enum_object<>::to_int32(power_state::suspend), csf_);
      assert::are_equal("suspend", enum_object<>::to_string(power_state::suspend), csf_);
      assert::are_equal(power_state::suspend, enum_object<>::parse<power_state>("suspend"), csf_);
    }
    
    void test_method_(hibernate) {
      assert::are_equal(1, enum_object<>::to_int32(power_state::hibernate), csf_);
      assert::are_equal("hibernate", enum_object<>::to_string(power_state::hibernate), csf_);
      assert::are_equal(power_state::hibernate, enum_object<>::parse<power_state>("hibernate"), csf_);
    }
  };
}
