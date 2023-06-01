#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_are_not_same_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int a = 24;
      int b =  24;
      xtd::tunit::valid::are_not_same(b, a);
    }
  };
}

void test_(valid_are_not_same_succeed_tests, test_output) {
  auto [result, output] = run_test_("valid_are_not_same_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_are_not_same_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_are_not_same_succeed_tests, test_result) {
  auto [result, output] = run_test_("valid_are_not_same_succeed_tests.*");
  assert_value_(0, result);
}
