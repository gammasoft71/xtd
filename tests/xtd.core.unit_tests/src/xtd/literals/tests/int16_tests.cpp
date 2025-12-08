#include <xtd/literals/int16>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(int16_tests) {
        auto test_method_(_i16_operator_on_long_double) {
          auto v = 42.0_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_unsigned_long_long) {
          auto v = 42_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_unsigned_long_long_with_overflow) {
          assert::throws<xtd::overflow_exception>([] {32768_i8;});
        }
        
        auto test_method_(_i16_operator_on_char_ptr) {
          auto v = "42"_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_i16;});
        }
        
        auto test_method_(_i16_operator_on_char8_ptr) {
          auto v = u8"42"_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_i16;});
        }
        
        auto test_method_(_i16_operator_on_char16_ptr) {
          auto v = u"42"_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_i16;});
        }
        
        auto test_method_(_i16_operator_on_char32_ptr) {
          auto v = U"42"_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_i16;});
        }
        
        auto test_method_(_i16_operator_on_wchar_ptr) {
          auto v = L"42"_i16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_i16, v);
        }
        
        auto test_method_(_i16_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_i16;});
        }
        
        auto test_method_(_s16_operator_on_long_double) {
          auto v = 42.0_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_unsigned_long_long) {
          auto v = 42_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_unsigned_long_long_with_overflow) {
          assert::throws<xtd::overflow_exception>([] {32768_s16;});
        }
        
        auto test_method_(_s16_operator_on_char_ptr) {
          auto v = "42"_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_s16;});
        }
        
        auto test_method_(_s16_operator_on_char8_ptr) {
          auto v = u8"42"_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_s16;});
        }
        
        auto test_method_(_s16_operator_on_char16_ptr) {
          auto v = u"42"_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_s16;});
        }
        
        auto test_method_(_s16_operator_on_char32_ptr) {
          auto v = U"42"_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_s16;});
        }
        
        auto test_method_(_s16_operator_on_wchar_ptr) {
          auto v = L"42"_s16;
          assert::is_true(is<int16>(v));
          assert::are_equal(42_s16, v);
        }
        
        auto test_method_(_s16_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_s16;});
        }
      };
    }
  }
}
