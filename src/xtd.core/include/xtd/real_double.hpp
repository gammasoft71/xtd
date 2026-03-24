/// @file
/// @brief Contains xtd::real_double concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "double.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/real_double_.hpp
  template<typename type_t>
  concept real_double =
  std::same_as<xtd::raw_type<type_t>, xtd::double_>;
}
