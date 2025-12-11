#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/tunit/tunit_main>
#include <xtd/startup>

namespace xtd::tunit::tests {
  class test_class_(manual_test_tunit) {
  public:
    void test_method_(test_method1) {
      assert::is_true(true);
    }
  };
}

startup_(tunit_main_);
