#include <xtd/collections/generic/dictionary>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/println>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(dictionary_tests) {
    void test_method_(key_type) {
      assert::are_equal(typeof_<int>(), typeof_<dictionary<int, string>::key_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_type>(), typeof_<dictionary<int, string>::key_type>());
    }
    
    void test_method_(mapped_type) {
      assert::are_equal(typeof_<string>(), typeof_<dictionary<int, string>::mapped_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::mapped_type>(), typeof_<dictionary<int, string>::mapped_type>());
    }
    
    void test_method_(value_type) {
      assert::are_equal(typeof_<key_value_pair<int, string>>(), typeof_<dictionary<int, string>::value_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<dictionary<int, string>::size_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::size_type>(), typeof_<dictionary<int, string>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<dictionary<int, string>::difference_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::difference_type>(), typeof_<dictionary<int, string>::difference_type>());
    }
    
    void test_method_(hasher) {
      assert::are_equal(typeof_<helpers::hasher<int>>(), typeof_<dictionary<int, string>::hasher>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::hasher>(), typeof_<dictionary<int, string>::hasher>());
    }
    
    void test_method_(equator) {
      assert::are_equal(typeof_<helpers::equator<int>>(), typeof_<dictionary<int, string>::equator>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_equal>(), typeof_<dictionary<int, string>::equator>());
    }
    
    void test_method_(key_equal) {
      assert::are_equal(typeof_<helpers::equator<int>>(), typeof_<dictionary<int, string>::key_equal>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_equal>(), typeof_<dictionary<int, string>::key_equal>());
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<helpers::allocator<std::pair<const int, string>>>(), typeof_<dictionary<int, string>::allocator_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::allocator_type>(), typeof_<dictionary<int, string>::allocator_type>());
    }

    void test_method_(base_value_type) {
      assert::are_equal(typeof_<std::pair<const int, string>>(), typeof_<dictionary<int, string>::base_value_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::value_type>(), typeof_<dictionary<int, string>::base_value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::unordered_map<int, string, helpers::hasher<int>, helpers::equator<int>>>(), typeof_<dictionary<int, string>::base_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<key_value_pair<int, string>&>(), typeof_<dictionary<int, string>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const key_value_pair<int, string>&>(), typeof_<dictionary<int, string>::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<std::allocator_traits<helpers::allocator<std::pair<const int, string>>>::pointer>(), typeof_<dictionary<int, string>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<std::allocator_traits<helpers::allocator<std::pair<const int, string>>>::const_pointer>(), typeof_<dictionary<int, string>::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::iterator>(), typeof_<dictionary<int, string>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::const_iterator>(), typeof_<dictionary<int, string>::const_iterator>());
    }
    
    void test_method_(local_iterator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::local_iterator>(), typeof_<dictionary<int, string>::local_iterator>());
    }
    
    void test_method_(const_local_iterator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::const_local_iterator>(), typeof_<dictionary<int, string>::const_local_iterator>());
    }
    
    void test_method_(node_type) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::node_type>(), typeof_<dictionary<int, string>::node_type>());
    }
    
    void test_method_(insert_return_type) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::insert_return_type>(), typeof_<dictionary<int, string>::insert_return_type>());
    }

    void test_method_(default_constructor) {
      auto items = dictionary<int, string> {};
      //assert::is_zero(items.capacity());
      //assert::is_zero(items.count());
      //collection_assert::is_empty(items);
    }
   };
}
