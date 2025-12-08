#include <xtd/format>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_wstring_string_tests) {
    auto test_method_(format_string_with_default_argument) {
      assert::are_equal(L"string", format(L"{0}", "string"));
    }
    
    auto test_method_(format_string_with_left_alignment) {
      assert::are_equal(L"    string", format(L"{0,10}", "string"));
    }
    
    auto test_method_(format_string_with_right_alignment) {
      assert::are_equal(L"string    ", format(L"{0, -10}", "string"));
    }
    
    auto test_method_(format_string_with_left_alignment_to_zero) {
      assert::are_equal(L"string", format(L"{0,0}", "string"));
    }
    
    auto test_method_(format_string_with_invalid_format) {
      assert::are_equal(L"string", format(L"{0:invalid}", "string"));
    }
    
    auto test_method_(format_string_with_decimal_format) {
      assert::are_equal(L"string", format(L"{0:D}", "string"));
    }
    
    auto test_method_(format_string_with_string) {
      assert::are_equal(L"string", format(L"{}", string("string")));
    }
    
    auto test_method_(format_string_with_u8string) {
      assert::are_equal(L"string", format(L"{}", u8string("string")));
    }
    
    auto test_method_(format_string_with_u16string) {
      assert::are_equal(L"string", format(L"{}", u16string("string")));
    }
    
    auto test_method_(format_string_with_u32string) {
      assert::are_equal(L"string", format(L"{}", u32string("string")));
    }
    
    auto test_method_(format_string_with_wstring) {
      assert::are_equal(L"string", format(L"{}", wstring("string")));
    }
    
    auto test_method_(format_string_with_std_string) {
      assert::are_equal(L"string", format(L"{}", std::string("string")));
    }
    
    auto test_method_(format_string_with_std_u8string) {
      assert::are_equal(L"string", format(L"{}", std::u8string(u8"string")));
    }
    
    auto test_method_(format_string_with_std_u16string) {
      assert::are_equal(L"string", format(L"{}", std::u16string(u"string")));
    }
    
    auto test_method_(format_string_with_std_u32string) {
      assert::are_equal(L"string", format(L"{}", std::u32string(U"string")));
    }
    
    auto test_method_(format_string_with_std_wstring) {
      assert::are_equal(L"string", format(L"{}", std::wstring(L"string")));
    }
  };
}
