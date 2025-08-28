/// @file
/// @brief Contains xtd::views alias namespace.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @cond
#if defined(__xtd__cpp_lib_ranges)
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The ranges namespace is an extension and generalization of the xtd::linq that makes them more powerful by making them composable and less error-prone.
  namespace ranges {
    /// @brief The view namesapce contains range views, lightweight objects that indirectly represent iterable sequences (ranges).
    namespace views {
    }
  }

  /// @brief The namespace alias xtd::views is provided as a shorthand for xtd::ranges::views.
  namespace views = xtd::ranges::views;
}
/// @cond
#endif
/// @endcond
