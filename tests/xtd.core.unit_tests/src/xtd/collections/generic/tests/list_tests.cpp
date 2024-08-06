#include <xtd/collections/generic/list>
#include <xtd/as>
#include <xtd/boolean>
#include <xtd/environment>
#include <xtd/int64_object>
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
      assert::are_equal(typeof_<int>(), typeof_<list<int>::value_type>(), csf_);
    }
    
    void test_method_(value_type_bool) {
      assert::are_equal(typeof_<bool>(), typeof_<list<bool>::value_type>(), csf_);
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<list<int>::base_type>(), csf_);
    }
    
    void test_method_(base_type_bool) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<list<bool>::base_type>(), csf_);
    }

    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<list<int>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<list<int>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<list<int>::reference>(), csf_);
    }

    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<list<int>::const_reference>(), csf_);
    }

    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<list<int>::pointer>(), csf_);
    }

    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<list<int>::const_pointer>(), csf_);
    }

    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<list<int>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<list<int>::const_iterator>(), csf_);
    }

    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::reverse_iterator>(), typeof_<list<int>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::const_reverse_iterator>(), typeof_<list<int>::const_reverse_iterator>(), csf_);
    }

    void test_method_(default_constructor) {
      auto items = list<ustring> {};
      assert::is_zero(items.capacity(), csf_);
      assert::is_zero(items.count(), csf_);
      collection_assert::is_empty(items, csf_);
    }
    
    void test_method_(constructor_with_count) {
      auto items = list<boolean>(3);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({false, false, false}, items, csf_);
    }

    void test_method_(constructor_with_count_and_type) {
      auto items = list<int>(3, 42);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({42, 42, 42}, items, csf_);
    }

    void test_method_(constructor_with_iterators) {
      std::vector v = {84, 42, 21};
      auto items = list<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(bt);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_list) {
      list l = {84, 42, 21};
      auto items = list(l);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_move_list) {
      list l = {84, 42, 21};
      auto items = list(std::move(l));
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
      collection_assert::is_empty(l, csf_);
    }

    void test_method_(constructor_with_move_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(std::move(bt));
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
      collection_assert::is_empty(bt, csf_);
    }
    
    void test_method_(const_back) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, items.back(), csf_);
    }
    
    void test_method_(back) {
      auto items = list {84, 42, 21};
      items.back() = 5;
      assert::are_equal(5, items.back(), csf_);
    }
    
    void test_method_(begin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.begin(), csf_);
    }
    
    void test_method_(capaciy) {
      auto items = list {84, 42, 21};
      assert::are_equal(3_z, items.count(), csf_);

      items.capacity(42);
      assert::are_equal(42_z, items.capacity(), csf_);
      assert::are_equal(3_z, items.count(), csf_);
    }

    void test_method_(cbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.cbegin(), csf_);
    }

    void test_method_(cend) {
      auto items = list {84, 42, 21};
      assert::throws<argument_out_of_range_exception>([&] {*items.cend();}, csf_);
    }
    
    void test_method_(count) {
      auto items = list<int> {};
      assert::is_zero(items.count(), csf_);
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.count(), csf_);
      items.resize(50);
      assert::are_equal(50_z, items.count(), csf_);
    }

    void test_method_(crbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, *items.crbegin(), csf_);
    }
    
    void test_method_(crend) {
      auto items = list {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.crend();}, csf_);
    }
    
    void test_method_(data) {
      auto items = list {84, 42, 21};
      
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
      assert::is_true(list<int> {}.empty(), csf_);
      assert::is_false(list<int> {42}.empty(), csf_);

      auto items = list<int> {};
      assert::is_true(items.empty(), csf_);
      items.capacity(42);
      assert::is_true(items.empty(), csf_);
      items.resize(1);
      assert::is_false(items.empty(), csf_);
      items.resize(0);
      assert::is_true(items.empty(), csf_);
      items.push_back(42);
      assert::is_false(items.empty(), csf_);
    }
    
    void test_method_(end) {
      auto items = list {84, 42, 21};
      assert::throws<argument_out_of_range_exception>([&] {*items.end();}, csf_);
    }
    
    void test_method_(front) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, items.front(), csf_);

      assert::throws<argument_out_of_range_exception>([&] {list<int> {}.front();}, csf_);
    }

    void test_method_(is_fixed_size) {
      // Is always false;
      assert::is_false(list<int> {}.is_fixed_size(), csf_);
    }

    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(list<int> {}.is_read_only(), csf_);
    }

    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(list<int> {}.is_synchronized(), csf_);
    }
    
    void test_method_(max_size) {
      assert::are_equal(as<xtd::size>(environment::os_version().is_linux() ? int64_object::max_value / 4 : int64_object::max_value / 2), list<int> {}.max_size(), csf_);
    }
    
    void test_method_(rbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, *items.rbegin(), csf_);
    }
    
    void test_method_(rend) {
      auto items = list {84, 42, 21};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.rend();}, csf_);
    }

    void test_method_(size) {
      auto items = list<int> {};
      assert::is_zero(items.size(), csf_);
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.size(), csf_);
      items.resize(50);
      assert::are_equal(50_z, items.size(), csf_);
    }
    
    void test_method_(sync_root) {
      auto a = list<int> {};
      auto b = list<int> {};
      assert::are_not_equal(a.sync_root(), b.sync_root(), csf_);
      
      auto synchronized_items = list<int> {};
      
      delegate<void()> {[&] {
        lock_ (synchronized_items.sync_root()) {
          synchronized_items.add(1);
          threading::thread::sleep(2);
          synchronized_items.add(2);
          synchronized_items.add(3);
        }
      }}.begin_invoke();

      delegate<void()> {[&] {
        lock_ (synchronized_items.sync_root()) {
          synchronized_items.add(4);
          synchronized_items.add(5);
          synchronized_items.add(6);
        }
      }}.begin_invoke();

      threading::thread::sleep(10);
      lock_ (synchronized_items.sync_root()) {
        collection_assert::are_equal({1, 2, 3, 4, 5, 6}, synchronized_items);
      }      
    }
  };
}
