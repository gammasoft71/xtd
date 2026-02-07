/// @file
/// @brief Contains xtd::comparable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "helpers/greater_than_comparable.hpp"
#include "helpers/less_than_comparable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @concept xtd::comparable
  /// @brief Concept comparable.
  /// @par Definition
  /// ```cpp
  /// template<typename value_t>
  /// concept comparable;
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
  /// The following code shows how to use xtd::comparable conceps
  /// @include comparable.cpp
  template<typename value_t>
  concept comparable = xtd::helpers::less_than_comparable<value_t> && xtd::helpers::greater_than_comparable<value_t>;
}
