/// @file
/// @brief Contains xtd::forms::box_renderer static class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "style_sheets/ibox_model.h"
#include <xtd/static>
#include <xtd/drawing/graphics>

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
    /// @par Header
    /// @code #include <xtd/forms/box_renderer> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ box_renderer static_ {
    public:
      /// @brief Draws a box in the specified bounds and style.
      /// @param graphics The Graphics used to draw a box.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the box.
      /// @param box_model The xtd::forms::style_sheets::ibox_model that specifies the style for the box.
      static void draw_box(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::ibox_model& box_model);
      
    private:
      static xtd::drawing::dash_style border_type_to_dash_style(xtd::forms::style_sheets::border_type value);
      static void draw_line_top(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width);
      static void draw_line_right(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width);
      static void draw_line_bottom(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width);
      static void draw_line_left(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_width& border_width);
      static void fill_box(xtd::drawing::graphics& graphics, const xtd::drawing::brush& brush, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::ibox_model& box_model);
    };
  }
}
