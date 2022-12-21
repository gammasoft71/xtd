#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Each character is drawn using its glyph bitmap, with the system default rendering hint. The text will be drawn using whatever font-smoothing settings the user has selected for the system.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_SYSTEM_DEFAULT = 0;

/// @brief Each character is drawn using its glyph bitmap. Hinting is used to improve character appearance on stems and curvature.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_SINGLE_BIT_PER_PIXEL_GRID_FIT = 1;

/// @brief Each character is drawn using its glyph bitmap. Hinting is not used.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_SINGLE_BIT_PAER_PIXEL = 2;

/// @brief Each character is drawn using its antialiased glyph bitmap with hinting. Much better quality due to antialiasing, but at a higher performance cost.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_ANTI_ALIAS_GRID_FIT = 3;

/// @brief Each character is drawn using its antialiased glyph bitmap without hinting. Better quality due to antialiasing. Stem width differences may be noticeable because hinting is turned off.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_ANTI_ALIAS = 4;

/// @brief Each character is drawn using its glyph ClearType bitmap with hinting. The highest quality setting. Used to take advantage of ClearType font features.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native tr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 TR_CLEAR_TYPE_GRID_FIT = 5;
