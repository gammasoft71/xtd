/// @file
/// @brief Contains xtd::collections::generic::sorted_set struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.h"
#include "helpers/comparer.h"
#include <set>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of objects that is maintained in sorted order.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// using sorted_set = std::set<type_t, helpers::comparer<type_t>, helpers::allocator<type_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/sorted_set
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::sorted_set class is same as [std::set](https://en.cppreference.com/w/cpp/container/set).
      /// @remarks A xtd::collections::generic::sorted_set object maintains a sorted order without affecting performance as elements are inserted and deleted. Duplicate elements are ! allowed. Changing the sort values of existing items is ! supported and may lead to unexpected behavior.
      /// @par Examples
      /// The following example demonstrates how to merge two disparate sets. This example creates two xtd::collections::generic::sorted_set objects, and populates them with even and odd numbers, respectively. A third xtd::collections::generic::sorted_set object is created from the set that contains the even numbers. The example then calls the UnionWith method, which adds the odd number set to the third set.
      /// @include sorted_set.cpp
      template<typename type_t>
      using sorted_set = std::set<type_t, helpers::comparer<type_t>, helpers::allocator<type_t>>;
    }
  }
}
