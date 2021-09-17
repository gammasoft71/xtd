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

#ifndef SBS_HORZ
// Scroll Bar Control Styles

/// @brief Designates a horizontal scroll bar. If neither the SBS_BOTTOMALIGN nor SBS_TOPALIGN style is specified, the scroll bar has the height, width, and position specified by the x, y, nWidth, and nHeight parameters of CreateWindowEx.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_HORZ = 0x0000;
/// @brief Designates a vertical scroll bar. If you specify neither the SBS_RIGHTALIGN nor the SBS_LEFTALIGN style, the scroll bar has the height, width, and position specified by the x, y, nWidth, and nHeight parameters of CreateWindowEx.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_VERT = 0x0001;
/// @brief Aligns the top edge of the scroll bar with the top edge of the rectangle defined by the x, y, nWidth, and nHeight parameters of CreateWindowEx. The scroll bar has the default height for system scroll bars. Use this style with the SBS_HORZ style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_TOPALIGN = 0x0002;
/// @brief Aligns the left edge of the scroll bar with the left edge of the rectangle defined by the x, y, nWidth, and nHeight parameters of CreateWindowEx. The scroll bar has the default width for system scroll bars. Use this style with the SBS_VERT style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_LEFTALIGN = 0x0002;
/// @brief Aligns the bottom edge of the scroll bar with the bottom edge of the rectangle defined by the x, y, nWidth, and nHeight parameters of CreateWindowEx function. The scroll bar has the default height for system scroll bars. Use this style with the SBS_HORZ style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_BOTTOMALIGN = 0x0004;
/// @brief Aligns the right edge of the scroll bar with the right edge of the rectangle defined by the x, y, nWidth, and nHeight parameters of CreateWindowEx. The scroll bar has the default width for system scroll bars. Use this style with the SBS_VERT style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_RIGHTALIGN = 0x0004;
/// @brief SAligns the upper left corner of the size box with the upper left corner of the rectangle specified by the x, y, nWidth, and nHeight parameters of CreateWindowEx. The size box has the default size for system size boxes. Use this style with the SBS_SIZEBOX or SBS_SIZEGRIP styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_SIZEBOXTOPLEFTALIGN = 0x0002L;
/// @brief Aligns the lower right corner of the size box with the lower right corner of the rectangle specified by the x, y, nWidth, and nHeight parameters of CreateWindowEx. The size box has the default size for system size boxes. Use this style with the SBS_SIZEBOX or SBS_SIZEGRIP styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_SIZEBOXBOTTOMRIGHTALIGN = 0x0004;
/// @brief Designates a size box. If you specify neither the SBS_SIZEBOXBOTTOMRIGHTALIGN nor the SBS_SIZEBOXTOPLEFTALIGN style, the size box has the height, width, and position specified by the x, y, nWidth, and nHeight parameters of CreateWindowEx.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_SIZEBOX = 0x0008;
/// @brief Same as SBS_SIZEBOX, but with a raised edge.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native sb
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t SBS_SIZEGRIP = 0x0010;

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
