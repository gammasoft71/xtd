#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies a mitered join. This produces a sharp corner or a clipped corner, depending on whether the length of the miter exceeds the miter limit.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native lj
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 LJ_MITER = 0;

/// @brief Specifies a beveled join. This produces a diagonal corner.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native lj
/// @remarks Added specifically for xtd.
/// @warning Internal use only

constexpr xtd::int32 LJ_BEVEL = 1;
/// @brief Specifies a circular join. This produces a smooth, circular arc between the lines.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native lj
/// @remarks Added specifically for xtd.
/// @warning Internal use only

constexpr xtd::int32 LJ_ROUND = 2;
/// @brief Specifies a mitered join. This produces a sharp corner or a beveled corner, depending on whether the length of the miter exceeds the miter limit.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native lj
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 LJ_MITER_CLIPPED = 3;
