/// @file
/// @brief Contains xtd::epos constant.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "npos"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Fields
  
  /// @{
  /// @brief Represents the index of the last valid element in a collection.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
  /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
  /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
  /// @par Examples
  /// ```cpp
  /// auto items = array {10, 20, 30, 40};
  /// console::write_line(items[epos]); // Prints 40
  /// console::write_line(items[epos - 1]); // Prints 30
  /// ```
  /// The wollowing exemple shows the same example with bitwise operator as index.
  /// ```cpp
  /// auto items = array {10, 20, 30, 40};
  /// console::write_line(items[~1_z]); // Prints 40
  /// console::write_line(items[~2_z]); // Prints 30
  /// ```
  inline constexpr xtd::size epos = xtd::npos - 1;
  /// @}
}
