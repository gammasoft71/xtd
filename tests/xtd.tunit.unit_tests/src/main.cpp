#include "assert_unit_tests.hpp"
#include <xtd/tunit>

std::vector<assert_unit_tests::register_assert_unit_test> assert_unit_tests::register_assert_unit_test::assert_unit_tests;

int main(int argc, char* argv[]) {
  return assert_unit_tests::register_assert_unit_test::run_all_tests(argc, argv);
}

