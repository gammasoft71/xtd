#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

constexpr size_t IFL_NONE = 0;
constexpr size_t IFL_SCALABLE = 0b1;
constexpr size_t IFL_HAS_ALPHA = 0b10;
constexpr size_t IFL_HAS_TRANSLUCENT = 0b100;
constexpr size_t IFL_PARTIALLY_SCALABLE = 0b1000;
constexpr size_t IFL_COLOR_SPACE_RGB = 0b10000;
constexpr size_t IFL_COLOR_SPACE_CMYK = 0b100000;
constexpr size_t IFL_COLOR_SPACE_GRAY = 0b1000000;
constexpr size_t IFL_COLOR_SPACE_YCBCR = 0b10000000;
constexpr size_t IFL_COLOR_SPACE_YCCK = 0b100000000;
constexpr size_t IFL_HAS_REAL_DPI = 0b1000000000000;
constexpr size_t IFL_HAS_REAL_PIXEL_SIZE = 0b10000000000000;
constexpr size_t IFL_READ_ONLY = 0b10000000000000000;
constexpr size_t IFL_CACHING = 0b100000000000000000;
