/// @file
/// @brief Contains xtd::forward_iterable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/forward_iterable> or <xtd/forward_iterable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the forward iterable concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::forward_iterable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/forward_iterable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @par Examples
  /// The following code shows how to use xtd::forward_iterable concept
  /// @include forward_iterable.cpp
  template<class value_t>
  struct forward_iterable;
}
