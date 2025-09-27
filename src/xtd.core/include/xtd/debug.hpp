/// @file
/// @brief Contains #DEBUG definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The #DEBUG definition.
/// @remarks xtd defines #DEBUG and #TRACE macros for .NET compatibility.
/// @remarks In C++, the real control macros are NDEBUG and NTRACE.
#if !defined(NDEBUG) && !defined(DEBUG)
#  define DEBUG
#endif
