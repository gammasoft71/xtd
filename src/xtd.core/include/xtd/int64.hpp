/// @file
/// @brief Contains xtd::int64 type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a 64-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/int64>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using int64 = int64_t;
  /// @}
}

#include "literals/int64.hpp"
