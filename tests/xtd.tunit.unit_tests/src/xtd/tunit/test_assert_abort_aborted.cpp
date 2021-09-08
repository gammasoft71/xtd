#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test_assert_abort_aborted) {
  public:
    void test_method_(test_case_aborted) {
      xtd::tunit::assert::abort(xtd::diagnostics::stack_frame {"test_assert_abort_aborted.cpp", 8});
    }
  };
}

void test_(test_assert_abort_aborted, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_abort_aborted.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  ABORTED test_assert_abort_aborted.test_case_aborted\n"
                "    Test aborted\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_abort_aborted, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_abort_aborted.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
