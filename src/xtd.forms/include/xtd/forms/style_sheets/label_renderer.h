/// @file
/// @brief Contains xtd::forms::style_sheets::label_data static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/graphics.h>
#include <xtd/forms/flat_style.h>
#include <xtd/forms/visual_styles/label_state.h>
#include "box_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides label control renderer methods.
      /// @code
      /// class forms_export_ label_renderer static_
      /// @endcode
      /// @par Inheritance
      /// xtd::static → xtd::forms::style_sheets::label_renderer
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class label_renderer static_ {
      public:
        /// @brief Draws a box in the specified bounds.
        /// @param graphics The Graphics used to draw a label.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
        /// @param graphics The Graphics used to draw a label control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label control.
        static void draw_label(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
        /// @brief Draws a box in the specified bounds and label style.
        /// @param graphics The Graphics used to draw a label.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
        /// @param graphics The Graphics used to draw a label control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label control.
        /// @param label_style the flat style appearance of the label control.
        static void draw_label(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style label_style);
        /// @brief Draws a box in the specified bounds, label style and label state.
        /// @param graphics The Graphics used to draw a label.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
        /// @param graphics The Graphics used to draw a label control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label control.
        /// @param label_style the flat style appearance of the label control.
        /// @param label_state The visual state of a label that is drawn with visual styles.
        static void draw_label(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style label_style, xtd::forms::visual_styles::label_state label_state);
        /// @brief Draws a box in the specified bounds, label style, label state and background color.
        /// @param graphics The Graphics used to draw a label.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
        /// @param graphics The Graphics used to draw a label control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label control.
        /// @param label_style the flat style appearance of the label control.
        /// @param label_state The visual state of a label that is drawn with visual styles.
        /// @param back_color The background color for the label control.
        /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
        static void draw_label(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style label_style, xtd::forms::visual_styles::label_state label_state, const std::optional<xtd::drawing::color>& back_color);
      };
    }
  }
}
