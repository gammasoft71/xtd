#include <xtd/stream_insertable>
#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  class test_class_(stream_insertable_tests) {
    template<class value_t>
    requires stream_insertable<value_t>
    auto is_stream_insertable(value_t&& value) -> bool {return true;}
    template<class value_t>
    requires (!stream_insertable<value_t>)
    auto is_stream_insertable(value_t&& value) -> bool {return false;}
    
    struct my_stream_insertable {
      friend auto operator <<(std::ostream& os, const my_stream_insertable&) -> std::ostream& {return os << "my_stream_insertable";}
    };

    struct my_stringable : public istringable<my_stringable> {
      auto to_string() const -> string override {return "my_stringable";}
    };
    
    struct my_stream_not_insertable {
    };
    
    auto test_method_(with_string_literal) {
      assert_that(is_stream_insertable("str")).is().true_();
    }
    
    auto test_method_(with_object) {
      assert_that(is_stream_insertable(object {})).is().false_();
    }
    
    auto test_method_(with_string) {
      assert_that(is_stream_insertable("str"_s)).is().true_();
    }
    
    auto test_method_(with_version) {
      assert_that(is_stream_insertable("1.2.3"_vers)).is().false_();
    }
    
    auto test_method_(with_my_stream_insertable) {
      assert_that(is_stream_insertable(my_stream_insertable {})).is().true_();
    }
    
    auto test_method_(with_my_stream_not_insertable) {
      assert_that(is_stream_insertable(my_stream_not_insertable {})).is().false_();
    }
    
    auto test_method_(with_my_stringable) {
      assert_that(is_stream_insertable(my_stringable {})).is().true_();
    }

    auto test_method_(with_bool) {
      assert_that(is_stream_insertable(true)).is().true_();
      assert_that(is_stream_insertable(false)).is().true_();
    }
    
    auto test_method_(with_integrals) {
      assert_that(is_stream_insertable(42_s8)).is().true_();
      assert_that(is_stream_insertable(42_s16)).is().true_();
      assert_that(is_stream_insertable(42_s32)).is().true_();
      assert_that(is_stream_insertable(42_s64)).is().true_();

      assert_that(is_stream_insertable(42_u8)).is().true_();
      assert_that(is_stream_insertable(42_u16)).is().true_();
      assert_that(is_stream_insertable(42_u32)).is().true_();
      assert_that(is_stream_insertable(42_u64)).is().true_();
    }
  };
}
