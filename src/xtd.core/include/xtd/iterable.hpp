/// @file
/// @brief Contains xtd::iterable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include <concepts>
#include <iterator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/iterable_.hpp
  template <class value_t>
  concept iterable = requires(value_t& value) {
    std::begin(value);
    std::end(value);
  };
}

#include "iterable_value_type.hpp"
