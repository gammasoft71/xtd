#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_convert_string) {
  public:
    void test_method_(literal_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string("aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u8_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u16_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u32_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(U"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_wide_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(L"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(ustring_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }

    void test_method_(literal_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring("aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u8_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u16_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(u"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u32_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(U"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_wide_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(L"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(ustring_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_ustring) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_ustring(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string("aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u8_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u16_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u32_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(U"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_wide_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(L"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(ustring_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string("aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u8_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u16_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u32_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(U"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_wide_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(L"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(ustring_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string("aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u8_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u16_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_u32_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(U"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_wide_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(L"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(ustring_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(literal_to_wstring) {
      if (sizeof(wchar_t) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring("aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring("aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(const_cast<char*>("aeiouàçéèêëïî\U0001F428")), line_info_);
      }
    }
    
    void test_method_(literal_u8_to_wstring) {
      if (sizeof(wchar_t) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(const_cast<char8_t*>(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
      }
    }
    
    void test_method_(literal_u16_to_wstring) {
      if (sizeof(wchar_t) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(const_cast<char16_t*>(u"aeiouàçéèêëïî\U0001F428")), line_info_);
      }
    }
    
    void test_method_(literal_u32_to_wstring) {
      if (sizeof(wchar_t) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(U"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(U"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(const_cast<char32_t*>(U"aeiouàçéèêëïî\U0001F428")), line_info_);
      }
    }
    
    void test_method_(literal_wide_to_wstring) {
      if (sizeof(wchar_t) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(L"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(L"aeiouàçéèêëïî\U0001F428"), line_info_);
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(const_cast<wchar_t*>(L"aeiouàçéèêëïî\U0001F428")), line_info_);
      }
    }
    
    void test_method_(ustring_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(ustring("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(string_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(string("aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(string("aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u8string_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u8string(u8"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u16string_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u16string(u"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(u32string_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u32string(U"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
    
    void test_method_(wstring_to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD83D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(wstring(L"aeiouàçéèêëïî\U0001F428")), line_info_);
    }
  };
}
