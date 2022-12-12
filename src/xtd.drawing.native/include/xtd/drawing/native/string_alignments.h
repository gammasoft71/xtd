#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies the text be aligned near the layout. In a left-to-right layout, the near position is left. In a right-to-left layout, the near position is right.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sa
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SA_NEAR = 0;

/// @brief Specifies that text is aligned in the center of the layout rectangle.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sa
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SA_CENTER = 1;

/// @brief Specifies that text is aligned far from the origin position of the layout rectangle. In a left-to-right layout, the far position is right. In a right-to-left layout, the far position is left.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sa
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SA_FAR = 2;
