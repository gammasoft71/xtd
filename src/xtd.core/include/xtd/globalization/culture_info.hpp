/// @file
/// @brief Contains xtd::globalization::culture_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "culture_not_found_exception.hpp"
#include "../collections/generic/dictionary.hpp"
#include "../core_export.hpp"
#include "../iequatable.hpp"
#include "../object.hpp"
#include "../optional.hpp"
#include "../string.hpp"
#include <locale>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as xtd::globalization::string_info and xtd::globalization::text_info provide advanced globalization functionalities, including surrogate support and text element processing.
  namespace globalization {
    /// @cond
    enum class culture_types;
    /// @endcond
    
    /// @brief Provides information about a specific culture (called a locale for unmanaged code development). The information includes the names for the culture, the writing system, the calendar used, the sort order of strings, and formatting for dates and numbers.
    /// ```cpp
    /// class culture_info : public xtd::object, public xtd::iequatable<xtd::globalization::culture_info>
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::globalization::culture_info
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/culture_not_found_exception>
    /// ```
    /// @par Namespace
    /// xtd::globalization
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core globalization
    /// @par Examples
    /// The following example shows how to create a xtd::globalization::culture_info object for Spanish (Spain) with the international sort and another xtd::globalization::culture_info object with the traditional sort.
    /// @include culture_info.cpp
    class culture_info : public xtd::object, public xtd::iequatable<xtd::globalization::culture_info> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class.
      culture_info();
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class with specified culture.
      /// @param culture The xtd::globalization::culture_info to inititalise this instance.
      culture_info(culture_info&& culture) = default;
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class with specified culture.
      /// @param culture The xtd::globalization::culture_info to inititalise this instance.
      culture_info(const culture_info& culture) = default;
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class with specified locale.
      /// @param locale The [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) to inititalise this instance.
      culture_info(const std::locale& locale);
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class based on the culture specified by the culture identifier.
      /// @param culture A predefined xtd::globalization::culture_info identifier, xtd::globalization::culture_info::lcid property of an existing xtd::globalization::culture_info object, or Windows-only culture identifier.
      /// @exception xtd::globalization::culture_not_found_exception culture is not a valid culture identifier. See the Notes to Callers section for more information.
      /// @remarks Predefined culture identifiers for cultures available on Windows system are listed in the Language tag column in the [list of language/region names supported by Windows](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c). Culture names follow the standard defined by [BCP 47](https://tools.ietf.org/html/bcp47).
      /// @remarks <br>In most cases, the `culture` parameter is mapped to the corresponding National Language Support (NLS) locale identifier. The value of the `culture` parameter becomes the value of the xtd::globalization::culture_info::lcid property of the new xtd::globalization::culture_info.
      /// @remarks <br>We recommend that you call the locale name constructor xtd::globalization::culture_info::culture_info (const xtd::string& name), because locale names are preferable to LCIDs. For custom locales, a locale name is required.
      /// @remarks <br>The user might choose to override some of the values associated with the current culture of Windows through the regional and language options portion of Control Panel. For example, the user might choose to display the date in a different format or to use a currency other than the default for the culture. If the specified culture identifier matches the culture identifier of the current Windows culture, this constructor creates a xtd::globalization::culture_info that uses those overrides, including user settings for the properties of the xtd::globalization::date_time_format_info instance returned by the xtd::globalization::culture_info::date_time_format property, and the properties of the xtd::globalization::number_format_info instance returned by the xtd::globalization::culture_info::number_format property. If the user settings are incompatible with the culture associated with the xtd::globalization::culture_info (for example, if the selected calendar is not one of the xtd::globalization::culture_info::optional_calendars) the results of the methods and the values of the properties are undefined.
      /// @remarks <br>For example, suppose that Arabic (Saudi Arabia) is the current Windows culture and the user has changed the calendar from Hijri to Gregorian.
      ///   * With `culture_info {0x0401}` (culture name ar-SA), xtd::globalization::culture_info::calendar is set to xtd::globalization::gregorian_calendar (which is the user setting).
      ///   * With `culture_info {0x041E}` (culture name th-TH), xtd::globalization::culture_info::calendar is set to xtd::globalization::thai_buddhist_calendar (which is the default calendar for th-TH).
      /// @note For backwards compatibility, a culture constructed using a culture parameter of `0x0004` or `0x7c04` will have a xtd::globalization::culture_info::name property of `zh-CHS` or `zh-CHT`, respectively. You should instead prefer to construct the culture using the current standard culture names of `zh-Hans` or `zh-Hant`, unless you have a reason for using the older names.
      /// @note <br>LCIDs are being deprecated, and implementers are strongly encouraged to use newer versions of APIs that support BCP 47 locale names instead. Each LCID can be represented by a BCP 47 locale name, but the reverse is not true. The LCID range is restricted and unable to uniquely identify all the possible combinations of language and region.
      explicit culture_info(xtd::size culture);
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class based on the culture specified by the culture identifier and on a value that specifies whether to use the user-selected culture settings from Windows.
      /// @param culture A predefined xtd::globalization::culture_info identifier, xtd::globalization::culture_info::lcid property of an existing xtd::globalization::culture_info object, or Windows-only culture identifier.
      /// @param use_user_override `true` to use the user-selected culture settings (Windows only); `false` to use the default culture settings.
      /// @exception xtd::globalization::culture_not_found_exception culture is not a valid culture identifier. See the Notes to Callers section for more information.
      /// @remarks Predefined culture identifiers for cultures available on Windows system are listed in the Language tag column in the [list of language/region names supported by Windows](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c). Culture names follow the standard defined by [BCP 47](https://tools.ietf.org/html/bcp47).
      /// @remarks <br>In most cases, the `culture` parameter is mapped to the corresponding National Language Support (NLS) locale identifier. The value of the `culture` parameter becomes the value of the xtd::globalization::culture_info::lcid property of the new xtd::globalization::culture_info.
      /// @remarks <br>We recommend that you call the locale name constructor xtd::globalization::culture_info::culture_info (const xtd::string& name), because locale names are preferable to LCIDs. For custom locales, a locale name is required.
      /// @remarks <br>The user might choose to override some of the values associated with the current culture of Windows through the regional and language options portion of Control Panel. For example, the user might choose to display the date in a different format or to use a currency other than the default for the culture. If the specified culture identifier matches the culture identifier of the current Windows culture, this constructor creates a xtd::globalization::culture_info that uses those overrides, including user settings for the properties of the xtd::globalization::date_time_format_info instance returned by the xtd::globalization::culture_info::date_time_format property, and the properties of the xtd::globalization::number_format_info instance returned by the xtd::globalization::culture_info::number_format property. If the user settings are incompatible with the culture associated with the xtd::globalization::culture_info (for example, if the selected calendar is not one of the xtd::globalization::culture_info::optional_calendars) the results of the methods and the values of the properties are undefined.
      /// @remarks <br>For example, suppose that Arabic (Saudi Arabia) is the current Windows culture and the user has changed the calendar from Hijri to Gregorian.
      ///   * With `culture_info {0x0401}` (culture name ar-SA), xtd::globalization::culture_info::calendar is set to xtd::globalization::gregorian_calendar (which is the user setting).
      ///   * With `culture_info {0x041E}` (culture name th-TH), xtd::globalization::culture_info::calendar is set to xtd::globalization::thai_buddhist_calendar (which is the default calendar for th-TH).
      /// @note For backwards compatibility, a culture constructed using a culture parameter of `0x0004` or `0x7c04` will have a xtd::globalization::culture_info::name property of `zh-CHS` or `zh-CHT`, respectively. You should instead prefer to construct the culture using the current standard culture names of `zh-Hans` or `zh-Hant`, unless you have a reason for using the older names.
      /// @note <br>LCIDs are being deprecated, and implementers are strongly encouraged to use newer versions of APIs that support BCP 47 locale names instead. Each LCID can be represented by a BCP 47 locale name, but the reverse is not true. The LCID range is restricted and unable to uniquely identify all the possible combinations of language and region.
      culture_info(xtd::size culture, bool use_user_override);
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class based on the culture specified by name.
      /// @param name A predefined xtd::globalization::culture_info name, xtd::globalization::culture_info::name of an existing xtd::globalization::culture_info, or Windows-only culture name. name is not case-sensitive.
      /// @par examples
      /// The following example retrieves the current culture. If it is anything other than the French (France) culture, it calls the xtd::globalization::culture_info::culture_info (const string&) constructor to instantiate a xtd::globalization::culture_info object that represents the French (France) culture and makes it the current culture. Otherwise, it instantiates a xtd::globalization::culture_info object that represents the French (Luxembourg) culture and makes it the current culture.
      /// @include culture_info_with_name.cpp
      /// @remarks For a list of predefined culture names on Windows systems, see the Language tag column in the [list of language/region names supported by Windows](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c). Culture names follow the standard defined by [BCP 47](https://tools.ietf.org/html/bcp47).
      /// @remarks <br>If `name` is xtd::string::empty_string, the constructor creates an instance of the invariant culture; this is equivalent to retrieving the value of the xtd::globalization::culture_info::invariant_culture property.
      /// @remarks <br>The user might choose to override some of the values associated with the current culture of Windows through the regional and language options portion of Control Panel. For example, the user might choose to display the date in a different format or to use a currency other than the default for the culture. If the specified culture identifier matches the culture identifier of the current Windows culture, this constructor creates a xtd::globalization::culture_info that uses those overrides, including user settings for the properties of the xtd::globalization::date_time_format_info instance returned by the xtd::globalization::culture_info::date_time_format property, and the properties of the xtd::globalization::number_format_info instance returned by the xtd::globalization::culture_info::number_format property. If the user settings are incompatible with the culture associated with the xtd::globalization::culture_info (for example, if the selected calendar is not one of the xtd::globalization::culture_info::optional_calendars) the results of the methods and the values of the properties are undefined.
      /// @remarks <br>For example, suppose that Arabic (Saudi Arabia) is the current Windows culture and the user has changed the calendar from Hijri to Gregorian.
      ///   * With `culture_info {0x0401}` (culture name ar-SA), xtd::globalization::culture_info::calendar is set to xtd::globalization::gregorian_calendar (which is the user setting).
      ///   * With `culture_info {0x041E}` (culture name th-TH), xtd::globalization::culture_info::calendar is set to xtd::globalization::thai_buddhist_calendar (which is the default calendar for th-TH).
      explicit culture_info(const xtd::string& name);
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class based on the culture specified by name and on a value that specifies whether to use the user-selected culture settings from Windows.
      /// @param name A predefined xtd::globalization::culture_info name, xtd::globalization::culture_info::name of an existing xtd::globalization::culture_info, or Windows-only culture name. name is not case-sensitive.
      /// @param use_user_override `true` to use the user-selected culture settings (Windows only); `false` to use the default culture settings.
      /// @par examples
      /// The following example retrieves the current culture. If it is anything other than the French (France) culture, it calls the xtd::globalization::culture_info::culture_info (const string&) constructor to instantiate a xtd::globalization::culture_info object that represents the French (France) culture and makes it the current culture. Otherwise, it instantiates a xtd::globalization::culture_info object that represents the French (Luxembourg) culture and makes it the current culture.
      /// @include culture_info_with_name.cpp
      /// @remarks For a list of predefined culture names on Windows systems, see the Language tag column in the [list of language/region names supported by Windows](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c). Culture names follow the standard defined by [BCP 47](https://tools.ietf.org/html/bcp47).
      /// @remarks <br>If `name` is xtd::string::empty_string, the constructor creates an instance of the invariant culture; this is equivalent to retrieving the value of the xtd::globalization::culture_info::invariant_culture property.
      /// @remarks <br>The user might choose to override some of the values associated with the current culture of Windows through the regional and language options portion of Control Panel. For example, the user might choose to display the date in a different format or to use a currency other than the default for the culture. If the specified culture identifier matches the culture identifier of the current Windows culture, this constructor creates a xtd::globalization::culture_info that uses those overrides, including user settings for the properties of the xtd::globalization::date_time_format_info instance returned by the xtd::globalization::culture_info::date_time_format property, and the properties of the xtd::globalization::number_format_info instance returned by the xtd::globalization::culture_info::number_format property. If the user settings are incompatible with the culture associated with the xtd::globalization::culture_info (for example, if the selected calendar is not one of the xtd::globalization::culture_info::optional_calendars) the results of the methods and the values of the properties are undefined.
      /// @remarks <br>For example, suppose that Arabic (Saudi Arabia) is the current Windows culture and the user has changed the calendar from Hijri to Gregorian.
      ///   * With `culture_info {0x0401}` (culture name ar-SA), xtd::globalization::culture_info::calendar is set to xtd::globalization::gregorian_calendar (which is the user setting).
      ///   * With `culture_info {0x041E}` (culture name th-TH), xtd::globalization::culture_info::calendar is set to xtd::globalization::thai_buddhist_calendar (which is the default calendar for th-TH).
      culture_info(const xtd::string& name, bool use_user_override);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the culture types that pertain to the current xtd::globalization::culture_info object.
      /// @return A bitwise combination of one or more xtd::globalization::culture_types values. There is no default value.
      /// @par Examples
      /// The following example demonstrates the xtd::globalization::culture_types enumeration and the xtd::globalization::culture_info::culture_types property.
      /// @include culture_info_culture_types.cpp
      xtd::globalization::culture_types culture_types() const noexcept;
      
      /// @brief Gets the full localized culture name.
      /// @return The full localized culture name in the format languagefull [country/regionfull], where languagefull is the full name of the language and country/regionfull is the full name of the country/region.
      /// @remarks This property represents the localized name of the xtd::globalization::culture_info object.
      /// @remarks Culture names may vary due to scripting or formatting conventions. You should use the returned name for display, and not attempt to parse it.
      /// @par Examples
      /// The following code example displays several properties of the neutral cultures.
      /// @include culture_info_properties.cpp
      /// @remarks This property represents the localized name of the xtd::globalization::culture_info object.
      /// @remarks Culture names may vary due to scripting or formatting conventions. You should use the returned name for display, and not attempt to parse it.
      const xtd::string& display_name() const noexcept;
      
      /// @brief Gets the culture name in the format languagefull [country/regionfull] in English.
      /// @return The culture name in the format languagefull [country/regionfull] in English, where languagefull is the full name of the language and country/regionfull is the full name of the country/region.
      /// @par Examples
      /// The following code example displays several properties of the neutral cultures.
      /// @include culture_info_properties.cpp
      /// @remarks For example, the xtd::globalization::culture_info::english_name for the specific culture name en-US is "English (United States)".
      /// @remarks The value of this property is the same, regardless of the language version of the xtd.
      const xtd::string& english_name() const noexcept;
      
      /// @brief Gets a value indicateing if the [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) corresponding to this instance is available.
      /// @return `true` if the [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) is available; otherwise `false`.
      /// @remarks If xtd::globalization::culture_info::is_locale_available return `true`, the xtd::globalization::culture_info::locale property returns a valid [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) with name corresponding to the current xtd::globalization::culture_info; otherwise a generic [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) with name equal to `"C"`.
      bool is_locale_available() const noexcept;

      /// @brief Gets a value indicating whether the current CultureInfo is read-only.
      /// @return `true` if the current xtd::globalization::culture_info is read-only; otherwise, `false`. The default is `false`.
      bool is_read_only() const noexcept;

      /// @brief Gets a value indicating whether the current xtd::globalization::culture_info represents a neutral culture.
      /// @return `true` if the current CultureInfo represents a neutral culture; otherwise, `false`.
      /// @par Examples
      /// The following code example determines which cultures using the Chinese language are neutral cultures.
      /// @include culture_info_is_neutral_culture.cpp
      bool is_neutral_culture() const noexcept;
      
      /// @brief Gets the active input locale identifier.
      /// @return A 32-bit signed number that specifies an input locale identifier.
      /// @remarks The input locale identifier was formerly called the keyboard layout. An input locale identifier is a broader concept than a keyboard layout since it can also indicate a speech-to-text converter, an Input Method Editor (IME), or any other form of input.
      xtd::size keyboard_layout_id() const noexcept;
      
      /// @brief Gets the culture identifier for the current xtd::globalization::culture_info.
      /// @return The culture identifier for the current xtd::globalization::culture_info.
      /// @par Examples
      /// The following code example shows how to create a current xtd::globalization::culture_info for Spanish (Spain).
      /// @include culture_info_lcid.cpp
      xtd::size lcid() const noexcept;

      /// @brief Gets the [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) associate for the current xtd::globalization::culture_info.
      /// @return The [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) associate for the current xtd::globalization::culture_info.
      /// @remarks If xtd::globalization::culture_info::is_locale_available return `true`, the xtd::globalization::culture_info::locale property returns a valid [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) with name corresponding to this instance otherwise a generic [std::locale](https://en.cppreference.com/w/cpp/locale/locale.html) with name equal to `"C"`.
      const std::locale& locale() const noexcept;
      
      /// @brief Gets the culture name in the format languagecode2-country/regioncode2.
      /// @return The culture name in the format languagecode2-country/regioncode2, if the current xtd::globalization::culture_info is culture-dependent; or an empty string, if it's an invariant culture. languagecode2 is a lowercase two-letter code as defined in ISO 639-1, or, if no two-letter code is available, a three-letter code as defined in ISO 639-3. country/regioncode2 contains a value defined in ISO 3166 and usually consists of two uppercase letters, or a BCP-47 language tag.
      /// @par Examples
      /// The following code example determines which cultures using the Chinese language are neutral cultures.
      /// @include culture_info_is_neutral_culture.cpp
      const xtd::string& name() const noexcept;
      
      const xtd::string& native_name() const noexcept;
      
      virtual xtd::globalization::culture_info parent() const noexcept;
      
      const xtd::string& three_letter_iso_language_name() const noexcept;
      
      const xtd::string& three_letter_windows_language_name() const noexcept;
      
      const xtd::string& two_letter_iso_language_name() const noexcept;

      bool use_user_override() const noexcept;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets the xtd::globalization::culture_info object that represents the culture used by the current application.
      /// @return The culture used by the current application.
      /// @par Examples
      /// The following example demonstrates how to change the xtd::globalization::culture_info::current_culture of the current application.
      /// @include culture_info_current_culture.cpp
      static culture_info current_culture() noexcept;
      /// @brief Sets the xtd::globalization::culture_info object that represents the culture used by the current application.
      /// @param value The culture used by the current application.
      /// @par Examples
      /// The following example demonstrates how to change the xtd::globalization::culture_info::current_culture of the current application.
      static void current_culture(const culture_info& value);
      
      /// @brief Gets the CultureInfo object that is culture-independent (invariant).
      /// @return The object that is culture-independent (invariant).
      static culture_info invariant_culture() noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      /// @par Examples
      /// The following code example compares the current instance with another object.
      /// @include object_equals.cpp
      bool equals(const object& obj) const noexcept override;
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param obj An object to compare with this object.
      /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
      bool equals(const culture_info& obj) const noexcept override;
      /// @brief Returns a xtd::string that represents the current object.
      /// @return A string that represents the current object.
      /// @par Examples
      /// The following code example demonstrates what to_string returns.
      /// @include object_to_string.cpp
      xtd::string to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      static xtd::array<culture_info> get_cultures(xtd::globalization::culture_types types) noexcept;
      static xtd::array<std::locale> get_system_locales() noexcept;
      /// @}
      
      /// @name Public Operators
      
      /// @{
      culture_info& operator =(culture_info&& culture) = default;
      culture_info& operator =(const culture_info& culture) = default;
      culture_info& operator =(std::locale&& locale);
      culture_info& operator =(const std::locale& locale);
      
      operator const std::locale& () const noexcept;
      /// @}
      
    private:
      culture_info(xtd::globalization::culture_types culture_types, string&& display_name, string&& english_name, xtd::size keyboard_layout_id, xtd::size lcid, string&& name, string&& native_name, string&& parent_name, string&& three_letter_iso_language_name, string&& three_letter_windows_language_name, string&& two_letter_iso_language_name);
      
      void fill_from_name(const xtd::string& name);
      static bool is_system_locale_available(const xtd::string& name) noexcept;
      
      static xtd::string to_cldr_name(const xtd::string& name);
      static xtd::string to_locale_name(const xtd::string& name);
      
      struct data;
      ptr<data> data_;
      static xtd::collections::generic::dictionary<xtd::string, culture_info> cultures_;
      static xtd::optional<culture_info> current_culture_;
    };
  }
}

#include "culture_types.hpp"
#define __XTD_BOX_INTERNAL__
#include "../box_.hpp"
#undef  __XTD_BOX_INTERNAL__
#define __XTD_ENUM_OBJECT_INTERNAL__
#include "../enum_object_.hpp"
#undef  __XTD_ENUM_OBJECT_INTERNAL__
#define __XTD_TO_STRING_INTERNAL__
#include "../to_string_.hpp"
#undef  __XTD_TO_STRING_INTERNAL__
