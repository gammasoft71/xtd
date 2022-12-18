/// @file
/// @brief Contains xtd::ticks typedef.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <chrono>
#include "tick.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a tick duration
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ticks = std::chrono::duration<int64, tick>;
}
