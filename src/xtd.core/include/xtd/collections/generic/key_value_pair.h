/// @file
/// @brief Contains xtd::collections::key_value_pair alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Defines a key/value pair that can be set or retrieved.
      /// ```cpp
      /// template<typename key_t, typename value_t>
      /// using key_value_pair = std::pair<key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/key_value_pair>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks xtd::collection::generic::key_value_pair is an alias of [std::pair](https://en.cppreference.com/w/cpp/utility/pair).
      template<typename key_t, typename value_t>
      using key_value_pair = std::pair<key_t, value_t>;
    }
  }
}
