#include <xtd/tunit>
#include <stdexcept>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
      assert::is_true_(false);
    }
    
    void test_method_(test_case2) {
      assert::is_false_(true);
    }
    
    void test_method_(test_case3) {
      assert::does_not_throw_([] {throw std::range_error("error");});
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
//   Start 3 tests from test
//     FAILED  test_case1 (0 ms total)
//
// Expected: true
// But was:  false
// error: |---OMITTED---|/xtd/xtd.tunit/examples/many_asserts/src/many_asserts.cpp:11
//
//     FAILED  test_case2 (0 ms total)
//
// Expected: false
// But was:  true
// error: |---OMITTED---|/xtd/xtd.tunit/examples/many_asserts/src/many_asserts.cpp:15
//
//     FAILED  test_case3 (0 ms total)
//
// Expected: No Exception to be thrown
// But was:  <std::range_error>
// error: |---OMITTED---|/xtd/xtd.tunit/examples/many_asserts/src/many_asserts.cpp:19
//
//   End 3 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 0 test.
// *** FAILED  3 tests, listed below:
// *** FAILED  test.test_case1
// *** FAILED  test.test_case2
// *** FAILED  test.test_case3
//
//     FAILED  3 tests.
// End 3 tests from 1 test case ran. (0 ms total)
