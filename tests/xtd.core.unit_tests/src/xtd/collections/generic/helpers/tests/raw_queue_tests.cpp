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
  };
}
