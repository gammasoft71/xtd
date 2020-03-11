#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test_assert_is_not_zero_failed) {
  public:
    void test_method_(test_case_failed) {
      int i = 0;
      xtd::tunit::assert::is_not_zero(i);
    }
  };
}

void test_(test_assert_is_not_zero_failed, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_zero_failed.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_assert_is_not_zero_failed.test_case_failed\n"
                "    Expected: not zero\n"
                "    But was:  0\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_not_zero_failed, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_zero_failed.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
