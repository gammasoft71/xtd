/// @file
/// @brief Contains xtd::formatable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/formatable> or <xtd/formatable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the formatable concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::formatable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/formatable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @return `true` if value_t is derived from xtd::iformatable, or value_t has output stream operator `<<`; otherwise `false`.
  /// @remarks If a type has only a xtd::to_string specialisation, it is always considered not formatable.
  /// @par Examples
  /// The following code shows how to use xtd::formatbale concept
  /// @include formatbale.cpp
  template<class value_t>
  struct formatable;
}
