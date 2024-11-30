/// @file
/// @brief Contains xtd::forms::status_bar_panel_renderer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/push_button_state.hpp"
#include "../forms_export.hpp"
#include "box_renderer.hpp"
#include "flat_button_appearance.hpp"
#include "text_renderer.hpp"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/optional>

/// @todo to remove
#include "flat_button_appearance.hpp"
#include "text_format_flags.hpp"
#include <xtd/drawing/system_fonts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides status bar panel renderer methods.
    /// ```cpp
    /// class forms_export_ status_bar_panel_renderer final static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::status_bar_panel_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/status_bar_panel_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms:
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ status_bar_panel_renderer final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws a status bar panel in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a button.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param back_color The background color for the button control.
      /// @param appearance The xtd::forms::flat_appearance that represents the flat appearance of the status bar panel.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_status_bar_panel(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::optional<xtd::drawing::color>& back_color, const xtd::string& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      /// @}
    };
  }
}
