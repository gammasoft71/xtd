/// @file
/// @brief Contains xtd::u8string_comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_comparer.hpp"
#include "char8.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Represents a u8string comparison operation that uses specific case and culture-based or ordinal comparison rules.
  /// @par Definition
  /// ```cpp
  /// using u8string_comparer = xtd::basic_string_comparer<xtd::char8>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/u8string_comparer
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  using u8string_comparer = xtd::basic_string_comparer<xtd::char8>;
#endif
}
