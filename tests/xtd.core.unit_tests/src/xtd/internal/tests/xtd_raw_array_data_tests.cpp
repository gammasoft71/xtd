#define __XTD_CORE_INTERNAL__
#include <xtd/internal/__xtd_raw_array_data.hpp>
#undef  __XTD_CORE_INTERNAL__
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

#include <xtd/diagnostics/debug>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::internal::tests {
  class test_class_(xtd_raw_array_data_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<__xtd_raw_array_data__<int>::value_type>());
    }
    
    void test_method_(value_type_with_bool) {
      assert::are_equal(typeof_<bool>(), typeof_<__xtd_raw_array_data__<bool>::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<__xtd_raw_array_data__<int>::base_type > ());
    }
    
    void test_method_(base_type_with_bool) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<__xtd_raw_array_data__<bool>::base_type > ());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<__xtd_raw_array_data__<int>::size_type>());
    }
    
    void test_method_(size_type_with_bool) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type::size_type>(), typeof_<__xtd_raw_array_data__<int>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<__xtd_raw_array_data__<int>::difference_type>());
    }
    
    void test_method_(difference_type_with_bool) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type::difference_type>(), typeof_<__xtd_raw_array_data__<int>::difference_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<__xtd_raw_array_data__<int>::reference>());
    }
    
    void test_method_(reference_with_bool) {
      assert::are_equal(typeof_<bool&>(), typeof_<__xtd_raw_array_data__<bool>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<__xtd_raw_array_data__<int>::const_reference>());
    }
    
    void test_method_(const_reference_with_bool) {
      assert::are_equal(typeof_<const bool&>(), typeof_<__xtd_raw_array_data__<bool>::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<__xtd_raw_array_data__<int>::pointer>());
    }
    
    void test_method_(pointer_with_bool) {
      assert::are_equal(typeof_<bool*>(), typeof_<__xtd_raw_array_data__<bool>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<__xtd_raw_array_data__<int>::const_pointer>());
    }
    
    void test_method_(const_pointer_with_bool) {
      assert::are_equal(typeof_<const bool*>(), typeof_<__xtd_raw_array_data__<bool>::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::base_type::iterator>(), typeof_<__xtd_raw_array_data__<int>::iterator::iterator_base_type>());
    }
    
    void test_method_(iterator_with_bool) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type::iterator>(), typeof_<__xtd_raw_array_data__<bool>::iterator::iterator_base_type>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::base_type::const_iterator>(), typeof_<__xtd_raw_array_data__<int>::const_iterator::iterator_base_type>());
    }
    
    void test_method_(const_iterator_with_bool) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type::const_iterator>(), typeof_<__xtd_raw_array_data__<bool>::const_iterator::iterator_base_type>());
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<std::reverse_iterator<__xtd_raw_array_data__<int>::iterator>>(), typeof_<__xtd_raw_array_data__<int>::reverse_iterator > ());
    }
    
    void test_method_(reverse_iterator_with_bool) {
      assert::are_equal(typeof_<std::reverse_iterator<__xtd_raw_array_data__<bool>::iterator>>(), typeof_<__xtd_raw_array_data__<bool>::reverse_iterator > ());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<std::reverse_iterator<__xtd_raw_array_data__<int>::const_iterator>>(), typeof_<__xtd_raw_array_data__<int>::const_reverse_iterator > ());
    }
    
    void test_method_(const_reverse_iterator_with_bool) {
      assert::are_equal(typeof_<std::reverse_iterator<__xtd_raw_array_data__<bool>::const_iterator>>(), typeof_<__xtd_raw_array_data__<bool>::const_reverse_iterator > ());
    }
    
    void test_method_(default_constructor) {
      auto items = __xtd_raw_array_data__<int> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    void test_method_(default_constructor_with_bool) {
      auto items = __xtd_raw_array_data__<bool> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_count) {
      auto items = __xtd_raw_array_data__<int>(3);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({0, 0, 0}, items);
    }
    
    void test_method_(constructor_with_bool_and_count) {
      auto items = __xtd_raw_array_data__<bool>(3);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({false, false, false}, items);
    }
    
    void test_method_(constructor_with_count_and_type) {
      auto items = __xtd_raw_array_data__<int>(3, 42);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({42, 42, 42}, items);
    }
    
    void test_method_(constructor_with_bool_count_and_type) {
      auto items = __xtd_raw_array_data__<bool>(3, true);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, true, true}, items);
    }
    
    void test_method_(constructor_with_iterators) {
      auto v = std::vector {84, 42, 21};
      auto items = __xtd_raw_array_data__<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_bool_and_iterators) {
      auto v = std::vector {true, false, true};
      auto items = __xtd_raw_array_data__<bool>(v.begin(), v.end());
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, false, true}, items);
    }
    
    void test_method_(constructor_with_base_type) {
      auto bt = __xtd_raw_array_data__<int>::base_type {84, 42, 21};
      auto items = __xtd_raw_array_data__<int>(bt);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_base_type_of_bool) {
      auto bt = __xtd_raw_array_data__<bool>::base_type {true, false, true};
      auto items = __xtd_raw_array_data__<bool>(bt);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, false, true}, items);
    }
    
    void test_method_(constructor_with_xtd_vector) {
      auto v = __xtd_raw_array_data__ {84, 42, 21};
      auto items = __xtd_raw_array_data__(v);
      v.push_back(10);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_xtd_vector_of_bool) {
      auto v = __xtd_raw_array_data__ {true, false, true};
      auto items = __xtd_raw_array_data__(v);
      v.push_back(false);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, false, true}, items);
    }
    
    void test_method_(constructor_with_move_xtd_vector) {
      auto v = __xtd_raw_array_data__ {84, 42, 21};
      auto items = __xtd_raw_array_data__(std::move(v));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(v);
    }
    
    void test_method_(constructor_with_move_xtd_vector_of_bool) {
      auto v = __xtd_raw_array_data__ {true, false, true};
      auto items = __xtd_raw_array_data__(std::move(v));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, false, true}, items);
      collection_assert::is_empty(v);
    }
    
    void test_method_(constructor_with_move_base_type) {
      auto bt = __xtd_raw_array_data__<int>::base_type {84, 42, 21};
      auto items = __xtd_raw_array_data__<int>(std::move(bt));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(bt);
    }
    
    void test_method_(constructor_with_move_base_type_of_bool) {
      auto bt = __xtd_raw_array_data__<bool>::base_type {true, false, true};
      auto items = __xtd_raw_array_data__<bool>(std::move(bt));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({true, false, true}, items);
      collection_assert::is_empty(bt);
    }
    
    void test_method_(const_back) {
      assert::are_equal(21, __xtd_raw_array_data__ {84, 42, 21}.back());
      assert::throws<std::out_of_range>([] {__xtd_raw_array_data__<int> {}.back();});
    }
    
    void test_method_(const_back_with_bool) {
      assert::are_equal(true, __xtd_raw_array_data__ {true, false, true}.back());
      assert::throws<std::out_of_range>([] {__xtd_raw_array_data__<bool> {}.back();});
    }
    
    void test_method_(back) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.back() = 5;
      assert::are_equal(5, items.back());
      auto empty_items = __xtd_raw_array_data__<int> {};
      assert::throws<std::out_of_range>([&] {empty_items.back() = 5;});
    }
    
    void test_method_(back_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.back() = false;
      assert::are_equal(false, items.back());
      auto empty_items = __xtd_raw_array_data__<bool> {};
      assert::throws<std::out_of_range>([&] {empty_items.back() = false;});
    }
    
    void test_method_(begin) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(typeof_<int>(), typeof_(*items.begin()));
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(begin_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true, false};
      assert::are_equal(typeof_<bool>(), typeof_(*items.begin()));
      assert::are_equal(true, *items.begin());
    }
    
    void test_method_(capaciy) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(3_z, items.size());
      
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.size());
    }
    
    void test_method_(capaciy_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      assert::are_equal(3_z, items.size());
      
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.size());
    }
    
    void test_method_(cbegin) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(84, *items.cbegin());
    }
    
    void test_method_(cbegin_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true, false};
      assert::are_equal(true, *items.cbegin());
    }
    
    void test_method_(cend) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.cend();});
      assert::is_true(items.cend() == items.cbegin() + items.size());
    }
    
    void test_method_(cend_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true, false};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.cend();});
      assert::is_true(items.cend() == items.cbegin() + items.size());
    }
    
    void test_method_(crbegin) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(typeof_<int>(), typeof_(*items.crbegin()));
      assert::are_equal(21, *items.crbegin());
    }
    
    void test_method_(crbegin_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true, false};
      assert::are_equal(typeof_<bool>(), typeof_(*items.crbegin()));
      assert::are_equal(false, *items.crbegin());
    }
    
    void test_method_(crend) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.crend();});
      assert::is_true(items.crend() == items.crbegin() + items.size());
    }
    
    void test_method_(crend_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true, false};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.crend();});
      assert::is_true(items.crend() == items.crbegin() + items.size());
    }
    
    void test_method_(data) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      
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
    
    void test_method_(data_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      
      auto ptr = items.data();
      assert::are_equal(true, *ptr);
      assert::are_equal(false, *(ptr + 1));
      assert::are_equal(true, *(ptr + 2));
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //assert::are_equal(false, *(ptr + 3));
      
      *(ptr) = false;
      *(ptr + 1) = true;
      *(ptr + 2) = false;
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //*(ptr + 3) = true;
      
      collection_assert::are_equal({false, true, false}, items);
    }
    
    void test_method_(empty) {
      assert::is_true(__xtd_raw_array_data__<int> {}.empty());
      assert::is_false(__xtd_raw_array_data__<int> {42}.empty());
      
      auto items = __xtd_raw_array_data__<int> {};
      assert::is_true(items.empty());
      items.reserve(42);
      assert::is_true(items.empty());
      items.resize(1);
      assert::is_false(items.empty());
      items.resize(0);
      assert::is_true(items.empty());
      items.push_back(42);
      assert::is_false(items.empty());
    }
    
    void test_method_(empty_with_bool) {
      assert::is_true(__xtd_raw_array_data__<bool> {}.empty());
      assert::is_false(__xtd_raw_array_data__<bool> {true}.empty());
      
      auto items = __xtd_raw_array_data__<int> {};
      assert::is_true(items.empty());
      items.reserve(42);
      assert::is_true(items.empty());
      items.resize(1);
      assert::is_false(items.empty());
      items.resize(0);
      assert::is_true(items.empty());
      items.push_back(true);
      assert::is_false(items.empty());
    }
    
    void test_method_(end) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.end();});
      assert::is_true(items.end() == items.begin() + items.size());
    }
    
    void test_method_(end_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.end();});
      assert::is_true(items.end() == items.begin() + items.size());
    }
    
    void test_method_(front_const) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(84, items.front());
      assert::throws<std::out_of_range>([&] {__xtd_raw_array_data__<int> {}.front();});
    }
    
    void test_method_(front_const_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      assert::are_equal(true, items.front());
      assert::throws<std::out_of_range>([&] {__xtd_raw_array_data__<bool> {}.front();});
    }
    
    void test_method_(front) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.front() = 10;
      assert::are_equal(10, items.front());
      auto empty_items = __xtd_raw_array_data__<int> {};
      assert::throws<std::out_of_range>([&] {empty_items.front() = 10;});
    }
    
    void test_method_(front_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.front() = false;
      assert::are_equal(false, items.front());
      auto empty_items = __xtd_raw_array_data__<bool> {};
      assert::throws<std::out_of_range>([&] {empty_items.front() = true;});
    }
    
    void test_method_(items_const) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::base_type>(), typeof_(__xtd_raw_array_data__ {1, 2, 3, 4, 5}.items()));
      collection_assert::are_equal({1, 2, 3, 4, 5}, __xtd_raw_array_data__ {1, 2, 3, 4, 5}.items());
    }
    
    void test_method_(items_const_with_bool) {
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type>(), typeof_(__xtd_raw_array_data__ {true, false, true, false}.items()));
      collection_assert::are_equal({1u, 0u, 1u, 0u}, __xtd_raw_array_data__ {true, false, true, false}.items());
    }
    
    void test_method_(items) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::base_type>(), typeof_(items.items()));
      
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
    
    void test_method_(items_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type>(), typeof_(items.items()));
      
      auto& inners = items.items();
      assert::are_equal(1u, inners[0]);
      assert::are_equal(0u, inners[1]);
      assert::are_equal(1u, inners[2]);
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::are_equal(false, inners[3]);
      
      inners[0] = false;
      inners[1] = true;
      inners[2] = false;
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //inners[3] = true;
      
      collection_assert::are_equal({false, true, false}, items);
    }
    
    void test_method_(max_size) {
      assert::is_not_zero(__xtd_raw_array_data__<int> {}.max_size());
    }
    
    void test_method_(max_size_with_bool) {
      assert::is_not_zero(__xtd_raw_array_data__<bool> {}.max_size());
    }
    
    void test_method_(rbegin) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      assert::are_equal(typeof_<int>(), typeof_(*items.rbegin()));
      assert::are_equal(21, *items.rbegin());
    }
    
    void test_method_(rbegin_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      assert::are_equal(typeof_<bool>(), typeof_(*items.rbegin()));
      assert::are_equal(true, *items.rbegin());
    }
    
    void test_method_(rend) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.rend();});
      assert::is_true(items.rend() == items.rbegin() + items.size());
    }
    
    void test_method_(rend_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.rend();});
      assert::is_true(items.rend() == items.rbegin() + items.size());
    }
    
    void test_method_(size) {
      auto items = __xtd_raw_array_data__<int> {};
      assert::is_zero(items.size());
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(size_with_bool) {
      auto items = __xtd_raw_array_data__<bool> {};
      assert::is_zero(items.size());
      items.push_back(true);
      items.push_back(false);
      items.push_back(true);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(assign_with_count_and_value) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.assign(4, 63);
      collection_assert::are_equal({63, 63, 63, 63}, items);
    }
    
    void test_method_(assign_with_count_value_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.assign(4, true);
      collection_assert::are_equal({true, true, true, true}, items);
    }
    
    void test_method_(assign_with_iterators) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = std::vector {10, 20, 30, 40};
      items.assign(items2.begin(), items2.end());
      collection_assert::are_equal({10, 20, 30, 40}, items);
    }
    
    void test_method_(assign_with_iterators_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto items2 = std::vector {false, true, true, false};
      items.assign(items2.begin(), items2.end());
      collection_assert::are_equal({false, true, true, false}, items);
    }
    
    void test_method_(assign_with_initializer_list) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.assign({10, 20, 30, 40});
      collection_assert::are_equal({10, 20, 30, 40}, items);
    }
    
    void test_method_(assign_with_initializer_list_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.assign({false, true, true, false});
      collection_assert::are_equal({false, true, true, false}, items);
    }
    
    void test_method_(at) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      
      assert::are_equal(84, items.at(0));
      assert::are_equal(42, items.at(1));
      assert::are_equal(21, items.at(2));
      assert::throws<std::out_of_range>([&] {[[maybe_unused]] auto i = items.at(3);});
      
      items.at(0) = 63;
      items.at(1) = 31;
      items.at(2) = 10;
      assert::throws<std::out_of_range>([&] {items.at(3) = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(at_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      
      assert::are_equal(true, items.at(0));
      assert::are_equal(false, items.at(1));
      assert::are_equal(true, items.at(2));
      assert::throws<std::out_of_range>([&] {[[maybe_unused]] auto i = items.at(3);});
      
      items.at(0) = false;
      items.at(1) = true;
      items.at(2) = false;
      assert::throws<std::out_of_range>([&] {items.at(3) = true;});
      
      collection_assert::are_equal({false, true, false}, items);
    }
    
    void test_method_(clear) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.clear();
      assert::are_equal(0_z, items.size());
    }
    
    void test_method_(clear_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.clear();
      assert::are_equal(0_z, items.size());
    }
    
    void test_method_(emplace) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.emplace(items.begin() + 2, 63);
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(emplace_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.emplace(items.begin() + 2, false);
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(emplace_back) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.emplace_back(63);
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(emplace_back_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.emplace_back(false);
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(erase_with_pos) {
      auto items = __xtd_raw_array_data__ {84, 42, 21, 63, 75, 96};
      items.erase(items.begin() + 2);
      collection_assert::are_equal({84, 42, 63, 75, 96}, items);
    }
    
    void test_method_(erase_with_pos_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, false, true, true, false};
      items.erase(items.begin() + 2);
      collection_assert::are_equal({true, false, true, true, false}, items);
    }
    
    void test_method_(erase_with_first_and_last) {
      auto items = __xtd_raw_array_data__ {84, 42, 21, 63, 75, 96};
      items.erase(items.begin() + 2, items.begin() + 5);
      collection_assert::are_equal({84, 42, 96}, items);
    }
    
    void test_method_(erase_with_first_last_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, false, true, true, false};
      items.erase(items.begin() + 2, items.begin() + 5);
      collection_assert::are_equal({true, false, false}, items);
    }
    
    void test_method_(get_allocator) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto allocator = items.get_allocator();
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::allocator_type>(), typeof_(allocator));
    }
    
    void test_method_(get_allocator_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto allocator = items.get_allocator();
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::allocator_type>(), typeof_(allocator));
    }
    
    void test_method_(insert) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.insert(items.begin() + 2, 63);
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(insert_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.insert(items.begin() + 2, false);
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(insert_with_move) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto v = 63;
      items.insert(items.begin() + 2, std::move(v));
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(insert_with_move_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto v = false;
      items.insert(items.begin() + 2, std::move(v));
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(insert_with_count) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.insert(items.begin() + 2, 3, 63);
      collection_assert::are_equal({84, 42, 63, 63, 63, 21}, items);
    }
    
    void test_method_(insert_with_count_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.insert(items.begin() + 2, 3, false);
      collection_assert::are_equal({true, false, false, false, false, true}, items);
    }
    
    void test_method_(insert_with_count_and_move) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto v = 63;
      items.insert(items.begin() + 2, 3, std::move(v));
      collection_assert::are_equal({84, 42, 63, 63, 63, 21}, items);
    }
    
    void test_method_(insert_with_count_move_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto v = false;
      items.insert(items.begin() + 2, 3, std::move(v));
      collection_assert::are_equal({true, false, false, false, false, true}, items);
    }
    
    void test_method_(insert_with_iterators) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = std::vector {10, 20, 30, 40};
      items.insert(items.begin() + 2, items2.begin(), items2.end());
      collection_assert::are_equal({84, 42, 10, 20, 30, 40, 21}, items);
    }
    
    void test_method_(insert_with_iterators_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto items2 = std::vector {false, true, true, false};
      items.insert(items.begin() + 2, items2.begin(), items2.end());
      collection_assert::are_equal({true, false, false, true, true, false, true}, items);
    }
    
    void test_method_(insert_with_initializer_list) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.insert(items.begin() + 2, {10, 20, 30, 40});
      collection_assert::are_equal({84, 42, 10, 20, 30, 40, 21}, items);
    }
    
    void test_method_(insert_with_initializer_list_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.insert(items.begin() + 2, {false, true, true, false});
      collection_assert::are_equal({true, false, false, true, true, false, true}, items);
    }
    
    void test_method_(pop_back) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.pop_back();
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(pop_back_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.pop_back();
      collection_assert::are_equal({true, false}, items);
    }
    
    void test_method_(push_back) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.push_back(63);
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(push_back_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.push_back(false);
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(push_back_with_move) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto v = 63;
      items.push_back(std::move(v));
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(push_back_with_move_and_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto v = false;
      items.push_back(std::move(v));
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(reserve) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
    }
    
    void test_method_(reserve_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
    }
    
    void test_method_(resize) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.resize(4);
      collection_assert::are_equal({84, 42, 21, 0}, items);
      items.resize(2);
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(resize_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.resize(4);
      collection_assert::are_equal({true, false, true, false}, items);
      items.resize(2);
      collection_assert::are_equal({true, false}, items);
    }
    
    void test_method_(shrink_to_fit) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      items.reserve(42);
      items.shrink_to_fit();
      assert::is_less(items.capacity(), 42_z);
    }
    
    void test_method_(shrink_to_fit_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      items.reserve(42);
      items.shrink_to_fit();
      assert::is_less(items.capacity(), 42_z);
    }
    
    void test_method_(swap) {
      auto items1 = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = __xtd_raw_array_data__ {63, 75, 96};
      items1.swap(items2);
      collection_assert::are_equal({63, 75, 96}, items1);
      collection_assert::are_equal({84, 42, 21}, items2);
    }
    
    void test_method_(swap_with_bool) {
      auto items1 = __xtd_raw_array_data__ {true, false, true};
      auto items2 = __xtd_raw_array_data__ {false, true, false};
      items1.swap(items2);
      collection_assert::are_equal({false, true, false}, items1);
      collection_assert::are_equal({true, false, true}, items2);
    }
    
    void test_method_(operator_equal) {
      auto items1 = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = __xtd_raw_array_data__ {63, 75, 96};
      items1 = items2;
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_bool) {
      auto items1 = __xtd_raw_array_data__ {true, false, true};
      auto items2 = __xtd_raw_array_data__ {false, true, false};
      items1 = items2;
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_equal_wtih_move) {
      auto items1 = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = __xtd_raw_array_data__ {63, 75, 96};
      items1 = std::move(items2);
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_move_and_bool) {
      auto items1 = __xtd_raw_array_data__ {true, false, true};
      auto items2 = __xtd_raw_array_data__ {false, true, false};
      items1 = std::move(items2);
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_equal_with_initializer_list) {
      auto items1 = __xtd_raw_array_data__ {84, 42, 21};
      auto items2 = {63, 75, 96};
      items1 = items2;
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_initializer_list_and_bool) {
      auto items1 = __xtd_raw_array_data__ {true, false, true};
      auto items2 = {false, true, false};
      items1 = items2;
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_index) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      
      assert::are_equal(84, items[0]);
      assert::are_equal(42, items[1]);
      assert::are_equal(21, items[2]);
      //assert::throws<std::out_of_range>([&] {[[maybe_unused]] auto i = items[3];});
      
      items[0] = 63;
      items[1] = 31;
      items[2] = 10;
      //assert::throws<std::out_of_range>([&] {items[3] = 5;});
      
      collection_assert::are_equal({63, 31, 10}, items);
    }
    
    void test_method_(operator_index_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      
      assert::are_equal(true, items[0]);
      assert::are_equal(false, items[1]);
      assert::are_equal(true, items[2]);
      //assert::throws<std::out_of_range>([&] {[[maybe_unused]] auto i = items[3];});
      
      items[0] = false;
      items[1] = true;
      items[2] = false;
      //assert::throws<std::out_of_range>([&] {items[3] = true;});
      
      collection_assert::are_equal({false, true, false}, items);
    }
    
    void test_method_(operator_base_type) {
      auto items = __xtd_raw_array_data__ {84, 42, 21};
      auto bt = __xtd_raw_array_data__<int>::base_type {};
      bt = items;
      assert::are_equal(typeof_<__xtd_raw_array_data__<int>::base_type>(), typeof_(bt));
      collection_assert::are_equal({84, 42, 21}, bt);
    }
    
    void test_method_(operator_base_type_with_bool) {
      auto items = __xtd_raw_array_data__ {true, false, true};
      auto bt = __xtd_raw_array_data__<bool>::base_type {};
      bt = items;
      assert::are_equal(typeof_<__xtd_raw_array_data__<bool>::base_type>(), typeof_(bt));
      collection_assert::are_equal({1u, 0u, 1u}, bt);
    }
  };
}
