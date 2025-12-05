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
    
    void test_method_(epos) {
      assert::are_equal(size_object::max_value - 1, list<int>::epos);
    }
    
    void test_method_(npos) {
      assert::are_equal(size_object::max_value, list<int>::npos);
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
    
    void test_method_(capacity) {
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
      collection_assert::are_equal({1, 2, 3, 4, 5}, list {1, 2, 3, 4, 5}.items());
    }
    
    void test_method_(items) {
      auto items = list {84, 42, 21};
      
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
    
    void test_method_(items_some_operations) {
      auto items = list<string> {"one", "two", "three"};
      items.items().push_back("four");
      collection_assert::are_equal({"one", "two", "three", "four"}, items);
      items.items().emplace_back(std::initializer_list<char> {'f', 'i', 'v', 'e'});
      collection_assert::are_equal({"one", "two", "three", "four", "five"}, items);
      items.items().insert(items.items().begin() + 2, "six");
      collection_assert::are_equal({"one", "two", "six", "three", "four", "five"}, items);
      std::sort(items.items().begin(), items.items().end());
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
    
    void test_method_(add_range_with_same_list) {
      auto items = list {1, 2, 3, 4, 5};
      
      assert::does_not_throw(delegate_ {items.add_range(items);});
      collection_assert::are_equal({1, 2, 3, 4, 5, 1, 2, 3, 4, 5}, items);
    }
    
    void test_method_(add_range_with_same_list_as_ienumerable) {
      auto items = list {1, 2, 3, 4, 5};
      
      assert::does_not_throw(delegate_ {items.add_range(as<ienumerable<int>>(items));});
      collection_assert::are_equal({1, 2, 3, 4, 5, 1, 2, 3, 4, 5}, items);
    }
    
    void test_method_(as_read_only) {
      auto items = list {84, 42, 21};
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
      assert::throws<argument_out_of_range_exception>(delegate_ {items.copy_to(dest, 1);});
    }
    
    void test_method_(copy_to_with_index_and_count) {
      auto items = list {84, 42, 21, 33};
      auto dest = array<int>(5);
      items.copy_to(3, dest, 2, 1);
      collection_assert::are_equal({0, 0, 33, 0, 0}, dest);
      
      dest = array<int>(3);
      assert::throws<argument_out_of_range_exception>(delegate_ {items.copy_to(0, dest, 0, 4);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.copy_to(1, dest, 0, 4);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.copy_to(1, dest, 1, 3);});
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
    
    void test_method_(find) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(42, items.find([](auto n) {return n == 42;}).value_or(-1));
      assert::are_equal(-1, items.find([](auto n) {return n == 24;}).value_or(-1));
    }
    
    void test_method_(find_all) {
      auto items = list {84, 42, 21, 33};
      collection_assert::are_equal({84, 42}, items.find_all([](auto n) {return n % 2 == 0;}));
      collection_assert::is_empty(items.find_all([](auto n) {return n % 5 == 0;}));
    }
    
    void test_method_(find_index) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_index([](auto n) {return n == 42;}));
      assert::are_equal(2_z, items.find_index([](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_index([](auto n) {return n == 65;}));
    }
    
    void test_method_(find_index_with_start_index) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_index(0, [](auto n) {return n == 42;}));
      assert::are_equal(1_z, items.find_index(1, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_index(2, [](auto n) {return n == 42;}));
      assert::are_equal(2_z, items.find_index(0, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(2_z, items.find_index(2, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_index(4, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_index(0, [](auto n) {return n == 65;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_index(5, [](auto n) {return n % 2 != 0;});});
    }
    
    void test_method_(find_index_with_start_index_and_count) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_index(0, 2, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_index(0, 1, [](auto n) {return n == 42;}));
      assert::are_equal(1_z, items.find_index(1, 1, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_index(2, 2, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_index(0, 2, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(3_z, items.find_index(3, 1, [](auto n) {return n % 2 != 0;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_index(3, 2, [](auto n) {return n % 2 != 0;});});
      assert::are_equal(items.npos, items.find_index(4, 0, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_index(0, 4, [](auto n) {return n == 65;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_index(5, 1, [](auto n) {return n % 2 != 0;});});
    }
    
    void test_method_(find_last) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(42, items.find_last([](auto n) {return n == 42;}).value_or(-1));
      assert::are_equal(-1, items.find_last([](auto n) {return n == 24;}).value_or(-1));
    }
    
    void test_method_(find_last_index) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_last_index([](auto n) {return n == 42;}));
      assert::are_equal(3_z, items.find_last_index([](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_last_index([](auto n) {return n == 65;}));
    }
    
    void test_method_(find_last_index_with_start_index) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_last_index(3, [](auto n) {return n == 42;}));
      assert::are_equal(1_z, items.find_last_index(1, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_last_index(0, [](auto n) {return n == 42;}));
      assert::are_equal(2_z, items.find_last_index(2, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(3_z, items.find_last_index(3, [](auto n) {return n % 2 != 0;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(4, [](auto n) {return n % 2 != 0;});});
      assert::are_equal(items.npos, items.find_last_index(3, [](auto n) {return n == 65;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(5, [](auto n) {return n % 2 != 0;});});
    }
    
    void test_method_(find_last_index_with_start_index_and_count) {
      auto items = list {84, 42, 21, 33};
      assert::are_equal(1_z, items.find_last_index(2, 2, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_last_index(3, 1, [](auto n) {return n == 42;}));
      assert::are_equal(1_z, items.find_last_index(1, 1, [](auto n) {return n == 42;}));
      assert::are_equal(items.npos, items.find_last_index(0, 1, [](auto n) {return n == 42;}));
      assert::are_equal(2_z, items.find_last_index(2, 2, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(3_z, items.find_last_index(3, 2, [](auto n) {return n % 2 != 0;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(0, 2, [](auto n) {return n % 2 != 0;});});
      assert::are_equal(3_z, items.find_last_index(3, 0, [](auto n) {return n % 2 != 0;}));
      assert::are_equal(items.npos, items.find_last_index(3, 4, [](auto n) {return n == 65;}));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(4, 0, [](auto n) {return n % 2 != 0;});});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(0, 4, [](auto n) {return n % 2 != 0;});});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.find_last_index(5, 1, [](auto n) {return n % 2 != 0;});});
    }
    
    void test_method_(for_each) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      items.for_each(delegate_(auto n) {accumulator += n;});
      assert::are_equal(15, accumulator);
      
      accumulator = 0;
      list<int> {}.for_each(delegate_(auto n) {accumulator += n;});
      assert::are_equal(0, accumulator);
    }
    
    void test_method_(get_enumerator) {
      auto items = list {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while (enumerator.move_next())
        accumulator += enumerator.current();
      assert::are_equal(15, accumulator);
      enumerator.reset();
      while (enumerator.move_next())
        accumulator += enumerator.current();
      assert::are_equal(30, accumulator);
    }
    
    void test_method_(range_based_for_loop) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item : items)
        accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    void test_method_(modifying_list_during_iteration) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      auto caught = false;
      try {
        for (auto item : items) {
          accumulator += item;
          if (item == 3) items.remove(item);
        }
      } catch (const invalid_operation_exception& e) {
        caught = true;
      }
      assert::is_true(caught);
      assert::are_equal(6, accumulator);
    }
    
    void test_method_(modifying_list_items_during_iteration) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      auto caught = false;
      try {
        for (auto item : items) {
          accumulator += item;
          if (item == 3) items.items().erase(items.items().begin() + 2);
        }
      } catch (const invalid_operation_exception& e) {
        caught = true;
      }
      assert::is_true(caught);
      assert::are_equal(6, accumulator);
    }
    
    void test_method_(get_range) {
      auto items = list {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.get_range(0, 5));
      collection_assert::are_equal({2, 3, 4}, items.get_range(1, 3));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.get_range(0, 6);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.get_range(6, 0);});
    }
    
    void test_method_(index_of) {
      assert::are_equal(list<int>::npos, list<int> {}.index_of(0));
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.index_of(1));
      assert::are_equal(2_z, items.index_of(3));
      assert::are_equal(4_z, items.index_of(5));
      assert::are_equal(items.npos, items.index_of(6));
    }
    
    void test_method_(index_of_with_index) {
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.index_of(1, 0));
      assert::are_equal(items.npos, items.index_of(1, 1));
      assert::are_equal(2_z, items.index_of(3, 2));
      assert::are_equal(items.npos, items.index_of(3, 3));
      assert::are_equal(4_z, items.index_of(5, 4));
      assert::are_equal(items.npos, items.index_of(6, 0));
      assert::are_equal(items.npos, items.index_of(6, 4));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.index_of(1, 6);});
    }
    
    void test_method_(index_of_with_index_and_count) {
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.index_of(1, 0, 4));
      assert::are_equal(items.npos, items.index_of(1, 1, 3));
      assert::are_equal(1_z, items.index_of(2, 1, 3));
      assert::are_equal(items.npos, items.index_of(2, 2, 2));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.index_of(1, 1, 5);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.index_of(1, 5, 1);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.index_of(1, 0, 6);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.index_of(1, 6, 0);});
    }
    
    void test_method_(insert) {
      auto items = list {1, 2, 3, 4, 5};
      items.insert(0, 6);
      collection_assert::are_equal({6, 1, 2, 3, 4, 5}, items);
      items.insert(3, 7);
      collection_assert::are_equal({6, 1, 2, 7, 3, 4, 5}, items);
      items.insert(items.count(), 8);
      collection_assert::are_equal({6, 1, 2, 7, 3, 4, 5, 8}, items);
    }
    
    void test_method_(insert_with_move) {
      auto items = list {1, 2, 3, 4, 5};
      auto i = 6;
      items.insert(0, std::move(i));
      collection_assert::are_equal({6, 1, 2, 3, 4, 5}, items);
      i = 7;
      items.insert(3, std::move(i));
      collection_assert::are_equal({6, 1, 2, 7, 3, 4, 5}, items);
      i = 8;
      items.insert(items.count(), std::move(i));
      collection_assert::are_equal({6, 1, 2, 7, 3, 4, 5, 8}, items);
    }
    
    void test_method_(insert_range_with_ienumerable) {
      auto items = list {1, 2, 3, 4, 5};
      items.insert_range(0, as<ienumerable<int>>(list {6, 7}));
      collection_assert::are_equal({6, 7, 1, 2, 3, 4, 5}, items);
      items.insert_range(4, as<ienumerable<int>>(list {8, 9}));
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5}, items);
      items.insert_range(items.count(), as<ienumerable<int>>(list {10, 11}));
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5, 10, 11}, items);
    }
    
    void test_method_(insert_range_with_list) {
      auto items = list {1, 2, 3, 4, 5};
      items.insert_range(0, list {6, 7});
      collection_assert::are_equal({6, 7, 1, 2, 3, 4, 5}, items);
      items.insert_range(4, list {8, 9});
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5}, items);
      items.insert_range(items.count(), list {10, 11});
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5, 10, 11}, items);
    }
    
    void test_method_(insert_range_with_initializer_list) {
      auto items = list {1, 2, 3, 4, 5};
      items.insert_range(0, {6, 7});
      collection_assert::are_equal({6, 7, 1, 2, 3, 4, 5}, items);
      items.insert_range(4, {8, 9});
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5}, items);
      items.insert_range(items.count(), {10, 11});
      collection_assert::are_equal({6, 7, 1, 2, 8, 9, 3, 4, 5, 10, 11}, items);
    }
    
    void test_method_(insert_range_with_same_list) {
      auto items = list {1, 2, 3, 4, 5};
      
      assert::does_not_throw(delegate_ {items.insert_range(2, items);});
      collection_assert::are_equal({1, 2, 1, 2, 3, 4, 5, 3, 4, 5}, items);
    }
    
    void test_method_(insert_range_with_same_list_as_ienumerable) {
      auto items = list {1, 2, 3, 4, 5};
      
      assert::does_not_throw(delegate_ {items.insert_range(2, as<ienumerable<int>>(items));});
      collection_assert::are_equal({1, 2, 1, 2, 3, 4, 5, 3, 4, 5}, items);
    }
    
    void test_method_(last_index_of) {
      assert::are_equal(list<int>::npos, list<int> {}.index_of(0));
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.last_index_of(1));
      assert::are_equal(2_z, items.last_index_of(3));
      assert::are_equal(4_z, items.last_index_of(5));
      assert::are_equal(items.npos, items.last_index_of(6));
    }
    
    void test_method_(last_index_of_with_index) {
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.last_index_of(1, 4));
      assert::are_equal(2_z, items.last_index_of(3, 4));
      assert::are_equal(items.npos, items.last_index_of(3, 0));
      assert::are_equal(4_z, items.last_index_of(5, 4));
      assert::are_equal(items.npos, items.last_index_of(5, 3));
      assert::are_equal(items.npos, items.last_index_of(6, 0));
      assert::are_equal(items.npos, items.last_index_of(6, 4));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.last_index_of(1, 6);});
    }
    
    void test_method_(last_index_of_with_index_and_count) {
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.last_index_of(1, 4, 5));
      assert::are_equal(items.npos, items.last_index_of(1, 4, 4));
      assert::are_equal(1_z, items.last_index_of(2, 4, 4));
      assert::are_equal(items.npos, items.last_index_of(2, 4, 3));
      assert::throws<argument_out_of_range_exception>(delegate_ {items.last_index_of(1, 5, 1);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.last_index_of(1, 1, 5);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.last_index_of(1, 6, 0);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.last_index_of(1, 0, 6);});
    }
    
    void test_method_(resize) {
      auto items = list {84, 42, 21};
      items.resize(4);
      collection_assert::are_equal({84, 42, 21, 0}, items);
      items.resize(2);
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(resize_with_value) {
      auto items = list {84, 42, 21};
      items.resize(4, -1);
      collection_assert::are_equal({84, 42, 21, -1}, items);
      items.resize(2, -1);
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(remove) {
      auto items = list {1, 2, 3};
      assert::is_false(items.remove(4));
      collection_assert::are_equal({1, 2, 3}, items);
      assert::is_true(items.remove(2));
      collection_assert::are_equal({1, 3}, items);
      assert::is_true(items.remove(3));
      collection_assert::are_equal({1}, items);
      assert::is_true(items.remove(1));
      collection_assert::is_empty(items);
      assert::is_false(items.remove(1));
      collection_assert::is_empty(items);
    }
    
    void test_method_(remove_all) {
      auto items = list {1, 2, 3, 4, 5};
      assert::are_equal(0_z, items.remove_all(delegate_(auto n) {return n > 5;}));
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      assert::are_equal(2_z, items.remove_all(delegate_(auto n) {return n % 2 == 0;}));
      collection_assert::are_equal({1, 3, 5}, items);
      assert::are_equal(3_z, items.remove_all(delegate_(auto n) {return n % 2 != 0;}));
      collection_assert::is_empty(items);
      assert::are_equal(0_z, items.remove_all(delegate_(auto n) {return n % 2 != 0;}));
      collection_assert::is_empty(items);
    }
    
    void test_method_(remove_at) {
      auto items = list {1, 2, 3, 4, 5};
      assert::throws<argument_out_of_range_exception>(delegate_ {items.remove_at(5);});
      items.remove_at(0);
      collection_assert::are_equal({2, 3, 4, 5}, items);
      items.remove_at(3);
      collection_assert::are_equal({2, 3, 4}, items);
      items.remove_at(1);
      collection_assert::are_equal({2, 4}, items);
      items.remove_at(1);
      collection_assert::are_equal({2}, items);
      items.remove_at(0);
      collection_assert::is_empty(items);
    }
    
    void test_method_(remove_range) {
      auto items = list {1, 2, 3, 4, 5};
      assert::throws<argument_out_of_range_exception>(delegate_ {items.remove_range(6, 0);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.remove_range(0, 6);});
      items.remove_range(0, items.count());
      collection_assert::is_empty(items);
      items = {1, 2, 3, 4, 5};
      items.remove_range(1, 3);
      collection_assert::are_equal({1, 5}, items);
      items.remove_range(0, 2);
      collection_assert::is_empty(items);
    }
    
    void test_method_(reverse) {
      auto items = list {1, 2, 3, 4, 5};
      items.reverse();
      collection_assert::are_equal({5, 4, 3, 2, 1}, items);
    }
    
    void test_method_(reverse_with_index_and_count) {
      auto items = list {1, 2, 3, 4, 5};
      assert::throws<argument_out_of_range_exception>(delegate_ {items.reverse(6, 0);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.reverse(0, 6);});
      items.reverse(0, items.count());
      collection_assert::are_equal({5, 4, 3, 2, 1}, items);
      items.reverse(1, 3);
      collection_assert::are_equal({5, 2, 3, 4, 1}, items);
      items.reverse(3, 1);
      collection_assert::are_equal({5, 2, 3, 4, 1}, items);
    }
    
    void test_method_(slice) {
      auto items = list {1, 2, 3, 4, 5};
      assert::throws<argument_out_of_range_exception>(delegate_ {items.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.slice(0, 6);});
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.slice(0, items.count()));
      collection_assert::are_equal({2, 3, 4}, items.slice(1, 3));
      collection_assert::are_equal({3}, items.slice(2, 1));
      collection_assert::is_empty(items.slice(1, 0));
    }
    
    void test_method_(sort) {
      auto items = list {1, 5, 3, 4, 2};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.sort());
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.sort());
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
    }
    
    void test_method_(sort_with_comparison) {
      auto items = list {1, 5, 3, 4, 2};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.sort(comparison<const int&> {delegate_(auto a, auto b) {return a < b ? -1 : a > b ? 1 : 0;}}));
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      collection_assert::are_equal({5, 4, 3, 2, 1}, items.sort(comparison<const int&> {delegate_(auto a, auto b) {return a < b ? 1 : a > b ? -1 : 0;}}));
      collection_assert::are_equal({5, 4, 3, 2, 1}, items);
    }
    
    void test_method_(sort_with_icomparer) {
      auto items = list {1, 5, 3, 4, 2};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.sort(comparer<int>::default_comparer));
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
    }
    
    void test_method_(sort_with_index_count_and_icomparer) {
      auto items = list {1, 5, 3, 4, 2};
      assert::throws<argument_out_of_range_exception>(delegate_ {items.sort(6, 0, comparer<int>::default_comparer);});
      assert::throws<argument_out_of_range_exception>(delegate_ {items.sort(0, 6, comparer<int>::default_comparer);});
      collection_assert::are_equal({1, 2, 3, 4, 5}, items.sort(0, items.count(), comparer<int>::default_comparer));
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      items = {1, 5, 3, 4, 2};
      collection_assert::are_equal({1, 3, 4, 5, 2}, items.sort(1, 3, comparer<int>::default_comparer));
      collection_assert::are_equal({1, 3, 4, 5, 2}, items);
      items = {1, 5, 3, 4, 2};
      collection_assert::are_equal({1, 5, 3, 4, 2}, items.sort(2, 1, comparer<int>::default_comparer));
      collection_assert::are_equal({1, 5, 3, 4, 2}, items);
    }
    
    void test_method_(to_array) {
      auto items = list {1, 2, 3, 4, 5};
      auto result = items.to_array();
      assert::are_equal(typeof_<array<int>>(), typeof_(result));
      collection_assert::are_equal({1, 2, 3, 4, 5}, result);
    }
    
    void test_method_(to_String) {
      assert::are_equal("[]", list<int> {}.to_string());
      assert::are_equal("[1, 2, 3, 4, 5]", list {1, 2, 3, 4, 5}.to_string());
      assert::are_equal("[one, two, three, four, five]", list {"one", "two", "three", "four", "five"}.to_string());
    }
    
    void test_method_(trim_excess) {
      auto items = list<int> {};
      items.capacity(256);
      assert::is_greater_or_equal(items.capacity(), 256_z);
      items.add_range({1, 2, 3, 4, 5});
      items.trim_excess();
      assert::are_equal(5_z, items.capacity());
    }
    
    void test_method_(true_for_all) {
      auto items = list {1, 2, 3, 4, 5};
      assert::is_false(items.true_for_all(delegate_(auto n) {return n % 2 == 0;}));
      assert::is_true(items.true_for_all(delegate_(auto n) {return n < 6;}));
    }
    
    void test_method_(equal_operator_with_list) {
      auto items = list {1, 2, 3, 4, 5};
      auto result = list<int> {};
      collection_assert::is_empty(result);
      result = items;
      collection_assert::are_equal({1, 2, 3, 4, 5}, result);
    }
    
    void test_method_(equal_operator_with_move_list) {
      auto items = list {1, 2, 3, 4, 5};
      auto result = list<int> {};
      collection_assert::is_empty(result);
      result = std::move(items);
      collection_assert::are_equal({1, 2, 3, 4, 5}, result);
      collection_assert::is_empty(items);
    }
    
    void test_method_(index_operators) {
      auto items = list {84, 42, 21};
      
      assert::are_equal(84, items[0]);
      assert::are_equal(42, items[1]);
      assert::are_equal(21, items[2]);
      assert::throws<index_out_of_range_exception>(delegate_ {[[maybe_unused]] auto i = items[3];});
      
      items[0] = 63;
      items[1] = 31;
      items[2] = 10;
      assert::throws<index_out_of_range_exception>(delegate_ {items[3] = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(index_operators_with_epos) {
      auto items = list {1, 2, 3, 4, 5};
      
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
    
    void test_method_(cast_opertor_to_std_vector) {
      auto items = list {1, 2, 3, 4, 5};
      auto result = std::vector<int> {};
      collection_assert::is_empty(result);
      result = items;
      collection_assert::are_equal({1, 2, 3, 4, 5}, result);
    }
  };
}
