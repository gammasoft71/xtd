#include "assert_unit_tests.hpp"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_is_not_null_nullptr_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      xtd::tunit::assert::is_not_null(nullptr);
    }
  };
}

void test_(assert_is_not_null_nullptr_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_is_not_null_nullptr_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  assert_is_not_null_nullptr_failed_tests.test_case_failed\n"
                "    Expected: not null\n"
                "    But was:  null\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(assert_is_not_null_nullptr_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_is_not_null_nullptr_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
