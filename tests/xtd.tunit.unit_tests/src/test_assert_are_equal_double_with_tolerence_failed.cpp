#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_assert_are_equal_double_with_tolerence_failed) {
  public:
    void test_method_(test_case_failed) {
      double d = 0.599;
      xtd::tunit::assert::are_equal(0.6, d, 0.001, xtd::tunit::line_info {"test_assert_are_equal_double_with_tolerence_failed.cpp", 9});
    }
  };
}

void test_(test_assert_are_equal_double_with_tolerence_failed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_with_tolerence_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_are_equal_double_with_tolerence_failed\n"
                "    FAILED  test_case_failed\n"
                "\n"
                "Expected: 0.6\n"
                "But was:  0.599\n"
                "error: test_assert_are_equal_double_with_tolerence_failed.cpp:9\n"
                "\n"
                "  End 1 test from test_assert_are_equal_double_with_tolerence_failed\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_are_equal_double_with_tolerence_failed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_with_tolerence_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(1, result);
}
