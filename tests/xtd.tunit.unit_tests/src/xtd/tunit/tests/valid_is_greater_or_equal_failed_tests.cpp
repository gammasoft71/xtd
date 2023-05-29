#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_is_greater_or_equal_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      int i = 42;
      xtd::tunit::valid::is_greater_or_equal(i, 84);
    }
  };
}

void test_(valid_is_greater_or_equal_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("valid_is_greater_or_equal_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_is_greater_or_equal_failed_tests.test_case_failed\n"
    "    Expected: greater than or equal to 84\n"
    "    But was:  42\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(valid_is_greater_or_equal_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("valid_is_greater_or_equal_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
