#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>

std::vector<assert_unit_tests::register_assert_unit_test> assert_unit_tests::register_assert_unit_test::assert_unit_tests;
size_t assert_unit_tests::register_assert_unit_test::ignore_test_count = 0;
extern bool __tunit_unit_tests_mode__;

int main() {
  __tunit_unit_tests_mode__ = true;
  return assert_unit_tests::register_assert_unit_test::run_all_tests();
}

