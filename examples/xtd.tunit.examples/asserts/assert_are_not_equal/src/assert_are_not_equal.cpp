#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto i = 24;
      assert::are_not_equal(23, i);
    }
    
    void test_method_(test_case_failed) {
      auto i = 24;
      assert::are_not_equal(24, i);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: not 24
//     But was:  24
//     Stack Trace: in |---OMITTED---|/assert_are_not_equal.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
