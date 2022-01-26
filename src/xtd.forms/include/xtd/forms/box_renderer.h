/// @file
/// @brief Contains xtd::forms::box_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <xtd/drawing/graphics.h>
#include "style_sheets/box_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides methods used to render a box with or without style sheets.
    /// @code
    /// class forms_export_ box_renderer static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static → xtd::forms::box_renderer
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ box_renderer static_ {
    public:
      /// @brief Draws a box in the specified bounds.
      /// @param graphics The Graphics used to draw a box.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the box.
      static void draw_box(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
      /// @brief Draws a box in the specified bounds and style.
      /// @param graphics The Graphics used to draw a box.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the box.
      /// @param data The xtd::forms::style_sheets::box_data that specifies the style for the box.
      static void draw_box(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      
    private:
      static void draw_line_top(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      static void draw_line_right(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      static void draw_line_bottom(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      static void draw_line_left(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      static xtd::drawing::dash_style border_type_to_dash_style(xtd::forms::style_sheets::border_type value);
    };
  }
}
