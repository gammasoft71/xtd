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
      assert::are_equal(typeof_<int>(), typeof_<array<int>::value_type>());
    }
    
    void test_method_(value_type_of_boolean) {
      assert::are_equal(typeof_<bool>(), typeof_<array<bool>::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<array<int>::base_type > ());
    }
    
    void test_method_(base_type_boolean) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<array<bool>::base_type > ());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<array<int>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<array<int>::difference_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<array<int>::reference>());
    }
    
    void test_method_(reference_of_boolean) {
      assert::are_equal(typeof_<bool&>(), typeof_<array<bool>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<array<int>::const_reference>());
    }
    
    void test_method_(const_reference_of_boolean) {
      assert::are_equal(typeof_<const bool&>(), typeof_<array<bool>::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<array<int>::pointer>());
    }
    
    void test_method_(pointer_of_boolean) {
      assert::are_equal(typeof_<bool*>(), typeof_<array<bool>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<array<int>::const_pointer>());
    }
    
    void test_method_(const_pointer_of_boolean) {
      assert::are_equal(typeof_<const bool*>(), typeof_<array<bool>::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<array<int>::iterator>());
    }
    
    void test_method_(iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::iterator>(), typeof_<array<bool>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<array<int>::const_iterator>());
    }
    
    void test_method_(const_iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::const_iterator>(), typeof_<array<bool>::const_iterator>());
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::reverse_iterator>(), typeof_<array<int>::reverse_iterator>());
    }
    
    void test_method_(reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::reverse_iterator>(), typeof_<array<bool>::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::const_reverse_iterator>(), typeof_<array<int>::const_reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::const_reverse_iterator>(), typeof_<array<bool>::const_reverse_iterator>());
    }
    
    void test_method_(default_constructor) {
      collection_assert::is_empty(array<int> {});
    }
    
    void test_method_(default_constructor_of_boolean) {
      collection_assert::is_empty(array<bool> {});
    }
    
    void test_method_(epos) {
      assert::are_equal(size_object::max_value - 1, array<int>::epos);
    }
    
    void test_method_(npos) {
      assert::are_equal(size_object::max_value, array<int>::npos);
    }
    
    void test_method_(constructor_with_initializer_lit) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array {1, 2, 3, 4, 5});
    }
    
    void test_method_(constructor_with_initializer_lit_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array {true, false, false, true, false});
    }
    
    void test_method_(constructor_with_array) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array {array {1, 2, 3, 4, 5}});
    }
    
    void test_method_(constructor_with_array_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array {array {true, false, false, true, false}});
    }
    
    void test_method_(constructor_with_size) {
      collection_assert::are_equal({0, 0, 0, 0, 0}, array<int>(5));
    }
    
    void test_method_(constructor_with_size_of_booleans) {
      collection_assert::are_equal({false, false, false, false, false}, array<bool>(5));
    }
    
    void test_method_(constructor_with_native_array) {
      int a[] = {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, array<int>(a));
    }
    
    void test_method_(constructor_with_native_array_of_booleans) {
      bool a[] = {true, false, false, true, false};
      collection_assert::are_equal({true, false, false, true, false}, array<bool>(a));
    }
    
    void test_method_(constructor_with_const_pointer_and_length) {
      int a[] = {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, array<int>(a, 5));
    }
    
    void test_method_(constructor_with_const_pointer_and_length_of_booleans) {
      bool a[] = {true, false, false, true, false};
      collection_assert::are_equal({true, false, false, true, false}, array<bool>(a, 5));
    }
    
    void test_method_(constructor_with_ienumerable) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array<int> {as<ienumerable<int >> (list {1, 2, 3, 4, 5})});
    }
    
    void test_method_(constructor_with_ienumerable_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array<bool> {as<ienumerable<bool >> (list {true, false, false, true, false})});
    }
    
    void test_method_(constructor_with_ilist) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array<int> {as<ilist<int >> (list {1, 2, 3, 4, 5})});
    }
    
    void test_method_(constructor_with_ilist_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array<bool> {as<ilist<bool >> (list {true, false, false, true, false})});
    }
    
    void test_method_(begin) {
      auto items = array {84, 42, 21};
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(cbegin) {
      auto items = array {84, 42, 21};
      assert::are_equal(84, *items.cbegin());
    }
    
    void test_method_(cend) {
      auto items = array {84, 42, 21};
      assert::is_true(items.cend() == items.cbegin() + items.count());
    }
    
    void test_method_(count) {
      auto items = array<int> {};
      assert::is_zero(items.count());
      items.resize(3);
      assert::are_equal(3_z, items.count());
      items.resize(50);
      assert::are_equal(50_z, items.count());
    }
    
    void test_method_(empty) {
      assert::is_true(array<int> {}.empty());
      assert::is_false(array<int> {42}.empty());
      
      auto items = array<int> {};
      assert::is_true(items.empty());
      items.resize(1);
      assert::is_false(items.empty());
      items.resize(0);
      assert::is_true(items.empty());
    }
    
    void test_method_(end) {
      auto items = array {84, 42, 21};
      assert::is_true(items.end() == items.begin() + items.count());
    }
    
    void test_method_(is_fixed_size) {
      // Is always true;
      assert::is_true(as<ilist<int>>(array<int> {}).is_fixed_size());
    }
    
    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(as<icollection<int>>(array<int> {}).is_read_only());
    }
    
    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(as<icollection<int>>(array<int> {}).is_synchronized());
    }
    
    void test_method_(items_const) {
      assert::are_equal(typeof_<array<int>::base_type>(), typeof_(array {1, 2, 3, 4, 5}.items()));
      collection_assert::are_equal({1, 2, 3, 4, 5}, array {1, 2, 3, 4, 5}.items());
    }
    
    void test_method_(items) {
      auto items = array {84, 42, 21};
      assert::are_equal(typeof_<array<int>::base_type>(), typeof_(items.items()));
      
      auto& inners = items.items();
      assert::are_equal(84, inners[0]);
      assert::are_equal(42, inners[1]);
      assert::are_equal(21, inners[2]);
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::throws<index_out_of_range_exception>([&]{[[maybe_unused]] auto i = inners[3];});
      
      inners[0] = 63;
      inners[1] = 31;
      inners[2] = 10;
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::throws<index_out_of_range_exception>([&]{inners[3] = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(length) {
      auto items = array<int> {};
      assert::is_zero(items.length());
      items.resize(3);
      assert::are_equal(3_z, items.length());
      items.resize(50);
      assert::are_equal(50_z, items.length());
    }
    
    void test_method_(long_length) {
      auto items = array<int> {};
      assert::is_zero(items.long_length());
      items.resize(3);
      assert::are_equal(3l, items.long_length());
      items.resize(50);
      assert::are_equal(50l, items.long_length());
    }
    
    void test_method_(rank) {
      assert::are_equal(1_z, array<int> {}.rank());
    }
    
    void test_method_(rank_of_boolean) {
      assert::are_equal(1_z, array<bool> {}.rank());
    }
    
    void test_method_(size) {
      auto items = array<int> {};
      assert::is_zero(items.size());
      items.resize(3);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(contains) {
      auto items = array {84, 42, 21};
      assert::is_true(items.contains(84));
      assert::is_true(items.contains(42));
      assert::is_true(items.contains(21));
      assert::is_false(items.contains(0));
      assert::is_false(items.contains(12));
      assert::is_false(items.contains(-1));
    }
    
    void test_method_(copy_to) {
      auto items = array {84, 42, 21};
      auto dest = array<int>(3);
      items.copy_to(dest, 0);
      collection_assert::are_equal({84, 42, 21}, dest);
      
      dest = array<int>(5);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21}, dest);
      
      dest = array<int>(7);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21, 0, 0}, dest);
    }
    
    void test_method_(equals_object) {
      auto items1 = array {84, 42, 21};
      auto items2 = array {84, 42, 21};
      assert::is_true(items1.equals(as<object>(items2)));
      auto items3 = array {84, 42, 33};
      assert::is_false(items1.equals(as<object>(items3)));
      auto items4 = list {84, 42, 21};
      assert::is_false(items1.equals(items4));
    }
    
    void test_method_(equals_array) {
      auto items1 = array {84, 42, 21};
      auto items2 = array {84, 42, 21};
      assert::is_true(items1.equals(items2));
      auto items3 = array {84, 42, 33};
      assert::is_false(items1.equals(items3));
    }
    
    void test_method_(fill) {
      auto items = array<int>(5);
      items.fill(84);
      collection_assert::are_equal({84, 84, 84, 84, 84}, items);
      items.fill(42);
      collection_assert::are_equal({42, 42, 42, 42, 42}, items);
      items.fill(21);
      collection_assert::are_equal({21, 21, 21, 21, 21}, items);
    }
    
    void test_method_(for_each) {
      auto items = array {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item : items)
        accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    void test_method_(get_enumerator) {
      auto items = array {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while (enumerator.move_next())
        accumulator += enumerator.current();
      assert::are_equal(15, accumulator);
    }
    
    void test_method_(get_length) {
      auto items = array {84, 42, 21};
      assert::are_equal(3_z, items.get_length(0));
      assert::throws<argument_out_of_range_exception>([&] {[[maybe_unused]] auto l = items.get_length(1);});
    }
    
    void test_method_(get_long_length) {
      auto items = array {84, 42, 21};
      assert::are_equal(3, items.get_long_length(0));
      assert::throws<argument_out_of_range_exception>([&] {[[maybe_unused]] auto l = items.get_long_length(1);});
    }
    
    void test_method_(get_lower_bound) {
      auto items = array {84, 42, 21};
      assert::is_zero(items.get_lower_bound(0));
      assert::throws<argument_out_of_range_exception>([&] {[[maybe_unused]] auto l = items.get_lower_bound(1);});
    }
    
    void test_method_(get_upper_bound) {
      auto items = array {84, 42, 21};
      assert::are_equal(2_z, items.get_upper_bound(0));
      assert::throws<argument_out_of_range_exception>([&] {[[maybe_unused]] auto l = items.get_upper_bound(1);});
    }
    
    void test_method_(get_value_with_index) {
      auto items = array {1, 2, 3, 4, 5};
      assert::are_equal(1, items.get_value(0));
      assert::are_equal(2, items.get_value(1));
      assert::are_equal(3, items.get_value(2));
      assert::are_equal(4, items.get_value(3));
      assert::are_equal(5, items.get_value(4));
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items.get_value(5);});
    }
    
    void test_method_(get_value_with_indexes_array) {
      auto items = array {1, 2, 3, 4, 5};
      assert::are_equal(1, items.get_value(array {0_z}));
      assert::are_equal(2, items.get_value(array {1_z}));
      assert::are_equal(3, items.get_value(array {2_z}));
      assert::are_equal(4, items.get_value(array {3_z}));
      assert::are_equal(5, items.get_value(array {4_z}));
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items.get_value(array {5_z});});
    }
    
    void test_method_(index_of_with_value_type) {
      assert::are_equal(array<int>::npos, array<int> {}.index_of(42));
      assert::are_equal(1_z, array {84, 42, 21, 42}.index_of(42));
      assert::are_equal(array<int>::npos, array {84, 42, 21, 42}.index_of(0));
    }
    
    void test_method_(resize) {
      auto items = array<int> {};
      assert::is_zero(items.count());
      items.resize(5);
      assert::are_equal(5_z, items.count());
      collection_assert::are_equal({0, 0, 0, 0, 0}, items);
      items.resize(50);
      assert::are_equal(50_z, items.count());
      assert::are_equal(0, items[0]);
      assert::are_equal(0, items[4]);
      assert::are_equal(0, items[5]);
      assert::are_equal(0, items[49]);
      items.resize(5);
      assert::are_equal(5_z, items.count());
      collection_assert::are_equal({0, 0, 0, 0, 0}, items);
      items.resize(0);
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    void test_method_(resize_with_value_type) {
      auto items = array<int> {};
      assert::is_zero(items.count());
      items.resize(5, 84);
      assert::are_equal(5_z, items.count());
      collection_assert::are_equal({84, 84, 84, 84, 84}, items);
      items.resize(50, 42);
      assert::are_equal(50_z, items.count());
      assert::are_equal(84, items[0]);
      assert::are_equal(84, items[4]);
      assert::are_equal(42, items[5]);
      assert::are_equal(42, items[49]);
      items.resize(5, 42);
      assert::are_equal(5_z, items.count());
      collection_assert::are_equal({84, 84, 84, 84, 84}, items);
      items.resize(0, 42);
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    void test_method_(reverse) {
      auto items = array<int> {1, 2, 3, 4, 5};
      array<int>::reverse(items);
      collection_assert::are_equal({5, 4, 3, 2, 1}, items);
    }
    
    void test_method_(reverse_with_index_and_count) {
      auto items = array<int> {1, 2, 3, 4, 5};
      array<int>::reverse(items, 1, 3);
      collection_assert::are_equal({1, 4, 3, 2, 5}, items);
      assert::throws<argument_out_of_range_exception>([&] {array<int>::reverse(items, 6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {array<int>::reverse(items, 1, 5);});
    }
    
    void test_method_(set_value_with_index) {
      auto items = array {1, 2, 3, 4, 5};
      items.set_value(6, 0);
      items.set_value(7, 1);
      items.set_value(8, 2);
      items.set_value(9, 3);
      items.set_value(10, 4);
      assert::throws<index_out_of_range_exception>([&] {items.set_value(11, 5);});
      collection_assert::are_equal({6, 7, 8, 9, 10}, items);
    }
    
    void test_method_(set_value_with_indexes_array) {
      auto items = array {1, 2, 3, 4, 5};
      items.set_value(6, array {0_z});
      items.set_value(7, array {1_z});
      items.set_value(8, array {2_z});
      items.set_value(9, array {3_z});
      items.set_value(10, array {4_z});
      assert::throws<index_out_of_range_exception>([&] {items.set_value(11, array {5_z});});
      collection_assert::are_equal({6, 7, 8, 9, 10}, items);
    }
    
    void test_method_(swap) {
      auto items1 = array<int> {1, 2, 3, 4, 5};
      auto items2 = array<int> {6, 7, 8, 9, 10};
      items1.swap(items2);
      collection_assert::are_equal({6, 7, 8, 9, 10}, items1);
      collection_assert::are_equal({1, 2, 3, 4, 5}, items2);
    }
    
    void test_method_(to_string) {
      assert::are_equal("[1, 2, 3, 4, 5]", array {1, 2, 3, 4, 5}.to_string());
      assert::are_equal("[one, two, three, four, five]", array {"one", "two", "three", "four", "five"}.to_string());
    }
    
    void test_method_(index_of_with_array_and_value_type) {
      assert::are_equal(array<int>::npos, array<int>::index_of(array<int> {}, 42));
      assert::are_equal(1_z, array<int>::index_of(array {84, 42, 21, 42}, 42));
      assert::are_equal(array<int>::npos, array<int>::index_of(array {84, 42, 21, 42}, 0));
    }
    
    void test_method_(index_of_with_array_value_type_and_index) {
      assert::are_equal(array<int>::npos, array<int>::index_of(array<int> {}, 42, 0));
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {}, 42, 1);});
      assert::are_equal(1_z, array<int>::index_of(array {84, 42, 21, 42}, 42, 0));
      assert::are_equal(3_z, array<int>::index_of(array {84, 42, 21, 42}, 42, 2));
      assert::are_equal(array<int>::npos, array<int>::index_of(array {84, 42, 21, 42}, 42, 4));
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {84, 42, 21, 42}, 42, 5);});
      assert::are_equal(array<int>::npos, array<int>::index_of(array {84, 42, 21, 42}, 0, 0));
    }
    
    void test_method_(index_of_with_array_value_type_index_and_count) {
      assert::are_equal(array<int>::npos, array<int>::index_of(array<int> {}, 42, 0, 0));
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {}, 42, 1, 0);});
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {}, 42, 0, 1);});
      assert::are_equal(1_z, array<int>::index_of(array {84, 42, 21, 42}, 42, 0, 4));
      assert::are_equal(3_z, array<int>::index_of(array {84, 42, 21, 42}, 42, 2, 2));
      assert::are_equal(array<int>::npos, array<int>::index_of(array {84, 42, 21, 42}, 42, 4, 0));
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {84, 42, 21, 42}, 42, 4, 1);});
      assert::throws<argument_out_of_range_exception>([&] {array<int>::index_of(array<int> {84, 42, 21, 42}, 42, 5, 0);});
      assert::are_equal(array<int>::npos, array<int>::index_of(array {84, 42, 21, 42}, 0, 0, 4));
    }
    
    void test_method_(equal_copy_operator_with_array) {
      auto items1 = array<int> {};
      auto items2 = array {84, 42, 21};
      collection_assert::is_empty(items1);
      items1 = items2;
      collection_assert::are_equal({84, 42, 21}, items1);
      auto items3 = array<int> {};
      items1 = items3;
      collection_assert::is_empty(items1);
    }
    
    void test_method_(equal_copy_operator_with_initializer_list) {
      auto items = array<int> {};
      collection_assert::is_empty(items);
      items = {84, 42, 21};
      collection_assert::are_equal({84, 42, 21}, items);
      items = {};
      collection_assert::is_empty(items);
    }
    
    void test_method_(equal_move_operator_with_array) {
      auto items = array<int> {};
      collection_assert::is_empty(items);
      items = array {84, 42, 21};
      collection_assert::are_equal({84, 42, 21}, items);
      items = array<int> {};
      collection_assert::is_empty(items);
    }
    
    void test_method_(const_base_type_cast_operator) {
      const auto items = array {84, 42, 21};
      const std::vector<int> base_itmes = items;
      collection_assert::are_equal({84, 42, 21}, base_itmes);
    }
    
    void test_method_(base_type_cast_operator) {
      auto items = array {84, 42, 21};
      std::vector<int> base_itmes = items;
      collection_assert::are_equal({84, 42, 21}, base_itmes);
    }
    
    void test_method_(index_operator) {
      auto items = array {84, 42, 21};
      
      assert::are_equal(84, items[0]);
      assert::are_equal(42, items[1]);
      assert::are_equal(21, items[2]);
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items[3];});
      
      items[0] = 63;
      items[1] = 31;
      items[2] = 10;
      assert::throws<index_out_of_range_exception>([&] {items[3] = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(index_operators_with_epos) {
      auto items = array {1, 2, 3, 4, 5};
      
      assert::are_equal(5, items[items.count() - 1]);
      assert::are_equal(5, items[items.epos]);
      assert::are_equal(5, items[xtd::epos]);
      
      items[items.epos] = 6;
      assert::are_equal(6, items[items.count() - 1]);
      assert::are_equal(6, items[items.epos]);
      assert::are_equal(6, items[xtd::epos]);
      
      items[xtd::epos] = 7;
      assert::are_equal(7, items[items.count() - 1]);
      assert::are_equal(7, items[items.epos]);
      assert::are_equal(7, items[xtd::epos]);
    }
    
    void test_method_(index_functor) {
      auto items = array {84, 42, 21};
      
      assert::are_equal(84, items(0));
      assert::are_equal(42, items(1));
      assert::are_equal(21, items(2));
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items(3);});
      
      items(0) = 63;
      items(1) = 31;
      items(2) = 10;
      assert::throws<index_out_of_range_exception>([&] {items(3) = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(index_functor_with_epos) {
      auto items = array {1, 2, 3, 4, 5};
      
      assert::are_equal(5, items(items.count() - 1));
      assert::are_equal(5, items(items.epos));
      assert::are_equal(5, items(xtd::epos));
      
      items(items.epos) = 6;
      assert::are_equal(6, items(items.count() - 1));
      assert::are_equal(6, items(items.epos));
      assert::are_equal(6, items(xtd::epos));
      
      items(xtd::epos) = 7;
      assert::are_equal(7, items(items.count() - 1));
      assert::are_equal(7, items(items.epos));
      assert::are_equal(7, items(xtd::epos));
    }
    
    void test_method_(indexes_array_functor) {
      auto items = array {84, 42, 21};
      
      assert::are_equal(84, items(array {0_z}));
      assert::are_equal(42, items(array {1_z}));
      assert::are_equal(21, items(array {2_z}));
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items(array {3_z});});
      
      items(array {0_z}) = 63;
      items(array {1_z}) = 31;
      items(array {2_z}) = 10;
      assert::throws<index_out_of_range_exception>([&] {items(array {3_z}) = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
  };
}
