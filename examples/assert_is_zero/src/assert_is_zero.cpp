#include <xtd/tunit>
#include <iterator>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int i = 0;
      assert::is_zero_(i);
    }

    void test_method_(test_case_failed) {
      int i = 42;
      assert::is_zero_(i);
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
//     PASSED test_case_succeed (0 ms total)
//     FAILED test_case_failed (0 ms total)
//
// Expected: zero
// But was:  42
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_is_zero.cpp:18
//
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED test.test_case_failed
//
//     FAILED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)

