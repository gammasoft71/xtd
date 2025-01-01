/// @file
/// @brief Contains xtd::forms::user_control_renderer static class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/control_state.hpp"
#include "border_sides.hpp"
#include "border_style.hpp"
#include "box_renderer.hpp"
#include <xtd/drawing/graphics>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides control renderer methods.
    /// ```cpp
    /// class forms_export_ user_control_renderer static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::user_control_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/user_control_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class user_control_renderer static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws a box in the specified bounds.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      static void draw_user_control(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
      /// @brief Draws a box in the specified bounds and control state.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param control_state The visual state of a control that is drawn with visual styles.
      static void draw_user_control(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::control_state control_state);
      /// @brief Draws a box in the specified bounds, control state and background color.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param control_state The visual state of a control that is drawn with visual styles.
      /// @param back_color The background color for the control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_user_control(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::control_state control_state, const std::optional<xtd::drawing::color>& back_color);
      /// @brief Draws a box in the specified style_sheet, bounds, control state and background color.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param control_state The visual state of a control that is drawn with visual styles.
      /// @param back_color The background color for the control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_user_control(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::control_state control_state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides);
      /// @}
    };
  }
}
