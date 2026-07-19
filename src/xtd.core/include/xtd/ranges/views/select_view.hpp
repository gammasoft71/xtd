/// @file
/// @brief Contains xtd::ranges::views::select_view class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#include "../../linq/enumerable.hpp"
#include "../../istringable.hpp"
#include "../../iterable.hpp"
#include "../../string.hpp"
#include "../../views/views.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The ranges namespace is an extension and generalization of the xtd::linq that makes them more powerful by making them composable and less error-prone.
  namespace ranges {
    /// @brief The view namesapce contains range views, lightweight objects that indirectly represent iterable sequences (ranges).
    namespace views {
      /// @brief The xtd::ranges::views::select_view class is used to select elements from a sequence.
      /// @par Definition
      /// ```cpp
      /// class select_view;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/select_view>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      /// @par Examples
      /// The following example shows how to use xtd::ranges::views::select instance :
      /// @include ranges_views_select.cpp
      /// The following example shows how to use xtd::ranges::views::select_view class :
      /// @include ranges_views_select2.cpp
      class select_view {
        template<typename selector_t>
        struct with_selector {
          const selector_t& selector;
          
          template <xtd::iterable iterable_t>
          auto operator()(iterable_t&& source) const {return xtd::linq::enumerable::from(std::forward<iterable_t>(source)).select(selector);}
          
          template <xtd::iterable iterable_t>
          friend auto operator |(iterable_t&& source, const with_selector& self) {return self(std::forward<iterable_t>(source));}
        };
        
      public:
        /// @name Public Operators
        
        /// @{
        /// @brief Projects each element of a sequence into a new form.
        /// @param source A sequence of values to invoke a transform function on.
        /// @param selector A transform function to apply to each element.
        /// @return An iterable select elements from the source sequence.
        template <xtd::iterable iterable_t, typename selector_t>
        auto operator()(iterable_t&& source, const selector_t& selector) const {return xtd::linq::enumerable::as_enumerable(std::forward<iterable_t>(source)).select(selector);}
        /// @brief Projects each element of a sequence into a new form.
        /// @param selector A transform function to apply to each element.
        /// @return An iterable select elements from the source sequence.
        template<typename selector_t>
        auto operator()(const selector_t& selector) const {return with_selector {selector};}
        
        /// @brief Applies a select projection on the given range using the pipe operator.
        /// @tparam range_type The type of the input range.
        /// @param source The input range to which the select view will be applied.
        /// @param view The select_view instance that defines the projection.
        /// @return A projected range resulting from applying the select_view to the input range.
        /// @par Examples
        /// @code
        /// auto numbers = std::vector {1, 2, 3, 4};
        /// auto result = numbers | select_view([](int x) { return x * 2; });
        /// // result = {2, 4, 6, 8}
        /// @endcode
        template <xtd::iterable iterable_t>
        friend auto operator |(iterable_t&& source, const select_view& view) {return view(std::forward<iterable_t>(source));}
        /// @}
      };
    }
  }
}
