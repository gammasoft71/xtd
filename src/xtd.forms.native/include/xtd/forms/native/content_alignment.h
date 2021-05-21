/// @file
/// @brief Contains content alignment constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

/// @brief Content is vertically aligned at the top, and horizontally aligned on the left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_TOPLEFT = 0b1;
/// @brief Content is vertically aligned at the top, and horizontally aligned at the center.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_TOPCENTER = 0b10;
/// @brief Content is vertically aligned at the top, and horizontally aligned on the right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_TOPRIGHT = 0b100;

/// @brief Content is vertically aligned in the middle, and horizontally aligned on the left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_MIDDLELEFT = 0b10000;
/// @brief Content is vertically aligned at the middle, and horizontally aligned at the center.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_MIDDLECENTER = 0b100000;
/// @brief Content is vertically aligned at the middle, and horizontally aligned on the right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_MIDDLERIGHT = 0b1000000;

/// @brief Content is vertically aligned in the bottom, and horizontally aligned on the left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_BOTTOMLEFT = 0b100000000;
/// @brief Content is vertically aligned at the bottom, and horizontally aligned at the center.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_BOTTOMCENTER = 0b1000000000;
/// @brief Content is vertically aligned at the bottom, and horizontally aligned on the right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ca
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t CA_BOTTOMRIGHT = 0b10000000000;
