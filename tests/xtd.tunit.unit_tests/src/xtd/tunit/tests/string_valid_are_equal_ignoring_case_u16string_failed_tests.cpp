#include <xtd/tunit/string_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(string_valid_are_equal_ignoring_case_u16string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::u16string s = u"VALUE";
      xtd::tunit::string_valid::are_equal_ignoring_case(u"key", s);
    }
  };
  
  void test_(string_valid_are_equal_ignoring_case_u16string_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::string_valid_are_equal_ignoring_case_u16string_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::tests::string_valid_are_equal_ignoring_case_u16string_failed_tests.test_case_failed\n"
                  "    Expected: \"key\", ignoring case\n"
                  "    But was:  \"VALUE\"\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(string_valid_are_equal_ignoring_case_u16string_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::string_valid_are_equal_ignoring_case_u16string_failed_tests.*");
    assert_value_(1, result);
  }
}
