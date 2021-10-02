/// @file
/// @brief Contains edit styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef ES_LEFT
/// @brief Left-aligns text in a single-line or multiline edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_LEFT = 0x00000000L;
/// @brief Centers text in a single-line or multiline edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_CENTER = 0x00000001L;
/// @brief Right-aligns text in a single-line or multiline edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_RIGHT = 0x00000002L;
/// @brief Designates a multiple-line edit control. (The default is single line.) If the ES_AUTOVSCROLL style is specified, the edit control shows as many lines as possible and scrolls vertically when the user presses the ENTER key. If ES_AUTOVSCROLL is not given, the edit control shows as many lines as possible and beeps if ENTER is pressed when no more lines can be displayed. If the ES_AUTOHSCROLL style is specified, the multiple-line edit control automatically scrolls horizontally when the caret goes past the right edge of the control. To start a new line, the user must press ENTER. If ES_AUTOHSCROLL is not given, the control automatically wraps words to the beginning of the next line when necessary; a new line is also started if ENTER is pressed. The position of the wordwrap is determined by the window size. If the window size changes, the wordwrap position changes and the text is redisplayed. Multiple-line edit controls can have scroll bars. An edit control with scroll bars processes its own scroll-bar messages. Edit controls without scroll bars scroll as described above and process any scroll messages sent by the parent window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_MULTILINE = 0x00000004L;
/// @brief Converts all characters to uppercase as they are typed into the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_UPPERCASE = 0x00000008L;
/// @brief Converts all characters to lowercase as they are typed into the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_LOWERCASE = 0x00000010L;
/// @brief Displays all characters as an asterisk (*) as they are typed into the edit control. An application can use the SetPasswordChar member function to change the character that is displayed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_PASSWORD = 0x00000020L;
/// @brief Automatically scrolls text up one page when the user presses ENTER on the last line.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_AUTOVSCROLL = 0x00000040L;
/// @brief Automatically scrolls text to the right by 10 characters when the user types a character at the end of the line. When the user presses the ENTER key, the control scrolls all text back to position 0.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @warning Internal use only
/// @brief
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_AUTOHSCROLL = 0x00000080L;
/// @brief Normally, an edit control hides the selection when the control loses the input focus and inverts the selection when the control receives the input focus. Specifying ES_NOHIDESEL deletes this default action.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_NOHIDESEL = 0x00000100L;
/// @brief Text entered in the edit control is converted from the ANSI character set to the OEM character set and then back to ANSI. This ensures proper character conversion when the application calls the AnsiToOem Windows function to convert an ANSI string in the edit control to OEM characters. This style is most useful for edit controls that contain filenames.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_OEMCONVERT = 0x00000400L;
/// @brief Prevents the user from entering or editing text in the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_READONLY = 0x00000800L;
/// @brief Specifies that a carriage return be inserted when the user presses the ENTER key while entering text into a multiple-line edit control in a dialog box. Without this style, pressing the ENTER key has the same effect as pressing the dialog boxes default pushbutton. This style has no effect on a single-line edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_WANTRETURN = 0x00001000L;
/// @brief Allows only digits to be entered into the edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t ES_NUMBER = 0x00002000L;
#endif
/// @brief Specifies that a tabulation be inserted when the user presses the TAB key while entering text into a edit control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native es
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr size_t ES_WANTTAB = 0x00004000L;
