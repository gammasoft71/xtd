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
