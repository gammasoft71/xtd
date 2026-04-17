#include "register_assert_unit_test.hpp"

std::vector<assert_unit_tests::register_assert_unit_test> assert_unit_tests::register_assert_unit_test::assert_unit_tests;
xtd::usize assert_unit_tests::register_assert_unit_test::error_test_count = 0;
xtd::usize assert_unit_tests::register_assert_unit_test::ignore_test_count = 0;
