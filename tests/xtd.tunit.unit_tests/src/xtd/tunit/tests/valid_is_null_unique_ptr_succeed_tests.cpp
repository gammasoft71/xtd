#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <memory>

namespace xtd::tunit::tests {
  class test_class_(valid_is_null_unique_ptr_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::unique_ptr<int> p;
      xtd::tunit::valid::is_null(p);
    }
  };
}

void test_(valid_is_null_unique_ptr_succeed_tests, test_output) {
  auto [output, result] = run_test_("valid_is_null_unique_ptr_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_is_null_unique_ptr_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_null_unique_ptr_succeed_tests, test_result) {
  auto [output, result] = run_test_("valid_is_null_unique_ptr_succeed_tests.*");
  assert_value_(0, result);
}
