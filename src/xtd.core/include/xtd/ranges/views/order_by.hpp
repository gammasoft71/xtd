/// @file
/// @brief Contains xtd::ranges::views::order_by value.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#define __XTD_STD_INTERNAL__
#include "../../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "order_by_view.hpp"

/// @cond
#if defined(__xtd__cpp_lib_ranges)
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The ranges namespace is an extension and generalization of the xtd::linq that makes them more powerful by making them composable and less error-prone.
  namespace ranges {
    /// @brief The view namesapce contains range views, lightweight objects that indirectly represent iterable sequences (ranges).
    namespace views {
      /// @brief The xtd::ranges::views::order_by instance.
      /// @par Definition
      /// ```cpp
      /// inline constexpr auto order_by = order_by_view {};
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/order_by>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      /// @par Examples
      /// The following example shows how to use xtd::ranges::views::order_by instance :
      /// @include ranges_views_order_by.cpp
      /// The following example shows how to use xtd::ranges::views::order_by_view class :
      /// @include ranges_views_order_by2.cpp
      inline constexpr auto order_by = order_by_view {};
    }
  }
}
/// @cond
#endif
/// @endcond
