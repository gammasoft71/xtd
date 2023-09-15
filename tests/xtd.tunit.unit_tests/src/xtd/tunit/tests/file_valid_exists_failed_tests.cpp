#include <xtd/tunit/file_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

namespace xtd::tunit::tests {
  class test_class_(file_valid_exists_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      file_valid::exists(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
    }
  };
}

void test_(file_valid_exists_failed_tests, test_output) {
  auto [output, result] = run_test_("file_valid_exists_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  file_valid_exists_failed_tests.test_case_failed\n"
      "    Expected: file exists\n"
      "    But was:  {}\n"
      "End 1 test from 1 test case ran.\n", std::quoted(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"))), output);
}

void test_(file_valid_exists_failed_tests, test_result) {
  auto [output, result] = run_test_("file_valid_exists_failed_tests.*");
  assert_value_(1, result);
}
