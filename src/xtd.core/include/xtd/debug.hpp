/// @file
/// @brief Contains #DEBUG definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The #DEBUG definition.
/// ```cpp
/// DEBUG
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
#if !defined(NDEBUG) && !DEBUG
#  define DEBUG 1
#endif
