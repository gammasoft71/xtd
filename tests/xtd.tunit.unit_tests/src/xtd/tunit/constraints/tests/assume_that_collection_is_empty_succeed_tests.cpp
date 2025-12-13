#include <xtd/tunit/constraints/assume_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"
#include <vector>

namespace xtd::tunit::constraints::tests {
  class test_class_(assume_that_collection_is_empty_succeed_tests) {
  public:
    auto test_method_(test_case_succeed) {
      auto v = array<int> {};
      xtd::tunit::assume::is_empty(v);
    }
  };
  
  void test_(assume_that_collection_is_empty_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assume_that_collection_is_empty_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::constraints::tests::assume_that_collection_is_empty_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assume_that_collection_is_empty_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assume_that_collection_is_empty_succeed_tests.*");
    assert_value_(0, result);
  }
}
