/// @file
/// @brief Contains xtd::forms::orientation enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the orientation of controls or elements of controls.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, orientation value) {return os << to_string(value, {{orientation::horizontal, "horizontal"}, {orientation::vertical, "vertical"}});}
    inline std::wostream& operator<<(std::wostream& os, orientation value) {return os << to_string(value, {{orientation::horizontal, L"horizontal"}, {orientation::vertical, L"vertical"}});}
    /// @endcond
  }
}
