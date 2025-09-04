#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto l = list {1, 2, 3, 4};
      assert::does_not_throw([&] {l[2];});
    }
    
    void test_method_(test_case_failed) {
      auto l = list {1, 2, 3, 4};
      assert::does_not_throw([&] {l[5];});
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
//     Expected: No Exception to be thrown
//     But was:  <index_out_of_range_exception>
//     Stack Trace: in |---OMITTED---|/assert_does_not_throw.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
