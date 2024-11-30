/// @file
/// @brief Contains xtd::forms::label_renderer static class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/label_state.hpp"
#include "visual_styles/link_label_state.hpp"
#include "content_alignment.hpp"
#include "border_sides.hpp"
#include "border_style.hpp"
#include "link_behavior.hpp"
#include "link.hpp"
#include "box_renderer.hpp"
#include "shadow.hpp"
#include <xtd/drawing/graphics>
#include <xtd/static>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides label control renderer methods.
    /// ```cpp
    /// class forms_export_ label_renderer static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::label_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/label_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class label_renderer static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws a box in the specified bounds, label style, label state and background color.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a label.
      /// @param graphics The xtd::drawing::graphics used to draw a label.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
      /// @param label_state The visual state of a label that is drawn with visual styles.
      /// @param back_color The background color for the label control.
      /// @param text The text of the label control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the label control.
      /// @param font The font of the text for the label control.
      /// @param image The image of the label control.
      /// @param image_align Contains the display and layout information for image .
      /// @param border Contains the border style for the control
      /// @param side Contains the border sides for the control.
      /// @param shadows An xtd::forms::shadow array used to draw shadows under the text.
      /// @param auto_ellipsis The value indicating whether the ellipsis character (...) appears at the right edge of the xtd::forms::label, denoting that the xtd::forms::label text extends beyond the specified length of the xtd::forms::label.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_label(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::label_state label_state, const std::optional<xtd::drawing::color>& back_color, const xtd::string& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides, const std::vector<xtd::forms::shadow>& shadows, bool auto_ellipsis);
      /// @brief Draws a box in the specified bounds, label style, label state and background color.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a label.
      /// @param graphics The xtd::drawing::graphics used to draw a label.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the label.
      /// @param label_state The visual state of a label that is drawn with visual styles.
      /// @param back_color The background color for the label control.
      /// @param text The text of the label control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the label control.
      /// @param font The font of the text for the label control.
      /// @param image The image of the label control.
      /// @param image_align Contains the display and layout information for image .
      /// @param border Contains the border style for the control
      /// @param side Contains the border sides for the control.
      /// @param shadows An xtd::forms::shadow array used to draw shadows under the text.
      /// @param auto_ellipsis The value indicating whether the ellipsis character (...) appears at the right edge of the xtd::forms::label, denoting that the xtd::forms::label text extends beyond the specified length of the xtd::forms::label.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_link_label(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::link_label_state link_label_state, const std::optional<xtd::drawing::color>& back_color, const xtd::string& text, const std::vector<xtd::forms::link>& links, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::color>& link_color, const std::optional<xtd::drawing::color>& visited_link_color, const std::optional<xtd::drawing::font>& font, xtd::forms::link_behavior link_behavior, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align, const std::optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides, const std::vector<xtd::forms::shadow>& shadows, bool auto_ellipsis);
      /// @}
    };
  }
}
