#include <xtd/tunit/string_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(string_valid_are_equal_ignoring_case_wstring_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::wstring s = L"VALUE";
      xtd::tunit::string_valid::are_equal_ignoring_case(L"value", s);
    }
  };
  
  void test_(string_valid_are_equal_ignoring_case_wstring_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::string_valid_are_equal_ignoring_case_wstring_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::tests::string_valid_are_equal_ignoring_case_wstring_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(string_valid_are_equal_ignoring_case_wstring_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::string_valid_are_equal_ignoring_case_wstring_succeed_tests.*");
    assert_value_(0, result);
  }
}
