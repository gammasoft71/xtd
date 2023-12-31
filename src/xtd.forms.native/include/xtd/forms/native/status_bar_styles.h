/// @file
/// @brief Contains status bar styles constants.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#if !defined(TBSTYLE_TOOLTIPS)
/// @brief The status bar control will include a sizing grip at the right end of the status bar. A sizing grip is similar to a sizing border; it is a rectangular area that the user can click and drag to resize the parent window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBARS_SIZEGRIP = 0x0100;
/// @brief Use this style to enable tooltips.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBARS_TOOLTIPS = 0x0800;
#endif

/// @brief Replace the end of the status texts with an ellipsis when the status text widths exceed status bar or status panel width.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SBARS_ELLIPSIZE = 0x1000;
/// @brief Specifies that the status bar is left position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SBARS_LEFT = 0x2000;
/// @brief Specifies that the status bar is bottom position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SBARS_BOTTOM = 0x4000;
/// @brief Specifies that the status bar is right position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t SBARS_RIGHT = 0x8000;
