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
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<raw_queue<int>::container_type::const_iterator>(), typeof_<raw_queue<int>::iterator> ());
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

    void test_method_(begin) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(typeof_<int>(), typeof_(*items.begin()));
      assert::are_equal(84, *items.begin());
    }
    
    void test_method_(capaciy) {
      auto items = raw_queue<int>(std::deque<int> {84, 42, 21});
      assert::are_equal(3_z, items.size());
      
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.size());
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

    /*
    
    void test_method_(items_const_with_bool) {
      assert::are_equal(typeof_<raw_queue<bool>::base_type>(), typeof_(raw_queue {true, false, true, false}.items()));
      collection_assert::are_equal({1u, 0u, 1u, 0u}, raw_queue {true, false, true, false}.items());
    }
    
    void test_method_(items_with_bool) {
      auto items = raw_queue {true, false, true};
      assert::are_equal(typeof_<raw_queue<bool>::base_type>(), typeof_(items.items()));
    
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
      assert::is_not_zero(raw_queue<int> {}.max_size());
    }
    
    void test_method_(max_size_with_bool) {
      assert::is_not_zero(raw_queue<bool> {}.max_size());
    }
    
    void test_method_(rbegin) {
      auto items = raw_queue {84, 42, 21};
      assert::are_equal(typeof_<int>(), typeof_(*items.rbegin()));
      assert::are_equal(21, *items.rbegin());
    }
    
    void test_method_(rbegin_with_bool) {
      auto items = raw_queue {true, false, true};
      assert::are_equal(typeof_<bool>(), typeof_(*items.rbegin()));
      assert::are_equal(true, *items.rbegin());
    }
    
    void test_method_(rend) {
      auto items = raw_queue {84, 42, 21};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.rend();});
      assert::is_true(items.rend() == items.rbegin() + items.size());
    }
    
    void test_method_(rend_with_bool) {
      auto items = raw_queue {true, false, true};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<std::out_of_range>([&] {*items.rend();});
      assert::is_true(items.rend() == items.rbegin() + items.size());
    }
    
    void test_method_(size) {
      auto items = raw_queue<int> {};
      assert::is_zero(items.size());
      items.push_back(84);
      items.push_back(42);
      items.push_back(21);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(size_with_bool) {
      auto items = raw_queue<bool> {};
      assert::is_zero(items.size());
      items.push_back(true);
      items.push_back(false);
      items.push_back(true);
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }
    
    void test_method_(assign_with_count_and_value) {
      auto items = raw_queue {84, 42, 21};
      items.assign(4, 63);
      collection_assert::are_equal({63, 63, 63, 63}, items);
    }
    
    void test_method_(assign_with_count_value_and_bool) {
      auto items = raw_queue {true, false, true};
      items.assign(4, true);
      collection_assert::are_equal({true, true, true, true}, items);
    }
    
    void test_method_(assign_with_iterators) {
      auto items = raw_queue {84, 42, 21};
      auto items2 = std::vector {10, 20, 30, 40};
      items.assign(items2.begin(), items2.end());
      collection_assert::are_equal({10, 20, 30, 40}, items);
    }
    
    void test_method_(assign_with_iterators_and_bool) {
      auto items = raw_queue {true, false, true};
      auto items2 = std::vector {false, true, true, false};
      items.assign(items2.begin(), items2.end());
      collection_assert::are_equal({false, true, true, false}, items);
    }
    
    void test_method_(assign_with_initializer_list) {
      auto items = raw_queue {84, 42, 21};
      items.assign({10, 20, 30, 40});
      collection_assert::are_equal({10, 20, 30, 40}, items);
    }
    
    void test_method_(assign_with_initializer_list_and_bool) {
      auto items = raw_queue {true, false, true};
      items.assign({false, true, true, false});
      collection_assert::are_equal({false, true, true, false}, items);
    }
    
    void test_method_(at) {
      auto items = raw_queue {84, 42, 21};
    
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
      auto items = raw_queue {true, false, true};
    
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
      auto items = raw_queue {84, 42, 21};
      items.clear();
      assert::are_equal(0_z, items.size());
    }
    
    void test_method_(clear_with_bool) {
      auto items = raw_queue {true, false, true};
      items.clear();
      assert::are_equal(0_z, items.size());
    }
    
    void test_method_(emplace) {
      auto items = raw_queue {84, 42, 21};
      items.emplace(items.begin() + 2, 63);
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(emplace_with_bool) {
      auto items = raw_queue {true, false, true};
      items.emplace(items.begin() + 2, false);
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(emplace_back) {
      auto items = raw_queue {84, 42, 21};
      items.emplace_back(63);
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(emplace_back_with_bool) {
      auto items = raw_queue {true, false, true};
      items.emplace_back(false);
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(erase_with_pos) {
      auto items = raw_queue {84, 42, 21, 63, 75, 96};
      items.erase(items.begin() + 2);
      collection_assert::are_equal({84, 42, 63, 75, 96}, items);
    }
    
    void test_method_(erase_with_pos_and_bool) {
      auto items = raw_queue {true, false, false, true, true, false};
      items.erase(items.begin() + 2);
      collection_assert::are_equal({true, false, true, true, false}, items);
    }
    
    void test_method_(erase_with_first_and_last) {
      auto items = raw_queue {84, 42, 21, 63, 75, 96};
      items.erase(items.begin() + 2, items.begin() + 5);
      collection_assert::are_equal({84, 42, 96}, items);
    }
    
    void test_method_(erase_with_first_last_and_bool) {
      auto items = raw_queue {true, false, false, true, true, false};
      items.erase(items.begin() + 2, items.begin() + 5);
      collection_assert::are_equal({true, false, false}, items);
    }
    
    void test_method_(get_allocator) {
      auto items = raw_queue {84, 42, 21};
      auto allocator = items.get_allocator();
      assert::are_equal(typeof_<raw_queue<int>::allocator_type>(), typeof_(allocator));
    }
    
    void test_method_(get_allocator_with_bool) {
      auto items = raw_queue {true, false, true};
      auto allocator = items.get_allocator();
      assert::are_equal(typeof_<raw_queue<bool>::allocator_type>(), typeof_(allocator));
    }
    
    void test_method_(insert) {
      auto items = raw_queue {84, 42, 21};
      items.insert(items.begin() + 2, 63);
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(insert_with_bool) {
      auto items = raw_queue {true, false, true};
      items.insert(items.begin() + 2, false);
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(insert_with_move) {
      auto items = raw_queue {84, 42, 21};
      auto v = 63;
      items.insert(items.begin() + 2, std::move(v));
      collection_assert::are_equal({84, 42, 63, 21}, items);
    }
    
    void test_method_(insert_with_move_and_bool) {
      auto items = raw_queue {true, false, true};
      auto v = false;
      items.insert(items.begin() + 2, std::move(v));
      collection_assert::are_equal({true, false, false, true}, items);
    }
    
    void test_method_(insert_with_count) {
      auto items = raw_queue {84, 42, 21};
      items.insert(items.begin() + 2, 3, 63);
      collection_assert::are_equal({84, 42, 63, 63, 63, 21}, items);
    }
    
    void test_method_(insert_with_count_and_bool) {
      auto items = raw_queue {true, false, true};
      items.insert(items.begin() + 2, 3, false);
      collection_assert::are_equal({true, false, false, false, false, true}, items);
    }
    
    void test_method_(insert_with_count_and_move) {
      auto items = raw_queue {84, 42, 21};
      auto v = 63;
      items.insert(items.begin() + 2, 3, std::move(v));
      collection_assert::are_equal({84, 42, 63, 63, 63, 21}, items);
    }
    
    void test_method_(insert_with_count_move_and_bool) {
      auto items = raw_queue {true, false, true};
      auto v = false;
      items.insert(items.begin() + 2, 3, std::move(v));
      collection_assert::are_equal({true, false, false, false, false, true}, items);
    }
    
    void test_method_(insert_with_iterators) {
      auto items = raw_queue {84, 42, 21};
      auto items2 = std::vector {10, 20, 30, 40};
      items.insert(items.begin() + 2, items2.begin(), items2.end());
      collection_assert::are_equal({84, 42, 10, 20, 30, 40, 21}, items);
    }
    
    void test_method_(insert_with_iterators_and_bool) {
      auto items = raw_queue {true, false, true};
      auto items2 = std::vector {false, true, true, false};
      items.insert(items.begin() + 2, items2.begin(), items2.end());
      collection_assert::are_equal({true, false, false, true, true, false, true}, items);
    }
    
    void test_method_(insert_with_initializer_list) {
      auto items = raw_queue {84, 42, 21};
      items.insert(items.begin() + 2, {10, 20, 30, 40});
      collection_assert::are_equal({84, 42, 10, 20, 30, 40, 21}, items);
    }
    
    void test_method_(insert_with_initializer_list_and_bool) {
      auto items = raw_queue {true, false, true};
      items.insert(items.begin() + 2, {false, true, true, false});
      collection_assert::are_equal({true, false, false, true, true, false, true}, items);
    }
    
    void test_method_(pop_back) {
      auto items = raw_queue {84, 42, 21};
      items.pop_back();
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(pop_back_with_bool) {
      auto items = raw_queue {true, false, true};
      items.pop_back();
      collection_assert::are_equal({true, false}, items);
    }
    
    void test_method_(push_back) {
      auto items = raw_queue {84, 42, 21};
      items.push_back(63);
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(push_back_with_bool) {
      auto items = raw_queue {true, false, true};
      items.push_back(false);
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(push_back_with_move) {
      auto items = raw_queue {84, 42, 21};
      auto v = 63;
      items.push_back(std::move(v));
      collection_assert::are_equal({84, 42, 21, 63}, items);
    }
    
    void test_method_(push_back_with_move_and_bool) {
      auto items = raw_queue {true, false, true};
      auto v = false;
      items.push_back(std::move(v));
      collection_assert::are_equal({true, false, true, false}, items);
    }
    
    void test_method_(reserve) {
      auto items = raw_queue {84, 42, 21};
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
    }
    
    void test_method_(reserve_with_bool) {
      auto items = raw_queue {true, false, true};
      items.reserve(42);
      assert::is_greater_or_equal(items.capacity(), 42_z);
    }
    
    void test_method_(resize) {
      auto items = raw_queue {84, 42, 21};
      items.resize(4);
      collection_assert::are_equal({84, 42, 21, 0}, items);
      items.resize(2);
      collection_assert::are_equal({84, 42}, items);
    }
    
    void test_method_(resize_with_bool) {
      auto items = raw_queue {true, false, true};
      items.resize(4);
      collection_assert::are_equal({true, false, true, false}, items);
      items.resize(2);
      collection_assert::are_equal({true, false}, items);
    }
    
    void test_method_(shrink_to_fit) {
      auto items = raw_queue {84, 42, 21};
      items.reserve(42);
      items.shrink_to_fit();
      assert::is_less(items.capacity(), 42_z);
    }
    
    void test_method_(shrink_to_fit_with_bool) {
      auto items = raw_queue {true, false, true};
      items.reserve(42);
      items.shrink_to_fit();
      assert::is_less(items.capacity(), 42_z);
    }
    
    void test_method_(swap) {
      auto items1 = raw_queue {84, 42, 21};
      auto items2 = raw_queue {63, 75, 96};
      items1.swap(items2);
      collection_assert::are_equal({63, 75, 96}, items1);
      collection_assert::are_equal({84, 42, 21}, items2);
    }
    
    void test_method_(swap_with_bool) {
      auto items1 = raw_queue {true, false, true};
      auto items2 = raw_queue {false, true, false};
      items1.swap(items2);
      collection_assert::are_equal({false, true, false}, items1);
      collection_assert::are_equal({true, false, true}, items2);
    }
    
    void test_method_(operator_equal) {
      auto items1 = raw_queue {84, 42, 21};
      auto items2 = raw_queue {63, 75, 96};
      items1 = items2;
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_bool) {
      auto items1 = raw_queue {true, false, true};
      auto items2 = raw_queue {false, true, false};
      items1 = items2;
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_equal_wtih_move) {
      auto items1 = raw_queue {84, 42, 21};
      auto items2 = raw_queue {63, 75, 96};
      items1 = std::move(items2);
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_move_and_bool) {
      auto items1 = raw_queue {true, false, true};
      auto items2 = raw_queue {false, true, false};
      items1 = std::move(items2);
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_equal_with_initializer_list) {
      auto items1 = raw_queue {84, 42, 21};
      auto items2 = {63, 75, 96};
      items1 = items2;
      collection_assert::are_equal({63, 75, 96}, items1);
    }
    
    void test_method_(operator_equal_with_initializer_list_and_bool) {
      auto items1 = raw_queue {true, false, true};
      auto items2 = {false, true, false};
      items1 = items2;
      collection_assert::are_equal({false, true, false}, items1);
    }
    
    void test_method_(operator_index) {
      auto items = raw_queue {84, 42, 21};
    
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
    
    void test_method_(operator_index_with_epos) {
      auto items = raw_queue {1, 2, 3, 4, 5};
    
      assert::are_equal(5, items[items.size() - 1]);
      assert::are_equal(5, items[items.epos]);
      assert::are_equal(5, items[xtd::epos]);
    
      items[items.epos] = 6;
      assert::are_equal(6, items[items.size() - 1]);
      assert::are_equal(6, items[items.epos]);
      assert::are_equal(6, items[xtd::epos]);
    
      items[xtd::epos] = 7;
      assert::are_equal(7, items[items.size() - 1]);
      assert::are_equal(7, items[items.epos]);
      assert::are_equal(7, items[xtd::epos]);
    }
    
    void test_method_(operator_index_with_bool) {
      auto items = raw_queue {true, false, true};
    
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
      auto items = raw_queue {84, 42, 21};
      auto bt = raw_queue<int>::base_type {};
      bt = items;
      assert::are_equal(typeof_<raw_queue<int>::base_type>(), typeof_(bt));
      collection_assert::are_equal({84, 42, 21}, bt);
    }
    
    void test_method_(operator_base_type_with_bool) {
      auto items = raw_queue {true, false, true};
      auto bt = raw_queue<bool>::base_type {};
      bt = items;
      assert::are_equal(typeof_<raw_queue<bool>::base_type>(), typeof_(bt));
      collection_assert::are_equal({1u, 0u, 1u}, bt);
    }
     */
  };
}
