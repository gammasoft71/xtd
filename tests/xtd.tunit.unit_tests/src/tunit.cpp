#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
    }
  };
}

void test_(simple_test_class, test_output) {
  std::stringstream ss;
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test\n"
                "    PASSED test_case1 (0 ms total)\n"
                "  End 1 test from test (0 ms total)\n"
                "\n"
                "  Summary :\n"
                "    PASSED 1 tests.\n"
                "End 1 test from 1 test case ran. (0 ms total)\n"
                "\n", ss.str());
}

void test_(simple_test_class, test_result) {
  std::stringstream ss;
  int result = xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_(0, result);
}
