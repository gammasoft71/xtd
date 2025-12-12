#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::contraints::tests {
  class test_class_(assert_that_is_equal_to_failed_tests) {
  public:
    auto test_method_(test_case_failed) {
      int i = 24;
      xtd::tunit::constraints::assert_that(i).is().equal_to(23);
    }
  };
  
  void test_(assert_that_is_equal_to_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::contraints::tests::assert_that_is_equal_to_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::contraints::tests::assert_that_is_equal_to_failed_tests.test_case_failed\n"
                  "    Expected: 23\n"
                  "    But was:  24\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_that_is_equal_to_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::contraints::tests::assert_that_is_equal_to_failed_tests.*");
    assert_value_(1, result);
  }
}
