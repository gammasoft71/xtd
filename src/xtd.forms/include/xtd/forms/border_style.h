/// @file
/// @brief Contains xtd::forms::border_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border style for a control.
    /// @par Header
    /// @code #include <xtd/forms/border_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the border style for controls that have a changeable border.
    enum class border_style {
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
      /// @brief A bevel inset border.
      bevel_inset,
      /// @brief A bevel outset border.
      bevel_outset,
      /// @brief A rounded line border.
      rounded,
      /// @brief A single-line border. Same as xtd::forms::border_style::solid
      fixed_single = solid,
      /// @brief A three-dimensional border. Same as xtd::forms::border_style::inset.
      fixed_3d = inset,
      /// @brief A sunken border. Same as xtd::forms::border_style::inset.
      sunken = inset,
      /// @brief A raised border. Same as xtd::forms::border_style::outset.
      raised = outset,
      /// @brief A bevel sunken border. Same as xtd::forms::border_style::bevel_inset.
      bevel_sunken = bevel_inset,
      /// @brief A bevel raised border. Same as xtd::forms::border_style::bevel_outset.
      bevel_raised = bevel_outset,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::border_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::border_style> {{xtd::forms::border_style::hidden, "hidden"}, {xtd::forms::border_style::fixed_single, "fixed_single"}, {xtd::forms::border_style::fixed_3d, "fixed_3d"}, {xtd::forms::border_style::none, "none"}, {xtd::forms::border_style::solid, "solid"}, {xtd::forms::border_style::inset, "inset"}, {xtd::forms::border_style::outset, "outset"}, {xtd::forms::border_style::groove, "groove"}, {xtd::forms::border_style::ridge, "ridge"}, {xtd::forms::border_style::theme, "theme"}, {xtd::forms::border_style::dashed, "dashed"}, {xtd::forms::border_style::dot_dash, "dot_dash"}, {xtd::forms::border_style::dot_dot_dash, "dot_dot_dash"}, {xtd::forms::border_style::dotted, "dotted"}, {xtd::forms::border_style::double_border, "double_border"}, {xtd::forms::border_style::bevel_inset, "bevel_inset"}, {xtd::forms::border_style::bevel_outset, "bevel_outset"}, {xtd::forms::border_style::rounded, "rounded"}};}
};
/// @endcond
