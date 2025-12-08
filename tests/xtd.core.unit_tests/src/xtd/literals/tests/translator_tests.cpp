#include <xtd/literals/translator.hpp>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(translator_tests) {
        static void class_initialize_(class_initialize) {
          translator::add_value("fr", "literals_translator_key1", "literals_translator_key1_fr");
        }
        
        auto test_method_(_t_operator_on_char_ptr) {
          translator::language("fr");
          assert::are_equal("literals_translator_key1_fr", "literals_translator_key1"_t);
        }
        
        auto test_method_(_t_operator_on_char8_ptr) {
          translator::language("fr");
          assert::are_equal("literals_translator_key1_fr", u8"literals_translator_key1"_t);
        }
        
        auto test_method_(_t_operator_on_char16_ptr) {
          translator::language("fr");
          assert::are_equal("literals_translator_key1_fr", u"literals_translator_key1"_t);
        }
        
        auto test_method_(_t_operator_on_char32_ptr) {
          translator::language("fr");
          assert::are_equal("literals_translator_key1_fr", U"literals_translator_key1"_t);
        }
        
        auto test_method_(_t_operator_on_wchar_ptr) {
          translator::language("fr");
          assert::are_equal("literals_translator_key1_fr", L"literals_translator_key1"_t);
        }
      };
    }
  }
}
