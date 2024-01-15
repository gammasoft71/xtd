#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed1) {
      auto i = 24;
      assert::is_greater_or_equal(i, 12);
    }
    
    void test_method_(test_case_succeed2) {
      auto i = 24;
      assert::is_greater_or_equal(i, 24);
    }
    
    void test_method_(test_case_failed) {
      auto i = 24;
      assert::is_greater_or_equal(i, 48);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed1 (0 ms total)
//   SUCCEED test.test_case_succeed2 (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: greater than or equal to 48
//     But was:  24
//     Stack Trace: in |---OMITTED---|/assert_is_greater_or_equal.cpp:18
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  1 test.
// End 3 tests from 1 test case ran. (0 ms total)
