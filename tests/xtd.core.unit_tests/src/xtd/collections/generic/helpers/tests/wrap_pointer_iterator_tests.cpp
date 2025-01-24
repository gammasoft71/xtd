#include <xtd/collections/generic/helpers/wrap_pointer_iterator>
#include <xtd/as_const.hpp>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic::helpers;
using namespace xtd::tunit;

namespace xtd::collections::generic::helpers::tests {
  class test_class_(wrap_pointer_iterator_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<int*>(), typeof_<wrap_pointer_iterator<int*>::value_type>());
    }
    
    void test_method_(iterator_category) {
      assert::are_equal(typeof_<std::forward_iterator_tag>(), typeof_<wrap_pointer_iterator<int*>::iterator_category>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<wrap_pointer_iterator<int*>::difference_type>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<int**>(), typeof_<wrap_pointer_iterator<int*>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<int* const*>(), typeof_<wrap_pointer_iterator<int*>::const_pointer>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<int*&>(), typeof_<wrap_pointer_iterator<int*>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<int* const&>(), typeof_<wrap_pointer_iterator<int*>::const_reference>());
    }

    void test_method_(constructor_with_pointer) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(a.data(), i.data());
    }

    void test_method_(data_const) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(a.data(), xtd::as_const(i.data()));
    }

    void test_method_(data) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      i.data() = xtd::as_const(i.data()) + 1;
      assert::are_equal(a.data() + 1, xtd::as_const(i.data()));
    }

    void test_method_(const_reference_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *xtd::as_const(i));
    }

    void test_method_(reference_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
    }

    void test_method_(const_pointer_operator) {
      auto a = array {"a b"_s, "c d"_s, "e f"_s, "g h"_s, "i j"_s};
      auto i = wrap_pointer_iterator<string*> {a.data()};
      auto r = xtd::as_const(i)->split();
      assert::are_equal("a", r[0]);
      assert::are_equal("b", r[1]);
    }

    void test_method_(pointer_operator) {
      auto a = array {"a b"_s, "c d"_s, "e f"_s, "g h"_s, "i j"_s};
      auto i = wrap_pointer_iterator<string*> {a.data()};
      auto r = i->split();
      assert::are_equal("a", r[0]);
      assert::are_equal("b", r[1]);
    }

    void test_method_(const_pre_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
      assert::are_equal(*(a.data() + 1), *(++xtd::as_const(i)));
      assert::are_equal(*(a.data() + 1), *i);
    }

    void test_method_(pre_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
      assert::are_equal(*(a.data() + 1), *(++i));
      assert::are_equal(*(a.data() + 1), *i);
    }

    void test_method_(const_post_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
      assert::are_equal(*(a.data()), *(xtd::as_const(i)++));
      assert::are_equal(*(a.data() + 1), *i);
    }

    void test_method_(post_increment_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
      assert::are_equal(*(a.data()), *(i++));
      assert::are_equal(*(a.data() + 1), *i);
    }

    void test_method_(add_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i = wrap_pointer_iterator<int*> {a.data()};
      assert::are_equal(*a.data(), *i);
      i = i + 2;
      assert::are_equal(*(a.data() + 2), *i);
    }
    
    void test_method_(minus_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i1 = wrap_pointer_iterator<int*> {a.data()};
      auto i2 = wrap_pointer_iterator<int*> {a.data() + 3};
      assert::are_equal(3, i2 - i1);
    }
    
    void test_method_(equal_to_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i1 = wrap_pointer_iterator<int*> {a.data()};
      auto i2 = wrap_pointer_iterator<int*> {a.data()};
      auto i3 = wrap_pointer_iterator<int*> {a.data() + 3};
      assert::is_true(i1 == i2);
      assert::is_false(i1 == i3);
      assert::is_false(i2 == i3);
    }
    
    void test_method_(not_equal_to_operator) {
      auto a = array {10, 20, 30, 40, 50};
      auto i1 = wrap_pointer_iterator<int*> {a.data()};
      auto i2 = wrap_pointer_iterator<int*> {a.data()};
      auto i3 = wrap_pointer_iterator<int*> {a.data() + 3};
      assert::is_false(i1 != i2);
      assert::is_true(i1 != i3);
      assert::is_true(i2 != i3);
    }
  };
}
