#pragma once

#include <ratio>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a tick (1 tick = 100 nanoseconds).
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  using tick = std::ratio<1LL, 10000000LL>;
}
