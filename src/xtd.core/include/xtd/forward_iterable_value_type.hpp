/// @file
/// @brief Contains xtd::forward_iterable_value_type alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "forward_iterable.hpp"
#include "raw_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the orward iterable value type.
  /// @par Definition
  /// ```cpp
  /// template <xtd::forward_iterable_value_type forward_iterable>
  /// using forward_iterable_value_type ;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/forward_iterable_value_type>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @par Examples
  /// The following code shows how to use xtd::forward_iterable_value_type conceps
  /// @include forward_iterable_value_type.cpp
  template <xtd::forward_iterable forward_iterable_type>
  using forward_iterable_value_type = xtd::raw_type<decltype(*std::begin(std::declval<forward_iterable_type&>()))>;
}
