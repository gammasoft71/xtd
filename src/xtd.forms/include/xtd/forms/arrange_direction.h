/// @file
/// @brief Contains xtd::forms::arrange_direction enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the direction the system uses to arrange minimized windows.
    /// @par Header
    /// @code #include <xtd/forms/arrange_direction> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the arrange_direction property of the system_information class.
    enum class arrange_direction {
      /// @brief Arranges vertically, from top to bottom.
      down = 0x0004,
      /// @brief Arranges horizontally, from left to right.
      left = 0x0000,
      /// @brief Arranges horizontally, from right to left.
      right = 0x0000,
      /// @brief Arranges vertically, from bottom to top.
      up = 0x0004,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, arrange_direction);

template<> struct xtd::enum_register<xtd::forms::arrange_direction> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::arrange_direction> {{xtd::forms::arrange_direction::down, "down"}, {xtd::forms::arrange_direction::left, "left"}, {xtd::forms::arrange_direction::right, "right"}, {xtd::forms::arrange_direction::up, "up"}};}
};
/// @endcond
