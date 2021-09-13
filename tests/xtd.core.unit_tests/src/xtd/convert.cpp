#include <xtd/convert.h>
#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_convert) {
    enum class values {
      zero,
      one,
      two
    };
    
  public:
    void test_method_(to_any_from_any) {
      any value = 42;
      assert::are_equal(42, any_cast<int>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_bool) {
      bool value = true;
      assert::is_true(any_cast<bool>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_byte) {
      byte_t value = 42;
      assert::are_equal(42u, any_cast<byte_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_char) {
      char value = 'a';
      assert::are_equal('a', any_cast<char>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_char8) {
      char8_t value = u8'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_any(value);}, csf_);
    }
    
    void test_method_(to_any_from_char16) {
      char16_t value = u'a';
      assert::are_equal(u'a', any_cast<char16_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_char32) {
      char32_t value = U'a';
      assert::are_equal(U'a', any_cast<char32_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(L'a', any_cast<wchar_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42.0l, any_cast<decimal_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_double) {
      double value = 42.0;
      assert::are_equal(42.0, any_cast<double>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0f, any_cast<float>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_int16) {
      int16_t value = 42;
      assert::are_equal(42, any_cast<int16_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_int32) {
      int32_t value = 42;
      assert::are_equal(42, any_cast<int32_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42l, any_cast<int64_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42ll, any_cast<llong_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42, any_cast<sbyte_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42u, any_cast<uint16_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42u, any_cast<uint32_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42lu, any_cast<uint64_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42llu, any_cast<ullong_t>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_ustring) {
      ustring value = "42";
      assert::are_equal("42", any_cast<ustring>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_string) {
      string value = "42";
      assert::are_equal("42", any_cast<string>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(u8"42", any_cast<u8string>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_u16string) {
      u16string value = u"42";
      assert::are_equal(u"42", any_cast<u16string>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_u32string) {
      u32string value = U"42";
      assert::are_equal(U"42", any_cast<u32string>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_wstring) {
      wstring value = L"42";
      assert::are_equal(L"42", any_cast<wstring>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_literal_char) {
      const char* value = "42";
      assert::are_equal("42", any_cast<const char*>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::throws<invalid_cast_exception>([&]{convert::to_any(value);}, csf_);
    }
    
    void test_method_(to_any_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(u"42", any_cast<const char16_t*>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(U"42", any_cast<const char32_t*>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(L"42", any_cast<const wchar_t*>(convert::to_any(value)), csf_);
    }
    
    void test_method_(to_any_from_values) {
      values value = values::two;
      assert::are_equal(values::two, any_cast<values>(convert::to_any(value)), csf_);
    }

    void test_method_(to_boolean_from_any) {
      any value = true;
      assert::is_true(convert::to_boolean(value), csf_);
      value = false;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_any_failed) {
      any value = "not a bool";
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_bool) {
      bool value = true;
      assert::is_true(convert::to_boolean(value), csf_);
      value = false;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_byte) {
      byte_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_char) {
      char value = 'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_char8) {
      char8_t value = u8'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_char16) {
      char16_t value = u'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_char32) {
      char32_t value = U'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_wchar) {
      wchar_t value = L'a';
      assert::throws<invalid_cast_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_decimal) {
      decimal_t value = 0.42l;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0.0l;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_double) {
      double value = 0.42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0.0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_float) {
      double value = 0.42f;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0.0f;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_int16) {
      int16_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_int32) {
      int32_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_int64) {
      int64_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_llong) {
      llong_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_sbyte) {
      sbyte_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_uint16) {
      uint16_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }
    
    void test_method_(to_boolean_from_uint32) {
      uint32_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }
    
    void test_method_(to_boolean_from_uint64) {
      uint64_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }
    
    void test_method_(to_boolean_from_ullong) {
      ullong_t value = 42;
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }
    
    void test_method_(to_boolean_from_ustring) {
      ustring value = "true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = "false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }
    
    void test_method_(to_boolean_from_string) {
      string value = "true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = "false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }
    
    void test_method_(to_boolean_from_u8string) {
      u8string value = u8"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = u8"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }
    
    void test_method_(to_boolean_from_u16string) {
      u16string value = u"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = u"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }
    
    void test_method_(to_boolean_from_u32string) {
      u32string value = U"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = U"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_wstring) {
      wstring value = L"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = L"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_literal_char) {
      const char* value = "true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = "false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_literal_char8) {
      const char8_t* value = u8"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = u8"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_literal_char16) {
      const char16_t* value = u"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = u"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_literal_char32) {
      const char32_t* value = U"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = U"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_literal_wchar) {
      const wchar_t* value = L"true";
      assert::is_true(convert::to_boolean(value), csf_);
      value = L"false";
      assert::is_false(convert::to_boolean(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_boolean(value);}, csf_);
    }

    void test_method_(to_boolean_from_values) {
      values value = values::two;
      assert::is_true(convert::to_boolean(value), csf_);
      value = values::zero;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_byte_from_any) {
      any value = static_cast<byte_t>(42);
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = static_cast<byte_t>(0);
      assert::is_zero(convert::to_byte(value), csf_);
    }
    
    void test_method_(to_byte_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_byte(value), csf_);
      value = false;
      assert::is_zero(convert::to_byte(value), csf_);
    }
    
    void test_method_(to_byte_from_byte) {
      byte_t value = 42;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
    }
    
    void test_method_(to_byte_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
    }
    
    void test_method_(to_byte_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
    }
    
    void test_method_(to_byte_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = u'\u01FF';
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = L'\x01FF';
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.49l;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.50l;
      assert::are_equal(43u, convert::to_byte(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256.0l;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.49;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.50;
      assert::are_equal(43u, convert::to_byte(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256.0;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.49f;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 42.50f;
      assert::are_equal(43u, convert::to_byte(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256.0f;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_int16) {
      int16_t value = 42;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_int32) {
      int32_t value = 42;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256l;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
      value = 256ll;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_byte(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_byte(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_byte(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_byte(value), csf_);
      value = 256lu;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_byte(value), csf_);
      value = 256llu;
      assert::throws<overflow_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_ustring) {
      ustring value = "42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_ustring_with_base) {
      assert::are_equal(42u, convert::to_byte("0b101010", 2), csf_);
      assert::are_equal(42u, convert::to_byte(u8"052", 8), csf_);
      assert::are_equal(42u, convert::to_byte(u"42", 10), csf_);
      assert::are_equal(42u, convert::to_byte(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_byte(L"42", 4);}, csf_);
    }

    void test_method_(to_byte_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }

    void test_method_(to_byte_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }
    
    void test_method_(to_byte_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42u, convert::to_byte(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_byte(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_byte(value);}, csf_);
    }

    void test_method_(to_byte_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_byte(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_byte(value), csf_);
    }

    void test_method_(to_char_from_any) {
      any value = 'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = '\0';
      assert::is_zero(convert::to_char(value), csf_);
    }
    
    void test_method_(to_char_from_any_failed) {
      any value = "not a char";
      assert::throws<invalid_cast_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_byte) {
      byte_t value = 97;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
    }
    
    void test_method_(to_char_from_char) {
      char value = 'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
    }
    
    void test_method_(to_char_from_char8) {
      char8_t value = u8'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
    }
    
    void test_method_(to_char_from_char16) {
      char16_t value = u'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = u'\u01FF';
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_char32) {
      char32_t value = U'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = L'\x01FF';
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_decimal) {
      decimal_t value = 97.0l;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.49l;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.50l;
      assert::are_equal('b', convert::to_char(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_char(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256.0l;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_double) {
      double value = 97.0;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.49;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.50;
      assert::are_equal('b', convert::to_char(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_char(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256.0;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_float) {
      float value = 97.0f;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.49f;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 97.50f;
      assert::are_equal('b', convert::to_char(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_char(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256.0f;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_int16) {
      int16_t value = 97;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_int32) {
      int32_t value = 97;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_int64) {
      int64_t value = 97l;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_char(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256l;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_llong) {
      llong_t value = 97ll;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_char(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
      value = 256ll;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_sbyte) {
      sbyte_t value = 97;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_uint16) {
      uint16_t value = 97u;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_uint32) {
      uint32_t value = 97u;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_uint64) {
      uint64_t value = 97lu;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_char(value), csf_);
      value = 256lu;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_ullong) {
      ullong_t value = 97llu;
      assert::are_equal('a', convert::to_char(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_char(value), csf_);
      value = 256llu;
      assert::throws<overflow_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_ustring) {
      ustring value = "a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_string) {
      string value = "a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_u8string) {
      u8string value = u8"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_u16string) {
      u16string value = u"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_u32string) {
      u32string value = U"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_wstring) {
      wstring value = L"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_literal_char) {
      const char* value = "a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_literal_char8) {
      const char8_t* value = u8"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_literal_char16) {
      const char16_t* value = u"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_literal_char32) {
      const char32_t* value = U"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }
    
    void test_method_(to_char_from_literal_wchar) {
      const wchar_t* value = L"a";
      assert::are_equal('a', convert::to_char(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char(value);}, csf_);
    }

    void test_method_(to_char_from_values) {
      values value = values::two;
      assert::are_equal('\2', convert::to_char(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_char(value), csf_);
    }

    void test_method_(to_char8_from_any) {
      // Cannot build on macOS: any with char8_t does not link!
      //any value = u8'a';
      //assert::throws<invalid_cast_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_any_failed) {
      any value = "not a char";
      assert::throws<invalid_cast_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_byte) {
      byte_t value = 97;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
    }
    
    void test_method_(to_char8_from_char) {
      char value = 'a';
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
    }
    
    void test_method_(to_char8_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
    }
    
    void test_method_(to_char8_from_char16) {
      char16_t value = u'a';
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = u'\u01FF';
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_char32) {
      char32_t value = U'a';
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = U'\U000001FF';
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = L'\x01FF';
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_decimal) {
      decimal_t value = 97.0l;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.49l;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.50l;
      assert::are_equal(u8'b', convert::to_char8(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256.0l;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_double) {
      double value = 97.0;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.49;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.50;
      assert::are_equal(u8'b', convert::to_char8(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256.0;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_float) {
      float value = 97.0f;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.49f;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 97.50f;
      assert::are_equal(u8'b', convert::to_char8(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256.0f;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_int16) {
      int16_t value = 97;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_int32) {
      int32_t value = 97;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_int64) {
      int64_t value = 97l;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256l;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_llong) {
      llong_t value = 97ll;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
      value = 256ll;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_sbyte) {
      sbyte_t value = 97;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char8(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_uint16) {
      uint16_t value = 97u;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char8(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_uint32) {
      uint32_t value = 97u;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char8(value), csf_);
      value = 256u;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_uint64) {
      uint64_t value = 97lu;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_char8(value), csf_);
      value = 256lu;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_ullong) {
      ullong_t value = 97llu;
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_char8(value), csf_);
      value = 256llu;
      assert::throws<overflow_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_ustring) {
      ustring value = "a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_string) {
      string value = "a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_u8string) {
      u8string value = u8"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_u16string) {
      u16string value = u"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_u32string) {
      u32string value = U"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_wstring) {
      wstring value = L"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_literal_char) {
      const char* value = "a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_literal_char8) {
      const char8_t* value = u8"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_literal_char16) {
      const char16_t* value = u"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_literal_char32) {
      const char32_t* value = U"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }
    
    void test_method_(to_char8_from_literal_wchar) {
      const wchar_t* value = L"a";
      assert::are_equal(u8'a', convert::to_char8(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char8(value);}, csf_);
    }

    void test_method_(to_char8_from_values) {
      values value = values::two;
      assert::are_equal(u8'\2', convert::to_char8(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_char8(value), csf_);
    }

    void test_method_(to_char16_from_any) {
      any value = u'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = u'\0';
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_any_failed) {
      any value = "not a char";
      assert::throws<invalid_cast_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_byte) {
      byte_t value = 97;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_char) {
      char value = 'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_char16) {
      char16_t value = u'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_char32) {
      char32_t value = U'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_decimal) {
      decimal_t value = 97.0l;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.49l;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.50l;
      assert::are_equal(u'b', convert::to_char16(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536.0l;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_double) {
      double value = 97.0;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.49;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.50;
      assert::are_equal(u'b', convert::to_char16(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536.0;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_float) {
      float value = 97.0f;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.49f;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 97.50f;
      assert::are_equal(u'b', convert::to_char16(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536.0f;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_int16) {
      int16_t value = 97;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_int32) {
      int32_t value = 97;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_int64) {
      int64_t value = 97l;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536l;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_llong) {
      llong_t value = 97ll;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
      value = 65536ll;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_sbyte) {
      sbyte_t value = 97;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char16(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_uint16) {
      uint16_t value = 97u;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char16(value), csf_);
    }
    
    void test_method_(to_char16_from_uint32) {
      uint32_t value = 97u;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char16(value), csf_);
      value = 65536u;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_uint64) {
      uint64_t value = 97lu;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_char16(value), csf_);
      value = 65536lu;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_ullong) {
      ullong_t value = 97llu;
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_char16(value), csf_);
      value = 65536llu;
      assert::throws<overflow_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_ustring) {
      ustring value = "a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_string) {
      string value = "a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_u8string) {
      u8string value = u8"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_u16string) {
      u16string value = u"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_u32string) {
      u32string value = U"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_wstring) {
      wstring value = L"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_literal_char) {
      const char* value = "a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_literal_char8) {
      const char8_t* value = u8"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_literal_char16) {
      const char16_t* value = u"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_literal_char32) {
      const char32_t* value = U"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }
    
    void test_method_(to_char16_from_literal_wchar) {
      const wchar_t* value = L"a";
      assert::are_equal(u'a', convert::to_char16(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char16(value);}, csf_);
    }

    void test_method_(to_char16_from_values) {
      values value = values::two;
      assert::are_equal(u'\2', convert::to_char16(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_char16(value), csf_);
    }

    void test_method_(to_char32_from_any) {
      any value = U'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = U'\0';
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_any_failed) {
      any value = "not a char";
      assert::throws<invalid_cast_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_byte) {
      byte_t value = 97;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_char) {
      char value = 'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_char16) {
      char16_t value = u'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_char32) {
      char32_t value = U'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_decimal) {
      decimal_t value = 97.0l;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.49l;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.50l;
      assert::are_equal(U'b', convert::to_char32(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
      value = 4294967296.0l;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_double) {
      double value = 97.0;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.49;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.50;
      assert::are_equal(U'b', convert::to_char32(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
      value = 4294967296.0;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_float) {
      float value = 97.0f;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.49f;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 97.50f;
      assert::are_equal(U'b', convert::to_char32(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_int16) {
      int16_t value = 97;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_int32) {
      int32_t value = 97;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_int64) {
      int64_t value = 97l;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
      value = 4294967296l;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_llong) {
      llong_t value = 97ll;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_sbyte) {
      sbyte_t value = 97;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_char32(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_uint16) {
      uint16_t value = 97u;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_uint32) {
      uint32_t value = 97u;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_uint64) {
      uint64_t value = 97lu;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_char32(value), csf_);
      value = 4294967296lu;
      assert::throws<overflow_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_ullong) {
      ullong_t value = 97llu;
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_char32(value), csf_);
    }
    
    void test_method_(to_char32_from_ustring) {
      ustring value = "a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_string) {
      string value = "a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_u8string) {
      u8string value = u8"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_u16string) {
      u16string value = u"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_u32string) {
      u32string value = U"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_wstring) {
      wstring value = L"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_literal_char) {
      const char* value = "a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_literal_char8) {
      const char8_t* value = u8"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_literal_char16) {
      const char16_t* value = u"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_literal_char32) {
      const char32_t* value = U"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }
    
    void test_method_(to_char32_from_literal_wchar) {
      const wchar_t* value = L"a";
      assert::are_equal(U'a', convert::to_char32(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_char32(value);}, csf_);
    }

    void test_method_(to_char32_from_values) {
      values value = values::two;
      assert::are_equal(U'\2', convert::to_char32(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_char32(value), csf_);
    }

    void test_method_(to_wchar_from_any) {
      any value = L'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = L'\0';
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_any_failed) {
      any value = "not a char";
      assert::throws<invalid_cast_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_bool) {
      bool value = true;
      assert::throws<invalid_cast_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_byte) {
      byte_t value = 97;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_char) {
      char value = 'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_char16) {
      char16_t value = u'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_char32) {
      char32_t value = U'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_decimal) {
      decimal_t value = 97.0l;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.49l;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.50l;
      assert::are_equal(L'b', convert::to_wchar(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -0.1l;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536.0l;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_double) {
      double value = 97.0;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.49;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.50;
      assert::are_equal(L'b', convert::to_wchar(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -0.1;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536.0;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_float) {
      float value = 97.0f;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.49f;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 97.50f;
      assert::are_equal(L'b', convert::to_wchar(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -0.1f;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536.0f;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_int16) {
      int16_t value = 97;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_int32) {
      int32_t value = 97;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_int64) {
      int64_t value = 97l;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -1l;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536l;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_llong) {
      llong_t value = 97ll;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -1ll;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
      value = 65536ll;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_sbyte) {
      sbyte_t value = 97;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = -1;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_uint16) {
      uint16_t value = 97u;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_wchar(value), csf_);
    }
    
    void test_method_(to_wchar_from_uint32) {
      uint32_t value = 97u;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = 65536u;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_uint64) {
      uint64_t value = 97lu;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = 65536lu;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_ullong) {
      ullong_t value = 97llu;
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_wchar(value), csf_);
      value = 65536llu;
      assert::throws<overflow_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_ustring) {
      ustring value = "a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_string) {
      string value = "a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_u8string) {
      u8string value = u8"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_u16string) {
      u16string value = u"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_u32string) {
      u32string value = U"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_wstring) {
      wstring value = L"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_literal_char) {
      const char* value = "a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = "ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_literal_char8) {
      const char8_t* value = u8"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = u8"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_literal_char16) {
      const char16_t* value = u"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = u"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_literal_char32) {
      const char32_t* value = U"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = U"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }
    
    void test_method_(to_wchar_from_literal_wchar) {
      const wchar_t* value = L"a";
      assert::are_equal(L'a', convert::to_wchar(value), csf_);
      value = L"ab";
      assert::throws<format_exception>([&]{convert::to_wchar(value);}, csf_);
    }

    void test_method_(to_wchar_from_values) {
      values value = values::two;
      assert::are_equal(L'\2', convert::to_wchar(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_wchar(value), csf_);
    }

    void test_method_(to_decimal_from_any) {
      any value = 42.0l;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_bool) {
      bool value = true;
      assert::are_equal(1.0l, convert::to_decimal(value), csf_);
      value = false;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_byte) {
      byte_t value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_char) {
      char value = 'a';
      assert::are_equal(97.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_double) {
      double value = 42.0;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);

    }
    
    void test_method_(to_decimal_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_int16) {
      int16_t value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_int32) {
      int32_t value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = 0;
      assert::is_zero(convert::to_decimal(value), csf_);
    }
    
    void test_method_(to_decimal_from_ustring) {
      ustring value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = "0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_string) {
      string value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = "0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_u8string) {
      u8string value = u8"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_u16string) {
      u16string value = u"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_u32string) {
      u32string value = U"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_wstring) {
      wstring value = L"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = "0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_literal_char8) {
      const char8_t* value = u8"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_literal_char16) {
      const char16_t* value = u"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_literal_char32) {
      const char32_t* value = U"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_literal_wchar) {
      const wchar_t* value = L"42.0";
      assert::are_equal(42.0l, convert::to_decimal(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_decimal(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_decimal(value);}, csf_);
    }
    
    void test_method_(to_decimal_from_values) {
      values value = values::two;
      assert::are_equal(2.0l, convert::to_decimal(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_decimal(value), csf_);
    }

    void test_method_(to_double_from_any) {
      any value = 42.0;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_bool) {
      bool value = true;
      assert::are_equal(1.0, convert::to_double(value), csf_);
      value = false;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_byte) {
      byte_t value = 42;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_char) {
      char value = 'a';
      assert::are_equal(97.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_double) {
      double value = 42.0;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
      
    }
    
    void test_method_(to_double_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_int16) {
      int16_t value = 42;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_int32) {
      int32_t value = 42;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = 0;
      assert::is_zero(convert::to_double(value), csf_);
    }
    
    void test_method_(to_double_from_ustring) {
      ustring value = "42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = "0";
      assert::is_zero(convert::to_double(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_string) {
      string value = "42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = "0";
      assert::is_zero(convert::to_double(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_u8string) {
      u8string value = u8"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_u16string) {
      u16string value = u"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_u32string) {
      u32string value = U"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_wstring) {
      wstring value = L"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = "0";
      assert::is_zero(convert::to_double(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_literal_char8) {
      const char8_t* value = u8"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_literal_char16) {
      const char16_t* value = u"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_literal_char32) {
      const char32_t* value = U"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_literal_wchar) {
      const wchar_t* value = L"42.0";
      assert::are_equal(42.0, convert::to_double(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_double(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_double(value);}, csf_);
    }
    
    void test_method_(to_double_from_values) {
      values value = values::two;
      assert::are_equal(2.0, convert::to_double(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_double(value), csf_);
    }

    void test_method_(to_single_from_any) {
      any value = 42.0f;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_bool) {
      bool value = true;
      assert::are_equal(1.0f, convert::to_single(value), csf_);
      value = false;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_byte) {
      byte_t value = 42;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_char) {
      char value = 'a';
      assert::are_equal(97.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_double) {
      double value = 42.0;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
      
    }
    
    void test_method_(to_single_from_float) {
      float value = 42.0f;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_int16) {
      int16_t value = 42;
      assert::are_equal(42.0, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_int32) {
      int32_t value = 42;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = 0;
      assert::is_zero(convert::to_single(value), csf_);
    }
    
    void test_method_(to_single_from_ustring) {
      ustring value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = "0";
      assert::is_zero(convert::to_single(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_string) {
      string value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = "0";
      assert::is_zero(convert::to_single(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_u8string) {
      u8string value = u8"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_u16string) {
      u16string value = u"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_u32string) {
      u32string value = U"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_wstring) {
      wstring value = L"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_literal_char) {
      const char* value = "42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = "0";
      assert::is_zero(convert::to_single(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_literal_char8) {
      const char8_t* value = u8"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_literal_char16) {
      const char16_t* value = u"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_literal_char32) {
      const char32_t* value = U"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_literal_wchar) {
      const wchar_t* value = L"42.0";
      assert::are_equal(42.0f, convert::to_single(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_single(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_single(value);}, csf_);
    }
    
    void test_method_(to_single_from_values) {
      values value = values::two;
      assert::are_equal(2.0f, convert::to_single(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_single(value), csf_);
    }

    void test_method_(to_int16_from_any) {
      any value = static_cast<int16_t>(42);
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = static_cast<int16_t>(0);
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_int16(value), csf_);
      value = false;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_byte) {
      byte_t value = 42;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.49l;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.50l;
      assert::are_equal(43, convert::to_int16(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768.0l;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.49;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.50;
      assert::are_equal(43, convert::to_int16(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768.0;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.49f;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 42.50f;
      assert::are_equal(43, convert::to_int16(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768.0f;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_int16) {
      int16_t value = 42;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_int32) {
      int32_t value = 42;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768l;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768ll;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int16(value), csf_);
    }
    
    void test_method_(to_int16_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768u;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768u;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768lu;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_int16(value), csf_);
      value = 32768llu;
      assert::throws<overflow_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_ustring) {
      ustring value = "42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_ustring_with_base) {
      assert::are_equal(42, convert::to_int16("0b101010", 2), csf_);
      assert::are_equal(42, convert::to_int16(u8"052", 8), csf_);
      assert::are_equal(42, convert::to_int16(u"42", 10), csf_);
      assert::are_equal(42, convert::to_int16(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_int16(L"42", 4);}, csf_);
    }

    void test_method_(to_int16_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42, convert::to_int16(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int16(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int16(value);}, csf_);
    }
    
    void test_method_(to_int16_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_int16(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_int16(value), csf_);
    }

    void test_method_(to_int32_from_any) {
      any value = static_cast<int32_t>(42);
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = static_cast<int32_t>(0);
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_int32(value), csf_);
      value = false;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_byte) {
      byte_t value = 42;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.49l;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.50l;
      assert::are_equal(43, convert::to_int32(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648.0l;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.49;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.50;
      assert::are_equal(43, convert::to_int32(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648.0;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.49f;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 42.50f;
      assert::are_equal(43, convert::to_int32(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_int16) {
      int16_t value = 42;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_int32) {
      int32_t value = 42;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648l;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int32(value), csf_);
    }
    
    void test_method_(to_int32_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648u;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648lu;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_int32(value), csf_);
      value = 2147483648llu;
      assert::throws<overflow_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_ustring) {
      ustring value = "42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_ustring_with_base) {
      assert::are_equal(42, convert::to_int32("0b101010", 2), csf_);
      assert::are_equal(42, convert::to_int32(u8"052", 8), csf_);
      assert::are_equal(42, convert::to_int32(u"42", 10), csf_);
      assert::are_equal(42, convert::to_int32(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_int32(L"42", 4);}, csf_);
    }

    void test_method_(to_int32_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42, convert::to_int32(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int32(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int32(value);}, csf_);
    }
    
    void test_method_(to_int32_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_int32(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_int32(value), csf_);
    }

    void test_method_(to_int64_from_any) {
      any value = static_cast<int64_t>(42);
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = static_cast<int64_t>(0);
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_bool) {
      bool value = true;
      assert::are_equal(1l, convert::to_int64(value), csf_);
      value = false;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_byte) {
      byte_t value = 42;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_char) {
      char value = 'a';
      assert::are_equal(97l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.49l;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.50l;
      assert::are_equal(43l, convert::to_int64(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_double) {
      double value = 42.0;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.49;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.50;
      assert::are_equal(43l, convert::to_int64(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_float) {
      float value = 42.0f;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.49f;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 42.50f;
      assert::are_equal(43l, convert::to_int64(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_int16) {
      int16_t value = 42;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_int32) {
      int32_t value = 42;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_int64(value), csf_);
      value = 9223372036854775808lu;
      assert::throws<overflow_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_int64(value), csf_);
    }
    
    void test_method_(to_int64_from_ustring) {
      ustring value = "42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_ustring_with_base) {
      assert::are_equal(42, convert::to_int64("0b101010", 2), csf_);
      assert::are_equal(42, convert::to_int64(u8"052", 8), csf_);
      assert::are_equal(42, convert::to_int64(u"42", 10), csf_);
      assert::are_equal(42, convert::to_int64(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_int64(L"42", 4);}, csf_);
    }

    void test_method_(to_int64_from_string) {
      string value = "42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42l, convert::to_int64(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_int64(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_int64(value);}, csf_);
    }
    
    void test_method_(to_int64_from_values) {
      values value = values::two;
      assert::are_equal(2l, convert::to_int64(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_int64(value), csf_);
    }

    void test_method_(to_llong_from_any) {
      any value = static_cast<llong_t>(42ll);
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = static_cast<llong_t>(0ll);
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_bool) {
      bool value = true;
      assert::are_equal(1ll, convert::to_llong(value), csf_);
      value = false;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_byte) {
      byte_t value = 42;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_char) {
      char value = 'a';
      assert::are_equal(97ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.49l;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.50l;
      assert::are_equal(43ll, convert::to_llong(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_double) {
      double value = 42.0;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.49;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.50;
      assert::are_equal(43ll, convert::to_llong(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_float) {
      float value = 42.0f;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.49f;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 42.50f;
      assert::are_equal(43ll, convert::to_llong(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_int16) {
      int16_t value = 42;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_int32) {
      int32_t value = 42;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_llong(value), csf_);
      value = 9223372036854775808lu;
      assert::throws<overflow_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_llong(value), csf_);
    }
    
    void test_method_(to_llong_from_ustring) {
      ustring value = "42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_ustring_with_base) {
      assert::are_equal(42, convert::to_llong("0b101010", 2), csf_);
      assert::are_equal(42, convert::to_llong(u8"052", 8), csf_);
      assert::are_equal(42, convert::to_llong(u"42", 10), csf_);
      assert::are_equal(42, convert::to_llong(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_llong(L"42", 4);}, csf_);
    }

    void test_method_(to_llong_from_string) {
      string value = "42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42ll, convert::to_llong(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_llong(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_llong(value);}, csf_);
    }
    
    void test_method_(to_llong_from_values) {
      values value = values::two;
      assert::are_equal(2ll, convert::to_llong(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_llong(value), csf_);
    }

    void test_method_(to_sbyte_from_any) {
      any value = static_cast<sbyte_t>(42);
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = static_cast<sbyte_t>(0);
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_sbyte(value), csf_);
      value = false;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_byte) {
      byte_t value = 42;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_char) {
      char value = 'a';
      assert::are_equal(97, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = u'\u0080';
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = U'\U00000080';
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = L'\x0080';
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.49l;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.50l;
      assert::are_equal(43, convert::to_sbyte(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128.0l;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_double) {
      double value = 42.0;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.49;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.50;
      assert::are_equal(43, convert::to_sbyte(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128.0;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_float) {
      float value = 42.0f;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.49f;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 42.50f;
      assert::are_equal(43, convert::to_sbyte(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128.0f;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_int16) {
      int16_t value = 42;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_int32) {
      int32_t value = 42;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128l;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128ll;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }
    
    void test_method_(to_sbyte_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128u;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128u;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128lu;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = 128llu;
      assert::throws<overflow_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_ustring) {
      ustring value = "42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_ustring_with_base) {
      assert::are_equal(42, convert::to_sbyte("0b101010", 2), csf_);
      assert::are_equal(42, convert::to_sbyte(u8"052", 8), csf_);
      assert::are_equal(42, convert::to_sbyte(u"42", 10), csf_);
      assert::are_equal(42, convert::to_sbyte(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_sbyte(L"42", 4);}, csf_);
    }

    void test_method_(to_sbyte_from_string) {
      string value = "42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = "0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42, convert::to_sbyte(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_sbyte(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_sbyte(value);}, csf_);
    }
    
    void test_method_(to_sbyte_from_values) {
      values value = values::two;
      assert::are_equal(2, convert::to_sbyte(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_sbyte(value), csf_);
    }

    void test_method_(to_uint16_from_any) {
      any value = static_cast<uint16_t>(42);
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = static_cast<uint16_t>(0);
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_bool) {
      bool value = true;
      assert::are_equal(1, convert::to_uint16(value), csf_);
      value = false;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_byte) {
      byte_t value = 42;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = U'\U0001FFFF';
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint16(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536.0l;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.49;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.50;
      assert::are_equal(43u, convert::to_uint16(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536.0;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint16(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536.0f;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_int16) {
      int16_t value = 42;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_int32) {
      int32_t value = 42;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536ll;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint16(value), csf_);
    }
    
    void test_method_(to_uint16_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536u;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536lu;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_uint16(value), csf_);
      value = 65536llu;
      assert::throws<overflow_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_ustring) {
      ustring value = "42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_ustring_with_base) {
      assert::are_equal(42u, convert::to_uint16("0b101010", 2), csf_);
      assert::are_equal(42u, convert::to_uint16(u8"052", 8), csf_);
      assert::are_equal(42u, convert::to_uint16(u"42", 10), csf_);
      assert::are_equal(42u, convert::to_uint16(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_uint16(L"42", 4);}, csf_);
    }

    void test_method_(to_uint16_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42u, convert::to_uint16(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint16(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint16(value);}, csf_);
    }
    
    void test_method_(to_uint16_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint16(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_uint16(value), csf_);
    }

    void test_method_(to_uint32_from_any) {
      any value = static_cast<uint32_t>(42);
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = static_cast<uint32_t>(0);
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_uint32(value), csf_);
      value = false;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_byte) {
      byte_t value = 42;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint32(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_uint32(value), csf_);
      value = 4294967296.0l;
      assert::throws<overflow_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.49;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.50;
      assert::are_equal(43u, convert::to_uint32(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_uint32(value), csf_);
      value = 4294967296.0;
      assert::throws<overflow_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint32(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_int16) {
      int16_t value = 42;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_int32) {
      int32_t value = 42;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_uint32(value), csf_);
      value = 4294967296;
      assert::throws<overflow_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_uint32(value), csf_);
      value = 4294967296lu;
      assert::throws<overflow_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_uint32(value), csf_);
    }
    
    void test_method_(to_uint32_from_ustring) {
      ustring value = "42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_ustring_with_base) {
      assert::are_equal(42u, convert::to_uint32("0b101010", 2), csf_);
      assert::are_equal(42u, convert::to_uint32(u8"052", 8), csf_);
      assert::are_equal(42u, convert::to_uint32(u"42", 10), csf_);
      assert::are_equal(42u, convert::to_uint32(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_uint32(L"42", 4);}, csf_);
    }

    void test_method_(to_uint32_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42u, convert::to_uint32(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint32(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint32(value);}, csf_);
    }
    
    void test_method_(to_uint32_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint32(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_uint32(value), csf_);
    }

    void test_method_(to_uint64_from_any) {
      any value = static_cast<uint64_t>(42);
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = static_cast<uint64_t>(0);
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_bool) {
      bool value = true;
      assert::are_equal(1u, convert::to_uint64(value), csf_);
      value = false;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_byte) {
      byte_t value = 42;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_char) {
      char value = 'a';
      assert::are_equal(97u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.49l;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.50l;
      assert::are_equal(43u, convert::to_uint64(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_double) {
      double value = 42.0;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.49;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.50;
      assert::are_equal(43u, convert::to_uint64(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.49f;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 42.50f;
      assert::are_equal(43u, convert::to_uint64(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_int16) {
      int16_t value = 42;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_int32) {
      int32_t value = 42;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_uint64(value), csf_);
    }
    
    void test_method_(to_uint64_from_ustring) {
      ustring value = "42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_ustring_with_base) {
      assert::are_equal(42u, convert::to_uint64("0b101010", 2), csf_);
      assert::are_equal(42u, convert::to_uint64(u8"052", 8), csf_);
      assert::are_equal(42u, convert::to_uint64(u"42", 10), csf_);
      assert::are_equal(42u, convert::to_uint64(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_uint64(L"42", 4);}, csf_);
    }

    void test_method_(to_uint64_from_string) {
      string value = "42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = "0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42u, convert::to_uint64(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_uint64(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_uint64(value);}, csf_);
    }
    
    void test_method_(to_uint64_from_values) {
      values value = values::two;
      assert::are_equal(2u, convert::to_uint64(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_uint64(value), csf_);
    }

    void test_method_(to_ullong_from_any) {
      any value = static_cast<ullong_t>(42);
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = static_cast<ullong_t>(0);
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_any_failed) {
      any value = "not a byte";
      assert::throws<invalid_cast_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_bool) {
      bool value = true;
      assert::are_equal(1llu, convert::to_ullong(value), csf_);
      value = false;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_byte) {
      byte_t value = 42;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_char) {
      char value = 'a';
      assert::are_equal(97llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_char8) {
      char8_t value = u8'a';
      assert::are_equal(97llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_char16) {
      char16_t value = u'a';
      assert::are_equal(97llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_char32) {
      char32_t value = U'a';
      assert::are_equal(97llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_wchar) {
      wchar_t value = L'a';
      assert::are_equal(97llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_decimal) {
      decimal_t value = 42.0l;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 42.49l;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 42.50l;
      assert::are_equal(43llu, convert::to_ullong(value), csf_);
      value = 0.0l;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_double) {
      double value = 42.0;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 42.49;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 42.50;
      assert::are_equal(43llu, convert::to_ullong(value), csf_);
      value = 0.0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_float) {
      float value = 42.0f;
      assert::are_equal(42u, convert::to_ullong(value), csf_);
      value = 42.49f;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 42.50f;
      assert::are_equal(43llu, convert::to_ullong(value), csf_);
      value = 0.0f;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_int16) {
      int16_t value = 42;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_int32) {
      int32_t value = 42;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_int64) {
      int64_t value = 42l;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0l;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_llong) {
      llong_t value = 42ll;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0ll;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_sbyte) {
      sbyte_t value = 42;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_uint16) {
      uint16_t value = 42u;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_uint32) {
      uint32_t value = 42u;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0u;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_uint64) {
      uint64_t value = 42lu;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0lu;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_ullong) {
      ullong_t value = 42llu;
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = 0llu;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
    
    void test_method_(to_ullong_from_ustring) {
      ustring value = "42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_ustring_with_base) {
      assert::are_equal(42u, convert::to_ullong("0b101010", 2), csf_);
      assert::are_equal(42u, convert::to_ullong(u8"052", 8), csf_);
      assert::are_equal(42u, convert::to_ullong(u"42", 10), csf_);
      assert::are_equal(42u, convert::to_ullong(U"2A", 16), csf_);
      assert::throws<argument_exception>([&]{convert::to_ullong(L"42", 4);}, csf_);
    }

    void test_method_(to_ullong_from_string) {
      string value = "42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_u8string) {
      u8string value = u8"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_u16string) {
      u16string value = u"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_u32string) {
      u32string value = U"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_wstring) {
      wstring value = L"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_literal_char) {
      const char* value = "42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = "0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = "bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_literal_char8) {
      const char8_t* value = u8"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = u8"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = u8"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_literal_char16) {
      const char16_t* value = u"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = u"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = u"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_literal_char32) {
      const char32_t* value = U"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = U"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = U"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_literal_wchar) {
      const wchar_t* value = L"42";
      assert::are_equal(42llu, convert::to_ullong(value), csf_);
      value = L"0";
      assert::is_zero(convert::to_ullong(value), csf_);
      value = L"bad value";
      assert::throws<argument_exception>([&]{convert::to_ullong(value);}, csf_);
    }
    
    void test_method_(to_ullong_from_values) {
      values value = values::two;
      assert::are_equal(2llu, convert::to_ullong(value), csf_);
      value = values::zero;
      assert::is_zero(convert::to_ullong(value), csf_);
    }
  };
}
