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
    
    void test_method_(constructor_default_with_extent) {
      auto s = span<int, 42>();
      assert::is_null(s.data());
      assert::is_zero(s.size());
      collection_assert::is_empty(s);
    }
    
    void test_method_(constructor_with_iterators) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a.begin(), a.end());
      assert::are_equal(a.data(), s.data());
      assert::are_equal(a.size(), s.size());
      collection_assert::are_equal({10, 20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_iterators_and_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a.begin(), a.end());
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
    
    void test_method_(constructor_with_collection_and_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_collection_and_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({10, 20, 30, 40}, s);
    }
    
    void test_method_(constructor_with_collection_count_and_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 4_z);
      assert::are_equal(a.data(), s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({10, 20, 30}, s);
    }
    
    void test_method_(constructor_with_collection_offset_and_count) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(4_z, s.size());
      collection_assert::are_equal({20, 30, 40, 50}, s);
    }
    
    void test_method_(constructor_with_collection_offset_count_and_extent) {
      auto a = array {10, 20, 30, 40, 50};
      auto s = span<int, 3>(a, 1_z, 4_z);
      assert::are_equal(a.data() + 1, s.data());
      assert::are_equal(3_z, s.size());
      collection_assert::are_equal({20, 30, 40}, s);
    }
  };
}
