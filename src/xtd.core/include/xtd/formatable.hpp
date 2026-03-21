/// @file
/// @brief Contains xtd::formatable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "stream_insertable.hpp"
#include "iformatable.hpp"
#include "raw_type.hpp"
#include <concepts>

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
  /// The following code shows how to use xtd::formatbale conceps
  /// @include formatbale.cpp
  template<class value_t>
  concept formatable =
  std::derived_from<xtd::raw_type<value_t>, xtd::iformatable> ||
  xtd::stream_insertable<xtd::raw_type<value_t>>;
}
