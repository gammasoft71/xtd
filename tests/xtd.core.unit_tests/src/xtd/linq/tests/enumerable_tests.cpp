#include <xtd/linq/enumerable>
#include <xtd/icomparable>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::linq;
using namespace xtd::tunit;

namespace xtd::linq::tests {
  class test_class_(enumerable_tests) {
    void test_method_(aggregate_with_source_and_func) {
      assert::are_equal(15, enumerable::aggregate(array {1, 2, 3, 4, 5}, [](int total, int next) {return total + next;}));
    }

    void test_method_(aggregate_with_source_seed_and_func) {
      assert::are_equal(25, enumerable::aggregate(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}));
    }

    void test_method_(aggregate_with_source_seed_func_and_result_selector) {
      assert::are_equal(-25, enumerable::aggregate(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }
    
    void test_method_(aggregate_with_iterators_and_func) {
      auto s = std::vector {1, 2, 3, 4, 5};
      assert::are_equal(15, enumerable::aggregate<int>(s.begin(), s.end(), [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_iterators_seed_and_func) {
      auto s = std::vector {1, 2, 3, 4, 5};
      assert::are_equal(25, enumerable::aggregate(s.begin(), s.end(), 10, [](int total, int next) {return total + next;}));
    }

    void test_method_(aggregate_with_iterators_seed_func_and_result_selector) {
      auto s = std::vector {1, 2, 3, 4, 5};
      assert::are_equal(-25, enumerable::aggregate(s.begin(), s.end(), 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }

    void test_method_(all_with_source_and_func) {
      assert::is_true(enumerable::all(array {2, 4, 6, 8, 10, 12}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::all(array {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
    }

    void test_method_(any_with_source) {
      assert::is_true(enumerable::any(array {1}));
      assert::is_false(enumerable::any(array<int> {}));
    }
  };
}
