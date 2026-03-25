/// @file
/// @brief Contains xtd::post_decrementable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/post_decrementable_.hpp
  template<typename type_t>
  concept post_decrementable = requires(xtd::raw_type<type_t>& a) {
    {a--} -> std::same_as<xtd::raw_type<type_t>>;
  };
}
