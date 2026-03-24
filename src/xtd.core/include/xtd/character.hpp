/// @file
/// @brief Contains xtd::character concept.
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
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/character_.hpp
  template<typename type_t>
  concept character =
  std::same_as<xtd::raw_type<type_t>, xtd::char_> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char8> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char16> ||
  std::same_as<xtd::raw_type<type_t>, xtd::char32> ||
  std::same_as<xtd::raw_type<type_t>, xtd::wchar>;
}
