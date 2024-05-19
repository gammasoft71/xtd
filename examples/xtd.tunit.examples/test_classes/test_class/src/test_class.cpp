#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    // This method is the method that is called just before the start of all tests. It is called only once.
    static void class_initialize_(class_initialize) {
    }
    
    // This method is the method that is called just after all the tests are finished. It is called only once.
    static void class_cleanup_(class_cleanup) {
    }
    
    // This method is the method that is called just before a test method starts. It is called for each test.
    static void test_initialize_(test_initialize) {
    }
    
    // This method is the method that is called right after a test method is finished. It is called for each test.
    static void test_cleanup_(test_cleanup) {
    }
    
    void test_method_(test_case1) {
    }
    
    void test_method_(test_case2) {
    }
    
    void ignore_test_method_(test_case3) {
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 (0 ms total)
//   SUCCEED unit_tests::test.test_case2 (0 ms total)
//   IGNORED test.test_case3 (0 ms total)
//     Test ignored
//
// Test results:
//   SUCCEED 2 tests.
//   IGNORED 1 test.
// End 3 tests from 1 test case ran. (0 ms total)
