#include <xtd/tunit/file_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(file_assume_are_equal_string_failed_tests) {
  public:
    void test_method_(test_case_lenght_failed) {
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), "Test xtd::tunit::file_assume::are_equl.");
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), "Test xtd::tunit::file_assume::are_equal.");
      
      file_assume::are_equal(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), csf_);
      
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"));
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"));
    }
    
    void test_method_(test_case_letter_failed) {
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), "Test xtd::tunit::Dile_assert::are_equal.");
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), "Test xtd::tunit::file_assume::are_equal.");
      
      file_assume::are_equal(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"), xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"), csf_);
      
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file1.txt"));
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file2.txt"));
    }
  };
}

void test_(file_assume_are_equal_string_failed_tests, test_output) {
  auto [output, result] = run_test_("file_assume_are_equal_string_failed_tests.*");
  assert_value_("Start 2 tests from 1 test case\n"
    "  ABORTED file_assume_are_equal_string_failed_tests.test_case_lenght_failed\n"
    "    Test aborted\n"
    "  ABORTED file_assume_are_equal_string_failed_tests.test_case_letter_failed\n"
    "    Test aborted\n"
    "End 2 tests from 1 test case ran.\n", output);
}

void test_(file_assume_are_equal_string_failed_tests, test_result) {
  auto [output, result] = run_test_("file_assume_are_equal_string_failed_tests.*");
  assert_value_(0, result);
}
