/// @file
/// @brief Contains #TRACE definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The #TRACE definition.
/// ```cpp
/// TRACE
/// ```
/// @par Header
/// ```cpp
/// #include <xtd/trace>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core
/// @remarks xtd defines #DEBUG and #TRACE macros for .NET compatibility.
/// @remarks In C++, the real control macros are NDEBUG and NTRACE.
#if !defined(NTRACE) && !TRACE
#  define TRACE 1
#endif
