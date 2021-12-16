/// @file
/// @brief Contains xtd::forms::month_calendar_styles enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which month_calendar styles is used.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the month_calendar class.
    enum class month_calendar_styles {
      /// @brief The cause of the closure was not defined or could not be determined.
      none = 0b0,
      /// @brief Show Sunday as the first day of the week (default)
      show_sunday_first = 0b1,
      /// @brief Show Monday as the first day of the week
      show_monday_first = 0b10,
      /// @brief Highlight holidays
      show_holidays = 0b100,
      /// @brief Disable the year change control, show only the month change one
      /// @deprecated in wxWidgets
      no_year_change = 0b1000,
      /// @brief Don't allow changing neither month nor year (implies  no_year_change)
      no_month_year_change = 0b10000,
      /// @brief Use MS-style month-selection instead of combo-spin combination
      sequential_month_selection = 0b100000,
      //// @brief Show the neighbouring weeks in the previous and next month
      show_surrounding_weeks = 0b1000000,
      /// @brief Show week numbers on the left side of the calendar.
      show_week_numbers = 0b10000000,
      /// @brief All styles except none and no_year_change.
      all = show_sunday_first | show_monday_first | show_holidays | no_month_year_change | sequential_month_selection | show_surrounding_weeks | show_week_numbers
    };

    /// @cond
    inline month_calendar_styles& operator +=(month_calendar_styles& lhs, month_calendar_styles rhs) {lhs = static_cast<month_calendar_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline month_calendar_styles& operator -=(month_calendar_styles& lhs, month_calendar_styles rhs) {lhs = static_cast<month_calendar_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline month_calendar_styles& operator &=(month_calendar_styles& lhs, month_calendar_styles rhs) {lhs = static_cast<month_calendar_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline month_calendar_styles& operator |=(month_calendar_styles& lhs, month_calendar_styles rhs) {lhs = static_cast<month_calendar_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline month_calendar_styles& operator ^=(month_calendar_styles& lhs, month_calendar_styles rhs) {lhs = static_cast<month_calendar_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline month_calendar_styles operator +(month_calendar_styles lhs, month_calendar_styles rhs) {return static_cast<month_calendar_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline month_calendar_styles operator -(month_calendar_styles lhs, month_calendar_styles rhs) {return static_cast<month_calendar_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline month_calendar_styles operator ~(month_calendar_styles rhs) {return static_cast<month_calendar_styles>(~static_cast<long long>(rhs));}
    inline month_calendar_styles operator &(month_calendar_styles lhs, month_calendar_styles rhs) {return static_cast<month_calendar_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline month_calendar_styles operator |(month_calendar_styles lhs, month_calendar_styles rhs) {return static_cast<month_calendar_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline month_calendar_styles operator ^(month_calendar_styles lhs, month_calendar_styles rhs) {return static_cast<month_calendar_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, const month_calendar_styles value) { return os << to_string(value, { {month_calendar_styles::none, "none"}, {month_calendar_styles::show_sunday_first, "show_sunday_first"}, {month_calendar_styles::show_monday_first, "show_monday_first"}, {month_calendar_styles::show_holidays, "show_holidays"}, {month_calendar_styles::no_year_change, "no_year_change"}, {month_calendar_styles::no_month_year_change, "no_month_year_change"}, {month_calendar_styles::sequential_month_selection, "sequential_month_selection"}, {month_calendar_styles::show_surrounding_weeks, "show_surrounding_weeks"}, {month_calendar_styles::show_week_numbers, "show_week_numbers"}, {month_calendar_styles::all, "all"} }); }
    inline std::wostream& operator<<(std::wostream& os, const month_calendar_styles value) { return os << to_string(value, { {month_calendar_styles::none, L"none"}, {month_calendar_styles::show_sunday_first, L"show_sunday_first"}, {month_calendar_styles::show_monday_first, L"show_monday_first"}, {month_calendar_styles::show_holidays, L"show_holidays"}, {month_calendar_styles::no_year_change, L"no_year_change"}, {month_calendar_styles::no_month_year_change, L"no_month_year_change"}, {month_calendar_styles::sequential_month_selection, L"sequential_month_selection"}, {month_calendar_styles::show_surrounding_weeks, L"show_surrounding_weeks"}, {month_calendar_styles::show_week_numbers, L"show_week_numbers"}, {month_calendar_styles::all, L"all"} }); }
    /// @endcond
  }
}

/*
enum
{
  // show Sunday as the first day of the week (default)
  wxCAL_SUNDAY_FIRST = 0x0080,

  // show Monday as the first day of the week
  wxCAL_MONDAY_FIRST = 0x0001,

  // highlight holidays
  wxCAL_SHOW_HOLIDAYS = 0x0002,

  // disable the year change control, show only the month change one
  // deprecated
  wxCAL_NO_YEAR_CHANGE = 0x0004,

  // don't allow changing neither month nor year (implies
  // wxCAL_NO_YEAR_CHANGE)
  wxCAL_NO_MONTH_CHANGE = 0x000c,

  // use MS-style month-selection instead of combo-spin combination
  wxCAL_SEQUENTIAL_MONTH_SELECTION = 0x0010,

  // show the neighbouring weeks in the previous and next month
  wxCAL_SHOW_SURROUNDING_WEEKS = 0x0020,

  // show week numbers on the left side of the calendar.
  wxCAL_SHOW_WEEK_NUMBERS = 0x0040
};*/