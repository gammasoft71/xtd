#include <xtd/span>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(span_tests) {
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
  };
}
