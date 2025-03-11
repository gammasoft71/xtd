#include <xtd/linq/enumerable>
#include <xtd/collections/generic/equality_comparer.hpp>
#include <xtd/collections/generic/list>
#include <xtd/argument_out_of_range_exception>
#include <xtd/as>
#include <xtd/icomparable>
#include <xtd/invalid_operation_exception>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::linq;
using namespace xtd::tunit;

namespace xtd::linq::tests {
  class test_class_(enumerable_tests) {
    void test_method_(aggregate_with_enumerable_and_func) {
      assert::are_equal(15, enumerable::aggregate<int>(array {1, 2, 3, 4, 5}, [](int total, int next)->int {return total + next;}));
    }
    
    void test_method_(aggregate_with_enumerable_seed_and_func) {
      assert::are_equal(25, enumerable::aggregate<int, int>(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}));
    }
    
    void test_method_(aggregate_with_enumerable_seed_func_and_result_selector) {
      assert::are_equal(-25, enumerable::aggregate<int, int, int>(array {1, 2, 3, 4, 5}, 10, [](int total, int next) {return total + next;}, [](int aggregated) {return -aggregated;}));
    }

    void test_method_(all_with_enumerable_and_predicate) {
      assert::is_true(enumerable::all<int>(array {2, 4, 6, 8, 10, 12}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::all<int>(array {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
    }

    void test_method_(any_with_enumerable) {
      assert::is_true(enumerable::any(array {1}));
      assert::is_false(enumerable::any(array<int> {}));
    }
    
    void test_method_(any_with_enumerable_and_predicate) {
      assert::is_true(enumerable::any<int>(array {1, 2, 3, 4, 5}, [](int next) {return next % 2 == 0;}));
      assert::is_false(enumerable::any<int>(array {1, 3, 5, 7, 9, 11}, [](int next) {return next % 2 == 0;}));
    }
    
    void test_method_(append_with_enumerable_and_element) {
      collection_assert::are_equal({1, 2, 3}, enumerable::append(array {1, 2}, 3));
    }
    
    void test_method_(as_enumerable_with_enumerable) {
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable(array {1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(array {1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_initializer_list) {
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable({1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable({1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_collection) {
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable(std::vector {1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(std::vector {1, 2, 3}));
    }
    
    void test_method_(as_enumerable_with_iterators) {
      auto s = array {1, 2, 3};
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable(s.begin(), s.end()));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(s.begin(), s.end()));
    }
    
    void test_method_(as_enumerable_with_iterator_and_length) {
      auto s = array {1, 2, 3};
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable(s.data(), s.size()));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(s.data(), s.size()));
    }

    void test_method_(as_enumerable_with_native_array) {
      int s[] = {1, 2, 3};
      assert::is_instance_of<xtd::collections::generic::ienumerable<int>>(enumerable::as_enumerable(s));
      collection_assert::are_equal({1, 2, 3}, enumerable::as_enumerable(s));
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
    
    void test_method_(cast_with_enumerable) {
      collection_assert::are_equal({1.0, 2.0, 3.0, 4.0, 5.0}, enumerable::cast<double>(array {1, 2, 3, 4, 5}));
      assert::is_instance_of<ienumerable<double>>(enumerable::cast<double>(array {1, 2, 3, 4, 5}));
    }
    
    void test_method_(chunk_with_enumerable) {
      auto s = array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
      const auto& chunks = enumerable::chunk(s, 4);
      auto enumerator = chunks.get_enumerator();
      assert::is_true(enumerator.move_next());
      collection_assert::are_equal({1, 2, 3, 4}, enumerator.current());
      assert::is_true(enumerator.move_next());
      collection_assert::are_equal({5, 6, 7, 8}, enumerator.current());
      assert::is_true(enumerator.move_next());
      collection_assert::are_equal({9, 10, 11, 12}, enumerator.current());
      assert::is_true(enumerator.move_next());
      collection_assert::are_equal({13, 14}, enumerator.current());
      assert::is_false(enumerator.move_next());

      assert::throws<xtd::argument_out_of_range_exception>([&] {enumerable::chunk(s, 0);});
    }
    
    void test_method_(concat_with_enumerable_and_enumerable) {
      collection_assert::are_equal({1, 2, 3, 4, 5, 6}, enumerable::concat(array {1, 2, 3}, array {4, 5, 6}));
      collection_assert::are_equal({1, 2, 3}, enumerable::concat(array {1, 2, 3}, array<int> {}));
      collection_assert::are_equal({4, 5, 6}, enumerable::concat(array<int> {}, array {4, 5, 6}));
    }
    
    void test_method_(contains_with_enumerable_and_value) {
      assert::is_true(enumerable::contains(array {1, 2, 3, 4, 5}, 3));
      assert::is_false(enumerable::contains(array {1, 2, 3, 4, 5}, 6));
    }
    
    void test_method_(contains_with_enumerable_and_iequality_comparer) {
      assert::is_true(enumerable::contains(array {1, 2, 3, 4, 5}, 3, equality_comparer<int>::default_equality_comparer()));
      assert::is_false(enumerable::contains(array {1, 2, 3, 4, 5}, 6, equality_comparer<int>::default_equality_comparer()));
    }
    
    void test_method_(count_with_enumerable) {
      assert::are_equal(5u, enumerable::count(array {1, 2, 3, 4, 5}));
      assert::are_equal(0u, enumerable::count(array<int> {}));
    }
    
    void test_method_(count_with_enumerable_and_predicate) {
      assert::are_equal(3u, enumerable::count<int>(array {1, 2, 3, 4, 5}, [](int value) {return value <= 3;}));
      assert::are_equal(0u, enumerable::count<int>(array {1, 2, 3, 4, 5}, [](int value) {return value < 0;}));
    }
    
    void test_method_(count_by_with_enumerable_and_key_selector) {
      const auto& result = enumerable::count_by<bool, int>(array {1, 2, 3, 4, 5, 6, 7, 9}, [](int value) {return value % 2 == 0;});
      auto enumerator = result.get_enumerator();
      assert::is_true(enumerator.move_next());
      assert::are_equal(false, enumerator.current().key());
      assert::are_equal(5u, enumerator.current().value());
      assert::is_true(enumerator.move_next());
      assert::are_equal(true, enumerator.current().key());
      assert::are_equal(3u, enumerator.current().value());
      assert::is_false(enumerator.move_next());
    }
    
    void test_method_(default_if_empty_with_enumerable) {
      collection_assert::are_equal({1, 2, 3}, enumerable::default_if_empty(array {1, 2, 3}));
      collection_assert::are_equal({0}, enumerable::default_if_empty(array<int> {}));
    }
    
    void test_method_(default_if_empty_with_enumerable_and_default_value) {
      collection_assert::are_equal({1, 2, 3}, enumerable::default_if_empty(array {1, 2, 3}, 5));
      collection_assert::are_equal({5}, enumerable::default_if_empty(array<int> {}, 5));
    }

    void test_method_(first_or_default_with_enumerable_predicate_and_default_value) {
      assert::are_equal(3, enumerable::first_or_default<int>(array {3, 4, 5}, [](int value) {return value <= 3;}, 2));
      assert::are_equal(2, enumerable::first_or_default<int>(array {3, 4, 5}, [](int value) {return value < 3;}, 2));
    }

    void test_method_(first_or_default_with_enumerable_and_predicate) {
      assert::are_equal(3, enumerable::first_or_default<int>(array {3, 4, 5}, [](int value) {return value <= 3;}));
      assert::are_equal(0, enumerable::first_or_default<int>(array {3, 4, 5}, [](int value) {return value < 3;}));
    }

    void test_method_(first_or_default_with_enumerable_and_default_value) {
      assert::are_equal(3, enumerable::first_or_default(array {3, 4, 5}, 2));
      assert::are_equal(2, enumerable::first_or_default(array<int> {}, 2));
    }
    
    void test_method_(first_or_default_with_enumerable) {
      assert::are_equal(3, enumerable::first_or_default(array {3, 4, 5}));
      assert::are_equal(0, enumerable::first_or_default(array<int> {}));
    }

    void test_method_(range_with_count) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enumerable::range(5));
      assert::is_zero(enumerable::range(0).count());
      assert::throws<argument_out_of_range_exception>([]{enumerable::range(-1);});
    }

    void test_method_(range_with_start_and_count) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, enumerable::range(1, 5));
      collection_assert::are_equal({11, 12, 13, 14, 15}, enumerable::range(11, 5));
      collection_assert::are_equal({-5, -4, -3, -2, -1}, enumerable::range(-5, 5));
      collection_assert::are_equal({-1, 0, 1, 2, 3}, enumerable::range(-1, 5));
      assert::is_zero(enumerable::range(1, 0).count());
      assert::throws<argument_out_of_range_exception>([]{enumerable::range(1, -1);});
    }

    void test_method_(range_with_start_count_end_step) {
      collection_assert::are_equal({1, 3, 5, 7, 9}, enumerable::range(1, 5, 2));
      collection_assert::are_equal({11, 9, 7, 5, 3}, enumerable::range(11, 5, -2));
      collection_assert::are_equal({-5, -3, -1, 1, 3}, enumerable::range(-5, 5, 2));
      collection_assert::are_equal({-1, -3, -5, -7, -9}, enumerable::range(-1, 5, -2));
      assert::throws<argument_exception>([]{enumerable::range(1, 5, 0);});
      assert::throws<argument_out_of_range_exception>([]{enumerable::range(1, -1, 1);});
    }

    void test_method_(to_list_with_enumerable) {
      assert::is_instance_of<list<int>>(enumerable::to_list(array {1, 2, 3}));
      collection_assert::are_equal({1, 2, 3}, enumerable::to_list(array {1, 2, 3}));
    }
  };
}
