/// @file
/// @brief Contains xtd::collections::generic::icollection <type_t> interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../interface.h"
#include "../../array.h"
#include "../../object.h"
#include "../../size.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Defines methods to manipulate generic collections.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class icollection interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/icollection
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core interfaces
      /// @remarks The xtd::collections::generic::icollection <type_t> interface is the base interface for classes in the xtd::collections::generic namespace.
      /// @remarks The xtd::collections::generic::icollection <type_t> interface extends xtd::collections::generic::ienumerable <type_t>; xtd::collections::generic::idictionary <key_t, value_t> and xtd::collections::generic::ilist <type_t> are more specialized interfaces that extend xtd::collections::generic::icollection <type_t>. A xtd::collections::generic::idictionary <key_t, value_t> implementation is a collection of key/value pairs, like the xtd::collections::generic::dictoinary <key_t, value_t> class. A xtd::collections::generic::ilist <type_t> implementation is a collection of values, and its members can be accessed by index, like the xtd::collections::generic::list <type_t> class.
      /// @remarks If neither the xtd::collections::generic::idictionary <key_t, value_t> interface nor the xtd::collections::generic::ilist <type_t> interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::generic::icollection <type_t> interface instead for more flexibility.
      template<typename type_t>
      class icollection interface_ {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection <type_t>.
        /// @return The number of elements contained in the xtd::collections::generic::icollection <type_t>.
        virtual xtd::size count() const noexcept = 0;

        /// @brief Gets a value indicating whether the xtd::collections::generic::icollection <type_t> is read-only.
        /// @return true if the xtd::collections::generic::icollection <type_t> is read-only; otherwise, false.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::generic::icollection <type_t> interface only supports addition and removal operations. For example, the IsReadOnly property of an array that is cast or converted to an xtd::collections::generic::icollection <type_t> object returns true, even though individual array elements can be modified.
        virtual bool is_read_only() const noexcept = 0;

        /// @brief Gets a value indicating whether access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe).
        /// @return true if access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe); otherwise, false.
        /// @remarks xtd::collections::generic::icollection::sync_root returns an object, which can be used to synchronize access to the xtd::collections::generic::icollection <type_t>.
        /// @remarks Most collection classes in the xtd::collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection.
        /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
        /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   for (auto item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// @endcode
        virtual bool is_synchronized() const noexcept = 0;

        /// @brief Gets an object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
        /// @return An object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
        /// @remarks For collections whose underlying store is not publicly available, the expected implementation is to return the current instance. Note that the pointer to the current instance might not be sufficient for collections that wrap other collections; those should return the underlying collection's `sync_root` property.
        /// @remarks Most collection classes in the xts::.collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection. However, derived classes can provide their own synchronized version of the collection using the xtd::collections::generic::icollection::sync_root property. The synchronizing code must perform operations on the xtd::collections::generic::icollection::sync_root property of the collection, not directly on the collection. This ensures proper operation of collections that are derived from other objects. Specifically, it maintains proper synchronization with other threads that might be simultaneously modifying the collection instance.
        /// @remarks In the absence of a `synchronized` method on a collection, the expected usage for the xtd::collections::generic::icollection::sync_root looks as follows:
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   // Some operation on the collection, which is now thread safe.
        /// }
        /// @encode
        /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
        /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   for (auto item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// @endcode
        virtual const xtd::object& sync_root() const noexcept = 0;
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        virtual void add(const type_t& item) = 0;

        /// @brief Removes all items from the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks xtd::collections::generic::icollection::count must be set to 0, and references to other objects from elements of the collection must be released.
        virtual void clear() = 0;

        /// @brief Determines whether the xtd::collections::generic::icollection <type_t> contains a specific value.
        /// @param item The object to locate in the xtd::collections::generic::icollection <type_t>.
        /// @return true if item is found in the xtd::collections::generic::icollection <type_t>; otherwise, false.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        virtual bool contains(const type_t& item) const noexcept = 0;
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        virtual void copy_to(xtd::array<type_t>& array, xtd::size array_index) const = 0;

        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::icollection <type_t>.
        /// @return true if item was successfully removed from the xtd::collections::generic::icollection <type_t>; otherwise, false. This method also returns false if item is not found in the original xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas, xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual bool remove(const type_t& item) = 0;
        /// @}
      };
    }
  }
}
