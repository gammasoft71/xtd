#include <xtd/not_implemented_exception>
#include <xtd/string_comparer>
#include <xtd/time_span>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_comparer_tests) {
    auto test_method_(string_comparer_current_culture) {
      assert::throws<not_implemented_exception>([] {string_comparer::current_culture();});
      //assert::are_not_same(string_comparer::current_culture(), string_comparer::current_culture());
    }
    
    auto test_method_(string_comparer_current_culture_ignore_case) {
      assert::throws<not_implemented_exception>([] {string_comparer::current_culture_ignore_case();});
      //assert::are_not_same(string_comparer::current_culture_ignore_case(), string_comparer::current_culture_ignore_case());
    }
    
    auto test_method_(invariant_culture) {
      assert::throws<not_implemented_exception>([] {string_comparer::invariant_culture();});
      //assert::are_not_same(string_comparer::invariant_culture(), string_comparer::invariant_culture());
    }
    
    auto test_method_(invariant_culture_ignore_case) {
      assert::throws<not_implemented_exception>([] {string_comparer::invariant_culture_ignore_case();});
      //assert::are_not_same(string_comparer::invariant_culture_ignore_case(), string_comparer::invariant_culture_ignore_case());
    }
    
    auto test_method_(ordinal) {
      assert::are_same(string_comparer::ordinal(), string_comparer::ordinal());
    }
    
    auto test_method_(ordinal_ignore_case) {
      assert::are_same(string_comparer::ordinal_ignore_case(), string_comparer::ordinal_ignore_case());
    }
    
    auto test_method_(string_comparer_ordinal_compare_with_strings) {
      assert::is_zero(string_comparer::ordinal().compare(string {""}, string {""}));
      auto s = string {"abc"};
      assert::is_zero(string_comparer::ordinal().compare(s, s));
      assert::is_zero(string_comparer::ordinal().compare(string {"abc"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare(string {"abc"}, string {"ABC"}));
      assert::is_zero(string_comparer::ordinal().compare(string {"ABC"}, string {"ABC"}));
      assert::is_negative(string_comparer::ordinal().compare(string {"ABC"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare(string {"bca"}, string {"abc"}));
      assert::is_negative(string_comparer::ordinal().compare(string {"abc"}, string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_compare_with_const_char_ponters) {
      assert::is_zero(string_comparer::ordinal().compare("", ""));
      auto s = "abc";
      assert::is_zero(string_comparer::ordinal().compare(s, s));
      assert::is_zero(string_comparer::ordinal().compare("abc", "abc"));
      assert::is_positive(string_comparer::ordinal().compare("abc", "ABC"));
      assert::is_zero(string_comparer::ordinal().compare("ABC", "ABC"));
      assert::is_negative(string_comparer::ordinal().compare("ABC", "abc"));
      assert::is_positive(string_comparer::ordinal().compare("bca", "abc"));
      assert::is_negative(string_comparer::ordinal().compare("abc", "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_compare_with_string_and_const_char_ponter) {
      assert::is_zero(string_comparer::ordinal().compare(string {""}, ""));
      assert::is_zero(string_comparer::ordinal().compare(string {"abc"}, "abc"));
      assert::is_positive(string_comparer::ordinal().compare(string {"abc"}, "ABC"));
      assert::is_zero(string_comparer::ordinal().compare(string {"ABC"}, "ABC"));
      assert::is_negative(string_comparer::ordinal().compare(string {"ABC"}, "abc"));
      assert::is_positive(string_comparer::ordinal().compare(string {"bca"}, "abc"));
      assert::is_negative(string_comparer::ordinal().compare(string {"abc"}, "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_compare_with_const_char_ponter_and_string) {
      assert::is_zero(string_comparer::ordinal().compare("", string {""}));
      assert::is_zero(string_comparer::ordinal().compare("abc", string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare("abc", string {"ABC"}));
      assert::is_zero(string_comparer::ordinal().compare("ABC", string {"ABC"}));
      assert::is_negative(string_comparer::ordinal().compare("ABC", string {"abc"}));
      assert::is_positive(string_comparer::ordinal().compare("bca", string {"abc"}));
      assert::is_negative(string_comparer::ordinal().compare("abc", string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_compare_with_time_span) {
      assert::is_zero(string_comparer::ordinal().compare(time_span {}, time_span {}));
      assert::is_positive(string_comparer::ordinal().compare(time_span {42}, time_span {21}));
      assert::is_negative(string_comparer::ordinal().compare(time_span {21}, time_span {42}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_compare_with_strings) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {""}, string {""}));
      auto s = string {"abc"};
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(s, s));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"abc"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"ABC"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"ABC"}, string {"ABC"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"ABC"}, string {"abc"}));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare(string {"bca"}, string {"abc"}));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare(string {"abc"}, string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_compare_with_const_char_ponters) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("", ""));
      auto s = "abc";
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(s, s));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("abc", "abc"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("abc", "ABC"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("ABC", "ABC"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("ABC", "abc"));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare("bca", "abc"));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare("abc", "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_compare_with_string_and_const_char_ponter) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {""}, ""));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, "abc"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"abc"}, "ABC"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"ABC"}, "ABC"));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(string {"ABC"}, "abc"));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare(string {"bca"}, "abc"));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare(string {"abc"}, "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_compare_with_const_char_ponter_and_string) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("", string {""}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("abc", string {"abc"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("abc", string {"ABC"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("ABC", string {"ABC"}));
      assert::is_zero(string_comparer::ordinal_ignore_case().compare("ABC", string {"abc"}));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare("bca", string {"abc"}));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare("abc", string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_compare_with_time_span) {
      assert::is_zero(string_comparer::ordinal_ignore_case().compare(time_span {}, time_span {}));
      assert::is_positive(string_comparer::ordinal_ignore_case().compare(time_span {42}, time_span {21}));
      assert::is_negative(string_comparer::ordinal_ignore_case().compare(time_span {21}, time_span {42}));
    }
    
    auto test_method_(string_comparer_ordinal_equals_with_strings) {
      assert::is_true(string_comparer::ordinal().equals(string {""}, string {""}));
      auto s = string {"abc"};
      assert::is_true(string_comparer::ordinal().equals(s, s));
      assert::is_true(string_comparer::ordinal().equals(string {"abc"}, string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals(string {"abc"}, string {"ABC"}));
      assert::is_true(string_comparer::ordinal().equals(string {"ABC"}, string {"ABC"}));
      assert::is_false(string_comparer::ordinal().equals(string {"ABC"}, string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals(string {"bca"}, string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals(string {"abc"}, string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_equals_with_const_char_pointers) {
      assert::is_true(string_comparer::ordinal().equals("", ""));
      auto s = "abc";
      assert::is_true(string_comparer::ordinal().equals(s, s));
      assert::is_true(string_comparer::ordinal().equals("abc", "abc"));
      assert::is_false(string_comparer::ordinal().equals("abc", "ABC"));
      assert::is_true(string_comparer::ordinal().equals("ABC", "ABC"));
      assert::is_false(string_comparer::ordinal().equals("ABC", "abc"));
      assert::is_false(string_comparer::ordinal().equals("bca", "abc"));
      assert::is_false(string_comparer::ordinal().equals("abc", "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_equals_withstring_and_const_char_pointer) {
      assert::is_true(string_comparer::ordinal().equals(string {""}, ""));
      assert::is_true(string_comparer::ordinal().equals(string {"abc"}, "abc"));
      assert::is_false(string_comparer::ordinal().equals(string {"abc"}, "ABC"));
      assert::is_true(string_comparer::ordinal().equals(string {"ABC"}, "ABC"));
      assert::is_false(string_comparer::ordinal().equals(string {"ABC"}, "abc"));
      assert::is_false(string_comparer::ordinal().equals(string {"bca"}, "abc"));
      assert::is_false(string_comparer::ordinal().equals(string {"abc"}, "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_equals_with_const_char_pointer_and_string) {
      assert::is_true(string_comparer::ordinal().equals("", string {""}));
      assert::is_true(string_comparer::ordinal().equals("abc", string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals("abc", string {"ABC"}));
      assert::is_true(string_comparer::ordinal().equals("ABC", string {"ABC"}));
      assert::is_false(string_comparer::ordinal().equals("ABC", string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals("bca", string {"abc"}));
      assert::is_false(string_comparer::ordinal().equals("abc", string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_equals_with_time_span) {
      assert::is_true(string_comparer::ordinal().equals(time_span {}, time_span {}));
      assert::is_false(string_comparer::ordinal().equals(time_span {42}, time_span {21}));
      assert::is_false(string_comparer::ordinal().equals(time_span {21}, time_span {42}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_equals_with_strings) {
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {""}, string {""}));
      auto s = string {"abc"};
      assert::is_true(string_comparer::ordinal_ignore_case().equals(s, s));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"abc"}, string {"abc"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"abc"}, string {"ABC"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"ABC"}, string {"ABC"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"ABC"}, string {"abc"}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(string {"bca"}, string {"abc"}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(string {"abc"}, string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_equals_with_const_char_pointers) {
      assert::is_true(string_comparer::ordinal_ignore_case().equals("", ""));
      auto s = "abc";
      assert::is_true(string_comparer::ordinal_ignore_case().equals(s, s));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("abc", "abc"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("abc", "ABC"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("ABC", "ABC"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("ABC", "abc"));
      assert::is_false(string_comparer::ordinal_ignore_case().equals("bca", "abc"));
      assert::is_false(string_comparer::ordinal_ignore_case().equals("abc", "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_equals_with_string_const_char_pointer) {
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {""}, ""));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"abc"}, "abc"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"abc"}, "ABC"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"ABC"}, "ABC"));
      assert::is_true(string_comparer::ordinal_ignore_case().equals(string {"ABC"}, "abc"));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(string {"bca"}, "abc"));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(string {"abc"}, "bca"));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_equals_with_const_char_pointer_and_string) {
      assert::is_true(string_comparer::ordinal_ignore_case().equals("", string {""}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("abc", string {"abc"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("abc", string {"ABC"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("ABC", string {"ABC"}));
      assert::is_true(string_comparer::ordinal_ignore_case().equals("ABC", string {"abc"}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals("bca", string {"abc"}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals("abc", string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_equals_with_time_span) {
      assert::is_true(string_comparer::ordinal_ignore_case().equals(time_span {}, time_span {}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(time_span {42}, time_span {21}));
      assert::is_false(string_comparer::ordinal_ignore_case().equals(time_span {21}, time_span {42}));
    }
    
    auto test_method_(string_comparer_ordinal_get_hash_code_with_strings) {
      assert::are_equal(string {""}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {""}));
      assert::are_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"abc"}));
      assert::are_not_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"ABC"}));
      assert::are_equal(string {"ABC"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"ABC"}));
      assert::are_not_equal(string {"ABC"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"abc"}));
      assert::are_not_equal(string {"bca"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"abc"}));
      assert::are_not_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal().get_hash_code(string {"bca"}));
    }
    
    auto test_method_(string_comparer_ordinal_ignore_case_get_hash_code_with_strings) {
      assert::are_equal(string {""}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {""}));
      assert::are_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"abc"}));
      assert::are_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"ABC"}));
      assert::are_not_equal(string {"ABC"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"ABC"}));
      assert::are_not_equal(string {"ABC"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"abc"}));
      assert::are_not_equal(string {"bca"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"abc"}));
      assert::are_not_equal(string {"abc"}.get_hash_code(), string_comparer::ordinal_ignore_case().get_hash_code(string {"bca"}));
    }
    
    auto test_method_(from_comparison) {
      assert::are_equal(string_comparer::ordinal(), string_comparer::from_comparison(string_comparison::ordinal));
      assert::are_equal(string_comparer::ordinal_ignore_case(), string_comparer::from_comparison(string_comparison::ordinal_ignore_case));
      assert::throws<argument_exception>([] {string_comparer::from_comparison(static_cast<string_comparison>(42));});
    }
  };
}
