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
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/textual_literal_.hpp
  template<typename type_t>
  concept textual_literal =
  std::same_as<type_t, const xtd::char_*> ||
  std::same_as<type_t, const xtd::wchar*> ||
  std::same_as<type_t, const xtd::char8*> ||
  std::same_as<type_t, const xtd::char16*> ||
  std::same_as<type_t, const xtd::char32*>;
}
