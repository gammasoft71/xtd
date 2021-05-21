/// @file
/// @brief Contains arranged direction constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef ARW_BOTTOMLEFT
/// @brief Start at the lower-left corner of the work area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_BOTTOMLEFT = 0x0000L;
/// @brief Start at the lower-right corner of the work area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_BOTTOMRIGHT = 0x0001L;
/// @brief Start at the upper-left corner of the work area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_TOPLEFT = 0x0002L;
/// @brief Start at the upper-right corner of the work area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_TOPRIGHT = 0x0003L;

/// @brief Equivalent to ARW_TOPRIGHT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_STARTMASK = 0x0003L;
/// @brief Equivalent to ARW_BOTTOMRIGHT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_STARTRIGHT = 0x0001L;
/// @brief Equivalent to ARW_TOPLEFT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_STARTTOP = 0x0002L;

/// @brief Arrange left (valid with ARW_BOTTOMRIGHT and ARW_TOPRIGHT only).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_LEFT = 0x0000;
/// @brief Arrange right (valid with ARW_BOTTOMLEFT and ARW_TOPLEFT only).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_RIGHT = 0x0000L;
/// @brief Arrange up (valid with ARW_BOTTOMLEFT and ARW_BOTTOMRIGHT only).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_UP = 0x0004L;
/// @brief Arrange down (valid with ARW_TOPLEFT and ARW_TOPRIGHT only).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_DOWN = 0x0004L;
/// @brief Hide minimized windows by moving them off the visible area of the screen.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native arw
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ARW_HIDE = 0x0008L;
#endif

