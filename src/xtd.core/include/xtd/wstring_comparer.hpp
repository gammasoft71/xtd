/// @file
/// @brief Contains xtd::wstring_comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_comparer.hpp"
#include "wchar.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a wstring comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// using wstring_comparer = xtd::basic_string_comparer<xtd::wchar>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/wstring_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  using wstring_comparer = xtd::basic_string_comparer<xtd::wchar>;
}
