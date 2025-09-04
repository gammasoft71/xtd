#include <xtd/xtd.tunit>

using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto l = list {1, 2, 3, 4};
      assume::does_not_throw([&] {l[2];});
    }
    
    void test_method_(test_case_aborted) {
      auto l = list {1, 2, 3, 4};
      assume::does_not_throw([&] {l[5];});
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Expected: No Exception to be thrown
//     But was:  <index_out_of_range_exception>
//     Stack Trace: in |---OMITTED---|/assume_does_not_throw.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
