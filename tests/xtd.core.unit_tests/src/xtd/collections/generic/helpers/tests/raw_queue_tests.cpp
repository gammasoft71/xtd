#include <xtd/collections/generic/helpers/raw_queue.hpp>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::collections::generic::helpers::tests {
  class test_class_(raw_queue_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<raw_queue<int>::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::queue<int>>(), typeof_<raw_queue<int>::base_type > ());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<raw_queue<int>::size_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<raw_queue<int>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<raw_queue<int>::const_reference>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<raw_queue<int>::container_type::const_iterator>(), typeof_<raw_queue<int>::const_iterator> ());
    }
    
    void test_method_(default_constructor) {
      auto items = raw_queue<int> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_capacity) {
      auto items = raw_queue<int>(3_z);
      assert::are_equal(3_z, items.capacity());
      assert::is_zero(items.size());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_iterators) {
      auto v = std::vector {84, 42, 21};
      auto items = raw_queue<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_base_type) {
      auto bt = raw_queue<int>::base_type(std::deque<int> {84, 42, 21});
      auto items = raw_queue<int>(bt);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_raw_queue) {
      auto q = raw_queue<int>(std::deque<int> {84, 42, 21});
      auto items = raw_queue(q);
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(constructor_with_move_raw_queue) {
      auto q = raw_queue<int>(std::deque<int> {84, 42, 21});
      auto items = raw_queue(std::move(q));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
      collection_assert::is_empty(q);
    }
    
    void test_method_(constructor_with_move_base_type) {
      auto bt = raw_queue<int>::base_type(std::deque<int> {84, 42, 21});
      auto items = raw_queue<int>(std::move(bt));
      assert::are_equal(3_z, items.size());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    void test_method_(capaciy) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(3_z, items.size());
      assert::are_equal(3_z, items.capacity());
      
      items.reserve(42);
      assert::are_equal(42_z, items.capacity());
      assert::are_equal(3_z, items.size());
      
      items.shrink_to_fit();
      assert::are_equal(3_z, items.capacity());
      assert::are_equal(3_z, items.size());
    }
    
    void test_method_(items) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_queue<int>::base_type>(), typeof_(items.items()));
      
      auto& inners = items.items();
      assert::are_equal(84, inners.front());
      assert::are_equal(21, inners.back());
    }
    
    void test_method_(items_const) {
      const auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_queue<int>::base_type>(), typeof_(items.items()));
      
      const auto& inners = items.items();
      assert::are_equal(84, inners.front());
      assert::are_equal(21, inners.back());
    }
    
    void test_method_(size) {
      auto items = raw_queue<int> {};
      assert::is_zero(items.size());
      items.push(84);
      items.push(42);
      items.push(21);
      assert::are_equal(3_z, items.size());
    }
    
    void test_method_(begin) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.begin()));
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(cbegin) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.begin()));
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(cend) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/queue/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.cend();});
      assert::is_true(items.cend() == items.cbegin() + items.size());
    }
    
    void test_method_(end) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/queue/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.end();});
      assert::is_true(items.end() == items.begin() + items.size());
    }
    
    void test_method_(pop) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(21, items.back());
      assert::are_equal(84, items.front());
      items.pop();
      assert::are_equal(21, items.back());
      assert::are_equal(42, items.front());
      items.pop();
      assert::are_equal(21, items.back());
      assert::are_equal(21, items.front());
      items.pop();
      assert::is_zero(items.size());
    }
    
    void test_method_(push) {
      auto items = raw_queue<int> {};
      items.push(84);
      assert::are_equal(84, items.back());
      assert::are_equal(84, items.front());
      items.push(42);
      assert::are_equal(42, items.back());
      assert::are_equal(84, items.front());
      items.push(21);
      assert::are_equal(21, items.back());
      assert::are_equal(84, items.front());
    }
    
    void test_method_(push_move_value) {
      auto q = raw_queue<string> {};
      auto s = "hello"_s;
      q.push(std::move(s));
      assert::are_equal("hello", q.back());
      assert::is_true(s.empty() || s == "hello");
    }
    
    void test_method_(reserve) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
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
    
    void test_method_(shrink_to_fit) {
      auto items = raw_queue<int> {};
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
    
    void test_method_(equality_operator) {
      auto q1 = raw_queue<int>(std::deque<int> {84, 42, 21});
      auto q2 = raw_queue<int> {};
      q2 = q1;
      assert::are_equal(3_z, q1.size());
      collection_assert::are_equal({84, 42, 21}, q1);
      assert::are_equal(3_z, q2.size());
      collection_assert::are_equal({84, 42, 21}, q2);
    }
    
    void test_method_(move_equality_operator) {
      auto q1 = raw_queue<int>(std::deque<int> {84, 42, 21});
      auto q2 = raw_queue<int> {};
      q2 = std::move(q1);
      assert::is_zero(q1.size());
      assert::are_equal(3_z, q2.size());
      collection_assert::are_equal({84, 42, 21}, q2);
    }
    
    void test_method_(base_type_cast_operator) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_queue<int>::base_type>(), typeof_(static_cast<raw_queue<int>::base_type&>(items)));
      
      auto& inners = static_cast<raw_queue<int>::base_type&>(items);
      assert::are_equal(84, inners.front());
      assert::are_equal(21, inners.back());
    }
    
    void test_method_(base_type_cast_operator_const) {
      const auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<raw_queue<int>::base_type>(), typeof_(static_cast<const raw_queue<int>::base_type&>(items)));
      
      const auto& inners = static_cast<const raw_queue<int>::base_type&>(items);
      assert::are_equal(84, inners.front());
      assert::are_equal(21, inners.back());
    }
    
    void test_method_(begin_end_on_empty_queue) {
      auto q = raw_queue<int> {};
      assert::are_equal(q.begin(), q.end());
    }
    
    void test_method_(cbegin_cend_on_empty_queue) {
      auto q = raw_queue<int> {};
      assert::are_equal(q.cbegin(), q.cend());
    }
  };
}
