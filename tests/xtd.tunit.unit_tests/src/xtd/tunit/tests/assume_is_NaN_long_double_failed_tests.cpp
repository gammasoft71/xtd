#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(assume_is_NaN_long_double_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      long double ld = 3.14159l;
      xtd::tunit::assume::is_NaN(ld);
    }
  };
  
  void test_(assume_is_NaN_long_double_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::assume_is_NaN_long_double_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  ABORTED xtd::tunit::tests::assume_is_NaN_long_double_failed_tests.test_case_failed\n"
                  "    Test aborted\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assume_is_NaN_long_double_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::assume_is_NaN_long_double_failed_tests.*");
    assert_value_(0, result);
  }
}
