/// @file
/// @brief Contains xtd::collections::generic::enumerable_value_type alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enumerable.hpp"
#include "../../raw_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents the enumerable value type.
      /// @par Definition
      /// ```cpp
      /// template <xtd::collections::generic::enumerable_type>
      /// using enumerable_value_type;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd//collections/generic/enumerable_value_type>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core system concepts
      /// @par Examples
      /// The following code shows how to use xtd::collections::generic::enumerable concept
      /// @include generic_enumerable.cpp
      template <xtd::collections::generic::enumerable enumerable_type>
      using enumerable_value_type = xtd::raw_type<decltype(*std::begin(std::declval<enumerable_type&>()))>;
    }
  }
}
