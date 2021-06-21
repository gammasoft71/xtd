
/// @file
/// @brief Contains assert idalog result constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
 
/// @brief The assert dialog return value is Abort (usually sent from a button labeled Abort).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native adr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADR_ABORT = 3;
/// @brief The assert dialog return value is Retry (usually sent from a button labeled Retry).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native adr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADR_RETRY = 4;
/// @brief The assert dialog return value is Ignore (usually sent from a button labeled Ignore).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native adr
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADR_IGNORE = 5;
