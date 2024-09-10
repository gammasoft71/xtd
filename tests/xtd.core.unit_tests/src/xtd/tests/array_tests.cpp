#include <xtd/array>
#include <xtd/as>
#include <xtd/environment>
#include <xtd/collections/generic/list>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(array_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<array_<int>::value_type>(), csf_);
    }
    
    void test_method_(value_type_of_boolean) {
      assert::are_equal(typeof_<bool>(), typeof_<array_<bool>::value_type>(), csf_);
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<array_<int>::base_type>(), csf_);
    }
    
    void test_method_(base_type_boolean) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<array_<bool>::base_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<array_<int>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<array_<int>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<array_<int>::reference>(), csf_);
    }
    
    void test_method_(reference_of_boolean) {
      assert::are_equal(typeof_<bool&>(), typeof_<array_<bool>::reference>(), csf_);
    }

    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<array_<int>::const_reference>(), csf_);
    }
    
    void test_method_(const_reference_of_boolean) {
      assert::are_equal(typeof_<const bool&>(), typeof_<array_<bool>::const_reference>(), csf_);
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<array_<int>::pointer>(), csf_);
    }
    
    void test_method_(pointer_of_boolean) {
      assert::are_equal(typeof_<bool*>(), typeof_<array_<bool>::pointer>(), csf_);
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<array_<int>::const_pointer>(), csf_);
    }
    
    void test_method_(const_pointer_of_boolean) {
      assert::are_equal(typeof_<const bool*>(), typeof_<array_<bool>::const_pointer>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<array_<int>::iterator>(), csf_);
    }
    
    void test_method_(iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::iterator>(), typeof_<array_<bool>::iterator>(), csf_);
    }

    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<array_<int>::const_iterator>(), csf_);
    }
    
    void test_method_(const_iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::const_iterator>(), typeof_<array_<bool>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<array_<int>::base_type::reverse_iterator>(), typeof_<array_<int>::reverse_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<array_<bool>::base_type::reverse_iterator>(), typeof_<array_<bool>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<array_<int>::base_type::const_reverse_iterator>(), typeof_<array_<int>::const_reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<array_<bool>::base_type::const_reverse_iterator>(), typeof_<array_<bool>::const_reverse_iterator>(), csf_);
    }
    
    void test_method_(default_constructor) {
      collection_assert::is_empty(array_<int> {}, csf_);
    }
    
    void test_method_(default_constructor_of_boolean) {
      collection_assert::is_empty(array_<bool> {}, csf_);
    }
    
    void test_method_(constructor_with_initializer_lit) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_{1, 2, 3, 4, 5}, csf_);
    }
    
    void test_method_(constructor_with_initializer_lit_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_{true, false, false, true, false}, csf_);
    }
    
    void test_method_(constructor_with_array) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_{array_ {1, 2, 3, 4, 5}}, csf_);
    }
    
    void test_method_(constructor_with_array_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_{array_ {true, false, false, true, false}}, csf_);
    }
    
    void test_method_(constructor_with_size) {
      collection_assert::are_equal({0, 0, 0, 0, 0}, array_<int>(5), csf_);
    }

    void test_method_(constructor_with_size_of_booleans) {
      collection_assert::are_equal({false, false, false, false, false}, array_<bool>(5), csf_);
    }

    void test_method_(constructor_with_native_array) {
      int a[] = {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int>(a), csf_);
    }
    
    void test_method_(constructor_with_native_array_of_booleans) {
      bool a[] = {true, false, false, true, false};
      collection_assert::are_equal({true, false, false, true, false}, array_<bool>(a), csf_);
    }

    void test_method_(constructor_with_const_pointer_and_length) {
      int a[] = {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int>(a, 5), csf_);
    }

    void test_method_(constructor_with_const_pointer_and_length_of_booleans) {
      bool a[] = {true, false, false, true, false};
      collection_assert::are_equal({true, false, false, true, false}, array_<bool>(a, 5), csf_);
    }

    void test_method_(constructor_with_ienumerable) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int> {as<ienumerable<int>>(list {1, 2, 3, 4, 5})}, csf_);
    }
    
    void test_method_(constructor_with_ienumerable_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_<bool> {as<ienumerable<bool>>(list {true, false, false, true, false})}, csf_);
    }

    void test_method_(constructor_with_ilist) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int> {as<ilist<int>>(list {1, 2, 3, 4, 5})}, csf_);
    }
    
    void test_method_(constructor_with_ilist_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_<bool> {as<ilist<bool>>(list {true, false, false, true, false})}, csf_);
    }
    
    void test_method_(const_back) {
      assert::are_equal(21, array_ {84, 42, 21}.back(), csf_);
      assert::throws<index_out_of_range_exception>([] {array_ {}.back();}, csf_);
    }
    
    void test_method_(back) {
      auto items = array_ {84, 42, 21};
      items.back() = 5;
      assert::are_equal(5, items.back(), csf_);
      auto empty_items = array_<int> {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.back() = 5;}, csf_);
    }
    
    void test_method_(begin) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(84, *items.begin(), csf_);
    }
    
    void test_method_(cbegin) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(84, *items.cbegin(), csf_);
    }

    void test_method_(cend) {
      auto items = array_ {84, 42, 21};
      assert::throws<index_out_of_range_exception>([&] {*items.cend();}, csf_);
    }
    
    void test_method_(count) {
      auto items = array_<int> {};
      assert::is_zero(items.count(), csf_);
      items.resize(3);
      assert::are_equal(3_z, items.count(), csf_);
      items.resize(50);
      assert::are_equal(50_z, items.count(), csf_);
    }
    
    void test_method_(crbegin) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(21, *items.crbegin(), csf_);
    }
    
    void test_method_(crend) {
      auto items = array_ {84, 42, 21};
      assert::does_not_throw([&] {*items.crend();}, csf_);
    }
    
    void test_method_(data) {
      auto items = array_ {84, 42, 21};
      
      auto ptr = items.data();
      assert::are_equal(84, *ptr, csf_);
      assert::are_equal(42, *(ptr + 1), csf_);
      assert::are_equal(21, *(ptr + 2), csf_);
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //assert::are_equal(0, *(ptr + 3), csf_);
      
      *(ptr) = 63;
      *(ptr + 1) = 31;
      *(ptr + 2) = 10;
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //*(ptr + 3) = 6;
      
      collection_assert::are_equal({63, 31, 10}, items, csf_);
    }

    void test_method_(empty) {
      assert::is_true(array_<int> {}.empty(), csf_);
      assert::is_false(array_<int> {42}.empty(), csf_);
      
      auto items = array_<int> {};
      assert::is_true(items.empty(), csf_);
      items.resize(1);
      assert::is_false(items.empty(), csf_);
      items.resize(0);
      assert::is_true(items.empty(), csf_);
    }

    void test_method_(end) {
      auto items = array_ {84, 42, 21};
      assert::throws<index_out_of_range_exception>([&] {*items.end();}, csf_);
    }
    
    void test_method_(front_const) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(84, items.front(), csf_);
      assert::throws<index_out_of_range_exception>([&] {list<int> {}.front();}, csf_);
    }
    
    void test_method_(front) {
      auto items = array_ {84, 42, 21};
      items.front() = 10;
      assert::are_equal(10, items.front(), csf_);
      auto empty_items = array_<int> {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.front() = 10;}, csf_);
    }

    void test_method_(is_fixed_size) {
      // Is always true;
      assert::is_true(array_<int> {}.is_fixed_size(), csf_);
    }
    
    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(array_<int> {}.is_read_only(), csf_);
    }
    
    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(array_<int> {}.is_synchronized(), csf_);
    }

    void test_method_(items_const) {
      assert::are_equal(typeof_<array_<int>::base_type>(), typeof_(array_ {1, 2, 3, 4, 5}.items()), csf_);
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_ {1, 2, 3, 4, 5}.items(), csf_);
    }

    void test_method_(items) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(typeof_<array_<int>::base_type>(), typeof_(items.items()), csf_);
      
      auto& inners = items.items();
      assert::are_equal(84, inners[0], csf_);
      assert::are_equal(42, inners[1], csf_);
      assert::are_equal(21, inners[2], csf_);
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::are_equal(0, inners[3], csf_);

      inners[0] = 63;
      inners[1] = 31;
      inners[2] = 10;
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //inners[3] = 6;
      
      collection_assert::are_equal({63, 31, 10}, items, csf_);
    }

    void test_method_(length) {
      auto items = array_<int> {};
      assert::is_zero(items.length(), csf_);
      items.resize(3);
      assert::are_equal(3_z, items.length(), csf_);
      items.resize(50);
      assert::are_equal(50_z, items.length(), csf_);
    }

    void test_method_(long_length) {
      auto items = array_<int> {};
      assert::is_zero(items.long_length(), csf_);
      items.resize(3);
      assert::are_equal(3l, items.long_length(), csf_);
      items.resize(50);
      assert::are_equal(50l, items.long_length(), csf_);
    }
    
    void test_method_(max_size) {
      assert::are_equal(as<xtd::size>(environment::os_version().is_linux() ? int64_object::max_value / 4 : int64_object::max_value / 2), array_<int> {}.max_size(), csf_);
    }

    void test_method_(rank) {
      assert::are_equal(1_z, array_<int> {}.rank(), csf_);
    }

    void test_method_(rank_of_boolean) {
      assert::are_equal(1_z, array_<bool> {}.rank(), csf_);
    }
    
    void test_method_(rbegin) {
      auto items = array_ {84, 42, 21};
      assert::are_equal(21, *items.rbegin(), csf_);
    }
    
    void test_method_(rend) {
      auto items = array_ {84, 42, 21};
      assert::does_not_throw([&] {*items.rend();}, csf_);
    }

    void test_method_(size) {
      auto items = array_<int> {};
      assert::is_zero(items.size(), csf_);
      items.resize(3);
      assert::are_equal(3_z, items.size(), csf_);
      items.resize(50);
      assert::are_equal(50_z, items.size(), csf_);
    }
    
    void test_method_(sync_root) {
      auto a = array_<int> {};
      auto b = array_<int> {};
      assert::are_not_equal(a.sync_root(), b.sync_root(), csf_);
    }

    void test_method_(resize) {
      auto items = array_<int> {};
      assert::is_zero(items.count(), csf_);
      items.resize(5);
      assert::are_equal(5_z, items.count(), csf_);
      collection_assert::are_equal({0, 0, 0, 0, 0}, items, csf_);
      items.resize(50);
      assert::are_equal(50_z, items.count(), csf_);
      assert::are_equal(0, items[0] , csf_);
      assert::are_equal(0, items[4] , csf_);
      assert::are_equal(0, items[5] , csf_);
      assert::are_equal(0, items[49] , csf_);
      items.resize(5);
      assert::are_equal(5_z, items.count(), csf_);
      collection_assert::are_equal({0, 0, 0, 0, 0}, items, csf_);
      items.resize(0);
      assert::is_zero(items.count(), csf_);
      collection_assert::is_empty(items, csf_);
    }
    
    void test_method_(resize_with_value_type) {
      auto items = array_<int> {};
      assert::is_zero(items.count(), csf_);
      items.resize(5, 84);
      assert::are_equal(5_z, items.count(), csf_);
      collection_assert::are_equal({84, 84, 84, 84, 84}, items, csf_);
      items.resize(50, 42);
      assert::are_equal(50_z, items.count(), csf_);
      assert::are_equal(84, items[0] , csf_);
      assert::are_equal(84, items[4] , csf_);
      assert::are_equal(42, items[5] , csf_);
      assert::are_equal(42, items[49] , csf_);
      items.resize(5, 42);
      assert::are_equal(5_z, items.count(), csf_);
      collection_assert::are_equal({84, 84, 84, 84, 84}, items, csf_);
      items.resize(0, 42);
      assert::is_zero(items.count(), csf_);
      collection_assert::is_empty(items, csf_);
    }
  };
}
