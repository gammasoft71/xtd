#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(directory_assert_does_not_exist_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      auto d = environment::get_folder_path(environment::special_folder::common_application_data);
      xtd::tunit::directory_assert::does_not_exist(d);
    }
  };
}

void test_(directory_assert_does_not_exist_string_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("directory_assert_does_not_exist_string_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  #if defined (_WIN32)
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  directory_assert_does_not_exist_string_failed_tests.test_case_failed\n"
    "    Expected: not directory exists\n"
    "    But was:  \"C:\\ProgramData\"\n"
    "End 1 test from 1 test case ran.\n", ss.str());
  #else
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  directory_assert_does_not_exist_string_failed_tests.test_case_failed\n"
    "    Expected: not directory exists\n"
    "    But was:  \"/usr/share\"\n"
    "End 1 test from 1 test case ran.\n", ss.str());
  #endif
}

void test_(directory_assert_does_not_exist_string_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("directory_assert_does_not_exist_string_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
