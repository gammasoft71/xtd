#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies that when a color is rendered, it is blended with the background color. The blend is determined by the alpha component of the color being rendered.
constexpr int32_t CM_SOURCE_OVER = 0;
/// @brief Specifies that when a color is rendered, it overwrites the background color.
constexpr int32_t CM_SOURCE_COPY = 1;
