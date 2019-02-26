#include <xtd/tunit>
#include <limits>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      double d = numeric_limits<double>::quiet_NaN();
      assert::is_NaN_(d);
    }

    void test_method_(test_case_failed) {
      double d = 3.14159;
      assert::is_NaN_(d);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
/// tart 2 tests from 1 test case
//   Start 2 tests from test
//     SUCCEED test_case_succeed (0 ms total)
//     FAILED  test_case_failed (0 ms total)
//
// Expected: NaN
// But was:  3.14159
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_is_NaN.cpp:17
//
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 1 test.
//     FAILED  1 test, listed below:
//     FAILED  test.test_case_failed
//
//     FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)

