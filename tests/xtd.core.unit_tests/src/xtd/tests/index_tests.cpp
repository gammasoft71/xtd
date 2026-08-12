#include <xtd/index>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(index_tests) {
    auto test_method_(default_ctor) {
      assert::is_zero(xtd::index {});
      assert::is_zero(xtd::index {}.value());
      assert::is_false(xtd::index {}.is_from_end());
    }
    
    auto test_method_(ctor_with_0_z) {
      assert::is_zero(xtd::index {0_z});
      assert::is_zero(xtd::index {0_z}.value());
      assert::is_false(xtd::index {0_z}.is_from_end());
    }
    
    auto test_method_(ctor_with_1_z) {
      assert::are_equal(1_z, xtd::index {1_z});
      assert::are_equal(1_z, xtd::index {1_z}.value());
      assert::is_false(xtd::index {1_z}.is_from_end());
    }
    
    auto test_method_(ctor_with_2_z) {
      assert::are_equal(2_z, xtd::index {2_z});
      assert::are_equal(2_z, xtd::index {2_z}.value());
      assert::is_false(xtd::index {2_z}.is_from_end());
    }
    
    auto test_method_(ctor_with_not_0_z) {
      assert::are_equal(18446744073709551615_z, xtd::index {~0_z});
      assert::is_zero(xtd::index {~0_z}.value());
      assert::is_true(xtd::index {~0_z}.is_from_end());
    }
    
    auto test_method_(ctor_with_not_1_z) {
      assert::are_equal(18446744073709551614_z, xtd::index {~1_z});
      assert::are_equal(1_z, xtd::index {~1_z}.value());
      assert::is_true(xtd::index {~1_z}.is_from_end());
    }
    
    auto test_method_(ctor_with_not_2_z) {
      assert::are_equal(18446744073709551613_z, xtd::index {~2_z});
      assert::are_equal(2_z, xtd::index {~2_z}.value());
      assert::is_true(xtd::index {~2_z}.is_from_end());
    }
  };
}
