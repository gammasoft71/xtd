#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(valid_are_equal_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int i = 24;
      xtd::tunit::valid::are_equal(24, i);
    }
  };
}

void test_(valid_are_equal_succeed_tests, test_output) {
  auto [output, result] = run_test_("valid_are_equal_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_are_equal_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_are_equal_succeed_tests, test_result) {
  auto [output, result] = run_test_("valid_are_equal_succeed_tests.*");
  assert_value_(0, result);
}
