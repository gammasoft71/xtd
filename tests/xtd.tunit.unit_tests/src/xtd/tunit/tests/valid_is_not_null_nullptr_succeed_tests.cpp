#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(valid_is_noot_null_nullptr_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int i = 0;
      int* p = &i;
      xtd::tunit::valid::is_not_null(p);
    }
  };
  
  void test_(valid_is_noot_null_nullptr_succeed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_is_noot_null_nullptr_succeed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  SUCCEED xtd::tunit::tests::valid_is_noot_null_nullptr_succeed_tests.test_case_succeed\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(valid_is_noot_null_nullptr_succeed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_is_noot_null_nullptr_succeed_tests.*");
    assert_value_(0, result);
  }
}
