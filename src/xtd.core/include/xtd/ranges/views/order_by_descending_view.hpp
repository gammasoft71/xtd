/// @file
/// @brief Contains xtd::ranges::views::order_by_descending_view class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
      /// @brief The xtd::ranges::views::order_by_descending_view class is used to sort the elements of a sequence in descending order according to a key.
      /// @par Definition
      /// ```cpp
      /// class order_by_descending_view;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/order_by_descending_view>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      /// @par Examples
      /// The following example shows how to use xtd::ranges::views::order_by_descending instance :
      /// @include ranges_views_order_by_descending.cpp
      /// The following example shows how to use xtd::ranges::views::order_by_descending_view class :
      /// @include ranges_views_order_by_descending2.cpp
      class order_by_descending_view {
        template <typename key_selector_t>
        struct with_key_selector {
          const key_selector_t& key_selector;
          
          template <std::ranges::range range_t>
          auto operator()(range_t&& source) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).order_by_descending(key_selector);}
          
          template <std::ranges::range range_t>
          friend auto operator |(range_t&& source, const with_key_selector& self) {return self(std::forward<range_t>(source));}
        };
        
      public:
        /// @name Public Operators
        
        /// @{
        /// @brief Sorts the elements of a sequence in descending order according to a key.
        /// @tparam range_t The type of the elements of source.
        /// @param source A sequence of values to sort.
        /// @param key_selector A function to extract a key from an element.
        template <std::ranges::range range_t, typename key_selector_t>
        auto operator()(range_t&& source, const key_selector_t& key_selector) const {return xtd::linq::enumerable::from(std::forward<range_t>(source)).order_by_descending(key_selector);}
        /// @brief Sorts the elements of a sequence in descending order according to a key.
        /// @tparam range_t The type of the elements of source.
        /// @param key_selector A function to extract a key from an element.
        template <typename key_selector_t>
        auto operator()(const key_selector_t& key_selector) const {return with_key_selector {key_selector};}
        
        /// @brief Applies a sort on the given range using the pipe operator.
        /// @tparam range_type The type of the input range.
        /// @param source The input range to which the order_by_descending view will be applied.
        /// @param view The order_by_descending_view instance that defines the projection.
        /// @return A projected range resulting from applying the order_by_descending_view to the input range.
        /// @par Examples
        /// @code
        /// auto numbers = std::vector {4, 2, 1, 3};
        /// auto result = numbers | order_by_descending_view([](int x) {return x;});
        /// // result = {1, 2, 3, 4}
        /// @endcode
        template <std::ranges::range range_type>
        friend auto operator |(range_type&& source, const order_by_descending_view& view) {return view(std::forward<range_type>(source));}
        /// @}
      };
    }
  }
}
/// @cond
#endif
/// @endcond
