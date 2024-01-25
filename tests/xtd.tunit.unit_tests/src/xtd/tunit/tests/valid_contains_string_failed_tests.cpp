#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <string>

namespace xtd::tunit::tests {
  class test_class_(valid_contains_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::string s = "string";
      xtd::tunit::valid::contains('a', s);
    }
  };
  
  void test_(valid_contains_string_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_contains_string_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  FAILED  xtd::tunit::tests::valid_contains_string_failed_tests.test_case_failed\n"
                  "    Expected: collection containing a\n"
                  "    But was:  < 's', 't', 'r', 'i', 'n', 'g' >\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(valid_contains_string_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_contains_string_failed_tests.*");
    assert_value_(1, result);
  }
}
