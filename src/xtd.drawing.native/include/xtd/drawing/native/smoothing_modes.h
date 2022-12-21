#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Specifies an invalid mode.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_INVALID = -1;

/// @brief Specifies no antialiasing.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_DEFAULT = 0;

/// @brief Specifies no antialiasing.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_HIGH_SPEED = 1;

/// @brief Specifies antialiased rendering.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_HIGHT_QUALITY = 2;

/// @brief Specifies no antialiasing.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_NONE = 3;

/// @brief Specifies antialiased rendering.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native sm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 SM_ANTI_ALIAS = 4;
