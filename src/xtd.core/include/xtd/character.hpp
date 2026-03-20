/// @file
/// @brief Contains xtd::character struct and character_v struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "char.hpp"
#include "char8.hpp"
#include "char16.hpp"
#include "char32.hpp"
#include "wchar.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a string literal concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::character = std::same_as<type_t, xtd::char_> || std::same_as<type_t, xtd::char8> || std::same_as<type_t, xtd::char16> || std::same_as<type_t, xtd::char32> || std::same_as<type_t, xtd::wchar>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/character>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class type_t>
  concept character =
  std::same_as<xtd::raw_type<type_t>, xtd::char_> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char8> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char16> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char32> ||
  std::same_as<xtd::raw_type<type_t>, xtd::wchar>;
}
