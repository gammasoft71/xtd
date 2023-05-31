#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(string_assert_are_equal_ignoring_case_uwstring_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::wstring s = L"VALUE";
      xtd::tunit::string_assert::are_equal_ignoring_case(L"key", s);
    }
  };
}

void test_(string_assert_are_equal_ignoring_case_uwstring_failed_tests, test_output) {
  auto [result, output] = run_test_("string_assert_are_equal_ignoring_case_uwstring_failed_tests*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  string_assert_are_equal_ignoring_case_uwstring_failed_tests.test_case_failed\n"
    "    Expected: \"key\", ignoring case\n"
    "    But was:  \"VALUE\"\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(string_assert_are_equal_ignoring_case_uwstring_failed_tests, test_result) {
  auto [result, output] = run_test_("string_assert_are_equal_ignoring_case_uwstring_failed_tests*");
  assert_value_(1, result);
}
