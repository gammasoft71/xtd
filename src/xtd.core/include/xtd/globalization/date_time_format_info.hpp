/// @file
/// @brief Contains xtd::globalization::date_time_format_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.hpp"
#include "../object.hpp"
#include "../string.hpp"
#include <locale>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  enum class day_of_week;
  ///@endcond
  
  /// @brief Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as xtd::globalization::string_info and xtd::globalization::text_info provide advanced globalization functionalities, including surrogate support and text element processing.
  namespace globalization {
    /// @cond
    class culture_info;
    /// @endcond
    /// @brief Provides information about a specific culture (called a locale for unmanaged code development). The information includes the names for the culture, the writing system, the calendar used, the sort order of strings, and formatting for dates and numbers.
    /// ```cpp
    /// class date_time_format_info : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::globalization::date_time_format_info
    /// @par Header
    /// ```cpp
    /// #include <xtd/globalization/date_time_format_info>
    /// ```
    /// @par Namespace
    /// xtd::globalization
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core globalization
    /// @par Examples
    /// The following example uses reflection to get the properties of the xtd::globalization::date_time_format_info object for the English (United States) culture. It displays the value of those properties that contain custom format strings and uses those strings to display formatted dates.
    /// @include date_time_format_info.cpp
    class core_export_ date_time_format_info : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class.
      date_time_format_info();
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class with specified info.
      /// @param info The xtd::globalization::date_time_format_info to inititalise this instance.
      date_time_format_info(date_time_format_info&& info) = default;
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class with specified infp.
      /// @param info The xtd::globalization::date_time_format_info to inititalise this instance.
      date_time_format_info(const date_time_format_info& info) = default;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      const xtd::array<xtd::string>& abreviated_day_names() const noexcept;
      
      const xtd::array<xtd::string>& abreviated_month_genitive_names() const noexcept;
      
      const xtd::array<xtd::string>& abreviated_month_names() const noexcept;

      const xtd::string& am_designator() const noexcept;

      const xtd::string& date_separator() const noexcept;
      
      const xtd::array<xtd::string>& day_names() const noexcept;
      
      xtd::day_of_week first_day_of_week() const noexcept;
      
      const string& full_date_time_pattern() const noexcept;

      const string& long_date_pattern() const noexcept;

      const string& long_time_pattern() const noexcept;

      const string& month_day_pattern() const noexcept;

      const xtd::array<xtd::string>& month_genitive_names() const noexcept;
      
      const xtd::array<xtd::string>& month_names() const noexcept;

      const xtd::string& native_calendar_name() const noexcept;

      const xtd::string& pm_designator() const noexcept;

      const string& rfc_1123_pattern() const noexcept;

      const string& short_date_pattern() const noexcept;

      const string& short_time_pattern() const noexcept;
      
      const xtd::array<xtd::string>& shortest_day_names() const noexcept;
      
      const string& sortable_date_time_pattern() const noexcept;

      const xtd::string& time_separator() const noexcept;
      
      const string& universal_sortable_date_time_pattern() const noexcept;

      const string& year_month_pattern() const noexcept;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      static const date_time_format_info& current_info() noexcept;
      
      static const date_time_format_info& invariant_info() noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @}
      
      /// @cond
      date_time_format_info& operator =(date_time_format_info&& culture) = default;
      date_time_format_info& operator =(const date_time_format_info& culture) = default;
      /// @endcond
      
    private:
      friend class culture_info;
      date_time_format_info(xtd::array<xtd::string>&& abreviated_day_names, xtd::array<xtd::string>&& abreviated_genitive_month_names, xtd::array<xtd::string>&& abreviated_month_names, xtd::string&& am_designator);
      
      struct data;
      ptr<data> data_;
    };
  }
}
