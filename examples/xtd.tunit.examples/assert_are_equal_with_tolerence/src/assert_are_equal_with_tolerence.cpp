#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      double d = 0.5999999999;
      assert::are_equal(0.6, d, 0.000000001);
    }

    void test_method_(test_case_failed) {
      double d = 0.5999999999;
      assert::are_equal(0.6, d, 0.0000000001);
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: 0.6
//     But was:  0.6
//     Stack Trace: in |---OMITTED---|/assert_are_equal_with_tolerence.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
