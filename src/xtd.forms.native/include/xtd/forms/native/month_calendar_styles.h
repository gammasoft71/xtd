/// @file
/// @brief Contains month calendar styles constants.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#if !defined(MCS_DAYSTATE)
/// @brief The month calendar sends MCN_GETDAYSTATE notifications to request information about which days should be displayed in bold.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_DAYSTATE = 0x0001;
/// @brief The month calendar enables the user to select a range of dates within the control. By default, the maximum range is one week. You can change the maximum range that can be selected by using the MCM_SETMAXSELCOUNT message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_MULTISELECT = 0x0002;
/// @brief The month calendar control displays week numbers (1-52) to the left of each row of days. Week 1 is defined as the first week that contains at least four days.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_WEEKNUMBERS = 0x0004;
/// @brief The month calendar control does not circle the "today" date.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_NOTODAYCIRCLE = 0x0008;
/// @brief The month calendar control does not display the "today" date at the bottom of the control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_NOTODAY = 0x0010;
/// @brief Dates from the previous and next months are not displayed in the current month's calendar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_NOTRAILINGDATES = 0x0040;
/// @brief Short day names are displayed in the header.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_SHORTDAYSOFWEEK = 0x0080;
/// @brief The selection is not changed when the user navigates next or previous in the calendar. This allows the user to select a range larger than is visible.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t MCS_NOSELCHANGEONNAV = 0x0100;
#endif
