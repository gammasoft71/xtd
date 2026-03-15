/// @file
/// @brief Contains xtd::ranges::views::to_list_view class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#define __XTD_STD_INTERNAL__
#include "../../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "../../linq/enumerable.hpp"
#include "../../istringable.hpp"
#include "../../string.hpp"
#include "../../views/views.hpp"

/// @cond
#if defined(__xtd__cpp_lib_ranges)
/// @endcond
#include <ranges>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The ranges namespace is an extension and generalization of the xtd::linq that makes them more powerful by making them composable and less error-prone.
  namespace ranges {
    /// @brief The view namesapce contains range views, lightweight objects that indirectly represent iterable sequences (ranges).
    namespace views {
      /// @brief The xtd::ranges::views::to_list_view class is used to convert a sequence to a list.
      /// @par Definition
      /// ```cpp
      /// class to_list_view;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/to_list_view>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      /// @par Examples
      /// The following example shows how to use xtd::ranges::views::to_list instance :
      /// @include ranges_views_to_list.cpp
      /// The following example shows how to use xtd::ranges::views::to_list_view class :
      /// @include ranges_views_to_list2.cpp
      class to_list_view {
      public:
        /// @name Public Operators
        
        /// @{
        /// @brief Converts a sequence of values to a list.
        /// @tparam range_t The type of the elements of source.
        /// @param source A sequence of values to convert to list.
        template <std::ranges::range range_t>
        auto operator()(range_t&& source) const {return xtd::linq::enumerable::from(std::forward<range_t>(source)).to_list();}
        
        /// @brief Applies a filter on the given range using the pipe operator.
        /// @tparam range_t The type of the elements of source.
        /// @param source A sequence of values to convert to list.
        /// @param view The to_list_view instance that defines the projection.
        /// @return A projected range resulting from applying the to_list_view to the input range.
        /// @par Examples
        /// @code
        /// auto numbers = std::vector {1, 2, 3, 4};
        /// auto result = numbers | to_list_view();
        /// // result = xtd::collections::generic::list {1, 2, 3, 4}
        /// @endcode
        template <std::ranges::range range_t>
        friend auto operator |(range_t&& source, const to_list_view& view) {return view(std::forward<range_t>(source));}
        /// @}
      };
    }
  }
}
/// @cond
#endif
/// @endcond
