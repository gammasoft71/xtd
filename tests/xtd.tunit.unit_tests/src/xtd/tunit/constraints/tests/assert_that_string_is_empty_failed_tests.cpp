#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"
#include <string>

namespace xtd::tunit::constraints::tests {
  class test_class_(assert_that_string_is_empty_failed_tests) {
  public:
    auto test_method_(test_case_failed) {
      auto s = "string";
      xtd::tunit::constraints::assert_that(s).is().empty();
    }
  };
  
  void test_(assert_that_string_is_empty_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_string_is_empty_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::constraints::tests::assert_that_string_is_empty_failed_tests.test_case_failed\n"
                  "    Expected: collection <empty>\n"
                  "    But was:  < s, t, r, i, n, g >\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_that_string_is_empty_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_string_is_empty_failed_tests.*");
    assert_value_(1, result);
  }
}
