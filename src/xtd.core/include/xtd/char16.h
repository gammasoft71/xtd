/// @file
/// @brief Contains xtd::char16 type.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a 16-bit unicode character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char16>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char16 = char16_t;
  /// @}
}
