#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(collection_assert_are_equivalent_vector_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a);
    }
  };
}

void test_(collection_assert_are_equivalent_vector_succeed_tests, test_output) {
  auto [result, output] = run_test_("collection_assert_are_equivalent_vector_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED collection_assert_are_equivalent_vector_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(collection_assert_are_equivalent_vector_succeed_tests, test_result) {
  auto [result, output] = run_test_("collection_assert_are_equivalent_vector_succeed_tests.*");
  assert_value_(0, result);
}
