#include <xtd/tunit/collection_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(collection_valid_all_items_are_unqiue_vector_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_valid::all_items_are_unique(a);
    }
  };
}

void test_(collection_valid_all_items_are_unqiue_vector_succeed_tests, test_output) {
  auto [output, result] = run_test_("collection_valid_all_items_are_unqiue_vector_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED collection_valid_all_items_are_unqiue_vector_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(collection_valid_all_items_are_unqiue_vector_succeed_tests, test_result) {
  auto [output, result] = run_test_("collection_valid_all_items_are_unqiue_vector_succeed_tests.*");
  assert_value_(0, result);
}
