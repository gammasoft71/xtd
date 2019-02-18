#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(one_test_one_test_case) {
  public:
    void test_method_(test_case1) {
    }
  };
}

void test_(one_test_one_test_case, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().filter_tests("one_test_one_test_case.*");
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from one_test_one_test_case\n"
                "    PASSED test_case1 (0 ms total)\n"
                "  End 1 test from one_test_one_test_case (0 ms total)\n"
                "\n"
                "  Summary :\n"
                "    PASSED 1 tests.\n"
                "End 1 test from 1 test case ran. (0 ms total)\n"
                "\n", ss.str());
}

void test_(one_test_one_test_case, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().filter_tests("one_test_one_test_case.*");
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(0, result);
}
