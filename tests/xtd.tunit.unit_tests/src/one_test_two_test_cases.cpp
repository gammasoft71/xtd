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
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 2 tests from 1 test case\n"
                "  Start 2 tests from one_test_two_test_cases\n"
                "    PASSED test_case1 (0 ms total)\n"
                "    PASSED test_case2 (0 ms total)\n"
                "  End 2 tests from one_test_two_test_cases (0 ms total)\n"
                "\n"
                "  Summary :\n"
                "    PASSED 2 tests.\n"
                "End 2 tests from 1 test case ran. (0 ms total)\n"
                "\n", ss.str());
}

void test_(one_test_two_test_cases, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().filter_tests("one_test_two_test_cases.*");
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
