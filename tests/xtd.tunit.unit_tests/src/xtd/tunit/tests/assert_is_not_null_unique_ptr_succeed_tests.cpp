#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <memory>

namespace xtd::tunit::tests {
  class test_class_(assert_is_not_null_unique_ptr_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::unique_ptr<int> p = std::make_unique<int>(42);
      xtd::tunit::assert::is_not_null(p);
    }
  };
}

void test_(assert_is_not_null_unique_ptr_succeed_tests, test_output) {
  auto [output, result] = run_test_("xtd::tunit::tests::assert_is_not_null_unique_ptr_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED xtd::tunit::tests::assert_is_not_null_unique_ptr_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_is_not_null_unique_ptr_succeed_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::assert_is_not_null_unique_ptr_succeed_tests.*");
  assert_value_(0, result);
}
