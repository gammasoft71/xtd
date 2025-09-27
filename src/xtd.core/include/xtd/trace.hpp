/// @file
/// @brief Contains #TRACE definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The #TRACE definition.
/// @remarks xtd defines #DEBUG and #TRACE macros for .NET compatibility.
/// @remarks In C++, the real control macros are NDEBUG and NTRACE.
#if !defined(NTRACE) && !defined(TRACE)
#  define TRACE
#endif
