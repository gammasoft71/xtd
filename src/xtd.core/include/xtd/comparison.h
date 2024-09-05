/// @file
/// @brief Contains xtd::comparison alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "delegate.h"
#include "int32.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that compares two objects of the same type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param T The type of the objects to compare.
  /// @param x The first object to compare.
  /// @param y The second object to compare.
  /// @return Int32 A signed integer that indicates the relative values of x and y, as shown in the following table.
  /// | Value          | Meaning              |
  /// |----------------|----------------------|
  /// | less than 0    | x is less than y.    |
  /// | 0              | x equals y.          |
  /// | Greater than 0 | x is greater than y. |
  template<typename type_t>
  using comparison = delegate<int32, type_t, type_t>;
}
