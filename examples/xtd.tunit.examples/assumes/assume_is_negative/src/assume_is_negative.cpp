#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto i = -1;
      assume::is_negative(i);
    }
    
    void test_method_(test_case_aborted) {
      auto i = 1;
      assume::is_negative(i);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Expected: negative
//     But was:  1
//     Stack Trace: in |---OMITTED---|/assume_is_negative.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
