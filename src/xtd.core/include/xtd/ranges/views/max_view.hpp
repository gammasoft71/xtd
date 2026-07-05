/// @file
/// @brief Contains xtd::ranges::views::max_view class.
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
      class max_view {
      public:
        /// @name Public Operators
        
        /// @{
        template <std::ranges::range range_t>
        auto operator()(range_t&& source) const {return xtd::linq::enumerable::from(std::forward<range_t>(source)).max();}
        
        template <std::ranges::range range_t>
        friend auto operator |(range_t&& source, const max_view& view) {return view(std::forward<range_t>(source));}
        /// @}
      };
    }
  }
}
/// @cond
#endif
/// @endcond
