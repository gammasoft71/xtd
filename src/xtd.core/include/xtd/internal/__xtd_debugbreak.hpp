/// @file
/// @brief Contains __xtd_debugbreak definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @cond
#if defined(_MSC_VER)
#define __xtd_debugbreak __debugbreak
#elif defined(__clang__) || defined(__GNUC__)
#define __xtd_debugbreak __builtin_trap
#else
#include <cstdlib>
#define __xtd_debugbreak std::abort
#endif
/// @endcond
