#include <xtd/random>
#include <xtd/collections/generic/list>
#include <xtd/as_const>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(random_tests) {
    void test_method_(default_constructor) {
      assert::are_equal(std::default_random_engine {static_cast<uint32>(environment::tick_count().count())}, xtd::random {}.generator());
    }

    void test_method_(constructor_with_seed) {
      assert::are_equal(std::default_random_engine {1}, xtd::random {0}.generator());
      assert::are_equal(std::default_random_engine {2}, xtd::random {1}.generator());
      assert::are_equal(std::default_random_engine {11}, xtd::random {10}.generator());
    }

    void test_method_(constructor_with_device) {
      // to be defined...
    }
    
    void test_method_(copy_constructor) {
      assert::are_equal(std::default_random_engine {43}, xtd::random {xtd::random {42}}.generator());
    }
    
    void test_method_(copy_operator) {
      auto rnd = xtd::random {};
      rnd = xtd::random {42};
      assert::are_equal(std::default_random_engine {43}, rnd.generator());
    }
    
    void test_method_(generator) {
      assert::are_equal(std::default_random_engine {1}, xtd::random {0}.generator());
    }
    
    void test_method_(const_generator) {
      auto rnd = xtd::random {0};
      assert::are_equal(std::default_random_engine {1}, as_const(rnd).generator());
    }
    
    void test_method_(get_items_boolean_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<boolean>(array<boolean> {false, true}, 16);
      assert::are_equal(16_z, items.length());
      if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
    }
    
    void test_method_(get_items_boolean_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<boolean>(read_only_span<boolean> {false, true}, 16);
      assert::are_equal(16_z, items.length());
      if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
    }
    
    void test_method_(get_items_boolean_with_choices_read_only_span_and_destination) {
      auto items_list = list<boolean>(16);
      auto items = span<boolean>(items_list);
      xtd::random {1}.get_items<boolean>(read_only_span<boolean> {false, true}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
    }
    
    void test_method_(get_items_int_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<int>(array<int> {0, 1, 2, 3}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
    }
    
    void test_method_(get_items_int_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<int>(read_only_span<int> {0, 1, 2, 3}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
    }
    
    void test_method_(get_items_int_with_choices_read_only_span_and_destination) {
      auto items_list = list<int>(16);
      auto items = span<int>(items_list);
      xtd::random {1}.get_items<int>(read_only_span<int> {0, 1, 2, 3}, items);
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
    }
    
    void test_method_(get_items_double_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<double>(array<double> {0.3, 0.5, 0.8}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
    }
    
    void test_method_(get_items_double_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<double>(read_only_span<double> {0.3, 0.5, 0.8}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
    }
    
    void test_method_(get_items_double_with_choices_read_only_span_and_destination) {
      auto items_list = list<double>(16);
      auto items = span<double>(items_list);
      xtd::random {1}.get_items<double>(read_only_span<double> {0.3, 0.5, 0.8}, items);
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
    }
  };
}
