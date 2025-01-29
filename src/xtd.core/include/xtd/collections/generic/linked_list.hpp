/// @file
/// @brief Contains xtd::collections::generic::linked_list <value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/comparer.hpp"
#include "list.hpp"
#include <forward_list>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a doubly linked list.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// using linked_list = std::list<type_t, xtd::collections::generic::helpers::allocator<type_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/linked_list>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      using linked_list = std::forward_list<type_t, allocator_t>;
    }
  }
}
