/// @file
/// @brief Contains xtd::collections::generic::icomparer <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../interface.hpp"
#include "../../int32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Exposes a method that compares two objects.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class icomparer interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/icomparer>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      template<class type_t>
      class icomparer interface_ {
      public:
        /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
        /// @param x The first entity to compare.
        /// @param y The second entity to compare.
        /// @return A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
        /// | Value             | Condition            |
        /// |-------------------|----------------------|
        /// | Less than zero    | x is less than y.    |
        /// | Zero              | x equals y.          |
        /// | Greater than zero | x is greater than y. |
        virtual auto compare(const type_t& x, const type_t& y) const -> int32 = 0;
      };
    }
  }
}
