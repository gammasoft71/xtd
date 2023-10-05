/// @file
/// @brief Contains __compiler_version definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../version.h"

/// @cond
#if defined(_MSC_VER)
#  define __compiler_version xtd::version {_MSC_VER / 100, _MSC_VER % 100, 0}
#elif defined(__clang__)
#  define __compiler_version xtd::version {__clang_major__, __clang_minor__, __clang_patchlevel__}
#elif defined(__GNUC__)
#  define __compiler_version xtd::version {__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__}
#else
#  define __compiler_version xtd::version {}
#endif
/// @endcond
