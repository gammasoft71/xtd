/// @file
/// @brief Contains xtd::collections::generic::dictionary struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
      /// @brief Represents a collection of keys and values.
      /// @par Definition
      /// ```cpp
      /// template<typename key_t, typename value_t>
      /// using dictionary = std::unordered_map<key_t, value_t, helpers::hasher<key_t>, helpers::equator<key_t>, helpers::allocator<std::pair<const key_t, value_t>>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/dictionary
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::dictionary class is same as [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map).
      /// @par Examples
      /// The following shows how to use xtd::collections::generic::dictionary.
      /// @include dictionary.cpp
      template<typename key_t, typename value_t>
      using dictionary = std::unordered_map<key_t, value_t, helpers::hasher<key_t>, helpers::equator<key_t>, helpers::allocator<std::pair<const key_t, value_t>>>;
    }
  }
}
