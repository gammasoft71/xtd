#include <xtd/tunit/file_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/typeof>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(file_assert_are_not_equal_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), "Test xtd::tunit::file_assert::are_not_equal.");
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), "Test xtd::tunit::file_assert::are_not_equal.");
      
      file_assert::are_not_equal(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), csf_);
      
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"));
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"));
    }
  };
}

void test_(file_assert_are_not_equal_string_failed_tests, test_output) {
  auto [output, result] = run_test_("file_assert_are_not_equal_string_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  file_assert_are_not_equal_string_failed_tests.test_case_failed\n"
      "    Expected: not equal <{0}>\n"
      "    But was:  <{0}>\n"
      "End 1 test from 1 test case ran.\n", typeof_<std::ifstream>()), output);
}

void test_(file_assert_are_not_equal_string_failed_tests, test_result) {
  auto [output, result] = run_test_("file_assert_are_not_equal_string_failed_tests.*");
  assert_value_(1, result);
}
