/// @file
/// @brief Contains xtd::collections::concurrent::concurrent_queue <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iproducer_consumer_collection.hpp"
#include "../generic/queue.hpp"
#include "../../threading/lock_guard.hpp"
#include "../../object.hpp"
#include "../../unused.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Provides several thread-safe collection classes that should be used in place of the corresponding types in the xtd::collections and xtd::collections::generic namespaces whenever multiple threads are accessing the collection concurrently.<br>
    /// However, access to elements of a collection object through extension methods or through explicit interface implementations are not guaranteed to be thread-safe and may need to be synchronized by the caller.
    namespace concurrent {
      /// @brief Represents a thread-safe first in-first out (FIFO) collection.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class concurrent_queue : pulic xtd::object, public xtd::collections::concurrent::iproducer_consumer_collection <type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/concurrent/iproducer_consumer_collection>
      /// ```
      /// @par Namespace
      /// xtd::collections::concurrent
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core concurrent_collections
      template<typename type_t>
      class concurrent_queue : public xtd::object, public xtd::collections::concurrent::iproducer_consumer_collection<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the concurrent bag value type.
        using value_type = typename iproducer_consumer_collection<type_t>::value_type;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the concurrent bag collection type.
        using collection_type = xtd::collections::generic::queue<value_type>;
        /// @}
        
        /// @name Public Conctructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_queue <type_t> class.
        concurrent_queue() = default;
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        concurrent_queue(std::initializer_list<type_t> items) {
          for (const auto& item : items)
            enqueue(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_queue <type_t> class that contains elements copied from the specified collection.
        concurrent_queue(const xtd::collections::generic::ienumerable<value_type>& collection) {
          for (const auto& item : collection)
            enqueue(item);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection.
        /// @return The number of elements contained in the xtd::collections::generic::icollection.
        [[nodiscard]] auto count() const noexcept -> xtd::usize override {
          lock_guard_(items_)
          return items_.count();
          return {};
        }
        
        /// @brief Gets a value indicating whether the xtd::collections::concurrent::concurrent_queue <type_t> is read-only.
        /// @return `true` if the xtd::collections::concurrent::concurrent_queue <type_t> is read-only; otherwise, `false`.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::concurrent::concurrent_queue <type_t> interface only supports addition and removal operations. For example, the xtd::collections::concurrent::concurrent_queue::is_read_only property of an array that is cast or converted to an xtd::collections::concurrent::concurrent_queue <type_t> object returns `true`, even though individual array elements can be modified.
        [[nodiscard]] auto is_read_only() const noexcept -> bool override {return false;}
        
        /// @brief Gets a value indicating whether access to the xtd::collections::concurrent::concurrent_queue <type_t> is synchronized (thread safe).
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
        [[nodiscard]] auto is_synchronized() const noexcept -> bool override {return true;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto clear() -> void override {
          lock_guard_(items_)
          items_.clear();
        }
        
        /// @brief Copies the elements of the xtd::collections::concurrent::concurrent_queue <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::concurrent::concurrent_queue <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::concurrent::concurrent_queue <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        auto copy_to(xtd::array<value_type>& array, xtd::usize array_index) const -> void override {
          lock_guard_(items_)
          items_.copy_to(array, array_index);
        }
        
        /// @brief Adds an item to the end of the xtd::collections::concurrent::concurrent_queue <type_t>.
        /// @param item The object to add to the xtd::collections::concurrent::concurrent_queue <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::concurrent::concurrent_queue <type_t> is read-only.
        virtual auto enqueue(const_reference item) -> void {
          lock_guard_(items_)
          items_.enqueue(item);
        }
        
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        /// @todo : use enumerator with a snapshot of the collection instead reference : enumerator {items_, enumerator_mode::snapshot};
        [[nodiscard]] auto get_enumerator() const -> xtd::collections::generic::enumerator<value_type> override {
          static thread_local auto items = xtd::array<value_type> {};
          items = to_array();
          return items.get_enumerator();
        }
        
        /// @brief Copies the elements contained in the xtd::collections::concurrent::concurrent_queue <type_t> to a new array.
        /// @return A new array containing the elements copied from the xtd::collections::concurrent::iproducer_consumer_collection <type_t.
        /// @remarks The method provides a snapshot of the underlying collection. It is possible for other threads to add or remove items immediately after the array is made.
        [[nodiscard]] auto to_array() const -> xtd::array<value_type> override {
          lock_guard_(items_)
          return items_.to_array();
          return {};
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override {
          return to_array().to_string();
        }
        
        /// @brief Tries to remove and return the object at the beginning of the concurrent queue.
        /// @param item When this method returns, if the operation was successful, result contains the object removed. If no object was available to be removed, the value is unspecified.
        /// @return `true` if an element was removed and returned from the beginning of the xtd::collections::concurrent::concurrent_queue <type_t> successfully; otherwise, `false`.
        virtual auto try_dequeue(reference result) -> bool {
          lock_guard_(items_)
          return items_.try_dequeue(result);
          return false;
        }
        
        /// @brief Tries to return an object from the beginning of the xtd::collections::concurrent::concurrent_queue <type_t> without removing it.
        /// @param result When this method returns, result contains an object from the beginning of the xtd::collections::concurrent::concurrent_queue <type_t> or an unspecified value if the operation failed.
        /// @return `true` if an object was returned successfully; otherwise, `false`.
        auto try_peek(reference result) const -> bool {
          lock_guard_(items_)
          return items_.try_peek(result);
          return false;
        }
        /// @}
        
      private:
        auto add(const_reference item) -> void override {enqueue(item);}
        [[nodiscard]] auto contains(const_reference item) const noexcept -> bool override {return false;}
        auto remove(const_reference item) -> bool override {return false;}
        [[nodiscard]] auto sync_root() const noexcept -> const object& override {return items_;}
        auto try_add(const_reference item) -> bool override {return false;}
        auto try_take(reference item) -> bool override {return try_dequeue(item);}
        
        collection_type items_;
      };
    }
  }
}
