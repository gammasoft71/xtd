/// @file
/// @brief Contains xtd::textual_literal concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "char.hpp"
#include "char8.hpp"
#include "char16.hpp"
#include "char32.hpp"
#include "wchar.hpp"
#include <type_traits>
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a text literal concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::textual_literal = std::same_as<type_t, const char*> || std::same_as<type_t, const wchar_t*> || std::same_as<type_t, const char8_t*> || std::same_as<type_t, const char16_t*> || std::same_as<type_t, const char32_t*>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/textual_literal>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class type_t>
  concept textual_literal =
  std::same_as<type_t, const xtd::char_*> ||
  std::same_as<type_t, const xtd::wchar*> ||
  std::same_as<type_t, const xtd::char8*> ||
  std::same_as<type_t, const xtd::char16*> ||
  std::same_as<type_t, const xtd::char32*>;
}
