#include <xtd/span>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(span_tests) {
    void test_method_(element_type) {
      assert::are_equal(typeof_<const int>(), typeof_<span<const int>::element_type>());
      assert::are_equal(typeof_<int>(), typeof_<span<int>::element_type>());
    }
    
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<span<const int>::value_type>());
      assert::are_equal(typeof_<int>(), typeof_<span<int>::value_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<size>(), typeof_<span<int>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<ptrdiff>(), typeof_<span<int>::difference_type>());
    }

    void test_method_(pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<span<const int>::pointer>());
      assert::are_equal(typeof_<int*>(), typeof_<span<int>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<span<const int>::const_pointer>());
      assert::are_equal(typeof_<const int*>(), typeof_<span<int>::const_pointer>());
    }

    void test_method_(reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<span<const int>::reference>());
      assert::are_equal(typeof_<int&>(), typeof_<span<int>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<span<const int>::const_reference>());
      assert::are_equal(typeof_<const int&>(), typeof_<span<int>::const_reference>());
    }

    void test_method_(iterator) {
      assert::are_equal(typeof_<wrap_pointer_iterator<const int*>>(), typeof_<span<const int>::iterator>());
      assert::are_equal(typeof_<wrap_pointer_iterator<int*>>(), typeof_<span<int>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<const wrap_pointer_iterator<const int*>>(), typeof_<span<const int>::const_iterator>());
      assert::are_equal(typeof_<const wrap_pointer_iterator<int*>>(), typeof_<span<int>::const_iterator>());
    }

    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<span<const int>::reverse_iterator>());
      assert::are_equal(typeof_<std::reverse_iterator<wrap_pointer_iterator<int*>>>(), typeof_<span<int>::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<span<const int>::const_reverse_iterator>());
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<int*>>>(), typeof_<span<int>::const_reverse_iterator>());
    }

    void test_method_(constructor_default) {
      auto s = span<int>();
      assert::is_null(s.data());
      assert::is_zero(s.size());
      collection_assert::is_empty(s);
    }
    
    void test_method_(constructor_default_with_static_extent) {
      auto s = span<int, 42>();
      assert::is_null(s.data());
      assert::is_zero(s.size());
      collection_assert::is_empty(s);
    }
    
    void test_method_(constructor_with_const_iterators) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_iterators_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_iterators) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_iterators_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_const_iterator_and_count) {
      /* Conflict with span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.size());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    void test_method_(constructor_with_const_iterator_count_and_static_extent) {
      /* Conflict with span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.size());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }

    void test_method_(constructor_with_iterator_and_count) {
      /* Conflict with span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.size());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    void test_method_(constructor_with_iterator_count_and_static_extent) {
      /* Conflict with span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.size());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }

    void test_method_(constructor_with_const_native_array) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_native_array_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_native_array) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }

    void test_method_(constructor_with_native_array_and_static_extent) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_const_std_array) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_std_array_and_static_extent) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_std_array) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_std_array_and_static_extent) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_const_range) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_range_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_range) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_range_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_initializer_list) {
      auto a = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_initializer_list_and_static_extent) {
      auto a = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_const_collection) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_collection_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_collection) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_collection_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_const_collection_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_const_collection_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_collection_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_collection_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_collection_start_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_collection_start_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_collection_start_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_collection_start_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({20, 30, 40}, s);
    }

    void test_method_(constructor_with_const_pointer_and_size) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_pointer_size_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }

    void test_method_(constructor_with_pointer_and_size) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_pointer_size_and_static_extent) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(back) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(50, s.back());
    }
    
    void test_method_(const_begin) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    void test_method_(begin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    void test_method_(cbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.cbegin().data());
      assert::are_equal(10, *s.cbegin());
    }
    
    void test_method_(cend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.cend().data());
    }
    
    void test_method_(crbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.crbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    void test_method_(crend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.crend().base().data());
    }
    
    void test_method_(data) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(10, *s.data());
    }
    
    void test_method_(empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::is_false(s.empty());
      assert::is_true(span<int> {}.empty());
      assert::is_true(span<int>::empty_span.empty());
    }
    
    void test_method_(empty_span) {
      assert::is_null(span<int>::empty_span.data());
      assert::is_zero(span<int>::empty_span.size());
    }
    
    void test_method_(const_end) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    void test_method_(end) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    void test_method_(front) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(10, s.front());
    }
    
    void test_method_(is_empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::is_false(s.is_empty());
      assert::is_true(span<int> {}.is_empty());
      assert::is_true(span<int>::empty_span.is_empty());
    }
  };
}
