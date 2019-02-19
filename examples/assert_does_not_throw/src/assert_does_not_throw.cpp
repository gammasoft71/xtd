#include <xtd/tunit>
#include <vector>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      std::vector v1 = {1, 2, 3, 4};
      xtd::tunit::assert::does_not_throw([&] {v1.at(2);});
    }
    
    void test_method_(test_case_failed) {
      std::vector v1 = {1, 2, 3, 4};
      xtd::tunit::assert::does_not_throw([&] {v1.at(5);});
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from test
//     PASSED test_case_succeed (0 ms total)
//     FAILED test_case_failed (4 ms total)
//
// Expected: No Exception to be thrown
// But was:  <std::out_of_range>
// error: !---OMITTED---!/xtd/xtd.tunit/examples/assert_does_not_throw/src/assert_does_not_throw.cpp:15
//
//   End 2 tests from test (4 ms total)
//
//   Summary :
//     PASSED 1 tests.
// *** FAILED 1 test, listed below:
// *** FAILED test.test_case_failed
//
//     FAILED 1 tests.
// End 2 tests from 1 test case ran. (4 ms total)
