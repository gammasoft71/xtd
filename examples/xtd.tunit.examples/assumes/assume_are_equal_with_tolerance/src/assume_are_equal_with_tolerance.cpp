#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto d = 0.5999999999;
      assume::are_equal(0.6, d, 0.000000001);
    }
    
    void test_method_(test_case_aborted) {
      auto d = 0.5999999999;
      assume::are_equal(0.6, d, 0.0000000001);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//

// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Test aborted
//     Expected: 0.6
//     But was:  0.6
//     Stack Trace: in |---OMITTED---|/assume_are_equal_with_tolerance.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
