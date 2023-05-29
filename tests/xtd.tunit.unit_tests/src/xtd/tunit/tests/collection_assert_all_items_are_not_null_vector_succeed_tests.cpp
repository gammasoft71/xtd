#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(collection_assert_all_items_are_not_null_vector_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int i1 = 0, i2 = 3;
      std::vector<int*> a = {&i1, &i2};
      xtd::tunit::collection_assert::all_items_are_not_null(a);
    }
  };
}

void test_(collection_assert_all_items_are_not_null_vector_succeed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_all_items_are_not_null_vector_succeed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED collection_assert_all_items_are_not_null_vector_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(collection_assert_all_items_are_not_null_vector_succeed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_all_items_are_not_null_vector_succeed_tests.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
