#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(valid_is_not_empty_collection_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> v;
      xtd::tunit::valid::is_not_empty(v);
    }
  };
  
  void test_(valid_is_not_empty_collection_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_is_not_empty_collection_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  FAILED  xtd::tunit::tests::valid_is_not_empty_collection_failed_tests.test_case_failed\n"
                  "    Expected: collection not <empty>\n"
                  "    But was:  <empty>\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(valid_is_not_empty_collection_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::valid_is_not_empty_collection_failed_tests.*");
    assert_value_(1, result);
  }
}
