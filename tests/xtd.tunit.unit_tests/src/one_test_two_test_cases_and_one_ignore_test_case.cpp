#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>


namespace unit_tests {
  class test_class_(one_test_two_test_cases_and_one_ignore_test_case) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
    void ignore_test_method_(test_case3) {
    }
  };
}

void test_(one_test_two_test_cases_and_one_ignore_test_case, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases_and_one_ignore_test_case.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 3 tests from 1 test case\n"
                "  SUCCEED one_test_two_test_cases_and_one_ignore_test_case.test_case1\n"
                "  SUCCEED one_test_two_test_cases_and_one_ignore_test_case.test_case2\n"
                "  IGNORED one_test_two_test_cases_and_one_ignore_test_case.test_case3\n"
                "    Test ignored\n"
                "End 3 tests from 1 test case ran.\n", ss.str());
}

void test_(one_test_two_test_cases_and_one_ignore_test_case, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases_and_one_ignore_test_case.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
