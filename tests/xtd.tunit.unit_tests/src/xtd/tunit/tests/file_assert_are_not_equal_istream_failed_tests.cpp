#include <xtd/tunit/file_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/typeof>
#include "../../../assert_unit_tests/assert_unit_tests.h"

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
  auto [output, result] = run_test_("xtd::tunit::tests::file_assert_are_not_equal_istream_failed_tests.*");
  assert_value_(xtd::ustring::format("Start 1 test from 1 test case\n"
      "  FAILED  xtd::tunit::tests::file_assert_are_not_equal_istream_failed_tests.test_case_failed\n"
      "    Expected: not equal <{0}>\n"
      "    But was:  <{0}>\n"
      "End 1 test from 1 test case ran.\n", typeof_<std::istringstream>()), output);
}

void test_(file_assert_are_not_equal_istream_failed_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::file_assert_are_not_equal_istream_failed_tests.*");
  assert_value_(1, result);
}
