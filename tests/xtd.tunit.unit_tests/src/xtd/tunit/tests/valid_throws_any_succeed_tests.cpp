#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(valid_throws_any_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::valid::throws_any([&] {v.at(5);});
    }
  };
}

void test_(valid_throws_any_succeed_tests, test_output) {
  auto [result, output] = run_test_("valid_throws_any_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_throws_any_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_throws_any_succeed_tests, test_result) {
  auto [result, output] = run_test_("valid_throws_any_succeed_tests.*");
  assert_value_(0, result);
}
