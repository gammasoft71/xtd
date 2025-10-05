/// @file
/// @brief Contains xtd::globalization::culture_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "culture_not_found_exception.hpp"
#include "culture_types.hpp"
#include "../core_export.hpp"
#include "../iequatable.hpp"
#include "../object.hpp"
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
      culture_info() = default;
      culture_info(culture_info&& culture) = default;
      culture_info(const culture_info& culture) = default;
      culture_info(const std::locale& locale);
      culture_info(const xtd::string& name);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      xtd::globalization::culture_types culture_types() const noexcept;
      const xtd::string& display_name() const noexcept;
      const xtd::string& english_name() const noexcept;
      bool is_locale_available() const noexcept;
      xtd::size keyboard_layout_id() const noexcept;
      xtd::size lc_id() const noexcept;
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
      culture_info(xtd::globalization::culture_types culture_types, string&& display_name, string&& english_name, xtd::size keyboard_layout_id, xtd::size lc_id, string&& name, string&& native_name);
      
      void fill_from_name(const xtd::string& name);
      static xtd::string to_cldr_name(const xtd::string& name);
      static xtd::string to_locale_name(const xtd::string& name);
      
      struct data {
        xtd::globalization::culture_types culture_types = xtd::globalization::culture_types::neutral_cultures;
        xtd::string display_name;
        xtd::string english_name;
        xtd::size keyboard_layout_id = 0;
        xtd::size lc_id = 0;
        std::locale locale;
        xtd::string name;
        xtd::string native_name;
      };
      ptr<data> data_ = new_ptr<data>();
      static xtd::array<culture_info> cultures_;
      static culture_info current_culture_;
    };
  }
}
