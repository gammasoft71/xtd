#include <xtd/tunit/directory_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

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
  auto [output, result] = run_test_("xtd::tunit::tests::directory_assert_does_not_exist_string_failed_tests.*");
  #if defined (_WIN32)
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  xtd::tunit::tests::directory_assert_does_not_exist_string_failed_tests.test_case_failed\n"
    "    Expected: not directory exists\n"
    "    But was:  \"C:\\ProgramData\"\n"
    "End 1 test from 1 test case ran.\n", output);
  #else
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  xtd::tunit::tests::directory_assert_does_not_exist_string_failed_tests.test_case_failed\n"
    "    Expected: not directory exists\n"
    "    But was:  \"/usr/share\"\n"
    "End 1 test from 1 test case ran.\n", output);
  #endif
}

void test_(directory_assert_does_not_exist_string_failed_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::directory_assert_does_not_exist_string_failed_tests.*");
  assert_value_(1, result);
}
