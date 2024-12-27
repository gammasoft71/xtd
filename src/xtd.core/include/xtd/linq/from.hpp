/// @file
/// @brief Contains xtd::linq::from methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
    template <typename source_t>
    const xtd::collections::generic::ienumerable<source_t>& from(const xtd::collections::generic::ienumerable<source_t>& source) {
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
    template <typename source_t>
    const xtd::collections::generic::ienumerable<source_t>& from(const std::initializer_list<source_t>& source) {
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
    template <typename collection_t>
    const auto& from(const collection_t& source) {
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
    template <typename input_iterator_t>
    const auto& from(input_iterator_t first, input_iterator_t last) {
      return enumerable::as_enumerable(first, last);
    }
  }
}
