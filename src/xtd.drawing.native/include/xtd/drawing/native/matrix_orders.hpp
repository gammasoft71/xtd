#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief The new operation is applied before the old operation.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native mo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32 MO_PREPEEND = 0;

/// @brief The new operation is applied after the old operation.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native mo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32 MO_APPEND = 1;
