/// @file
/// @brief Contains xtd::unsigned_integer_16 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include "uint16.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/unsigned_integer_16_.hpp
  template<typename type_t>
  concept unsigned_integer_16 =
  std::same_as<xtd::raw_type<type_t>, xtd::uint16>;
}
