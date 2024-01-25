#include <xtd/tunit/directory_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

#if defined(__cpp_lib_filesystem)
namespace xtd::tunit::tests {
  class test_class_(directory_valid_are_equal_filesystem_directory_entry_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::filesystem::directory_entry d1(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()));
      std::filesystem::directory_entry d2(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).c_str()) / "subdir");
      xtd::tunit::directory_valid::are_equal(d1, d2);
    }
  };
}

void test_(directory_valid_are_equal_filesystem_directory_entry_failed_tests, test_output) {
  auto [output, result] = run_test_("xtd::tunit::tests::directory_valid_are_equal_filesystem_directory_entry_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  xtd::tunit::tests::directory_valid_are_equal_filesystem_directory_entry_failed_tests.test_case_failed\n"
      "    Expected: {0}\n"
      "    But was:  {1}\n"
      "End 1 test from 1 test case ran.\n", xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data).quoted(), xtd::io::path::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data), "subdir").quoted()), output);
}

void test_(directory_valid_are_equal_filesystem_directory_entry_failed_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::directory_valid_are_equal_filesystem_directory_entry_failed_tests.*");
  assert_value_(1, result);
}
#endif
