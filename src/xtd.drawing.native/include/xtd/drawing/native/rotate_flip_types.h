#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies no clockwise rotation and no FLIPping.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_NONE_FLIP_NONE = 0;

/// @brief Specifies a 270-degree clockwise rotation followed bY a horizontal and vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_90_FLIP_NONE = 1;

/// @brief Specifies a 180-degree clockwise rotation without FLIPping.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_180_FLIP_NONE = 2;

/// @brief Specifies a 270-degree clockwise rotation without FLIPping.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_270_FLIP_NONE = 3;

/// @brief Specifies no clockwise rotation followed bY a horizontal FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_NONE_FLIP_X = 4;

/// @brief Specifies a 90-degree clockwise rotation followed bY a horizontal FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_90_FLIP_X = 5;

/// @brief Specifies a 180-degree clockwise rotation followed bY a horizontal FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_180_FLIP_X = 6;

/// @brief Specifies a 270-degree clockwise rotation followed bY a horizontal FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_270_FLIP_X = 7;

/// @brief Specifies no clockwise rotation followed bY a vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_NONE_FLIP_Y = RFT_ROTATE_180_FLIP_X;

/// @brief Specifies a 90-degree clockwise rotation followed bY a vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_90_FLIP_Y = RFT_ROTATE_270_FLIP_X;

/// @brief Specifies a 180-degree clockwise rotation followed bY a vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_180_FLIP_Y = RFT_ROTATE_NONE_FLIP_X;

/// @brief Specifies a 270-degree clockwise rotation followed bY a vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_270_FLIP_Y = RFT_ROTATE_90_FLIP_X;

/// @brief Specifies no clockwise rotation followed bY a horizontal and vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_NONE_FLIP_XY = RFT_ROTATE_180_FLIP_NONE;

/// @brief Specifies a 90-degree clockwise rotation followed bY a horizontal and vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_90_FLIP_XY = RFT_ROTATE_270_FLIP_NONE;

/// @brief Specifies a 180-degree clockwise rotation followed bY a horizontal and vertical FLIP.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_180_FLIP_XY = RFT_ROTATE_NONE_FLIP_NONE;

/// @brief Specifies a 90-degree clockwise rotation without FLIPping.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native rft
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 RFT_ROTATE_270_FLIP_XY = RFT_ROTATE_90_FLIP_NONE;
