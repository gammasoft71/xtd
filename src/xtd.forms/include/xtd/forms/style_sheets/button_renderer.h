/// @file
/// @brief Contains xtd::forms::style_sheets::button_data class.
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
#include <xtd/forms/visual_styles/push_button_state.h>
#include "box_renderer.h"
#include "text_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides button renderer methods.
      /// @code
      /// class forms_export_ button_renderer static_
      /// @endcode
      /// @par Inheritance
      /// xtd::static → xtd::forms::style_sheets::button_renderer
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class button_renderer static_ {
      public:
        /// @brief Draws a box in the specified bounds, button style, text, font, text format, image and image bounds.
        /// @param graphics The Graphics used to draw a button.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
        static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style button_style, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags text_format, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds);
        /// @brief Draws a box in the specified bounds, button style, text, font, text format, image, image bounds, fucsed and button state.
        /// @param graphics The Graphics used to draw a button.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
        static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style button_style, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags text_format, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state button_state);
        /// @brief Draws a box in the specified bounds, button style, text, font, text format, image, image bounds, fucsed, button state, background color and text color.
        /// @param graphics The Graphics used to draw a button.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
        static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style button_style, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags text_format, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state button_state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      };
    }
  }
}
