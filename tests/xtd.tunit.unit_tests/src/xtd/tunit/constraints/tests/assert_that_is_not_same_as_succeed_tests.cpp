#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::constraints::tests {
  class test_class_(assert_that_is_not_same_as_succeed_tests) {
  public:
    auto test_method_(test_case_succeed) {
      int a = 24;
      int b = 24;
      xtd::tunit::constraints::assert_that(a).is().not_().same_as(b);
    }
  };
  
  void test_(assert_that_is_not_same_as_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_is_not_same_as_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::constraints::tests::assert_that_is_not_same_as_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_that_is_not_same_as_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_is_not_same_as_succeed_tests.*");
    assert_value_(0, result);
  }
}
