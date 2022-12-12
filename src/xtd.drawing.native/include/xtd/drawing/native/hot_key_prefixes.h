#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief No hot-key prefix.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native hkp
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 HKP_NONE = 0;

/// @brief Display the hot-key prefix.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native hkp
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 HKP_SHOW = 1;

/// @brief Do not display the hot-key prefix.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native hkp
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 HKP_HIDE = 2;
