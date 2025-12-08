#include <xtd/convert_string>
#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(convert_string_tests) {
    auto test_method_(literal_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string("aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u8_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u8"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u16_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u32_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(U"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_wide_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(L"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(std::string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u8string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u8string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u16string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u16string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u32string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u32string_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(wstring_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_wstring_to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string("aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u8_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(u8"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u16_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(u"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u32_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(U"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_wide_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(L"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(std::string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u8string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u16string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u32string_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(wstring_to_u8string) {
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8>(0xC3), static_cast<char8>(0xA0), static_cast<char8>(0xC3), static_cast<char8>(0xA7), static_cast<char8>(0xC3), static_cast<char8>(0xA9), static_cast<char8>(0xC3), static_cast<char8>(0xA8), static_cast<char8>(0xC3), static_cast<char8>(0xAA), static_cast<char8>(0xC3), static_cast<char8>(0xAB), static_cast<char8>(0xC3), static_cast<char8>(0xAF), static_cast<char8>(0xC3), static_cast<char8>(0xAE), static_cast<char8>(0xF0), static_cast<char8>(0x9F), static_cast<char8>(0x90), static_cast<char8>(0xA8)}, convert_string::to_u8string(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string("aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u8_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u8"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u16_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u32_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(U"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_wide_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(L"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(std::string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u8string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u8string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u16string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u16string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u32string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u32string_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(wstring_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_wstring_to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD83D', u'\xDC28'}, convert_string::to_u16string(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string("aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u8_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u8"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u16_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_u32_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(U"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_wide_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(L"aeiouàçéèêëïî\U0001F428"));
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(std::string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u8string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u16string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u16string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u32string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u32string_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(wstring_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_wstring_to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(literal_to_wstring) {
      if (sizeof(wchar) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring("aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring("aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(const_cast<char*>("aeiouàçéèêëïî\U0001F428")));
      }
    }
    
    auto test_method_(literal_u8_to_wstring) {
      if (sizeof(wchar) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(const_cast<char8*>(u8"aeiouàçéèêëïî\U0001F428")));
      }
    }
    
    auto test_method_(literal_u16_to_wstring) {
      if (sizeof(wchar) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(u"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(u"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(const_cast<char16*>(u"aeiouàçéèêëïî\U0001F428")));
      }
    }
    
    auto test_method_(literal_u32_to_wstring) {
      if (sizeof(wchar) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(U"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(U"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(const_cast<char32*>(U"aeiouàçéèêëïî\U0001F428")));
      }
    }
    
    auto test_method_(literal_wide_to_wstring) {
      if (sizeof(wchar) > 2) {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(L"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
      } else {
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(L"aeiouàçéèêëïî\U0001F428"));
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(const_cast<wchar*>(L"aeiouàçéèêëïî\U0001F428")));
      }
    }
    
    auto test_method_(string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(string("aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(std::string("aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(std::string("aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u8string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(u8string(u8"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u8string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(std::u8string(u8"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u16string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(u16string(u"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u16string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(std::u16string(u"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(u32string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(u32string(U"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_u32string_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(std::u32string(U"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(wstring_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(wstring(L"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
    
    auto test_method_(std_wstring_to_wstring) {
      if (sizeof(wchar) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0x1F428)}, convert_string::to_wstring(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar>(0xD83D), static_cast<wchar>(0xDC28)}, convert_string::to_wstring(std::wstring(L"aeiouàçéèêëïî\U0001F428")));
    }
  };
}
