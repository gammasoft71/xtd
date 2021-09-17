
/// @file
/// @brief Contains socket option level constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Socket options apply to all sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_level
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_LEVEL_SOCKET = 65535;

/// @brief Socket options apply only to IP sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_level
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_LEVEL_IP = 0;

/// @brief Socket options apply only to IPv6 sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_level
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_LEVEL_IP_V6 = 41;

/// @brief Socket options apply only to TCP sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_level
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_LEVEL_TCP = 6;

/// @brief Socket options apply only to UDP sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_level
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_LEVEL_UDP = 17;
