/// @file
/// @brief Contains xtd::forward_iterable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iterable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/forward_iterable_.hpp
  template <class value_t>
  concept forward_iterable = xtd::iterable<value_t> && std::forward_iterator<decltype(std::begin(std::declval<value_t&>()))>;
}

#include "forward_iterable_value_type.hpp"
