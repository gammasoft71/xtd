#include <xtd/security/secure_string.h>
#include <xtd/xtd.tunit>

using namespace xtd::security;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_secure_string) {
  public:
    void test_method_(create_secure_string) {
      secure_string ss("String to test", 14);
      assert::are_equal(14U, ss.size());
      assert::are_equal("String to test", ss.to_unsecure_string());
    }

    void test_method_(create_secure_string_with_null_pointer) {
      secure_string ss(nullptr, 14);
      assert::are_equal(0U, ss.size());
      assert::are_equal("", ss.to_unsecure_string());
    }
  };
}
