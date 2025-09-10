/// @file
/// @brief Contains xtd::epos constant.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "npos"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the index of the last valid element in a collection.
  /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
  /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
  /// @par Examples
  /// ```cpp
  /// auto items = array {10, 20, 30, 40};
  /// console::write_line(items[epos]); // Prints 40
  /// ```
  static inline constexpr xtd::size epos = xtd::npos - 1;
}
