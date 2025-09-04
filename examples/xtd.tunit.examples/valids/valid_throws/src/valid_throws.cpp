#include <xtd/xtd.tunit>

using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto l = list {1, 2, 3, 4};
      valid::throws<index_out_of_range_exception>([&] {return l[5];});
    }
    
    void test_method_(test_case_failed) {
      auto l = list {1, 2, 3, 4};
      valid::throws<index_out_of_range_exception>([&] {return l[2];});
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
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: <index_out_of_range_exception>
//     But was:  <nothing>
//     Stack Trace: in |---OMITTED---|/valid_throws.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
