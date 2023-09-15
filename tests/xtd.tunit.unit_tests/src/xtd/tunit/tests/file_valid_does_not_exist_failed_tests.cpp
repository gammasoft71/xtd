#include <xtd/tunit/file_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(file_valid_does_not_exist_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), "Test xtd::tunit::file_valid::does_not_exist.");
      
      file_valid::does_not_exist(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
    }
  };
}

void test_(file_valid_does_not_exist_failed_tests, test_output) {
  auto [output, result] = run_test_("file_valid_does_not_exist_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  file_valid_does_not_exist_failed_tests.test_case_failed\n"
      "    Expected: not file exists\n"
      "    But was:  {}\n"
      "End 1 test from 1 test case ran.\n", std::quoted(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"))), output);
      
  xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"));
}

void test_(file_valid_does_not_exist_failed_tests, test_result) {
  auto [output, result] = run_test_("file_valid_does_not_exist_failed_tests.*");
  assert_value_(1, result);
  
  xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"));
}
