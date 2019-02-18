#include "assert_unit_tests.hpp"
#include <xtd/tunit>


namespace unit_tests {
  class test_class_(two_tests_five_test_cases_1) {
  public:
    void test_method_(test_case1) {
    }
    void test_method_(test_case2) {
    }
  };

  class test_class_(two_tests_five_test_cases_2) {
  public:
    void test_method_(test_case3) {
    }
    void test_method_(test_case4) {
    }
    void test_method_(test_case5) {
    }
  };
}

void test_(two_tests_five_test_cases, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().filter_tests("two_tests_five_test_cases_?.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 5 tests from 2 test cases\n"
                "  Start 2 tests from two_tests_five_test_cases_1\n"
                "    PASSED test_case1\n"
                "    PASSED test_case2\n"
                "  End 2 tests from two_tests_five_test_cases_1\n"
                "  Start 3 tests from two_tests_five_test_cases_2\n"
                "    PASSED test_case3\n"
                "    PASSED test_case4\n"
                "    PASSED test_case5\n"
                "  End 3 tests from two_tests_five_test_cases_2\n"
                "\n"
                "  Summary :\n"
                "    PASSED 5 tests.\n"
                "End 5 tests from 2 test cases ran.\n"
                "\n", ss.str());
}

void test_(two_tests_five_test_cases, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().filter_tests("two_tests_two_test_cases_?.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
