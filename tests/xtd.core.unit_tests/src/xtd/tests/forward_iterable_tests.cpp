#include <xtd/forward_iterable>
#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  class test_class_(forward_iterable_tests) {
    template<typename value_t>
    requires forward_iterable<value_t>
    [[nodiscard]] static auto is_forward_iterable(value_t&& value) noexcept -> bool {return true;}
    
    template<typename value_t>
    requires (!forward_iterable<value_t>)
    [[nodiscard]] static auto is_forward_iterable(value_t&& value) noexcept -> bool {return false;}
    
    auto test_method_(with_string_literal) {
      assert_that(is_forward_iterable("str")).is().true_();
    }
    
    auto test_method_(with_object) {
      assert_that(is_forward_iterable(object {})).is().false_();
    }
    
    auto test_method_(with_string) {
      assert_that(is_forward_iterable("str"_s)).is().true_();
    }
    
    auto test_method_(with_version) {
      assert_that(is_forward_iterable("1.2.3"_vers)).is().false_();
    }

    auto test_method_(with_std_vector) {
      assert_that(is_forward_iterable(std::vector<int> {})).is().true_();
    }
    
    auto test_method_(with_list) {
      assert_that(is_forward_iterable(list<int> {})).is().true_();
    }
    
    auto test_method_(with_my_not_forward_iterable) {
      struct my_not_forward_iterable {};
      
      assert_that(is_forward_iterable(my_not_forward_iterable {})).is().false_();
    }
    
    auto test_method_(with_my_forward_iterable) {
      struct my_forward_iterable {
        auto begin() const {return items.begin();}
        auto end() const {return items.end();}
        std::vector<int> items;
      };
      
      assert_that(is_forward_iterable(my_forward_iterable {})).is().true_();
    }
    
    auto test_method_(with_my_broken_end_forward_iterable) {
      struct my_broken_end_forward_iterable {
        auto begin() const {return items.begin();}
        std::vector<int> items;
      };
      
      assert_that(is_forward_iterable(my_broken_end_forward_iterable {})).is().false_();
    }
    
    auto test_method_(with_my_broken_begin_forward_iterable) {
      struct my_broken_begin_forward_iterable {
        auto end() const {return items.end();}
        std::vector<int> items;
      };
      
      assert_that(is_forward_iterable(my_broken_begin_forward_iterable {})).is().false_();
    }
  };
}
