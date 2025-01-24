/// @file
/// @brief Contains xtd::dynamic_extent field.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "size.hpp"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Fields
  
  /// @{
  /// @brief Represents the constant of type xtd::size signifying that the span has dynamic extent
  /// @remarks xtd::dynamic_extent is a constant of type xtd::size that is generally used to indicate that any type using xtd::dynamic_extent will dynamically store its value (e.g., size) rather than having the value statically known in the type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/dynamic_extent>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  inline constexpr xtd::size dynamic_extent = std::numeric_limits<xtd::size>::max();
  /// @}
}
