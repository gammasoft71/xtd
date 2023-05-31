#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assume_are_equal_const_char_pointer_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      const char* s = "string";
      xtd::tunit::assume::are_equal("string", s);
    }
  };
}

void test_(assume_are_equal_const_char_pointer_succeed_tests, test_output) {
  auto [result, output] = run_test_("assume_are_equal_const_char_pointer_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assume_are_equal_const_char_pointer_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_are_equal_const_char_pointer_succeed_tests, test_result) {
  auto [result, output] = run_test_("assume_are_equal_const_char_pointer_succeed_tests.*");
  assert_value_(0, result);
}
