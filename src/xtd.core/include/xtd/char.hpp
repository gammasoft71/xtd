/// @file
/// @brief Contains xtd::char_ type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Represents a 32-bit unicode character on Linux and many other non-Windows systems, but a 16-bit unicode character on Windows.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char_ = char;
  /// @}
}
