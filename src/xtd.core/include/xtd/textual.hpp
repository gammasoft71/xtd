/// @file
/// @brief Contains xtd::textual concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "string.hpp"
#include "raw_type.hpp"
#include "textual_literal.hpp"
#include "u16string.hpp"
#include "u32string.hpp"
#include "u8string.hpp"
#include "wstring.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a text concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::textual = std::same_as<type_t, const char*> || std::same_as<type_t, const wchar_t*> || std::same_as<type_t, const char8_t*> || std::same_as<type_t, const char16_t*> || std::same_as<type_t, const char32_t*>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/textual>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class type_t>
  concept textual =
  std::same_as<xtd::raw_type<type_t>, std::string> ||
  std::same_as<xtd::raw_type<type_t>, std::u16string> ||
  std::same_as<xtd::raw_type<type_t>, std::u32string> ||
  std::same_as<xtd::raw_type<type_t>, std::u8string> ||
  std::same_as<xtd::raw_type<type_t>, std::wstring> ||
  std::same_as<xtd::raw_type<type_t>, xtd::string> ||
  std::same_as<xtd::raw_type<type_t>, xtd::u16string> ||
  std::same_as<xtd::raw_type<type_t>, xtd::u32string> ||
  std::same_as<xtd::raw_type<type_t>, xtd::u8string> ||
  std::same_as<xtd::raw_type<type_t>, xtd::wstring> ||
  xtd::textual_literal<type_t>;
}
