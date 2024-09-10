#include <xtd/array>
#include <xtd/as>
#include <xtd/collections/generic/list>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(array_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<array_<int>::value_type>(), csf_);
    }
    
    void test_method_(value_type_of_boolean) {
      assert::are_equal(typeof_<bool>(), typeof_<array_<bool>::value_type>(), csf_);
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<array_<int>::base_type>(), csf_);
    }
    
    void test_method_(base_type_boolean) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<array_<bool>::base_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<array_<int>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<array_<int>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<array_<int>::reference>(), csf_);
    }
    
    void test_method_(reference_of_boolean) {
      assert::are_equal(typeof_<bool&>(), typeof_<array_<bool>::reference>(), csf_);
    }

    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<array_<int>::const_reference>(), csf_);
    }
    
    void test_method_(const_reference_of_boolean) {
      assert::are_equal(typeof_<const bool&>(), typeof_<array_<bool>::const_reference>(), csf_);
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<array_<int>::pointer>(), csf_);
    }
    
    void test_method_(pointer_of_boolean) {
      assert::are_equal(typeof_<bool*>(), typeof_<array_<bool>::pointer>(), csf_);
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<array_<int>::const_pointer>(), csf_);
    }
    
    void test_method_(const_pointer_of_boolean) {
      assert::are_equal(typeof_<const bool*>(), typeof_<array_<bool>::const_pointer>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<array_<int>::iterator>(), csf_);
    }
    
    void test_method_(iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::iterator>(), typeof_<array_<bool>::iterator>(), csf_);
    }

    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<array_<int>::const_iterator>(), csf_);
    }
    
    void test_method_(const_iterator_of_boolean) {
      assert::are_equal(typeof_<ilist<bool>::const_iterator>(), typeof_<array_<bool>::const_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<array_<int>::base_type::reverse_iterator>(), typeof_<array_<int>::reverse_iterator>(), csf_);
    }
    
    void test_method_(reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<array_<bool>::base_type::reverse_iterator>(), typeof_<array_<bool>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<array_<int>::base_type::const_reverse_iterator>(), typeof_<array_<int>::const_reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator_of_boolean) {
      assert::are_equal(typeof_<array_<bool>::base_type::const_reverse_iterator>(), typeof_<array_<bool>::const_reverse_iterator>(), csf_);
    }
    
    void test_method_(default_constructor) {
      collection_assert::is_empty(array_<int> {}, csf_);
    }
    
    void test_method_(default_constructor_of_boolean) {
      collection_assert::is_empty(array_<bool> {}, csf_);
    }
    
    void test_method_(constructor_with_array) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_{array_ {1, 2, 3, 4, 5}}, csf_);
    }

    void test_method_(constructor_with_array_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_{array_ {true, false, false, true, false}}, csf_);
    }

    void test_method_(constructor_with_size) {
      collection_assert::are_equal({0, 0, 0, 0, 0}, array_<int>(5), csf_);
    }

    void test_method_(constructor_with_size_of_booleans) {
      collection_assert::are_equal({false, false, false, false, false}, array_<bool>(5), csf_);
    }

    void test_method_(constructor_with_native_array) {
      int a[] = {1, 2, 3, 4, 5};
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int>(a), csf_);
    }
    
    void test_method_(constructor_with_native_array_of_booleans) {
      bool a[] = {true, false, false, true, false};
      collection_assert::are_equal({true, false, false, true, false}, array_<bool>(a), csf_);
    }
    
    void test_method_(constructor_with_ienumerable) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int> {as<ienumerable<int>>(list {1, 2, 3, 4, 5})}, csf_);
    }
    
    void test_method_(constructor_with_ienumerable_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_<bool> {as<ienumerable<bool>>(list {true, false, false, true, false})}, csf_);
    }

    void test_method_(constructor_with_ilist) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, array_<int> {as<ilist<int>>(list {1, 2, 3, 4, 5})}, csf_);
    }
    
    void test_method_(constructor_with_ilist_of_booleans) {
      collection_assert::are_equal({true, false, false, true, false}, array_<bool> {as<ilist<bool>>(list {true, false, false, true, false})}, csf_);
    }

    void test_method_(rank) {
      assert::are_equal(1_z, array_<int> {}.rank(), csf_);
    }

    void test_method_(rank_of_boolean) {
      assert::are_equal(1_z, array_<bool> {}.rank(), csf_);
    }
  };
}
