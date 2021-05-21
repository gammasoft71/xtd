/// @file
/// @brief Contains tab control styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef TCS_SCROLLOPPOSITE
/// @brief Unneeded tabs scroll to the opposite side of the control when a tab is selected.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_SCROLLOPPOSITE = 0x0001; // assumes multiline tab
/// @brief Tabs appear at the bottom of the control. This value equals TCS_RIGHT.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_BOTTOM = 0x0002;
/// @brief Tabs appear vertically on the right side of controls that use the TCS_VERTICAL style. This value equals TCS_BOTTOM.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_RIGHT = 0x0002;
/// @brief Multiple tabs can be selected by holding down the CTRL key when clicking. This style must be used with the TCS_BUTTONS style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_MULTISELECT = 0x0004; // allow multi-select in button mode
/// @brief Selected tabs appear as being indented into the background while other tabs appear as being on the same plane as the background. This style only affects tab controls with the TCS_BUTTONS style
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FLATBUTTONS = 0x0008;
/// @brief Icons are aligned with the left edge of each fixed-width tab. This style can only be used with the TCS_FIXEDWIDTH style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FORCEICONLEFT = 0x0010;
/// @brief Labels are aligned with the left edge of each fixed-width tab; that is, the label is displayed immediately to the right of the icon instead of being centered. This style can only be used with the TCS_FIXEDWIDTH style, and it implies the TCS_FORCEICONLEFT style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FORCELABELLEFT = 0x0020;
/// @brief Items under the pointer are automatically highlighted. You can check whether hot tracking is enabled by calling SystemParametersInfo.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_HOTTRACK = 0x0040;
/// @brief Tabs appear at the left side of the control, with tab text displayed vertically. This style is valid only when used with the TCS_MULTILINE style. To make tabs appear on the right side of the control, also use the TCS_RIGHT style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_VERTICAL = 0x0080;
/// @brief Tabs appear as tabs, and a border is drawn around the display area. This style is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_TABS = 0x0000;
/// @brief Tabs appear as buttons, and no border is drawn around the display area.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_BUTTONS = 0x0100;
/// @brief Only one row of tabs is displayed. The user can scroll to see more tabs, if necessary. This style is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_SINGLELINE = 0x0000;
/// @brief Multiple rows of tabs are displayed, if necessary, so all tabs are visible at once.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_MULTILINE = 0x0200;
/// @brief The width of each tab is increased, if necessary, so that each row of tabs fills the entire width of the tab control. This window style is ignored unless the TCS_MULTILINE style is also specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_RIGHTJUSTIFY = 0x0000;
/// @brief All tabs are the same width. This style cannot be combined with the TCS_RIGHTJUSTIFY style.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FIXEDWIDTH = 0x0400;
/// @brief Rows of tabs will not be stretched to fill the entire width of the control. This style is the default.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_RAGGEDRIGHT = 0x0800;
/// @brief The tab control receives the input focus when clicked.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FOCUSONBUTTONDOWN = 0x1000;
/// @brief The parent window is responsible for drawing tabs.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_OWNERDRAWFIXED = 0x2000;
/// @brief The tab control has a tooltip control associated with it.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_TOOLTIPS = 0x4000;
/// @brief The tab control does not receive the input focus when clicked.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native tcs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t TCS_FOCUSNEVER = 0x8000;
#endif
