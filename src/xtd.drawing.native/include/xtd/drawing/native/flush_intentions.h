#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies that the stack of all graphics operations is flushed immediately.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native fi
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t FI_FLUSH = 0;

/// @brief Specifies that all graphics operations on the stack are executed as soon as possible. This synchronizes the graphics state.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native fi
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t FI_SYNC = 1;
