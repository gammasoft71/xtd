#include <exception>
#include <xtd/convert>
#include <xtd/overflow_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(convert_tests) {
    enum class values {
      zero,
      one,
      two
    };
    
    void test_method_(to_any_from_any) {
      std::any value = 42;
      assert::are_equal(42, std::any_cast<int>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_bool) {
      bool value = true;
      assert::is_true(std::any_cast<bool>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42u, std::any_cast<xtd::byte>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_char) {
      char value = 'a';
      assert::are_equal('a', std::any_cast<char>(convert::to_any(value)));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_any_from_char8) {
      char8 value = u8'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_any(value);});
    }
#endif
    
    void test_method_(to_any_from_char16) {
      char16 value = u'a';
      assert::are_equal(u'a', std::any_cast<char16>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_char32) {
      char32 value = U'a';
      assert::are_equal(U'a', std::any_cast<char32>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_wchar) {
      wchar value = L'a';
      assert::are_equal(L'a', std::any_cast<wchar>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42.0l, std::any_cast<decimal>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_double) {
      double value = 42.0;
      assert::are_equal(42.0, std::any_cast<double>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0f, std::any_cast<float>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_int16) {
      int16 value = 42;
      assert::are_equal(42, std::any_cast<int16>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_int32) {
      int32 value = 42;
      assert::are_equal(42, std::any_cast<int32>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_int64) {
      int64 value = 42l;
      assert::are_equal(42l, std::any_cast<int64>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_llong) {
      slong value = 42ll;
      assert::are_equal(42ll, std::any_cast<slong>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42, std::any_cast<sbyte>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42u, std::any_cast<uint16>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42u, std::any_cast<uint32>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42lu, std::any_cast<uint64>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42llu, std::any_cast<xtd::ulong>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_string) {
      string value = "42";
      assert::are_equal("42", std::any_cast<string>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_std_string) {
      std::string value = "42";
      assert::are_equal("42", std::any_cast<std::string>(convert::to_any(value)));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_any_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(u8"42", std::any_cast<std::u8string>(convert::to_any(value)));
    }
#endif
    
    void test_method_(to_any_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(u"42", std::any_cast<std::u16string>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(U"42", std::any_cast<std::u32string>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(L"42", std::any_cast<std::wstring>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_literal_char) {
      const char* value = "42";
      assert::are_equal("42", std::any_cast<const char*>(convert::to_any(value)));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_any_from_literal_char8) {
      const char8* value = u8"42";
      assert::throws<invalid_cast_exception>([&] {convert::to_any(value);});
    }
#endif
    
    void test_method_(to_any_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(u"42", std::any_cast<const char16*>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(U"42", std::any_cast<const char32*>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(L"42", std::any_cast<const wchar*>(convert::to_any(value)));
    }
    
    void test_method_(to_any_from_values) {
      values value = values::two;
      assert::are_equal(values::two, std::any_cast<values>(convert::to_any(value)));
    }
    
    void test_method_(to_boolean_from_any) {
      std::any value = true;
      assert::is_true(convert::to_boolean(value));
      value = false;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_any_failed) {
      std::any value = "not a bool";
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_bool) {
      bool value = true;
      assert::is_true(convert::to_boolean(value));
      value = false;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_byte) {
      xtd::byte value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_char) {
      char value = 'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_boolean_from_char8) {
      char8 value = u8'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
#endif
    
    void test_method_(to_boolean_from_char16) {
      char16 value = u'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_char32) {
      char32 value = U'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_wchar) {
      wchar value = L'a';
      assert::throws<invalid_cast_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_decimal) {
      decimal value = 0.42l;
      assert::is_true(convert::to_boolean(value));
      value = 0.0l;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_double) {
      double value = 0.42;
      assert::is_true(convert::to_boolean(value));
      value = 0.0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_float) {
      double value = 0.42f;
      assert::is_true(convert::to_boolean(value));
      value = 0.0f;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_int16) {
      int16 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_int32) {
      int32 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_int64) {
      int64 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_llong) {
      slong value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_sbyte) {
      sbyte value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_uint16) {
      uint16 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_uint32) {
      uint32 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_uint64) {
      uint64 value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_ullong) {
      xtd::ulong value = 42;
      assert::is_true(convert::to_boolean(value));
      value = 0;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_boolean_from_string) {
      string value = "true";
      assert::is_true(convert::to_boolean(value));
      value = "false";
      assert::is_false(convert::to_boolean(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_std_string) {
      std::string value = "true";
      assert::is_true(convert::to_boolean(value));
      value = "false";
      assert::is_false(convert::to_boolean(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_boolean_from_u8string) {
      std::u8string value = u8"true";
      assert::is_true(convert::to_boolean(value));
      value = u8"false";
      assert::is_false(convert::to_boolean(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
#endif
    
    void test_method_(to_boolean_from_u16string) {
      std::u16string value = u"true";
      assert::is_true(convert::to_boolean(value));
      value = u"false";
      assert::is_false(convert::to_boolean(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_u32string) {
      std::u32string value = U"true";
      assert::is_true(convert::to_boolean(value));
      value = U"false";
      assert::is_false(convert::to_boolean(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_wstring) {
      std::wstring value = L"true";
      assert::is_true(convert::to_boolean(value));
      value = L"false";
      assert::is_false(convert::to_boolean(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_literal_char) {
      const char* value = "true";
      assert::is_true(convert::to_boolean(value));
      value = "false";
      assert::is_false(convert::to_boolean(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_boolean_from_literal_char8) {
      const char8* value = u8"true";
      assert::is_true(convert::to_boolean(value));
      value = u8"false";
      assert::is_false(convert::to_boolean(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
#endif
    
    void test_method_(to_boolean_from_literal_char16) {
      const char16* value = u"true";
      assert::is_true(convert::to_boolean(value));
      value = u"false";
      assert::is_false(convert::to_boolean(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_literal_char32) {
      const char32* value = U"true";
      assert::is_true(convert::to_boolean(value));
      value = U"false";
      assert::is_false(convert::to_boolean(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_literal_wchar) {
      const wchar* value = L"true";
      assert::is_true(convert::to_boolean(value));
      value = L"false";
      assert::is_false(convert::to_boolean(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_boolean(value);});
    }
    
    void test_method_(to_boolean_from_values) {
      values value = values::two;
      assert::is_true(convert::to_boolean(value));
      value = values::zero;
      assert::is_false(convert::to_boolean(value));
    }
    
    void test_method_(to_byte_from_any) {
      std::any value = static_cast<xtd::byte>(42);
      assert::are_equal(42u, convert::to_byte(value));
      value = static_cast<xtd::byte>(0);
      assert::is_zero(convert::to_byte(value));
    }
    
    void test_method_(to_byte_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_byte(value));
      value = false;
      assert::is_zero(convert::to_byte(value));
    }
    
    void test_method_(to_byte_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
    }
    
    void test_method_(to_byte_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_byte_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
    }
#endif
    
    void test_method_(to_byte_from_char16) {
      char16 value = u'a';
      assert::are_equal(97u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = u'\u01FF';
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_char32) {
      char32 value = U'a';
      assert::are_equal(97u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = L'\x01FF';
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.49l;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.50l;
      assert::are_equal(43u, convert::to_byte(value));
      value = 0.0l;
      assert::is_zero(convert::to_byte(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256.0l;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.49;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.50;
      assert::are_equal(43u, convert::to_byte(value));
      value = 0.0;
      assert::is_zero(convert::to_byte(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256.0;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.49f;
      assert::are_equal(42u, convert::to_byte(value));
      value = 42.50f;
      assert::are_equal(43u, convert::to_byte(value));
      value = 0.0f;
      assert::is_zero(convert::to_byte(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256.0f;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_int16) {
      int16 value = 42;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_int32) {
      int32 value = 42;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_int64) {
      int64 value = 42l;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0l;
      assert::is_zero(convert::to_byte(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256l;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_llong) {
      slong value = 42ll;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0ll;
      assert::is_zero(convert::to_byte(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
      value = 256ll;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0;
      assert::is_zero(convert::to_byte(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0u;
      assert::is_zero(convert::to_byte(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0u;
      assert::is_zero(convert::to_byte(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0lu;
      assert::is_zero(convert::to_byte(value));
      value = 256lu;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42u, convert::to_byte(value));
      value = 0llu;
      assert::is_zero(convert::to_byte(value));
      value = 256llu;
      assert::throws<overflow_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_byte(value));
      value = "0";
      assert::is_zero(convert::to_byte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_string_with_base) {
      assert::are_equal(42u, convert::to_byte("0b101010", 2));
      assert::are_equal(42u, convert::to_byte(u8"052", 8));
      assert::are_equal(42u, convert::to_byte(u"42", 10));
      assert::are_equal(42u, convert::to_byte(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_byte(L"42", 4);});
    }
    
    void test_method_(to_byte_from_std_string) {
      std::string value = "42";
      assert::are_equal(42u, convert::to_byte(value));
      value = "0";
      assert::is_zero(convert::to_byte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_byte_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = u8"0";
      assert::is_zero(convert::to_byte(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
#endif
    
    void test_method_(to_byte_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = u"0";
      assert::is_zero(convert::to_byte(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = U"0";
      assert::is_zero(convert::to_byte(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = L"0";
      assert::is_zero(convert::to_byte(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_byte(value));
      value = "0";
      assert::is_zero(convert::to_byte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_byte_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = u8"0";
      assert::is_zero(convert::to_byte(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
#endif
    
    void test_method_(to_byte_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = u"0";
      assert::is_zero(convert::to_byte(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = U"0";
      assert::is_zero(convert::to_byte(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42u, convert::to_byte(value));
      value = L"0";
      assert::is_zero(convert::to_byte(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_byte(value);});
    }
    
    void test_method_(to_byte_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_byte(value));
      value = values::zero;
      assert::is_zero(convert::to_byte(value));
    }
    
    void test_method_(to_char_from_any) {
      std::any value = 'a';
      assert::are_equal('a', convert::to_char(value));
      value = '\0';
      assert::is_zero(convert::to_char(value));
    }
    
    void test_method_(to_char_from_any_failed) {
      std::any value = "not a char";
      assert::throws<invalid_cast_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_byte) {
      xtd::byte value = 97;
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
    }
    
    void test_method_(to_char_from_char) {
      char value = 'a';
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char_from_char8) {
      char8 value = u8'a';
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
    }
#endif
    
    void test_method_(to_char_from_char16) {
      char16 value = u'a';
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = u'\u01FF';
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_char32) {
      char32 value = U'a';
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_wchar) {
      wchar value = L'a';
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = L'\x01FF';
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_decimal) {
      decimal value = 97.0l;
      assert::are_equal('a', convert::to_char(value));
      value = 97.49l;
      assert::are_equal('a', convert::to_char(value));
      value = 97.50l;
      assert::are_equal('b', convert::to_char(value));
      value = 0.0l;
      assert::is_zero(convert::to_char(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256.0l;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_double) {
      double value = 97.0;
      assert::are_equal('a', convert::to_char(value));
      value = 97.49;
      assert::are_equal('a', convert::to_char(value));
      value = 97.50;
      assert::are_equal('b', convert::to_char(value));
      value = 0.0;
      assert::is_zero(convert::to_char(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256.0;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_float) {
      float value = 97.0f;
      assert::are_equal('a', convert::to_char(value));
      value = 97.49f;
      assert::are_equal('a', convert::to_char(value));
      value = 97.50f;
      assert::are_equal('b', convert::to_char(value));
      value = 0.0f;
      assert::is_zero(convert::to_char(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256.0f;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_int16) {
      int16 value = 97;
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_int32) {
      int32 value = 97;
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_int64) {
      int64 value = 97l;
      assert::are_equal('a', convert::to_char(value));
      value = 0l;
      assert::is_zero(convert::to_char(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256l;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_llong) {
      slong value = 97ll;
      assert::are_equal('a', convert::to_char(value));
      value = 0ll;
      assert::is_zero(convert::to_char(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
      value = 256ll;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_sbyte) {
      sbyte value = 97;
      assert::are_equal('a', convert::to_char(value));
      value = 0;
      assert::is_zero(convert::to_char(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_uint16) {
      uint16 value = 97u;
      assert::are_equal('a', convert::to_char(value));
      value = 0u;
      assert::is_zero(convert::to_char(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_uint32) {
      uint32 value = 97u;
      assert::are_equal('a', convert::to_char(value));
      value = 0u;
      assert::is_zero(convert::to_char(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_uint64) {
      uint64 value = 97lu;
      assert::are_equal('a', convert::to_char(value));
      value = 0lu;
      assert::is_zero(convert::to_char(value));
      value = 256lu;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_ullong) {
      xtd::ulong value = 97llu;
      assert::are_equal('a', convert::to_char(value));
      value = 0llu;
      assert::is_zero(convert::to_char(value));
      value = 256llu;
      assert::throws<overflow_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_string) {
      string value = "a";
      assert::are_equal('a', convert::to_char(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_std_string) {
      std::string value = "a";
      assert::are_equal('a', convert::to_char(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char_from_u8string) {
      std::u8string value = u8"a";
      assert::are_equal('a', convert::to_char(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
#endif
    
    void test_method_(to_char_from_u16string) {
      std::u16string value = u"a";
      assert::are_equal('a', convert::to_char(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_u32string) {
      std::u32string value = U"a";
      assert::are_equal('a', convert::to_char(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_wstring) {
      std::wstring value = L"a";
      assert::are_equal('a', convert::to_char(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_literal_char) {
      const char* value = "a";
      assert::are_equal('a', convert::to_char(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char_from_literal_char8) {
      const char8* value = u8"a";
      assert::are_equal('a', convert::to_char(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
#endif
    
    void test_method_(to_char_from_literal_char16) {
      const char16* value = u"a";
      assert::are_equal('a', convert::to_char(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_literal_char32) {
      const char32* value = U"a";
      assert::are_equal('a', convert::to_char(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_literal_wchar) {
      const wchar* value = L"a";
      assert::are_equal('a', convert::to_char(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char(value);});
    }
    
    void test_method_(to_char_from_values) {
      values value = values::two;
      assert::are_equal('\2', convert::to_char(value));
      value = values::zero;
      assert::is_zero(convert::to_char(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char8_from_any) {
      // Cannot build on macOS: std::any with char8 does not link!
      //std::any value = u8'a';
      //assert::throws<invalid_cast_exception>([&]{convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_any_failed) {
      std::any value = "not a char";
      assert::throws<invalid_cast_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_byte) {
      xtd::byte value = 97;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
    }
    
    void test_method_(to_char8_from_char) {
      char value = 'a';
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
    }
    
    void test_method_(to_char8_from_char8) {
      char8 value = u8'a';
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
    }
    
    void test_method_(to_char8_from_char16) {
      char16 value = u'a';
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = u'\u01FF';
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_char32) {
      char32 value = U'a';
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_wchar) {
      wchar value = L'a';
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = L'\x01FF';
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_decimal) {
      decimal value = 97.0l;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.49l;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.50l;
      assert::are_equal(u8'b', convert::to_char8(value));
      value = 0.0l;
      assert::is_zero(convert::to_char8(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256.0l;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_double) {
      double value = 97.0;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.49;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.50;
      assert::are_equal(u8'b', convert::to_char8(value));
      value = 0.0;
      assert::is_zero(convert::to_char8(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256.0;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_float) {
      float value = 97.0f;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.49f;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 97.50f;
      assert::are_equal(u8'b', convert::to_char8(value));
      value = 0.0f;
      assert::is_zero(convert::to_char8(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256.0f;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_int16) {
      int16 value = 97;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_int32) {
      int32 value = 97;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_int64) {
      int64 value = 97l;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0l;
      assert::is_zero(convert::to_char8(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256l;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_llong) {
      slong value = 97ll;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0ll;
      assert::is_zero(convert::to_char8(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
      value = 256ll;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_sbyte) {
      sbyte value = 97;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0;
      assert::is_zero(convert::to_char8(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_uint16) {
      uint16 value = 97u;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0u;
      assert::is_zero(convert::to_char8(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_uint32) {
      uint32 value = 97u;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0u;
      assert::is_zero(convert::to_char8(value));
      value = 256u;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_uint64) {
      uint64 value = 97lu;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0lu;
      assert::is_zero(convert::to_char8(value));
      value = 256lu;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_ullong) {
      xtd::ulong value = 97llu;
      assert::are_equal(u8'a', convert::to_char8(value));
      value = 0llu;
      assert::is_zero(convert::to_char8(value));
      value = 256llu;
      assert::throws<overflow_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_string) {
      string value = "a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_std_string) {
      std::string value = "a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_u8string) {
      std::u8string value = u8"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_u16string) {
      std::u16string value = u"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_u32string) {
      std::u32string value = U"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_wstring) {
      std::wstring value = L"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_literal_char) {
      const char* value = "a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_literal_char8) {
      const char8* value = u8"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_literal_char16) {
      const char16* value = u"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_literal_char32) {
      const char32* value = U"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_literal_wchar) {
      const wchar* value = L"a";
      assert::are_equal(u8'a', convert::to_char8(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char8(value);});
    }
    
    void test_method_(to_char8_from_values) {
      values value = values::two;
      assert::are_equal(u8'\2', convert::to_char8(value));
      value = values::zero;
      assert::is_zero(convert::to_char8(value));
    }
#endif
    
    void test_method_(to_char16_from_any) {
      std::any value = u'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = u'\0';
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char16_from_any_failed) {
      std::any value = "not a char";
      assert::throws<invalid_cast_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_byte) {
      xtd::byte value = 97;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char16_from_char) {
      char value = 'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char16_from_char8) {
      char8 value = u8'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
    }
#endif
    
    void test_method_(to_char16_from_char16) {
      char16 value = u'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char16_from_char32) {
      char32 value = U'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_wchar) {
      wchar value = L'a';
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char16_from_decimal) {
      decimal value = 97.0l;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.49l;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.50l;
      assert::are_equal(u'b', convert::to_char16(value));
      value = 0.0l;
      assert::is_zero(convert::to_char16(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536.0l;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_double) {
      double value = 97.0;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.49;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.50;
      assert::are_equal(u'b', convert::to_char16(value));
      value = 0.0;
      assert::is_zero(convert::to_char16(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536.0;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_float) {
      float value = 97.0f;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.49f;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 97.50f;
      assert::are_equal(u'b', convert::to_char16(value));
      value = 0.0f;
      assert::is_zero(convert::to_char16(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536.0f;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_int16) {
      int16 value = 97;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_int32) {
      int32 value = 97;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_int64) {
      int64 value = 97l;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0l;
      assert::is_zero(convert::to_char16(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536l;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_llong) {
      slong value = 97ll;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0ll;
      assert::is_zero(convert::to_char16(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
      value = 65536ll;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_sbyte) {
      sbyte value = 97;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0;
      assert::is_zero(convert::to_char16(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_uint16) {
      uint16 value = 97u;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0u;
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char16_from_uint32) {
      uint32 value = 97u;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0u;
      assert::is_zero(convert::to_char16(value));
      value = 65536u;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_uint64) {
      uint64 value = 97lu;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0lu;
      assert::is_zero(convert::to_char16(value));
      value = 65536lu;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_ullong) {
      xtd::ulong value = 97llu;
      assert::are_equal(u'a', convert::to_char16(value));
      value = 0llu;
      assert::is_zero(convert::to_char16(value));
      value = 65536llu;
      assert::throws<overflow_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_string) {
      string value = "a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_std_string) {
      std::string value = "a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char16_from_u8string) {
      std::u8string value = u8"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
#endif
    
    void test_method_(to_char16_from_u16string) {
      std::u16string value = u"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_u32string) {
      std::u32string value = U"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_wstring) {
      std::wstring value = L"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_literal_char) {
      const char* value = "a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char16_from_literal_char8) {
      const char8* value = u8"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
#endif
    
    void test_method_(to_char16_from_literal_char16) {
      const char16* value = u"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_literal_char32) {
      const char32* value = U"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_literal_wchar) {
      const wchar* value = L"a";
      assert::are_equal(u'a', convert::to_char16(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char16(value);});
    }
    
    void test_method_(to_char16_from_values) {
      values value = values::two;
      assert::are_equal(u'\2', convert::to_char16(value));
      value = values::zero;
      assert::is_zero(convert::to_char16(value));
    }
    
    void test_method_(to_char32_from_any) {
      std::any value = U'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = U'\0';
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_any_failed) {
      std::any value = "not a char";
      assert::throws<invalid_cast_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_byte) {
      xtd::byte value = 97;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_char) {
      char value = 'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char32_from_char8) {
      char8 value = u8'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
#endif
    
    void test_method_(to_char32_from_char16) {
      char16 value = u'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_char32) {
      char32 value = U'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_wchar) {
      wchar value = L'a';
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_decimal) {
      decimal value = 97.0l;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.49l;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.50l;
      assert::are_equal(U'b', convert::to_char32(value));
      value = 0.0l;
      assert::is_zero(convert::to_char32(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
      value = 4294967296.0l;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_double) {
      double value = 97.0;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.49;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.50;
      assert::are_equal(U'b', convert::to_char32(value));
      value = 0.0;
      assert::is_zero(convert::to_char32(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
      value = 4294967296.0;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_float) {
      float value = 97.0f;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.49f;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 97.50f;
      assert::are_equal(U'b', convert::to_char32(value));
      value = 0.0f;
      assert::is_zero(convert::to_char32(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_int16) {
      int16 value = 97;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_int32) {
      int32 value = 97;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_int64) {
      int64 value = 97l;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0l;
      assert::is_zero(convert::to_char32(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
      value = 4294967296l;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_llong) {
      slong value = 97ll;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0ll;
      assert::is_zero(convert::to_char32(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_sbyte) {
      sbyte value = 97;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0;
      assert::is_zero(convert::to_char32(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_uint16) {
      uint16 value = 97u;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0u;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_uint32) {
      uint32 value = 97u;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0u;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_uint64) {
      uint64 value = 97lu;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0lu;
      assert::is_zero(convert::to_char32(value));
      value = 4294967296lu;
      assert::throws<overflow_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_ullong) {
      xtd::ulong value = 97llu;
      assert::are_equal(U'a', convert::to_char32(value));
      value = 0llu;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_char32_from_string) {
      string value = "a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_std_string) {
      std::string value = "a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char32_from_u8string) {
      std::u8string value = u8"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
#endif
    
    void test_method_(to_char32_from_u16string) {
      std::u16string value = u"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_u32string) {
      std::u32string value = U"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_wstring) {
      std::wstring value = L"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_literal_char) {
      const char* value = "a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_char32_from_literal_char8) {
      const char8* value = u8"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
#endif
    
    void test_method_(to_char32_from_literal_char16) {
      const char16* value = u"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_literal_char32) {
      const char32* value = U"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_literal_wchar) {
      const wchar* value = L"a";
      assert::are_equal(U'a', convert::to_char32(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_char32(value);});
    }
    
    void test_method_(to_char32_from_values) {
      values value = values::two;
      assert::are_equal(U'\2', convert::to_char32(value));
      value = values::zero;
      assert::is_zero(convert::to_char32(value));
    }
    
    void test_method_(to_wchar_from_any) {
      std::any value = L'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = L'\0';
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_wchar_from_any_failed) {
      std::any value = "not a char";
      assert::throws<invalid_cast_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_byte) {
      xtd::byte value = 97;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_wchar_from_char) {
      char value = 'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_wchar_from_char8) {
      char8 value = u8'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
    }
#endif
    
    void test_method_(to_wchar_from_char16) {
      char16 value = u'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_wchar_from_char32) {
      char32 value = U'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_wchar) {
      wchar value = L'a';
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_wchar_from_decimal) {
      decimal value = 97.0l;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.49l;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.50l;
      assert::are_equal(L'b', convert::to_wchar(value));
      value = 0.0l;
      assert::is_zero(convert::to_wchar(value));
      value = -0.1l;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536.0l;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_double) {
      double value = 97.0;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.49;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.50;
      assert::are_equal(L'b', convert::to_wchar(value));
      value = 0.0;
      assert::is_zero(convert::to_wchar(value));
      value = -0.1;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536.0;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_float) {
      float value = 97.0f;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.49f;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 97.50f;
      assert::are_equal(L'b', convert::to_wchar(value));
      value = 0.0f;
      assert::is_zero(convert::to_wchar(value));
      value = -0.1f;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536.0f;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_int16) {
      int16 value = 97;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_int32) {
      int32 value = 97;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_int64) {
      int64 value = 97l;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0l;
      assert::is_zero(convert::to_wchar(value));
      value = -1l;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536l;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_llong) {
      slong value = 97ll;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0ll;
      assert::is_zero(convert::to_wchar(value));
      value = -1ll;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
      value = 65536ll;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_sbyte) {
      sbyte value = 97;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0;
      assert::is_zero(convert::to_wchar(value));
      value = -1;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_uint16) {
      uint16 value = 97u;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0u;
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_wchar_from_uint32) {
      uint32 value = 97u;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0u;
      assert::is_zero(convert::to_wchar(value));
      value = 65536u;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_uint64) {
      uint64 value = 97lu;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0lu;
      assert::is_zero(convert::to_wchar(value));
      value = 65536lu;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_ullong) {
      xtd::ulong value = 97llu;
      assert::are_equal(L'a', convert::to_wchar(value));
      value = 0llu;
      assert::is_zero(convert::to_wchar(value));
      value = 65536llu;
      assert::throws<overflow_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_string) {
      string value = "a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_std_string) {
      std::string value = "a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_wchar_from_u8string) {
      std::u8string value = u8"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
#endif
    
    void test_method_(to_wchar_from_u16string) {
      std::u16string value = u"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_u32string) {
      std::u32string value = U"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_wstring) {
      std::wstring value = L"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_literal_char) {
      const char* value = "a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = "ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_wchar_from_literal_char8) {
      const char8* value = u8"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = u8"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
#endif
    
    void test_method_(to_wchar_from_literal_char16) {
      const char16* value = u"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = u"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_literal_char32) {
      const char32* value = U"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = U"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_literal_wchar) {
      const wchar* value = L"a";
      assert::are_equal(L'a', convert::to_wchar(value));
      value = L"ab";
      assert::throws<format_exception>([&] {convert::to_wchar(value);});
    }
    
    void test_method_(to_wchar_from_values) {
      values value = values::two;
      assert::are_equal(L'\2', convert::to_wchar(value));
      value = values::zero;
      assert::is_zero(convert::to_wchar(value));
    }
    
    void test_method_(to_decimal_from_any) {
      std::any value = 42.0l;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0.0l;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_bool) {
      bool value = true;
      assert::are_equal(1.0l, convert::to_decimal(value));
      value = false;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_char) {
      char value = 'a';
      assert::are_equal(97.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_decimal_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
#endif
    
    void test_method_(to_decimal_from_char16) {
      char16 value = u'a';
      assert::are_equal(97.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_char32) {
      char32 value = U'a';
      assert::are_equal(97.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_double) {
      double value = 42.0;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
      
    }
    
    void test_method_(to_decimal_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_int16) {
      int16 value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_int32) {
      int32 value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_int64) {
      int64 value = 42l;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_llong) {
      slong value = 42ll;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = 0;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_decimal_from_string) {
      string value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = "0";
      assert::is_zero(convert::to_decimal(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_std_string) {
      std::string value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = "0";
      assert::is_zero(convert::to_decimal(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_decimal_from_u8string) {
      std::u8string value = u8"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = u8"0";
      assert::is_zero(convert::to_decimal(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
#endif
    
    void test_method_(to_decimal_from_u16string) {
      std::u16string value = u"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = u"0";
      assert::is_zero(convert::to_decimal(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_u32string) {
      std::u32string value = U"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = U"0";
      assert::is_zero(convert::to_decimal(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_wstring) {
      std::wstring value = L"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = L"0";
      assert::is_zero(convert::to_decimal(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = "0";
      assert::is_zero(convert::to_decimal(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_decimal_from_literal_char8) {
      const char8* value = u8"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = u8"0";
      assert::is_zero(convert::to_decimal(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
#endif
    
    void test_method_(to_decimal_from_literal_char16) {
      const char16* value = u"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = u"0";
      assert::is_zero(convert::to_decimal(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_literal_char32) {
      const char32* value = U"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = U"0";
      assert::is_zero(convert::to_decimal(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_literal_wchar) {
      const wchar* value = L"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value));
      value = L"0";
      assert::is_zero(convert::to_decimal(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_decimal(value);});
    }
    
    void test_method_(to_decimal_from_values) {
      values value = values::two;
      assert::are_equal(2.0l, convert::to_decimal(value));
      value = values::zero;
      assert::is_zero(convert::to_decimal(value));
    }
    
    void test_method_(to_double_from_any) {
      std::any value = 42.0;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0.0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_bool) {
      bool value = true;
      assert::are_equal(1.0, convert::to_double(value));
      value = false;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_char) {
      char value = 'a';
      assert::are_equal(97.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_double_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
#endif
    
    void test_method_(to_double_from_char16) {
      char16 value = u'a';
      assert::are_equal(97.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_char32) {
      char32 value = U'a';
      assert::are_equal(97.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_double) {
      double value = 42.0;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
      
    }
    
    void test_method_(to_double_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_int16) {
      int16 value = 42;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_int32) {
      int32 value = 42;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_int64) {
      int64 value = 42l;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_llong) {
      slong value = 42ll;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42.0, convert::to_double(value));
      value = 0;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_double_from_string) {
      string value = "42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = "0";
      assert::is_zero(convert::to_double(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_std_string) {
      std::string value = "42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = "0";
      assert::is_zero(convert::to_double(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_double_from_u8string) {
      std::u8string value = u8"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = u8"0";
      assert::is_zero(convert::to_double(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
#endif
    
    void test_method_(to_double_from_u16string) {
      std::u16string value = u"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = u"0";
      assert::is_zero(convert::to_double(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_u32string) {
      std::u32string value = U"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = U"0";
      assert::is_zero(convert::to_double(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_wstring) {
      std::wstring value = L"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = L"0";
      assert::is_zero(convert::to_double(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = "0";
      assert::is_zero(convert::to_double(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_double_from_literal_char8) {
      const char8* value = u8"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = u8"0";
      assert::is_zero(convert::to_double(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
#endif
    
    void test_method_(to_double_from_literal_char16) {
      const char16* value = u"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = u"0";
      assert::is_zero(convert::to_double(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_literal_char32) {
      const char32* value = U"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = U"0";
      assert::is_zero(convert::to_double(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_literal_wchar) {
      const wchar* value = L"42.0";
      assert::are_equal(42.0, convert::to_double(value));
      value = L"0";
      assert::is_zero(convert::to_double(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_double(value);});
    }
    
    void test_method_(to_double_from_values) {
      values value = values::two;
      assert::are_equal(2.0, convert::to_double(value));
      value = values::zero;
      assert::is_zero(convert::to_double(value));
    }
    
    void test_method_(to_single_from_any) {
      std::any value = 42.0f;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0.0f;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_bool) {
      bool value = true;
      assert::are_equal(1.0f, convert::to_single(value));
      value = false;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_char) {
      char value = 'a';
      assert::are_equal(97.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_single_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
#endif
    
    void test_method_(to_single_from_char16) {
      char16 value = u'a';
      assert::are_equal(97.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_char32) {
      char32 value = U'a';
      assert::are_equal(97.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_double) {
      double value = 42.0;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
      
    }
    
    void test_method_(to_single_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_int16) {
      int16 value = 42;
      assert::are_equal(42.0, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_int32) {
      int32 value = 42;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_int64) {
      int64 value = 42l;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_llong) {
      slong value = 42ll;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42.0f, convert::to_single(value));
      value = 0;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_single_from_string) {
      string value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = "0";
      assert::is_zero(convert::to_single(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_std_string) {
      std::string value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = "0";
      assert::is_zero(convert::to_single(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_single_from_u8string) {
      std::u8string value = u8"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = u8"0";
      assert::is_zero(convert::to_single(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
#endif
    
    void test_method_(to_single_from_u16string) {
      std::u16string value = u"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = u"0";
      assert::is_zero(convert::to_single(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_u32string) {
      std::u32string value = U"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = U"0";
      assert::is_zero(convert::to_single(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_wstring) {
      std::wstring value = L"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = L"0";
      assert::is_zero(convert::to_single(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = "0";
      assert::is_zero(convert::to_single(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_single_from_literal_char8) {
      const char8* value = u8"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = u8"0";
      assert::is_zero(convert::to_single(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
#endif
    
    void test_method_(to_single_from_literal_char16) {
      const char16* value = u"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = u"0";
      assert::is_zero(convert::to_single(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_literal_char32) {
      const char32* value = U"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = U"0";
      assert::is_zero(convert::to_single(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_literal_wchar) {
      const wchar* value = L"42.0";
      assert::are_equal(42.0f, convert::to_single(value));
      value = L"0";
      assert::is_zero(convert::to_single(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_single(value);});
    }
    
    void test_method_(to_single_from_values) {
      values value = values::two;
      assert::are_equal(2.0f, convert::to_single(value));
      value = values::zero;
      assert::is_zero(convert::to_single(value));
    }
    
    void test_method_(to_int16_from_any) {
      std::any value = static_cast<int16>(42);
      assert::are_equal(42, convert::to_int16(value));
      value = static_cast<int16>(0);
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_int16(value));
      value = false;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int16_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
#endif
    
    void test_method_(to_int16_from_char16) {
      char16 value = u'a';
      assert::are_equal(97, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_char32) {
      char32 value = U'a';
      assert::are_equal(97, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.49l;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.50l;
      assert::are_equal(43, convert::to_int16(value));
      value = 0.0l;
      assert::is_zero(convert::to_int16(value));
      value = 32768.0l;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.49;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.50;
      assert::are_equal(43, convert::to_int16(value));
      value = 0.0;
      assert::is_zero(convert::to_int16(value));
      value = 32768.0;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.49f;
      assert::are_equal(42, convert::to_int16(value));
      value = 42.50f;
      assert::are_equal(43, convert::to_int16(value));
      value = 0.0f;
      assert::is_zero(convert::to_int16(value));
      value = 32768.0f;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_int16) {
      int16 value = 42;
      assert::are_equal(42, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_int32) {
      int32 value = 42;
      assert::are_equal(42, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
      value = 32768;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_int64) {
      int64 value = 42l;
      assert::are_equal(42, convert::to_int16(value));
      value = 0l;
      assert::is_zero(convert::to_int16(value));
      value = 32768l;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_llong) {
      slong value = 42ll;
      assert::are_equal(42, convert::to_int16(value));
      value = 0ll;
      assert::is_zero(convert::to_int16(value));
      value = 32768ll;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42, convert::to_int16(value));
      value = 0;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int16_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42, convert::to_int16(value));
      value = 0u;
      assert::is_zero(convert::to_int16(value));
      value = 32768u;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42, convert::to_int16(value));
      value = 0u;
      assert::is_zero(convert::to_int16(value));
      value = 32768u;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42, convert::to_int16(value));
      value = 0lu;
      assert::is_zero(convert::to_int16(value));
      value = 32768lu;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42, convert::to_int16(value));
      value = 0llu;
      assert::is_zero(convert::to_int16(value));
      value = 32768llu;
      assert::throws<overflow_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_int16(value));
      value = "0";
      assert::is_zero(convert::to_int16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_string_with_base) {
      assert::are_equal(42, convert::to_int16("0b101010", 2));
      assert::are_equal(42, convert::to_int16(u8"052", 8));
      assert::are_equal(42, convert::to_int16(u"42", 10));
      assert::are_equal(42, convert::to_int16(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_int16(L"42", 4);});
    }
    
    void test_method_(to_int16_from_std_string) {
      std::string value = "42";
      assert::are_equal(42, convert::to_int16(value));
      value = "0";
      assert::is_zero(convert::to_int16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int16_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42, convert::to_int16(value));
      value = u8"0";
      assert::is_zero(convert::to_int16(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
#endif
    
    void test_method_(to_int16_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42, convert::to_int16(value));
      value = u"0";
      assert::is_zero(convert::to_int16(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42, convert::to_int16(value));
      value = U"0";
      assert::is_zero(convert::to_int16(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42, convert::to_int16(value));
      value = L"0";
      assert::is_zero(convert::to_int16(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_int16(value));
      value = "0";
      assert::is_zero(convert::to_int16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int16_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42, convert::to_int16(value));
      value = u8"0";
      assert::is_zero(convert::to_int16(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
#endif
    
    void test_method_(to_int16_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42, convert::to_int16(value));
      value = u"0";
      assert::is_zero(convert::to_int16(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42, convert::to_int16(value));
      value = U"0";
      assert::is_zero(convert::to_int16(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42, convert::to_int16(value));
      value = L"0";
      assert::is_zero(convert::to_int16(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int16(value);});
    }
    
    void test_method_(to_int16_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_int16(value));
      value = values::zero;
      assert::is_zero(convert::to_int16(value));
    }
    
    void test_method_(to_int32_from_any) {
      std::any value = static_cast<int32>(42);
      assert::are_equal(42, convert::to_int32(value));
      value = static_cast<int32>(0);
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_int32(value));
      value = false;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int32_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
#endif
    
    void test_method_(to_int32_from_char16) {
      char16 value = u'a';
      assert::are_equal(97, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_char32) {
      char32 value = U'a';
      assert::are_equal(97, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.49l;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.50l;
      assert::are_equal(43, convert::to_int32(value));
      value = 0.0l;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648.0l;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.49;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.50;
      assert::are_equal(43, convert::to_int32(value));
      value = 0.0;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648.0;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.49f;
      assert::are_equal(42, convert::to_int32(value));
      value = 42.50f;
      assert::are_equal(43, convert::to_int32(value));
      value = 0.0f;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_int16) {
      int16 value = 42;
      assert::are_equal(42, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_int32) {
      int32 value = 42;
      assert::are_equal(42, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_int64) {
      int64 value = 42l;
      assert::are_equal(42, convert::to_int32(value));
      value = 0l;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648l;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_llong) {
      slong value = 42ll;
      assert::are_equal(42, convert::to_int32(value));
      value = 0ll;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42, convert::to_int32(value));
      value = 0;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42, convert::to_int32(value));
      value = 0u;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int32_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42, convert::to_int32(value));
      value = 0u;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648u;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42, convert::to_int32(value));
      value = 0lu;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648lu;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42, convert::to_int32(value));
      value = 0llu;
      assert::is_zero(convert::to_int32(value));
      value = 2147483648llu;
      assert::throws<overflow_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_int32(value));
      value = "0";
      assert::is_zero(convert::to_int32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_string_with_base) {
      assert::are_equal(42, convert::to_int32("0b101010", 2));
      assert::are_equal(42, convert::to_int32(u8"052", 8));
      assert::are_equal(42, convert::to_int32(u"42", 10));
      assert::are_equal(42, convert::to_int32(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_int32(L"42", 4);});
    }
    
    void test_method_(to_int32_from_std_string) {
      std::string value = "42";
      assert::are_equal(42, convert::to_int32(value));
      value = "0";
      assert::is_zero(convert::to_int32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int32_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42, convert::to_int32(value));
      value = u8"0";
      assert::is_zero(convert::to_int32(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
#endif
    
    void test_method_(to_int32_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42, convert::to_int32(value));
      value = u"0";
      assert::is_zero(convert::to_int32(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42, convert::to_int32(value));
      value = U"0";
      assert::is_zero(convert::to_int32(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42, convert::to_int32(value));
      value = L"0";
      assert::is_zero(convert::to_int32(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_int32(value));
      value = "0";
      assert::is_zero(convert::to_int32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int32_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42, convert::to_int32(value));
      value = u8"0";
      assert::is_zero(convert::to_int32(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
#endif
    
    void test_method_(to_int32_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42, convert::to_int32(value));
      value = u"0";
      assert::is_zero(convert::to_int32(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42, convert::to_int32(value));
      value = U"0";
      assert::is_zero(convert::to_int32(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42, convert::to_int32(value));
      value = L"0";
      assert::is_zero(convert::to_int32(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int32(value);});
    }
    
    void test_method_(to_int32_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_int32(value));
      value = values::zero;
      assert::is_zero(convert::to_int32(value));
    }
    
    void test_method_(to_int64_from_any) {
      std::any value = static_cast<int64>(42);
      assert::are_equal(42l, convert::to_int64(value));
      value = static_cast<int64>(0);
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_bool) {
      bool value = true;
      assert::are_equal(1l, convert::to_int64(value));
      value = false;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_char) {
      char value = 'a';
      assert::are_equal(97l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int64_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
#endif
    
    void test_method_(to_int64_from_char16) {
      char16 value = u'a';
      assert::are_equal(97l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_char32) {
      char32 value = U'a';
      assert::are_equal(97l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.49l;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.50l;
      assert::are_equal(43l, convert::to_int64(value));
      value = 0.0l;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_double) {
      double value = 42.0;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.49;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.50;
      assert::are_equal(43l, convert::to_int64(value));
      value = 0.0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_float) {
      float value = 42.0f;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.49f;
      assert::are_equal(42l, convert::to_int64(value));
      value = 42.50f;
      assert::are_equal(43l, convert::to_int64(value));
      value = 0.0f;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_int16) {
      int16 value = 42;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_int32) {
      int32 value = 42;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_int64) {
      int64 value = 42l;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0l;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_llong) {
      slong value = 42ll;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0ll;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0u;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0u;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0lu;
      assert::is_zero(convert::to_int64(value));
      value = 9223372036854775808lu;
      assert::throws<overflow_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42l, convert::to_int64(value));
      value = 0llu;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_int64_from_string) {
      string value = "42";
      assert::are_equal(42l, convert::to_int64(value));
      value = "0";
      assert::is_zero(convert::to_int64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_string_with_base) {
      assert::are_equal(42, convert::to_int64("0b101010", 2));
      assert::are_equal(42, convert::to_int64(u8"052", 8));
      assert::are_equal(42, convert::to_int64(u"42", 10));
      assert::are_equal(42, convert::to_int64(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_int64(L"42", 4);});
    }
    
    void test_method_(to_int64_from_std_string) {
      std::string value = "42";
      assert::are_equal(42l, convert::to_int64(value));
      value = "0";
      assert::is_zero(convert::to_int64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int64_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = u8"0";
      assert::is_zero(convert::to_int64(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
#endif
    
    void test_method_(to_int64_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = u"0";
      assert::is_zero(convert::to_int64(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = U"0";
      assert::is_zero(convert::to_int64(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = L"0";
      assert::is_zero(convert::to_int64(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42l, convert::to_int64(value));
      value = "0";
      assert::is_zero(convert::to_int64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_int64_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = u8"0";
      assert::is_zero(convert::to_int64(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
#endif
    
    void test_method_(to_int64_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = u"0";
      assert::is_zero(convert::to_int64(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = U"0";
      assert::is_zero(convert::to_int64(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42l, convert::to_int64(value));
      value = L"0";
      assert::is_zero(convert::to_int64(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_int64(value);});
    }
    
    void test_method_(to_int64_from_values) {
      values value = values::two;
      assert::are_equal(2l, convert::to_int64(value));
      value = values::zero;
      assert::is_zero(convert::to_int64(value));
    }
    
    void test_method_(to_llong_from_any) {
      std::any value = static_cast<slong>(42ll);
      assert::are_equal(42ll, convert::to_llong(value));
      value = static_cast<slong>(0ll);
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_bool) {
      bool value = true;
      assert::are_equal(1ll, convert::to_llong(value));
      value = false;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_char) {
      char value = 'a';
      assert::are_equal(97ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_llong_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
#endif
    
    void test_method_(to_llong_from_char16) {
      char16 value = u'a';
      assert::are_equal(97ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_char32) {
      char32 value = U'a';
      assert::are_equal(97ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.49l;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.50l;
      assert::are_equal(43ll, convert::to_llong(value));
      value = 0.0l;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_double) {
      double value = 42.0;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.49;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.50;
      assert::are_equal(43ll, convert::to_llong(value));
      value = 0.0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_float) {
      float value = 42.0f;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.49f;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 42.50f;
      assert::are_equal(43ll, convert::to_llong(value));
      value = 0.0f;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_int16) {
      int16 value = 42;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_int32) {
      int32 value = 42;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_int64) {
      int64 value = 42l;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0l;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_llong) {
      slong value = 42ll;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0ll;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0u;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0u;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0lu;
      assert::is_zero(convert::to_llong(value));
      value = 9223372036854775808lu;
      assert::throws<overflow_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42ll, convert::to_llong(value));
      value = 0llu;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_llong_from_string) {
      string value = "42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = "0";
      assert::is_zero(convert::to_llong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_string_with_base) {
      assert::are_equal(42, convert::to_llong("0b101010", 2));
      assert::are_equal(42, convert::to_llong(u8"052", 8));
      assert::are_equal(42, convert::to_llong(u"42", 10));
      assert::are_equal(42, convert::to_llong(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_llong(L"42", 4);});
    }
    
    void test_method_(to_llong_from_std_string) {
      std::string value = "42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = "0";
      assert::is_zero(convert::to_llong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_llong_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = u8"0";
      assert::is_zero(convert::to_llong(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
#endif
    
    void test_method_(to_llong_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = u"0";
      assert::is_zero(convert::to_llong(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = U"0";
      assert::is_zero(convert::to_llong(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = L"0";
      assert::is_zero(convert::to_llong(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = "0";
      assert::is_zero(convert::to_llong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_llong_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = u8"0";
      assert::is_zero(convert::to_llong(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
#endif
    
    void test_method_(to_llong_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = u"0";
      assert::is_zero(convert::to_llong(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = U"0";
      assert::is_zero(convert::to_llong(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42ll, convert::to_llong(value));
      value = L"0";
      assert::is_zero(convert::to_llong(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_llong(value);});
    }
    
    void test_method_(to_llong_from_values) {
      values value = values::two;
      assert::are_equal(2ll, convert::to_llong(value));
      value = values::zero;
      assert::is_zero(convert::to_llong(value));
    }
    
    void test_method_(to_sbyte_from_any) {
      std::any value = static_cast<sbyte>(42);
      assert::are_equal(42, convert::to_sbyte(value));
      value = static_cast<sbyte>(0);
      assert::is_zero(convert::to_sbyte(value));
    }
    
    void test_method_(to_sbyte_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_sbyte(value));
      value = false;
      assert::is_zero(convert::to_sbyte(value));
    }
    
    void test_method_(to_sbyte_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
    }
    
    void test_method_(to_sbyte_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_sbyte_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
    }
#endif
    
    void test_method_(to_sbyte_from_char16) {
      char16 value = u'a';
      assert::are_equal(97, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
      value = u'\u0080';
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_char32) {
      char32 value = U'a';
      assert::are_equal(97, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
      value = U'\U00000080';
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
      value = L'\x0080';
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.49l;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.50l;
      assert::are_equal(43, convert::to_sbyte(value));
      value = 0.0l;
      assert::is_zero(convert::to_sbyte(value));
      value = 128.0l;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.49;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.50;
      assert::are_equal(43, convert::to_sbyte(value));
      value = 0.0;
      assert::is_zero(convert::to_sbyte(value));
      value = 128.0;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.49f;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 42.50f;
      assert::are_equal(43, convert::to_sbyte(value));
      value = 0.0f;
      assert::is_zero(convert::to_sbyte(value));
      value = 128.0f;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_int16) {
      int16 value = 42;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
      value = 128;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_int32) {
      int32 value = 42;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
      value = 128;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_int64) {
      int64 value = 42l;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0l;
      assert::is_zero(convert::to_sbyte(value));
      value = 128l;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_llong) {
      slong value = 42ll;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0ll;
      assert::is_zero(convert::to_sbyte(value));
      value = 128ll;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0;
      assert::is_zero(convert::to_sbyte(value));
    }
    
    void test_method_(to_sbyte_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0u;
      assert::is_zero(convert::to_sbyte(value));
      value = 128u;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0u;
      assert::is_zero(convert::to_sbyte(value));
      value = 128u;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0lu;
      assert::is_zero(convert::to_sbyte(value));
      value = 128lu;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42, convert::to_sbyte(value));
      value = 0llu;
      assert::is_zero(convert::to_sbyte(value));
      value = 128llu;
      assert::throws<overflow_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = "0";
      assert::is_zero(convert::to_sbyte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_string_with_base) {
      assert::are_equal(42, convert::to_sbyte("0b101010", 2));
      assert::are_equal(42, convert::to_sbyte(u8"052", 8));
      assert::are_equal(42, convert::to_sbyte(u"42", 10));
      assert::are_equal(42, convert::to_sbyte(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_sbyte(L"42", 4);});
    }
    
    void test_method_(to_sbyte_from_std_string) {
      std::string value = "42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = "0";
      assert::is_zero(convert::to_sbyte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_sbyte_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = u8"0";
      assert::is_zero(convert::to_sbyte(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
#endif
    
    void test_method_(to_sbyte_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = u"0";
      assert::is_zero(convert::to_sbyte(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = U"0";
      assert::is_zero(convert::to_sbyte(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = L"0";
      assert::is_zero(convert::to_sbyte(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = "0";
      assert::is_zero(convert::to_sbyte(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_sbyte_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = u8"0";
      assert::is_zero(convert::to_sbyte(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
#endif
    
    void test_method_(to_sbyte_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = u"0";
      assert::is_zero(convert::to_sbyte(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = U"0";
      assert::is_zero(convert::to_sbyte(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42, convert::to_sbyte(value));
      value = L"0";
      assert::is_zero(convert::to_sbyte(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_sbyte(value);});
    }
    
    void test_method_(to_sbyte_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_sbyte(value));
      value = values::zero;
      assert::is_zero(convert::to_sbyte(value));
    }
    
    void test_method_(to_uint16_from_any) {
      std::any value = static_cast<uint16>(42);
      assert::are_equal(42u, convert::to_uint16(value));
      value = static_cast<uint16>(0);
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_uint16(value));
      value = false;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint16_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
#endif
    
    void test_method_(to_uint16_from_char16) {
      char16 value = u'a';
      assert::are_equal(97u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_char32) {
      char32 value = U'a';
      assert::are_equal(97u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint16(value));
      value = 0.0l;
      assert::is_zero(convert::to_uint16(value));
      value = 65536.0l;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.49;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.50;
      assert::are_equal(43u, convert::to_uint16(value));
      value = 0.0;
      assert::is_zero(convert::to_uint16(value));
      value = 65536.0;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint16(value));
      value = 0.0f;
      assert::is_zero(convert::to_uint16(value));
      value = 65536.0f;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_int16) {
      int16 value = 42;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_int32) {
      int32 value = 42;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
      value = 65536;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_int64) {
      int64 value = 42l;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0l;
      assert::is_zero(convert::to_uint16(value));
      value = 65536;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_llong) {
      slong value = 42ll;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0ll;
      assert::is_zero(convert::to_uint16(value));
      value = 65536ll;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0u;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint16_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0u;
      assert::is_zero(convert::to_uint16(value));
      value = 65536u;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0lu;
      assert::is_zero(convert::to_uint16(value));
      value = 65536lu;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42u, convert::to_uint16(value));
      value = 0llu;
      assert::is_zero(convert::to_uint16(value));
      value = 65536llu;
      assert::throws<overflow_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = "0";
      assert::is_zero(convert::to_uint16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_string_with_base) {
      assert::are_equal(42u, convert::to_uint16("0b101010", 2));
      assert::are_equal(42u, convert::to_uint16(u8"052", 8));
      assert::are_equal(42u, convert::to_uint16(u"42", 10));
      assert::are_equal(42u, convert::to_uint16(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_uint16(L"42", 4);});
    }
    
    void test_method_(to_uint16_from_std_string) {
      std::string value = "42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = "0";
      assert::is_zero(convert::to_uint16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint16_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = u8"0";
      assert::is_zero(convert::to_uint16(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
#endif
    
    void test_method_(to_uint16_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = u"0";
      assert::is_zero(convert::to_uint16(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = U"0";
      assert::is_zero(convert::to_uint16(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = L"0";
      assert::is_zero(convert::to_uint16(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = "0";
      assert::is_zero(convert::to_uint16(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint16_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = u8"0";
      assert::is_zero(convert::to_uint16(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
#endif
    
    void test_method_(to_uint16_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = u"0";
      assert::is_zero(convert::to_uint16(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = U"0";
      assert::is_zero(convert::to_uint16(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42u, convert::to_uint16(value));
      value = L"0";
      assert::is_zero(convert::to_uint16(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint16(value);});
    }
    
    void test_method_(to_uint16_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint16(value));
      value = values::zero;
      assert::is_zero(convert::to_uint16(value));
    }
    
    void test_method_(to_uint32_from_any) {
      std::any value = static_cast<uint32>(42);
      assert::are_equal(42u, convert::to_uint32(value));
      value = static_cast<uint32>(0);
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_uint32(value));
      value = false;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint32_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
#endif
    
    void test_method_(to_uint32_from_char16) {
      char16 value = u'a';
      assert::are_equal(97u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_char32) {
      char32 value = U'a';
      assert::are_equal(97u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint32(value));
      value = 0.0l;
      assert::is_zero(convert::to_uint32(value));
      value = 4294967296.0l;
      assert::throws<overflow_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.49;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.50;
      assert::are_equal(43u, convert::to_uint32(value));
      value = 0.0;
      assert::is_zero(convert::to_uint32(value));
      value = 4294967296.0;
      assert::throws<overflow_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint32(value));
      value = 0.0f;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_int16) {
      int16 value = 42;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_int32) {
      int32 value = 42;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_int64) {
      int64 value = 42l;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0l;
      assert::is_zero(convert::to_uint32(value));
      value = 4294967296;
      assert::throws<overflow_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_llong) {
      slong value = 42;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0ll;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0u;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0u;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0lu;
      assert::is_zero(convert::to_uint32(value));
      value = 4294967296lu;
      assert::throws<overflow_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42u, convert::to_uint32(value));
      value = 0llu;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint32_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = "0";
      assert::is_zero(convert::to_uint32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_string_with_base) {
      assert::are_equal(42u, convert::to_uint32("0b101010", 2));
      assert::are_equal(42u, convert::to_uint32(u8"052", 8));
      assert::are_equal(42u, convert::to_uint32(u"42", 10));
      assert::are_equal(42u, convert::to_uint32(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_uint32(L"42", 4);});
    }
    
    void test_method_(to_uint32_from_std_string) {
      std::string value = "42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = "0";
      assert::is_zero(convert::to_uint32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint32_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = u8"0";
      assert::is_zero(convert::to_uint32(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
#endif
    
    void test_method_(to_uint32_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = u"0";
      assert::is_zero(convert::to_uint32(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = U"0";
      assert::is_zero(convert::to_uint32(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = L"0";
      assert::is_zero(convert::to_uint32(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = "0";
      assert::is_zero(convert::to_uint32(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint32_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = u8"0";
      assert::is_zero(convert::to_uint32(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
#endif
    
    void test_method_(to_uint32_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = u"0";
      assert::is_zero(convert::to_uint32(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = U"0";
      assert::is_zero(convert::to_uint32(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42u, convert::to_uint32(value));
      value = L"0";
      assert::is_zero(convert::to_uint32(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint32(value);});
    }
    
    void test_method_(to_uint32_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint32(value));
      value = values::zero;
      assert::is_zero(convert::to_uint32(value));
    }
    
    void test_method_(to_uint64_from_any) {
      std::any value = static_cast<uint64>(42);
      assert::are_equal(42u, convert::to_uint64(value));
      value = static_cast<uint64>(0);
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_uint64(value));
      value = false;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint64_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
#endif
    
    void test_method_(to_uint64_from_char16) {
      char16 value = u'a';
      assert::are_equal(97u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_char32) {
      char32 value = U'a';
      assert::are_equal(97u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint64(value));
      value = 0.0l;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.49;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.50;
      assert::are_equal(43u, convert::to_uint64(value));
      value = 0.0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint64(value));
      value = 0.0f;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_int16) {
      int16 value = 42;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_int32) {
      int32 value = 42;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_int64) {
      int64 value = 42l;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0l;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_llong) {
      slong value = 42ll;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0ll;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0u;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0u;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0lu;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42u, convert::to_uint64(value));
      value = 0llu;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_uint64_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = "0";
      assert::is_zero(convert::to_uint64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_string_with_base) {
      assert::are_equal(42u, convert::to_uint64("0b101010", 2));
      assert::are_equal(42u, convert::to_uint64(u8"052", 8));
      assert::are_equal(42u, convert::to_uint64(u"42", 10));
      assert::are_equal(42u, convert::to_uint64(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_uint64(L"42", 4);});
    }
    
    void test_method_(to_uint64_from_std_string) {
      std::string value = "42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = "0";
      assert::is_zero(convert::to_uint64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint64_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = u8"0";
      assert::is_zero(convert::to_uint64(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
#endif
    
    void test_method_(to_uint64_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = u"0";
      assert::is_zero(convert::to_uint64(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = U"0";
      assert::is_zero(convert::to_uint64(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = L"0";
      assert::is_zero(convert::to_uint64(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = "0";
      assert::is_zero(convert::to_uint64(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_uint64_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = u8"0";
      assert::is_zero(convert::to_uint64(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
#endif
    
    void test_method_(to_uint64_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = u"0";
      assert::is_zero(convert::to_uint64(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = U"0";
      assert::is_zero(convert::to_uint64(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42u, convert::to_uint64(value));
      value = L"0";
      assert::is_zero(convert::to_uint64(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_uint64(value);});
    }
    
    void test_method_(to_uint64_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint64(value));
      value = values::zero;
      assert::is_zero(convert::to_uint64(value));
    }
    
    void test_method_(to_ullong_from_any) {
      std::any value = static_cast<xtd::ulong>(42);
      assert::are_equal(42llu, convert::to_ullong(value));
      value = static_cast<xtd::ulong>(0);
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_any_failed) {
      std::any value = "not a byte";
      assert::throws<invalid_cast_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_bool) {
      bool value = true;
      assert::are_equal(1llu, convert::to_ullong(value));
      value = false;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_byte) {
      xtd::byte value = 42;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_char) {
      char value = 'a';
      assert::are_equal(97llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_ullong_from_char8) {
      char8 value = u8'a';
      assert::are_equal(97llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
#endif
    
    void test_method_(to_ullong_from_char16) {
      char16 value = u'a';
      assert::are_equal(97llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_char32) {
      char32 value = U'a';
      assert::are_equal(97llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_wchar) {
      wchar value = L'a';
      assert::are_equal(97llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_decimal) {
      decimal value = 42.0l;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 42.49l;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 42.50l;
      assert::are_equal(43llu, convert::to_ullong(value));
      value = 0.0l;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_double) {
      double value = 42.0;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 42.49;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 42.50;
      assert::are_equal(43llu, convert::to_ullong(value));
      value = 0.0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_ullong(value));
      value = 42.49f;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 42.50f;
      assert::are_equal(43llu, convert::to_ullong(value));
      value = 0.0f;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_int16) {
      int16 value = 42;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_int32) {
      int32 value = 42;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_int64) {
      int64 value = 42l;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0l;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_llong) {
      slong value = 42ll;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0ll;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_sbyte) {
      sbyte value = 42;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_uint16) {
      uint16 value = 42u;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0u;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_uint32) {
      uint32 value = 42u;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0u;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_uint64) {
      uint64 value = 42lu;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0lu;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_ullong) {
      xtd::ulong value = 42llu;
      assert::are_equal(42llu, convert::to_ullong(value));
      value = 0llu;
      assert::is_zero(convert::to_ullong(value));
    }
    
    void test_method_(to_ullong_from_string) {
      string value = "42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = "0";
      assert::is_zero(convert::to_ullong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_string_with_base) {
      assert::are_equal(42u, convert::to_ullong("0b101010", 2));
      assert::are_equal(42u, convert::to_ullong(u8"052", 8));
      assert::are_equal(42u, convert::to_ullong(u"42", 10));
      assert::are_equal(42u, convert::to_ullong(U"2A", 16));
      assert::throws<argument_exception>([&] {convert::to_ullong(L"42", 4);});
    }
    
    void test_method_(to_ullong_from_std_string) {
      std::string value = "42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = "0";
      assert::is_zero(convert::to_ullong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_ullong_from_u8string) {
      std::u8string value = u8"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = u8"0";
      assert::is_zero(convert::to_ullong(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
#endif
    
    void test_method_(to_ullong_from_u16string) {
      std::u16string value = u"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = u"0";
      assert::is_zero(convert::to_ullong(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_u32string) {
      std::u32string value = U"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = U"0";
      assert::is_zero(convert::to_ullong(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_wstring) {
      std::wstring value = L"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = L"0";
      assert::is_zero(convert::to_ullong(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = "0";
      assert::is_zero(convert::to_ullong(value));
      value = "bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(to_ullong_from_literal_char8) {
      const char8* value = u8"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = u8"0";
      assert::is_zero(convert::to_ullong(value));
      value = u8"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
#endif
    
    void test_method_(to_ullong_from_literal_char16) {
      const char16* value = u"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = u"0";
      assert::is_zero(convert::to_ullong(value));
      value = u"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_literal_char32) {
      const char32* value = U"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = U"0";
      assert::is_zero(convert::to_ullong(value));
      value = U"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_literal_wchar) {
      const wchar* value = L"42";
      assert::are_equal(42llu, convert::to_ullong(value));
      value = L"0";
      assert::is_zero(convert::to_ullong(value));
      value = L"bad value";
      assert::throws<format_exception>([&] {convert::to_ullong(value);});
    }
    
    void test_method_(to_ullong_from_values) {
      values value = values::two;
      assert::are_equal(2llu, convert::to_ullong(value));
      value = values::zero;
      assert::is_zero(convert::to_ullong(value));
    }
  };
}

