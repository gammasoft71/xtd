#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <stdexcept>

namespace xtd::tunit::tests {
  class test_class_(assert_is_instance_of_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::invalid_argument e("invalid argument");
      xtd::tunit::assert::is_instance_of<std::bad_cast>(e);
    }
  };
}

void test_(assert_is_instance_of_failed_tests, test_output) {
  auto [output, result] = run_test_("assert_is_instance_of_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_is_instance_of_failed_tests.test_case_failed\n"
    "    Expected: instance of <std::bad_cast>\n"
    "    But was:  <std::invalid_argument>\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_is_instance_of_failed_tests, test_result) {
  auto [output, result] = run_test_("assert_is_instance_of_failed_tests.*");
  assert_value_(1, result);
}
