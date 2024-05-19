#include <xtd/tunit/test>
#include "assert_unit_tests/assert_unit_tests.h"

auto main() -> int {
  xtd::system_exception::enable_stack_trace(false);
  xtd::tunit::test::__internal_tunit_unit_tests_mode__ = reinterpret_cast<xtd::intptr>("internal_tests");
  return assert_unit_tests::register_assert_unit_test::run_all_tests();
}
