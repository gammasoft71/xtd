#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(string_assert_are_equal_ignoring_case_u16string_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::u16string s = u"VALUE";
      xtd::tunit::string_assert::are_equal_ignoring_case(u"value", s);
    }
  };
}

void test_(string_assert_are_equal_ignoring_case_u16string_succeed_tests, test_output) {
  auto [result, output] = run_test_("string_assert_are_equal_ignoring_case_u16string_succeed_tests*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED string_assert_are_equal_ignoring_case_u16string_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(string_assert_are_equal_ignoring_case_u16string_succeed_tests, test_result) {
  auto [result, output] = run_test_("string_assert_are_equal_ignoring_case_u16string_succeed_tests*");
  assert_value_(0, result);
}
