/// @file
/// @brief Contains xtd::ptrdiff type.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represent the signed integer type of the result of subtracting two pointers.
  /// @par Header
  /// ```cpp
  /// #include <xtd/ptrdiff>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using ptrdiff = std::ptrdiff_t;
  /// @}
}
