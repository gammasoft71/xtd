/// @file
/// @brief Contains xtd::translator class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/specialized/string_dictionary.hpp"
#include "literals/translator.hpp"
#include "io/path.hpp"
#include "environment.hpp"
#include "optional.hpp"
#include "static.hpp"
#include "string.hpp"
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents translator class. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system translate
  /// @remarks This class is used to translate an application into different languages.
  /// @remarks For more information about internationalization, see [Internationalizations](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/internationalization).
  /// @par Examples
  /// The following shows how to use translator with std::locale method, litteral operator @c _t and translation files.
  /// @include translator.cpp
  /// @include /examples/xtd.forms.examples/components/translator/locale/ru/locale.strings
  class translator final static_ {
  public:
    /// @name Public Static Properties
    
    /// @{
    /// @brief Gets the current application language.
    /// @return The current application language.
    /// @remarks By default language is initialized with the current system language.
    static xtd::string language();
    /// @brief Sets the current application language.
    /// @param language The current application language.
    /// @remarks Normally you should use the std::locale() method. This function only exists if you have a good reason to bypass std::locale().
    /// @warning If you set the language with this method, and you use the std::locale method afterwards, translator will use the language initialized with this method and not with std::locale().
    static void language(const xtd::string& language);
    /// @brief Sets the current application language.
    /// @param language The current application language.
    /// @remarks Normally you should use the std::locale() method. This function only exists if you have a good reason to bypass std::locale().
    /// @warning If you set the language with this method, and you use the std::locale method afterwards, translator will use the language initialized with this method and not with std::locale().
    static void language(xtd::null_ptr);
    
    /// @brief Gets an array of languages supported by the application.
    /// @return An array of languages supported by the application.
    static xtd::array<xtd::string> languages();
    
    /// @brief Gets the current system language.
    /// @return The current system language.
    static xtd::string system_language();
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Manually adds a translation for a specified key and language.
    /// @param language The language of the key to be translated.
    /// @param key The key to be translated.
    /// @parama value The translation of the key for the specified language.
    /// @warning This method should not be used. The translation is normally done automatically. This method is present only if you want to make an instant translation on a very small number of keys. It would not be wise to translate an entire application into different languages with this method.
    static void add_value(const xtd::string& language, const xtd::string& key, const xtd::string& value) {
      auto language_name  = to_language_name(language);
      if (!xtd::io::directory::exists(xtd::io::path::combine(application_locale_path(), language_name))) language_name = to_fallback_name(language_name);
      if (load_language(language_name)) languages_[language_name] = language_name;
      language_values_[languages_[language_name]][key] = value;
    }
    
    /// @brief Parses a specified path that contains translations.
    /// @param locale_path Path that contains translations.
    /// @return `true` if parse succeed; otherwhise `false`.
    /// @remarks parse path with xtd::translator::language() language.
    static bool parse_locale(const xtd::string& locale_path);
    
    /// @brief Parses a specified path that contains translations.
    /// @param locale_path Path that contains translations.
    /// @return `true` if parse succeed; otherwhise `false`.
    static bool parse_locale(const xtd::string& locale_path, const xtd::string& language);
    
    /// @brief Parses a specified file that contains translations for a specified language.
    /// @param file The file that contains translations.
    /// @return `true` if parse succeed; otherwhise `false`.
    /// @remarks parse file with xtd::translator::language() language.
    static bool parse_file(const xtd::string& file);
    
    /// @brief Parses a specified file that contains translations for a specified language.
    /// @param file The file that contains translations.
    /// @param language The language of the translation file.
    /// @return `true` if parse succeed; otherwhise `false`.
    static bool parse_file(const xtd::string& file, const xtd::string& language);
    
    /// @brief Translates a string into the lganguage specified by the xtd::translate::language property.
    /// @return The translated string.
    /// @remarks If no translation is found, the result is the same as the value.
    static xtd::string translate(const xtd::string& value) noexcept {return translate(language(), value);}
    /// @brief Translates a string into the specified lganguage.
    /// @return The translated string.
    /// @param language The language used to translate the value
    /// @remarks If no translation is found, the result is the same as the value.
    static xtd::string translate(const xtd::string& language, const xtd::string& value) noexcept {return translate(language, value.chars().c_str());}
    /// @}
    
    /// @cond
    static const char* translate(const char* value) noexcept {return translate(language(), value);}
    static const char* translate(const xtd::string& language, const char* value) noexcept {
      auto language_name  = to_language_name(language);
      if (!xtd::io::directory::exists(xtd::io::path::combine(application_locale_path(), language_name))) language_name = to_fallback_name(language_name);
      if (!load_language(language_name)) return value;
      if (!language_values_[languages_[language_name]].contains_key(value)) return value;
      return language_values_[languages_[language_name]][value].c_str();
    }
    /// @endcond
    
  private:
    static string application_locale_path() {return xtd::io::path::combine(xtd::environment::get_folder_path(environment::special_folder::application_resources), "locale");}
    static string xtd_locale_path() {return environment::get_folder_path(xtd::environment::special_folder::xtd_locale);}
    static bool load_language(const xtd::string& language) {return load_language(language, xtd_locale_path(), application_locale_path());}
    static bool load_language(const xtd::string& language, const xtd::string& xtd_locale_path, const xtd::string& application_locale_path);
    static string to_language_name(const xtd::string& language);
    static string to_fallback_name(const xtd::string& language);
    static xtd::collections::generic::dictionary<xtd::string, xtd::collections::specialized::string_dictionary> language_values_;
    static xtd::collections::specialized::string_dictionary languages_;
    static xtd::optional<xtd::string> language_;
  };
}

/// @cond
// The following method implementation are defined in xtd/literals/translater.hpp
inline const char* xtd::literals::operator""_t(const char* s, xtd::size n) noexcept {
  return xtd::translator::translate(s);
}

inline xtd::string xtd::literals::operator""_t(const char8* s, xtd::size n) noexcept {
  return xtd::translator::translate(xtd::u8string(s, s + n));
}

inline xtd::string xtd::literals::operator""_t(const char16* s, xtd::size n) noexcept {
  return xtd::translator::translate(xtd::u16string(s, s + n));
}

inline xtd::string xtd::literals::operator""_t(const char32* s, xtd::size n) noexcept {
  return xtd::translator::translate(xtd::u32string(s, s + n));
}

inline xtd::string xtd::literals::operator""_t(const wchar* s, xtd::size n) noexcept {
  return xtd::translator::translate(xtd::wstring(s, s + n));
}
/// @endcond
