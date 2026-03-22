/// @file
/// @brief Contains xtd::collections::generic::enumerable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#error "Do not include this file: Internal use only. Include <xtd/collections/generic/enumerable> or <xtd/collections/generic/enumerable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Concept enumerable.
      /// @par Definition
      /// ```cpp
      /// template<class value_t>
      /// concept xtd::collections::generic::enumerable = requires {typename xtd::raw_type<type_t>::value_type;} && std::derived_from<xtd::raw_type<type_t>, xtd::collections::generic::ienumerable<typename xtd::raw_type<type_t>::value_type>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd//collections/generic/enumerable>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core system concepts
      /// @par Examples
      /// The following code shows how to use xtd::collections::generic::enumerable conceps
      /// @include generic_enumerable.cpp
      template<class type_t>
      struct enumerable;
    }
  }
}

#include "enumerable_value_type.hpp"
