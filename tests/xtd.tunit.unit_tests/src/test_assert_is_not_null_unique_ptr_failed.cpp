#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <memory>

namespace unit_tests {
  class test_class_(test_assert_is_not_null_unqiue_ptr_failed) {
  public:
    void test_method_(test_case_failed) {
      std::unique_ptr<int> p;
      xtd::tunit::assert::is_not_null(p, xtd::tunit::line_info {"test_assert_is_not_null_unqiue_ptr_failed.cpp", 10});
    }
  };
}

void test_(test_assert_is_not_null_unqiue_ptr_failed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_unqiue_ptr_failed.*");
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_assert_is_not_null_unqiue_ptr_failed.test_case_failed\n"
                "    Expected: not null\n"
                "    But was:  null\n"
                "    Stack trace: in test_assert_is_not_null_unqiue_ptr_failed.cpp:10\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_not_null_unqiue_ptr_failed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_unqiue_ptr_failed.*");
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
