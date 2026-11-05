/// @file
/// @brief Contains __xtd_unreachable definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @cond
#if defined(_MSC_VER)
#  define __xtd_unreachable() (__assume(false))
#elif defined(__GNUC__) || defined(__clang__)
#  define __xtd_unreachable() (__builtin_unreachable())
#else
[[noreturn]] inline auto ___unreachable___() -> void {}
#define __xtd_unreachable() (___unreachable___())
#endif
/// @endcond
