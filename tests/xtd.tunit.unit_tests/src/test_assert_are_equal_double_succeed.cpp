#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_assert_are_equal_double_succeed) {
  public:
    void test_method_(test_case_succeed) {
      double d = 0.2;
      xtd::tunit::assert::are_equal(0.2, d, xtd::tunit::line_info {"test_assert_are_equal_double_succeed.cpp", 9});
    }
  };
}

void test_(test_assert_are_equal_double_succeed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_are_equal_double_succeed\n"
                "    SUCCEED test_case_succeed\n"
                "  End 1 test from test_assert_are_equal_double_succeed\n"
                "\n"
                "  Summary :\n"
                "    SUCCEED 1 test.\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_are_equal_double_succeed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_double_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(0, result);
}
