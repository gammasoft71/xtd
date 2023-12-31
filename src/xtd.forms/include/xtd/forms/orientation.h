/// @file
/// @brief Contains xtd::forms::orientation enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the orientation of controls or elements of controls.
    /// @par Header
    /// @code #include <xtd/forms/orientation> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class orientation {
      /// @brief The control or element is oriented horizontally.
      horizontal = 0,
      /// @brief The control or element is oriented vertically.
      vertical = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::orientation> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::orientation> {{xtd::forms::orientation::horizontal, "horizontal"}, {xtd::forms::orientation::vertical, "vertical"}};}
};
/// @endcond
