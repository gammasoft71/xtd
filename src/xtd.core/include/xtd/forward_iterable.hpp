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
#include <iterator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @concept xtd::forward_iterable
  /// @brief Concept forward iterable.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::forward_iterable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/forward_iterable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system concepts
  /// @par Examples
  /// The following code shows how to use xtd::forward_iterable conceps
  /// @include forward_iterable.cpp
  template<class value_t>
  concept forward_iterable =
#if defined(__xtd__cpp_lib_ranges)
  std::ranges::range<value_t> &&
#endif
  std::forward_iterator<std::ranges::iterator_t<value_t>>;
}

#include "forward_iterable_value_type.hpp"
