#include <xtd/collections/generic/list>
#include <xtd/boolean>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(list_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int>(), typeof_<list<int>::value_type>(), csf_);
    }
    
    void test_method_(value_type_bool) {
      assert::are_equal(typeof_<bool>(), typeof_<list<bool>::value_type>(), csf_);
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<int>>(), typeof_<list<int>::base_type>(), csf_);
    }
    
    void test_method_(base_type_bool) {
      assert::are_equal(typeof_<std::vector<byte>>(), typeof_<list<bool>::base_type>(), csf_);
    }

    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<list<int>::size_type>(), csf_);
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<list<int>::difference_type>(), csf_);
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int&>(), typeof_<list<int>::reference>(), csf_);
    }

    void test_method_(const_reference) {
      assert::are_equal(typeof_<const int&>(), typeof_<list<int>::const_reference>(), csf_);
    }

    void test_method_(pointer) {
      assert::are_equal(typeof_<int*>(), typeof_<list<int>::pointer>(), csf_);
    }

    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const int*>(), typeof_<list<int>::const_pointer>(), csf_);
    }

    void test_method_(iterator) {
      assert::are_equal(typeof_<ilist<int>::iterator>(), typeof_<list<int>::iterator>(), csf_);
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<ilist<int>::const_iterator>(), typeof_<list<int>::const_iterator>(), csf_);
    }

    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::reverse_iterator>(), typeof_<list<int>::reverse_iterator>(), csf_);
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<list<int>::base_type::const_reverse_iterator>(), typeof_<list<int>::const_reverse_iterator>(), csf_);
    }

    void test_method_(default_constructor) {
      auto items = list<ustring> {};
      assert::is_zero(items.capacity(), csf_);
      assert::is_zero(items.count(), csf_);
      collection_assert::is_empty(items, csf_);
    }
    
    void test_method_(constructor_with_count) {
      auto items = list<boolean>(3);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({false, false, false}, items, csf_);
    }

    void test_method_(constructor_with_count_and_type) {
      auto items = list<int>(3, 42);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({42, 42, 42}, items, csf_);
    }

    void test_method_(constructor_with_iterators) {
      std::vector v = {84, 42, 21};
      auto items = list<int>(v.begin(), v.end());
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(bt);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_list) {
      list l = {84, 42, 21};
      auto items = list(l);
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
    }

    void test_method_(constructor_with_move_list) {
      list l = {84, 42, 21};
      auto items = list(std::move(l));
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
      collection_assert::is_empty(l, csf_);
    }

    void test_method_(constructor_with_move_base_type) {
      list<int>::base_type bt = {84, 42, 21};
      auto items = list<int>(std::move(bt));
      assert::are_equal(3_z, items.count(), csf_);
      collection_assert::are_equal({84, 42, 21}, items, csf_);
      collection_assert::is_empty(bt, csf_);
    }
    
    void test_method_(const_back) {
      auto items = list {84, 42, 21};
      assert::are_equal(21, items.back(), csf_);
    }
    
    void test_method_(back) {
      auto items = list {84, 42, 21};
      items.back() = 5;
      assert::are_equal(5, items.back(), csf_);
    }
    
    void test_method_(begin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.begin(), csf_);
    }
    
    void test_method_(capaciy) {
      auto items = list {84, 42, 21};
      assert::are_equal(3_z, items.count(), csf_);

      items.capacity(42);
      assert::are_equal(42_z, items.capacity(), csf_);
      assert::are_equal(3_z, items.count(), csf_);
    }

    void test_method_(cbegin) {
      auto items = list {84, 42, 21};
      assert::are_equal(84, *items.cbegin(), csf_);
    }

    void test_method_(cend) {
      auto items = list {84, 42, 21};
      assert::are_equal(0, *items.cend(), csf_);
    }
  };
}
