/// @file
/// @brief Contains xtd::ranges::views::where_view class.
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
      /// @brief The xtd::ranges::views::where_view class is used to filter elements from a sequence.
      /// @par Definition
      /// ```cpp
      /// class where_view;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/where_view>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      class where_view {
        template <typename predicate_t>
        struct with_predicate {
          const predicate_t& predicate;
          
          template <std::ranges::range range_t>
          auto operator()(range_t&& source) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).where(predicate);}
          
          template <std::ranges::range range_t>
          friend auto operator |(range_t&& source, const with_predicate& self) {return self(std::forward<range_t>(source));}
        };
        
      public:
        /// @name Public Operators
        
        /// @{
        /// @brief Filters a sequence of values based on a predicate.
        /// @tparam range_t The type of the elements of source.
        /// @param source A sequence of values to filter.
        /// @param predicate A function to test each element for a condition.
        template <std::ranges::range range_t, typename predicate_t>
        auto operator()(range_t&& source, const predicate_t& predicate) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).where(predicate);}
        /// @brief Filters a sequence of values based on a predicate.
        /// @tparam range_t The type of the elements of source.
        /// @param predicate A function to test each element for a condition.
        template <typename predicate_t>
        auto operator()(const predicate_t& predicate) const {return with_predicate {predicate};}
        
        /// @brief Applies a filter on the given range using the pipe operator.
        /// @tparam range_type The type of the input range.
        /// @param source The input range to which the where view will be applied.
        /// @param view The where_view instance that defines the projection.
        /// @return A projected range resulting from applying the where_view to the input range.
        /// @par Examples
        /// @code
        /// auto numbers = std::vector {1, 2, 3, 4};
        /// auto result = numbers | where_view([](int x) { return x % 2 == 0; });
        /// // result = {2, 4}
        /// @endcode
        template <std::ranges::range range_type>
        friend auto operator |(range_type&& source, const where_view& view) {return view(std::forward<range_type>(source));}
        /// @}
      };
    }
  }
}
/// @cond
#endif
/// @endcond
