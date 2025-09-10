/// @file
/// @brief Contains xtd::epos constant.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "npos"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the index of the firsy valid element in a collection.
  /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
  /// @par Examples
  /// ```cpp
  /// auto items = array {10, 20, 30, 40};
  /// console::write_line(items[bpos]); // Prints 10
  /// ```
  static inline constexpr xtd::size bpos = 0;
}
