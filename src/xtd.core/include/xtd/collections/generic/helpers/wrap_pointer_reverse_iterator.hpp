/// @file
/// @brief Contains xtd::collections::generic::helpers::wrap_pointer_reverse_iterator alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "wrap_pointer_iterator.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Represents a wrap pointer reverse iterator.
        /// @par Definition
        /// ```cpp
        /// template<class value_t, class iterator_tag_t = std::random_access_iterator_tag>
        /// using wrap_pointer_reverse_iterator = std::reverse_iterator<wrap_pointer_iterator<value_t, iterator_tag_t>>;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/genric/helpers/wrap_pointer_reverse_iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class value_t, class iterator_tag_t = std::random_access_iterator_tag>
        using wrap_pointer_reverse_iterator = std::reverse_iterator<wrap_pointer_iterator<value_t, iterator_tag_t>>;
      }
    }
  }
}
