/// @file
/// @brief Contains xtd::globalization::culture_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "culture_not_found_exception.hpp"
#include "culture_types.hpp"
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
    /// @brief Provides information about a specific culture (called a locale for unmanaged code development). The information includes the names for the culture, the writing system, the calendar used, the sort order of strings, and formatting for dates and numbers.
    /// ```cpp
    /// class culture_info : public xtd::object, public xtd::iequatable<xtd::globalization::culture_info>
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::collections::culture_not_found_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/culture_not_found_exception>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
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
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the culture types that pertain to the current xtd::globalization::culture_info object.
      /// @return A bitwise combination of one or more xtd::globalization::culture_types values. There is no default value.
      /// @par Examples
      /// The following example demonstrates the xtd::globalization::culture_types enumeration and the xtd::globalization::culture_info::culture_types property.
      /// @include culture_info_culture_types.cpp
      xtd::globalization::culture_types culture_types() const noexcept;
      const xtd::string& display_name() const noexcept;
      const xtd::string& english_name() const noexcept;
      bool is_locale_available() const noexcept;
      xtd::size keyboard_layout_id() const noexcept;
      xtd::size lcid() const noexcept;
      const std::locale& locale() const noexcept;
      const xtd::string& name() const noexcept;
      const xtd::string& native_name() const noexcept;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      static culture_info current_culture() noexcept;
      static void current_culture(const culture_info& value);
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
      culture_info(xtd::globalization::culture_types culture_types, string&& display_name, string&& english_name, xtd::size keyboard_layout_id, xtd::size lcid, string&& name, string&& native_name);
      
      void fill_from_name(const xtd::string& name);
      static bool is_system_locale_available(const xtd::string& name) noexcept;
      
      static xtd::string to_cldr_name(const xtd::string& name);
      static xtd::string to_locale_name(const xtd::string& name);
      
      struct data {
        xtd::globalization::culture_types culture_types = xtd::globalization::culture_types::specific_cultures;
        xtd::string display_name = "Invariant Language (Invariant Country)";
        xtd::string english_name = "Invariant Language (Invariant Country)";
        xtd::size keyboard_layout_id = 127;
        xtd::size lcid = 127;
        std::locale locale = std::locale {""};
        xtd::string name;
        xtd::string native_name = "Invariant Language (Invariant Country)";
      };
      ptr<data> data_ = new_ptr<data>();
      static xtd::array<culture_info> cultures_;
      static xtd::optional<culture_info> current_culture_;
    };
  }
}
