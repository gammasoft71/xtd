/// @file
/// @brief Contains xtd::signed_integer_8 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "sbyte.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/signed_integer_8_.hpp
  template<typename type_t>
  concept signed_integer_8 =
  std::same_as<xtd::raw_type<type_t>, xtd::sbyte>;
}
