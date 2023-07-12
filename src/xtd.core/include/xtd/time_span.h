/// @file
/// @brief Contains xtd::time_span typedef.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "ticks.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represents a time interval.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using time_span = xtd::ticks;
  /// @}
}

