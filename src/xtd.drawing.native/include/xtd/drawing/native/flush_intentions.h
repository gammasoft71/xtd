/// @file
/// @brief Contains xtd::drawing::drawing2d::flush_intentions constant.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies that the stack of all graphics operations is flushed immediately.
static const int32_t FI_FLUSH = 0;
/// @brief Specifies that all graphics operations on the stack are executed as soon as possible. This synchronizes the graphics state.
static const int32_t FI_SYNC = 1;
