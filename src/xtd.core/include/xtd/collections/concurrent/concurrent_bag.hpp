/// @file
/// @brief Contains xtd::collections::concurrent::concurrent_bag <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iproducer_consumer_collection.hpp"
#include "../generic/dictionary.hpp"
#include "../generic/queue.hpp"
#include "../../threading/interlocked.hpp"
#include "../../as.hpp"
#include "../../lock_guard.hpp"
#include "../../new_ptr.hpp"
#include <atomic>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Provides several thread-safe collection classes that should be used in place of the corresponding types in the xtd::collections and xtd::collections::generic namespaces whenever multiple threads are accessing the collection concurrently.<br>
    /// However, access to elements of a collection object through extension methods or through explicit interface implementations are not guaranteed to be thread-safe and may need to be synchronized by the caller.
    namespace concurrent {
      /// @brief Represents a thread-safe, unordered collection of objects.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class concurrent_bag : pulic xtd::object, public xtd::collections::concurrent::iproducer_consumer_collection <type_t>
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
      class concurrent_bag : public xtd::object, public xtd::collections::concurrent::iproducer_consumer_collection<type_t> {
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
        /// @brief Represents the concurrent bag collection type.
        using local_storage_type = collection_type*;
        /// @brief Represents the concurrent bag collection type.
        using storage_type = xtd::collections::generic::dictionary<xtd::intptr, xtd::ptr<collection_type>>;
        /// @}

        /// @name Public Conctructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_bag <type_t> class.
        concurrent_bag() = default;
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        concurrent_bag(std::initializer_list<type_t> items) {
          for (const auto& item : items)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_bag <type_t> class that contains elements copied from the specified collection.
        concurrent_bag(const xtd::collections::generic::ienumerable<value_type>& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection.
        /// @return The number of elements contained in the xtd::collections::generic::icollection.
        [[nodiscard]] auto count() const noexcept -> xtd::usize override {return as<xtd::usize>(count_);}
        
        /// @brief Gets a value indicating whether the xtd::collections::concurrent::concurrent_bag <type_t> is emtpy.
        /// @return `true` if the xtd::collections::concurrent::concurrent_bag <type_t> is empty; otherwise, `false`.
        [[nodiscard]] auto is_empty() const noexcept -> bool {return count_ == 0;}

        /// @brief Gets a value indicating whether the xtd::collections::concurrent::concurrent_bag <type_t> is read-only.
        /// @return `true` if the xtd::collections::concurrent::concurrent_bag <type_t> is read-only; otherwise, `false`.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::concurrent::concurrent_bag <type_t> interface only supports addition and removal operations. For example, the xtd::collections::concurrent::concurrent_bag::is_read_only property of an array that is cast or converted to an xtd::collections::concurrent::concurrent_bag <type_t> object returns `true`, even though individual array elements can be modified.
        [[nodiscard]] auto is_read_only() const noexcept -> bool override {return false;}
        
        /// @brief Gets a value indicating whether access to the xtd::collections::concurrent::concurrent_bag <type_t> is synchronized (thread safe).
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
        /// @brief Adds an item to the xtd::collections::concurrent::concurrent_bag <type_t>.
        /// @param item The object to add to the xtd::collections::concurrent::concurrent_bag <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::concurrent::concurrent_bag <type_t> is read-only.
        auto add(const_reference item) -> void override {if (try_add(item) == false) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::not_supported);}
                
        /// @brief Copies the elements of the xtd::collections::concurrent::concurrent_bag <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::concurrent::concurrent_bag <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::concurrent::concurrent_bag <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        auto copy_to(xtd::array<value_type>& array, xtd::usize array_index) const -> void override {
          if (array_index + count() > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          static thread_local auto items = xtd::array<value_type> {};
          items = to_array();
          for (auto i = xtd::usize {0}; i < count(); ++i)
            array[array_index + i] = items[i];
        }
        
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        /// @todo : use enumerator with a snapshot of the collection instead reference : enumerator {items_, enumerator_mode::snapshot};
        [[nodiscard]] auto get_enumerator() const -> xtd::collections::generic::enumerator<value_type> override {
          static thread_local auto items = xtd::array<value_type> {};
          items = to_array();
          return items.get_enumerator();
        }
                
        /// @brief Copies the elements contained in the xtd::collections::concurrent::concurrent_bag <type_t> to a new array.
        /// @return A new array containing the elements copied from the xtd::collections::concurrent::iproducer_consumer_collection <type_t.
        /// @remarks The method provides a snapshot of the underlying collection. It is possible for other threads to add or remove items immediately after the array is made.
        [[nodiscard]] auto to_array() const -> xtd::array<value_type> override {
          auto result = xtd::collections::generic::list<value_type> {};
          lock_guard_(storages_) {
            for (const auto& [thread_id, storage] : storages_)
              result.add_range(*storage);
          }
          return result.to_array();
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return xtd::string::format("[{}]", xtd::string::join(", ", self_));}
        
        /// @brief Attempts to add an object to the xtd::collections::concurrent::concurrent_bag <type_t>.
        /// @param item The object to add to the xtd::collections::concurrent::iproducer_consumer_collection <type_t>.
        /// @return `true` if the object was added successfully; otherwise, `false`.
        /// @exceprion xtd::argument_exception The item was invalid for this collection.
        auto try_add(const_reference item) -> bool override {
          current_local_storage()->enqueue(item);
          xtd::threading::interlocked::increment(count_);
          return true;
        }
        
        /// @brief Attempts to return an object from the xtd::collections::concurrent::concurrent_bag <type_t> without removing it.
        /// @param item When this method returns, result contains an object from the ConcurrentBag<T> or the default value of T if the operation failed.
        /// @return `true` if an object was returned successfully; otherwise, `false`.
        auto try_peek(reference item) const -> bool {
          if (current_local_storage()->count()) return current_local_storage()->try_peek(item);
          lock_guard_(storages_) {
            for (auto& [thread_id, storage] : storages_) {
              if (storage->count()) return storage->try_peek(item);
            }
          }
          return false;
        }
        
        /// @brief Attempts to remove and return an object from the xtd::collections::concurrent::concurrent <type_t>.
        /// @param item When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
        /// @return `true` if an object was removed and returned successfully; otherwise, `false`.
        auto try_take(reference item) -> bool override {
          if (current_local_storage()->count()) {
            auto result = current_local_storage()->try_dequeue(item);
            if (result) {
              xtd::threading::interlocked::decrement(count_);
              return true;
            }
          }
          lock_guard_(storages_) {
            for (auto& [thread_id, storage] : storages_) {
              if (storage->count()) {
                auto result = storage->try_dequeue(item);
                if (result) {
                  xtd::threading::interlocked::decrement(count_);
                  return true;
                }
              }
            }
          }
          return false;
        }
        
      private:
        auto clear() -> void override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::not_supported);}
        [[nodiscard]] auto contains(const_reference item) const noexcept -> bool override {return false;}
        auto remove(const_reference item) -> bool override {return false;}
        [[nodiscard]] auto sync_root() const noexcept -> const object& override {return storages_;}
        
        auto current_local_storage() const -> local_storage_type {
          if (thread_local_storages_.contains_key(instance_id_)) return thread_local_storages_[instance_id_];
          lock_guard_(storages_) {
            auto id = xtd::threading::thread::current_thread().thread_id();
            if (!storages_.contains_key(id)) storages_.add(id, new_ptr<collection_type>());
            auto storage = storages_[id].get();
            thread_local_storages_[instance_id_] = storage;
            return storage;
          }
          return thread_local_storages_[instance_id_];
        }

        inline static thread_local xtd::collections::generic::dictionary<xtd::uint64, local_storage_type> thread_local_storages_;
        inline static std::atomic<xtd::uint64> next_id_;
        mutable storage_type storages_;
        xtd::int64 count_ = 0;
        xtd::uint64 instance_id_ = ++next_id_;
      };

      /// @cond
      // Deduction guides for xtd::collections::concurrent::concurrent_bag
      // {
      template<typename type_t>
      concurrent_bag(std::initializer_list<type_t>) -> concurrent_bag<type_t>;
      
      template<typename type_t>
      concurrent_bag(const xtd::collections::generic::ienumerable<type_t>&) -> concurrent_bag<type_t>;
      // }
      /// @endcond
    }
  }
}
