#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

/*
 This test is commented, it can't work because the pointer addresses change at each build...

namespace xtd::tunit::tests {
  class test_class_(collection_assert_all_items_are_instances_of_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      xtd::tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a);
    }
  };
}

void test_(collection_assert_all_items_are_instances_of_vector_failed_tests, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_all_items_are_instances_of_vector_failed_tests.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  collection_assert_all_items_are_instances_of_vector_failed_tests.test_case_failed\n"
    "    Expected: all items instance of <std::__1::basic_ostream<char, std::__1::char_traits<char> >*>\n"
    "    But was:  < 8-byte object <90-9A 44-E9 01-00 00-00>, 8-byte object <D0-9B 44-E9 01-00 00-00>, 8-byte object <48-99 44-E9 01-00 00-00> >\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(collection_assert_all_items_are_instances_of_vector_failed_tests, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("collection_assert_all_items_are_instances_of_vector_failed_tests.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
*/
