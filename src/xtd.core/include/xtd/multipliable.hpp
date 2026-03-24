/// @file
/// @brief Contains xtd::multipliable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/multipliable_.hpp
  template<typename type_t>
  concept multipliable = requires(const xtd::raw_type<type_t>& a, const xtd::raw_type<type_t>& b) {
    {a * b} -> std::same_as<xtd::raw_type<type_t>>;
  };
}
