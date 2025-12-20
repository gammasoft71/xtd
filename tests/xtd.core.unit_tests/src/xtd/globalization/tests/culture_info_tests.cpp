#include <xtd/globalization/culture_info>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd::globalization::tests {
  class test_class_(culture_info_tests) {
    inline static culture_info current_ulture_;
    
    static void test_initialize_(test_initialize) {
      current_ulture_ = culture_info::current_culture();
    }
    
    static void test_cleanup_(test_cleanup) {
      culture_info::current_culture(current_ulture_);
    }
    
    auto test_method_(create_default) {
      auto culture = culture_info {};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal(std::locale {""}, culture.locale());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(create_with_valid_lcid_and_valid_locale) {
      auto culture = culture_info {1033_z};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(create_with_valid_lcid_and_invalid_locale) {
      auto culture = culture_info {77_z};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Assamese", culture.display_name());
      assert::are_equal("Assamese", culture.english_name());
      assert::is_false(culture.is_locale_available());
      assert::are_equal(77_z, culture.keyboard_layout_id());
      assert::are_equal(77_z, culture.lcid());
      assert::are_equal(std::locale {"C"}, culture.locale());
      assert::are_equal("as", culture.name());
      assert::are_equal("অসমীয়া", culture.native_name());
    }
    
    auto test_method_(create_with_empty_string) {
      auto culture = culture_info {""};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal(std::locale {""}, culture.locale());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(create_with_valid_string_and_valid_locale) {
      auto culture = culture_info {"en-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(create_with_valid_string_and_invalid_locale) {
      auto culture = culture_info {"agq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Aghem", culture.display_name());
      assert::are_equal("Aghem", culture.english_name());
      assert::is_false(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal(std::locale {"C"}, culture.locale());
      assert::are_equal("agq", culture.name());
      assert::are_equal("Aghem", culture.native_name());
    }
    
    auto test_method_(create_with_lower_case_string) {
      auto culture = culture_info {"en-us"};
      assert::are_equal("en-US", culture.name());
    }
    
    auto test_method_(create_with_upper_case_string) {
      auto culture = culture_info {"EN-US"};
      assert::are_equal("en-US", culture.name());
    }
    
    auto test_method_(create_with_invalid_string) {
      assert::throws<culture_not_found_exception>(delegate_ {culture_info {"en-USS"};});
    }
    
    auto test_method_(create_with_valid_locale) {
      auto culture = culture_info {std::locale {"en_US.UTF-8"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(create_with_empty_locale) {
      // In Linux the std::locale {""}.name() return "en_US.UTF-8" instead ""
      if (environment::os_version().is_linux()) assert::ignore();
      auto culture = culture_info {std::locale {""}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal(std::locale {""}, culture.locale());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(create_with_c_locale) {
      auto culture = culture_info {std::locale {"C"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(create_with_posix_locale) {
      // In Windows the std::locale {"POSIX"} does not work
      if (environment::os_version().is_windows()) assert::ignore();
      auto culture = culture_info {std::locale {"POSIX"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(create_with_invalid_locale) {
      assert::throws<std::runtime_error>(delegate_ {culture_info {std::locale {"en_USS.UTF-8"}};});
    }
    
    auto test_method_(current_culture) {
      if (environment::get_environment_variable("CI") == "true") return;
      auto culture = culture_info::current_culture();
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {xtd::native::culture_info::current_locale_name()}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(set_current_culture_with_valid_culture_info_and_valid_locale) {
      culture_info::current_culture(culture_info {"en-US"});
      auto culture = culture_info::current_culture();
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.UTF-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(set_current_culture_with_valid_culture_info_and_empty_locale) {
      // In Linux the std::locale {""}.name() return "en_US.UTF-8" instead ""
      if (environment::os_version().is_linux()) assert::ignore();
      culture_info::current_culture(culture_info {""});
      auto culture = culture_info::current_culture();
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal(std::locale {""}, culture.locale());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(set_current_culture_with_valid_culture_info_and_invalid_locale) {
      culture_info::current_culture(culture_info {"agq"});
      auto culture = culture_info::current_culture();
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Aghem", culture.display_name());
      assert::are_equal("Aghem", culture.english_name());
      assert::is_false(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal(std::locale {"C"}, culture.locale());
      assert::are_equal("agq", culture.name());
      assert::are_equal("Aghem", culture.native_name());
    }
    
    auto test_method_(invariant_culture) {
      auto culture = culture_info::invariant_culture();
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal(std::locale {""}, culture.locale());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(equals) {
      auto c1 = culture_info {"fr-BE"};
      auto c2 = culture_info {"fr-CH"};
      auto c3 = culture_info {"fr-BE"};
      auto c4 = culture_info {"fr-CH"};
      
      assert::is_true(c1.equals(c1));
      assert::is_false(c1.equals(c2));
      assert::is_true(c1.equals(c3));
      assert::is_false(c1.equals(c4));
      
      assert::is_false(c2.equals(c1));
      assert::is_true(c2.equals(c2));
      assert::is_false(c2.equals(c3));
      assert::is_true(c2.equals(c4));
      
      assert::is_true(c3.equals(c1));
      assert::is_false(c3.equals(c2));
      assert::is_true(c3.equals(c3));
      assert::is_false(c3.equals(c4));
      
      assert::is_false(c4.equals(c1));
      assert::is_true(c4.equals(c2));
      assert::is_false(c4.equals(c3));
      assert::is_true(c4.equals(c4));
    }
    
    auto test_method_(equals_with_object) {
      auto c1 = culture_info {"fr-BE"};
      auto c2 = culture_info {"fr-CH"};
      auto c3 = culture_info {"fr-BE"};
      auto c4 = culture_info {"fr-CH"};
      auto& o1 = c1;
      auto& o2 = c2;
      auto& o3 = c3;
      auto& o4 = c4;
      
      assert::is_true(c1.equals(o1));
      assert::is_false(c1.equals(o2));
      assert::is_true(c1.equals(o3));
      assert::is_false(c1.equals(o4));
      
      assert::is_false(c2.equals(o1));
      assert::is_true(c2.equals(o2));
      assert::is_false(c2.equals(o3));
      assert::is_true(c2.equals(o4));
      
      assert::is_true(c3.equals(o1));
      assert::is_false(c3.equals(o2));
      assert::is_true(c3.equals(o3));
      assert::is_false(c3.equals(o4));
      
      assert::is_false(c4.equals(o1));
      assert::is_true(c4.equals(o2));
      assert::is_false(c4.equals(o3));
      assert::is_true(c4.equals(o4));
    }
    
    auto test_method_(to_string) {
      assert::are_equal("en-US", culture_info {"en-US"}.to_string());
      assert::are_equal("fr-BE", culture_info {"fr-be"}.to_string());
      assert::are_equal("zh-Hans-CN", culture_info {"ZH-HANS-CN"}.to_string());
      assert::are_equal("", culture_info {""}.to_string());
    }
    
    auto test_method_(get_cultures_wth_all_cultures) {
      assert::are_equal(1035_z, culture_info::get_cultures(xtd::globalization::culture_types::all_cultures).length());
      assert::is_true(culture_info::get_cultures(xtd::globalization::culture_types::all_cultures).contains(culture_info {"en-US"}));
      assert::is_true(culture_info::get_cultures(xtd::globalization::culture_types::all_cultures).contains(culture_info {"agq"}));
    }
    
    auto test_method_(get_cultures_wth_specific_cultures) {
      assert::are_equal(706_z, culture_info::get_cultures(xtd::globalization::culture_types::specific_cultures).length());
      assert::is_true(culture_info::get_cultures(xtd::globalization::culture_types::specific_cultures).contains(culture_info {"en-US"}));
      assert::is_false(culture_info::get_cultures(xtd::globalization::culture_types::specific_cultures).contains(culture_info {"agq"}));
    }
    
    auto test_method_(get_cultures_wth_neutral_cultures) {
      assert::are_equal(329_z, culture_info::get_cultures(xtd::globalization::culture_types::neutral_cultures).length());
      assert::is_false(culture_info::get_cultures(xtd::globalization::culture_types::neutral_cultures).contains(culture_info {"en-US"}));
      assert::is_true(culture_info::get_cultures(xtd::globalization::culture_types::neutral_cultures).contains(culture_info {"agq"}));
    }
    
    auto test_method_(get_cultures_wth_installed_win32_cultures) {
      assert::are_equal(0_z, culture_info::get_cultures(xtd::globalization::culture_types::installed_win32_cultures).length());
      assert::is_false(culture_info::get_cultures(xtd::globalization::culture_types::installed_win32_cultures).contains(culture_info {"en-US"}));
      assert::is_false(culture_info::get_cultures(xtd::globalization::culture_types::installed_win32_cultures).contains(culture_info {"agq"}));
    }
  };
}
