#include <xtd/read_only_span>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(read_only_span_tests) {
    void test_method_(element_type) {
      assert::are_equal(typeof_<const int>(), typeof_<read_only_span<const int>::element_type>());
      assert::are_equal(typeof_<int>(), typeof_<read_only_span<int>::element_type>());
    }
    
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<read_only_span<const int>::value_type>());
      assert::are_equal(typeof_<int>(), typeof_<read_only_span<int>::value_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<read_only_span<int>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<ptrdiff>(), typeof_<read_only_span<int>::difference_type>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<read_only_span<const int>::pointer>());
      assert::are_equal(typeof_<const int*>(), typeof_<read_only_span<int>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<read_only_span<const int>::const_pointer>());
      assert::are_equal(typeof_<const int*>(), typeof_<read_only_span<int>::const_pointer>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<read_only_span<const int>::reference>());
      assert::are_equal(typeof_<const int&>(), typeof_<read_only_span<int>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<read_only_span<const int>::const_reference>());
      assert::are_equal(typeof_<const int&>(), typeof_<read_only_span<int>::const_reference>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<wrap_pointer_iterator<const int*>>(), typeof_<read_only_span<const int>::iterator > ());
      assert::are_equal(typeof_<wrap_pointer_iterator<const int*>>(), typeof_<read_only_span<int>::iterator > ());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<const wrap_pointer_iterator<const int*>>(), typeof_<read_only_span<const int>::const_iterator > ());
      assert::are_equal(typeof_<const wrap_pointer_iterator<const int*>>(), typeof_<read_only_span<int>::const_iterator > ());
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<read_only_span<const int>::reverse_iterator>());
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<read_only_span<int>::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<read_only_span<const int>::const_reverse_iterator>());
      assert::are_equal(typeof_<const std::reverse_iterator<wrap_pointer_iterator<const int*>>>(), typeof_<read_only_span<int>::const_reverse_iterator>());
    }
    
    void test_method_(constructor_default) {
      auto s = read_only_span<int>();
      assert::is_null(s.data());
      assert::is_zero(s.size());
      collection_assert::is_empty(s);
    }
    
    void test_method_(constructor_default_with_static_extent) {
      auto s = read_only_span<int, 42>();
      assert::is_null(s.data());
      assert::is_zero(s.size());
      collection_assert::is_empty(s);
    }
    
    void test_method_(constructor_with_const_iterators) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_iterators_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_iterators) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_iterators_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_iterator_and_count) {
      /* Conflict with read_only_span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = read_only_span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.size());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    void test_method_(constructor_with_const_iterator_count_and_static_extent) {
      /* Conflict with read_only_span(collection_t& items, xtd::size count)
       const auto a = array {10, 20, 30, 40, 50};
       auto s = read_only_span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.size());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }
    
    void test_method_(constructor_with_iterator_and_count) {
      /* Conflict with read_only_span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = read_only_span(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(4_z, s.size());
       collection_assert::are_equal({10, 20, 30, 40, 50}, s);
       */
    }
    
    void test_method_(constructor_with_iterator_count_and_static_extent) {
      /* Conflict with read_only_span(collection_t& items, xtd::size count)
       auto a = array {10, 20, 30, 40, 50};
       auto s = read_only_span<int, 3>(a.begin(), 4_z);
       assert::are_equal(a.data(), s.data());
       assert::are_equal(3_z, s.size());
       collection_assert::are_equal({10, 20, 30}, s);
       */
    }
    
    void test_method_(constructor_with_const_native_array) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_native_array_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_native_array) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_native_array_and_static_extent) {
      int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_std_array) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_std_array_and_static_extent) {
      const auto a = std::array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_std_array) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_std_array_and_static_extent) {
      auto a = std::array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_range) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_range_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_range) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_range_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_initializer_list) {
      auto a = {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_initializer_list_and_static_extent) {
      auto a = {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.begin(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_collection) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_collection_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_collection) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_collection_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_collection_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_const_collection_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_collection_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_collection_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_const_collection_start_and_length) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_collection_start_length_and_static_extent) {
      const auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_collection_start_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_collection_start_length_and_static_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_const_pointer_and_size) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(5_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_const_pointer_size_and_static_extent) {
      const int a[] = {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a, 5);
      assert::are_equal(a, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(back) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(50, s.back());
    }
    
    void test_method_(const_begin) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    void test_method_(begin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data(), s.begin().data());
      assert::are_equal(10, *s.begin());
    }
    
    void test_method_(cbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data(), s.cbegin().data());
      assert::are_equal(10, *s.cbegin());
    }
    
    void test_method_(cend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.cend().data());
    }
    
    void test_method_(crbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.crbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    void test_method_(crend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data(), s.crend().base().data());
    }
    
    void test_method_(data) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(10, *s.data());
    }
    
    void test_method_(empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::is_false(s.empty());
      assert::is_true(read_only_span<int> {}.empty());
      assert::is_true(read_only_span<int>::empty_read_only_span.empty());
    }
    
    void test_method_(empty_read_only_span) {
      assert::is_null(read_only_span<int>::empty_read_only_span.data());
      assert::is_zero(read_only_span<int>::empty_read_only_span.size());
    }
    
    void test_method_(const_end) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    void test_method_(end) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.end().data());
    }
    
    void test_method_(front) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(10, s.front());
    }
    
    void test_method_(is_empty) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::is_false(s.is_empty());
      assert::is_true(read_only_span<int> {}.is_empty());
      assert::is_true(read_only_span<int>::empty_read_only_span.is_empty());
    }
    
    void test_method_(const_length) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(5_z, s.length());
    }
    
    void test_method_(const_length_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    void test_method_(length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(5_z, s.length());
    }
    
    void test_method_(length_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(3_z, s.length());
    }
    
    void test_method_(const_rbegin) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.crbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    void test_method_(rbegin) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data() + 5, s.crbegin().base().data());
      assert::are_equal(50, *s.crbegin());
    }
    
    void test_method_(const_rend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(s.data(), s.crend().base().data());
    }
    
    void test_method_(rend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(s.data(), s.crend().base().data());
    }
    
    void test_method_(const_size) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(5_z, s.size());
    }
    
    void test_method_(const_size_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span<int, 3>(a);
      assert::are_equal(3_z, s.size());
    }
    
    void test_method_(size) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(5_z, s.size());
    }
    
    void test_method_(size_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(3_z, s.size());
    }
    
    void test_method_(const_size_bytes) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(20_z, s.size_bytes());
    }
    
    void test_method_(const_size_bytes_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span<int, 3>(a);
      assert::are_equal(12_z, s.size_bytes());
    }
    
    void test_method_(size_bytes) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(20_z, s.size_bytes());
    }
    
    void test_method_(size_bytes_with_static_extend) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span<int, 3>(a);
      assert::are_equal(12_z, s.size_bytes());
    }
    
    void test_method_(const_at) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(10, s.at(0));
      assert::are_equal(20, s.at(1));
      assert::are_equal(30, s.at(2));
      assert::are_equal(40, s.at(3));
      assert::are_equal(50, s.at(4));
      assert::throws<index_out_of_range_exception>([&] {s.at(5);});
      assert::throws<index_out_of_range_exception>([] {read_only_span<int> {}.at(0);});
    }
    
    void test_method_(at) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(10, s.at(0));
      assert::are_equal(20, s.at(1));
      assert::are_equal(30, s.at(2));
      assert::are_equal(40, s.at(3));
      assert::are_equal(50, s.at(4));
      assert::throws<index_out_of_range_exception>([&] {s.at(5);});
      assert::throws<index_out_of_range_exception>([] {read_only_span<int> {}.at(0);});
    }
    
    void test_method_(copy_to) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
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
    
    void test_method_(equal_to_operator) {
      auto a1 = array {10, 20, 30, 40, 50};
      auto s1 = read_only_span(a1);
      auto s2 = read_only_span(a1);
      auto a3 = array {0, 0, 0, 0, 0};
      auto s3 = read_only_span<int> {a3};
      assert::is_true(s1 == s2);
      assert::is_false(s1 == s3);
      assert::is_false(s2 == s3);
    }
    
    void test_method_(not_equal_to_operator) {
      auto a1 = array {10, 20, 30, 40, 50};
      auto s1 = read_only_span(a1);
      auto s2 = read_only_span(a1);
      auto a3 = array {0, 0, 0, 0, 0};
      auto s3 = read_only_span<int> {a3};
      assert::is_false(s1 != s2);
      assert::is_true(s1 != s3);
      assert::is_true(s2 != s3);
    }
    
    void test_method_(first) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.first<3>();
      
      assert::are_equal(a.data(), s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    void test_method_(first_with_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.first(3);
      
      assert::are_equal(a.data(), s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    void test_method_(last) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.last<3>();
      
      assert::are_equal(a.data() + 2, s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    void test_method_(last_with_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.last(3);
      
      assert::are_equal(a.data() + 2, s2.data());
      assert::are_equal(3_z, s2.length());
    }
    
    void test_method_(slice) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.slice<1, 3>();
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice<6, 0>();});
      assert::throws<argument_out_of_range_exception>([&] {s.slice<0, 6>();});
      assert::throws<argument_out_of_range_exception>([&] {s.slice<2, 4>();});
    }
    
    void test_method_(slice_with_start) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.slice(1);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(4_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6);});
    }
    
    void test_method_(slice_with_start_and_length) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.slice(1, 3);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    void test_method_(subspan) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.subspan<1, 3>();
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    void test_method_(subspan_with_offset_and_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      auto s2 = s.subspan(1, 3);
      
      assert::are_equal(a.data() + 1, s2.data());
      assert::are_equal(3_z, s2.length());
      
      assert::throws<argument_out_of_range_exception>([&] {s.slice(6, 0);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(0, 6);});
      assert::throws<argument_out_of_range_exception>([&] {s.slice(2, 4);});
    }
    
    void test_method_(to_array) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      collection_assert::are_equal(a, s.to_array());
    }
    
    void test_method_(to_string) {
      auto a = array {10, 20, 30, 40, 50};
      auto sa = read_only_span(a);
      assert::are_equal("[10, 20, 30, 40, 50]", sa.to_string());
      
      auto s = string {"Hello, World!"};
      auto ss = read_only_span(s);
      assert::are_equal("Hello, World!", ss.to_string());
      
      assert::are_equal("[]", read_only_span<int>::empty_read_only_span.to_string());
    }
    
    void test_method_(try_copy_to) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
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
    
    void test_method_(const_index_operator) {
      auto a = array {10, 20, 30, 40, 50};
      const auto s = read_only_span(a);
      assert::are_equal(10, s[0]);
      assert::are_equal(20, s[1]);
      assert::are_equal(30, s[2]);
      assert::are_equal(40, s[3]);
      assert::are_equal(50, s[4]);
      assert::throws<index_out_of_range_exception>([&] {s[5];});
      assert::throws<index_out_of_range_exception>([] {read_only_span<int> {} [0];});
    }
    
    void test_method_(index_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = read_only_span(a);
      assert::are_equal(10, s[0]);
      assert::are_equal(20, s[1]);
      assert::are_equal(30, s[2]);
      assert::are_equal(40, s[3]);
      assert::are_equal(50, s[4]);
      assert::throws<index_out_of_range_exception>([&] {s[5];});
      assert::throws<index_out_of_range_exception>([] {read_only_span<int> {} [0];});
    }
  };
}
