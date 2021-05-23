
/// @file
/// @brief Contains environment variable target constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief The environment variable is stored or retrieved from the environment block associated with the current process.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native environment_variable_target
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ENVIRONMENT_VARIABLE_TARGET_PROCESS = 0;
/// @brief The environment variable is stored or retrieved from the HKEY_CURRENT_USER\Environment key in the Windows operating system registry.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native environment_variable_target
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ENVIRONMENT_VARIABLE_TARGET_USER = 1;
/// @brief The environment variable is stored or retrieved from the HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment key in the Windows operating system registry.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native environment_variable_target
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ENVIRONMENT_VARIABLE_TARGET_MACHINE = 2;
/// @brief Console color black.
