#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Equivalent to the xtd::drawing::drawing2d::quality_mode::invalid element of the xtd::drawing::drawing2d::quality_mode enumeration.
constexpr int32_t IM_INVALID = -1;
/// @brief Specifies default mode.
constexpr int32_t IM_DEFAULT = 0;
/// @brief Specifies low quality interpolation.
constexpr int32_t IM_LOW = 1;
/// @brief Specifies high quality interpolation.
constexpr int32_t IM_HIGHT = 2;
/// @brief Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.
constexpr int32_t IM_BILINEAR = 3;
/// @brief Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.
constexpr int32_t IM_BICUBIC = 4;
/// @brief Specifies nearest-neighbor interpolation.
constexpr int32_t IM_NEAREST_NEIGHBOOR = 5;
/// @brief Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.
constexpr int32_t IM_HIGH_QUALLITY_BILINEAR = 6;
/// @brief Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images.
constexpr int32_t IL_HIGN_QUALITY_BICUBIC = 7;
