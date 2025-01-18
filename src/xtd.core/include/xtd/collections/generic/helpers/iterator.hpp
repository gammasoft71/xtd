/// @file
/// @brief Contains iteraors aliases.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <iterator>
#include <tuple>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Represents the value iterator type.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template <class input_iterator_t>
        using iterator_value_t = typename std::iterator_traits<input_iterator_t>::value_type;
        
        /// @brief Represents the key iterator type.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template <class input_iterator_t>
        using iterator_key_t = std::remove_const_t<std::tuple_element_t<0, iterator_value_t<input_iterator_t>>>;
        
        /// @brief Represents the mapped iterator type.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template <class input_iterator_t>
        using iterator_mapped_t = std::tuple_element_t<1, iterator_value_t<input_iterator_t>>;
        
        /// @brief Represents the iterator to allocator type.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template< class input_iterator_t >
        using iterator_to_allocator_t = std::pair<std::add_const_t<iterator_key_t<input_iterator_t>>, iterator_mapped_t<input_iterator_t>>;
      }
    }
  }
}
