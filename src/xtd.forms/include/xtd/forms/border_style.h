/// @file
/// @brief Contains xtd::forms::border_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
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
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, const border_style value) {return os << to_string(value, {{border_style::hidden, "hidden"}, {border_style::fixed_single, "fixed_single"}, {border_style::fixed_3d, "fixed_3d"}, {border_style::none, "none"}, {border_style::solid, "solid"}, {border_style::inset, "inset"}, {border_style::outset, "outset"}, {border_style::groove, "groove"}, {border_style::ridge, "ridge"}, {border_style::theme, "theme"}, {border_style::dashed, "dashed"}, {border_style::dot_dash, "dot_dash"}, {border_style::dot_dot_dash, "dot_dot_dash"}, {border_style::dotted, "dotted"}, {border_style::double_border, "double_border"}, {border_style::bevel_inset, "bevel_inset"}, {border_style::bevel_outset, "bevel_outset"}, {border_style::rounded, "rounded"}});}
    inline std::wostream& operator<<(std::wostream& os, const border_style value) {return os << to_string(value, {{border_style::hidden, L"hidden"}, {border_style::fixed_single, L"fixed_single"}, {border_style::fixed_3d, L"fixed_3d"}, {border_style::none, L"none"}, {border_style::solid, L"solid"}, {border_style::inset, L"inset"}, {border_style::outset, L"outset"}, {border_style::groove, L"groove"}, {border_style::ridge, L"ridge"}, {border_style::theme, L"theme"}, {border_style::dashed, L"dashed"}, {border_style::dot_dash, L"dot_dash"}, {border_style::dot_dot_dash, L"dot_dot_dash"}, {border_style::dotted, L"dotted"}, {border_style::double_border, L"double_border"}, {border_style::bevel_inset, L"bevel_inset"}, {border_style::bevel_outset, L"bevel_outset"}, {border_style::rounded, L"rounded"}});}
    /// @endcond
  }
}
