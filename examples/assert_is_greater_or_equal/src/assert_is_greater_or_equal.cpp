#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed1) {
      int i = 24;
      assert::is_greater_or_equal_(i, 12);
    }
    
    void test_method_(test_case_succeed2) {
      int i = 24;
      assert::is_greater_or_equal_(i, 24);
    }
    
    void test_method_(test_case_failed) {
      int i = 24;
      assert::is_greater_or_equal_(i, 48);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
/// tart 3 tests from 1 test case
//   Start 3 tests from test
//     SUCCEED test_case_succeed1 (0 ms total)
//     SUCCEED test_case_succeed2 (0 ms total)
//     FAILED  test_case_failed (0 ms total)
//
// Expected: greater than or equal to 48
// But was:  24
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_is_greater_or_equal.cpp:20
//
//   End 3 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 2 tests.
// *** FAILED  1 test, listed below:
// *** FAILED  test.test_case_failed
//
//     FAILED  1 test.
// End 3 tests from 1 test case ran. (0 ms total)

