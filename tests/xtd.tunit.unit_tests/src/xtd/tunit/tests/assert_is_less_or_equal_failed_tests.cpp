#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_is_less_or_equal_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      int i = 42;
      xtd::tunit::assert::is_less_or_equal(i, 24);
    }
  };
}

void test_(assert_is_less_or_equal_failed_tests, test_output) {
  auto [result, output] = run_test_("assert_is_less_or_equal_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_is_less_or_equal_failed_tests.test_case_failed\n"
    "    Expected: less than or equal to 24\n"
    "    But was:  42\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_is_less_or_equal_failed_tests, test_result) {
  auto [result, output] = run_test_("assert_is_less_or_equal_failed_tests.*");
  assert_value_(1, result);
}
