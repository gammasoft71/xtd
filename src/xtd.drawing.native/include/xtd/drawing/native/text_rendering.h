#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Each character is drawn using its glyph bitmap, with the system default rendering hint. The text will be drawn using whatever font-smoothing settings the user has selected for the system.
constexpr int32_t TR_SYSTEM_DEFAULT = 0;
/// @brief Each character is drawn using its glyph bitmap. Hinting is used to improve character appearance on stems and curvature.
constexpr int32_t TR_SINGLE_BIT_PER_PIXEL_GRID_FIT = 1;
/// @brief Each character is drawn using its glyph bitmap. Hinting is not used.
constexpr int32_t TR_SINGLE_BIT_PAER_PIXEL = 2;
/// @brief Each character is drawn using its antialiased glyph bitmap with hinting. Much better quality due to antialiasing, but at a higher performance cost.
constexpr int32_t TR_ANTI_ALIAS_GRID_FIT = 3;
/// @brief Each character is drawn using its antialiased glyph bitmap without hinting. Better quality due to antialiasing. Stem width differences may be noticeable because hinting is turned off.
constexpr int32_t TR_ANTI_ALIAS = 4;
/// @brief Each character is drawn using its glyph ClearType bitmap with hinting. The highest quality setting. Used to take advantage of ClearType font features.
constexpr int32_t TR_CLEAR_TYPE_GRID_FIT = 5;
