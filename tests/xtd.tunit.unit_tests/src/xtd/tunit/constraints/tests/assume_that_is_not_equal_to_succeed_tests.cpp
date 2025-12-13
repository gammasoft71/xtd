#include <xtd/tunit/constraints/assume_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::constraints::tests {
  class test_class_(assume_that_is_not_equal_to_succeed_tests) {
  public:
    auto test_method_(test_case_succeed) {
      int i = 24;
      xtd::tunit::assume::are_not_equal(23, i);
    }
  };
  
  void test_(assume_that_is_not_equal_to_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assume_that_is_not_equal_to_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::constraints::tests::assume_that_is_not_equal_to_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assume_that_is_not_equal_to_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assume_that_is_not_equal_to_succeed_tests.*");
    assert_value_(0, result);
  }
}
