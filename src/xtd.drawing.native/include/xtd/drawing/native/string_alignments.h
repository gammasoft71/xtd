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

/// @brief Specifies the text be aligned near the layout. In a left-to-right layout, the near position is left. In a right-to-left layout, the near position is right.
static const int32_t SA_NEAR = 0;
/// @brief Specifies that text is aligned in the center of the layout rectangle.
static const int32_t SA_CENTER = 1;
/// @brief Specifies that text is aligned far from the origin position of the layout rectangle. In a left-to-right layout, the far position is right. In a right-to-left layout, the far position is left.
static const int32_t SA_FAR = 2;
