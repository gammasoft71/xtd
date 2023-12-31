/// @file
/// @brief Contains xtd::drawing::dash_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the style of dashed lines drawn with a xtd::drawing::pen object.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    /// @remarks To define a custom dash_style, set the dash_pattern property of the xtd::drawing::pen.
    enum class dash_style {
      /// @brief Specifies a solid line.
      solid = 0,
      /// @brief Specifies a line consisting of dashes.
      dash,
      /// @brief Specifies a line consisting of dots.
      dot,
      /// @brief Specifies a line consisting of a repeating pattern of dash-dot.
      dash_dot,
      /// @brief Specifies a line consisting of a repeating pattern of dash-dot-dot.
      dash_dot_dot,
      /// @brief Specifies a user-defined custom dash style.
      custom
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::dash_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::dash_style> {{xtd::drawing::dash_style::solid, "solid"}, {xtd::drawing::dash_style::dash, "dash"}, {xtd::drawing::dash_style::dot, "dot"}, {xtd::drawing::dash_style::dash_dot, "dash_dot"}, {xtd::drawing::dash_style::dash_dot_dot, "dash_dot_dot"}};}
};
/// @endcond
