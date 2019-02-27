#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_failed) {
      assert::fail();
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
// Run tests:
//   FAILED  test.test_case_failed (0 ms total)
//     Test failed
//     Stack Trace: in |---OMITTED---|/xtd/xtd.tunit/examples/assert_fail/src/assert_fail.cpp:8
//
// Test results:
//   FAILED  1 test.
// End 1 test from 1 test case ran. (0 ms total)
