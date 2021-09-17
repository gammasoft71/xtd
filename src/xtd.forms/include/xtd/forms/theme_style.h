/// @file
/// @brief Contains xtd::forms::theme_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the style of theme.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the theme_style property of the theme classl.
    enum theme_style {
      system_auto = 0,
      undefined = 0,
      light,
      dark,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, theme_style value) {return os << to_string(value, {{theme_style::system_auto, "system_auto"}, {theme_style::light, "light"}, {theme_style::dark, "dark"}});}
    inline std::wostream& operator<<(std::wostream& os, theme_style value) {return os << to_string(value, {{theme_style::system_auto, L"system_auto"}, {theme_style::light, L"light"}, {theme_style::dark, L"dark"}});}
    /// @endcond
  }
}
