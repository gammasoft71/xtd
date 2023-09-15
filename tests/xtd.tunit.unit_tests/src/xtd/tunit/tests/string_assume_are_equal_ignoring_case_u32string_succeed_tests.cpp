#include <xtd/tunit/string_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(string_assume_are_equal_ignoring_case_u32string_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::u32string s = U"VALUE";
      xtd::tunit::string_assume::are_equal_ignoring_case(U"value", s);
    }
  };
}

void test_(string_assume_are_equal_ignoring_case_u32string_succeed_tests, test_output) {
  auto [output, result] = run_test_("string_assume_are_equal_ignoring_case_u32string_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED string_assume_are_equal_ignoring_case_u32string_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(string_assume_are_equal_ignoring_case_u32string_succeed_tests, test_result) {
  auto [output, result] = run_test_("string_assume_are_equal_ignoring_case_u32string_succeed_tests.*");
  assert_value_(0, result);
}
