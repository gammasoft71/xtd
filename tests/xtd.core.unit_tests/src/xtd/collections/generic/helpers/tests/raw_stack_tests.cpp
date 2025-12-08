#include <xtd/collections/generic/helpers/raw_stack.hpp>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::collections::generic::helpers::tests {
  class test_class_(raw_stack_tests) {
    auto test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<raw_stack<int>::value_type>());
    }
    
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::stack<int>>(), typeof_<raw_stack<int>::base_type > ());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<raw_stack<int>::size_type>());
    }
    
    auto test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<raw_stack<int>::reference>());
    }
    
    auto test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<raw_stack<int>::const_reference>());
    }
    
    auto test_method_(const_iterator) {
      assert::are_equal(typeof_<raw_stack<int>::container_type::const_iterator>(), typeof_<raw_stack<int>::const_iterator> ());
    }
    
    auto test_method_(default_constructor) {
      auto items = raw_stack<int> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    auto test_method_(constructor_with_capacity) {
      auto items = raw_stack<int>(3_z);
      assert::are_equal(3_z, items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    auto test_method_(constructor_with_iterators) {
      auto v = std::vector {84, 42, 21};
      auto items = raw_stack<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(constructor_with_base_type) {
      auto bt = raw_stack<int>::base_type(std::deque<int> {84, 42, 21});
      auto items = raw_stack<int>(bt);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(constructor_with_raw_stack) {
      auto s = raw_stack<int>(std::deque<int> {84, 42, 21});
      auto items = raw_stack(s);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(constructor_with_move_raw_stack) {
      auto s = raw_stack<int>(std::deque<int> {84, 42, 21});
      auto items = raw_stack(std::move(s));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(s);
    }
    
    auto test_method_(constructor_with_move_base_type) {
      auto bt = raw_stack<int>::base_type(std::deque<int> {84, 42, 21});
      auto items = raw_stack<int>(std::move(bt));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(capacity) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(3_z, items.size());
      assert::are_equal(3_z, items.capacity());
      
      items.reserve(42);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
      
      items.shrink_to_fit();
      assert::are_equal(3_z, items.capacity());
      assert::are_equal(3_z, items.size());
    }
    
    auto test_method_(items) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_stack<int>::base_type>(), typeof_(items.items()));
      
      auto& inners = items.items();
      assert::are_equal(21, inners.top());
    }
    
    auto test_method_(items_const) {
      const auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_stack<int>::base_type>(), typeof_(items.items()));
      
      const auto& inners = items.items();
      assert::are_equal(21, inners.top());
    }
    
    auto test_method_(size) {
      auto items = raw_stack<int> {};
      assert::is_zero(items.size());
      items.push(84);
      items.push(42);
      items.push(21);
      assert::are_equal(3_z, items.size());
    }
    
    auto test_method_(begin) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.begin()));
      assert::are_equal(84, *items.begin());
    }
    
    auto test_method_(cbegin) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.cbegin()));
      assert::are_equal(84, *items.cbegin());
    }
    
    auto test_method_(cend) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/stack/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.cend();});
      assert::is_true(items.cend() == items.cbegin() + items.size());
    }
    
    auto test_method_(crbegin) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.crbegin()));
      assert::are_equal(21, *items.crbegin());
    }
    
    auto test_method_(crend) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/stack/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.crend();});
      assert::is_true(items.crend() == items.crbegin() + items.size());
    }
    
    auto test_method_(end) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/stack/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.end();});
      assert::is_true(items.end() == items.begin() + items.size());
    }
    
    auto test_method_(pop) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(21, items.top());
      items.pop();
      assert::are_equal(42, items.top());
      items.pop();
      assert::are_equal(84, items.top());
      items.pop();
      assert::is_zero(items.size());
    }
    
    auto test_method_(push) {
      auto items = raw_stack<int> {};
      items.push(84);
      assert::are_equal(84, items.top());
      items.push(42);
      assert::are_equal(42, items.top());
      items.push(21);
      assert::are_equal(21, items.top());
    }
    
    auto test_method_(push_move_value) {
      auto s = raw_stack<string> {};
      auto str = "hello"_s;
      s.push(std::move(str));
      assert::are_equal("hello", s.top());
      assert::is_true(str.empty() || str == "hello");
    }
    
    auto test_method_(rbegin) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.rbegin()));
      assert::are_equal(21, *items.rbegin());
    }
    
    auto test_method_(rend) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/stack/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.rend();});
      assert::is_true(items.rend() == items.rbegin() + items.size());
    }
    
    auto test_method_(reserve) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(3_z, items.capacity());
      assert::are_equal(3_z, items.size());
      items.reserve(42);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
      items.reserve(24);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
      items.reserve(2);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
    }
    
    auto test_method_(shrink_to_fit) {
      auto items = raw_stack<int> {};
      items.reserve(42);
      items.push(84);
      items.push(42);
      items.push(21);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
      
      items.shrink_to_fit();
      assert::are_equal(3_z, items.capacity());
      assert::are_equal(3_z, items.size());
    }
    
    auto test_method_(equality_operator) {
      auto q1 = raw_stack<int>(std::deque<int> {84, 42, 21});
      auto q2 = raw_stack<int> {};
      q2 = q1;
      assert::are_equal(3_z, q1.size());
      collection_assert::are_equal({84, 42, 21}, q1);
      assert::are_equal(3_z, q2.size());
      collection_assert::are_equal({84, 42, 21}, q2);
    }
    
    auto test_method_(move_equality_operator) {
      auto q1 = raw_stack<int>(std::deque<int> {84, 42, 21});
      auto q2 = raw_stack<int> {};
      q2 = std::move(q1);
      assert::is_zero(q1.size());
      assert::are_equal(3_z, q2.size());
      collection_assert::are_equal({84, 42, 21}, q2);
    }
    
    auto test_method_(base_type_cast_operator) {
      auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_stack<int>::base_type>(), typeof_(static_cast<raw_stack<int>::base_type&>(items)));
      
      auto& inners = static_cast<raw_stack<int>::base_type&>(items);
      assert::are_equal(21, inners.top());
    }
    
    auto test_method_(base_type_cast_operator_const) {
      const auto items = raw_stack<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_stack<int>::base_type>(), typeof_(static_cast<const raw_stack<int>::base_type&>(items)));
      
      const auto& inners = static_cast<const raw_stack<int>::base_type&>(items);
      assert::are_equal(21, inners.top());
    }
    
    auto test_method_(begin_end_on_empty_stack) {
      auto s = raw_stack<int> {};
      assert::are_equal(s.begin(), s.end());
    }
    
    auto test_method_(cbegin_cend_on_empty_stack) {
      auto s = raw_stack<int> {};
      assert::are_equal(s.cbegin(), s.cend());
    }
  };
}
