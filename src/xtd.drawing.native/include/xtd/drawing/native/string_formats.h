#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Text is displayed from right to left. text.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_RIGHT_TO_LEFT = 0b1;

/// @brief Text is vertically aligned.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_VERTICAL = 0b10;

/// @brief Parts of characters are allowed to overhang the string's layout rectangle. By default, characters are repositioned to avoid any overhang.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_FIT_BLACK_BOX = 0b100;

/// @brief Control characters such as the left-to-right mark are shown in the output with a representative glyph.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_DISPLAY_FORMAT_CONTROL = 0b100000;

/// @brief Fallback to alternate fonts for characters not supported in the requested font is disabled. Any missing characters are displayed with the fonts missing glyph, usually an open square.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_NO_FONT_FAILBACK = 0b10000000000;

/// @brief Includes the trailing space at the end of each line. By default the boundary rectangle returned by the MeasureString method excludes the space at the end of each line. Set this flag to include that space in measurement.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_MEASURE_TRAILING_SPACES = 0b100000000000;

/// @brief Text wrapping between lines when formatting within a rectangle is disabled. This flag is implied when a point is passed instead of a rectangle, or when the specified rectangle has a zero line length.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_NO_WRAP = 0b1000000000000;

/// @brief Only entire lines are laid out in the formatting rectangle. By default layout continues until the end of the text, or until no more lines are visible as a result of clipping, whichever comes first. Note that the default settings allow the last line to be partially obscured by a formatting rectangle that is not a whole multiple of the line height. To ensure that only whole lines are seen, specify this value and be careful to provide a formatting rectangle at least as tall as the height of one line.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_LINE_LIMIT = 0b10000000000000;

/// @brief Overhanging parts of glyphs, and unwrapped text reaching outside the formatting rectangle are allowed to show. By default all text and glyph parts reaching outside the formatting rectangle are clipped.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sf
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SF_NO_CLIP = 0b100000000000000;
