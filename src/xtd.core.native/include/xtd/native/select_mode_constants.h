/// @file
/// @brief Contains select mode constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Read status mode.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native select_mode
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SELECT_MODE_READ = 0;

/// @brief Write status mode.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native select_mode
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SELECT_MODE_WRITE = 1;

/// @brief Error status mode.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native select_mode
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SELECT_MODE_ERROR = 2;
