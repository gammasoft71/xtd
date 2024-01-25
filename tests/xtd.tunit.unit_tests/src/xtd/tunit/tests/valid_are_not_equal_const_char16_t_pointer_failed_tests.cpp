#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(valid_are_not_equal_const_char16_t_pointer_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      const char16* s = u"value";
      xtd::tunit::valid::are_not_equal(u"value", s);
    }
  };
  
  void test_(valid_are_not_equal_const_char16_t_pointer_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_are_not_equal_const_char16_t_pointer_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  FAILED  xtd::tunit::tests::valid_are_not_equal_const_char16_t_pointer_failed_tests.test_case_failed\n"
                  "    Expected: not \"value\"\n"
                  "    But was:  \"value\"\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(valid_are_not_equal_const_char16_t_pointer_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_are_not_equal_const_char16_t_pointer_failed_tests.*");
    assert_value_(1, result);
  }
}
