/// @file
/// @brief Contains xtd::ranges::views::distinct_view class.
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
      /// @brief The xtd::ranges::views::distinct_view class is used to distinct elements from a sequence.
      class distinct_view {
        template <typename comparer_t>
        struct with_comparer {
          const comparer_t& comparer;
          
          template <std::ranges::range range_t>
          auto operator()(range_t&& source) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).distinct(comparer);}
          
          template <std::ranges::range range_t>
          friend auto operator |(range_t&& source, const with_comparer& self) {return self(std::forward<range_t>(source));}
        };
        
      public:
        /// @brief Returns distinct elements from a sequence by using the default equality comparer to compare values.
        /// @param source The sequence to remove duplicate elements from.
        /// @return An iterable distinct elements from the source sequence.
        template <std::ranges::range range_t>
        auto operator()(range_t&& source) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).distinct();}
        /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
        /// @param source The sequence to remove duplicate elements from.
        /// @param comparer An xtd::collections::generic::iequality_comparer <type_t> to compare values.
        /// @return An iterable distinct elements from the source sequence.
        template <std::ranges::range range_t, typename comparer_t>
        auto operator()(range_t&& source, const comparer_t& comparer) const {return xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).distinct(comparer);}
        /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
        /// @param comparer An xtd::collections::generic::iequality_comparer <type_t> to compare values.
        /// @return An iterable distinct elements from the source sequence.
        template <typename comparer_t>
        auto operator()(const comparer_t& comparer) const {return with_comparer {comparer};}
        
        template <std::ranges::range range_type>
        friend auto operator |(range_type&& source, const distinct_view& view) {return view(std::forward<range_type>(source));}
      };
    }
  }
}
/// @cond
#endif
/// @endcond
