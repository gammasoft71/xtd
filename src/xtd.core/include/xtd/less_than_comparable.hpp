/// @file
/// @brief Contains xtd::helpers::less_than_comparable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <type_traits>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept less than comparable.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept xtd::less_than_comparable = requires(const value_t& a, const value_t& b) {{ a < b } -> std::convertible_to<bool>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/less_than_comparable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core helpers concepts
  template<typename value_t>
  concept less_than_comparable =
  requires(const value_t& a, const value_t& b) {{ a < b } -> std::convertible_to<bool>;};
}
