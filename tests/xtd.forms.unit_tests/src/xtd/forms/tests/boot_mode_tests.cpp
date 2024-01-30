#include <xtd/forms/boot_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(boot_mode_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(boot_mode::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(boot_mode::normal), csf_);
      assert::are_equal(boot_mode::normal, enum_object<>::parse<boot_mode>("normal"), csf_);
    }
    
    void test_method_(fail_safe) {
      assert::are_equal(1, enum_object<>::to_int32(boot_mode::fail_safe), csf_);
      assert::are_equal("fail_safe", enum_object<>::to_string(boot_mode::fail_safe), csf_);
      assert::are_equal(boot_mode::fail_safe, enum_object<>::parse<boot_mode>("fail_safe"), csf_);
    }
    
    void test_method_(fail_safe_with_network) {
      assert::are_equal(2, enum_object<>::to_int32(boot_mode::fail_safe_with_network), csf_);
      assert::are_equal("fail_safe_with_network", enum_object<>::to_string(boot_mode::fail_safe_with_network), csf_);
      assert::are_equal(boot_mode::fail_safe_with_network, enum_object<>::parse<boot_mode>("fail_safe_with_network"), csf_);
    }
  };
}
