/// @file
/// @brief Contains window styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

// https://docs.microsoft.com/en-us/cpp/mfc/reference/styles-used-by-mfc

#ifndef WS_OVERLAPPED
/// @brief Creates an overlapped window. An overlapped window usually has a caption and a border.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_OVERLAPPED = 0x00000000;
/// @brief Creates a window that has a Maximize button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_MAXIMIZEBOX = 0x00010000;
/// @brief Creates a window that has a Minimize button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_MINIMIZEBOX = 0x00020000;
/// @brief Creates a window with a thick frame that can be used to size the window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_THICKFRAME = 0x00040000;
/// @brief Creates a window that has a Control-menu box in its title bar. Used only for windows with title bars.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_SYSMENU = 0x00080000;
/// @brief Creates a window that has a horizontal scroll bar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_HSCROLL = 0x00100000;
/// @brief Creates a window that has a vertical scroll bar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_VSCROLL = 0x00200000;
/// @brief Creates a window with a double border but no title.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_DLGFRAME = 0x00400000;
/// @brief Creates a window that has a border.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_BORDER = 0x00800000;
/// @brief Creates a window that has a title bar (implies the WS_BORDER style). Cannot be used with the WS_DLGFRAME style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @warning Internal use only
/// @brief
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_CAPTION = 0x00C00000; // WS_BORDER|WS_DLGFRAME
/// @brief Creates a window of maximum size.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_MAXIMIZE = 0x01000000;
/// @brief Excludes the area occupied by child windows when you draw within the parent window. Used when you create the parent window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_CLIPCHILDREN = 0x02000000;
/// @brief Clips child windows relative to each other; that is, when a particular child window receives a paint message, the WS_CLIPSIBLINGS style clips all other overlapped child windows out of the region of the child window to be updated. (If WS_CLIPSIBLINGS is not given and child windows overlap, when you draw within the client area of a child window, it is possible to draw within the client area of a neighboring child window.) For use with the WS_CHILD style only.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_CLIPSIBLINGS = 0x04000000;
/// @brief Creates a window that is initially disabled.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_DISABLED = 0x08000000;
/// @brief Creates a window that is initially visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_VISIBLE = 0x10000000;
/// @brief Creates a window that is initially minimized. For use with the WS_OVERLAPPED style only.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_MINIMIZE = 0x20000000;
/// @brief Creates a child window. Cannot be used with the WS_POPUP style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_CHILD = 0x40000000;
/// @brief Creates a pop-up window. Cannot be used with the WS_CHILD style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_POPUP = 0x80000000;

/// @brief Specifies the first control of a group of controls in which the user can move from one control to the next with the arrow keys. All controls defined with the WS_GROUP style FALSE after the first control belong to the same group. The next control with the WS_GROUP style starts the next group (that is, one group ends where the next begins).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_GROUP = 0x00020000;
/// @brief Specifies one of any number of controls through which the user can move by using the TAB key. The TAB key moves the user to the next control specified by the WS_TABSTOP style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_TABSTOP = 0x00010000;

// Common Window Styles

/// @brief Creates an overlapped window with the WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, and WS_MAXIMIZEBOX styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_OVERLAPPEDWINDOW = WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX;
/// @brief Creates a pop-up window with the WS_BORDER, WS_POPUP, and WS_SYSMENU styles. The WS_CAPTION style must be combined with the WS_POPUPWINDOW style to make the Control menu visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_POPUPWINDOW = WS_POPUP|WS_BORDER|WS_SYSMENU;
/// @brief Same as the WS_CHILD style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_CHILDWINDOW = WS_CHILD;

// Window Styles (next...)

/// @brief Creates an overlapped window. An overlapped window has a title bar and a border. Same as the WS_OVERLAPPED style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_TILED = WS_OVERLAPPED;
/// @brief Creates a window that is initially minimized. Same as the WS_MINIMIZE style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_ICONIC = WS_MINIMIZE;
/// @brief Creates a window that has a sizing border. Same as the WS_THICKFRAME style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_SIZEBOX = WS_THICKFRAME;
/// @brief Creates an overlapped window with the WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, and WS_MAXIMIZEBOX styles. Same as the WS_OVERLAPPEDWINDOW style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_TILEDWINDOW = WS_OVERLAPPEDWINDOW;
#endif
