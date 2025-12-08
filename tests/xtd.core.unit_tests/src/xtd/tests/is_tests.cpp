#include <xtd/is>
#include <xtd/globalization/translator>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(is_tests) {
    auto test_method_(is_string_with_string) {
      std::string v;
      assert::is_true(is<std::string>(v));
    }
    
    auto test_method_(is_string_without_string) {
      std::exception v;
      assert::is_false(is<std::string>(v));
    }
    
    auto test_method_(is_string_with_const_string) {
      assert::is_true(is<string>(""_s));
    }
    
    auto test_method_(is_string_without_const_string) {
      assert::is_false(is<std::string>(std::exception()));
    }
    
    auto test_method_(is_bool_with_bool) {
      bool v = true;
      assert::is_true(is<bool>(v));
    }
    
    auto test_method_(is_bool_without_bool) {
      int v = 42;
      assert::is_false(is<bool>(v));
    }
    
    auto test_method_(is_char_with_char) {
      char v = 'a';
      assert::is_true(is<char>(v));
    }
    
    auto test_method_(is_char_without_char) {
      int v = 42;
      assert::is_false(is<char>(v));
    }
    
    auto test_method_(is_char16_with_char) {
      char16 v = u'a';
      assert::is_true(is<char16>(v));
    }
    
    auto test_method_(is_char16_without_char) {
      int v = 42;
      assert::is_false(is<char16>(v));
    }
    
    auto test_method_(is_char32_with_char) {
      char32 v = U'a';
      assert::is_true(is<char32>(v));
    }
    
    auto test_method_(is_char32_without_char) {
      int v = 42;
      assert::is_false(is<char32>(v));
    }
    
    auto test_method_(is_char8_with_char) {
      char8 v = u8'a';
        assert::is_true(is<char8>(v));
      }
      
        auto test_method_(is_char8_without_char) {
        int v = 42;
        assert::is_false(is<char8>(v));
      }
      
        auto test_method_(is_wchar_with_char) {
        wchar v = L'a';
        assert::is_true(is<wchar>(v));
      }
      
        auto test_method_(is_wchar_without_char) {
        int v = 42;
        assert::is_false(is<wchar>(v));
      }
      
        auto test_method_(is_decimal_with_decimal) {
        decimal v = 4.2;
        assert::is_true(is<decimal>(v));
      }
      
        auto test_method_(is_decimal_without_decimal) {
        bool v = true;
        assert::is_false(is<decimal>(v));
      }
      
        auto test_method_(is_double_with_double) {
        double v = 4.2;
        assert::is_true(is<double>(v));
      }
      
        auto test_method_(is_double_without_double) {
        bool v = true;
        assert::is_false(is<double>(v));
      }
      
        auto test_method_(is_float_with_float) {
        float v = 4.2f;
        assert::is_true(is<float>(v));
      }
      
        auto test_method_(is_float_without_float) {
        bool v = true;
        assert::is_false(is<float>(v));
      }
      
        auto test_method_(is_int8_with_int8) {
        sbyte v = 42;
        assert::is_true(is<sbyte>(v));
      }
      
        auto test_method_(is_int8_without_int8) {
        bool v = true;
        assert::is_false(is<sbyte>(v));
      }
      
        auto test_method_(is_int16_with_int16) {
        int16 v = 42;
        assert::is_true(is<int16>(v));
      }
      
        auto test_method_(is_int16_without_int16) {
        bool v = true;
        assert::is_false(is<int16>(v));
      }
      
        auto test_method_(is_int32_with_int32) {
        int32 v = 42;
        assert::is_true(is<int32>(v));
      }
      
        auto test_method_(is_int32_without_int32) {
        bool v = true;
        assert::is_false(is<int32>(v));
      }
      
        auto test_method_(is_int64_with_int64) {
        int64 v = 42;
        assert::is_true(is<int64>(v));
      }
      
        auto test_method_(is_int64_without_int64) {
        bool v = true;
        assert::is_false(is<int64>(v));
      }
      
        auto test_method_(is_short_with_short) {
        short v = 42;
        assert::is_true(is<short>(v));
      }
      
        auto test_method_(is_short_without_short) {
        bool v = true;
        assert::is_false(is<short>(v));
      }
      
        auto test_method_(is_int_with_int) {
        int v = 42;
        assert::is_true(is<int>(v));
      }
      
        auto test_method_(is_int_without_int) {
        bool v = true;
        assert::is_false(is<int>(v));
      }
      
        auto test_method_(is_long_with_long) {
        long v = 42;
        assert::is_true(is<long>(v));
      }
      
        auto test_method_(is_long_without_long) {
        bool v = true;
        assert::is_false(is<long>(v));
      }
      
        auto test_method_(is_llong_with_llong) {
        slong v = 42;
        assert::is_true(is<slong>(v));
      }
      
        auto test_method_(is_llong_without_llong) {
        bool v = true;
        assert::is_false(is<slong>(v));
      }
      
        auto test_method_(is_uint8_with_uint8) {
        xtd::byte v = 42;
        assert::is_true(is<xtd::byte>(v));
      }
      
        auto test_method_(is_uint8_without_uint8) {
        bool v = true;
        assert::is_false(is<xtd::byte>(v));
      }
      
        auto test_method_(is_uint16_with_uint16) {
        uint16 v = 42;
        assert::is_true(is<uint16>(v));
      }
      
        auto test_method_(is_uint16_without_uint16) {
        bool v = true;
        assert::is_false(is<uint16>(v));
      }
      
        auto test_method_(is_uint32_with_uint32) {
        uint32 v = 42;
        assert::is_true(is<uint32>(v));
      }
      
        auto test_method_(is_uint32_without_uint32) {
        bool v = true;
        assert::is_false(is<uint32>(v));
      }
      
        auto test_method_(is_uint64_with_uint64) {
        uint64 v = 42;
        assert::is_true(is<uint64>(v));
      }
      
        auto test_method_(is_uint64_without_uint64) {
        bool v = true;
        assert::is_false(is<uint64>(v));
      }
      
        auto test_method_(is_unsigned_short_with_unsigned_short) {
        unsigned short v = 42;
        assert::is_true(is<unsigned short>(v));
      }
      
        auto test_method_(is_unsigned_short_without_unsigned_short) {
        bool v = true;
        assert::is_false(is<unsigned short>(v));
      }
      
        auto test_method_(is_unsigned_int_with_unsigned_int) {
        unsigned int v = 42;
        assert::is_true(is<unsigned int>(v));
      }
      
        auto test_method_(is_unsigned_int_without_unsigned_int) {
        bool v = true;
        assert::is_false(is<unsigned int>(v));
      }
      
        auto test_method_(is_ulong_with_unsigned_long) {
        unsigned long v = 42;
        assert::is_true(is<unsigned long>(v));
      }
      
        auto test_method_(is_ulong_without_unsigned_long) {
        bool v = true;
        assert::is_false(is<unsigned long>(v));
      }
      
        auto test_method_(is_ullong_with_ullong) {
        xtd::ulong v = 42;
        assert::is_true(is<xtd::ulong>(v));
      }
      
        auto test_method_(is_ullong_without_ullong) {
        bool v = true;
        assert::is_false(is<xtd::ulong>(v));
      }
      };
      }
      
      
