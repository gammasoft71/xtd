#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case1) {
      assert_that(true).is().true_();
    }
    
    void test_method_(test_case2) {
      assert_that(true).is().false_();
    }
    
    void test_method_(test_case3) {
      assert_that([] {throw index_out_of_range_exception("error");}).does().not_().throw_();
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output :
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 [< 1 ms]
//   FAILED unit_tests::test.test_case2 [< 1 ms]
//     Expected: false
//     But was:  true
//     Stack Trace: in |---OMITTED---|/assert_that.cpp:10
//   FAILED  unit_tests::test.test_case3 [< 1 ms]
//     Expected: No Exception to be thrown
//     But was:  <xtd::index_out_of_range_exception>
//     Stack Trace: in |---OMITTED---|/assert_that.cpp:14
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  2 tests.
// End 3 tests from 1 test case ran. [0.0006 seconds]
