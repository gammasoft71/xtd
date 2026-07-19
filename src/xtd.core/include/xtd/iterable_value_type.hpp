/// @file
/// @brief Contains xtd::iterable_value_type alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iterable.hpp"
#include "raw_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the orward iterable value type.
  /// @par Definition
  /// ```cpp
  /// template <xtd::iterable_value_type iterable>
  /// using iterable_value_type ;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/iterable_value_type>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @par Examples
  /// The following code shows how to use xtd::iterable_value_type concept
  /// @include iterable_value_type.cpp
  template <xtd::iterable iterable_t>
  using iterable_value_type = xtd::raw_type<decltype(*std::begin(std::declval<iterable_t&>()))>;
}
