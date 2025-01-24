/// @file
/// @brief Contains xtd::string_comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_comparer.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Aliases
  
  /// @{
  /// @brief Represents a string comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// using string_comparer = basic_string_comparer<char>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/string_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  using string_comparer = basic_string_comparer<char>;
  /// @}
}
