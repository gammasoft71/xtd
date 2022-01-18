/// @file
/// @brief Contains xtd::forms::style_sheets::box_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"
#include "border_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides methods used to render a box with or without style sheets.
      /// @code
      /// class forms_export_ box_renderer static_
      /// @endcode
      /// @par Inheritance
      /// xtd::static → xtd::forms::style_sheets::box_renderer
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
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
      };
    }
  }
}
