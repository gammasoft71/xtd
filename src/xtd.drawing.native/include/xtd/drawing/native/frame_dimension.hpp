#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief The define the frame dimension page.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native fdi
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t FD_PAGE = 0b1;

/// @brief The define the frame dimension resolution.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native fdi
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t FD_RESOLUTION = 0b10;

/// @brief The define the frame dimension time.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native fdi
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t FD_TIME = 0b100;
