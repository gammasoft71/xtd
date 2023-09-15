#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(assume_are_equal_long_double_with_tolerence_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      long double ld = 0.599l;
      xtd::tunit::assume::are_equal(0.6l, ld, 0.01l);
    }
  };
}

// fail on linux
void test_(assume_are_equal_long_double_with_tolerence_succeed_tests, test_output) {
  auto [output, result] = run_test_("assume_are_equal_long_double_with_tolerence_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assume_are_equal_long_double_with_tolerence_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_are_equal_long_double_with_tolerence_succeed_tests, test_result) {
  auto [output, result] = run_test_("assume_are_equal_long_double_with_tolerence_succeed_tests.*");
  assert_value_(0, result);
}
