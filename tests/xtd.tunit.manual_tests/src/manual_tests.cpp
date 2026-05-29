#include <xtd/xtd>

namespace xtd::tunit::tests {
  class test_class_(manual_test_tunit) {
  public:
    void test_method_(test_method1) {
      assert_that(true).is().true_();
    }
  };
}

startup_(tunit_main_);
