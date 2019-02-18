#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_assert_are_equal) {
  public:
    void test_method_(test_case_succeed) {
      int i = 24;
      xtd::tunit::assert::are_equal(24, i, xtd::tunit::line_info {"test_assert_are_equal.cpp", 9});
    }
    
    void test_method_(test_case_failed) {
      int i = 24;
      xtd::tunit::assert::are_equal(23, i, xtd::tunit::line_info {"test_assert_are_equal.cpp", 14});
    }
  };
}

void test_(test_assert_are_equal, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 2 tests from 1 test case\n"
                "  Start 2 tests from test_assert_are_equal\n"
                "    PASSED test_case_succeed\n"
                "    FAILED test_case_failed\n"
                "\n"
                "Expected: 23\n"
                "But was:  24\n"
                "error: test_assert_are_equal.cpp:14\n"
                "\n"
                "  End 2 tests from test_assert_are_equal\n"
                "\n"
                "  Summary :\n"
                "    PASSED 1 tests.\n"
                "*** FAILED 1 test, listed below:\n"
                "*** FAILED test_assert_are_equal.test_case_failed\n"
                "\n"
                "    FAILED 1 tests.\n"
                "End 2 tests from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_are_equal, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(1, result);
}
