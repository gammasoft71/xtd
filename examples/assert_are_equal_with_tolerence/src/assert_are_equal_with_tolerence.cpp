#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      double d = 0.5999999999;
      assert::are_equal_(0.6, d, 0.000000001);
    }

    void test_method_(test_case_failed) {
      double d = 0.5999999999;
      assert::are_equal_(0.6, d, 0.0000000001);
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
// Expected: 23
// But was:  24
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_are_equal.cpp:15
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

