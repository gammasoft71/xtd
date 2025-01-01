/// @file
/// @brief Contains xtd::forms::tool_bar_renderer static class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/form_state.hpp"
#include "border_sides.hpp"
#include "border_style.hpp"
#include "box_renderer.hpp"
#include "flat_style.hpp"
#include <xtd/drawing/graphics>
#include <xtd/static>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides tool_bar control renderer methods.
    /// ```cpp
    /// class forms_export_ tool_bar_renderer static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::tool_bar_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/tool_bar_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class tool_bar_renderer static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws a box in the specified bounds, form state and background color.
      /// @param graphics The Graphics used to draw a form.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form.
      /// @param graphics The Graphics used to draw a form control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
      /// @param form_state The visual state of a form that is drawn with visual styles.
      /// @param back_color The background color for the form control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_tool_bar(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::form_state form_state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides);
      /// @}
    };
  }
}
