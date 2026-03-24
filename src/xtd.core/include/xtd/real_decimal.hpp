/// @file
/// @brief Contains xtd::real_decimal concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "decimal.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/real_decimal_.hpp
  template<typename type_t>
  concept real_decimal =
  std::same_as<xtd::raw_type<type_t>, xtd::decimal>;
}
