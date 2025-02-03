/// @file
/// @brief Contains xtd::collections::generic::sorted_list <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/lesser.hpp"
#include "sorted_dictionary.hpp" /// @todo remove when sorted_dictionay is developped.

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of key/value pairs that are sorted by the keys and are accessible by key and by index.
      /// @par Definition
      /// ```cpp
      /// template<class key_t, class value_t, class allocator_t = helpers::allocator<std::pair<const key_t, value_t>>>
      /// class sorted_list : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/sorted_list>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::sorted_list class is same as [std::map](https://en.cppreference.com/w/cpp/container/map).
      /// @remarks A xtd::collections::generic::sorted_list object maintains a sorted order without affecting performance as elements are inserted and deleted. Duplicate elements are ! allowed. Changing the sort values of existing items is ! supported and may lead to unexpected behavior.
      /// @par Examples
      /// The following shows how to use xtd::collections::generic::sorted_list.
      /// @include sorted_list.cpp
      template<class key_t, class value_t, class allocator_t = helpers::allocator<std::pair<const key_t, value_t>>>
      using sorted_list = sorted_dictionary<key_t, value_t, helpers::lesser<key_t>, allocator_t>;
    }
  }
}
