/// @file
/// @brief Contains xtd::collections::generic::ilist <type_t> interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "icollection.h"
#include "../../size_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of objects that can be individually accessed by index.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class ilist : public xtd::collections::generic::icollection<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/ilist
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core interfaces
      /// @remarks The xtd::collections::generic::ilist <type_t> interface is the base interface for classes in the xtd::collections::generic namespace.
      /// @remarks The xtd::collections::generic::ilist <type_t> interface extends xtd::collections::generic::ienumerable <type_t>; xtd::collections::generic::idictionary <key_t, value_t> and xtd::collections::generic::ilist <type_t> are more specialized interfaces that extend xtd::collections::generic::ilist <type_t>. A xtd::collections::generic::idictionary <key_t, value_t> implementation is a collection of key/value pairs, like the xtd::collections::generic::dictoinary <key_t, value_t> class. A xtd::collections::generic::ilist <type_t> implementation is a collection of values, and its members can be accessed by index, like the xtd::collections::generic::list <type_t> class.
      /// @remarks If neither the xtd::collections::generic::idictionary <key_t, value_t> interface nor the xtd::collections::generic::ilist <type_t> interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::generic::ilist <type_t> interface instead for more flexibility.
      template<typename type_t>
      class ilist : public icollection<type_t> {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
        inline static constexpr xtd::size npos = xtd::size_object::max_value;
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Determines the index of a specific item in the xtd::collections::generic::ilist <type_t>.
        /// @param item The object to locate in the xtd::collections::generic::ilist <type_t>.
        /// @return The index of item if found in the list; otherwise, xtd::collections::generic::ilist::npos.
        /// @remarks If an object occurs multiple times in the list, the xtd::collections::generic::ilist::index_of method always returns the first instance found.
        virtual xtd::size index_of(const type_t& item) const noexcept = 0;
        
        /// @brief Inserts an item to the xtd::collections::generic::ilist <type_t> at the specified index.
        /// @param index The zero-based index at which item should be inserted.
        /// @param item The object to insert into the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks If `index` equals the number of items in the xtd::collections::generic::ilist <type_t>, then item is appended to the list.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the insertion point move down to accommodate the new element. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual void insert(xtd::size index, const type_t& item) = 0;

        /// @brief Removes the xtd::collections::generic::ilist <type_t> item at the specified index.
        /// @param index The zero-based index of the item to remove.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual void remove_at(xtd::size index) = 0;
        /// @}

        /// @name Public Operators
        
        /// @{
        /// @brief Gets the element at the specified index.
        /// @param index The zero-based index of the element to get.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual const type_t& operator [](xtd::size index) const = 0;
        /// @brief Sets the element at the specified index.
        /// @param index The zero-based index of the element to set.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual type_t& operator [](xtd::size index) = 0;
        /// @}
      };
    }
  }
}
