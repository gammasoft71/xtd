#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_convert_string) {
  public:
    void test_method_(to_string) {
      collection_assert::are_equal({'a', 'e', 'i', 'o', 'u', '\xC3', '\xA0', '\xC3', '\xA7', '\xC3', '\xA9', '\xC3', '\xA8', '\xC3', '\xAA', '\xC3', '\xAB', '\xC3', '\xAF', '\xC3', '\xAE', '\xF0', '\x9F', '\x90', '\xA8'}, convert_string::to_string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
    }
    
    void test_method_(to_u8string) {
      // The following line does not build with Visual Studio 2019 (16.10.0)
      //collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', u8'\xC3', u8'\xA0', u8'\xC3', u8'\xA7', u8'\xC3', u8'\xA9', u8'\xC3', u8'\xA8', u8'\xC3', u8'\xAA', u8'\xC3', u8'\xAB', u8'\xC3', u8'\xAF', u8'\xC3', u8'\xAE', u8'\xF0', u8'\x9F', u8'\x90', u8'\xA8'}, strings::to_u8string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      collection_assert::are_equal({u8'a', u8'e', u8'i', u8'o', u8'u', static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA0), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA7), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA9), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xA8), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAA), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAB), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAF), static_cast<char8_t>(0xC3), static_cast<char8_t>(0xAE), static_cast<char8_t>(0xF0), static_cast<char8_t>(0x9F), static_cast<char8_t>(0x90), static_cast<char8_t>(0xA8)}, convert_string::to_u8string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
    }
    
    void test_method_(to_u16string) {
      collection_assert::are_equal({u'a', u'e', u'i', u'o', u'u', u'à', u'ç', u'é', u'è', u'ê', u'ë', u'ï', u'î', u'\xD87D', u'\xDC28'}, convert_string::to_u16string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
    }
    
    void test_method_(to_u32string) {
      collection_assert::are_equal({U'a', U'e', U'i', U'o', U'u', U'à', U'ç', U'é', U'è', U'ê', U'ë', U'ï', U'î', U'\x1F428'}, convert_string::to_u32string(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
    }
    
    void test_method_(to_wstring) {
      if (sizeof(wchar_t) > 2)
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0x1F428)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
      else
        collection_assert::are_equal({L'a', L'e', L'i', L'o', L'u', L'à', L'ç', L'é', L'è', L'ê', L'ë', L'ï', L'î', static_cast<wchar_t>(0xD87D), static_cast<wchar_t>(0xDC28)}, convert_string::to_wstring(u8"aeiouàçéèêëïî\U0001F428"), line_info_);
    }
  };
}
