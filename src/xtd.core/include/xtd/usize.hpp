/// @file
/// @brief Contains xtd::usize type.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @brief Represents an unsigned size of any object in bytes
  /// @par Header
  /// ```cpp
  /// #include <xtd/usize>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using usize = std::size_t;
  /// @}
}

#include "literals/usize.hpp"
