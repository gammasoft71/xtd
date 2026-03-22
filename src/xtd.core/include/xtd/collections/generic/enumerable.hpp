/// @file
/// @brief Contains xtd::collections::generic::enumerable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "ienumerable.hpp"
#include "../../raw_type"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/collections/generic/enumerable.hpp
      template<class type_t>
      concept enumerable =
      requires {typename xtd::raw_type<type_t>::value_type;} &&
      std::derived_from<xtd::raw_type<type_t>, xtd::collections::generic::ienumerable<typename xtd::raw_type<type_t>::value_type>>;
    }
  }
}

#include "enumerable_value_type.hpp"
