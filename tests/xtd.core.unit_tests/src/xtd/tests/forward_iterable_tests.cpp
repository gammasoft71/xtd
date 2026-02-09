#include <xtd/forward_iterable>
#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  class test_class_(forward_iterable_tests) {
    template<class value_t>
    requires forward_iterable<value_t>
    auto is_forward_iterable(value_t&& value) -> bool {return true;}
    template<class value_t>
    requires (!forward_iterable<value_t>)
    auto is_forward_iterable(value_t&& value) -> bool {return false;}
    
    auto test_method_(with_string_literal) {
      assert_that(is_forward_iterable("str")).is().true_();
    }
    
    auto test_method_(with_object) {
      assert_that(is_forward_iterable(object {})).is().false_();
    }
    
    auto test_method_(with_string) {
      assert_that(is_forward_iterable("str"_s)).is().true_();
    }
    
    auto test_method_(with_std_vector) {
      assert_that(is_forward_iterable(std::vector<int> {})).is().true_();
    }
    
    auto test_method_(with_list) {
      assert_that(is_forward_iterable(list<int> {})).is().true_();
    }
  };
}
