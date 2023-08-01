/// @file
/// @brief Contains internal std::chrono duration types.
#pragma once
/// @cond
#if !defined(__XTD_CORE_DURATION_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <chrono>
#include <ratio>

/// @cond
#define __GCC_VERSION__ (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if __cplusplus == 201703L || (_MSC_VER && _MSC_VER < 1929) || (!__clang__ && !_MSC_VER && __GCC_VERSION__ < 100000)
namespace std {
  namespace chrono {
    using days = std::chrono::duration<long, std::ratio<86400>>;
    using weeks = std::chrono::duration<long, std::ratio<604800>>;
    using months = std::chrono::duration<long, std::ratio<2629746>>;
    using years = std::chrono::duration<long, std::ratio<31556952>>;
  }
}
#endif
/// @endcond
