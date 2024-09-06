#include <xtd/collections/generic/params>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(params_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<params<int>::value_type>(), csf_);
    }
    
    void test_method_(value_type_bool) {
      assert::are_equal(typeof_<bool>(), typeof_<params<bool>::value_type>(), csf_);
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::initializer_list<int>>(), typeof_<params<int>::base_type>(), csf_);
    }
    
    void test_method_(base_type_bool) {
      assert::are_equal(typeof_<std::initializer_list<bool>>(), typeof_<params<bool>::base_type>(), csf_);
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<params<int>::size_type>(), csf_);
      assert::are_equal(typeof_<std::initializer_list<int>::size_type>(), typeof_<params<int>::size_type>(), csf_);
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<params<int>::reference>(), csf_);
      assert::are_equal(typeof_<std::initializer_list<int>::reference>(), typeof_<params<int>::reference>(), csf_);
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<params<int>::const_reference>(), csf_);
      assert::are_equal(typeof_<std::initializer_list<int>::const_reference>(), typeof_<params<int>::const_reference>(), csf_);
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<const int*>(), typeof_<params<int>::iterator>(), csf_);
      assert::are_equal(typeof_<std::initializer_list<int>::iterator>(), typeof_<params<int>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<const int*>(), typeof_<params<int>::const_iterator>(), csf_);
      assert::are_equal(typeof_<std::initializer_list<int>::const_iterator>(), typeof_<params<int>::const_iterator>(), csf_);
    }

    void test_method_(default_constructor) {
      collection_assert::are_equal(std::initializer_list<string> {}, params<string> {}, csf_);
    }

    void test_method_(constructor) {
      collection_assert::are_equal({1, 2, 3, 4, 5}, params {1, 2, 3, 4, 5}, csf_);
    }

    void test_method_(size) {
      assert::is_zero(params<int> {}.size(), csf_);
      assert::are_equal(5_z, params {1, 2, 3, 4, 5}.size(), csf_);
    }
  };
}
