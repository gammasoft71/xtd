#include <xtd/ustring>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_string_format_tests) {
    void test_method_(format_string_with_default_argument) {
      assert::are_equal("string", ustring::format("{0}", "string"), csf_);
    }
    
    void test_method_(format_string_with_left_alignment) {
      assert::are_equal("    string", ustring::format("{0,10}", "string"), csf_);
    }
    
    void test_method_(format_string_with_right_alignment) {
      assert::are_equal("string    ", ustring::format("{0, -10}", "string"), csf_);
    }
    
    void test_method_(format_string_with_left_alignment_to_zero) {
      assert::are_equal("string", ustring::format("{0,0}", "string"), csf_);
    }
    
    void test_method_(format_string_with_invalid_format) {
      assert::are_equal("string", ustring::format("{0:invalid}", "string"), csf_);
    }
    
    void test_method_(format_string_with_decimal_format) {
      assert::are_equal("string", ustring::format("{0:D}", "string"), csf_);
    }
    
    void test_method_(format_string_with_string) {
      assert::are_equal("string", ustring::format("{}", std::string("string")), csf_);
    }
    
    void test_method_(format_string_with_ustring) {
      assert::are_equal("string", ustring::format("{}", ustring("string")), csf_);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(format_string_with_u8string) {
      assert::are_equal("string", ustring::format("{}", std::u8string(u8"string")), csf_);
    }
#endif
    
    void test_method_(format_string_with_u16string) {
      assert::are_equal("string", ustring::format("{}", std::u16string(u"string")), csf_);
    }
    
    void test_method_(format_string_with_u32string) {
      assert::are_equal("string", ustring::format("{}", std::u32string(U"string")), csf_);
    }
    
    void test_method_(format_string_with_wstring) {
      assert::are_equal("string", ustring::format("{}", std::wstring(L"string")), csf_);
    }
  };
}
