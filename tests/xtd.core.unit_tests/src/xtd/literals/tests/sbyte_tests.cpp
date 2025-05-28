#include <xtd/literals/sbyte>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(sbyte_tests) {
        void test_method_(_i8_operator_on_long_double) {
          auto v = 42.0_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_unsigned_long_long) {
          auto v = 42_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_unsigned_long_long_with_overflow) {
          assert::throws<xtd::overflow_exception>([] {128_i8;});
        }
        
        void test_method_(_i8_operator_on_char_ptr) {
          auto v = "42"_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_i8;});
        }
        
#if defined(__xtd__cpp_lib_char8_t)
        void test_method_(_i8_operator_on_char8_ptr) {
          auto v = u8"42"_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_i8;});
        }
#endif
        
        void test_method_(_i8_operator_on_char16_ptr) {
          auto v = u"42"_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_i8;});
        }
        
        void test_method_(_i8_operator_on_char32_ptr) {
          auto v = U"42"_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_i8;});
        }
        
        void test_method_(_i8_operator_on_wchar_ptr) {
          auto v = L"42"_i8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_i8, v);
        }
        
        void test_method_(_i8_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_i8;});
        }
        
        void test_method_(_s8_operator_on_long_double) {
          auto v = 42.0_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_unsigned_long_long) {
          auto v = 42_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_unsigned_long_long_with_overflow) {
          assert::throws<xtd::overflow_exception>([] {128_s8;});
        }
        
        void test_method_(_s8_operator_on_char_ptr) {
          auto v = "42"_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_s8;});
        }
        
#if defined(__xtd__cpp_lib_char8_t)
        void test_method_(_s8_operator_on_char8_ptr) {
          auto v = u8"42"_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_s8;});
        }
#endif
        
        void test_method_(_s8_operator_on_char16_ptr) {
          auto v = u"42"_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_s8;});
        }
        
        void test_method_(_s8_operator_on_char32_ptr) {
          auto v = U"42"_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_s8;});
        }
        
        void test_method_(_s8_operator_on_wchar_ptr) {
          auto v = L"42"_s8;
          assert::is_true(is<sbyte>(v));
          assert::are_equal(42_s8, v);
        }
        
        void test_method_(_s8_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_s8;});
        }
      };
    }
  }
}
