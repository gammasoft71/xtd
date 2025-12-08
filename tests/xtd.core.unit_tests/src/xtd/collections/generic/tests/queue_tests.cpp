#include <xtd/collections/generic/queue>
#include <xtd/as>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::object_model;
using namespace xtd::collections::generic;
using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(queue_tests) {
    auto test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<queue<int>::value_type>());
    }
    
    auto test_method_(base_type) {
      assert::are_equal(typeof_<raw_queue<int>>(), typeof_<queue<int>::base_type > ());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<queue<int>::size_type>());
      assert::are_equal(typeof_<queue<bool>::base_type::size_type>(), typeof_<queue<int>::size_type>());
    }
    
    auto test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<queue<int>::reference>());
    }
    
    auto test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<queue<int>::const_reference>());
    }
    
    auto test_method_(default_constructor) {
      auto items = queue<string> {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    auto test_method_(constructor_copy_queue) {
      auto q = queue {84, 42, 21};
      auto items = queue(q);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::are_equal(3_z, q.count());
      collection_assert::are_equal({84, 42, 21}, q);
    }
    
    auto test_method_(constructor_move_queue) {
      auto q = queue {84, 42, 21};
      auto items = queue(std::move(q));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::is_zero(q.count());
    }
    
    auto test_method_(constructor_copy_std_queue) {
      auto q = std::queue(std::deque {84, 42, 21});
      auto items = queue(q);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::are_equal(3_z, q.size());
      assert::are_equal(21, q.back());
      assert::are_equal(84, q.front());
    }
    
    auto test_method_(constructor_move_std_queue) {
      auto q = std::queue(std::deque {84, 42, 21});
      auto items = queue(std::move(q));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::is_zero(q.size());
    }
    
    auto test_method_(constructor_with_ienumerable) {
      auto a = array {84, 42, 21};
      auto items = queue(a);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(constructor_with_capacity) {
      auto items = queue<boolean>(3);
      assert::is_greater_or_equal(items.capacity(), 3_z);
      assert::is_zero(items.count());
    }
    
    auto test_method_(constructor_with_initializer_list) {
      auto items = queue {84, 42, 21};
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(constructor_with_iterators) {
      auto a = array {84, 42, 21};
      auto items = queue(a.begin(), a.end());
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
    }
    
    auto test_method_(begin) {
      auto items = queue {84, 42, 21};
      assert::are_equal(84, *items.begin());
    }
    
    auto test_method_(capacity) {
      auto items = queue {84, 42, 21};
      assert::are_equal(3_z, items.count());
      
      items.ensure_capacity(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.count());
    }
    
    auto test_method_(cbegin) {
      auto items = queue {84, 42, 21};
      assert::are_equal(84, *items.cbegin());
    }
    
    auto test_method_(cend) {
      auto items = queue {84, 42, 21};
      assert::is_true(items.cend() == items.cbegin() + items.count());
    }
    
    auto test_method_(count) {
      auto items = queue<int> {};
      assert::is_zero(items.count());
      items.enqueue(84);
      items.enqueue(42);
      items.enqueue(21);
      assert::are_equal(3_z, items.count());
    }
    
    auto test_method_(end) {
      auto items = queue {84, 42, 21};
      assert::is_true(items.end() == items.begin() + items.count());
    }
    
    auto test_method_(is_read_only) {
      // Is always false;
      assert::is_false(as<icollection<int>>(queue<int> {}).is_read_only());
    }
    
    auto test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(as<icollection<int>>(queue<int> {}).is_synchronized());
    }
    
    auto test_method_(items_const) {
      auto q = queue {1, 2, 3, 4, 5}.items();
      assert::are_equal(1, q.front());
      q.pop();
      assert::are_equal(2, q.front());
      q.pop();
      assert::are_equal(3, q.front());
      q.pop();
      assert::are_equal(4, q.front());
      q.pop();
      assert::are_equal(5, q.front());
      q.pop();
      assert::is_zero(q.size());
    }
    
    auto test_method_(clear) {
      auto items = queue {84, 42, 21};
      items.clear();
      assert::is_zero(items.count());
      items.clear();
      assert::is_zero(items.count());
    }
    
    auto test_method_(contains) {
      auto items = queue {84, 42, 21};
      assert::is_true(items.contains(84));
      assert::is_true(items.contains(42));
      assert::is_true(items.contains(21));
      assert::is_false(items.contains(0));
      assert::is_false(items.contains(12));
      assert::is_false(items.contains(-1));
    }
    
    auto test_method_(copy_to_with_index) {
      auto items = queue {84, 42, 21};
      auto dest = array<int>(5);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21}, dest);
      
      dest = array<int>(7);
      items.copy_to(dest, 2);
      collection_assert::are_equal({0, 0, 84, 42, 21, 0, 0}, dest);
      
      dest = array<int>(3);
      assert::throws<argument_out_of_range_exception>(delegate_ {items.copy_to(dest, 1);});
    }
    
    auto test_method_(dequeue) {
      auto items = queue {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      items.dequeue();
      collection_assert::are_equal({2, 3, 4, 5}, items);
      items.dequeue();
      collection_assert::are_equal({3, 4, 5}, items);
      items.dequeue();
      collection_assert::are_equal({4, 5}, items);
      items.dequeue();
      collection_assert::are_equal({5}, items);
      items.dequeue();
      collection_assert::is_empty(items);
      assert::throws<invalid_operation_exception>([&] {items.dequeue();});
    }
    
    auto test_method_(enqueue) {
      auto items = queue<int> {};
      collection_assert::is_empty(items);
      items.enqueue(1);
      collection_assert::are_equal({1}, items);
      items.enqueue(2);
      collection_assert::are_equal({1, 2}, items);
      items.enqueue(3);
      collection_assert::are_equal({1, 2, 3}, items);
      items.enqueue(4);
      collection_assert::are_equal({1, 2, 3, 4}, items);
      items.enqueue(5);
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
    }
    
    auto test_method_(ensure_capacity) {
      auto items = queue<int> {};
      assert::is_zero(items.capacity());
      assert::are_equal(3_z, items.ensure_capacity(3));
      assert::are_equal(3_z, items.capacity());
      assert::are_equal(5_z, items.ensure_capacity(5));
      assert::are_equal(5_z, items.capacity());
      assert::are_equal(5_z, items.ensure_capacity(3));
      assert::are_equal(5_z, items.capacity());
    }
    
    auto test_method_(get_enumerator) {
      auto items = queue {84, 42, 21};
      auto enumerator = items.get_enumerator();
      assert::throws<invalid_operation_exception>([&] {enumerator.current();});
      assert::is_true(enumerator.move_next());
      assert::are_equal(84, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(42, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(21, enumerator.current());
      assert::is_false(enumerator.move_next());
      assert::throws<invalid_operation_exception>([&] {enumerator.current();});
    }
    
    auto test_method_(peek) {
      auto items = queue {84, 42, 21};
      assert::are_equal(84, items.peek());
      items.dequeue();
      assert::are_equal(42, items.peek());
      items.dequeue();
      assert::are_equal(21, items.peek());
      items.dequeue();
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto i = items.peek();});
    }
    
    auto test_method_(to_array) {
      assert::is_instance_of<array<int>>(queue {84, 42, 21}.to_array());
      collection_assert::are_equal({84, 42, 21}, queue {84, 42, 21}.to_array());
      collection_assert::is_empty(queue<int> {}.to_array());
    }
    
    auto test_method_(to_string) {
      assert::are_equal("[84, 42, 21]", queue {84, 42, 21}.to_string());
      assert::are_equal("[]", queue<int> {}.to_string());
    }
    
    auto test_method_(trim_excess) {
      auto items = queue {84, 42, 21};
      assert::are_equal(3_z, items.capacity());
      items.ensure_capacity(5);
      assert::are_equal(5_z, items.capacity());
      items.trim_excess();
      assert::are_equal(3_z, items.capacity());
      items.trim_excess();
      assert::are_equal(3_z, items.capacity());
      items.ensure_capacity(4);
      assert::are_equal(4_z, items.capacity());
      items.trim_excess(); // Does not effect because if that number is less than 90 percent of current capacity.
      assert::are_equal(4_z, items.capacity());
    }
    
    auto test_method_(trim_excess_with_capacity) {
      auto items = queue {84, 42, 21};
      assert::are_equal(3_z, items.capacity());
      items.ensure_capacity(10);
      assert::are_equal(10_z, items.capacity());
      items.trim_excess(5);
      assert::are_equal(5_z, items.capacity());
      items.trim_excess(3);
      assert::are_equal(3_z, items.capacity());
      assert::throws<argument_out_of_range_exception>([&] {items.trim_excess(2);});
      items.trim_excess(10);
      assert::are_equal(10_z, items.capacity());
    }
    
    auto test_method_(try_dequeue) {
      auto items = queue {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, items);
      auto item = 0;
      assert::is_true(items.try_dequeue(item));
      assert::are_equal(1, item);
      collection_assert::are_equal({2, 3, 4, 5}, items);
      assert::is_true(items.try_dequeue(item));
      assert::are_equal(2, item);
      collection_assert::are_equal({3, 4, 5}, items);
      assert::is_true(items.try_dequeue(item));
      assert::are_equal(3, item);
      collection_assert::are_equal({4, 5}, items);
      assert::is_true(items.try_dequeue(item));
      assert::are_equal(4, item);
      collection_assert::are_equal({5}, items);
      assert::is_true(items.try_dequeue(item));
      assert::are_equal(5, item);
      collection_assert::is_empty(items);
      assert::is_false(items.try_dequeue(item));
      assert::are_equal(0, item);
    }
    
    auto test_method_(try_peek) {
      auto items = queue {84, 42, 21};
      auto item = 0;
      assert::is_true(items.try_peek(item));
      assert::are_equal(84, item);
      items.dequeue();
      assert::is_true(items.try_peek(item));
      assert::are_equal(42, item);
      items.dequeue();
      assert::is_true(items.try_peek(item));
      assert::are_equal(21, item);
      items.dequeue();
      assert::is_false(items.try_peek(item));
      assert::are_equal(0, item);
    }
    
    auto test_method_(operator_copy_queue) {
      auto q = queue {84, 42, 21};
      auto items = queue<int> {};
      items = q;
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::are_equal(3_z, q.count());
      collection_assert::are_equal({84, 42, 21}, q);
    }
    
    auto test_method_(operator_move_queue) {
      auto q = queue {84, 42, 21};
      auto items = queue<int> {};
      items = std::move(q);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::is_zero(q.count());
    }
    
    auto test_method_(operator_copy_std_queue) {
      auto q = std::queue(std::deque {84, 42, 21});
      auto items = queue<int> {};
      items = q;
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::are_equal(3_z, q.size());
      assert::are_equal(21, q.back());
      assert::are_equal(84, q.front());
    }
    
    auto test_method_(operator_move_std_queue) {
      auto q = std::queue(std::deque {84, 42, 21});
      auto items = queue<int> {};
      items = std::move(q);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({84, 42, 21}, items);
      assert::is_zero(q.size());
    }
    
    auto test_method_(operator_cast_as_std_queue) {
      auto q = static_cast<const std::queue<int>&>(queue {1, 2, 3, 4, 5});
      assert::are_equal(1, q.front());
      q.pop();
      assert::are_equal(2, q.front());
      q.pop();
      assert::are_equal(3, q.front());
      q.pop();
      assert::are_equal(4, q.front());
      q.pop();
      assert::are_equal(5, q.front());
      q.pop();
      assert::is_zero(q.size());
    }
  };
}
