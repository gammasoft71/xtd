/// @file
/// @brief Contains xtd::translator class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "collections/specialized/string_dictionary.hpp"
#include "static.hpp"
#include "string.hpp"
#include <string>
#include <map>
#include <set>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents translator class. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system translate
  /// @remarks This class is used to translate an application into different languages.
  /// @remarks For more information about internationalization, see [Internationalizations](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/internationalization).
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

    /// @brief Gets the global locale.
    /// @return The global locale.
    /// @remarks is same a call `std::locale {};`
    static std::locale locale();
    /// @brief Sets the global locale.
    /// @param value The global locale.
    /// @remarks is same a call `std::locale::global(std::locale {value});`
    static void locale(const xtd::string& value);
    /// @brief Sets the global locale.
    /// @param value The global locale.
    /// @remarks is same a call `std::locale::global(value);`
    static void locale(const std::locale& value);

    /// @brief Gets an array of languages supported by the application.
    /// @return An array of languages supported by the application.
    static std::vector<xtd::string> languages();
    
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
    static void add_value(const xtd::string& language, const xtd::string& key, const xtd::string& value);
    
    /// @brief Parses a specified path that contains translations.
    /// @param locale_path Path that contains translations.
    static void parse_locale(const xtd::string& locale_path);
    
    /// @brief Parses a specified file that contains translations for a specified language.
    /// @param file The file that contains translations.
    /// @param language The language of the translation file.
    static void parse_file(const xtd::string& file, const xtd::string& language);
    
    /// @brief Translates a string into the lganguage specified by the xtd::translate::language property.
    /// @return The translated string.
    /// @remarks If no translation is found, the result is the same as the value.
    static xtd::string translate(const xtd::string& value) noexcept;
    /// @brief Translates a string into the specified lganguage.
    /// @return The translated string.
    /// @param language The language used to translate the value
    /// @remarks If no translation is found, the result is the same as the value.
    static xtd::string translate(const xtd::string& language, const xtd::string& value) noexcept;
    /// @}
    
    /// @cond
    static const char* translate(const char* value) noexcept;
    static const char* translate(const xtd::string& language, const char* value) noexcept;
    /// @endcond
    
  private:
    static void initialize();
    static xtd::string locale_to_language(xtd::string locale);
    static std::map<xtd::string, xtd::collections::specialized::string_dictionary> language_values_;
    static xtd::string language_;
    static std::set<string> translated_languages_;
  };
}
