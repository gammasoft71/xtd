#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(assume_are_same_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int a = 24;
      int& b = a;
      xtd::tunit::assume::are_same(b, a);
    }
  };
  
  void test_(assume_are_same_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::assume_are_same_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::tests::assume_are_same_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assume_are_same_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::assume_are_same_succeed_tests.*");
    assert_value_(0, result);
  }
}
