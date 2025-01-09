/// @file
/// @brief Contains xtd::collections::generic::sorted_dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/comparer.hpp"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of key/value pairs that are sorted on the key.
      /// @par Definition
      /// ```cpp
      /// template<typename key_t, typename value_t>
      /// using sorted_dictionary = std::map<key_t, value_t, helpers::comparer<key_t>, helpers::allocator<std::pair<const key_t, value_t>>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/sorted_dictionary
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::sorted_dictionary class is same as [std::map](https://en.cppreference.com/w/cpp/container/map).
      /// @remarks A xtd::collections::generic::sorted_dictionary object maintains a sorted order without affecting performance as elements are inserted and deleted. Duplicate elements are ! allowed. Changing the sort values of existing items is ! supported and may lead to unexpected behavior.
      /// @par Examples
      /// The following shows how to use xtd::collections::generic::sorted_dictionary.
      /// @include sorted_dictionary.cpp
      template<typename key_t, typename value_t>
      using sorted_dictionary = std::map<key_t, value_t, helpers::comparer<key_t>, helpers::allocator<std::pair<const key_t, value_t>>>;
    }
  }
}
