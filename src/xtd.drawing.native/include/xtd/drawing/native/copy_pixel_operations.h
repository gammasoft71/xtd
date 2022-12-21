#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types.h>

/// @brief The destination area is filled by using the color associated with index 0 in the physical palette. (This color is black for the default physical palette.)
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_BLACKNESS = 66;

/// @brief Windows that are layered on top of your window are included in the resulting image. By default, the image contains only your window. Note that this generally cannot be used for printing device contexts.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_CAPTURE_BLT = 1073741824;

/// @brief The destination area is inverted.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_DESTINATION_INVERT = 5570569;

/// @brief The colors of the source area are merged with the colors of the selected brush of the destination device context using the Boolean AND operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_MERGE_COPY = 12583114;

/// @brief The colors of the inverted source area are merged with the colors of the destination area by using the Boolean OR operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_MERGE_PAINT = 12255782;

/// @brief The bitmap is not mirrored.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_NO_MIRROR_BITMAP = -2147483648;

/// @brief The inverted source area is copied to the destination.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_NOT_SOURCE_COPY = 3342344;

/// @brief The source and destination colors are combined using the Boolean OR operator, and then resultant color is then inverted.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_NOT_SOURCE_ERASE = 1114278;

/// @brief The brush currently selected in the destination device context is copied to the destination bitmap.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_PAT_COPY = 15728673;

/// @brief The colors of the brush currently selected in the destination device context are combined with the colors of the destination are using the Boolean XOR operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_PAT_INVERT = 5898313;

/// @brief The colors of the brush currently selected in the destination device context are combined with the colors of the inverted source area using the Boolean OR operator. The result of this operation is combined with the colors of the destination area using the Boolean OR operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_PAT_PAINT = 16452105;

/// @brief The colors of the source and destination areas are combined using the Boolean AND operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_SOURCE_AND = 8913094;

/// @brief The source area is copied directly to the destination area.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_SOURCE_COPY = 13369376;

/// @brief The inverted colors of the destination area are combined with the colors of the source area using the Boolean AND operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_SOURCE_ERASE = 4457256;

/// @brief The colors of the source and destination areas are combined using the Boolean XOR operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_SOURCE_INVERT = 6684742;

/// @brief The colors of the source and destination areas are combined using the Boolean OR operator.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_SOURCE_PAINT = 15597702;

/// @brief The destination area is filled by using the color associated with index 1 in the physical palette. (This color is white for the default physical palette.)
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native cpo
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::int32 CPO_WHITENESS = 16711778;
