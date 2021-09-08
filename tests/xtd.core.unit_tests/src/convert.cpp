#include <xtd/convert.h>
#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_convert) {
  public:
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
  };
}
