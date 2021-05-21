/// @file
/// @brief Contains progress bar styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef SB_HORZ
// Scroll Bar Control Constants

/// @brief Shows or hides a window's standard horizontal scroll bars.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_HORZ = 0;
/// @brief Shows or hides a window's standard vertical scroll bar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_VERT = 1;
/// @brief Shows or hides a scroll bar control. The hwnd parameter must be the handle to the scroll bar control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_CTL = 2;
/// @brief Shows or hides a window's standard horizontal and vertical scroll bars.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_BOTH = 3;

// Scroll Bar Commands

/// @brief Scrolls one line up.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_LINEUP = 0;
/// @brief Scrolls one line left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_LINELEFT = 0;
/// @brief Scrolls one line down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_LINEDOWN = 1;
/// @brief Scrolls one line right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_LINERIGHT = 1;
/// @brief Scrolls one page up.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_PAGEUP = 2;
/// @brief Scrolls one page left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_PAGELEFT = 2;
/// @brief Scrolls one page down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_PAGEDOWN = 3;
/// @brief Scrolls one page right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_PAGERIGHT = 3;
/// @brief The user has dragged the scroll box (thumb) and released the mouse button. The HIWORD indicates the position of the scroll box at the end of the drag operation.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_THUMBPOSITION = 4;
/// @brief The user is dragging the scroll box. This message is sent repeatedly until the user releases the mouse button. The HIWORD indicates the position that the scroll box has been dragged to.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_THUMBTRACK = 5;
/// @brief Scrolls to the upper left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_TOP = 6;
/// @brief Scrolls to the upper left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_LEFT = 6;
/// @brief Scrolls to the lower right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_BOTTOM = 7;
/// @brief Scrolls to the lower right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_RIGHT = 7;
/// @brief Ends scroll.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SB_ENDSCROLL = 8;
#endif
