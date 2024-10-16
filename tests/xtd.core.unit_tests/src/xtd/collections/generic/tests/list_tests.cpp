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
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<list<int>::base_type>());
    }
    
    void test_method_(base_type_bool) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<list<bool>::base_type>());
    }

    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<list<int>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<list<int>::difference_type>());
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

    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<list<int>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<list<int>::const_iterator>());
    }

    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::reverse_iterator>(), typeof_<list<int>::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::const_reverse_iterator>(), typeof_<list<int>::const_reverse_iterator>());
    }

    void test_method_(default_constructor) {
      auto items = list<string> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_count) {
      auto items = list<boolean>(3);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({false, false, false}, items);
    }

    void test_method_(constructor_with_count_and_type) {
      auto items = list<int>(3, 42);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({42, 42, 42}, items);
    }

    void test_method_(constructor_with_iterators) {
      std::vector v = {84, 42, 21};
      auto items = list<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }

    void test_method_(constructor_with_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(bt);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }

    void test_method_(constructor_with_list) {
      list l = {84, 42, 21};
      auto items = list(l);
      l.add(10);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }

    void test_method_(constructor_with_move_list) {
      list l = {84, 42, 21};
      auto items = list(std::move(l));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(l);
    }

    void test_method_(constructor_with_move_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(std::move(bt));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(bt);
    }
    
    void test_method_(const_back) {
      assert::are_equal(21, list {84, 42, 21}.back());
      assert::throws<index_out_of_range_exception>([] {list<int> {}.back();});
    }
    
    void test_method_(back) {
      auto items = list {84, 42, 21};
      items.back() = 5;
      assert::are_equal(5, items.back());
      auto empty_items = list<int> {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.back() = 5;});
    }
    
    void test_method_(begin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(capaciy) {
      auto items = list {84, 42, 21};
      assert::are_equal(3_z, items.count());

      items.capacity(42);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.count());
    }

    void test_method_(cbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.cbegin());
    }

    void test_method_(cend) {
      auto items = list {84, 42, 21};
      assert::throws<index_out_of_range_exception>([&] {*items.cend();});
    }
    
    void test_method_(count) {
      auto items = list<int> {};
      assert::is_zero(items.count());
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.count());
      items.resize(50);
      assert::are_equal(50_z, items.count());
    }

    void test_method_(crbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, *items.crbegin());
    }
    
    void test_method_(crend) {
      auto items = list {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.crend();});
    }
    
    void test_method_(data) {
      auto items = list {84, 42, 21};
      
      auto ptr = items.data();
      assert::are_equal(84, *ptr);
      assert::are_equal(42, *(ptr + 1));
      assert::are_equal(21, *(ptr + 2));
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //assert::are_equal(0, *(ptr + 3));
      
      *(ptr) = 63;
      *(ptr + 1) = 31;
      *(ptr + 2) = 10;
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //*(ptr + 3) = 6;
      
      collection_assert::are_equal({63, 31, 10}, items);
    }

    void test_method_(empty) {
      assert::is_true(list<int> {}.empty());
      assert::is_false(list<int> {42}.empty());

      auto items = list<int> {};
      assert::is_true(items.empty());
      items.capacity(42);
      assert::is_true(items.empty());
      items.resize(1);
      assert::is_false(items.empty());
      items.resize(0);
      assert::is_true(items.empty());
      items.push_back(42);
      assert::is_false(items.empty());
    }
    
    void test_method_(end) {
      auto items = list {84, 42, 21};
      assert::throws<index_out_of_range_exception>([&] {*items.end();});
    }
    
    void test_method_(front_const) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, items.front());
      assert::throws<index_out_of_range_exception>([&] {list<int> {}.front();});
    }
      
    void test_method_(front) {
      auto items = list {84, 42, 21};
      items.front() = 10;
      assert::are_equal(10, items.front());
      auto empty_items = list<int> {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.front() = 10;});
    }

    void test_method_(is_fixed_size) {
      // Is always false;
      assert::is_false(list<int> {}.is_fixed_size());
    }

    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(list<int> {}.is_read_only());
    }

    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(list<int> {}.is_synchronized());
    }
    
    void test_method_(items_const) {
      assert::are_equal(typeof_<list<int>::base_type>(), typeof_(list {1, 2, 3, 4, 5}.items()));
      collection_assert::are_equal({1, 2, 3, 4, 5}, list {1, 2, 3, 4, 5}.items());
    }

    void test_method_(items) {
      auto items = list {84, 42, 21};
      assert::are_equal(typeof_<array_<int>::base_type>(), typeof_(items.items()));
      
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
    
    void test_method_(max_size) {
      assert::are_equal(environment::os_version().is_linux() ? size_object::max_value / 8 : size_object::max_value / 4, list<int> {}.max_size());
    }
    
    void test_method_(rbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, *items.rbegin());
    }
    
    void test_method_(rend) {
      auto items = list {84, 42, 21};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.rend();});
    }

    void test_method_(size) {
      auto items = list<int> {};
      assert::is_zero(items.size());
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(sync_root) {
      auto a = list<int> {};
      auto b = list<int> {};
      assert::are_not_equal(a.sync_root(), b.sync_root());
      
      auto synchronized_items = list<int> {};
      
      delegate<void()> {[&] {
        lock_ (synchronized_items.sync_root()) {
          threading::thread::sleep(10);
          synchronized_items.add(1);
          synchronized_items.add(2);
          synchronized_items.add(3);
        }
      }}.begin_invoke();
      threading::thread::sleep(5);

      delegate<void()> {[&] {
        lock_ (synchronized_items.sync_root()) {
          synchronized_items.add(4);
          synchronized_items.add(5);
          synchronized_items.add(6);
        }
      }}.begin_invoke();

      threading::thread::sleep(15);
      lock_ (synchronized_items.sync_root()) {
        collection_assert::are_equal({1, 2, 3, 4, 5, 6}, synchronized_items);
      }
    }

    void test_method_(at) {
      auto items = list {84, 42, 21};
      
      assert::are_equal(84, items.at(0));
      assert::are_equal(42, items.at(1));
      assert::are_equal(21, items.at(2));
      assert::throws<index_out_of_range_exception>([&]{[[maybe_unused]] auto i = items[3];});
      
      items.at(0) = 63;
      items.at(1) = 31;
      items.at(2) = 10;
      assert::throws<index_out_of_range_exception>([&]{items[3] = 5;});
      
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
    
    void test_method_(add_range) {
      auto items = list<int> {};

      items.add_range({1, 2, 3, 4});
      collection_assert::are_equal({1, 2, 3, 4}, items);

      items.add_range(list {5, 6, 7, 8});
      collection_assert::are_equal({1, 2, 3, 4, 5, 6, 7, 8}, items);

      items.add_range(as<ienumerable<int>>(list {9, 10, 11, 12}));
      collection_assert::are_equal({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, items);
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
    
    void test_method_(copy_to) {
      auto items = list {84, 42, 21};
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
      auto items1 = list {84, 42, 21};
      auto items2 = list {84, 42, 21};
      assert::is_true(items1.equals(as<object>(items2)));
      auto items3 = list {84, 42, 33};
      assert::is_false(items1.equals(as<object>(items3)));
      auto items4 = array_ {84, 42, 21};
      assert::is_false(items1.equals(items4));
    }
    
    void test_method_(equals_list) {
      auto items1 = list {84, 42, 21};
      auto items2 = list {84, 42, 21};
      assert::is_true(items1.equals(items2));
      auto items3 = list {84, 42, 33};
      assert::is_false(items1.equals(items3));
    }
    
    void test_method_(for_each) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item: items)
        accumulator += item;
      assert::are_equal(15, accumulator);
    }

    void test_method_(get_enumerator) {
      auto items = list {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while(enumerator.move_next())
        accumulator += enumerator.current();
      assert::are_equal(15, accumulator);
    }

    void test_method_(index_operator) {
      auto items = list {84, 42, 21};
      
      assert::are_equal(84, items[0]);
      assert::are_equal(42, items[1]);
      assert::are_equal(21, items[2]);
      assert::throws<index_out_of_range_exception>([&]{[[maybe_unused]] auto i = items[3];});
      
      items[0] = 63;
      items[1] = 31;
      items[2] = 10;
      assert::throws<index_out_of_range_exception>([&]{items[3] = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
  };
}
