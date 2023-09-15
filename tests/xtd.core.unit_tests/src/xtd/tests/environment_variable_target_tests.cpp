#include <xtd/environment_variable_target>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_variable_target_tests) {
  public:
    void test_method_(process) {
      assert::are_equal(0, enum_object<>::to_int32(environment_variable_target::process), csf_);
      assert::are_equal("process", enum_object<>::to_string(environment_variable_target::process), csf_);
      assert::are_equal(environment_variable_target::process, enum_object<>::parse<environment_variable_target>("process"), csf_);
    }
    
    void test_method_(user) {
      assert::are_equal(1, enum_object<>::to_int32(environment_variable_target::user), csf_);
      assert::are_equal("user", enum_object<>::to_string(environment_variable_target::user), csf_);
      assert::are_equal(environment_variable_target::user, enum_object<>::parse<environment_variable_target>("user"), csf_);
    }
    
    void test_method_(machine) {
      assert::are_equal(2, enum_object<>::to_int32(environment_variable_target::machine), csf_);
      assert::are_equal("machine", enum_object<>::to_string(environment_variable_target::machine), csf_);
      assert::are_equal(environment_variable_target::machine, enum_object<>::parse<environment_variable_target>("machine"), csf_);
    }
  };
}
