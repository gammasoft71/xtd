/// @file
/// @brief Contains xtd::collections::concurrent::iproducer_consumer_collection <type_t> interface.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../generic/icollection.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Provides several thread-safe collection classes that should be used in place of the corresponding types in the xtd::collections and xtd::collections::generic namespaces whenever multiple threads are accessing the collection concurrently.<br>
    /// However, access to elements of a collection object through extension methods or through explicit interface implementations are not guaranteed to be thread-safe and may need to be synchronized by the caller.
    namespace concurrent {
      /// @brief Defines methods to manipulate thread-safe collections intended for producer/consumer usage. This interface provides a unified representation for producer/consumer collections so that higher level abstractions such as xtd::collections::concurrent::blocking_collection <type_t> can use the collection as the underlying storage mechanism.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class iproducer_consumer_collection : public xtd::collections::generic::icollection <type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/concurrent/iproducer_consumer_collection>
      /// ```
      /// @par Namespace
      /// xtd::collections::concurrent
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core concurrent_collections interfaces
      template<typename type_t>
      class iproducer_consumer_collection : public xtd::collections::generic::icollection<type_t> {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection.
        /// @return The number of elements contained in the xtd::collections::generic::icollection.
        [[nodiscard]] virtual auto count() const noexcept -> xtd::usize = 0;
        
        /// @brief Gets a value indicating whether access to the xtd::collections::generic::icollection is synchronized (thread safe).
        /// @return `true` if access to the ICollection is synchronized (thread safe); otherwise, `false`.
        /// @remarks xtd::collections::concurrent::iproducer_consumer_collection::sync_root returns an object, which can be used to synchronize access to the xtd::collections::generic::icollection.
        /// @remarks Most collection classes in the xtd::collections namespace also implement a Synchronized method, which provides a synchronized wrapper around the underlying collection.
        /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
        /// @remarks The following code example shows how to lock the collection using the xtd::collections::concurrent::iproducer_consumer_collection::sync_root property during the entire enumeration.
        /// ```cpp
        /// icollection& my_collection = some_collection;
        /// lock(my_collection.sync_root()) {
        ///   for (const auto& item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// ```
        [[nodiscard]] virtual auto is_synchronize() const noexcept -> bool = 0;

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
        ///   for (const auto& item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// @endcode
        [[nodiscard]] virtual auto sync_root() const noexcept -> const object& = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        virtual auto copy_to(xtd::array<type_t>& array, xtd::usize array_index) const -> void = 0;

        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        [[nodiscard]] virtual auto get_enumerator() const -> xtd::collections::generic::enumerator<type_t> = 0;

        /// @brief Copies the elements contained in the xtd::collections::concurrent::iproducer_consumer_collection <type_t> to a new array.
        /// @return A new array containing the elements copied from the xtd::collections::concurrent::iproducer_consumer_collection <type_t.
        /// @remarks The method provides a snapshot of the underlying collection. It is possible for other threads to add or remove items immediately after the array is made.
        [[nodiscard]] virtual auto to_array() const -> xtd::array<type_t> = 0;
        
        /// @brief Attempts to add an object to the xtd::collections::concurrent::iproducer_consumer_collection <type_t>.
        /// @param item The object to add to the xtd::collections::concurrent::iproducer_consumer_collection <type_t>.
        /// @return `true` if the object was added successfully; otherwise, `false`.
        /// @exceprion xtd::argument_exception The item was invalid for this collection.
        virtual auto try_add(const type_t& item) -> bool = 0;
        
        /// @brief Attempts to remove and return an object from the xtd::collections::concurrent::iproducer_consumer_collection <type_t>.
        /// @param item When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
        /// @return `true` if an object was removed and returned successfully; otherwise, `false`.
        virtual auto try_take(type_t& item) -> bool = 0;
        /// @}
      };
    }
  }
}
