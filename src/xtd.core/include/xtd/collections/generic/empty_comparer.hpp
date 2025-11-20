/// @file
/// @brief Contains xtd::collections::generic::empty_comparer <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icomparer.hpp"
#include "../../object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Provides an empty comparer class.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class empty_comparer : public xtd::object, public xtd::collections::generic::icomparer<type_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/empty_comparer>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t>
      class empty_comparer : public object, public icomparer<type_t> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::comparer <type_t> class.
        empty_comparer() = default;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
        /// @param x The first entity to compare.
        /// @param y The second entity to compare.
        /// @return Always 0.
        auto compare(const type_t& x, const type_t& y) const -> int32 override {return 0;}
        /// @}
      };
    }
  }
}
