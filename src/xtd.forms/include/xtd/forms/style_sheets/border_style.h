/// @file
/// @brief Contains xtd::forms::style_sheets::border_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      enum class border_style {
        none,
        dashed,
        dot_dash,
        dot_dot_dash,
        dotted,
        double_style,
        groove,
        inset,
        outset,
        ridge,
        solid,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, const border_style value) {return os << to_string(value, {{border_style::none, "none,"}, {border_style::dashed, "dashed,"}, {border_style::dot_dash, "dot_dash,"}, {border_style::dot_dot_dash, "dot_dot_dash,"}, {border_style::dotted, "dotted,"}, {border_style::double_style, "double_style,"}, {border_style::groove, "groove,"}, {border_style::inset, "inset,"}, {border_style::outset, "outset,"}, {border_style::ridge, "ridge,"}, {border_style::solid, "solid,"}});}
      inline std::wostream& operator<<(std::wostream& os, const border_style value) {return os << to_string(value, {{border_style::none, L"none,"}, {border_style::dashed, L"dashed,"}, {border_style::dot_dash, L"dot_dash,"}, {border_style::dot_dot_dash, L"dot_dot_dash,"}, {border_style::dotted, L"dotted,"}, {border_style::double_style, L"double_style,"}, {border_style::groove, L"groove,"}, {border_style::inset, L"inset,"}, {border_style::outset, L"outset,"}, {border_style::ridge, L"ridge,"}, {border_style::solid, L"solid,"}});}
      /// @endcond
    }
  }
}
