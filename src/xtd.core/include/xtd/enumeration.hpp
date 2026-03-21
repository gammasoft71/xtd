/// @file
/// @brief Contains xtd::enumeration concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a enumeration concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::enumeration = std::is_enum_v<xtd::raw_type<type_t>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/enumeration>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class type_t>
  concept enumeration =
  std::is_enum_v<xtd::raw_type<type_t>>;
}
