#include <xtd/collections/generic/linked_list>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(linked_list_node_tests) {
    auto test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<linked_list_node<int>::value_type>());
    }
    
    auto test_method_(linked_list_type) {
      assert::are_equal(typeof_<linked_list<int>>(), typeof_<linked_list_node<int>::linked_list_type>());
    }
    
    auto test_method_(base_type) {
      assert::are_equal(typeof_<linked_list<int>::base_type>(), typeof_<linked_list_node<int>::base_type>());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<linked_list<int>::size_type>(), typeof_<linked_list_node<int>::size_type>());
    }
    
    auto test_method_(constructor_with_int_value) {
      auto node = linked_list_node {42};
      assert::are_equal(42, node.value());
      assert::is_true(node.list().is_empty());
      assert::is_null(node.previous());
      assert::is_null(node.next());
    }
    
    auto test_method_(constructor_with_string_value) {
      auto node = linked_list_node {"value"_s};
      assert::are_equal("value", node.value());
      assert::is_true(node.list().is_empty());
      assert::is_null(node.previous());
      assert::is_null(node.next());
    }
    
    auto test_method_(copy_constructor) {
      auto node1 = linked_list_node {42};
      auto node2 = node1;
      assert::are_equal(42, node2.value());
      assert::is_true(node2.list().is_empty());
      assert::is_null(node2.previous());
      assert::is_null(node2.next());
    }
    
    auto test_method_(move_constructor) {
      auto node1 = linked_list_node {42};
      auto node2 = std::move(node1);
      assert::are_equal(42, node2.value());
      assert::is_true(node2.list().is_empty());
      assert::is_null(node2.previous());
      assert::is_null(node2.next());
    }
    
    auto test_method_(create_from_linked_list_with_one_item) {
      auto list = linked_list<int> {42};
      auto node = *list.first();
      assert::are_equal(42, node.value());
      assert::are_equal(list, node.list());
      assert::is_null(node.previous());
      assert::is_null(node.next());
    }
    
    auto test_method_(create_from_linked_list_with_two_item) {
      auto list = linked_list<int> {42, 84};
      auto node = *list.first();
      assert::are_equal(42, node.value());
      assert::are_equal(list, node.list());
      assert::is_null(node.previous());
      assert::are_equal(84, node.next()->value());
      assert::are_equal(42, node.next()->previous()->value());
      assert::is_null(node.next()->next());
    }
    
    auto test_method_(create_from_linked_list_with_three_item) {
      auto list = linked_list<int> {42, 84, 21};
      auto node = *list.first();
      assert::are_equal(42, node.value());
      assert::are_equal(list, node.list());
      assert::is_null(node.previous());
      assert::are_equal(84, node.next()->value());
      assert::are_equal(42, node.next()->previous()->value());
      assert::are_equal(21, node.next()->next()->value());
    }
    
    auto test_method_(value_throws_excpetion_when_linked_list_changed) {
      auto list = linked_list<int> {42, 84, 21};
      auto node = *list.first()->next();
      list.clear();
      assert::throws<invalid_operation_exception>([&] {node.value();});
    }
    
    auto test_method_(next_throws_excpetion_when_linked_list_changed) {
      auto list = linked_list<int> {42, 84, 21};
      auto node = *list.first()->next();
      list.clear();
      assert::throws<invalid_operation_exception>([&] {node.next();});
    }
    
    auto test_method_(previous_throws_excpetion_when_linked_list_changed) {
      auto list = linked_list<int> {42, 84, 21};
      auto node = *list.first()->next();
      list.clear();
      assert::throws<invalid_operation_exception>([&] {node.previous();});
    }
    
    auto test_method_(copy_operator) {
      auto node1 = linked_list_node {42};
      auto node2 = linked_list_node {84};
      node2 = node1;
      assert::are_equal(42, node2.value());
      assert::is_true(node2.list().is_empty());
      assert::is_null(node2.previous());
      assert::is_null(node2.next());
    }
    
    auto test_method_(move_operator) {
      auto node1 = linked_list_node {42};
      auto node2 = linked_list_node {84};
      node2 = std::move(node1);
      assert::are_equal(42, node2.value());
      assert::is_true(node2.list().is_empty());
      assert::is_null(node2.previous());
      assert::is_null(node2.next());
    }
  };
}
