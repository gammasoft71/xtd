/// @file
/// @brief Contains xtd::helpers::greater_than_comparable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept greater than comparable.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// concept xtd::greater_than_comparable = requires(const type_t& a, const type_t& b) {{ a > b } -> std::convertible_to<bool>;};
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/greater_than_comparable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core helpers concepts
  template<typename type_t>
  concept greater_than_comparable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {
    {a > b} -> std::convertible_to<bool>;
  };
}
