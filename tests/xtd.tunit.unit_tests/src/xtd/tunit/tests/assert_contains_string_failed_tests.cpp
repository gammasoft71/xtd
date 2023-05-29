#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <string>

namespace xtd::tunit::tests {
  class test_class_(assert_contains_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::string s = "string";
      xtd::tunit::assert::contains('a', s);
    }
  };
}

void test_(assert_contains_string_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_contains_string_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_contains_string_failed_tests.test_case_failed\n"
    "    Expected: collection containing a\n"
    "    But was:  < 's', 't', 'r', 'i', 'n', 'g' >\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(assert_contains_string_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_contains_string_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
