#include <xtd/globalization/culture_info>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd::globalization::tests {
  class test_class_(culture_info_tests) {
    inline static std::locale current_locale_;
    static void test_initialize_(test_initialize) {
      current_locale_ = std::locale {};
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(current_locale_);
    }
    
    void test_method_(create_default) {
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

    void test_method_(create_with_valid_lcid_and_valid_locale) {
      auto culture = culture_info {1033_z};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    void test_method_(create_with_valid_lcid_and_invalid_locale) {
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

    void test_method_(create_with_empty_string) {
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

    void test_method_(create_with_valid_string_and_valid_locale) {
      auto culture = culture_info {"en-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }

    void test_method_(create_with_valid_string_and_invalid_locale) {
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

    void test_method_(create_with_lower_case_string) {
      auto culture = culture_info {"en-us"};
      assert::are_equal("en-US", culture.name());
    }

    void test_method_(create_with_upper_case_string) {
      auto culture = culture_info {"EN-US"};
      assert::are_equal("en-US", culture.name());
    }

    void test_method_(create_with_invalid_string) {
      assert::throws<culture_not_found_exception>(delegate_ {culture_info {"en-USS"};});
    }

    void test_method_(create_with_valid_locale) {
      auto culture = culture_info {std::locale {"en_US.utf-8"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }

    void test_method_(create_with_empty_locale) {
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

    void test_method_(create_with_c_locale) {
      auto culture = culture_info {std::locale {"C"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }

    void test_method_(create_with_posix_locale) {
      auto culture = culture_info {std::locale {"POSIX"}};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }

    void test_method_(create_with_invalid_locale) {
      assert::throws<std::runtime_error>(delegate_ {culture_info {std::locale {"en_USS.utf-8"}};});
    }

    void test_method_(current_culture) {
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
    
    void test_method_(set_current_culture_with_valid_culture_info_and_valid_locale) {
      culture_info::current_culture(culture_info {"en-US"});
      auto culture = culture_info::current_culture();
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::is_true(culture.is_locale_available());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal(std::locale {"en_US.utf-8"}, culture.locale());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    void test_method_(set_current_culture_with_valid_culture_info_and_empty_locale) {
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
    
    void test_method_(set_current_culture_with_valid_culture_info_and_invalid_locale) {
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
  };
}
