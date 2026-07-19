/// @file
/// @brief Contains xtd::iterable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/iterable> or <xtd/iterable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the iterable concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::iterable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/iterable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @par Examples
  /// The following code shows how to use xtd::iterable concept
  /// @include iterable.cpp
  template<class value_t>
  struct iterable;
}
