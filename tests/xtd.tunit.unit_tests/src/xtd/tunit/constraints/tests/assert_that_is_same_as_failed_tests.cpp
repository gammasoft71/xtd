#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::constraints::tests {
  class test_class_(assert_that_is_same_as_failed_tests) {
  public:
    auto test_method_(test_case_failed) {
      int a = 24;
      int b = 24;
      xtd::tunit::constraints::assert_that(a).is().same_as(b);
    }
  };
  
  void test_(assert_that_is_same_as_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_is_same_as_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::constraints::tests::assert_that_is_same_as_failed_tests.test_case_failed\n"
                  "    Expected: same as 24\n"
                  "    But was:  24\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_that_is_same_as_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_is_same_as_failed_tests.*");
    assert_value_(1, result);
  }
}
