/// @file
/// @brief Contains xtd::month_of_year enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the month of the year.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Example
  /// The following example demonstrates the xtd::date_time::days_in_month method and the xtd::month_of_year enumeration.
  /// @include date_time_days_in_month.cpp
  /// @remarks The xtd::month_of_year enumeration represents the month of the year in calendars that have twelve month per year. The value of the constants in this enumeration ranges from xtd::month_of_year::january to xtd::month_of_year::december. If cast to an integer, its value ranges from one (which indicates xtd::month_of_year::january) to twelve (which indicates xtd::month_of_year::december).
  /// @remarks This enumeration is useful when it is desirable to have a strongly typed specification of the day of the week. For example, this enumeration is the type of the property value for the xtd::date_time::day_of_week and xtd::date_time_offset::day_of_week properties.
  /// @remarks The members of the xtd::month_of_year enumeration are not localized. To return the localized name of the month of the year, call the xtd::date_time::to_string(ustring) method with either the "j" or "J" format strings. The former format string produces the abbreviated month name; the latter produces the full month name.
  enum class month_of_year {
    /// @brief Indicates january.
    january = 1,
    /// @brief Indicates february.
    february,
    /// @brief Indicates march.
    march,
    /// @brief Indicates april.
    april,
    /// @brief Indicates may.
    may,
    /// @brief Indicates june.
    june,
    /// @brief Indicates july.
    july,
    /// @brief Indicates august.
    august,
    /// @brief Indicates september.
    september,
    /// @brief Indicates october.
    october,
    /// @brief Indicates november.
    november,
    /// @brief Indicates december.
    december
  };
  
  /// @cond
  inline std::ostream& operator<<(std::ostream& os, const month_of_year value) {return os << xtd::to_string(value, { {month_of_year::january, "january"}, {month_of_year::february, "february"}, {month_of_year::march, "march"}, {month_of_year::april, "april"}, {month_of_year::may, "may"}, {month_of_year::june, "june"}, {month_of_year::july, "july"}, {month_of_year::august, "august"}, {month_of_year::september, "september"}, {month_of_year::october, "october"}, {month_of_year::november, "november"}, {month_of_year::december, "december"}});}
  inline std::wostream& operator<<(std::wostream& os, const month_of_year value) {return os << xtd::to_string(value, { {month_of_year::january, L"january"}, {month_of_year::february, L"february"}, {month_of_year::march, L"march"}, {month_of_year::april, L"april"}, {month_of_year::may, L"may"}, {month_of_year::june, L"june"}, {month_of_year::july, L"july"}, {month_of_year::august, L"august"}, {month_of_year::september, L"september"}, {month_of_year::october, L"october"}, {month_of_year::november, L"november"}, {month_of_year::december, L"december"}});}
  /// @endcond
}
