#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(collection_assert_is_empty_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_assert::is_empty(a);
    }
  };
}

void test_(collection_assert_is_empty_vector_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_is_empty_vector_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  collection_assert_is_empty_vector_failed_tests.test_case_failed\n"
    "    Expected: <empty>\n"
    "    But was:  < 1, 2, 3, 4 >\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(collection_assert_is_empty_vector_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_is_empty_vector_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
