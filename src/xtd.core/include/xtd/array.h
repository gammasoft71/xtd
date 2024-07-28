/// @file
/// @brief Contains xtd::array alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, there by serving as the base class for all arrays.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// using array = std::vector<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/array>
  /// ```
    /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  using array = std::vector<type_t>;
}
