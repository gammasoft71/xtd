#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed1) {
      auto i = 24;
      valid::is_less_or_equal(i, 48);
    }
    
    void test_method_(test_case_succeed2) {
      auto i = 24;
      valid::is_less_or_equal(i, 24);
    }
    
    void test_method_(test_case_failed) {
      auto i = 24;
      valid::is_less_or_equal(i, 12);
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
//   SUCCEED unit_tests::test.test_case_succeed1 (0 ms total)
//   SUCCEED unit_tests::test.test_case_succeed2 (0 ms total)
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: less than or equal to 12
//     But was:  24
//     Stack Trace: in |---OMITTED---|/valid_is_less_or_equal.cpp:18
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  1 test.
// End 3 tests from 1 test case ran. (0 ms total)
