#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../../assert_unit_tests/assert_unit_tests.hpp"
#include <vector>

namespace xtd::tunit::constraints::tests {
  class test_class_(assert_that_collection_is_not_empty_succeed_testst) {
  public:
    auto test_method_(test_case_succeed) {
      auto a = array {0, 1, 2, 3};
      xtd::tunit::constraints::assert_that(a).is().not_().empty();
    }
  };
  
  void test_(assert_that_collection_is_not_empty_succeed_testst, test_output) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_collection_is_not_empty_succeed_testst.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::constraints::tests::assert_that_collection_is_not_empty_succeed_testst.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_that_collection_is_not_empty_succeed_testst, test_result) {
    auto [output, result] = run_test_("xtd::tunit::constraints::tests::assert_that_collection_is_not_empty_succeed_testst.*");
    assert_value_(0, result);
  }
}
