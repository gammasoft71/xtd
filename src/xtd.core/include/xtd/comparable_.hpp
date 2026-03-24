/// @file
/// @brief Contains xtd::comparable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/comparable> or <xtd/comparable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the comparable concept.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept xtd::comparable = xtd::less_than_comparable<value_t> && xtd::greater_than_comparable<value_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/comparable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::comparable concept
  /// @include comparable.cpp
  template<typename value_t>
  struct comparable;
}
