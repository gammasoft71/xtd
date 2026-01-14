/// @file
/// @brief Contains xtd::formatable concept.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "iformatable.hpp"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept formatable.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::formatable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/helpers/formatable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @return `true` if value_t is derived from xtd::object, or value_t is derived from xtd::iformatable, or value_t is derived from xtd::iformatable, or value_t is derived from std::exception, or value_t is an enum, value_t is std::ranges::range, or value_t has output stream operator `<<`; otherwise `false`.
  /// @remarks If a type has only a xtd::to_string specialisation, it is always considered not formatable.
  template<class value_t>
  concept formatable = std::derived_from<std::remove_cvref_t<value_t>, xtd::iformatable>;
}
