/// @file
/// @brief Contains xtd::stringable concept.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "stream_insertable.hpp"
#include "iformatable.hpp"
#include "istringable.hpp"
#include "object.hpp"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept stringable.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::stringable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/helpers/stringable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @return `true` if value_t is derived from xtd::object, or value_t is derived from xtd::istringable, or value_t is derived from xtd::iformatable, or value_t is derived from std::exception, or value_t is an enum, value_t is std::ranges::range, or value_t has output stream operator `<<`; otherwise `false`.
  /// @remarks If a type has only a xtd::to_string specialisation, it is always considered not stringable.
  template<class value_t>
  concept stringable =
    std::derived_from<std::remove_cvref_t<value_t>, xtd::object> ||
    std::derived_from<std::remove_cvref_t<value_t>, xtd::istringable<std::remove_cvref_t<value_t>>> ||
    std::derived_from<std::remove_cvref_t<value_t>, xtd::iformatable> ||
    std::derived_from<std::remove_cvref_t<value_t>, std::exception> ||
    std::is_enum_v<std::remove_cvref_t<value_t>> ||
    #if defined(__xtd__cpp_lib_ranges)
    std::ranges::range<std::remove_cvref_t<value_t>> ||
    #endif
    xtd::stream_insertable<std::remove_cvref_t<value_t>>;
}
