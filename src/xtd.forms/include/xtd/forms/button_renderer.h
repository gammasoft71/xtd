/// @file
/// @brief Contains xtd::forms::button_renderer class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export"
#include "box_renderer"
#include "flat_button_appearance"
#include "flat_style"
#include "text_renderer"
#include "visual_styles/push_button_state"
#include <xtd/optional>
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <string>
/// @todo to remove
#include <xtd/drawing/system_fonts>
#include "application"
#include "flat_button_appearance"
#include "text_format_flags"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides button control renderer methods.
    /// @code
    /// class forms_export_ button_renderer static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static → xtd::forms::button_renderer
    /// @par Header
    /// @code #include <xtd/forms/button_renderer> @endcode
    /// @par Namespace
    /// xtd::forms:
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ button_renderer final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Draws a button in the specified bounds.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
      /// @brief Draws a button in the specified bounds.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      static void draw_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds);
      /// @brief Draws a button in the specified bounds, button style and button state.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button);
      /// @brief Draws a button in the specified bounds, button style and button state.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      static void draw_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button);
      /// @brief Draws a button in the specified bounds, button style, button state and background color.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color);
      /// @brief Draws a button in the specified bounds, button style, button state and background color.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color);
      /// @brief Draws a button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font);
      /// @brief Draws a button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font);
      /// @brief Draws a button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      /// @brief Draws a button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a button.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      /// @brief Draws a flat button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a button.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_flat_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const flat_button_appearance& appearance, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      /// @brief Draws a popup button in the specified bounds, button style, button state, background color, text, optional text flags, optional foreground color and optional font.
      /// @param style_sheet The xtd::forms::style_sheets::style_sheet used to draw a button.
      /// @param graphics The xtd::drawing::graphics used to draw a button.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the button.
      /// @param button_state The visual state of a button that is drawn with visual styles.
      /// @param default_button Sets to tru if the buffon is default; otherwise false.
      /// @param back_color The background color for the button control.
      /// @param text The text of the button control.
      /// @param text_flags Contains the display and layout information for text strings.
      /// @param fore_color The foreground color for the button control.
      /// @param font The font of the text for the button control.
      /// @param image The image of the button control.
      /// @param image_align Contains the display and layout information for image .
      /// @remarks The parameter back_color is set only if they are different from its default value; otherwise std::nullopt.
      static void draw_popup_button(const style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state button_state, bool default_button, const std::optional<xtd::drawing::color>& back_color, const flat_button_appearance& appearance, const xtd::ustring& text, const std::optional<xtd::forms::content_alignment>& text_align, const std::optional<xtd::drawing::color>& fore_color, const std::optional<xtd::drawing::font>& font, const xtd::drawing::image& image, const std::optional<xtd::forms::content_alignment>& image_align);
      
      /// @cond
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state& state) {draw_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::push_button_state& state) {draw_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(default_theme(), g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {draw_button(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state& state) {draw_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::push_button_state& state) {draw_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(theme, g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_button(theme, g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state& state) {draw_flat_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::push_button_state& state) {draw_flat_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_flat_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_flat_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_flat_button(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_flat_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_flat_button(g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_flat_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
      
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::push_button_state& state) {draw_popup_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::push_button_state& state) {draw_popup_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_popup_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_popup_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_popup_button(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_popup_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state) {draw_popup_button(g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text(), flat_button_appearance());}
      static void draw_popup_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
      /// @endcond
      
    private:
      static xtd::ustring default_theme() {return application::style_sheet().theme().name();}
      static void draw_button_kde(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_kde_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_kde_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_gnome(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_gnome_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_gnome_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_macos(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_macos_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_macos_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_symbolic(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_symbolic_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_symbolic_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_windows(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_windows_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_windows_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_xtd(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_xtd_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_button_xtd_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_flat_button_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
      static void draw_flat_button_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
      static void draw_popup_button_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
      static void draw_popup_button_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color, const flat_button_appearance& flat_appearance);
    };
  }
}
