#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(assume_are_equal_double_with_tolerence_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      double d = 0.599;
      xtd::tunit::assume::are_equal(0.6, d, 0.001);
    }
  };
}

void test_(assume_are_equal_double_with_tolerence_failed_tests, test_output) {
  auto [output, result] = run_test_("assume_are_equal_double_with_tolerence_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assume_are_equal_double_with_tolerence_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_are_equal_double_with_tolerence_failed_tests, test_result) {
  auto [output, result] = run_test_("assume_are_equal_double_with_tolerence_failed_tests.*");
  assert_value_(0, result);
}
