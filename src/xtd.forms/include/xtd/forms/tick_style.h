/// @file
/// @brief Contains xtd::forms::tick_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the location of tick marks in a track_bar control.
    /// @par Header
    /// @code #include <xtd/forms/tick_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the tick_style property of the track_bar control.
    enum class tick_style {
      /// @brief No tick marks appear in the control.
      none = 0,
      /// @brief Tick marks are located on the top of a horizontal control or on the left of a vertical control.
      top_left = 1,
      /// @brief Tick marks are located on the bottom of a horizontal control or on the right side of a vertical control.
      bottom_right = 2,
      /// @brief Tick marks are located on both sides of the control.
      both = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::tick_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::tick_style> {{xtd::forms::tick_style::none, "none"}, {xtd::forms::tick_style::top_left, "top_left"}, {xtd::forms::tick_style::bottom_right, "bottom_right"}, {xtd::forms::tick_style::both, "both"}};}
};
/// @endcond
