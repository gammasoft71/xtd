/// @file
/// @brief Contains xtd::globalization::date_time_format_info class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
      date_time_format_info(xtd::globalization::date_time_format_info&& info) = default;
      /// @brief Initializes a new instance of the xtd::globalization::date_time_format_info class with specified infp.
      /// @param info The xtd::globalization::date_time_format_info to inititalise this instance.
      date_time_format_info(const xtd::globalization::date_time_format_info& info);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a one-dimensional array of type String containing the culture-specific abbreviated names of the days of the week.
      /// @return A one-dimensional array of type xtd::string containing the culture-specific abbreviated names of the days of the week. The array for xtd::globalization::date_time_format_info::invariant_info contains "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", and "Sat".
      [[nodiscard]] auto abreviated_day_names() const noexcept -> const xtd::array<xtd::string>& ;
      /// @brief Sets a one-dimensional array of type String containing the culture-specific abbreviated names of the days of the week.
      /// @param value A one-dimensional array of type xtd::string containing the culture-specific abbreviated names of the days of the week. The array for xtd::globalization::date_time_format_info::invariant_info contains "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", and "Sat".
      /// @exception xtd::argument_exception The property is being set to an array that has a length that is not exactly 7.
      auto abreviated_day_names(const xtd::array<xtd::string>& value) -> xtd::globalization::date_time_format_info&;
      
      /// @brief Gets a string array of abbreviated month names associated with the current xtd::globalization::date_time_format_info object.
      /// @return An array of abbreviated month names.
      [[nodiscard]] auto abreviated_month_genitive_names() const noexcept -> const xtd::array<xtd::string>& ;
      /// @brief Sets a string array of abbreviated month names associated with the current xtd::globalization::date_time_format_info object.
      /// @param value An array of abbreviated month names.
      /// @exception xtd::argument_exception The property is being set to an array that has a length that is not exactly 13.
      auto abreviated_month_genitive_names(const xtd::array<xtd::string>& value) -> xtd::globalization::date_time_format_info&;

      /// @brief Gets or a one-dimensional string array that contains the culture-specific abbreviated names of the months.
      /// @return A one-dimensional string array with 13 elements that contains the culture-specific abbreviated names of the months. For 12-month calendars, the 13th element of the array is an empty string. The array for InvariantInfo contains "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", and "".
      [[nodiscard]] auto abreviated_month_names() const noexcept -> const xtd::array<xtd::string>& ;
      /// @brief Sets or a one-dimensional string array that contains the culture-specific abbreviated names of the months.
      /// @oaram value A one-dimensional string array with 13 elements that contains the culture-specific abbreviated names of the months. For 12-month calendars, the 13th element of the array is an empty string. The array for InvariantInfo contains "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", and "".
      /// @exception xtd::argument_exception The property is being set to an array that has a length that is not exactly 13.
      auto abreviated_month_names(const xtd::array<xtd::string>& value) -> xtd::globalization::date_time_format_info&;
      
      /// @brief Gets the string designator for hours that are "ante meridiem" (before noon).
      /// @return The string designator for hours that are ante meridiem. The default for InvariantInfo is "AM".
      /// @remarks The xtd::globalization::date_time_format_info::am_designator property is used for all times from 0:00:00 (midnight) to 11:59:59.999.
      /// @remarks If a custom format string includes the "tt" format specifier and the time is before noon, the xtd::date_time::to_string method includes the value of the xtd::globalization::date_time_format_info::am_designator property in place of "tt" in the result string. If the custom format string includes the "t" custom format specifier, only the first character of the xtd::globalization::date_time_format_info::am_designator property value is included. You should use "tt" for languages for which it is necessary to maintain the distinction between A.M. and P.M. An example is Japanese, in which the A.M. and P.M. designators differ in the second character instead of the first character.
      /// @remarks For cultures that do not use an A.M. designator, this property returns an empty string.
      [[nodiscard]] auto am_designator() const noexcept -> const xtd::string&;
      /// @brief Sets the string designator for hours that are "ante meridiem" (before noon).
      /// @param value The string designator for hours that are ante meridiem. The default for InvariantInfo is "AM".
      /// @remarks If a custom format string includes the "tt" format specifier and the time is before noon, the xtd::date_time::to_string method includes the value of the xtd::globalization::date_time_format_info::am_designator property in place of "tt" in the result string. If the custom format string includes the "t" custom format specifier, only the first character of the xtd::globalization::date_time_format_info::am_designator property value is included. You should use "tt" for languages for which it is necessary to maintain the distinction between A.M. and P.M. An example is Japanese, in which the A.M. and P.M. designators differ in the second character instead of the first character.
      /// @remarks For cultures that do not use an A.M. designator, this property returns an empty string.
      auto am_designator(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto date_separator() const noexcept -> const xtd::string&;
      auto date_separator(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto day_names() const noexcept -> const xtd::array<xtd::string>& ;
      auto day_names(const xtd::array<xtd::string>& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto first_day_of_week() const noexcept -> xtd::day_of_week;
      auto first_day_of_week(xtd::day_of_week value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto full_date_time_pattern() const noexcept -> const xtd::string&;
      auto full_date_time_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto long_date_pattern() const noexcept -> const xtd::string&;
      auto long_date_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto long_time_pattern() const noexcept -> const xtd::string&;
      auto long_time_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto month_day_pattern() const noexcept -> const xtd::string&;
      auto month_day_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto month_genitive_names() const noexcept -> const xtd::array<xtd::string>& ;
      auto month_genitive_names(const xtd::array<xtd::string>& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto month_names() const noexcept -> const xtd::array<xtd::string>& ;
      auto month_names(const xtd::array<xtd::string>& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto native_calendar_name() const noexcept -> const xtd::string&;
      auto native_calendar_name(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto pm_designator() const noexcept -> const xtd::string&;
      auto pm_designator(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto rfc_1123_pattern() const noexcept -> const xtd::string&;
      auto rfc_1123_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto short_date_pattern() const noexcept -> const xtd::string&;
      auto short_date_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto short_time_pattern() const noexcept -> const xtd::string&;
      auto short_time_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto shortest_day_names() const noexcept -> const xtd::array<xtd::string>& ;
      auto shortest_day_names(const xtd::array<xtd::string>& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto sortable_date_time_pattern() const noexcept -> const xtd::string&;
      auto sortable_date_time_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto time_separator() const noexcept -> const xtd::string&;
      auto time_separator(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto universal_sortable_date_time_pattern() const noexcept -> const xtd::string&;
      auto universal_sortable_date_time_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      
      [[nodiscard]] auto year_month_pattern() const noexcept -> const xtd::string&;
      auto year_month_pattern(const xtd::string& value) noexcept -> xtd::globalization::date_time_format_info&;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a read-only xtd::globalization::date_time_format_info object that formats values based on the current culture.
      /// @return A read-only xtd::globalization::date_time_format_info object based on the xtd::globalization::culture_info object for the current thread.
      /// @remarks The xtd::globalization::date_time_format_info object returned by the xtd::globalization::date_time_format_info::current_info property reflects user overrides.
      [[nodiscard]] static auto current_info() noexcept -> const xtd::globalization::date_time_format_info&;

      /// @brief Gets the default read-only xtd::globalization::date_time_format_info object that is culture-independent (invariant).
      /// @return A read-only object that is culture-independent (invariant).
      /// @remarks This property does not change, regardless of the current culture. Because of this, the invariant culture's xtd::globalization::date_time_format_info object can be used to produce consistent, culture-independent results in parsing and formatting operations on data that is multi-cultural. For example, if date and time data from multiple cultures is to be persisted in string form, it can be formatted by using the xtd::globalization::date_time_format_info object of the invariant culture and saved. It can then be parsed by using the invariant culture's xtd::globalization::date_time_format_info object.
      [[nodiscard]] static auto invariant_info() noexcept -> const xtd::globalization::date_time_format_info&;
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
      auto operator =(xtd::globalization::date_time_format_info&& culture) -> xtd::globalization::date_time_format_info& = default;
      auto operator =(const xtd::globalization::date_time_format_info& culture) -> xtd::globalization::date_time_format_info&;
      /// @endcond
      
    private:
      friend class culture_info;
      date_time_format_info(xtd::array<xtd::string>&& abreviated_day_names, xtd::array<xtd::string>&& abreviated_genitive_month_names, xtd::array<xtd::string>&& abreviated_month_names, xtd::string&& am_designator, xtd::string&& date_separator, xtd::array<xtd::string>&& day_names, xtd::day_of_week first_day_of_week, xtd::string&& full_date_time_pattern, xtd::string&& long_date_pattern, xtd::string&& long_time_pattern, xtd::string&& month_day_pattern, xtd::array<xtd::string>&& month_genitive_names, xtd::array<xtd::string>&& month_names, xtd::string&& native_calendar_name, xtd::string&& pm_designator, xtd::string&& rfc_1123_pattern, xtd::string&& short_date_pattern, xtd::string&& short_time_pattern, xtd::array<xtd::string>&& shortest_day_names, xtd::string&& sortable_date_time_pattern, xtd::string&& time_separator, xtd::string&& universal_sortable_date_time_pattern, xtd::string&& year_month_pattern);
      static xtd::collections::generic::dictionary<xtd::string, xtd::globalization::date_time_format_info>& formats();
      
      struct data;
      xtd::ptr<data> data_;
    };
  }
}
