#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/usize>

/// @brief Indicates the unknoxn image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_UNKNOWN = 0;

/// @brief Indicates the bitmap image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_BMP = 1;

/// @brief Indicates the enhanced metafile image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_EMF = 2;

/// @brief Indicates the Exif format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_EXIF = 3;

/// @brief Indicates the GIF image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_GIF = 4;

/// @brief Indicates the icon image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_ICO = 5;

/// @brief Indicates the JOEG image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_JPEG = 6;

/// @brief Indicates the bitmap memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_BMP = 7;

/// @brief Indicates the PNG image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_PNG = 8;

/// @brief Indicates the TIFF image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_TIFF = 9;

/// @brief Indicates the WMF image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_WMF = 10;

/// @brief Indicates the GIF mempry image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_GIF = 11;

/// @brief Indicates the icon memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_ICO = 12;

/// @brief Indicates the JPEG memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_JPEG = 13;

/// @brief Indicates the PNG memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_PNG = 14;

/// @brief Indicates the TIFF memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_TIFF = 15;

/// @brief Indicates the cursor image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_CUR = 16;

/// @brief Indicates the CUR memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_CUR = 17;

/// @brief Indicates the XBM image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_XBM = 18;

/// @brief Indicates the XBM memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_XBM = 19;

/// @brief Indicates the XPM image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_XPM = 20;

/// @brief Indicates the XPM memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_XPM = 21;

/// @brief Indicates the PNM image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_PNM = 22;

/// @brief Indicates the PNM memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_PNM = 23;

/// @brief Indicates the PCX image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_PCX = 24;

/// @brief Indicates the PCX memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_PCX = 25;

/// @brief Indicates the PICT image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_PICT = 26;

/// @brief Indicates the PICT memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_PICT = 27;

/// @brief Indicates the ICON image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_ICON = 28;

/// @brief Indicates the ICOM memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_ICON = 29;

/// @brief Indicates the Apple CURSOR format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MACCUR = 30;

/// @brief Indicates the CURSOR memory image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_MEMORY_MACCUR = 31;

/// @brief Indicates the ANI image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_ANI = 32;

/// @brief Indicates the IIF image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_IIF = 33;

/// @brief Indicates the TGA image format.
/// @par Library
/// xtd.drawing.native
/// @ingroup xtd_drawing_native ifm
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr xtd::usize IFM_TGA = 34;
