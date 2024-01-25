#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(two_tests_five_test_cases_1_tests) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
  };
  
  class test_class_(two_tests_five_test_cases_2_tests) {
  public:
    void test_method_(test_case3) {
    }
    void test_method_(test_case4) {
    }
    void test_method_(test_case5) {
    }
  };
  
  class two_tests_five_test_cases {};
  
  void test_(two_tests_five_test_cases, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::two_tests_five_test_cases_*");
    assert_value_("Start 5 tests from 2 test cases\n"
                  "  SUCCEED xtd::tunit::tests::two_tests_five_test_cases_1_tests.test_case1\n"
                  "  SUCCEED xtd::tunit::tests::two_tests_five_test_cases_1_tests.test_case2\n"
                  "  SUCCEED xtd::tunit::tests::two_tests_five_test_cases_2_tests.test_case3\n"
                  "  SUCCEED xtd::tunit::tests::two_tests_five_test_cases_2_tests.test_case4\n"
                  "  SUCCEED xtd::tunit::tests::two_tests_five_test_cases_2_tests.test_case5\n"
                  "End 5 tests from 2 test cases ran.\n", output);
  }
  
  void test_(two_tests_five_test_cases, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::two_tests_five_test_cases_*");
    assert_value_(0, result);
  }
}
