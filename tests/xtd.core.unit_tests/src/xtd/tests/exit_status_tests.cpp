#include <xtd/exit_status>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(exit_status_tests) {
    void test_method_(success) {
      assert::are_equal(EXIT_SUCCESS, enum_object<>::to_int32(exit_status::success), csf_);
      assert::are_equal("success", enum_object<>::to_string(exit_status::success), csf_);
      assert::are_equal(exit_status::success, enum_object<>::parse<exit_status>("success"), csf_);
    }
    
    void test_method_(failure) {
      assert::are_equal(EXIT_FAILURE, enum_object<>::to_int32(exit_status::failure), csf_);
      assert::are_equal("failure", enum_object<>::to_string(exit_status::failure), csf_);
      assert::are_equal(exit_status::failure, enum_object<>::parse<exit_status>("failure"), csf_);
    }
  };
}
