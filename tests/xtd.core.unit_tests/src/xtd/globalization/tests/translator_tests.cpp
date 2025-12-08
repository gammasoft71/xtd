#include <xtd/globalization/translator>
#include <xtd/globalization/culture_info>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd {
  namespace globalization {
    namespace tests {
      class test_class_(translator_tests) {
        static void class_initialize_(class_initialize) {
          translator::add_value("fr", "globalization_translator_key1", "globalization_translator_key1_fr");
        }
        
        static void test_cleanup_(test_cleanup) {
          translator::language(null);
        }
        
        auto test_method_(language) {
          assert::are_equal(culture_info::current_culture().name().replace("-", "_"), translator::language());
        }
        
        auto test_method_(language_with_fr) {
          translator::language("fr");
          assert::are_equal("fr", translator::language());
        }
        
        auto test_method_(language_with_fr_FR) {
          translator::language("fr-FR");
          assert::are_equal("fr_FR", translator::language());
        }
        
        auto test_method_(language_with_fr_FR2) {
          translator::language("fr_FR");
          assert::are_equal("fr_FR", translator::language());
        }
        
        auto test_method_(language_with_empty) {
          assert::throws<argument_exception>([] {translator::language("");});
        }
        
        auto test_method_(language_with_invalid_char) {
          assert::throws<argument_exception>([] {translator::language("(fr");});
          assert::throws<argument_exception>([] {translator::language("fr)");});
          assert::throws<argument_exception>([] {translator::language("1fr");});
          assert::throws<argument_exception>([] {translator::language("fr1");});
          assert::throws<argument_exception>([] {translator::language(" fr");});
          assert::throws<argument_exception>([] {translator::language("fr ");});
        }
        
        auto test_method_(language_with_null) {
        }
        
        auto test_method_(languages) {
          collection_assert::contains({"fr"_s}, translator::languages());
        }
        
        auto test_method_(system_language) {
          assert::are_equal(culture_info::current_culture().name().replace("-", "_"), translator::system_language());
          translator::language("fr");
          assert::are_equal(culture_info::current_culture().name().replace("-", "_"), translator::system_language());
        }
        
        auto test_method_(translate_with_char_ptr) {
          translator::language("fr");
          assert::are_equal("globalization_translator_key1_fr", translator::translate("globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_language_and_char_ptr) {
          assert::are_equal("globalization_translator_key1_fr", translator::translate("fr", "globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_char8_ptr) {
          translator::language("fr");
          assert::are_equal("globalization_translator_key1_fr", translator::translate(u8"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_language_and_char8_ptr) {
          assert::are_equal("globalization_translator_key1_fr", translator::translate("fr", u8"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_char16_ptr) {
          translator::language("fr");
          assert::are_equal("globalization_translator_key1_fr", translator::translate(u"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_language_and_char16_ptr) {
          assert::are_equal("globalization_translator_key1_fr", translator::translate("fr", u"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_char32_ptr) {
          translator::language("fr");
          assert::are_equal("globalization_translator_key1_fr", translator::translate(U"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_language_and_char32_ptr) {
          assert::are_equal("globalization_translator_key1_fr", translator::translate("fr", U"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_wchar_ptr) {
          translator::language("fr");
          assert::are_equal("globalization_translator_key1_fr", translator::translate(L"globalization_translator_key1"));
        }
        
        auto test_method_(translate_with_language_and_wchar_ptr) {
          assert::are_equal("globalization_translator_key1_fr", translator::translate("fr", L"globalization_translator_key1"));
        }
      };
    }
  }
}
