/// @file
/// @brief Contains xtd::collections::generic::list struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../allocator.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a strongly typed list of objects that can be accessed by index. Provides methods to search, sort, and manipulate lists.
      /// ```cpp
      /// class list
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/list
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::list is alias on [std::vector](https://en.cppreference.com/w/cpp/container/vector).
      /// @remarks A simple alias for the moment, which leaves open the possibility of implementing a specific list for xtd if necessary in the future.
      template<typename type_t, typename allocator_t = xtd::collections::allocator<type_t>>
      using list = std::vector<type_t, allocator_t>;
    }
  }
}
