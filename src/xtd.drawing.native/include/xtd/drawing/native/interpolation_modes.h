#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief Equivalent to the xtd::drawing::drawing_2d::quality_mode::invalid element of the xtd::drawing::drawing_2d::quality_mode enumeration.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_INVALID = -1;

/// @brief Specifies default mode.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_DEFAULT = 0;

/// @brief Specifies low quality interpolation.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_LOW = 1;

/// @brief Specifies high quality interpolation.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_HIGHT = 2;

/// @brief Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_BILINEAR = 3;

/// @brief Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_BICUBIC = 4;

/// @brief Specifies nearest-neighbor interpolation.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_NEAREST_NEIGHBOOR = 5;

/// @brief Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_HIGH_QUALITY_BILINEAR = 6;

/// @brief Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native im
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 IM_HIGH_QUALITY_BICUBIC = 7;
