#include <xtd/xtd.tunit>
#include <stdexcept>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    void test_method_(test_case1) {
      assume::is_true(true);
    }
    
    void test_method_(test_case2) {
      assume::is_false(true);
    }
    
    void test_method_(test_case3) {
      assume::does_not_throw([] {throw std::range_error("error");});
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case1 (0 ms total)
//   ABORTED test.test_case2 (0 ms total)
//     Test aborted
//     Expected: false
//     But was:  true
//     Stack Trace: in |---OMITTED---|/assume.cpp:14
//   ABORTED test.test_case3 (0 ms total)
//     Test aborted
//     Expected: No Exception to be thrown
//     But was:  <std::range_error>
//     Stack Trace: in |---OMITTED---|/assume.cpp:18
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 2 tests.
// End 3 tests from 1 test case ran. (0 ms total)
