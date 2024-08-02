/// @file
/// @brief Contains xtd::collections::generic::ienumarable <type_t> interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enumerable_iterators.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Supports a simple iteration over a generic collection.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class ienumarable interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/ienumarable
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core interfaces
      template <typename type_t>
      class ienumerable : public interface, public enumerable_iterators<type_t, ienumerable<type_t>> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the iterator of xtd::collections::generic::ienumerable value type.
        using iterator = enumerable_iterators<type_t, ienumerable<type_t>>::iterator;
        /// @brief Represents the const iterator of xtd::collections::generic::ienumerable value type.
        using const_iterator = enumerable_iterators<type_t, ienumerable<type_t>>::const_iterator;
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        virtual enumerator<type_t> get_enumerator() const noexcept = 0;
        /// @}

        /// @cond
        ienumerable() : enumerable_iterators<type_t, ienumerable<type_t>>(this) {}
        /// @endcond
      };
    }
  }
}
