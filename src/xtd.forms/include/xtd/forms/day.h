/// @file
/// @brief Contains xtd::forms::day enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the day of the week.
    /// @par Header
    /// @code #include <xtd/forms/day> @endcode
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::day> {{xtd::forms::day::monday, "monday"}, {xtd::forms::day::tuesday, "tuesday"}, {xtd::forms::day::wednesday, "wednesday"}, {xtd::forms::day::thursday, "thursday"}, {xtd::forms::day::friday, "friday"}, {xtd::forms::day::saturday, "saturday"}, {xtd::forms::day::sunday, "sunday"}, {xtd::forms::day::default_day, "default_day"}};}
};
/// @endcond
