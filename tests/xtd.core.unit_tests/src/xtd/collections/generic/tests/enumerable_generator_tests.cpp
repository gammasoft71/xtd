#include <xtd/collections/generic/enumerable_generator>
#include <xtd/invalid_operation_exception>
#include <xtd/not_supported_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(enumerable_generator_tests) {
    inline static constexpr auto numbers = {10, 3, 6, 2, 9, 1, 8, 4, 7, 5};
    auto numbers_generator() -> enumerable_generator<int> {
      for (auto number : numbers)
        co_yield number;
    }

    auto test_method_(enumerator) {
      auto enumerable = numbers_generator();
      auto enumerator = enumerable.get_enumerator();
      assert::throws<not_supported_exception>([&] {enumerator.reset();});
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto _ = enumerator.current();});
      assert::is_true(enumerator.move_next());
      assert::are_equal(10, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(3, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(6, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(2, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(9, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(1, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(8, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(4, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(7, enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::are_equal(5, enumerator.current());
      assert::is_false(enumerator.move_next());
      assert::throws<not_supported_exception>([&] {enumerator.reset();});
    }
    
    auto test_method_(const_iterator) {
      auto enumerable = numbers_generator();
      auto iterator = enumerable.cbegin();
      assert::are_equal(10, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(3, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(6, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(2, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(9, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(1, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(8, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(4, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(7, *iterator);
      assert::are_not_equal(enumerable.cend(), ++iterator);
      assert::are_equal(5, *iterator);
      assert::are_equal(enumerable.cend(), ++iterator);
      assert::are_equal(5, *iterator);
      assert::are_equal(enumerable.cend(), ++iterator);
      assert::are_equal(5, *iterator);
    }
    
    auto test_method_(duplicate_const_iterator) {
      auto enumerable = numbers_generator();
      auto iterator1 = enumerable.cbegin();
      assert::are_equal(10, *iterator1);
      auto iterator2 = enumerable.cbegin();
      assert::are_equal(3, *iterator1);
      assert::are_equal(3, *iterator2);
      assert::are_not_equal(enumerable.cend(), ++iterator1);
      assert::are_equal(6, *iterator1);
      assert::are_equal(6, *iterator2);
      assert::are_not_equal(enumerable.cend(), ++iterator2);
      assert::are_equal(2, *iterator1);
      assert::are_equal(2, *iterator2);
    }
    
    auto test_method_(iterator) {
      auto enumerable = numbers_generator();
      auto iterator = enumerable.begin();
      assert::are_equal(10, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(3, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(6, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(2, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(9, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(1, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(8, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(4, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(7, *iterator);
      assert::are_not_equal(enumerable.end(), ++iterator);
      assert::are_equal(5, *iterator);
      assert::are_equal(enumerable.end(), ++iterator);
      assert::are_equal(5, *iterator);
      assert::are_equal(enumerable.end(), ++iterator);
      assert::are_equal(5, *iterator);
    }

    auto test_method_(to_array) {
      collection_assert::are_equal(numbers, numbers_generator().to_array());
    }
  };
}
