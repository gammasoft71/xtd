/// @file
/// @brief Contains xtd::drawing::string_format_flags enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the display and layout information for text strings. This enumeration  allows a bitwise combination of its member values.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    enum class string_format_flags {
      /// @brief Text is displayed from right to left. text.
      direction_right_to_left = 0b1,
      /// @brief Text is vertically aligned.
      direction_vertical = 0b10,
      /// @brief Parts of characters are allowed to overhang the string's layout rectangle. By default, characters are repositioned to avoid any overhang.
      fit_black_box = 0b100,
      /// @brief Control characters such as the left-to-right mark are shown in the output with a representative glyph.
      display_format_control = 0b100000,
      /// @brief Fallback to alternate fonts for characters not supported in the requested font is disabled. Any missing characters are displayed with the fonts missing glyph, usually an open square.
      no_font_fallback = 0b10000000000,
      /// @brief Includes the trailing space at the end of each line. By default the boundary rectangle returned by the MeasureString method excludes the space at the end of each line. Set this flag to include that space in measurement.
      measure_trailing_spaces = 0b100000000000,
      /// @brief Text wrapping between lines when formatting within a rectangle is disabled. This flag is implied when a point is passed instead of a rectangle, or when the specified rectangle has a zero line length.
      no_wrap = 0b1000000000000,
      /// @brief Only entire lines are laid out in the formatting rectangle. By default layout continues until the end of the text, or until no more lines are visible as a result of clipping, whichever comes first. Note that the default settings allow the last line to be partially obscured by a formatting rectangle that is not a whole multiple of the line height. To ensure that only whole lines are seen, specify this value and be careful to provide a formatting rectangle at least as tall as the height of one line.
      line_limit = 0b10000000000000,
      /// @brief Overhanging parts of glyphs, and unwrapped text reaching outside the formatting rectangle are allowed to show. By default all text and glyph parts reaching outside the formatting rectangle are clipped.
      no_clip = 0b100000000000000,
    };
  }
}

/// @cond
flags_attribute_(xtd::drawing, string_format_flags);

template<> struct xtd::enum_register<xtd::drawing::string_format_flags> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::string_format_flags> {{xtd::drawing::string_format_flags::direction_right_to_left, "direction_right_to_left"}, {xtd::drawing::string_format_flags::direction_vertical, "direction_vertical"}, {xtd::drawing::string_format_flags::fit_black_box, "fit_black_box"}, {xtd::drawing::string_format_flags::display_format_control, "display_format_control"}, {xtd::drawing::string_format_flags::no_font_fallback, "no_font_fallback"}, {xtd::drawing::string_format_flags::measure_trailing_spaces, "measure_trailing_spaces"}, {xtd::drawing::string_format_flags::no_wrap, "no_wrap"}, {xtd::drawing::string_format_flags::line_limit, "line_limit"}, {xtd::drawing::string_format_flags::no_clip, "no_clip"}};}
};
/// @endcond
