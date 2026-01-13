/// @file
/// @brief Contains xtd::globalization::translator class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../collections/specialized/string_dictionary.hpp"
#include "../io/path.hpp"
#include "../environment.hpp"
#include "../optional.hpp"
#include "../static.hpp"
#include "../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as xtd::globalization::string_info and xtd::globalization::text_info provide advanced globalization functionalities, including surrogate support and text element processing.
  namespace globalization {
    /// @brief Represents translator class. This class cannot be inherited.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system globalization
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
      static auto language() -> xtd::string;
      /// @brief Sets the current application language.
      /// @param language The current application language.
      /// @remarks Normally you should use the xtd::globalization::culture_info::current_culture property. This function only exists if you have a good reason to bypass xtd::globalization::culture_info::current_culture.
      /// @warning If you set the language with this method, and you use the xtd::globalization::culture_info::current_culture property afterwards, translator will use the language initialized with this method and not with xtd::globalization::culture_info::current_culture.
      static auto language(const xtd::string& language) -> void;
      /// @brief Sets the current application language.
      /// @param language The current application language.
      /// @remarks Normally you should use the xtd::globalization::culture_info::current_culture property. This function only exists if you have a good reason to bypass xtd::globalization::culture_info::current_culture.
      /// @warning If you set the language with this method, and you use the xtd::globalization::culture_info::current_culture property afterwards, translator will use the language initialized with this method and not with xtd::globalization::culture_info::current_culture.
      static auto language(xtd::null_ptr) -> void;
      
      /// @brief Gets an array of languages supported by the application.
      /// @return An array of languages supported by the application.
      static auto languages() -> xtd::array<xtd::string>;
      
      /// @brief Gets the current system language.
      /// @return The current system language.
      static auto system_language() -> xtd::string;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Manually adds a translation for a specified key and language.
      /// @param language The language of the key to be translated.
      /// @param key The key to be translated.
      /// @parama value The translation of the key for the specified language.
      /// @warning This method should not be used. The translation is normally done automatically. This method is present only if you want to make an instant translation on a very small number of keys. It would not be wise to translate an entire application into different languages with this method.
      static auto add_value(const xtd::string& language, const xtd::string& key, const xtd::string& value) -> void {
        auto language_name  = to_language_name(language);
        if (!xtd::io::directory::exists(xtd::io::path::combine(application_locale_path(), language_name))) language_name = to_fallback_name(language_name);
        if (load_language(language_name)) languages_[language_name] = language_name;
        language_values_[languages_[language_name]][key] = value;
      }
      
      /// @brief Parses a specified path that contains translations.
      /// @param locale_path Path that contains translations.
      /// @return `true` if parse succeed; otherwhise `false`.
      /// @remarks parse path with xtd::globalization::translator::language() language.
      static auto parse_locale(const xtd::string& locale_path) -> bool;
      
      /// @brief Parses a specified path that contains translations.
      /// @param locale_path Path that contains translations.
      /// @return `true` if parse succeed; otherwhise `false`.
      static auto parse_locale(const xtd::string& locale_path, const xtd::string& language) -> bool;
      
      /// @brief Parses a specified file that contains translations for a specified language.
      /// @param file The file that contains translations.
      /// @return `true` if parse succeed; otherwhise `false`.
      /// @remarks parse file with xtd::globalization::translator::language() language.
      static auto parse_file(const xtd::string& file) -> bool;
      
      /// @brief Parses a specified file that contains translations for a specified language.
      /// @param file The file that contains translations.
      /// @param language The language of the translation file.
      /// @return `true` if parse succeed; otherwhise `false`.
      static auto parse_file(const xtd::string& file, const xtd::string& language) -> bool;
      
      /// @brief Translates a string into the lganguage specified by the xtd::translate::language property.
      /// @return The translated string.
      /// @remarks If no translation is found, the result is the same as the value.
      static auto translate(const xtd::string& value) noexcept -> xtd::string {return translate(language(), value);}
      /// @brief Translates a string into the specified lganguage.
      /// @return The translated string.
      /// @param language The language used to translate the value
      /// @remarks If no translation is found, the result is the same as the value.
      static auto translate(const xtd::string& language, const xtd::string& value) noexcept -> xtd::string {return translate(language, value.chars().c_str());}
      /// @}
      
      /// @cond
      static auto translate(const char* value) noexcept -> const char* {return translate(language(), value);}
      static auto translate(const xtd::string& language, const char* value) noexcept -> const char* {
        auto language_name  = to_language_name(language);
        if (!xtd::io::directory::exists(xtd::io::path::combine(application_locale_path(), language_name))) language_name = to_fallback_name(language_name);
        if (!load_language(language_name)) return value;
        if (!language_values_[languages_[language_name]].contains_key(value)) return value;
        return language_values_[languages_[language_name]][value].c_str();
      }
      /// @endcond
      
    private:
      static auto application_locale_path() -> xtd::string {return xtd::io::path::combine(xtd::environment::get_folder_path(environment::special_folder::application_resources), "locale");}
      static auto xtd_locale_path() -> xtd::string {return environment::get_folder_path(xtd::environment::special_folder::xtd_locale);}
      static auto load_language(const xtd::string& language) -> bool {return load_language(language, xtd_locale_path(), application_locale_path());}
      static auto load_language(const xtd::string& language, const xtd::string& xtd_locale_path, const xtd::string& application_locale_path) -> bool;
      static auto to_language_name(const xtd::string& language) -> xtd::string;
      static auto to_fallback_name(const xtd::string& language) -> xtd::string;
      static xtd::collections::generic::dictionary<xtd::string, xtd::collections::specialized::string_dictionary> language_values_;
      static xtd::collections::specialized::string_dictionary languages_;
      static xtd::optional<xtd::string> language_;
    };
  }
}

#include "../literals/translator.hpp"
