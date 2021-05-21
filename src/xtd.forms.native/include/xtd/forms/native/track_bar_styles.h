/// @file
/// @brief Contains track bar styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef TBS_AUTOTICKS
/// @brief The trackbar control has a tick mark for each increment in its range of values.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_AUTOTICKS = 0x0001;
/// @brief The trackbar control is oriented vertically.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_VERT = 0x0002;
/// @brief The trackbar control is oriented horizontally. This is the default orientation.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_HORZ = 0x0000;
/// @brief The trackbar control displays tick marks above the control. This style is valid only with TBS_HORZ.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_TOP = 0x0004;
/// @brief The trackbar control displays tick marks below the control. This style is valid only with TBS_HORZ.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_BOTTOM = 0x0000;
/// @brief The trackbar control displays tick marks to the left of the control. This style is valid only with TBS_VERT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_LEFT = 0x0004;
/// @brief The trackbar control displays tick marks to the right of the control. This style is valid only with TBS_VERT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_RIGHT = 0x0000;
/// @brief The trackbar control displays tick marks on both sides of the control. This will be both top and bottom when used with TBS_HORZ or both left and right if used with TBS_VERT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_BOTH = 0x0008;
/// @brief The trackbar control does not display any tick marks.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_NOTICKS = 0x0010;
/// @brief The trackbar control displays a selection range only. The tick marks at the starting and ending positions of a selection range are displayed as triangles (instead of vertical dashes), and the selection range is highlighted.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_ENABLESELRANGE = 0x0020;
/// @brief The trackbar control allows the size of the slider to be changed with the TBM_SETTHUMBLENGTH message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_FIXEDLENGTH = 0x0040;
/// @brief The trackbar control does not display a slider.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_NOTHUMB = 0x0080;
/// @brief The trackbar control supports tooltips. When a trackbar control is created using this style, it automatically creates a default tooltip control that displays the slider's current position. You can change where the tooltips are displayed by using the TBM_SETTIPSIDE message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_TOOLTIPS = 0x0100;
/// @brief This style bit is used for "reversed" trackbars, where a smaller number indicates "higher" and a larger number indicates "lower." It has no effect on the control; it is simply a label that can be checked to determine whether a trackbar is normal or reversed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_REVERSED = 0x0200;  // Accessibility hint: the smaller number (usually the min value) means "high" and the larger number (usually the max value) means "low"
/// @brief By default, the trackbar control uses down equal to right and up equal to left. Use the TBS_DOWNISLEFT style to reverse the default, making down equal left and up equal right.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_DOWNISLEFT = 0x0400;  // Down=Left and Up=Right (default is Down=Right and Up=Left)
/// @brief Trackbar should notify parent before repositioning the slider due to user action (enables snapping).
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_NOTIFYBEFOREMOVE = 0x0800;  // Trackbar should notify parent before repositioning the slider due to user action (enables snapping)
/// @brief Background is painted by the parent via the WM_PRINTCLIENT message.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TBS_TRANSPARENTBKGND = 0x1000;  // Background is painted by the parent via WM_PRINTCLIENT
#endif
