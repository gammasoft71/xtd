/// @file
/// @brief Contains xtd::forms::border_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border style for a control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class border_style {
      /// @brief No border.
      none = 0,
      /// @brief A single-line border.
      fixed_single = 1,
      /// @brief A three-dimensional border.
      fixed_3d = 2,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, border_style value) {return os << to_string(value, {{border_style::none, "none"}, {border_style::fixed_single, "fixed_single"}, {border_style::fixed_3d, "fixed_3d"}});}
    inline std::wostream& operator<<(std::wostream& os, border_style value) {return os << to_string(value, {{border_style::none, L"none"}, {border_style::fixed_single, L"fixed_single"}, {border_style::fixed_3d, L"fixed_3d"}});}
    /// @endcond
  }
}
