#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(assume_are_equal_float_NaN_tests) {
  public:
    void test_method_(test_case_succeed) {
      float f = std::numeric_limits<float>::quiet_NaN();
      xtd::tunit::assume::are_equal(std::numeric_limits<float>::quiet_NaN(), f);
    }
  };
}

void test_(assume_are_equal_float_NaN_tests, test_output) {
  auto [output, result] = run_test_("xtd::tunit::tests::assume_are_equal_float_NaN_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED xtd::tunit::tests::assume_are_equal_float_NaN_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_are_equal_float_NaN_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::assume_are_equal_float_NaN_tests.*");
  assert_value_(0, result);
}
