/// @file
/// @brief Contains up down styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef UDS_WRAP
/// @brief Causes the position to "wrap" if it is incremented or decremented beyond the ending or beginning of the range.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_WRAP = 0x0001;
/// @brief Causes the up-down control to set the text of the buddy window (using the WM_SETTEXT message) when the position changes. The text consists of the position formatted as a decimal or hexadecimal string.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_SETBUDDYINT = 0x0002;
/// @brief Positions the up-down control next to the right edge of the buddy window. The width of the buddy window is decreased to accommodate the width of the up-down control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_ALIGNRIGHT = 0x0004;
/// @brief Positions the up-down control next to the left edge of the buddy window. The buddy window is moved to the right, and its width is decreased to accommodate the width of the up-down control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_ALIGNLEFT = 0x0008;
/// @brief Automatically selects the previous window in the z-order as the up-down control's buddy window.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_AUTOBUDDY = 0x0010;
/// @brief Causes the up-down control to increment and decrement the position when the UP ARROW and DOWN ARROW keys are pressed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_ARROWKEYS = 0x0020;
/// @brief Causes the up-down control's arrows to point left and right instead of up and down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_HORZ = 0x0040;
/// @brief Does not insert a thousands separator between every three decimal digits.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_NOTHOUSANDS = 0x0080;
/// @brief Causes the control to exhibit "hot tracking" behavior. That is, it highlights the UP ARROW and DOWN ARROW on the control as the pointer passes over them.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native uds
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t UDS_HOTTRACK = 0x0100;
#endif
