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

#ifndef CBS_SIMPLE
/// @brief Displays the list box at all times. The current selection in the list box is displayed in the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_SIMPLE = 0x0001L;
/// @brief Similar to CBS_SIMPLE, except that the list box is not displayed unless the user selects an icon next to the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_DROPDOWN = 0x0002L;
/// @brief Similar to CBS_DROPDOWN, except that the edit control is replaced by a static text item that displays the current selection in the list box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_DROPDOWNLIST = 0x0003L;
/// @brief Specifies that the owner of the list box is responsible for drawing its contents and that the items in the list box are all the same height. The owner window receives a WM_MEASUREITEM message when the combo box is created and a WM_DRAWITEM message when a visual aspect of the combo box has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_OWNERDRAWFIXED = 0x0010L;
/// @brief Specifies that the owner of the list box is responsible for drawing its contents and that the items in the list box are variable in height. The owner window receives a WM_MEASUREITEM message for each item in the combo box when you create the combo box and a WM_DRAWITEM message when a visual aspect of the combo box has changed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_OWNERDRAWVARIABLE = 0x0020L;
/// @brief Automatically scrolls the text in an edit control to the right when the user types a character at the end of the line. If this style is not set, only text that fits within the rectangular boundary is allowed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_AUTOHSCROLL = 0x0040L;
/// @brief Converts text entered in the combo box edit control from the Windows character set to the OEM character set and then back to the Windows character set. This ensures proper character conversion when the application calls the CharToOem function to convert a Windows string in the combo box to OEM characters. This style is most useful for combo boxes that contain file names and applies only to combo boxes created with the CBS_SIMPLE or CBS_DROPDOWN style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_OEMCONVERT = 0x0080L;
/// @brief Automatically sorts strings added to the list box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_SORT = 0x0100L;
/// @brief Specifies that an owner-drawn combo box contains items consisting of strings. The combo box maintains the memory and address for the strings so the application can use the CB_GETLBTEXT message to retrieve the text for a particular item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_HASSTRINGS = 0x0200L;
/// @brief Specifies that the size of the combo box is exactly the size specified by the application when it created the combo box. Normally, the system sizes a combo box so that it does not display partial items.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_NOINTEGRALHEIGHT = 0x0400L;
/// @brief Shows a disabled vertical scroll bar in the list box when the box does not contain enough items to scroll. Without this style, the scroll bar is hidden when the list box does not contain enough items.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_DISABLENOSCROLL = 0x0800L;
/// @brief Converts to uppercase all text in both the selection field and the list
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_UPPERCASE = 0x2000L;
/// @brief Converts to lowercase all text in both the selection field and the list.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native cbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t CBS_LOWERCASE = 0x4000L;
#endif
