/// @file
/// @brief Contains xtd::numeric concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "integer.hpp"
#include "real.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/numeric_.hpp
  template<typename type_t>
  concept numeric =
  xtd::integer<type_t> ||
  xtd::real<type_t>;
}
