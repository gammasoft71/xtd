/// @file
/// @brief Contains xtd::stringable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/stringable> or <xtd/stringable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the stringable concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::stringable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/stringable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @return `true` if value_t is derived from xtd::object, or value_t is derived from xtd::istringable, or value_t is derived from xtd::iformatable, or value_t is derived from std::exception, or value_t is an enum, value_t is std::ranges::range, or value_t has output stream operator `<<`; otherwise `false`.
  /// @remarks If a type has only a xtd::to_string specialisation, it is always considered not stringable.
  /// @par Examples
  /// The following code shows how to use xtd::stringable concept
  /// @include stringable.cpp
  template<class value_t>
  struct stringable;
}
