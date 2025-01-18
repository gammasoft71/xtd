/// @file
/// @brief Contains xtd::collections::generic::list definitions.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents the type to list type.
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/list>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t>
      using type_to_list_t = typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type;
      
      /// @cond
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_to_list_t<type_t>>>
      class list;
      /// @endcond
    }
  }
}
