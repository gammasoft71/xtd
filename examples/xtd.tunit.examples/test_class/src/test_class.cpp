#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    // This is the method that is called 1 time before test class run.
    static void class_initialize_(class_initialize) {
    }
    
    // This is the method that is called 1 time after test class run.
    static void class_cleanup_(class_cleanup) {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    static void test_initialize_(test_initialize) {
    }
    
    // This is the method that is called after any tests in a fixture are run.
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

int main() {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case1 (0 ms total)
//   SUCCEED test.test_case2 (0 ms total)
//   IGNORED test.test_case3 (0 ms total)
//     Test ignored
//
// Test results:
//   SUCCEED 2 tests.
//   IGNORED 1 test.
// End 3 tests from 1 test case ran. (0 ms total)
