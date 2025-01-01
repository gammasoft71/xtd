/// @file
/// @brief Contains xtd::forms::toggle_button_renderer static class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/toggle_button_state.hpp"
#include "border_sides.hpp"
#include "border_style.hpp"
#include "box_renderer.hpp"
#include "content_alignment.hpp"
#include "flat_button_appearance.hpp"
#include "flat_style.hpp"
#include <xtd/drawing/graphics>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides xtd::forms::toggle_button renderer methods.
    /// ```cpp
    /// class forms_export_ toggle_button_renderer static_
    /// ```
    /// @par Inheritance
    /// xtd::static → xtd::forms::toggle_button_renderer
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/toggle_button_renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms::style_sheets
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class toggle_button_renderer static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Draws a box in the specified style_sheet, bounds, control state and background color.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param graphics The Graphics used to draw a control.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the control.
      /// @param toggle_state The visual state of a control that is drawn with visual styles.
      /// @param back_color The background color for the control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_toggle_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::toggle_button_state toggle_state, const std::optional<xtd::drawing::color>& back_color, const xtd::string& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      static void draw_flat_toggle_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::toggle_button_state toggle_state, const std::optional<xtd::drawing::color>& back_color, const flat_button_appearance& flat_appearance, const xtd::string& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      static void draw_popup_toggle_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::toggle_button_state toggle_state, const std::optional<xtd::drawing::color>& back_color, const flat_button_appearance& flat_appearance, const xtd::string& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      /// @}
    };
  }
}
