#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(assert_does_not_throw_succeed_tests) {
  public:
    auto test_method_(test_case_succeed) {
      auto a = array {1, 2, 3, 4};
      xtd::tunit::assert::does_not_throw([&] {a[2];});
    }
  };
  
  void test_(assert_does_not_throw_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_does_not_throw_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::tests::assert_does_not_throw_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_does_not_throw_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_does_not_throw_succeed_tests.*");
    assert_value_(0, result);
  }
}
