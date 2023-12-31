/// @file
/// @brief Contains xtd::forms::style_sheets::border_type enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The border_type enum class specifies what kind of border to display.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/border_type> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class border_type {
        /// @brief Defines no border.
        none,
        /// @brief Defines a hidden border.
        hidden = none,
        /// @brief Defines a solid border
        solid,
        /// @brief Defines a 3D inset border. The effect depends on the border color value.
        inset,
        /// @brief Defines a 3D outset border. The effect depends on the border color value.
        outset,
        /// @brief Defines a 3D grooved border. The effect depends on the border color value.
        groove,
        /// @brief Defines a 3D ridged border. The effect depends on the border color value.
        ridge,
        /// @brief Defines a 3D themed border. The effect depends on the border color value.
        theme,
        /// @brief Defines a dashed border.
        dashed,
        /// @brief Defines a dot dashed border.
        dot_dash,
        /// @brief Defines a dot dot dashed border.
        dot_dot_dash,
        /// @brief Defines a dotted border.
        dotted,
        /// @brief Defines a double border.
        double_border,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::style_sheets::border_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::border_type> {{xtd::forms::style_sheets::border_type::hidden, "hidden"}, {xtd::forms::style_sheets::border_type::none, "none"}, {xtd::forms::style_sheets::border_type::solid, "solid"}, {xtd::forms::style_sheets::border_type::inset, "inset"}, {xtd::forms::style_sheets::border_type::outset, "outset"}, {xtd::forms::style_sheets::border_type::groove, "groove"}, {xtd::forms::style_sheets::border_type::ridge, "ridge"}, {xtd::forms::style_sheets::border_type::theme, "theme"}, {xtd::forms::style_sheets::border_type::dashed, "dashed"}, {xtd::forms::style_sheets::border_type::dot_dash, "dot_dash"}, {xtd::forms::style_sheets::border_type::dot_dot_dash, "dot_dot_dash"}, {xtd::forms::style_sheets::border_type::dotted, "dotted"}, {xtd::forms::style_sheets::border_type::double_border, "double_border"}};}
};
/// @endcond
