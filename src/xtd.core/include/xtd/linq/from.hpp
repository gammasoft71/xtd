/// @file
/// @brief Contains xtd::linq::from methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enumerable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
    /// @param source A sequence of values.
    /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
    /// @par Header
    /// ```cpp
    /// #include <xtd/linq/from>
    /// ```
    /// @par Namespace
    /// xtd::linq
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core linq
    /// @par Examples
    /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
    /// @include linq_from3.cpp
    /// @see xtd::linq::enumerable::from methods for all overloads of xtd::linq::from.
    template<typename collection_t>
    [[nodiscard]] auto from(collection_t&& source) noexcept {
      return enumerable::as_enumerable(source);
    }
    /// @cond
    template<typename input_iterator_t>
    [[nodiscard]] auto from(input_iterator_t first, input_iterator_t last) noexcept {
      return enumerable::as_enumerable(first, last);
    }
    template<typename source_t>
    [[nodiscard]] auto from(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
      return enumerable::as_enumerable(source);
    }
    template<typename source_t>
    [[nodiscard]] auto from(const std::initializer_list<source_t>& source) noexcept {
      return enumerable::as_enumerable(source);
    }
    template<typename input_iterator_t>
    [[nodiscard]] auto from(input_iterator_t iterator, xtd::usize length) noexcept {
      return enumerable::as_enumerable(iterator, iterator + length);
    }
    template<typename source_t, xtd::usize length>
    [[nodiscard]] auto from(const source_t (&array)[length]) noexcept {
      return enumerable::as_enumerable(array, array + length);
    }
    /// @endcond
  }
}
