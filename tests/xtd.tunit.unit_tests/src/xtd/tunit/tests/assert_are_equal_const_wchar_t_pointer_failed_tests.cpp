#include "assert_unit_tests.hpp"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assert_are_equal_const_wchar_t_pointer_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      const wchar* s = L"string";
      xtd::tunit::assert::are_equal(L"str", s);
    }
  };
}

void test_(assert_are_equal_const_wchar_t_pointer_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_are_equal_const_wchar_t_pointer_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_are_equal_const_wchar_t_pointer_failed_tests.test_case_failed\n"
    "    Expected: \"str\"\n"
    "    But was:  \"string\"\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(assert_are_equal_const_wchar_t_pointer_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("assert_are_equal_const_wchar_t_pointer_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
