#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test_tunit) {
  public:
    void test_method_(test_case1) {
      assert::are_equal(42, 0x2A, csf_);
    }
  };
}

startup_(tunit_main_);
