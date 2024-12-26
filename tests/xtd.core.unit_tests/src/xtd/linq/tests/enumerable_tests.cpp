#include <xtd/linq/enumerable>
#include <xtd/icomparable>
#include <xtd/invalid_operation_exception>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::linq;
using namespace xtd::tunit;

namespace xtd::linq::tests {
  class test_class_(enumerable_tests) {
    void test_method_(aggregate_with_enumerable_and_func) {
      assert::are_equal(15, enumerable::aggregate(array {1, 2, 3, 4, 5}, [](int total, int next)->int {return total + next;}));
    }
    
    void test_method_(aggregate_with_intializer_list_and_func) {
      assert::are_equal(15, enumerable::aggregate({1, 2, 3, 4, 5}, [](int total, int next)->int {return total + next;}));
    }
    
    void test_method_(aggregate_with_collection_and_func) {
      assert::are_equal(15, enumerable::aggregate(std::vector {1, 2, 3, 4, 5}, [](int total, int next)->int {return total + next;}));
    }
    
    void test_method_(aggregate_with_iterators_and_func) {
      auto s = array {1, 2, 3, 4, 5};
      assert::are_equal(15, enumerable::aggregate(s.begin(), s.end(), [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_enumerable_seed_and_func) {
      assert::are_equal(25, enumerable::aggregate(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_initializer_list_seed_and_func) {
      assert::are_equal(25, enumerable::aggregate({1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_collection_seed_and_func) {
      assert::are_equal(25, enumerable::aggregate(std::vector {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}));
    }

    void test_method_(aggregate_with_iterators_seed_and_func) {
      auto s = array {1, 2, 3, 4, 5};
      assert::are_equal(25, enumerable::aggregate(s.begin(), s.end(), 10, [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_enumerable_seed_func_and_result_selector) {
      assert::are_equal(-25, enumerable::aggregate(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }
    
    void test_method_(aggregate_with_initializer_list_seed_func_and_result_selector) {
      assert::are_equal(-25, enumerable::aggregate({1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }
    
    void test_method_(aggregate_with_collection_seed_func_and_result_selector) {
      assert::are_equal(-25, enumerable::aggregate(std::vector {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }
    
    void test_method_(aggregate_with_iterators_seed_func_and_result_selector) {
      auto s = array {1, 2, 3, 4, 5};
      assert::are_equal(-25, enumerable::aggregate(s.begin(), s.end(), 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }

    void test_method_(all_with_enumerable_and_predicate) {
      assert::is_true(enumerable::all(array {2, 4, 6, 8, 10, 12}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::all(array {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(all_with_initializer_list_and_predicate) {
      assert::is_true(enumerable::all({2, 4, 6, 8, 10, 12}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::all({1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(all_with_collection_and_predicate) {
      assert::is_true(enumerable::all(std::vector {2, 4, 6, 8, 10, 12}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::all(std::vector {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(all_with_iterators_and_predicate) {
      auto s1 = array {2, 4, 6, 8, 10, 12};
      assert::is_true(enumerable::all(s1.begin(), s1.end(), [](int next) {return next % 2 == 0;}));
      auto s2 = array {1, 2, 3, 4, 5};
      assert::is_false(enumerable::all(s2.begin(), s2.end(), [](int next) {return next % 2 == 0;}));
    }

    void test_method_(any_with_enumerable) {
      assert::is_true(enumerable::any(array {1}));
      assert::is_false(enumerable::any(array<int> {}));
    }
    
    void test_method_(any_with_initializer_list) {
      assert::is_true(enumerable::any({1}));
      assert::is_false(enumerable::any(std::initializer_list<int> {}));
    }
    
    void test_method_(any_with_collection) {
      assert::is_true(enumerable::any(std::vector {1}));
      assert::is_false(enumerable::any(std::vector<int> {}));
    }
    
    void test_method_(any_with_iterators) {
      auto s1 = array {1};
      assert::is_true(enumerable::any(s1.begin(), s1.end()));
      auto s2 = array<int> {};
      assert::is_false(enumerable::any(s2.begin(), s2.end()));
    }
    
    void test_method_(any_with_enumerable_and_predicate) {
      assert::is_true(enumerable::any(array {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::any(array {1, 3, 5, 7, 9, 11}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(any_with_initializer_list_and_predicate) {
      assert::is_true(enumerable::any({1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::any({1, 3, 5, 7, 9, 11}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(any_with_collection_and_predicate) {
      assert::is_true(enumerable::any(std::vector {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::any(std::vector {1, 3, 5, 7, 9, 11}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(any_with_iterators_and_predicate) {
      auto s1 = array {1, 2, 3, 4, 5};
      assert::is_true(enumerable::any(s1.begin(), s1.end(), [](int next) {return next % 2 == 0;}));
      auto s2 = array {1, 3, 5, 7, 9, 11};
      assert::is_false(enumerable::any(s2.begin(), s2.end(), [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(append_with_enumerable_and_element) {
      collection_assert::are_equal({1, 2, 3}, enumerable::append(array {1, 2}, 3));
    }
    
    void test_method_(append_with_initializer_list_and_element) {
      collection_assert::are_equal({1, 2, 3}, enumerable::append({1, 2}, 3));
    }
    
    void test_method_(append_with_collection_and_element) {
      collection_assert::are_equal({1, 2, 3}, enumerable::append(std::vector {1, 2}, 3));
    }
    
    void test_method_(append_with_iterators_and_element) {
      auto s = array {1, 2};
      collection_assert::are_equal({1, 2, 3}, enumerable::append(s.begin(), s.end(), 3));
    }
    
    void test_method_(as_enumerable_with_enumerable) {
      assert::is_instance_of<xtd::linq::enumerable_collection<int>>(enumerable::as_enumerable(array {1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(array {1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_initializer_list) {
      assert::is_instance_of<xtd::linq::enumerable_collection<int>>(enumerable::as_enumerable({1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable({1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_collection) {
      assert::is_instance_of<xtd::linq::enumerable_collection<int>>(enumerable::as_enumerable(std::vector {1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(std::vector {1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_iterators) {
      auto s = array {1, 2, 3};
      assert::is_instance_of<xtd::linq::enumerable_collection<int>>(enumerable::as_enumerable(s.begin(), s.end()));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(s.begin(), s.end()));
    }
    
    void test_method_(average_with_enumerable_decimal) {
      assert::are_equal(.3l, enumerable::average(array {.1l, .2l, .3l, .4l, .5l}));
      assert::throws<invalid_operation_exception>([]{enumerable::average(array<decimal> {});});
    }
    
    void test_method_(average_with_enumerable_double) {
      assert::are_equal(.3, enumerable::average(array {.1, .2, .3, .4, .5}));
      assert::throws<invalid_operation_exception>([]{enumerable::average(array<double> {});});
    }

    void test_method_(average_with_enumerable_float) {
      assert::are_equal(.3f, enumerable::average(array {.1f, .2f, .3f, .4f, .5f}));
      assert::throws<invalid_operation_exception>([]{enumerable::average(array<float> {});});
    }
    
    void test_method_(average_with_enumerable_int32) {
      assert::are_equal(3.0, enumerable::average(array {1, 2, 3, 4, 5}));
      assert::throws<invalid_operation_exception>([]{enumerable::average(array<int32> {});});
    }

    void test_method_(average_with_enumerable_int64) {
      assert::are_equal(3.0, enumerable::average(array {1_s64, 2_s64, 3_s64, 4_s64, 5_s64}));
      assert::throws<invalid_operation_exception>([]{enumerable::average(array<int64> {});});
    }
    
    void test_method_(average_with_enumerable_optional_decimal) {
      assert::are_equal(.3l, enumerable::average(array<optional<decimal>> {.1l, .2l, nullopt, .3l, .4l, .5l}));
      assert::are_equal(nullopt, enumerable::average(array<optional<decimal>> {}));
    }
    
    void test_method_(average_with_enumerable_optional_double) {
      assert::are_equal(.3, enumerable::average(array<optional<double>> {.1, .2, nullopt, .3, .4, .5}));
      assert::are_equal(nullopt, enumerable::average(array<optional<double>> {}));
    }
    
    void test_method_(average_with_enumerable_optional_float) {
      assert::are_equal(.3f, enumerable::average(array<optional<float>> {.1f, .2f, nullopt, .3f, .4f, .5f}));
      assert::are_equal(nullopt, enumerable::average(array<optional<float>> {}));
    }
    
    void test_method_(average_with_enumerable_optional_int32) {
      assert::are_equal(3.0, enumerable::average(array<optional<int32>> {1, 2, nullopt, 3, 4, 5}));
      assert::are_equal(nullopt, enumerable::average(array<optional<int32>> {}));
    }
    
    void test_method_(average_with_enumerable_optional_int64) {
      assert::are_equal(3.0, enumerable::average(array<optional<int64>> {1_s64, 2_s64, nullopt, 3_s64, 4_s64, 5_s64}));
      assert::are_equal(nullopt, enumerable::average(array<optional<int64>> {}));
    }
    
    void test_method_(range_with_start_and_count) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, enumerable::range(1, 5));
    }
  };
}
