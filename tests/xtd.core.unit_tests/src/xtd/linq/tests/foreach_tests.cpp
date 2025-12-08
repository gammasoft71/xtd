#include <xtd/linq/foreach>
#include <xtd/collections/generic/list>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::linq::tests {
  class test_class_(foreach_tests) {
    auto test_method_(ienumerable_defined_before_foreach) {
      auto items = list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      foreach_(auto item, items)
      accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(ienumerable_defined_in_foreach) {
      auto accumulator = 0;
      foreach_(auto item, list {1, 2, 3, 4, 5})
      accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(vector_defined_before_foreach) {
      auto items = std::vector {1, 2, 3, 4, 5};
      auto accumulator = 0;
      foreach_(auto item, items)
      accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(vector_defined_in_foreach) {
      auto accumulator = 0;
      foreach_(auto item, std::vector {1, 2, 3, 4, 5})
      accumulator += item;
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(with_break) {
      auto accumulator = 0;
      auto index = 0;
      foreach_(auto item, list {1, 2, 3, 4, 5}) {
        accumulator += item;
        if (++index == 2) break;
      }
      assert::are_equal(3, accumulator);
    }
    
    auto test_method_(with_continue) {
      auto accumulator = 0;
      auto index = 0;
      foreach_(auto item, list {1, 2, 3, 4, 5}) {
        if (++index <= 2) continue;
        accumulator += item;
      }
      assert::are_equal(12, accumulator);
    }
  };
}
