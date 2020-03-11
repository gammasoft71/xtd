#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>


namespace unit_tests {
  class test_class_(one_test_two_test_cases) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
  };
}

void test_(one_test_two_test_cases, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 2 tests from 1 test case\n"
                "  SUCCEED one_test_two_test_cases.test_case1\n"
                "  SUCCEED one_test_two_test_cases.test_case2\n"
                "End 2 tests from 1 test case ran.\n", ss.str());
}

void test_(one_test_two_test_cases, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
