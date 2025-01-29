/// @file
/// @brief Contains xtd::collections::generic::hash_set <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
#include "iset.hpp"
#include <unordered_set>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a set of values.
      /// @par Definition
      /// ```cpp
      /// template<class type_t, class hasher_t = xtd::collections::generic::helpers::hasher<type_t>, class equator_t = xtd::collections::generic::helpers::equator<type_t>, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      /// using hash_set = std::unordered_set<type_t, hasher_t, equator_t, allocator_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/hash_set>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::hash_set class is same as [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set).
      template<class type_t, class hasher_t = xtd::collections::generic::helpers::hasher<type_t>, class equator_t = xtd::collections::generic::helpers::equator<type_t>, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      using hash_set = std::unordered_set<type_t, hasher_t, equator_t, allocator_t>;
    }
  }
}
