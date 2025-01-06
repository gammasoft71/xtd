/// @file
/// @brief Contains xtd::linq::from methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "enumerable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @param source A sequence of values.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    /// @include linq_from.cpp
    template <typename source_t>
    const xtd::collections::generic::ienumerable<source_t>& from(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
      return enumerable::as_enumerable(source);
    }
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @param source A sequence of values.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    /// @include linq_from2.cpp
    template <typename source_t>
    const xtd::collections::generic::ienumerable<source_t>& from(const std::initializer_list<source_t>& source) noexcept{
      return enumerable::as_enumerable(source);
    }
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @param source A sequence of values.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    template <typename collection_t>
    const auto& from(const collection_t& source) noexcept {
      return enumerable::as_enumerable(source);
    }
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @param first The first iterator.
    /// @param last The last iterator.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    /// @include linq_from4.cpp
    template <typename input_iterator_t>
    const auto& from(input_iterator_t first, input_iterator_t last) noexcept {
      return enumerable::as_enumerable(first, last);
    }
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @tparam input_iterator_t The type of the source iterators.
    /// @param iterator The iterator.
    /// @param legnth The le,gth to iterate.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    /// @include linq_from5.cpp
    template<typename input_iterator_t>
    const auto& from(input_iterator_t iterator, size_t length) noexcept {
      return enumerable::as_enumerable(iterator, iterator + length);
    }
    /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
    /// @tparam source_t The type of the source array.
    /// @param array The native array.
    /// @param legnth The length of the array.
    /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
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
    /// @include linq_from6.cpp
    template<typename source_t, size_t length>
    const auto& from(const source_t (&array)[length]) noexcept {
      return enumerable::as_enumerable(array, array + length);
    }
  }
}
