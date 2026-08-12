#include <xtd/index>
#include <xtd/array>
#include <xtd/index_out_of_range_exception>
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
    
    auto test_method_(bpos) {
      assert::is_zero(xtd::index::bpos);
      assert::is_zero(xtd::index::bpos.value());
      assert::is_false(xtd::index::bpos.is_from_end());
    }
    
    auto test_method_(epos) {
      assert::are_equal(18446744073709551614_z, xtd::index::epos);
      assert::are_equal(1_z, xtd::index::epos.value());
      assert::is_true(xtd::index::epos.is_from_end());
    }
    
    auto test_method_(npos) {
      assert::are_equal(18446744073709551615_z, xtd::index::npos);
      assert::is_zero(xtd::index::npos.value());
      assert::is_true(xtd::index::npos.is_from_end());
    }
    
    auto test_method_(access_array_item_with_bpos) {
      auto items = array {1, 2, 3, 4};
      assert::are_equal(1, items[xtd::index::bpos]);
      assert::are_equal(2, items[xtd::index::bpos + 1]);
      assert::throws<index_out_of_range_exception>([&items] {auto _ = items[xtd::index::bpos - 1];});
    }
  };
}
