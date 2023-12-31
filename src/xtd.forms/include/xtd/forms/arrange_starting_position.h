/// @file
/// @brief Contains xtd::forms::arrange_starting_position enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the starting position that the system uses to arrange minimized windows.
    /// @par Header
    /// @code #include <xtd/forms/arrange_starting_position> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the arrange_starting_position property of the system_information class.
    enum class arrange_starting_position {
      /// @brief Starts at the lower-left corner of the screen, which is the default position.
      bottom_left = 0,
      /// @brief Starts at the lower-right corner of the screen.
      bottom_right = 1,
      /// @brief Starts at the upper-left corner of the screen.
      top_left = 2,
      /// @brief Starts at the upper-right corner of the screen.
      top_right = 3,
      /// @brief Hides minimized windows by moving them off the visible area of the screen.
      hide = 8
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, arrange_starting_position);
/// @endcond

/// @cond
template<> struct xtd::enum_register<xtd::forms::arrange_starting_position> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::arrange_starting_position> {{xtd::forms::arrange_starting_position::bottom_left, "bottom_left"}, {xtd::forms::arrange_starting_position::bottom_right, "bottom_right"}, {xtd::forms::arrange_starting_position::top_left, "top_left"}, {xtd::forms::arrange_starting_position::top_right, "top_right"}, {xtd::forms::arrange_starting_position::hide, "hide"}};}
};
/// @endcond
