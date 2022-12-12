#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Invalid quality.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_INVALID = -1;

/// @brief Default quality.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_DEFAULT_VALUE = 0;

/// @brief High speed, low quality.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_HIGH_SPEED = 1;

/// @brief High quality, low speed compositing.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_HIGH_QUALITY = 2;

/// @brief Gamma correction is used.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_GAMMA_CORRECTED = 3;

/// @brief Assume linear values.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cq
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CQ_ASSUME_LINEAR = 4;
