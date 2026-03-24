/// @file
/// @brief Contains xtd::arithmeticable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "addable.hpp"
#include "divisible.hpp"
#include "multipliable.hpp"
#include "subtractable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/arithmeticable_.hpp
  template<typename type_t>
  concept arithmeticable =
  xtd::addable<type_t> &&
  xtd::divisible<type_t> &&
  xtd::multipliable<type_t> &&
  xtd::subtractable<type_t>;
}
