/// @file
/// @brief Contains xtd::forms::style_sheets::border_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <xtd/drawing/graphics.h>
#include "border_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides methods used to render a border with or without style sheets.
      /// @code
      /// class forms_export_ border_renderer static_
      /// @endcode
      /// @par Inheritance
      /// xtd::static → xtd::forms::style_sheets::border_renderer
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_renderer static_ {
      public:
        /// @brief Draws a border in the specified bounds.
        /// @param graphics The Graphics used to draw a border.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the border.
        static void draw_border(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
        /// @brief Draws a border in the specified bounds and style.
        /// @param graphics The Graphics used to draw a border.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the border.
        /// @param data The xtd::forms::style_sheets::border_data that specifies the style for the four borders.
        static void draw_border(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::border_data& data);
        /// @brief Draws a border in the specified bounds and styles.
        /// @param graphics The Graphics used to draw a boder.
        /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the border.
        /// @param data The xtd::forms::style_sheets::border_data that specifies the style for each border.
        static void draw_border(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data);
        
      private:
        static void draw_line_top(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data);
        static void draw_line_right(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data);
        static void draw_line_bottom(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data);
        static void draw_line_left(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data);
        static xtd::drawing::dash_style border_style_to_dash_style(xtd::forms::style_sheets::border_style value);
      };
    }
  }
}
