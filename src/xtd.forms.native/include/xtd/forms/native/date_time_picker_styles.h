/// @file
/// @brief Contains date time picker style constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef DTS_UPDOWN
/// @brief Places an up-down control to the right of the DTP control to modify date-time values. This style can be used in place of the drop-down month calendar, which is the default style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_UPDOWN = 0x0001;
/// @brief It is possible to have no date currently selected in the control. With this style, the control displays a check box that is automatically selected whenever a date is picked or entered. If the check box is subsequently deselected, the application cannot retrieve the date from the control because, in essence, the control has no date. The state of the check box can be set with the DTM_SETSYSTEMTIME message or queried with the DTM_GETSYSTEMTIME message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_SHOWNONE = 0x0002; // allow a NONE selection
/// @brief Displays the date in short format. The default format string for this style is defined by LOCALE_SSHORTDATE, which produces output like "4/19/96".
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_SHORTDATEFORMAT = 0x0000; // use the short date format (app must forward WM_WININICHANGE messages)
/// @brief Displays the date in long format. The default format string for this style is defined by LOCALE_SLONGDATEFORMAT, which produces output like "Friday, April 19, 1996". When this style is used, the dropdown button does not display an icon.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_LONGDATEFORMAT = 0x0004; // use the long date format (app must forward WM_WININICHANGE messages)
/// @brief Similar to the DTS_SHORTDATEFORMAT style, except the year is a four-digit field. The default format string for this style is based on LOCALE_SSHORTDATE. The output looks like: "4/19/1996".
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_SHORTDATECENTURYFORMAT = 0x000C; // short date format with century (app must forward WM_WININICHANGE messages)
/// @brief Displays the time. The default format string for this style is defined by LOCALE_STIMEFORMAT, which produces output like "5:31:42 PM".
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_TIMEFORMAT = 0x0009; // use the time format (app must forward WM_WININICHANGE messages)
/// @brief Allows the owner to parse user input and take necessary action. It enables users to edit within the client area of the control when they press the F2 key. The control sends DTN_USERSTRING notification codes when users are finished.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_APPCANPARSE = 0x0010; // allow user entered strings (app MUST respond to DTN_USERSTRING)
/// @brief The drop-down month calendar will be right-aligned with the control instead of left-aligned, which is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native dts
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t DTS_RIGHTALIGN = 0x0020; // right-align popup instead of left-align it
#endif
