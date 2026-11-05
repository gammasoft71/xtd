/// @file
/// @brief Contains __xtd_unreachable definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @cond
#if !defined(NDEBUG) && defined(_MSC_VER)
#  define __xtd_unreachable() (__assume(false))
#elif !defined(NDEBUG) && (defined(__GNUC__) || defined(__clang__))
#  define __xtd_unreachable() (__builtin_unreachable())
#else
#include <cstdlib>
[[noreturn]] inline auto ___unreachable___() noexcept -> void {std::_Exit(0);}
#define __xtd_unreachable() (___unreachable___())
#endif
/// @endcond
