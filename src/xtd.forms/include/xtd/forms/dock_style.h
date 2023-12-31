/// @file
/// @brief Contains xtd::forms::dock_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the position and manner in which a control is docked.
    /// @par Header
    /// @code #include <xtd/forms/dock_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks When a control is docked to an edge of its container, it is always positioned flush against that edge when the container is resized. If more than one control is docked to an edge, the controls appear side by side according to their z-order; controls higher in the z-order are positioned farther from the container's edge.
    /// @remarks If left, right, top, or bottom is selected, the specified and opposite edges of the control are resized to the size of the containing control's corresponding edges. If fill is selected, all four sides of the control are resized to match the containing control's edges.
    enum class dock_style {
      /// @brief The control is not docked.
      none = 0,
      /// @brief The control's top edge is docked to the top of its containing control.
      top = 1,
      /// @brief The control's bottom edge is docked to the bottom of its containing control.
      bottom = 2,
      /// @brief The control's left edge is docked to the left edge of its containing control.
      left = 3,
      /// @brief The control's right edge is docked to the right edge of its containing control.
      right = 4,
      /// @brief All the control's edges are docked to the all edges of its containing control and sized appropriately.
      fill = 5,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::dock_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::dock_style> {{xtd::forms::dock_style::none, "none"}, {xtd::forms::dock_style::top, "top"}, {xtd::forms::dock_style::bottom, "bottom"}, {xtd::forms::dock_style::left, "left"}, {xtd::forms::dock_style::right, "right"}, {xtd::forms::dock_style::fill, "fill"}};}
};
/// @endcond
