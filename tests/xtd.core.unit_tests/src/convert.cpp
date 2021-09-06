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
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_char8) {
      char8_t value = u8'a';
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_char16) {
      char16_t value = u'a';
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
    }

    void test_method_(to_boolean_from_char32) {
      char32_t value = U'a';
      assert::is_true(convert::to_boolean(value), csf_);
      value = 0;
      assert::is_false(convert::to_boolean(value), csf_);
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
  };
}
