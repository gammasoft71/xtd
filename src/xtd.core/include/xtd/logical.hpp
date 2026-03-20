/// @file
/// @brief Contains xtd::logical concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "boolean.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a logical concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::logical = std::same_as<xtd::raw_type<type_t>, xtd::boolean>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/logical>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class type_t>
  concept logical =
  std::same_as<xtd::raw_type<type_t>, xtd::boolean>;
}
