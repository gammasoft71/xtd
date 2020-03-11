#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>


namespace unit_tests {
  class test_class_(two_tests_five_test_cases_1) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
  };

  class test_class_(two_tests_five_test_cases_2) {
  public:
    void test_method_(test_case3) {
    }
    void test_method_(test_case4) {
    }
    void test_method_(test_case5) {
    }
  };
}

void test_(two_tests_five_test_cases, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("two_tests_five_test_cases_?.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 5 tests from 2 test cases\n"
                "  SUCCEED two_tests_five_test_cases_1.test_case1\n"
                "  SUCCEED two_tests_five_test_cases_1.test_case2\n"
                "  SUCCEED two_tests_five_test_cases_2.test_case3\n"
                "  SUCCEED two_tests_five_test_cases_2.test_case4\n"
                "  SUCCEED two_tests_five_test_cases_2.test_case5\n"
                "End 5 tests from 2 test cases ran.\n", ss.str());
}

void test_(two_tests_five_test_cases, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("two_tests_two_test_cases_?.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
