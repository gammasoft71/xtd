/// @file
/// @brief Contains xtd::forms::style_sheets::form_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/forms/flat_style.h>
#include <xtd/forms/visual_styles/form_state.h>
#include "box_renderer.h"
#include "text_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides form control renderer methods.
      /// @code
      /// class forms_export_ form_renderer static_
      /// @endcode
      /// @par Inheritance
      /// xtd::static → xtd::forms::style_sheets::form_renderer
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class form_renderer static_ {
      public:
        /// @brief Draws a box in the specified bounds.
        /// @param graphics The Graphics used to draw a form.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form.
        /// @param graphics The Graphics used to draw a form control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
        static void draw_form(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
        /// @brief Draws a box in the specified bounds and form style.
        /// @param graphics The Graphics used to draw a form.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form.
        /// @param graphics The Graphics used to draw a form control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
        /// @param form_style the flat style appearance of the form control.
        static void draw_form(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style form_style);
        /// @brief Draws a box in the specified bounds, form style and form state.
        /// @param graphics The Graphics used to draw a form.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form.
        /// @param graphics The Graphics used to draw a form control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
        /// @param form_style the flat style appearance of the form control.
        /// @param form_state The visual state of a form that is drawn with visual styles.
        static void draw_form(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style form_style, xtd::forms::visual_styles::form_state form_state);
        /// @brief Draws a box in the specified bounds, form style, form state and background color.
        /// @param graphics The Graphics used to draw a form.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form.
        /// @param graphics The Graphics used to draw a form control.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
        /// @param form_style the flat style appearance of the form control.
        /// @param form_state The visual state of a form that is drawn with visual styles.
        /// @param back_color The background color for the form control.
        /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
        static void draw_form(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style form_style, xtd::forms::visual_styles::form_state form_state, const std::optional<xtd::drawing::color>& back_color);
      };
    }
  }
}
