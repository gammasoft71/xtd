#include <xtd/collections/generic/linked_list>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

namespace xtd::collections::generic::tests {
  class test_class_(linked_list_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<linked_list<int>::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::list<int>>(), typeof_<linked_list<int>::base_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<const size>(), typeof_<linked_list<int>::size_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<linked_list<int>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<linked_list<int>::const_reference>());
    }
    
    void test_method_(create_empty) {
      auto list = linked_list<int> {};
      collection_assert::is_empty(list);
      assert::is_zero(list.count());
      assert::is_null(list.first());
      assert::is_zero(list.items().size());
      assert::is_null(list.last());
    }
    
    void test_method_(create_with_one_item_initializer_list) {
      auto list = linked_list {42};
      collection_assert::are_equal({42}, list);
      assert::are_equal(1_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42}, list.items());
      assert::are_equal(1_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_items_initializer_list) {
      auto list = linked_list {42, 84, 21};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_ienumerable) {
      auto list = linked_list<int> {array {42, 84, 21}};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_linked_list) {
      auto list = linked_list<int> {linked_list {42, 84, 21}};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_move_linked_list) {
      auto orig = linked_list {42, 84, 21};
      auto list = linked_list<int> {std::move(orig)};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_std_list) {
      auto list = linked_list<int> {std::list {42, 84, 21}};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_move_std_list) {
      auto orig = std::list {42, 84, 21};
      auto list = linked_list<int> {std::move(orig)};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(create_with_iterators) {
      auto orig = std::vector {42, 84, 21};
      auto list = linked_list<int> {orig.begin(), orig.end()};
      collection_assert::are_equal({42, 84, 21}, list);
      assert::are_equal(3_z, list.count());
      assert::is_not_null(list.first());
      collection_assert::are_equal({42, 84, 21}, list.items());
      assert::are_equal(3_z, list.items().size());
      assert::is_not_null(list.last());
    }
    
    void test_method_(count_on_empty_list) {
      assert::is_zero(linked_list<int> {}.count());
    }
    
    void test_method_(count_on_one_item_list) {
      assert::are_equal(1_z, linked_list {42}.count());
    }
    
    void test_method_(count_on_items_list) {
      assert::are_equal(3_z, linked_list {42, 84, 21}.count());
    }
    
    void test_method_(first_on_empty_list) {
      auto list = linked_list<int> {};
      assert::is_null(list.first());
    }
    
    void test_method_(first_on_one_item_list) {
      assert::is_null(linked_list {42}.first()->previous());
      assert::is_null(linked_list {42}.first()->next());
      assert::are_equal(42, linked_list {42}.first()->value());
    }
    
    void test_method_(first_on_items_list) {
      assert::is_null(linked_list {42, 84}.first()->previous());
      assert::are_equal(84, linked_list {42, 84}.first()->next()->value());
      assert::are_equal(42, linked_list {42, 84}.first()->value());
    }
    
    void test_method_(items_on_empty_list) {
      assert::is_zero(linked_list<int> {}.items());
    }
    
    void test_method_(items_on_one_item_list) {
      collection_assert::are_equal({42}, linked_list {42}.items());
    }
    
    void test_method_(items_on_items_list) {
      collection_assert::are_equal({42, 84}, linked_list {42, 84}.items());
    }
    
    void test_method_(last_on_empty_list) {
      assert::is_null(linked_list<int> {}.last());
    }
    
    void test_method_(last_on_one_item_list) {
      assert::is_null(linked_list {42}.last()->previous());
      assert::is_null(linked_list {42}.last()->next());
      assert::are_equal(42, linked_list {42}.last()->value());
    }
    
    void test_method_(last_on_items_list) {
      assert::are_equal(42, linked_list {42, 84}.last()->previous()->value());
      assert::is_null(linked_list {42, 84}.last()->next());
      assert::are_equal(84, linked_list {42, 84}.last()->value());
    }
    
    void test_method_(add_after_value_on_empty_list) {
      auto list = linked_list<int> {};
      /// @todo Does not work as xtd::optional is an alias on std::optional. Remove following commnt when xtd::optional will an alias on xtd::nullable.
      //assert::throws<argument_null_exception>([&] {list.add_after(*list.first(), 42);});
    }
    
    void test_method_(add_after_value_on_one_item_list) {
      auto list = linked_list {42};
      auto node = list.add_after(*list.first(), 84);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_after_value_on_items_list) {
      auto list = linked_list {42, 84};
      auto node = list.add_after(*list.first()->next(), 21);
      assert::are_equal(21, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_after_new_node_on_empty_list) {
      auto list = linked_list<int> {};
      /// @todo Does not work as xtd::optional is an alias on std::optional. Remove following commnt when xtd::optional will an alias on xtd::nullable.
      //auto node = linked_list_node {42}:
      //assert::throws<argument_null_exception>([&] {list.add_after(*list.first(), node);});
    }
    
    void test_method_(add_after_new_node_on_one_item_list) {
      auto list = linked_list {42};
      auto node = linked_list_node {84};
      list.add_after(*list.first(), node);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_after_new_node_on_items_list) {
      auto list = linked_list {42, 84};
      auto node = linked_list_node {21};
      list.add_after(*list.first()->next(), node);
      assert::are_equal(21, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_after_with_invalid_node) {
      auto list = linked_list {42, 84};
      auto node = linked_list_node {21};
      assert::throws<invalid_operation_exception>([&] {list.add_after(*linked_list {42, 84}.first()->next(), node);});
    }
    
    void test_method_(add_after_with_invalid_new_node) {
      auto list = linked_list {42, 84};
      auto node = *list.first();
      assert::throws<invalid_operation_exception>([&] {list.add_after(*list.first()->next(), node);});
      node = *linked_list {42, 84}.first();
      assert::throws<invalid_operation_exception>([&] {list.add_after(*list.first()->next(), node);});
    }
    
    void test_method_(add_after_node_stale) {
      auto list = linked_list {42, 84, 21};
      auto first_node = *list.first();
      auto node = *list.first()->next();
      auto last_node = *list.last();
      assert::are_equal(42, first_node.value());
      assert::are_equal(84, node.value());
      assert::are_equal(21, last_node.value());
      list.add_after(node, 12);
      assert::throws<invalid_operation_exception>([&] {first_node.value();});
      assert::throws<invalid_operation_exception>([&] {node.value();});
      assert::throws<invalid_operation_exception>([&] {last_node.value();});
    }
    
    void test_method_(add_before_value_on_empty_list) {
      auto list = linked_list<int> {};
      /// @todo Does not work as xtd::optional is an alias on std::optional. Remove following commnt when xtd::optional will an alias on xtd::nullable.
      //assert::throws<argument_null_exception>([&] {list.add_before(*list.first(), 42);});
    }
    
    void test_method_(add_before_value_on_one_item_list) {
      auto list = linked_list {84};
      auto node = list.add_before(*list.first(), 42);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_before_value_on_items_list) {
      auto list = linked_list {42, 21};
      auto node = list.add_before(*list.first()->next(), 84);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_before_new_node_on_empty_list) {
      auto list = linked_list<int> {};
      /// @todo Does not work as xtd::optional is an alias on std::optional. Remove following commnt when xtd::optional will an alias on xtd::nullable.
      //auto node = linked_list_node {42}:
      //assert::throws<argument_null_exception>([&] {list.add_before(*list.first(), node);});
    }
    
    void test_method_(add_before_new_node_on_one_item_list) {
      auto list = linked_list {84};
      auto node = linked_list_node {42};
      list.add_before(*list.first(), node);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_before_new_node_on_items_list) {
      auto list = linked_list {42, 21};
      auto node = linked_list_node {84};
      list.add_before(*list.first()->next(), node);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_before_with_invalid_node) {
      auto list = linked_list {42, 21};
      auto node = linked_list_node {84};
      assert::throws<invalid_operation_exception>([&] {list.add_before(*linked_list {42, 21}.first()->next(), node);});
    }
    
    void test_method_(add_before_with_invalid_new_node) {
      auto list = linked_list {42, 21};
      auto node = *list.first();
      assert::throws<invalid_operation_exception>([&] {list.add_before(*list.first()->next(), node);});
      node = *linked_list {42, 21}.first();
      assert::throws<invalid_operation_exception>([&] {list.add_before(*list.first()->next(), node);});
    }
    
    void test_method_(add_before_node_stale) {
      auto list = linked_list {42, 84, 12};
      auto first_node = *list.first();
      auto node = *list.first()->next();
      auto last_node = *list.last();
      assert::are_equal(42, first_node.value());
      assert::are_equal(84, node.value());
      assert::are_equal(12, last_node.value());
      list.add_before(node, 21);
      assert::throws<invalid_operation_exception>([&] {first_node.value();});
      assert::throws<invalid_operation_exception>([&] {node.value();});
      assert::throws<invalid_operation_exception>([&] {last_node.value();});
    }
    
    void test_method_(add_first_value_on_empty_list) {
      auto list = linked_list<int> {};
      auto node = list.add_first(42);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42}, list);
    }
    
    void test_method_(add_first_value_on_one_item_list) {
      auto list = linked_list {84};
      auto node = list.add_first(42);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_first_value_on_items_list) {
      auto list = linked_list {84, 21};
      auto node = list.add_first(42);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_first_new_node_on_empty_list) {
      auto list = linked_list<int> {};
      auto node = linked_list_node {42};
      list.add_first(node);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42}, list);
    }
    
    void test_method_(add_first_new_node_on_one_item_list) {
      auto list = linked_list {84};
      auto node = linked_list_node {42};
      list.add_first(node);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_first_new_node_on_items_list) {
      auto list = linked_list {84, 21};
      auto node = linked_list_node {42};
      list.add_first(node);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_first_with_invalid_new_node) {
      auto list = linked_list {42, 21};
      auto node = *list.first();
      assert::throws<invalid_operation_exception>([&] {list.add_first(node);});
      node = *linked_list {42, 21}.first();
      assert::throws<invalid_operation_exception>([&] {list.add_first(node);});
    }
    
    void test_method_(add_first_node_stale) {
      auto list = linked_list {84, 21, 12};
      auto first_node = *list.first();
      auto node = *list.first()->next();
      auto last_node = *list.last();
      assert::are_equal(84, first_node.value());
      assert::are_equal(21, node.value());
      assert::are_equal(12, last_node.value());
      list.add_first(42);
      assert::throws<invalid_operation_exception>([&] {first_node.value();});
      assert::throws<invalid_operation_exception>([&] {node.value();});
      assert::throws<invalid_operation_exception>([&] {last_node.value();});
    }
    
    void test_method_(add_last_value_on_empty_list) {
      auto list = linked_list<int> {};
      auto node = list.add_last(42);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42}, list);
    }
    
    void test_method_(add_last_value_on_one_item_list) {
      auto list = linked_list {42};
      auto node = list.add_last(84);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_last_value_on_items_list) {
      auto list = linked_list {42, 84};
      auto node = list.add_last(21);
      assert::are_equal(21, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_last_new_node_on_empty_list) {
      auto list = linked_list<int> {};
      auto node = linked_list_node {42};
      list.add_last(node);
      assert::are_equal(42, node.value());
      collection_assert::are_equal({42}, list);
    }
    
    void test_method_(add_last_new_node_on_one_item_list) {
      auto list = linked_list {42};
      auto node = linked_list_node {84};
      list.add_last(node);
      assert::are_equal(84, node.value());
      collection_assert::are_equal({42, 84}, list);
    }
    
    void test_method_(add_last_new_node_on_items_list) {
      auto list = linked_list {42, 84};
      auto node = linked_list_node {21};
      list.add_last(node);
      assert::are_equal(21, node.value());
      collection_assert::are_equal({42, 84, 21}, list);
    }
    
    void test_method_(add_last_with_invalid_new_node) {
      auto list = linked_list {42, 21};
      auto node = *list.first();
      assert::throws<invalid_operation_exception>([&] {list.add_last(node);});
      node = *linked_list {42, 21}.first();
      assert::throws<invalid_operation_exception>([&] {list.add_last(node);});
    }
    
    void test_method_(add_last_node_stale) {
      auto list = linked_list {42, 84, 21};
      auto first_node = *list.first();
      auto node = *list.first()->next();
      auto last_node = *list.last();
      assert::are_equal(42, first_node.value());
      assert::are_equal(84, node.value());
      assert::are_equal(21, last_node.value());
      list.add_last(12);
      assert::throws<invalid_operation_exception>([&] {first_node.value();});
      assert::throws<invalid_operation_exception>([&] {node.value();});
      assert::throws<invalid_operation_exception>([&] {last_node.value();});
    }
    
    void test_method_(clear_empty_list) {
      auto list = linked_list<int> {};
      list.clear();
      collection_assert::is_empty(list);
    }
    
    void test_method_(clear_not_empty_list) {
      auto list = linked_list {42, 84, 21};
      list.clear();
      collection_assert::is_empty(list);
    }
    
    void test_method_(clear_stale) {
      auto list = linked_list {42, 84, 21};
      auto first_node = *list.first();
      auto node = *list.first()->next();
      auto last_node = *list.last();
      assert::are_equal(42, first_node.value());
      assert::are_equal(84, node.value());
      assert::are_equal(21, last_node.value());
      list.clear();
      assert::throws<invalid_operation_exception>([&] {first_node.value();});
      assert::throws<invalid_operation_exception>([&] {node.value();});
      assert::throws<invalid_operation_exception>([&] {last_node.value();});
    }
    
    void test_method_(contains_empty_list) {
      assert::is_false(linked_list<int> {}.contains(42));
    }
    
    void test_method_(contains_not_empty_list) {
      assert::is_true(linked_list {42, 84, 21}.contains(42));
      assert::is_true(linked_list {42, 84, 21}.contains(84));
      assert::is_true(linked_list {42, 84, 21}.contains(21));
      assert::is_false(linked_list {42, 84, 21}.contains(12));
    }
    
    void test_method_(copy_to_an_empty_list) {
      auto items = array<int>(0_z);
      linked_list<int> {}.copy_to(items, 0_z);
      assert::throws<argument_out_of_range_exception>([&] {linked_list<int> {}.copy_to(items, 1_z);});
    }
    
    void test_method_(copy_to_an_not_empty_list) {
      auto items = array<int>(5_z);
      linked_list {42, 84, 21}.copy_to(items, 0_z);
      collection_assert::are_equal({42, 84, 21, 0, 0}, items);
      items.fill(0);
      linked_list {42, 84, 21}.copy_to(items, 2_z);
      collection_assert::are_equal({0, 0, 42, 84, 21}, items);
      assert::throws<argument_out_of_range_exception>([&] {linked_list {42, 84, 21}.copy_to(items, 3_z);});
    }
    
    void test_method_(find_on_empty_list) {
      assert::is_null(linked_list<int> {}.find(42));
    }
    
    void test_method_(find_on_not_empty_list) {
      auto list = linked_list {42, 84, 21, 42};

      assert::are_equal(list, list.find(42)->list());
      assert::are_equal(84, list.find(42)->next()->value());
      assert::is_null(list.find(42)->previous());
      assert::are_equal(42, list.find(42)->value());

      assert::are_equal(list, list.find(84)->list());
      assert::are_equal(21, list.find(84)->next()->value());
      assert::are_equal(42, list.find(84)->previous()->value());
      assert::are_equal(84, list.find(84)->value());

      assert::are_equal(list, list.find(21)->list());
      assert::are_equal(42, list.find(21)->next()->value());
      assert::are_equal(84, list.find(21)->previous()->value());
      assert::are_equal(21, list.find(21)->value());

      assert::is_null(linked_list<int> {}.find(12));
    }
    
    void test_method_(find_last_on_empty_list) {
      assert::is_null(linked_list<int> {}.find_last(42));
    }
    
    void test_method_(find_last_on_not_empty_list) {
      auto list = linked_list {42, 84, 21, 42};
      
      assert::are_equal(list, list.find_last(42)->list());
      assert::is_null(list.find_last(42)->next());
      assert::are_equal(21, list.find_last(42)->previous()->value());
      assert::are_equal(42, list.find_last(42)->value());
      
      assert::are_equal(list, list.find_last(21)->list());
      assert::are_equal(42, list.find_last(21)->next()->value());
      assert::are_equal(84, list.find_last(21)->previous()->value());
      assert::are_equal(21, list.find_last(21)->value());

      assert::are_equal(list, list.find_last(84)->list());
      assert::are_equal(21, list.find_last(84)->next()->value());
      assert::are_equal(42, list.find_last(84)->previous()->value());
      assert::are_equal(84, list.find_last(84)->value());
      
      assert::is_null(linked_list<int> {}.find_last(12));
    }
    
    void test_method_(get_enumerator_on_empty_list) {
      auto list = linked_list<int> {};
      auto enumerator = list.get_enumerator();
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = enumerator.current();});
      assert::is_false(enumerator.move_next());
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = enumerator.current();});
    }
    
    void test_method_(get_enumerator_on_not_empty_list) {
      auto list = linked_list {42, 84, 21};
      auto enumerator = list.get_enumerator();
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = enumerator.current();});
      assert::is_true(enumerator.move_next());
      assert::are_equal(42, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(84, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(21, enumerator.current());
      assert::is_false(enumerator.move_next());
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = enumerator.current();});
    }
    
    void test_method_(iterator_on_empty_list) {
      auto list = linked_list<int> {};
      auto iterator = list.begin();
      assert::are_equal(list.end(), iterator);
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = *iterator;});
    }
    
    void test_method_(iterator_on_not_empty_list) {
      auto list = linked_list {42, 84, 21};
      auto iterator = list.begin();
      assert::are_not_equal(list.end(), iterator);
      assert::are_equal(42, *iterator);
      assert::are_not_equal(list.end(), ++iterator);
      assert::are_equal(84, *iterator);
      assert::are_not_equal(list.end(), ++iterator);
      assert::are_equal(21, *iterator);
      assert::are_equal(list.end(), ++iterator);
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto value = *iterator;});
    }
  };
}
