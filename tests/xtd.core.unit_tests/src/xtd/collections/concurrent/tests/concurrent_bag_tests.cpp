#include <xtd/collections/concurrent/concurrent_bag>
#include <xtd/threading/tasks/task_factory>
#include <xtd/argument_out_of_range_exception>
#include <xtd/invalid_operation_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace collections::concurrent;

namespace xtd::collections::tests {
  class test_class_(concurrent_bag_tests) {
    auto test_method_(value_type) {
      assert::are_equal(type_of<int>(), type_of<concurrent_bag<int>::value_type>());
    }

    auto test_method_(reference) {
      assert::are_equal(type_of<int&>(), type_of<concurrent_bag<int>::reference>());
    }

    auto test_method_(const_reference) {
      assert::are_equal(type_of<const int&>(), type_of<concurrent_bag<int>::const_reference>());
    }

    auto test_method_(collection_type) {
      assert::are_equal(type_of<xtd::collections::generic::queue<int>>(), type_of<concurrent_bag<int>::collection_type>());
    }

    auto test_method_(local_storage_type) {
      assert::are_equal(type_of<xtd::collections::generic::queue<int>*>(), type_of<concurrent_bag<int>::local_storage_type>());
    }

    auto test_method_(storage_type) {
      assert::are_equal(type_of<xtd::collections::generic::dictionary<xtd::intptr, xtd::ptr<xtd::collections::generic::queue<int>>>>(), type_of<concurrent_bag<int>::storage_type>());
    }

    auto test_method_(default_constructor) {
      auto items = concurrent_bag<int> {};
      collection_assert::is_empty(items);
    }

    auto test_method_(constructor_with_initializer_list) {
      auto items = concurrent_bag {1, 2, 3, 4, 5};
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, items);
    }

    auto test_method_(constructor_with_ienumerable) {
      auto items = concurrent_bag(array {1, 2, 3, 4, 5});
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, items);
    }

    auto test_method_(copy_constructor) {
      auto items1 = concurrent_bag<int> {};
      auto t1 = task_factory {}.start_new([&items1] {items1.add(1);});
      auto t2 = task_factory {}.start_new([&items1] {items1.add(2);});
      task<>::wait_all(t1, t2);
      collection_assert::are_equivalent({1, 2}, items1);
      auto items2 = items1;
      collection_assert::are_equal(items1, items2);
      collection_assert::are_equivalent({1, 2}, items2);
    }

    auto test_method_(move_constructor) {
      auto items1 = concurrent_bag<int> {};
      auto t1 = task_factory {}.start_new([&items1] {items1.add(1);});
      auto t2 = task_factory {}.start_new([&items1] {items1.add(2);});
      task<>::wait_all(t1, t2);
      collection_assert::are_equivalent({1, 2}, items1);
      auto items2 = std::move(items1);
      collection_assert::are_equivalent({1, 2}, items2);
    }
    
    auto test_method_(count) {
      assert::are_equal(5_z, concurrent_bag<int> {1, 2, 3, 4, 5}.count());
      auto items = concurrent_bag<int> {};
      assert::is_zero(items.count());
      items.add(1);
      assert::are_equal(1_z, items.count());
      items.add(2);
      assert::are_equal(2_z, items.count());
      items.add(3);
      assert::are_equal(3_z, items.count());
      items.add(4);
      assert::are_equal(4_z, items.count());
      items.add(5);
      assert::are_equal(5_z, items.count());
    }
    
    auto test_method_(size) {
      assert::are_equal(5_z, concurrent_bag<int> {1, 2, 3, 4, 5}.size());
      auto items = concurrent_bag<int> {};
      assert::is_zero(items.size());
      items.add(1);
      assert::are_equal(1_z, items.size());
      items.add(2);
      assert::are_equal(2_z, items.size());
      items.add(3);
      assert::are_equal(3_z, items.size());
      items.add(4);
      assert::are_equal(4_z, items.size());
      items.add(5);
      assert::are_equal(5_z, items.size());
    }

    auto test_method_(empty) {
      assert::is_false(concurrent_bag<int> {1, 2, 3, 4, 5}.empty());
      auto items = concurrent_bag<int> {};
      assert::is_true(items.empty());
      items.add(1);
      assert::is_false(items.empty());
    }
    
    auto test_method_(is_empty) {
      assert::is_false(concurrent_bag<int> {1, 2, 3, 4, 5}.is_empty());
      auto items = concurrent_bag<int> {};
      assert::is_true(items.is_empty());
      items.add(1);
      assert::is_false(items.is_empty());
    }
    
    auto test_method_(add) {
      auto items = concurrent_bag<int> {};
      items.add(1);
      collection_assert::are_equivalent({1}, items);
      items.add(2);
      collection_assert::are_equivalent({1, 2}, items);
      items.add(3);
      collection_assert::are_equivalent({1, 2, 3}, items);
      items.add(4);
      collection_assert::are_equivalent({1, 2, 3, 4}, items);
      items.add(5);
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, items);
    }
    
    auto test_method_(concurrent_add) {
      auto start_event = manual_reset_event {};
      auto tasks = list<task<>> {};
      auto items = concurrent_bag<int> {};
      for (auto task = 0; task < 100; ++task) {
        tasks.add(task_factory {}.start_new([&] {
          start_event.wait_one();
          for (auto count = 0; count < 100; ++count) {
            items.add(task * 10 + count);
            thread::yield();
          }
        }));
      }
      start_event.set();
      task<>::wait_all(tasks);
      assert::are_equal(10000_z, items.count());
    }
    
    auto test_method_(copy_to) {
      auto a1 = array<int>(5_z);
      concurrent_bag<int> {}.copy_to(a1, 0);
      collection_assert::are_equal({0, 0, 0, 0, 0}, a1);

      concurrent_bag<int> {1, 2, 3, 4, 5}.copy_to(a1, 0);
      collection_assert::are_equal({1, 2, 3, 4, 5}, a1);

      assert::throws<argument_out_of_range_exception>([&] {concurrent_bag<int> {1, 2, 3, 4, 5}.copy_to(a1, 1);});

      auto a2 = array<int>(9_z);
      concurrent_bag<int> {1, 2, 3, 4, 5}.copy_to(a2, 2);
      collection_assert::are_equal({0, 0, 1, 2, 3, 4, 5, 0, 0}, a2);

      assert::throws<argument_out_of_range_exception>([&] {concurrent_bag<int> {1, 2, 3, 4, 5}.copy_to(a2, 5);});
    }
    
    auto test_method_(get_enumerator) {
      auto items = concurrent_bag<int> {1, 2, 3, 4, 5};
      auto enumeator = items.get_enumerator();
      assert::throws<invalid_operation_exception>([&] {auto __ = enumeator.current();});
      assert::is_true(enumeator.move_next());
      assert::are_equal(1, enumeator.current());
      assert::is_true(enumeator.move_next());
      assert::are_equal(2, enumeator.current());
      assert::is_true(enumeator.move_next());
      assert::are_equal(3, enumeator.current());
      assert::is_true(enumeator.move_next());
      assert::are_equal(4, enumeator.current());
      assert::is_true(enumeator.move_next());
      assert::are_equal(5, enumeator.current());
      assert::is_false(enumeator.move_next());
      assert::throws<invalid_operation_exception>([&] {auto __ = enumeator.current();});
    }
    
    auto test_method_(to_array) {
      collection_assert::is_empty(concurrent_bag<int> {}.to_array());
      collection_assert::are_equal({1, 2, 3, 4, 5}, concurrent_bag {1, 2, 3, 4, 5}.to_array());
    }
    
    auto test_method_(to_string) {
      assert::are_equal("[]", concurrent_bag<int> {}.to_string());
      assert::are_equal("[1, 2, 3, 4, 5]", concurrent_bag {1, 2, 3, 4, 5}.to_string());
    }
    
    auto test_method_(try_add) {
      auto items = concurrent_bag<int> {};
      assert::is_true(items.try_add(1));
      collection_assert::are_equivalent({1}, items);
      assert::is_true(items.try_add(2));
      collection_assert::are_equivalent({1, 2}, items);
      assert::is_true(items.try_add(3));
      collection_assert::are_equivalent({1, 2, 3}, items);
      assert::is_true(items.try_add(4));
      collection_assert::are_equivalent({1, 2, 3, 4}, items);
      assert::is_true(items.try_add(5));
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, items);
    }
    
    auto test_method_(concurrent_try_add) {
      auto start_event = manual_reset_event {};
      auto tasks = list<task<>> {};
      auto items = concurrent_bag<int> {};
      auto result_try = std::atomic<bool> {true};
      for (auto task = 0; task < 100; ++task) {
        tasks.add(task_factory {}.start_new([&] {
          start_event.wait_one();
          for (auto count = 0; count < 100; ++count) {
            result_try = result_try && items.try_add(task * 10 + count);
            thread::yield();
          }
        }));
      }
      start_event.set();
      task<>::wait_all(tasks);
      assert::is_true(result_try);
      assert::are_equal(10000_z, items.count());
    }
    
    auto test_method_(try_peek) {
      auto result = 0;
      assert::is_false(concurrent_bag<int> {}.try_peek(result));
      auto items = concurrent_bag {1, 2, 3, 4, 5};
      assert::is_true(items.try_peek(result));
      assert::are_equal(1, result);
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, items);
    }
  
    auto test_method_(try_take) {
      auto result = 0;
      assert::is_false(concurrent_bag<int> {}.try_take(result));
      auto items = concurrent_bag {1, 2, 3, 4, 5};
      assert::is_true(items.try_take(result));
      assert::are_equal(1, result);
      collection_assert::are_equivalent({2, 3, 4, 5}, items);
      assert::is_true(items.try_take(result));
      assert::are_equal(2, result);
      collection_assert::are_equivalent({3, 4, 5}, items);
      assert::is_true(items.try_take(result));
      assert::are_equal(3, result);
      collection_assert::are_equivalent({4, 5}, items);
      assert::is_true(items.try_take(result));
      assert::are_equal(4, result);
      collection_assert::are_equivalent({5}, items);
      assert::is_true(items.try_take(result));
      assert::are_equal(5, result);
      collection_assert::is_empty(items);
      assert::is_false(items.try_take(result));
    }
  };
}
