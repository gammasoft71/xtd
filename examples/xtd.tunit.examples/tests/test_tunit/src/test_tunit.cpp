#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_test_project2 {
  class test_class_(unit_test1) {
    void test_method_(test_method1) {
      assert::is_true(true);
    }
    
    void ignore_test_method_(test_method2) {
      assert::is_true(true);
    }
    
    void test_method_(test_method3) {
      assert::is_true(false);
    }
  };
  
  class test_class_(unit_test2) {
    void test_method_(test_method1) {
      assert::is_true(true);
    }
    
    void test_method_(test_method2) {
      assert::is_true(true);
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
//   SUCCEED hello_world_test.create_string_from_literal (0 ms total)
//   SUCCEED hello_world_test.create_string_from_chars (0 ms total)
//
// Test results:
//   SUCCEED 2 tests.
// End 2 tests from 1 test case ran. (0 ms total)
