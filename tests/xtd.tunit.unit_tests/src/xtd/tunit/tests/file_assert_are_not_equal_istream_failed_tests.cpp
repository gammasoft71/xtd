#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_are_not_equal_istream_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      // As the xtd::tunit::file_assert::are_not_equal method uses std::istream and not std::ifstream, the test can be performed with std::istringstream.
      xtd::tunit::file_assert::are_not_equal(std::istringstream("Test xtd::tunit::file_assert::are_not_equal."), std::istringstream("Test xtd::tunit::file_assert::are_not_equal."));
    }
  };
}

void test_(file_assert_are_not_equal_istream_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("file_assert_are_not_equal_istream_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
    "  FAILED  file_assert_are_not_equal_istream_failed_tests.test_case_failed\n"
    "    Expected: not equal <{0}>\n"
    "    But was:  <{0}>\n"
    "End 1 test from 1 test case ran.\n", xtd::ustring::full_class_name<std::istringstream>()), ss.str());
}

void test_(file_assert_are_not_equal_istream_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("file_assert_are_not_equal_istream_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
