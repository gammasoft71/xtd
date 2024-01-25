#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(one_test_two_test_cases_and_one_ignore_test_case_tests) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
    void ignore_test_method_(test_case3) {
    }
  };
}

void test_(one_test_two_test_cases_and_one_ignore_test_case_tests, test_output) {
  auto [output, result] = run_test_("xtd::tunit::tests::one_test_two_test_cases_and_one_ignore_test_case_tests.*");
  assert_value_("Start 3 tests from 1 test case\n"
    "  SUCCEED xtd::tunit::tests::one_test_two_test_cases_and_one_ignore_test_case_tests.test_case1\n"
    "  SUCCEED xtd::tunit::tests::one_test_two_test_cases_and_one_ignore_test_case_tests.test_case2\n"
    "  IGNORED xtd::tunit::tests::one_test_two_test_cases_and_one_ignore_test_case_tests.test_case3\n"
    "    Test ignored\n"
    "End 3 tests from 1 test case ran.\n", output);
}

void test_(one_test_two_test_cases_and_one_ignore_test_case_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::one_test_two_test_cases_and_one_ignore_test_case_tests.*");
  assert_value_(0, result);
}
