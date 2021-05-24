/// @file
/// @brief Contains xtd::ticks typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <chrono>
#include "tick.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a tick duration
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ticks = std::chrono::duration<long long, tick>;
}
