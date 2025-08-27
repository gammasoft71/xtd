#include <xtd/xtd.tunit>
#include <stdexcept>

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    void test_method_(test_case1) {
      assert::is_true(true);
    }
    
    void test_method_(test_case2) {
      assert::is_false(true);
    }
    
    void test_method_(test_case3) {
      assert::does_not_throw([] {throw std::range_error("error");});
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output :
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 [< 1 ms]
//   FAILED unit_tests::test.test_case2 [< 1 ms]
//     Expected: false
//     But was:  true
//     Stack Trace: in |---OMITTED---|/assert.cpp:14
//   FAILED  unit_tests::test.test_case3 [< 1 ms]
//     Expected: No Exception to be thrown
//     But was:  <std::range_error>
//     Stack Trace: in |---OMITTED---|/assert.cpp:18
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  2 tests.
// End 3 tests from 1 test case ran. [0.0006 seconds]
