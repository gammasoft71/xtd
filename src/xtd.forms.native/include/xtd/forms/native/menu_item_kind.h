/// @file
/// @brief Contains menu item kinds constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

/// @brief Normal menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mi
/// @warning Internal use only
constexpr size_t MI_NORMAL = 0;
/// @brief Check menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mi
/// @warning Internal use only
constexpr size_t MI_CHECK = 1;
/// @brief Radio menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mi
/// @warning Internal use only
constexpr size_t MI_RADIO = 2;
/// @brief Drop down menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mi
/// @warning Internal use only
constexpr size_t MI_DROPDOWN = 3;
/// @brief Separator menu item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native mi
/// @warning Internal use only
constexpr size_t MI_SEPARATOR = 4;
