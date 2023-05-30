#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_fail_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      xtd::tunit::assert::fail(xtd::diagnostics::stack_frame {"assert_fail_failed_tests.cpp", 8});
    }
  };
}

void test_(assert_fail_failed_tests, test_output) {
  auto [result, output] = run_test_("assert_fail_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_fail_failed_tests.test_case_failed\n"
    "    Test failed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_fail_failed_tests, test_result) {
  auto [result, output] = run_test_("assert_fail_failed_tests.*");
  assert_value_(1, result);
}
