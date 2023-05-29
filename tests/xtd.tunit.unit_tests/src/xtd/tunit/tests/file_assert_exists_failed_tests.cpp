#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_exists_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      file_assert::exists(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
    }
  };
}

void test_(file_assert_exists_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("file_assert_exists_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
    "  FAILED  file_assert_exists_failed_tests.test_case_failed\n"
    "    Expected: file exists\n"
    "    But was:  \"{}\"\n"
    "End 1 test from 1 test case ran.\n", std::quoted(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"))), ss.str());
}

void test_(file_assert_exists_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("file_assert_exists_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
