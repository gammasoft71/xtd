#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto a = 24;
      auto& b = a;
      assert::are_same(b, a);
    }
    
    void test_method_(test_case_failed) {
      auto a = 24;
      auto b =  24;
      assert::are_same(b, a);
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
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: same as 24
//     But was:  24
//     Stack Trace: in |---OMITTED---|/assert_are_same.cpp:14
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)

