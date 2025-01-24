/// @file
/// @brief Contains xtd::u16string_comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_comparer.hpp"
#include "char16.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Aliases
  
  /// @{
  /// @brief Represents a u16string comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// using u16string_comparer = xtd::basic_string_comparer<xtd::char16>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/u16string_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  using u16string_comparer = xtd::basic_string_comparer<xtd::char16>;
  /// @}
}
