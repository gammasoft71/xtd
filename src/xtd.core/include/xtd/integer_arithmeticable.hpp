/// @file
/// @brief Contains xtd::integer_arithmeticable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "arithmeticable.hpp"
#include "modable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/integer_arithmeticable_.hpp
  template<typename type_t>
  concept integer_arithmeticable =
  xtd::arithmeticable<type_t> &&
  xtd::modable<type_t>;
}
