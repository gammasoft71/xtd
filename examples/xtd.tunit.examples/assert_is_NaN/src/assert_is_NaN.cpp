#include <xtd/xtd.tunit>
#include <limits>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      double d = numeric_limits<double>::quiet_NaN();
      assert::is_NaN(d);
    }

    void test_method_(test_case_failed) {
      double d = 3.14159;
      assert::is_NaN(d);
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
//     Expected: NaN
//     But was:  3.14159
//     Stack Trace: in |---OMITTED---|/assert_is_NaN.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
