/// @file
/// @brief Contains xtd::ranges and xtd::views namespaces.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @cond
#if defined(__xtd__cpp_lib_ranges)
/// @endcond
#include <ranges>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The namespace alias xtd::ranges is provided as a shorthand for std::ranges.
  namespace ranges = std::ranges;
  
  /// @brief The namespace alias xtd::views is provided as a shorthand for std::ranges::views.
  namespace views = xtd::ranges::views;
}
/// @cond
#endif
/// @endcond
