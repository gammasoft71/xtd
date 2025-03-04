#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_collection_succeed) {
      valid::is_empty(std::initializer_list<int> {});
    }
    
    void test_method_(test_case_collection_failed) {
      valid::is_empty({0, 1, 2, 3});
    }
    
    void test_method_(test_case_string_succeed) {
      valid::is_empty("");
    }
    
    void test_method_(test_case_string_failed) {
      valid::is_empty("string");
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 4 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_collection_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_collection_failed (0 ms total)
//     Expected: collection <empty>
//     But was:  < 0, 1, 2, 3 >
//     Stack Trace: in |---OMITTED---|/valid_is_empty.cpp:13
//   SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_string_failed (0 ms total)
//     Expected: collection <empty>
//     But was:  < 's', 't', 'r', 'i', 'n', 'g' >
//     Stack Trace: in |---OMITTED---|/valid_is_empty.cpp:21
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  2 tests.
// End 4 tests from 1 test case ran. (0 ms total)
