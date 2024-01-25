#include <xtd/tunit/collection_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.h"

/*
 This test is commented, it can't work because the pointer addresses change at each build...

 namespace xtd::tunit::tests {
  class test_class_(collection_valid_all_items_are_instances_of_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a);
    }
  };
}

void test_(collection_valid_all_items_are_instances_of_vector_failed_tests, test_output) {
  auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_all_items_are_instances_of_vector_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  xtd::tunit::tests::collection_valid_all_items_are_instances_of_vector_failed_tests.test_case_failed\n"
    "    Expected: all items instance of <std::__1::basic_ostream<char, std::__1::char_traits<char> >*>\n"
    "    But was:  < 8-byte object <90-9A 44-E9 01-00 00-00>, 8-byte object <D0-9B 44-E9 01-00 00-00>, 8-byte object <48-99 44-E9 01-00 00-00> >\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(collection_valid_all_items_are_instances_of_vector_failed_tests, test_result) {
  auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_all_items_are_instances_of_vector_failed_tests.*");
  assert_value_(1, result);
}
*/
