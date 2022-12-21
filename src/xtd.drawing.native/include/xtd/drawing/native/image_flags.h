#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief There is no format information.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_NONE = 0;

/// @brief The pixel data is scalable.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_SCALABLE = 0b1;

/// @brief The pixel data contains alpha information.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_HAS_ALPHA = 0b10;

/// @brief Specifies that the pixel data has alpha values other than 0 (transparent) and 255 (opaque).
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_HAS_TRANSLUCENT = 0b100;

/// @brief The pixel data is partially scalable, but there are some limitations.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_PARTIALLY_SCALABLE = 0b1000;

/// @brief The pixel data uses an RGB color space.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_COLOR_SPACE_RGB = 0b10000;

/// @brief The pixel data uses a CMYK color space.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_COLOR_SPACE_CMYK = 0b100000;

/// @brief The pixel data is grayscale.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_COLOR_SPACE_GRAY = 0b1000000;

/// @brief Specifies that the image is stored using a YCBCR color space.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_COLOR_SPACE_YCBCR = 0b10000000;

/// @brief Specifies that the image is stored using a YCCK color space.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_COLOR_SPACE_YCCK = 0b100000000;

/// @brief Specifies that dots per inch information is stored in the image.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_HAS_REAL_DPI = 0b1000000000000;

/// @brief Specifies that the pixel size is stored in the image.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_HAS_REAL_PIXEL_SIZE = 0b10000000000000;

/// @brief The pixel data is read-only.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_READ_ONLY = 0b10000000000000000;

/// @brief The pixel data can be cached for faster access.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t IFL_CACHING = 0b100000000000000000;
