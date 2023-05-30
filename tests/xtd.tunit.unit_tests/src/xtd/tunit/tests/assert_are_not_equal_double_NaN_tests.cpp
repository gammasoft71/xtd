#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_are_not_equal_double_NaN_tests) {
  public:
    void test_method_(test_case_succeed) {
      double d = 0;
      xtd::tunit::assert::are_not_equal(std::numeric_limits<double>::quiet_NaN(), d);
    }
  };
}

void test_(assert_are_not_equal_double_NaN_tests, test_output) {
  auto [result, output] = run_test_("assert_are_not_equal_double_NaN_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assert_are_not_equal_double_NaN_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_are_not_equal_double_NaN_tests, test_result) {
  auto [result, output] = run_test_("assert_are_not_equal_double_NaN_tests.*");
  assert_value_(0, result);
}
