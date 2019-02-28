#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <vector>

namespace unit_tests {
  class test_class_(test_assert_is_not_empty_collection_failed) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> v;
      xtd::tunit::assert::is_not_empty(v, xtd::tunit::line_info {"test_assert_is_not_empty_collection_failed.cpp", 10});
    }
  };
}

void test_(test_assert_is_not_empty_collection_failed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_empty_collection_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_is_not_empty_collection_failed\n"
                "    FAILED  test_case_failed\n"
                "\n"
                "Expected: collection not <empty>\n"
                "But was:  <empty>\n"
                "error: test_assert_is_not_empty_collection_failed.cpp:10\n"
                "\n"
                "  End 1 test from test_assert_is_not_empty_collection_failed\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_is_not_empty_collection_failed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_empty_collection_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(1, result);
}
