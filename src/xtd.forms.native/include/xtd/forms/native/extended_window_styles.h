/// @file
/// @brief Contains extended window styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

// https://docs.microsoft.com/en-us/cpp/mfc/reference/styles-used-by-mfc

#ifndef WS_EX_DLGMODALFRAME
/// @brief Designates a window with a double border that may (optionally) be created with a title bar when you specify the WS_CAPTION style flag in the dwStyle parameter.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_DLGMODALFRAME = 0x00000001;
/// @brief Specifies that a child window created with this style will not send the WM_PARENTNOTIFY message to its parent window when the child window is created or destroyed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_NOPARENTNOTIFY = 0x00000004;
/// @brief Specifies that a window created with this style should be placed above all nontopmost windows and stay above them even when the window is deactivated. An application can use the SetWindowPos member function to add or remove this attribute.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_TOPMOST = 0x00000008;
/// @brief Specifies that a window created with this style accepts drag-and-drop files.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_ACCEPTFILES = 0x00000010;
/// @brief Specifies that a window created with this style is to be transparent. That is, any windows that are beneath the window are not obscured by the window. A window created with this style receives WM_PAINT messages only after all sibling windows beneath it have been updated.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_TRANSPARENT = 0x00000020;
/// @brief Creates an MDI child window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_MDICHILD = 0x00000040;
/// @brief Creates a tool window, which is a window intended to be used as a floating toolbar. A tool window has a title bar that is shorter than a normal title bar, and the window title is drawn using a smaller font. A tool window does not appear in the task bar or in the window that appears when the user presses ALT+TAB.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_TOOLWINDOW = 0x00000080;
/// @brief Specifies that a window has a border with a raised edge.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_WINDOWEDGE = 0x00000100;
/// @brief Specifies that a window has a 3D look — that is, a border with a sunken edge.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_CLIENTEDGE = 0x00000200;
/// @brief Includes a question mark in the title bar of the window. When the user clicks the question mark, the cursor changes to a question mark with a pointer. If the user then clicks a child window, the child receives a WM_HELP message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_CONTEXTHELP = 0x00000400;
/// @brief Gives a window generic right-aligned properties. This depends on the window class.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_RIGHT = 0x00001000;
/// @brief Gives window generic left-aligned properties. This is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_LEFT = 0x00000000;
/// @brief Displays the window text using right-to-left reading order properties.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_RTLREADING = 0x00002000;
/// @brief Displays the window text using left-to-right reading order properties. This is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_LTRREADING = 0x00000000;
/// @brief Places a vertical scroll bar to the left of the client area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_LEFTSCROLLBAR = 0x00004000;
/// @brief Places a vertical scroll bar (if present) to the right of the client area. This is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_RIGHTSCROLLBAR = 0x00000000;

/// @brief Allows the user to navigate among the child windows of the window by using the TAB key.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_CONTROLPARENT = 0x00010000;
/// @brief Creates a window with a three-dimensional border style intended to be used for items that do not accept user input.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_STATICEDGE = 0x00020000;
/// @brief Forces a top-level window onto the taskbar when the window is visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_APPWINDOW = 0x00040000;


/// @brief Combines the WS_EX_CLIENTEDGE and WS_EX_WINDOWEDGE styles
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_OVERLAPPEDWINDOW = WS_EX_WINDOWEDGE|WS_EX_CLIENTEDGE;
/// @brief Combines the WS_EX_WINDOWEDGE and WS_EX_TOPMOST styles.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_PALETTEWINDOW = WS_EX_WINDOWEDGE|WS_EX_TOOLWINDOW|WS_EX_TOPMOST;

/// @brief The window is a layered window. This style cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC. However, Microsoft Windows 8 does support the WS_EX_LAYERED style for child windows, where previous Windows versions support it only for top-level windows.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_LAYERED = 0x00080000;

/// @brief Specifies that a child window created with this style will not send the WM_PARENTNOTIFY message to its parent window when the child window is created or destroyed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_NOINHERITLAYOUT = 0x00100000; // Disable inheritence of mirroring by children

/// @brief The window does not render to a redirection surface. This is for windows that do not have visible content or that use mechanisms other than surfaces to provide their visual.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_NOREDIRECTIONBITMAP = 0x00200000;

/// @brief If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the horizontal origin of the window is on the right edge. Increasing horizontal values advance to the left.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_LAYOUTRTL = 0x00400000; // Right to left mirroring

/// @brief Paints all descendants of a window in bottom-to-top painting order using double-buffering. Bottom-to-top painting order allows a descendent window to have translucency (alpha) and transparency (color-key) effects, but only if the descendent window also has the WS_EX_TRANSPARENT bit set. Double-buffering allows the window and its descendents to be painted without flicker. This cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_COMPOSITED = 0x02000000;
/// @brief A top-level window created with this style does not become the foreground window when the user clicks it. The system does not bring this window to the foreground when the user minimizes or closes the foreground window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t WS_EX_NOACTIVATE = 0x08000000;
#endif
/// @brief Activate automatic scroll based on virtual size.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t WS_EX_AUTOSCROLL = 0x40000000;
/// @brief Create a modal window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native ex_ws
/// @todo check if it's not redondant with WS_EX_DLGMODALFRAME fllags ?
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t WS_EX_MODALWINDOW = 0x80000000;
