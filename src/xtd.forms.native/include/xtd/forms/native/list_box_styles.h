/// @file
/// @brief Contains combo box style constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef LBS_NOSEL
/// @brief Causes the list box to send a notification code to the parent window whenever the user clicks a list box item (LBN_SELCHANGE), double-clicks an item (LBN_DBLCLK), or cancels the selection (LBN_SELCANCEL).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_NOTIFY = 0x0001;
/// @brief Sorts strings in the list box alphabetically.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_SORT = 0x0002;
/// @brief Specifies that the list box's appearance is not updated when changes are made.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_NOREDRAW = 0x0004;
/// @brief Turns string selection on or off each time the user clicks or double-clicks a string in the list box. The user can select any number of strings.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_MULTIPLESEL = 0x0008;
/// @brief Specifies that the owner of the list box is responsible for drawing its contents and that the items in the list box are the same height. The owner window receives a WM_MEASUREITEM message when the list box is created and a WM_DRAWITEM message when a visual aspect of the list box has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_OWNERDRAWFIXED = 0x0010;
/// @brief Specifies that the owner of the list box is responsible for drawing its contents and that the items in the list box are variable in height. The owner window receives a WM_MEASUREITEM message for each item in the box when the list box is created and a WM_DRAWITEM message when a visual aspect of the list box has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_OWNERDRAWVARIABLE = 0x0020;
/// @brief Specifies that a list box contains items consisting of strings. The list box maintains the memory and addresses for the strings so that the application can use the LB_GETTEXT message to retrieve the text for a particular item. By default, all list boxes except owner-drawn list boxes have this style. You can create an owner-drawn list box either with or without this style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_HASSTRINGS = 0x0040;
/// @brief Enables a list box to recognize and expand tab characters when drawing its strings. You can use the LB_SETTABSTOPS message to specify tab stop positions. The default tab positions are 32 dialog template units apart. Dialog template units are the device-independent units used in dialog box templates. To convert measurements from dialog template units to screen units (pixels), use the MapDialogRect function.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_USETABSTOPS = 0x0080;
/// @brief Specifies that the size of the list box is exactly the size specified by the application when it created the list box. Normally, the system sizes a list box so that the list box does not display partial items.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_NOINTEGRALHEIGHT = 0x0100;
/// @brief Specifies a multi-column list box that is scrolled horizontally. The list box automatically calculates the width of the columns, or an application can set the width by using the LB_SETCOLUMNWIDTH message. If a list box has the LBS_OWNERDRAWFIXED style, an application can set the width when the list box sends the WM_MEASUREITEM message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_MULTICOLUMN = 0x0200;
/// @brief Specifies that the owner of the list box receives WM_VKEYTOITEM messages whenever the user presses a key and the list box has the input focus. This enables an application to perform special processing on the keyboard input.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_WANTKEYBOARDINPUT = 0x0400;
/// @brief Allows multiple items to be selected by using the SHIFT key and the mouse or special key combinations.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_EXTENDEDSEL = 0x0800;
/// @brief Shows a disabled horizontal or vertical scroll bar when the list box does not contain enough items to scroll. If you do not specify this style, the scroll bar is hidden when the list box does not contain enough items. This style must be used with the WS_VSCROLL or WS_HSCROLL style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_DISABLENOSCROLL = 0x1000;
/// @brief Specifies a no-data list box. Specify this style when the count of items in the list box will exceed one thousand. A no-data list box must also have the LBS_OWNERDRAWFIXED style, but must not have the LBS_SORT or LBS_HASSTRINGS style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_NODATA = 0x2000;
/// @brief Specifies that the list box contains items that can be viewed but not selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_NOSEL = 0x4000;
/// @brief Notifies a list box that it is part of a combo box. This allows coordination between the two controls so that they present a unified UI. The combo box itself must set this style. If the style is set by anything but the combo box, the list box will regard itself incorrectly as a child of a combo box and a failure will result.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native lbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t LBS_COMBOBOX = 0x8000;
#endif
