/// @file
/// @brief Contains xtd::incrementable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "post_incrementable.hpp"
#include "pre_incrementable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/incrementable_.hpp
  template<typename type_t>
  concept incrementable =
  xtd::post_incrementable<type_t> &&
  xtd::pre_incrementable<type_t>;
}
