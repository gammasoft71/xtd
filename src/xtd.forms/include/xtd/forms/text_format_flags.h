/// @file
/// @brief Contains xtd::forms::text_format_flags enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the display and layout information for text strings.
    /// @par Header
    /// @code #include <xtd/forms/text_format_flags> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The text_format_flags enumeration is used by the text_renderer when drawing and measuring text. The text_renderer does not support adding tab stops to drawn text, although you can expand existing tab stops using the expand_tabs flag.
    enum class text_format_flags {
      /// @brief Applies the default formatting, which is left-aligned.
      default_format = 0b0,
      /// @brief Adds padding to the bounding rectangle to accommodate overhanging glyphs. This is the default.
      glyph_overhang_padding = 0b0,
      /// @brief Aligns the text on the left side of the clipping area. This is the default.
      left = 0b0,
      /// @brief Aligns the text on the top of the bounding rectangle. This is the default.
      top = 0b0,
      /// @brief Centers the text horizontally within the bounding rectangle.
      horizontal_center = 0b1,
      /// @brief Aligns the text on the right side of the clipping area.
      right = 0b10,
      /// @brief Centers the text vertically, within the bounding rectangle.
      vertical_center = 0b100,
      /// @brief Aligns the text on the bottom of the bounding rectangle. Applied only when the text is a single line.v
      bottom = 0b1000,
      /// @brief Breaks the text at the end of a word.
      word_break = 0b10000,
      /// @brief Displays the text in a single line.
      single_line = 0b100000,
      /// @brief Expands tab characters. The default number of characters per tab is eight. The word_ellipsis, path_ellipsis, and end_ellipsis values cannot be used with expand_tabs.
      expand_tabs = 0b1000000,
      /// @brief Allows the overhanging parts of glyphs and unwrapped text reaching outside the formatting rectangle to show.
      no_clipping = 0b100000000,
      /// @brief Includes the font external leading in line height. Typically, external leading is not included in the height of a line of text.
      external_leading = 0b1000000000,
      /// @brief Turns off processing of prefix characters. Typically, the ampersand (&) mnemonic-prefix character is interpreted as a directive to underscore the character that follows, and the double-ampersand (&&) mnemonic-prefix characters as a directive to print a single ampersand. By specifying no_prefix, this processing is turned off. For example, an input string of "A&bc&&d" with no_prefix applied would result in output of "A&bc&&d". Compare with prefix_only.
      no_prefix = 0b10000000000,
      /// @brief Uses the system font to calculate text metrics.
      internal = 0b1000000000000,
      /// @brief Specifies the text should be formatted for display on a TextBox control.
      text_box_control = 0b10000000000000,
      /// @brief Removes the center of trimmed lines and replaces it with an ellipsis. When used to draw text by text_renderer, the string is not modified unless the modify_string flag is specified. Compare with end_ellipsis and word_ellipsis.
      path_ellipsis = 0b100000000000000,
      /// @brief Removes the end of trimmed lines, and replaces them with an ellipsis. When used to draw text by text_renderer, the string is not modified unless the modify_string flag is specified. Compare with path_ellipsis and word_ellipsis.
      end_ellipse = 0b1000000000000000,
      /// @brief Has no effect on the drawn text or text measurements. When used to draw text by TextRenderer, modifies the specified string parameter to match the displayed text if ellipsis are shown. This value has no effect unless end_ellipsis or path_ellipsis is specified.
      modify_string = 0b10000000000000000,
      /// @brief Displays the text from right to left.
      right_to_left = 0b100000000000000000,
      /// @brief Trims the line to the nearest word and an ellipsis is placed at the end of a trimmed line. Compare with end_ellipsis and path_ellipsis.
      word_ellipsis = 0b1000000000000000000,
      /// @brief A legacy value that has no effect. It prevents a line break at a double-wide character string, so that the line-breaking rule is equivalent to that for single-wide character strings.
      no_full_width_characterB_break = 0b10000000000000000000,
      /// @brief Ignores the ampersand (&) prefix character in the text, so that the letter that follows won't be underlined, but other mnemonic-prefix characters are still processed.
      hide_prefix = 0b100000000000000000000,
      /// @brief Draws only an underline at the position of the character following the ampersand (&) prefix character and doesn't draw any other characters in the string.
      prefix_only = 0b1000000000000000000000,
      /// @brief Preserves the clipping specified by a graphics object. Applies only to methods receiving an idevice_context that is a graphics.
      preserve_graphics_clipping = 0b1000000000000000000000000,
      /// @brief Preserves the transformation specified by a graphics. Applies only to methods receiving an ideviceContext that is a graphics.
      preserve_graphics_translate_transform = 0b10000000000000000000000000,
      /// @brief Does not add padding to the bounding rectangle.
      no_padding = 0b10000000000000000000000000000,
      /// @brief Adds padding to both sides of the bounding rectangle.
      left_and_right_padding = 0b100000000000000000000000000000,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, text_format_flags);

template<> struct xtd::enum_register<xtd::forms::text_format_flags> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::text_format_flags> {{xtd::forms::text_format_flags::default_format, "default_format"}, {xtd::forms::text_format_flags::glyph_overhang_padding, "glyph_overhang_padding"}, {xtd::forms::text_format_flags::left, "left"}, {xtd::forms::text_format_flags::top, "top"}, {xtd::forms::text_format_flags::horizontal_center, "horizontal_center"}, {xtd::forms::text_format_flags::right, "right"}, {xtd::forms::text_format_flags::vertical_center, "vertical_center"}, {xtd::forms::text_format_flags::bottom, "bottom"}, {xtd::forms::text_format_flags::word_break, "word_break"}, {xtd::forms::text_format_flags::single_line, "single_line"}, {xtd::forms::text_format_flags::expand_tabs, "expand_tabs"}, {xtd::forms::text_format_flags::no_clipping, "no_clipping"}, {xtd::forms::text_format_flags::external_leading, "external_leading"}, {xtd::forms::text_format_flags::no_prefix, "no_prefix"}, {xtd::forms::text_format_flags::internal, "internal"}, {xtd::forms::text_format_flags::text_box_control, "text_box_control"}, {xtd::forms::text_format_flags::path_ellipsis, "path_ellipsis"}, {xtd::forms::text_format_flags::end_ellipse, "end_ellipse"}, {xtd::forms::text_format_flags::modify_string, "modify_string"}, {xtd::forms::text_format_flags::right_to_left, "right_to_left"}, {xtd::forms::text_format_flags::word_ellipsis, "word_ellipsis"}, {xtd::forms::text_format_flags::no_full_width_characterB_break, "no_full_width_characterB_break"}, {xtd::forms::text_format_flags::hide_prefix, "hide_prefix"}, {xtd::forms::text_format_flags::prefix_only, "prefix_only"}, {xtd::forms::text_format_flags::preserve_graphics_clipping, "preserve_graphics_clipping"}, {xtd::forms::text_format_flags::preserve_graphics_translate_transform, "preserve_graphics_translate_transform"}, {xtd::forms::text_format_flags::no_padding, "no_padding"}, {xtd::forms::text_format_flags::left_and_right_padding, "left_and_right_padding"}};}
};
/// @endcond
