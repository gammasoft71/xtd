#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies an invalid mode.
constexpr int32_t PO_INVALID = -1;
/// @brief Specifies default mode.
constexpr int32_t PO_DEFAULT = 0;
/// @brief Specifies high speed, low quality rendering.
constexpr int32_t PO_HIGH_SPEED = 1;
/// @brief Specifies high quality, low speed rendering.
constexpr int32_t PO_HIGHT_QUALITY = 2;
/// @brief Specifies no pixel offset.
constexpr int32_t PO_NONE = 3;
/// @brief Specifies that pixels are offset by -.5 units, both horizontally and vertically, for high speed antialiasing.
constexpr int32_t PO_HALF = 4;
