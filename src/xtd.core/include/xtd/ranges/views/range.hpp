/// @file
/// @brief Contains xtd::ranges::views::to_array value.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#define __XTD_STD_INTERNAL__
#include "../../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "../../linq/enumerable.hpp"

/// @cond
#if defined(__xtd__cpp_lib_ranges)
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The ranges namespace is an extension and generalization of the xtd::linq that makes them more powerful by making them composable and less error-prone.
  namespace ranges {
    /// @brief The view namesapce contains range views, lightweight objects that indirectly represent iterable sequences (ranges).
    namespace views {
      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// auto range(type_t count);
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/range>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      template<typename type_t>
      [[nodiscard]] auto range(type_t count) {
        return xtd::linq::enumerable::range(count);
      }

      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// auto range(type_t start, type_t count);
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/range>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      template<typename type_t>
      [[nodiscard]] auto range(type_t start, type_t count) {
        return xtd::linq::enumerable::range(start, count);
      }

      /// @brief Generates a sequence of integral numbers within a specified range and step.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @param step The integer number specifying the incrementation.
      /// @return An xtd::collections::generic::ienumerable that contains a range of sequential integral numbers.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// auto range(type_t start, type_t count, type_t step);
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/ranges/views/range>
      /// ```
      /// @par Namespace
      /// xtd::ranges::views
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core ranges
      template<typename type_t>
      [[nodiscard]] auto range(type_t start, type_t count, type_t step) {
        return xtd::linq::enumerable::range(start, count, step);
      }
    }
  }
}
/// @cond
#endif
/// @endcond
