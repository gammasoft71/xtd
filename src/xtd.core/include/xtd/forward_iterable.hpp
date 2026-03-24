/// @file
/// @brief Contains xtd::forward_iterable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#if defined(__xtd__cpp_lib_ranges)
#include <ranges>
#endif
#include <concepts>
#include <iterator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/forward_iterable_.hpp
  template<typename value_t>
  concept forward_iterable =
#if defined(__xtd__cpp_lib_ranges)
  std::ranges::range<value_t> &&
#endif
  std::forward_iterator<std::ranges::iterator_t<value_t>>;
}

#include "forward_iterable_value_type.hpp"
