/// @file
/// @brief Contains xtd::ticks typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "chrono.hpp"
#include "tick.hpp"
#include "types.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represents a tick duration
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using ticks = std::chrono::duration<int64, tick>;
  /// @}
}
