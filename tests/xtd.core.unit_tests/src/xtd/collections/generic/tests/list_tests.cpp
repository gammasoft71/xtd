#include <xtd/collections/generic/list>
#include <xtd/as>
#include <xtd/boolean>
#include <xtd/environment>
#include <xtd/size_object>
#include <xtd/lock>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::object_model;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(list_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<list<int>::value_type>());
    }
    
    void test_method_(value_type_bool) {
      assert::are_equal(typeof_<bool>(), typeof_<list<bool>::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<list<int>::base_type > ());
    }
    
    void test_method_(base_type_bool) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<list<bool>::base_type > ());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<list<int>::size_type>());
      assert::are_equal(typeof_<list<bool>::base_type::size_type>(), typeof_<list<int>::size_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<list<int>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<list<int>::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<list<int>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<list<int>::const_pointer>());
    }
    
    void test_method_(default_constructor) {
      auto items = list<string> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_capacity) {
      auto items = list<boolean>(3);
      assert::is_greater_or_equal(items.capacity(), 3_z);
      assert::is_zero(items.count());
    }
    
    void test_method_(constructor_with_iterators) {
      auto v = array {84, 42, 21};
      auto items = list<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_base_type) {
      auto bt = list<int>::base_type {84, 42, 21};
      auto items = list<int>(bt);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_list) {
      auto l = list {84, 42, 21};
      auto items = list(l);
      l.add(10);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_move_list) {
      auto l = list {84, 42, 21};
      auto items = list(std::move(l));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(l);
    }
    
    void test_method_(constructor_with_move_base_type) {
      auto bt = list<int>::base_type {84, 42, 21};
      auto items = list<int>(std::move(bt));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(bt);
    }
    
    void test_method_(begin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(capaciy) {
      auto items = list {84, 42, 21};
      assert::are_equal(3_z, items.count());
      
      items.capacity(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.count());
    }
    
    void test_method_(cbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.cbegin());
    }
    
    void test_method_(cend) {
      auto items = list {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.cend();});
      assert::is_true(items.cend() == items.cbegin() + items.count());
    }
    
    void test_method_(count) {
      auto items = list<int> {};
      assert::is_zero(items.count());
      items.add(84);
      items.add(42);
      items.add(21);
      assert::are_equal(3_z, items.count());
    }
    
    void test_method_(end) {
      auto items = list {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.end();});
      assert::is_true(items.end() == items.begin() + items.count());
    }
    
    void test_method_(is_fixed_size) {
      // Is always false;
      assert::is_false(as<ilist<int>>(list<int> {}).is_fixed_size());
    }
    
    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(as<icollection<int>>(list<int> {}).is_read_only());
    }
    
    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(as<icollection<int>>(list<int> {}).is_synchronized());
    }
    
    void test_method_(items_const) {
      assert::are_equal(typeof_<list<int>::base_type>(), typeof_(list {1, 2, 3, 4, 5}.items()));
      collection_assert::are_equal({1, 2, 3, 4, 5}, list {1, 2, 3, 4, 5}.items());
    }
    
    void test_method_(items) {
      auto items = list {84, 42, 21};
      assert::are_equal(typeof_<list<int>::base_type>(), typeof_(items.items()));
      
      auto& inners = items.items();
      assert::are_equal(84, inners[0]);
      assert::are_equal(42, inners[1]);
      assert::are_equal(21, inners[2]);
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::are_equal(0, inners[3]);
      
      inners[0] = 63;
      inners[1] = 31;
      inners[2] = 10;
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //inners[3] = 6;
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(add) {
      auto items = list<int> {};
      
      items.add(1);
      collection_assert::are_equal({1}, items);
      items.add(2);
      collection_assert::are_equal({1, 2}, items);
      items.add(3);
      collection_assert::are_equal({1, 2, 3}, items);
      items.add(4);
      collection_assert::are_equal({1, 2, 3, 4}, items);
    }
    
    void test_method_(add_with_move) {
      auto items = list<int> {};
      
      auto i = 1;
      items.add(std::move(i));
      collection_assert::are_equal({1}, items);
    }
    
    void test_method_(add_range_with_ienumerable) {
      auto items = list<int> {};
      
      items.add_range(as<ienumerable<int>>(list {1, 2, 3, 4}));
      collection_assert::are_equal({1, 2, 3, 4}, items);
      
      items.add_range(as<ienumerable<int>>(list {5, 6, 7, 8}));
      collection_assert::are_equal({1, 2, 3, 4, 5, 6, 7, 8}, items);
    }
    
    void test_method_(add_range_with_initializer_list) {
      auto items = list<int> {};
      
      items.add_range({1, 2, 3, 4});
      collection_assert::are_equal({1, 2, 3, 4}, items);
      
      items.add_range({5, 6, 7, 8});
      collection_assert::are_equal({1, 2, 3, 4, 5, 6, 7, 8}, items);
    }
    
    void test_method_(add_range_with_list) {
      auto items = list<int> {};
      
      items.add_range(list {1, 2, 3, 4});
      collection_assert::are_equal({1, 2, 3, 4}, items);
      
      items.add_range(list {5, 6, 7, 8});
      collection_assert::are_equal({1, 2, 3, 4, 5, 6, 7, 8}, items);
    }
    
    void test_method_(as_read_only) {
      auto items = list<int> {84, 42, 21};
      auto roc = items.as_read_only();
      assert::is_instance_of<read_only_collection<int>>(roc);
      assert::is_true(as<icollection<int>>(roc).is_read_only());
      collection_assert::are_equal({84, 42, 21}, roc);
    }
    
    void test_method_(binary_search) {
      auto items = list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(16));
      assert::are_equal(3_z, items.binary_search(20));
      assert::are_equal(~6_z, items.binary_search(33));
      assert::are_equal(6_z, items.binary_search(35));
      assert::are_equal(~8_z, items.binary_search(50));
    }
    
    void test_method_(binary_search_with_comparer) {
      auto items = list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(16, comparer<int>::default_comparer));
      assert::are_equal(3_z, items.binary_search(20, comparer<int>::default_comparer));
      assert::are_equal(~6_z, items.binary_search(33, comparer<int>::default_comparer));
      assert::are_equal(6_z, items.binary_search(35, comparer<int>::default_comparer));
      assert::are_equal(~8_z, items.binary_search(50, comparer<int>::default_comparer));
    }
    
    void test_method_(binary_search_with_index_count_and_comparer) {
      auto items = list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(2, 3, 16, comparer<int>::default_comparer));
      assert::are_equal(3_z, items.binary_search(2, 3, 20, comparer<int>::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 33, comparer<int>::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 35, comparer<int>::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 50, comparer<int>::default_comparer));
    }

    void test_method_(clear) {
      auto items = list {84, 42, 21};
      items.clear();
      assert::are_equal(0_z, items.count());
    }
    
    void test_method_(contains) {
      auto items = list {84, 42, 21};
      assert::is_true(items.contains(84));
      assert::is_true(items.contains(42));
      assert::is_true(items.contains(21));
      assert::is_false(items.contains(0));
      assert::is_false(items.contains(12));
      assert::is_false(items.contains(-1));
    }
    
    void test_method_(convert_all) {
      auto items = list {84, 42, 21};
      collection_assert::are_equal({"84", "42", "21"}, items.convert_all<string>([](auto n) {return string::format("{}", n);}));
    }
    
    void test_method_(copy_to) {
      auto items = list {84, 42, 21};
      auto dest = array<int>(3);
      items.copy_to(dest, 0);
      collection_assert::are_equal({84, 42, 21}, dest);
    }
    
    void test_method_(copy_to_with_index) {
      auto items = list {84, 42, 21};
      auto dest = array<int>(5);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21}, dest);
      
      dest = array<int>(7);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21, 0, 0}, dest);
      
      dest = array<int>(3);
      assert::throws<argument_exception>([&] {items.copy_to(dest, 1);});
    }
    
    void test_method_(copy_to_with_index_and_count) {
      auto items = list {84, 42, 21, 33};
      auto dest = array<int>(5);
      items.copy_to(3, dest, 2, 1);
      collection_assert::are_equal({0, 0, 33, 0, 0}, dest);

      dest = array<int>(3);
      assert::throws<argument_exception>([&] {items.copy_to(0, dest, 0, 4);});
      assert::throws<argument_exception>([&] {items.copy_to(1, dest, 0, 4);});
      assert::throws<argument_exception>([&] {items.copy_to(1, dest, 1, 3);});
    }
    
    void test_method_(ensure_capacity) {
      auto items = list<int> {};
      assert::is_greater_or_equal(items.ensure_capacity(42), 42_z);
    }
    
    void test_method_(equals_object) {
      auto items1 = list {84, 42, 21};
      auto items2 = list {84, 42, 21};
      assert::is_true(items1.equals(as<object>(items2)));
      auto items3 = list {84, 42, 33};
      assert::is_false(items1.equals(as<object>(items3)));
      auto items4 = array {84, 42, 21};
      assert::is_false(items1.equals(items4));
    }
    
    void test_method_(equals_list) {
      auto items1 = list {84, 42, 21};
      auto items2 = list {84, 42, 21};
      assert::is_true(items1.equals(items2));
      auto items3 = list {84, 42, 33};
      assert::is_false(items1.equals(items3));
    }
    
    void test_method_(exist) {
      auto items = list {84, 42, 21, 33};
      assert::is_true(items.exists([](auto n) {return n == 42;}));
      assert::is_false(items.exists([](auto n) {return n == 24;}));
    }
    
    void test_method_(for_each) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item : items)
        accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    void test_method_(get_enumerator) {
      auto items = list {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while (enumerator.move_next())
        accumulator += enumerator.current();
      assert::are_equal(15, accumulator);
    }
    
    void test_method_(index_operator) {
      auto items = list {84, 42, 21};
      
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
  };
}
