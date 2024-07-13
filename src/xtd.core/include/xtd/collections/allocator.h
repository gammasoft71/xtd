/// @file
/// @brief Contains xtd::allocator alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represent an allocator alias.
    /// @par Header
    /// ```cpp
    /// #include <xtd/allocator>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The xtd::collections::allocator is the default allocator used by all xtd library containers if no user-specified allocator is provided.
    /// @remarks The xtd::collections::allocator is alias on [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator).
    /// @remarks A simple alias for the moment, which leaves open the possibility of implementing a specific allocator for xtd if necessary in the future.
    /// @par Examples
    /// ```cpp
    /// auto v = std::vector<int, xtd::collections::allocator> {};
    /// v.push_back(42);
    /// ```
    template<typename type_t>
    using allocator = std::allocator<type_t>;
  }
}
