/// @file
/// @brief Contains xtd::forms::bounds_specified enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the bounds of the control to use when defining a control's size and position. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @par Header
    /// @code #include <xtd/forms/bounds_specified> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration when calling the set_bounds_core and set_bounds methods of the control class.
    enum class bounds_specified {
      /// @brief No border.s
      none = 0,
      /// @brief Specifies that the left edge of the control is defined.
      x = 0b1,
      /// @brief Specifies that the top edge of the control is defined.
      y = 0b10,
      /// @brief Specifies that both the x and y coordinates of the control are defined.
      location = x | y,
      /// @brief Specifies that the width of the control is defined.
      width = 0b100,
      /// @brief Specifies that the height of the control is defined.
      height = 0b1000,
      /// @brief Specifies that both the width and height property values of the control are defined.
      size = width | height,
      /// @brief Specifies that both the location and size property values are defined.
      all = location | size,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, bounds_specified);
template<> struct xtd::enum_register<xtd::forms::bounds_specified> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::bounds_specified> {{xtd::forms::bounds_specified::none, "none"}, {xtd::forms::bounds_specified::x, "x"}, {xtd::forms::bounds_specified::y, "y"}, {xtd::forms::bounds_specified::width, "width"}, {xtd::forms::bounds_specified::height, "height"}};}
};
/// @endcond
