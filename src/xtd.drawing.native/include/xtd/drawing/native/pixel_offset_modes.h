#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies an invalid mode.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_INVALID = -1;

/// @brief Specifies default mode.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_DEFAULT = 0;

/// @brief Specifies high speed, low quality rendering.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_HIGH_SPEED = 1;

/// @brief Specifies high quality, low speed rendering.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_HIGHT_QUALITY = 2;

/// @brief Specifies no pixel offset.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_NONE = 3;

/// @brief Specifies that pixels are offset by -.5 units, both horizontally and vertically, for high speed antialiasing.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native po
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 PO_HALF = 4;
