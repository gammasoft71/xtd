/// @file
/// @brief Contains xtd::forms::form_renderer static class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/form_state.h"
#include "flat_style.h"
#include "box_renderer.h"
#include <xtd/drawing/graphics>
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides form control renderer methods.
    /// @code
    /// class forms_export_ form_renderer static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static → xtd::forms::form_renderer
    /// @par Header
    /// @code #include <xtd/forms/form_renderer> @endcode
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class form_renderer static_ {
    public:
      /// @brief Draws a box in the specified bounds, form state and background color.
      /// @param graphics The xtd::drawing::graphics used to draw a form control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the form control.
      /// @param form_state The visual state of a form that is drawn with visual styles.
      /// @param back_color The background color for the form control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_form(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::form_state form_state, const std::optional<xtd::drawing::color>& back_color);
    };
  }
}
