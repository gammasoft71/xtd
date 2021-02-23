#pragma once

#include <chrono>
#include "tick.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a tick duration
  using ticks = std::chrono::duration<long long, tick>;
}
