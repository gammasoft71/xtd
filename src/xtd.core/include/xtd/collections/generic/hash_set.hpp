/// @file
/// @brief Contains xtd::collections::generic::hash_set struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
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
      /// template<typename type_t>
      /// using hash_set = std::unordered_set<type_t, helpers::hasher<type_t>, helpers::equator<type_t>, helpers::allocator<type_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/hash_set
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::hash_set class is same as [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set).
      template<typename type_t>
      using hash_set = std::unordered_set<type_t, helpers::hasher<type_t>, helpers::equator<type_t>, helpers::allocator<type_t>>;
    }
  }
}
