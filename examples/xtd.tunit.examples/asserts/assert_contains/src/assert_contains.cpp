#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_collection_succeed) {
      assert::contains(2, {0, 1, 2, 3});
    }
    
    void test_method_(test_case_collection_failed) {
      assert::contains(4, {0, 1, 2, 3});
    }
    
    void test_method_(test_case_string_succeed) {
      assert::contains('i', "string");
    }
    
    void test_method_(test_case_string_failed) {
      assert::contains('a', "string");
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
//     Expected: collection containing 4
//     But was:  < 0, 1, 2, 3 >
//     Stack Trace: in |---OMITTED---|/assert_contains.cpp:14
//   SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_string_failed (0 ms total)
//     Expected: collection containing a
//     But was:  < 's', 't', 'r', 'i', 'n', 'g' >
//     Stack Trace: in |---OMITTED---|/assert_contains.cpp:22
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  2 tests.
// End 4 tests from 1 test case ran. (0 ms total)
