#include <xtd/xtd.tunit>
#include <iterator>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int i = 0;
      assert::is_zero(i);
    }

    void test_method_(test_case_failed) {
      int i = 42;
      assert::is_zero(i);
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
//     Expected: zero
//     But was:  42
//     Stack Trace: in |---OMITTED---|/assert_is_zero.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
