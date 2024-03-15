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
#if defined(_MSC_FULL_VER) && defined(_MSC_BUILD) && _MSC_BUILD != 0
#  define __compiler_version xtd::version {_MSC_FULL_VER / 10000000, _MSC_FULL_VER % 10000000 / 100000, _MSC_FULL_VER % 100000, _MSC_BUILD}
#elif defined(_MSC_FULL_VER)
#  define __compiler_version xtd::version {_MSC_FULL_VER / 10000000, _MSC_FULL_VER % 10000000 / 100000, _MSC_FULL_VER % 100000}
#elif defined(_MSC_VER)
#  define __compiler_version xtd::version {_MSC_VER / 100, _MSC_VER % 100}
#elif defined(__clang__) && __clang_patchlevel__ != 0
#  define __compiler_version xtd::version {__clang_major__, __clang_minor__, __clang_patchlevel__}
#elif defined(__clang__)
#  define __compiler_version xtd::version {__clang_major__, __clang_minor__}
#elif defined(__GNUC__) && __GNUC_PATCHLEVEL__ != 0
#  define __compiler_version xtd::version {__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__}
#elif defined(__GNUC__)
#  define __compiler_version xtd::version {__GNUC__, __GNUC_MINOR__}
#else
#  define __compiler_version xtd::version {}
#endif
/// @endcond
