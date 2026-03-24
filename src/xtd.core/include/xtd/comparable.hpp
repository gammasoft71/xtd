/// @file
/// @brief Contains xtd::comparable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "greater_than_comparable.hpp"
#include "less_than_comparable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/comparable_.hpp
  template<typename value_t>
  concept comparable =
  xtd::less_than_comparable<value_t> &&
  xtd::greater_than_comparable<value_t>;
}
