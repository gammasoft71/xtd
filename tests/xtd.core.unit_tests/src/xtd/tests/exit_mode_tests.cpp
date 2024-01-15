#include <xtd/exit_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(exit_mode_tests) {
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(exit_mode::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(exit_mode::normal), csf_);
      assert::are_equal(exit_mode::normal, enum_object<>::parse<exit_mode>("normal"), csf_);
    }
    
    void test_method_(quick) {
      assert::are_equal(1, enum_object<>::to_int32(exit_mode::quick), csf_);
      assert::are_equal("quick", enum_object<>::to_string(exit_mode::quick), csf_);
      assert::are_equal(exit_mode::quick, enum_object<>::parse<exit_mode>("quick"), csf_);
    }
  };
}
