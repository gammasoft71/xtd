/// @file
/// @brief Contains xtd::ranges::views::__xtd_range_view_adapter__ class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#define __XTD_STD_INTERNAL__
#include "../../internal/__xtd_std_version.hpp"
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
      /// @cond
      /// Usage example :
      /// template <std::ranges::range range_t>
      /// auto operator()(range_t&& source) const {
      ///   auto result = xtd::linq::enumerable::as_enumerable(std::forward<range_t>(source)).distinct().distinct();
      ///   return __xtd_range_view_adapter__<decltype(result)> {std::move(result)};
      /// }
      template <typename range_t>
      class __xtd_range_view_adapter__ : public xtd::istringable {
      public:
        explicit __xtd_range_view_adapter__(range_t&& range) : range(std::move(range)) {}
        auto begin() {return range.begin();}
        auto end() {return range.end();}
        auto begin() const {return range.begin();}
        auto end() const {return range.end();}
        auto cbegin() const {return range.begin();}
        auto cend() const {return range.end();}
        xtd::string to_string() const override {return string::format("{}", range);}
      private:
        range_t range;
      };
      /// @endcond
    }
  }
}
/// @cond
#endif
/// @endcond
