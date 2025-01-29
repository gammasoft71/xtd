/// @file
/// @brief Contains xtd::collections::generic::iset <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "../../size.hpp"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Provides the base interface for the abstraction of sets.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class iset : public xtd::collections::generic::icollection<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/iset>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @include generic_iset.cpp
      /// @remarks This interface provides methods for implementing sets, which are collections that have unique elements and specific operations. The xtd::collections::generic::hash_set <type_t> and xtd::collections::generic::sorted_set <type_t> collections implement this interface.
      template<class type_t>
      class iset : public icollection<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the iterator of xtd::collections::generic::ienumerable value type.
        using iterator = typename icollection<type_t>::iterator;
        /// @brief Represents the const iterator of xtd::collections::generic::ienumerable value type.
        using const_iterator = typename icollection<type_t>::const_iterator;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an element to the current set and returns a value to indicate if the element was successfully added.
        /// @param item The element to add to the set.
        /// @return `true` if the element is added to the set; `false` if the element is already in the set.
        virtual bool add(const type_t& item) noexcept = 0;
        
        /// @brief Removes all elements in the specified collection from the current set.
        /// @param other The collection of items to remove from the set.
        /// @remarks This method is an O(n) operation, where n is the number of elements in the other parameter.
        virtual void except_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept = 0;

        /// @brief Modifies the current set so that it contains only elements that are also in a specified collection.
        /// @param other The collection to compare to the current set.
        /// @remarks This method ignores any duplicate elements in `other`.
        virtual void intersec_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept = 0;
        
        /// @brief Determines whether the current set is a proper (strict) superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a proper superset of `other`; otherwise, `false`.
        virtual bool is_proper_subset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Determines whether the current set is a proper (strict) superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a proper superset of `other`; otherwise, `false`.
        virtual bool is_proper_superset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Determines whether a set is a subset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a subset of `other`; otherwise, `false`.
        virtual bool is_subset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Determines whether a set is a superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a superset of `other`; otherwise, `false`.
        virtual bool is_superset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Determines whether the current set overlaps with the specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set and `other` share at least one common element; otherwise, `false`.
        virtual bool overlaps(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Determines whether the current set and the specified collection contain the same elements.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is equal to `other`; otherwise, `false`.
        virtual bool set_equals(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept = 0;

        /// @brief Modifies the current set so that it contains only elements that are present either in the current set or in the specified collection, but not both.
        /// @param other The collection to compare to the current set.
        /// @remarks Any duplicate elements in `other` are ignored.
        virtual void symetric_excep_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept = 0;

        /// @brief Modifies the current set so that it contains all elements that are present in the current set, in the specified collection, or in both.
        /// @param other The collection to compare to the current set.
        /// @remarks Any duplicate elements in `other` are ignored.
        virtual void union_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept = 0;
        /// @}
      };
    }
  }
}
