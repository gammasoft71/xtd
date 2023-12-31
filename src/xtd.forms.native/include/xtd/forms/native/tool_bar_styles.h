/// @file
/// @brief Contains tool bar styles constants.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#if !defined(TBSTYLE_TOOLTIPS)
/// @brief Creates a tooltip control that an application can use to display descriptive text for the buttons in the toolbar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_TOOLTIPS = 0x00000100;
/// @brief Creates a toolbar that can have multiple lines of buttons. Toolbar buttons can "wrap" to the next line when the toolbar becomes too narrow to include all buttons on the same line. When the toolbar is wrapped, the break will occur on either the rightmost separator or the rightmost button if there are no separators on the bar. This style must be set to display a vertical toolbar control when the toolbar is part of a vertical rebar control. This style cannot be combined with CCS_VERT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_WRAPABLE = 0x00000200;
/// @brief Allows users to change a toolbar button's position by dragging it while holding down the ALT key. If this style is not specified, the user must hold down the SHIFT key while dragging a button. Note that the CCS_ADJUSTABLE style must be specified to enable toolbar buttons to be dragged.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_ALTDRAG = 0x00000400;
/// @brief Creates a flat toolbar. In a flat toolbar, both the toolbar and the buttons are transparent and hot-tracking is enabled. Button text appears under button bitmaps. To prevent repainting problems, this style should be set before the toolbar control becomes visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_FLAT = 0x00000800;
/// @brief Creates a flat toolbar with button text to the right of the bitmap. Otherwise, this style is identical to TBSTYLE_FLAT. To prevent repainting problems, this style should be set before the toolbar control becomes visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_LIST = 0x00001000;
/// @brief Generates NM_CUSTOMDRAW notification codes when the toolbar processes WM_ERASEBKGND messages.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_CUSTOMERASE = 0x00002000;
/// @brief Generates TBN_GETOBJECT notification codes to request drop target objects when the cursor passes over toolbar buttons.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_REGISTERDROP = 0x00004000;
/// @brief Creates a transparent toolbar. In a transparent toolbar, the toolbar is transparent but the buttons are not. Button text appears under button bitmaps. To prevent repainting problems, this style should be set before the toolbar control becomes visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBSTYLE_TRANSPARENT = 0x00008000;
#endif

/// @brief Specifies that the tool bar button texts are visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_SHOWTEXT = 0x00020000;
/// @brief Specifies that the tool bar button texts are right-aligned. The default value is bottom aligned.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_TEXTRIGHTALIGN = 0x00040000;
/// @brief Specifies that the tool bar is left position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_LEFT = 0x00080000;
/// @brief Specifies that the tool bar is bottom position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_BOTTOM = 0x00100000;
/// @brief Specifies that the tool bar is right position. The default value is top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_RIGHT = 0x00200000;
/// @brief Specifies that the tool bar icon is no visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_NOSHOWICON = 0x00400000;
/// @brief Specifies that the tool bar divider is no visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbstyle
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t TBSTYLE_NODIVIDER = 0x00800000;
