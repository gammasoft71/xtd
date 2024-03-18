#include <xtd/security/secure_string>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::security;
using namespace xtd::tunit;

namespace xtd::security::tests {
  class test_class_(secure_string_tests) {
    void test_method_(create_secure_string) {
      secure_string ss("String to test", 14);
      assert::are_equal(14_z, ss.size(), csf_);
      assert::are_equal("String to test", ss.to_unsecure_string(), csf_);
    }
    
    void test_method_(create_secure_string_with_null_pointer) {
      secure_string ss(nullptr, 14);
      assert::are_equal(0_z, ss.size(), csf_);
      assert::is_empty(ss.to_unsecure_string(), csf_);
    }
  };
}
