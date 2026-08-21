#include <xtd/index>
#include <xtd/array>
#include <xtd/index_out_of_range_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  class test_class_(index_tests) {
    auto test_method_(default_ctor) {
      assert::is_zero(xtd::index {}.to_usize());
      assert::is_zero(xtd::index {}.value());
      assert::is_false(xtd::index {}.is_from_end());
    }
    
    auto test_method_(ctor_with_0) {
      assert::is_zero(xtd::index {0}.to_usize());
      assert::is_zero(xtd::index {0}.value());
      assert::is_false(xtd::index {0}.is_from_end());
      assert::is_zero(xtd::index {0}.get_offset(10));
    }
    
    auto test_method_(ctor_with_1) {
      assert::are_equal(1_z, xtd::index {1}.to_usize());
      assert::are_equal(1_z, xtd::index {1}.value());
      assert::is_false(xtd::index {1}.is_from_end());
      assert::are_equal(1_z, xtd::index {1}.get_offset(10));
    }
    
    auto test_method_(ctor_with_2) {
      assert::are_equal(2_z, xtd::index {2}.to_usize());
      assert::are_equal(2_z, xtd::index {2}.value());
      assert::is_false(xtd::index {2}.is_from_end());
      assert::are_equal(2_z, xtd::index {2}.get_offset(10));
    }
    
    auto test_method_(ctor_with_not_0) {
      assert::are_equal(18446744073709551615_z, xtd::index {~0}.to_usize());
      assert::is_zero(xtd::index {~0}.value());
      assert::is_true(xtd::index {~0}.is_from_end());
      assert::are_equal(10_z, xtd::index {~0}.get_offset(10));
    }
    
    auto test_method_(ctor_with_not_1) {
      assert::are_equal(18446744073709551614_z, xtd::index {~1}.to_usize());
      assert::are_equal(1_z, xtd::index {~1}.value());
      assert::is_true(xtd::index {~1}.is_from_end());
      assert::are_equal(9_z, xtd::index {~1}.get_offset(10));
    }
    
    auto test_method_(ctor_with_not_2) {
      assert::are_equal(18446744073709551613_z, xtd::index {~2}.to_usize());
      assert::are_equal(2_z, xtd::index {~2}.value());
      assert::is_true(xtd::index {~2}.is_from_end());
      assert::are_equal(8_z, xtd::index {~2}.get_offset(10));
    }
    
    auto test_method_(end) {
      assert::are_equal(18446744073709551615_z, xtd::index::end.to_usize());
      assert::is_zero(xtd::index::end.value());
      assert::is_true(xtd::index::end.is_from_end());
      assert::are_equal(10_z, xtd::index::end.get_offset(10));
    }

    auto test_method_(last) {
      assert::are_equal(18446744073709551614_z, xtd::index::last.to_usize());
      assert::are_equal(1_z, xtd::index::last.value());
      assert::is_true(xtd::index::last.is_from_end());
      assert::are_equal(9_z, xtd::index::last.get_offset(10));
    }
    
    auto test_method_(start) {
      assert::is_zero(xtd::index::start.to_usize());
      assert::is_zero(xtd::index::start.value());
      assert::is_false(xtd::index::start.is_from_end());
      assert::is_zero(xtd::index::start.get_offset(10));
    }

    auto test_method_(access_array_item_with_last) {
      auto items = array {1, 2, 3, 4};
      assert::are_equal(4, items[xtd::index::last]);
      assert::are_equal(3, items[xtd::index::last - 1]);
      assert::throws<index_out_of_range_exception>([&items] {auto _ = items[xtd::index::last + 1];});
    }
    
    auto test_method_(access_array_item_with_end) {
      auto items = array {1, 2, 3, 4};
      assert::throws<index_out_of_range_exception>([&items] {auto _ = items[xtd::index::end];});
      assert::are_equal(1, items[xtd::index::end + 1]);
      assert::are_equal(4, items[xtd::index::end - 1]);
    }

    auto test_method_(access_array_item_with_start) {
      auto items = array {1, 2, 3, 4};
      assert::are_equal(1, items[xtd::index::start]);
      assert::are_equal(2, items[xtd::index::start + 1]);
      assert::throws<index_out_of_range_exception>([&items] {auto _ = items[xtd::index::start - 1];});
    }
  };
}
