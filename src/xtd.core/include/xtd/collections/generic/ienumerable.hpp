/// @file
/// @brief Contains xtd::collections::generic::ienumerable <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "extensions/enumerable.hpp"
#include "extensions/enumerable_iterators.hpp"
#include "../../interface.hpp"
#define __XTD_IENUMERABLE_INTERNAL__
#include "ienumerable_abstract.hpp"
#undef __XTD_IENUMERABLE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Exposes the enumerator, which supports a simple iteration over a collection of a specified type.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class ienumerable interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/ienumerable>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @par Examples
      /// The following example demonstrates how to implement the xtd::collections::generic::ienumerable <type_t> interface. When you implement xtd::collections::generic::ienumerable <type_t>, you must also implement xtd::collections::generic::ienumerator <type_t>.
      /// @include generic_ienumerable.cpp
      /// @remarks xtd::collections::generic::ienumerable <type_t> is the base interface for collections in the xtd::collections::generic namespace such as xtd::collections::generic::list <type_t>, xtd::collections::generic::dictionary <key_t, value_t>, and xtd::collections::generic::stack <type_t> and other generic collections such as xtd::collections::object_model::observable_collection <type_t> and xtd::collections::concurent::concurrent_stack <type_t>. Collections that implement xtd::collections::generic::ienumerable <type_t> can be enumerated by using the `for each` statement.
      /// @remarks For the non-generic version of this interface, see xtd::collections::ienumerable.
      /// @remarks xtd::collections::generic::ienumerable <type_t> contains a single method that you must implement when implementing this interface; xtd::collections::generic::ienumerable::get_enumerator, which returns an xtd::collections::generic::enumerator <type_t> object. The returned xtd::collections::generic::enumerator <type_t> provides the ability to iterate through the collection by exposing a xtd::collections::generic::enumerator::current property.
      template <class type_t>
      class ienumerable interface_, public ienumerable_abstract, public xtd::collections::generic::extensions::enumerable_iterators<type_t, xtd::collections::generic::ienumerable<type_t>>, public xtd::collections::generic::extensions::enumerable<ienumerable<type_t>, type_t > {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the xtd::collections::generic::ienumerable value type.
        using value_type = type_t;
        /// @brief Represents the iterator of xtd::collections::generic::ienumerable value type.
        using iterator = typename xtd::collections::generic::extensions::enumerable_iterators<type_t, xtd::collections::generic::ienumerable<type_t>>::iterator;
        /// @brief Represents the const iterator of xtd::collections::generic::ienumerable value type.
        using const_iterator = typename xtd::collections::generic::extensions::enumerable_iterators<type_t, xtd::collections::generic::ienumerable<type_t>>::const_iterator;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        virtual auto get_enumerator() const -> xtd::collections::generic::enumerator<type_t> = 0;
        /// @}
      };
    }
  }
}
