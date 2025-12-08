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
    auto test_method_(element_type) {
      assert::are_equal(typeof_<const int>(), typeof_<span<const int>::element_type>());
      assert::are_equal(typeof_<int>(), typeof_<span<int>::element_type>());
    }
    
    auto test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<span<const int>::value_type>());
      assert::are_equal(typeof_<int>(), typeof_<span<int>::value_type>());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<span<int>::size_type>());
    }
    
    auto test_method_(difference_type) {
      assert::are_equal(typeof_<ptrdiff>(), typeof_<span<int>::difference_type>());
    }
    
    auto test_method_(pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<span<const int>::pointer>());
      assert::are_equal(typeof_<int*>(), typeof_<span<int>::pointer>());
    }
    
    auto test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<span<const int>::const_pointer>());
      assert::are_equal(typeof_<const int*>(), typeof_<span<int>::const_pointer>());
    }
    
    auto test_method_(reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<span<const int>::reference>());
      assert::are_equal(typeof_<int&>(), typeof_<span<int>::reference>());
    }
    
    auto test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<span<const int>::const_reference>());
      assert::are_equal(typeof_<const int&>(), typeof_<span<int>::const_reference>());
    }
    
    auto test_method_(iterator) {
      assert::are_equal(typeof_<wrap_pointer_iterator<const int*>>(), typeof_<span<const int>::iterator > ());
      assert::are_equal(typeof_<wrap_pointer_iterator<int*>>(), typeof_<span<int>::iterator > ());
    }
    
    auto test_method_(const_iterator) {
      assert::are_equal(typeof_<const wrap_pointer_iterator<const int*>>(), typeof_<span<const int>::const_iterator > ());
      assert::are_equal(typeof_<const wrap_pointer_iterator<int*>>(), typeof_<span<int>::const_iterator > ());
    }
    
    auto test_method_(reverse_iterator) {
      assert::are_equal(typeof_<std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<span<const int>::reverse_iterator>());
      assert::are_equal(typeof_<std::reverse_iterator<wrap_pointer_iterator<int*>>>(), typeof_<span<int>::reverse_iterator>());
    }
    
    auto test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<span<const int>::const_reverse_iterator>());
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<int*>>>(), typeof_<span<int>::const_reverse_iterator>());
    }
    
    auto test_method_(constructor_default) {
      auto s = span<int>();
      assert::is_null(s.data());
      assert::is_zero(s.length());
      collection_assert::is_empty(s);
    }
    
    auto test_method_(constructor_default_with_static_extent) {
      auto s = span<int, 42>();
      assert::is_null(s.data());
      assert::is_zero(s.length());
      collection_assert::is_empty(s);
    }
    
    auto test_method_(constructor_with_const_iterators) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_iterators_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_iterators) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_iterators_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_iterator_and_count) {
      /* Conflict with span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.length());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    auto test_method_(constructor_with_const_iterator_count_and_static_extent) {
      /* Conflict with span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.length());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }
    
    auto test_method_(constructor_with_iterator_and_count) {
      /* Conflict with span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.length());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    auto test_method_(constructor_with_iterator_count_and_static_extent) {
      /* Conflict with span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.length());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }
    
    auto test_method_(constructor_with_const_native_array) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_native_array_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_native_array) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_native_array_and_static_extent) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_std_array) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_std_array_and_static_extent) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_std_array) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_std_array_and_static_extent) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_range) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_range_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_range) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_range_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_initializer_list) {
      auto a = {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(a.size(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_initializer_list_and_static_extent) {
      auto a = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_collection) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_collection_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_collection) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.length(), s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_collection_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_collection_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    auto test_method_(constructor_with_const_collection_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_collection_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    auto test_method_(constructor_with_collection_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_const_collection_start_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.length());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_collection_start_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({20, 30, 40}, s);
    }
    
    auto test_method_(constructor_with_collection_start_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.length());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_collection_start_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({20, 30, 40}, s);
    }
    
    auto test_method_(constructor_with_const_pointer_and_size) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_const_pointer_size_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = span<const int, 3>(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(constructor_with_pointer_and_size) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.length());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    auto test_method_(constructor_with_pointer_size_and_static_extent) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.length());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    auto test_method_(back) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(50, s.back());
    }
    
    auto test_method_(const_begin) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    auto test_method_(begin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    auto test_method_(cbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.cbegin().data());
      assert::are_equal(10, *s.cbegin());
    }
    
    auto test_method_(cend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.cend().data());
    }
    
    auto test_method_(crbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.crbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    auto test_method_(crend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.crend().base().data());
    }
    
    auto test_method_(data) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(10, *s.data());
    }
    
    auto test_method_(empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::is_false(s.empty());
      assert::is_true(span<int> {}.empty());
      assert::is_true(span<int>::empty_span.empty());
    }
    
    auto test_method_(empty_span) {
      assert::is_null(span<int>::empty_span.data());
      assert::is_zero(span<int>::empty_span.size());
    }
    
    auto test_method_(const_end) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    auto test_method_(end) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    auto test_method_(front) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(10, s.front());
    }
    
    auto test_method_(is_empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::is_false(s.is_empty());
      assert::is_true(span<int> {}.is_empty());
      assert::is_true(span<int>::empty_span.is_empty());
    }
    
    auto test_method_(const_length) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(5_z, s.length());
    }
    
    auto test_method_(const_length_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    auto test_method_(length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(5_z, s.length());
    }
    
    auto test_method_(length_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    auto test_method_(const_rbegin) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data() + 5, s.rbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    auto test_method_(rbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data() + 5, s.rbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    auto test_method_(const_rend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(s.data(), s.rend().base().data());
    }
    
    auto test_method_(rend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(s.data(), s.rend().base().data());
    }
    
    auto test_method_(const_size) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(5_z, s.length());
    }
    
    auto test_method_(const_size_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    auto test_method_(size) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(5_z, s.length());
    }
    
    auto test_method_(size_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    auto test_method_(const_size_bytes) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(20_z, s.size_bytes());
    }
    
    auto test_method_(const_size_bytes_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span<int, 3>(a);
      assert::are_equal(12_z, s.size_bytes());
    }
    
    auto test_method_(size_bytes) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(20_z, s.size_bytes());
    }
    
    auto test_method_(size_bytes_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(12_z, s.size_bytes());
    }
    
    auto test_method_(const_at) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(10, s.at(0));
      assert::are_equal(20, s.at(1));
      assert::are_equal(30, s.at(2));
      assert::are_equal(40, s.at(3));
      assert::are_equal(50, s.at(4));
      assert::throws<index_out_of_range_exception>([&] {s.at(5);});
      assert::throws<index_out_of_range_exception>([] {span<int> {}.at(0);});
    }
    
    auto test_method_(at) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(10, s.at(0));
      assert::are_equal(20, s.at(1));
      assert::are_equal(30, s.at(2));
      assert::are_equal(40, s.at(3));
      assert::are_equal(50, s.at(4));
      assert::throws<index_out_of_range_exception>([&] {s.at(5);});
      assert::throws<index_out_of_range_exception>([] {span<int> {}.at(0);});
    }
    
    auto test_method_(clear) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      s.clear();
      assert::are_equal(0, s.at(0));
      assert::are_equal(0, s.at(1));
      assert::are_equal(0, s.at(2));
      assert::are_equal(0, s.at(3));
      assert::are_equal(0, s.at(4));
      
      assert::are_equal(0, a[0]);
      assert::are_equal(0, a[1]);
      assert::are_equal(0, a[2]);
      assert::are_equal(0, a[3]);
      assert::are_equal(0, a[4]);
    }
    
    auto test_method_(copy_to) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto ac = array {0, 0, 0, 0, 0};
      auto sc = span<int> {ac};
      s.copy_to(sc);
      assert::are_equal(10, sc.at(0));
      assert::are_equal(20, sc.at(1));
      assert::are_equal(30, sc.at(2));
      assert::are_equal(40, sc.at(3));
      assert::are_equal(50, sc.at(4));
      
      assert::are_equal(10, ac[0]);
      assert::are_equal(20, ac[1]);
      assert::are_equal(30, ac[2]);
      assert::are_equal(40, ac[3]);
      assert::are_equal(50, ac[4]);
      
      auto sc2 = span<int, 4> {ac};
      assert::throws<argument_exception>([&] {s.copy_to(sc2);});
    }
    
    auto test_method_(equal_to_operator) {
      auto a1 = array {10, 20, 30, 40, 50};
      auto s1 = span(a1);
      auto s2 = span(a1);
      auto a3 = array {0, 0, 0, 0, 0};
      auto s3 = span<int> {a3};
      assert::is_true(s1 == s2);
      assert::is_false(s1 == s3);
      assert::is_false(s2 == s3);
    }
    
    auto test_method_(not_equal_to_operator) {
      auto a1 = array {10, 20, 30, 40, 50};
      auto s1 = span(a1);
      auto s2 = span(a1);
      auto a3 = array {0, 0, 0, 0, 0};
      auto s3 = span<int> {a3};
      assert::is_false(s1 != s2);
      assert::is_true(s1 != s3);
      assert::is_true(s2 != s3);
    }
    
    auto test_method_(fill) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      s.fill(42);
      assert::are_equal(42, s.at(0));
      assert::are_equal(42, s.at(1));
      assert::are_equal(42, s.at(2));
      assert::are_equal(42, s.at(3));
      assert::are_equal(42, s.at(4));
      
      assert::are_equal(42, a[0]);
      assert::are_equal(42, a[1]);
      assert::are_equal(42, a[2]);
      assert::are_equal(42, a[3]);
      assert::are_equal(42, a[4]);
    }
    
    auto test_method_(first) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.first<3>();
      
      assert::are_equal(a.data(), s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    auto test_method_(first_with_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.first(3);
      
      assert::are_equal(a.data(), s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    auto test_method_(last) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.last<3>();
      
      assert::are_equal(a.data() + 2, s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    auto test_method_(last_with_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.last(3);
      
      assert::are_equal(a.data() + 2, s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    auto test_method_(slice) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.slice<1, 3>();
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice<6, 0>();});
      assert::throws<argument_out_of_range_exception>([&] {s.slice<0, 6>();});
      assert::throws<argument_out_of_range_exception>([&] {s.slice<2, 4>();});
    }
    
    auto test_method_(slice_with_start) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.slice(1);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(4_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6);});
    }
    
    auto test_method_(slice_with_start_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.slice(1, 3);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    auto test_method_(subspan) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.subspan<1, 3>();
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    auto test_method_(subspan_with_offset_and_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto s2 = s.subspan(1, 3);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    auto test_method_(to_array) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      collection_assert::are_equal(a, s.to_array());
    }
    
    auto test_method_(to_string) {
      auto a = array {10, 20, 30, 40, 50};
      auto sa = span(a);
      assert::are_equal("[10, 20, 30, 40, 50]", sa.to_string());
      
      auto s = string {"Hello, World!"};
      auto ss = span<const char>(s);
      assert::are_equal("Hello, World!", ss.to_string());
      
      assert::are_equal("[]", span<int>::empty_span.to_string());
    }
    
    auto test_method_(try_copy_to) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      auto ac = array {0, 0, 0, 0, 0};
      auto sc = span<int> {ac};
      assert::is_true(s.try_copy_to(sc));
      assert::are_equal(10, sc.at(0));
      assert::are_equal(20, sc.at(1));
      assert::are_equal(30, sc.at(2));
      assert::are_equal(40, sc.at(3));
      assert::are_equal(50, sc.at(4));
      
      assert::are_equal(10, ac[0]);
      assert::are_equal(20, ac[1]);
      assert::are_equal(30, ac[2]);
      assert::are_equal(40, ac[3]);
      assert::are_equal(50, ac[4]);
      
      auto sc2 = span<int, 4> {ac};
      assert::is_false(s.try_copy_to(sc2));
    }
    
    auto test_method_(const_index_operator) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = span(a);
      assert::are_equal(10, s[0]);
      assert::are_equal(20, s[1]);
      assert::are_equal(30, s[2]);
      assert::are_equal(40, s[3]);
      assert::are_equal(50, s[4]);
      assert::throws<index_out_of_range_exception>([&] {s[5];});
      assert::throws<index_out_of_range_exception>([] {span<int> {} [0];});
    }
    
    auto test_method_(index_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a);
      assert::are_equal(10, s[0]);
      assert::are_equal(20, s[1]);
      assert::are_equal(30, s[2]);
      assert::are_equal(40, s[3]);
      assert::are_equal(50, s[4]);
      assert::throws<index_out_of_range_exception>([&] {s[5];});
      assert::throws<index_out_of_range_exception>([] {span<int> {} [0];});
    }
  };
}
