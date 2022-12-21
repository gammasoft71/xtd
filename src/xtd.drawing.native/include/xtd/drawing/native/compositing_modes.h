#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies that when a color is rendered, it is blended with the background color. The blend is determined by the alpha component of the color being rendered.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CM_SOURCE_OVER = 0;

/// @brief Specifies that when a color is rendered, it overwrites the background color.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CM_SOURCE_COPY = 1;
