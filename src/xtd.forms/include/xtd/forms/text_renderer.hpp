/// @file
/// @brief Contains xtd::forms::text_renderer static class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "style_sheets/ibox_model.hpp"
#include "style_sheets/itext_model.hpp"
#include <xtd/drawing/graphics>
#include <xtd/drawing/rectangle>
#include <xtd/static>
#include <xtd/string>
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides methods used to render a text with style sheets.
    /// ```cpp
    /// class forms_export_ text_renderer static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::text_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/text_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ text_renderer static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws shadow text.
      /// @param graphics The xtd::drawing::graphics used to draw text.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the text.
      /// @param text The xtd::string text to draw.
      /// @param data The xtd::forms::style_sheets::itext_model class wish contains informations about how to draw the the text.
      /// @param box xtd::forms::style_sheets::ibox_model class that contains the background color of the control.
      static void draw_shadow_text(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::forms::style_sheets::itext_model& data, const xtd::forms::style_sheets::ibox_model& box);
      /// @brief Draws text.
      /// @param graphics The xtd::drawing::graphics used to draw text.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the text.
      /// @param text The xtd::string text to draw.
      /// @param data The xtd::forms::style_sheets::itext_model class wish contains informations about how to draw the the text.
      static void draw_text(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::forms::style_sheets::itext_model& data);
      
      static void draw_shadow_text_and_links(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::forms::style_sheets::itext_model& data, const xtd::forms::style_sheets::ibox_model& box);
      static void draw_text_and_links(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::forms::style_sheets::itext_model& data);
      /// @}
    };
  }
}
