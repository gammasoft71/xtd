#include "assert_unit_tests.hpp"
#include <xtd/tunit>


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
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases_and_one_ignore_test_case.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 3 tests from 1 test case\n"
                "  Start 3 tests from one_test_two_test_cases_and_one_ignore_test_case\n"
                "    SUCCEED test_case1\n"
                "    SUCCEED test_case2\n"
                "  End 3 tests from one_test_two_test_cases_and_one_ignore_test_case\n"
                "\n"
                "  Summary :\n"
                "    IGNORED 1 test, listed below:\n"
                "    IGNORED one_test_two_test_cases_and_one_ignore_test_case.test_case3\n"
                "\n"
                "    SUCCEED 2 tests.\n"
                "    IGNORED 1 test.\n"
                "End 3 tests from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(one_test_two_test_cases_and_one_ignore_test_case, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases_and_one_ignore_test_case.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
