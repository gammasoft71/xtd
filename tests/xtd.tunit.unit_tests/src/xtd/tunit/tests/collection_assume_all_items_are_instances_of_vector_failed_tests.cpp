#include <xtd/tunit/collection_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(collection_assume_all_items_are_instances_of_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      auto a = xtd::array<std::ios_base*> {&std::cout, &std::cerr, &std::cin};
      xtd::tunit::collection_assume::all_items_are_instances_of<std::basic_ostream<char>*>(a);
    }
  };
  
  void test_(collection_assume_all_items_are_instances_of_vector_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_assume_all_items_are_instances_of_vector_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "  ABORTED xtd::tunit::tests::collection_assume_all_items_are_instances_of_vector_failed_tests.test_case_failed\n"
                  "    Test aborted\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(collection_assume_all_items_are_instances_of_vector_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_assume_all_items_are_instances_of_vector_failed_tests.*");
    assert_value_(0, result);
  }
}
