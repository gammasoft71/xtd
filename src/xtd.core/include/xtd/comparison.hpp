/// @file
/// @brief Contains xtd::comparison delegate.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "delegate.hpp"
#include "int32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that compares two objects of the same type.
  /// ```cpp
  /// template<class type_t>
  /// using comparison = xtd::delegate<int32(type_t x, type_t y)>;
  /// ```
  /// @param type_t The type of the objects to compare.
  /// @param x The first object to compare.
  /// @param y The second object to compare.
  /// @return A signed integer that indicates the relative values of x and y, as shown in the following table.
  /// | Value          | Meaning              |
  /// |----------------|----------------------|
  /// | less than 0    | x is less than y.    |
  /// | 0              | x equals y.          |
  /// | Greater than 0 | x is greater than y. |
  /// @par Header
  /// ```cpp
  /// #include <xtd/comparison>
  /// ```
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  template<class type_t>
  using comparison = xtd::delegate<int32(type_t x, type_t y)>;
}
