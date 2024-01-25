#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(assert_is_null_nullptr_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      int i = 0;
      int* p = &i;
      xtd::tunit::assert::is_null(p);
    }
  };
  
  void test_(assert_is_null_nullptr_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_is_null_nullptr_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  FAILED  xtd::tunit::tests::assert_is_null_nullptr_failed_tests.test_case_failed\n"
                  "    Expected: null\n"
                  "    But was:  not null\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_is_null_nullptr_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_is_null_nullptr_failed_tests.*");
    assert_value_(1, result);
  }
}
