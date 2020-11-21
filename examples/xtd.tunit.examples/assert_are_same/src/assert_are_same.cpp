#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int a = 24;
      int& b = a;
      assert::are_same(b, a);
    }

    void test_method_(test_case_failed) {
      int a = 24;
      int b =  24;
      assert::are_same(b, a);
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
//     Expected: same as 24
//     But was:  24
//     Stack Trace: in |---OMITTED---|/assert_are_same.cpp:14
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)

