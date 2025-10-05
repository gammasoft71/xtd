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
      /// @param culture The culture to inititalise this instance.
      culture_info(culture_info&& culture) = default;
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class with specified culture.
      /// @param culture The culture to inititalise this instance.
      culture_info(const culture_info& culture) = default;
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class with specified locale.
      /// @param locale The locale to inititalise this instance.
      culture_info(const std::locale& locale);
      /// @brief Initializes a new instance of the xtd::globalization::culture_info class based on the culture specified by the culture identifier.
      /// @param culture A predefined xtd::globalization::culture_info identifier, xtd::globalization::culture_info::lcid property of an existing xtd::globalization::culture_info object, or Windows-only culture identifier.
      /// @exception xtd::globalization::culture_not_found_exception culture is not a valid culture identifier. See the Notes to Callers section for more information.
      /// @remarks Predefined culture identifiers for cultures available on Windows system are listed in the Language tag column in the [list of language/region names supported by Windows](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c). Culture names follow the standard defined by [BCP 47](https://tools.ietf.org/html/bcp47).
      /// @remarks In most cases, the `culture` parameter is mapped to the corresponding National Language Support (NLS) locale identifier. The value of the `culture` parameter becomes the value of the xtd::globalization::culture_info::lcid property of the new xtd::globalization::culture_info.
      /// @remarks We recommend that you call the locale name constructor xtd::globalization::culture_info::culture_info (const xtd::string& name), because locale names are preferable to LCIDs. For custom locales, a locale name is required.
      explicit culture_info(xtd::size culture);
      explicit culture_info(const xtd::string& name);
      /// @}
      
      /// @name Public Properties
      
      /// @{
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
      static xtd::string to_cldr_name(const xtd::string& name);
      static xtd::string to_locale_name(const xtd::string& name);
      
      struct data {
        xtd::globalization::culture_types culture_types = xtd::globalization::culture_types::specific_cultures;
        xtd::string display_name = "Invariant Language (Invariant Country)";
        xtd::string english_name = "Invariant Language (Invariant Country)";
        xtd::size keyboard_layout_id = 127;
        xtd::size lcid = 127;
        std::locale locale;
        xtd::string name;
        xtd::string native_name = "Invariant Language (Invariant Country)";
      };
      ptr<data> data_ = new_ptr<data>();
      static xtd::array<culture_info> cultures_;
      static xtd::optional<culture_info> current_culture_;
    };
  }
}
