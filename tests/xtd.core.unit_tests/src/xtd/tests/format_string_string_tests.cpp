#include <xtd/format>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(format_string_string_tests) {
    void test_method_(format_string_with_default_argument) {
      assert::are_equal("string", format("{0}", "string"));
    }
    
    void test_method_(format_string_with_left_alignment) {
      assert::are_equal("    string", format("{0,10}", "string"));
    }
    
    void test_method_(format_string_with_right_alignment) {
      assert::are_equal("string    ", format("{0, -10}", "string"));
    }
    
    void test_method_(format_string_with_left_alignment_to_zero) {
      assert::are_equal("string", format("{0,0}", "string"));
    }
    
    void test_method_(format_string_with_invalid_format) {
      assert::are_equal("string", format("{0:invalid}", "string"));
    }
    
    void test_method_(format_string_with_decimal_format) {
      assert::are_equal("string", format("{0:D}", "string"));
    }
    
    void test_method_(format_string_with_string) {
      assert::are_equal("string", format("{}", string("string")));
    }
    
    void test_method_(format_string_with_u8string) {
      assert::are_equal("string", format("{}", u8string("string")));
    }
    
    void test_method_(format_string_with_u16string) {
      assert::are_equal("string", format("{}", u16string("string")));
    }
    
    void test_method_(format_string_with_u32string) {
      assert::are_equal("string", format("{}", u32string("string")));
    }
    
    void test_method_(format_string_with_wstring) {
      assert::are_equal("string", format("{}", wstring("string")));
    }
    
    void test_method_(format_string_with_std_string) {
      assert::are_equal("string", format("{}", std::string("string")));
    }
    
    void test_method_(format_string_with_std_u8string) {
      assert::are_equal("string", format("{}", std::u8string(u8"string")));
    }
    
    void test_method_(format_string_with_std_u16string) {
      assert::are_equal("string", format("{}", std::u16string(u"string")));
    }
    
    void test_method_(format_string_with_std_u32string) {
      assert::are_equal("string", format("{}", std::u32string(U"string")));
    }
    
    void test_method_(format_string_with_std_wstring) {
      assert::are_equal("string", format("{}", std::wstring(L"string")));
    }
  };
}
