#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_failed) {
      assert::fail_();
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 1 test from 1 test case
//   Start 1 test from test
//     FAILED test_case_failed (0 ms total)
//
// Failled
// error: !---OMITTED---!/xtd/xtd.tunit/examples/assert_does_not_throw/src/assert_fail.cpp:9
//
//   End 1 test from test (0 ms total)
//
//   Summary :
// *** FAILED 1 test, listed below:
// *** FAILED test.test_case_failed
//
//     FAILED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
