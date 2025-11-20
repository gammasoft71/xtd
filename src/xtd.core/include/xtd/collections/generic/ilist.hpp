/// @file
/// @brief Contains xtd::collections::generic::ilist <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "../../bpos.hpp"
#include "../../epos.hpp"
#include "../../npos.hpp"
#include "../../size.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of objects that can be individually accessed by index.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class ilist : public xtd::collections::generic::icollection<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/ilist>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @par Examples
      /// The following example implements the xtd::collections::generic::ilist <type_t> interface to create a collection of custom `box` objects named `box_collection`. Each `box` has `height`, `length`, and `width` properties, which are used to define equality. Equality can be defined as all dimensions being the same or the volume being the same. The `box` class implements the xtd::iequatable <type_t> interface to define the default equality as the dimensions being the same.
      ///
      /// The `box_collection` class implements the xtd::collections::generic::ibox::index_of method to use the default equality to determine whether a `box` is in the collection. This method is used by the xtd::collections::generic::icollection::add method so that each `box` added to the collection has a unique set of dimensions. The `box_collection` class also provides an overload of the xtd::collections::generic::icollection::contains method that takes a specified xtd::collections::generic::iequality_comparer <type_t> interface, such as `b`ox_same_dimensions` and `box_same_volume` classes in the example.
      ///
      /// This example also implements an xtd::collections::generic::ienumerator <type_t> interface for the `box_collection` class so that the collection can be enumerated.
      /// @include generic_ilist.cpp
      /// @remarks The xtd::collections::generic::ilist <type_t> interface is the base interface for classes in the xtd::collections::generic namespace.
      /// @remarks The xtd::collections::generic::ilist <type_t> interface extends xtd::collections::generic::ienumerable <type_t>; xtd::collections::generic::idictionary <key_t, value_t> and xtd::collections::generic::ilist <type_t> are more specialized interfaces that extend xtd::collections::generic::ilist <type_t>. A xtd::collections::generic::idictionary <key_t, value_t> implementation is a collection of key/value pairs, like the xtd::collections::generic::dictoinary <key_t, value_t> class. A xtd::collections::generic::ilist <type_t> implementation is a collection of values, and its members can be accessed by index, like the xtd::collections::generic::list <type_t> class.
      /// @remarks If neither the xtd::collections::generic::idictionary <key_t, value_t> interface nor the xtd::collections::generic::ilist <type_t> interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::generic::ilist <type_t> interface instead for more flexibility.
      template<class type_t>
      class ilist : public icollection<type_t> {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief Represents a value that is not a valid position in a collection.
        /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::size.
        /// @par Examples
        /// ```cpp
        /// auto items = list {1, 2, 3};
        /// if (items.index_of(42) == items.npos)
        ///   console::write_line("Value not found");
        /// ```
        inline static constexpr xtd::size npos = xtd::npos;
        
        /// @brief Represents the index of the first valid element in a collection.
        /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
        /// @par Examples
        /// ```cpp
        /// auto items = list {10, 20, 30, 40};
        /// console::write_line(items[bpos]); // Prints 10
        /// console::write_line(items[bpos + 1]); // Prints Z0
        /// ```
        static inline constexpr xtd::size bpos = 0;
        
        /// @brief Represents the index of the last valid element in a collection.
        /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
        /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
        /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
        /// @par Examples
        /// ```cpp
        /// auto items = list {10, 20, 30, 40};
        /// console::write_line(items[epos]); // Prints 40
        /// console::write_line(items[epos - 1]); // Prints 30
        /// ```
        /// The wollowing exemple shows the same example with bitwise operator as index.
        /// ```cpp
        /// auto items = list {10, 20, 30, 40};
        /// console::write_line(items[~1_z]); // Prints 40
        /// console::write_line(items[~2_z]); // Prints 30
        /// ```
        static inline constexpr xtd::size epos = npos - 1;
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets a value indicating whether the xtd::collections::generic::ilist <type_t> has a fixed size.
        /// @return `true` if the xtd::collections::generic::ilist <type_t> has a fixed size; otherwise, `false`.
        /// @remarks A collection with a fixed size does not allow the addition or removal of elements after the collection is created, but it allows the modification of existing elements.
        virtual auto is_fixed_size() const noexcept -> bool = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines the index of a specific item in the xtd::collections::generic::ilist <type_t>.
        /// @param item The object to locate in the xtd::collections::generic::ilist <type_t>.
        /// @return The index of item if found in the list; otherwise, xtd::collections::generic::ilist::npos.
        /// @remarks If an object occurs multiple times in the list, the xtd::collections::generic::ilist::index_of method always returns the first instance found.
        virtual auto index_of(const type_t& item) const noexcept -> xtd::size = 0;
        
        /// @brief Inserts an item to the xtd::collections::generic::ilist <type_t> at the specified index.
        /// @param index The zero-based index at which item should be inserted.
        /// @param item The object to insert into the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks If `index` equals the number of items in the xtd::collections::generic::ilist <type_t>, then item is appended to the list.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the insertion point move down to accommodate the new element. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto insert(xtd::size index, const type_t& item) -> void = 0;
        
        /// @brief Removes the xtd::collections::generic::ilist <type_t> item at the specified index.
        /// @param index The zero-based index of the item to remove.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto remove_at(xtd::size index) -> void = 0;
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Gets the element at the specified index.
        /// @param index The zero-based index of the element to get.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual auto operator [](xtd::size index) const -> const type_t& = 0;
        /// @brief Sets the element at the specified index.
        /// @param index The zero-based index of the element to set.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual auto operator [](xtd::size index) -> type_t& = 0;
        /// @}
      };
    }
  }
}
