#include "assert_unit_tests.hpp"
#include <xtd/tunit>


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
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 2 tests from 1 test case\n"
                "  Start 2 tests from one_test_two_test_cases\n"
                "    SUCCEED test_case1\n"
                "    SUCCEED test_case2\n"
                "  End 2 tests from one_test_two_test_cases\n"
                "\n"
                "  Summary :\n"
                "    SUCCEED 2 tests.\n"
                "End 2 tests from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(one_test_two_test_cases, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
