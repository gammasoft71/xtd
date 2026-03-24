/// @file
/// @brief Contains xtd::signed_integer_64 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "int64.hpp"
#include "slong.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/signed_integer_64_.hpp
  template<typename type_t>
  concept signed_integer_64 =
  std::same_as<xtd::raw_type<type_t>, xtd::int64> ||
  std::same_as<xtd::raw_type<type_t>, xtd::slong>;
}
