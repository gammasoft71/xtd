#include <xtd/collections/generic/helpers/wrap_pointer_reverse_iterator>
#include <xtd/as_const>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::collections::generic::helpers::tests {
  class test_class_(wrap_pointer_reverse_iterator_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int*>(), typeof_<wrap_pointer_reverse_iterator<int*>::value_type>());
    }
    
    void test_method_(iterator_category) {
      assert::are_equal(typeof_<std::forward_iterator_tag>(), typeof_<wrap_pointer_reverse_iterator<int*>::iterator_category>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<wrap_pointer_reverse_iterator<int*>::difference_type>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int**>(), typeof_<wrap_pointer_reverse_iterator<int*>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<int* const*>(), typeof_<wrap_pointer_reverse_iterator<int*>::const_pointer>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int*&>(), typeof_<wrap_pointer_reverse_iterator<int*>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<int* const&>(), typeof_<wrap_pointer_reverse_iterator<int*>::const_reference>());
    }
    
    void test_method_(constructor_with_pointer) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(a.data() + a.size() - 1, i.data());
    }
    
    void test_method_(data_const) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(a.data() + a.size() - 1, as_const(i.data()));
    }

    void test_method_(data) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      i.data() = as_const(i.data()) - 1;
      assert::are_equal(a.data() + a.size() - 2, as_const(i.data()));
    }

    void test_method_(const_reference_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *as_const(i));
    }

    void test_method_(reference_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *i);
    }

    void test_method_(const_pointer_operator) {
      auto a = array {"a b"_s, "c d"_s, "e f"_s, "g h"_s, "i j"_s};
      auto i = wrap_pointer_reverse_iterator<string*> {a.data() + a.size()};
      auto r = xtd::as_const(i)->split();
      assert::are_equal("i", r[0]);
      assert::are_equal("j", r[1]);
    }
    
    void test_method_(pointer_operator) {
      auto a = array {"a b"_s, "c d"_s, "e f"_s, "g h"_s, "i j"_s};
      auto i = wrap_pointer_reverse_iterator<string*> {a.data() + a.size()};
      auto r = i->split();
      assert::are_equal("i", r[0]);
      assert::are_equal("j", r[1]);
    }

    void test_method_(const_pre_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *i);
      assert::are_equal(*(a.data() + a.size() - 2), *(++xtd::as_const(i)));
      assert::are_equal(*(a.data() + a.size() - 2), *i);
    }
    
    void test_method_(pre_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *i);
      assert::are_equal(*(a.data() + a.size() - 2), *(++i));
      assert::are_equal(*(a.data() + a.size() - 2), *i);
    }
    
    void test_method_(const_post_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *i);
      assert::are_equal(*(a.data() + a.size() - 1), *(xtd::as_const(i)++));
      assert::are_equal(*(a.data() + a.size() - 2), *i);
    }
    
    void test_method_(post_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_reverse_iterator<int*> {a.data() + a.size()};
      assert::are_equal(*(a.data() + a.size() - 1), *i);
      assert::are_equal(*(a.data() + a.size() - 1), *(i++));
      assert::are_equal(*(a.data() + a.size() - 2), *i);
    }
  };
}
