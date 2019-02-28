#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <limits>

namespace unit_tests {
  class test_class_(test_assert_is_NaN_double_succeed) {
  public:
    void test_method_(test_case_succeed) {
      double d = std::numeric_limits<double>::quiet_NaN();
      xtd::tunit::assert::is_NaN(d, xtd::tunit::line_info {"test_assert_is_NaN_double_succeed.cpp", 10});
    }
  };
}

void test_(test_assert_is_NaN_double_succeed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_NaN_double_succeed.*");
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_assert_is_NaN_double_succeed.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_NaN_double_succeed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_NaN_double_succeed.*");
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(0, result);
}
