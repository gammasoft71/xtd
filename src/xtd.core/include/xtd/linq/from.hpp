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
    template<xtd::forward_iterable source_t>
    [[nodiscard]] auto from(const source_t& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    /// @cond
    template<typename value_t>
    [[nodiscard]] auto from(const std::initializer_list<value_t>& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    template<std::forward_iterator iterator_t>
    [[nodiscard]] auto from(iterator_t first, iterator_t last) noexcept {return xtd::linq::enumerable::as_enumerable(first, last);}
    template<std::forward_iterator iterator_t>
    [[nodiscard]] auto from(iterator_t iterator, xtd::usize length) noexcept {return xtd::linq::enumerable::as_enumerable(iterator, length);}
    template<typename source_t, xtd::usize length>
    [[nodiscard]] auto from(const source_t (&array)[length]) noexcept {return xtd::linq::enumerable::as_enumerable(array);}
    template<xtd::usize size_>
    [[nodiscard]] auto from(const std::bitset<size_>& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    template<typename value_t, typename container_t>
    [[nodiscard]] auto from(const std::queue<value_t, container_t>& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    template<typename value_t, typename container_t>
    [[nodiscard]] auto from(const std::priority_queue<value_t, container_t>& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    template<typename value_t, typename container_t>
    [[nodiscard]] auto from(const std::stack<value_t, container_t>& source) noexcept {return xtd::linq::enumerable::as_enumerable(source);}
    /// @endcond
  }
}
