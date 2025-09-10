/// @file
/// @brief Contains xtd::npos constant.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "size.hpp"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Fields
  
  /// @{
  /// @brief Represents a value that is not a valid position in a collection.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::size.
  /// @par Examples
  /// ```cpp
  /// auto items = array {1, 2, 3};
  /// if (items.index_of(42) == npos)
  ///   console::write_line("Value not found");
  /// ```
  static inline constexpr xtd::size npos = std::numeric_limits<xtd::size>::max();
  /// @}
}
