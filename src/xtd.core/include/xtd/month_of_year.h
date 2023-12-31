/// @file
/// @brief Contains xtd::month_of_year enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the month of the year.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
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
}

/// @cond
template<> struct xtd::enum_register<xtd::month_of_year> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::month_of_year> {{xtd::month_of_year::january, "january"}, {xtd::month_of_year::february, "february"}, {xtd::month_of_year::march, "march"}, {xtd::month_of_year::april, "april"}, {xtd::month_of_year::may, "may"}, {xtd::month_of_year::june, "june"}, {xtd::month_of_year::july, "july"}, {xtd::month_of_year::august, "august"}, {xtd::month_of_year::september, "september"}, {xtd::month_of_year::october, "october"}, {xtd::month_of_year::november, "november"}, {xtd::month_of_year::december, "december"}};}
};
/// @endcond
