/// @file
/// @brief Contains xtd::raw_type alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a raw type alias equivalent to std::remove_cvref_t<value_t>.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// using xtd::raw_type = std::remove_cvref_t<value_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/raw_type>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename value_t>
  using raw_type = std::remove_cvref_t<value_t>;
}
