/// @file
/// @brief Contains xtd::unsigned_integer_64 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include "uint64.hpp"
#include "ulong.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/unsigned_integer_64_.hpp
  template<typename type_t>
  concept unsigned_integer_64 =
  std::same_as<xtd::raw_type<type_t>, xtd::uint64> ||
  std::same_as<xtd::raw_type<type_t>, xtd::ulong>;
}
