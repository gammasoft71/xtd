#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies an invalid mode.
constexpr int32_t SM_INVALID = -1;
/// @brief Specifies no antialiasing.
constexpr int32_t SM_DEFAULT = 0;
/// @brief Specifies no antialiasing.
constexpr int32_t SM_HIGH_SPEED = 1;
/// @brief Specifies antialiased rendering.
constexpr int32_t SM_HIGHT_QUALITY = 2;
/// @brief Specifies no antialiasing.
constexpr int32_t SM_NONE = 3;
/// @brief Specifies antialiased rendering.
constexpr int32_t SM_ANTI_ALIAS = 4;
