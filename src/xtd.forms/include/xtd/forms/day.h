/// @file
/// @brief Contains xtd::forms::day enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the day of the week.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class day {
      /// @brief The day monday.
      monday,
      /// @brief The day tuesday.
      tuesday,
      /// @brief The day wednesday.
      wednesday,
      /// @brief The day thursday.
      thursday,
      /// @brief The day friday.
      friday,
      /// @brief The day saturday.
      saturday,
      /// @brief The day sunday.
      sunday,
      /// @brief A default day of the week specified by the application.
      default_day
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, const day value) {return os << to_string(value, {{day::monday, "monday"}, {day::tuesday, "tuesday"}, {day::wednesday, "wednesday"}, {day::thursday, "thursday"}, {day::friday, "friday"}, {day::saturday, "saturday"}, {day::sunday, "sunday"}, {day::default_day, "default_day"}});}
    inline std::wostream& operator<<(std::wostream& os, const day value) {return os << to_string(value, {{day::monday, L"monday"}, {day::tuesday, L"tuesday"}, {day::wednesday, L"wednesday"}, {day::thursday, L"thursday"}, {day::friday, L"friday"}, {day::saturday, L"saturday"}, {day::sunday, L"sunday"}, {day::default_day, L"default_day"}});}
    /// @endcond
  }
}
