/// @file
/// @brief Contains xtd::decrementable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "post_decrementable.hpp"
#include "pre_decrementable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/decrementable_.hpp
  template<typename type_t>
  concept decrementable =
  xtd::post_decrementable<type_t> &&
  xtd::pre_decrementable<type_t>;
}
