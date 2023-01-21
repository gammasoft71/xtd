#include "xtd/tunit/tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

std::vector<assert_unit_tests::register_assert_unit_test> assert_unit_tests::register_assert_unit_test::assert_unit_tests;
size_t assert_unit_tests::register_assert_unit_test::ignore_test_count = 0;

auto main()->int {
  xtd::system_exception::enable_stack_trace(false);
  xtd::tunit::test::__internal_tunit_unit_tests_mode__ = reinterpret_cast<xtd::intptr>("internal_tests");
  return assert_unit_tests::register_assert_unit_test::run_all_tests();
}

