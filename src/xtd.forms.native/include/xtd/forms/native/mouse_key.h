/// @file
/// @brief Contains mouse key constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef MK_LBUTTON
/// @brief The left mouse button is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_LBUTTON = 0x0001;
/// @brief The right mouse button is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_RBUTTON = 0x0002;
/// @brief The SHIFT key is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_SHIFT = 0x0004;
/// @brief The CTRL key is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_CONTROL = 0x0008;
/// @brief The middle mouse button is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_MBUTTON = 0x0010;
/// @brief The first X button is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_XBUTTON1 = 0x0020;
/// @brief The second X button is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_XBUTTON2 = 0x0040;
#endif
/// @brief The CMD key is down.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mk
/// @warning Internal use only
constexpr size_t MK_COMMAND = 0x0080;
