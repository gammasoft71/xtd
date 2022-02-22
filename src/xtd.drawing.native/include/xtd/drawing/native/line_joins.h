/// @file
/// @brief Contains xtd::drawing::drawing2d::line_joins constant.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies a mitered join. This produces a sharp corner or a clipped corner, depending on whether the length of the miter exceeds the miter limit.
static const int32_t LJ_MITER = 0;
/// @brief Specifies a beveled join. This produces a diagonal corner.
static const int32_t LJ_BEVEL = 1;
/// @brief Specifies a circular join. This produces a smooth, circular arc between the lines.
static const int32_t LJ_ROUND = 2;
/// @brief Specifies a mitered join. This produces a sharp corner or a beveled corner, depending on whether the length of the miter exceeds the miter limit.
static const int32_t LJ_MITER_CLIPPED = 3;
