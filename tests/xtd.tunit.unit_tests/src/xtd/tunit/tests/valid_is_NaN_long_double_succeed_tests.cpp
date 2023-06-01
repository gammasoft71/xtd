#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <limits>

namespace xtd::tunit::tests {
  class test_class_(valid_is_NaN_long_double_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      long double ld = std::numeric_limits<long double>::quiet_NaN();
      xtd::tunit::valid::is_NaN(ld);
    }
  };
}

void test_(valid_is_NaN_long_double_succeed_tests, test_output) {
  auto [result, output] = run_test_("valid_is_NaN_long_double_succeed_tests*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_is_NaN_long_double_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_NaN_long_double_succeed_tests, test_result) {
  auto [result, output] = run_test_("valid_is_NaN_long_double_succeed_tests*");
  assert_value_(0, result);
}
