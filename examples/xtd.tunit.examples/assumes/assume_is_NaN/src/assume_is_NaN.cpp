#include <xtd/xtd.tunit>
#include <xtd/double_object>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto d = double_object::NaN;
      assume::is_NaN(d);
    }
    
    void test_method_(test_case_aborted) {
      auto d = 3.14159;
      assume::is_NaN(d);
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
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Expected: NaN
//     But was:  3.14159
//     Stack Trace: in |---OMITTED---|/assume_is_NaN.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
