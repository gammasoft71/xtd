#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
//#include <xtd/tunit/tunit_main>
#include <xtd/tunit/console_unit_test>
#include <xtd/startup>

namespace xtd::tunit::tests {
  class test_class_(manual_test_tunit) {
  public:
    void test_method_(test_method1) {
      environment::exit(42);
      assert_that(false).is().true_();
    }
    
    static auto main() {
      console_unit_test {}.run();
    }
  };
}

//startup_(tunit_main_);
startup_(xtd::tunit::tests::manual_test_tunit::main);
