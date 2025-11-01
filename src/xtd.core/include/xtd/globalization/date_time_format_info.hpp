/// @file
/// @brief Contains xtd::globalization::date_time_format_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.hpp"
#include "../collections/generic/dictionary.hpp"
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
    
    /// @brief Provides culture-specific information about the format of date and time values.
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
      /// @remarks This constructor creates a xtd::globalization::date_time_format_info object that represents the date and time information of the invariant culture. To create a xtd::globalization::date_time_format_info object for a specific culture, create a xtd::globalization::culture_info object for that culture and retrieve the xtd::globalization::date_time_format_info object returned by its xtd::globalization::culture_info::date_time_format property.
      /// @remarks The properties of the xtd::globalization::date_time_format_info object created by this constructor can be modified. However, you cannot modify the xtd::globalization::date_time_format_info::calendar property, because the invariant culture supports only a localized version of the Gregorian calendar. To create a xtd::globalization::date_time_format_info object that uses a specific calendar, you must instantiate a xtd::globalization::culture_info object that supports that calendar and assign the calendar to the xtd::globalization::date_time_format_info::calendar property of the xtd::globalization::date_time_format_info object returned by the xtd::globalization::culture_info::date_time_format property.
      date_time_format_info();
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class with specified info.
      /// @param info The xtd::globalization::date_time_format_info to inititalise this instance.
      date_time_format_info(date_time_format_info&& info) = default;
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class with specified infp.
      /// @param info The xtd::globalization::date_time_format_info to inititalise this instance.
      date_time_format_info(const date_time_format_info& info);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a one-dimensional array of type String containing the culture-specific abbreviated names of the days of the week.
      /// @return A one-dimensional array of type xtd::string containing the culture-specific abbreviated names of the days of the week. The array for xtd::globalization::date_time_format_info::invariant_info contains "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", and "Sat".
      const xtd::array<xtd::string>& abreviated_day_names() const noexcept;
      /// @brief Sets a one-dimensional array of type String containing the culture-specific abbreviated names of the days of the week.
      /// @param value A one-dimensional array of type xtd::string containing the culture-specific abbreviated names of the days of the week. The array for xtd::globalization::date_time_format_info::invariant_info contains "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", and "Sat".
      /// @exception xtd::argument_exception The property is being set to an array that has a length that is not exactly 7.
      date_time_format_info& abreviated_day_names(const xtd::array<xtd::string>& value) noexcept;
      
      const xtd::array<xtd::string>& abreviated_month_genitive_names() const noexcept;
      date_time_format_info& abreviated_month_genitive_names(const xtd::array<xtd::string>& value) noexcept;
      
      const xtd::array<xtd::string>& abreviated_month_names() const noexcept;
      date_time_format_info& abreviated_month_names(const xtd::array<xtd::string>& value) noexcept;
      
      const xtd::string& am_designator() const noexcept;
      date_time_format_info& am_designator(const xtd::string& value) noexcept;
      
      const xtd::string& date_separator() const noexcept;
      date_time_format_info& date_separator(const xtd::string& value) noexcept;
      
      const xtd::array<xtd::string>& day_names() const noexcept;
      date_time_format_info& day_names(const xtd::array<xtd::string>& value) noexcept;
      
      xtd::day_of_week first_day_of_week() const noexcept;
      date_time_format_info& first_day_of_week(xtd::day_of_week value) noexcept;
      
      const string& full_date_time_pattern() const noexcept;
      date_time_format_info& full_date_time_pattern(const string& value) noexcept;
      
      const string& long_date_pattern() const noexcept;
      date_time_format_info& long_date_pattern(const string& value) noexcept;
      
      const string& long_time_pattern() const noexcept;
      date_time_format_info& long_time_pattern(const string& value) noexcept;
      
      const string& month_day_pattern() const noexcept;
      date_time_format_info& month_day_pattern(const string& value) noexcept;
      
      const xtd::array<xtd::string>& month_genitive_names() const noexcept;
      date_time_format_info& month_genitive_names(const xtd::array<xtd::string>& value) noexcept;
      
      const xtd::array<xtd::string>& month_names() const noexcept;
      date_time_format_info& month_names(const xtd::array<xtd::string>& value) noexcept;
      
      const xtd::string& native_calendar_name() const noexcept;
      date_time_format_info& native_calendar_name(const xtd::string& value) noexcept;
      
      const xtd::string& pm_designator() const noexcept;
      date_time_format_info& pm_designator(const xtd::string& value) noexcept;
      
      const string& rfc_1123_pattern() const noexcept;
      date_time_format_info& rfc_1123_pattern(const string& value) noexcept;
      
      const string& short_date_pattern() const noexcept;
      date_time_format_info& short_date_pattern(const string& value) noexcept;
      
      const string& short_time_pattern() const noexcept;
      date_time_format_info& short_time_pattern(const string& value) noexcept;
      
      const xtd::array<xtd::string>& shortest_day_names() const noexcept;
      date_time_format_info& shortest_day_names(const xtd::array<xtd::string>& value) noexcept;
      
      const string& sortable_date_time_pattern() const noexcept;
      date_time_format_info& sortable_date_time_pattern(const string& value) noexcept;
      
      const xtd::string& time_separator() const noexcept;
      date_time_format_info& time_separator(const xtd::string& value) noexcept;
      
      const string& universal_sortable_date_time_pattern() const noexcept;
      date_time_format_info& universal_sortable_date_time_pattern(const string& value) noexcept;
      
      const string& year_month_pattern() const noexcept;
      date_time_format_info& year_month_pattern(const string& value) noexcept;
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
      date_time_format_info& operator =(const date_time_format_info& culture);
      /// @endcond
      
    private:
      friend class culture_info;
      date_time_format_info(xtd::array<xtd::string>&& abreviated_day_names, xtd::array<xtd::string>&& abreviated_genitive_month_names, xtd::array<xtd::string>&& abreviated_month_names, xtd::string&& am_designator, xtd::string&& date_separator, xtd::array<xtd::string>&& day_names, xtd::day_of_week first_day_of_week, xtd::string&& full_date_time_pattern, xtd::string&& long_date_pattern, xtd::string&& long_time_pattern, xtd::string&& month_day_pattern, xtd::array<xtd::string>&& month_genitive_names, xtd::array<xtd::string>&& month_names, xtd::string&& native_calendar_name, xtd::string&& pm_designator, xtd::string&& rfc_1123_pattern, xtd::string&& short_date_pattern, xtd::string&& short_time_pattern, xtd::array<xtd::string>&& shortest_day_names, xtd::string&& sortable_date_time_pattern, xtd::string&& time_separator, xtd::string&& universal_sortable_date_time_pattern, xtd::string&& year_month_pattern);
      static xtd::collections::generic::dictionary<xtd::string, date_time_format_info>& formats();
      
      struct data;
      ptr<data> data_;
    };
  }
}
