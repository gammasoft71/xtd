/// @file
/// @brief Contains xtd::collections::generic::stack <value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/comparer.hpp"
#include "icollection.hpp"
#include "list.hpp"
#include <deque>
#include <stack>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a variable size last-in-first-out (LIFO) collection of instances of the same specified type.
      /// @par Definition
      /// ```cpp
      /// template<class type_t, class container_t = std::deque<type_t>>
      /// using stack = std::stack<type_t, container_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/stack>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t, class container_t = std::deque<type_t>>
      using stack = std::stack<type_t, container_t>;
    }
  }
}
