/// @file
/// @brief Contains xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iproducer_consumer_collection.hpp"
#include "../generic/dictionary.hpp"
#include "../../threading/lock_guard.hpp"
#include "../../environment.hpp"
#include "../../object.hpp"
#include "../../unused.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, dictionarys, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Provides several thread-safe collection classes that should be used in place of the corresponding types in the xtd::collections and xtd::collections::generic namespaces whenever multiple threads are accessing the collection concurrently.<br>
    /// However, access to elements of a collection object through extension methods or through explicit interface implementations are not guaranteed to be thread-safe and may need to be synchronized by the caller.
    namespace concurrent {
      /// @brief Represents a thread-safe collection of key/value pairs that can be accessed by multiple threads concurrently.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class concurrent_dictionary : pulic xtd::object, public xtd::collections::concurrent::concurrent_dictionary <key_t, value_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/concurrent/concurrent_dictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections::concurrent
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core concurrent_collections
      /// @par Examples
      /// The following example shows how to construct a xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> object.
      /// @include concurrent_dictionary.cpp
      template<typename key_t, typename value_t, typename hasher_t = xtd::collections::generic::helpers::hasher<key_t>, typename equator_t = xtd::collections::generic::helpers::equator<key_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      class concurrent_dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = typename xtd::collections::generic::idictionary<key_t, value_t>::key_type;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = typename xtd::collections::generic::idictionary<key_t, value_t>::mapped_type;
        /// @brief Represents the dictionary value type.
        using value_type = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_type;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the concurrent bag collection type.
        using collection_type = xtd::collections::generic::dictionary<key_t, value_t, hasher_t, equator_t, allocator_t>;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_collection;
        /// @}
        
        /// @name Public Conctructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that is empty, has the default concurrency level, has the default initial capacity, and uses the default comparer for the key type.
        /// @remarks The default concurrency level is equal to the number of CPUs. The higher the concurrency level is, the more concurrent write operations can take place without interference and blocking. Higher concurrency level values also cause operations that require all locks (for example, table resizing, ToArray and Count) to become more expensive. The default capacity (DEFAULT_CAPACITY), which represents the initial number of buckets, is a trade-off between the size of a very small dictionary and the number of resizes when constructing a large dictionary. Also, the capacity should not be divisible by a small prime number. The default capacity is 31.
        concurrent_dictionary() = default;
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable<value_type>, has the default concurrency level, has the default initial capacity, and uses the default comparer for the key type.
        /// @param collection The xtd::collections::generic::ienumerable<value_type> whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        concurrent_dictionary(xtd::collections::generic::ienumerable<value_type>&& collection) {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_.add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::iterable, has the default concurrency level, has the default initial capacity, and uses the default comparer for the key type.
        /// @param collection The xtd::iterable whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        concurrent_dictionary(xtd::iterable auto&& collection) {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that is empty, has the default concurrency level and capacity, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {comparer} {}
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable has the default concurrency level, has the default initial capacity, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param collection The xtd::collections::generic::ienumerable<value_type> whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(xtd::collections::generic::ienumerable<value_type>&& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {comparer} {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_.add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::iterable has the default concurrency level, has the default initial capacity, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param collection The xtd::iterable whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(xtd::iterable auto&& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {comparer} {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that is empty, has the specified concurrency level and capacity, and uses the default comparer for the key type.
        /// @param concurrent_level The estimated number of threads that will update the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> concurrently,.
        /// @param capacity The initial number of elements that the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> can contain.
        concurrent_dictionary(xtd::usize concurrent_level, xtd::usize capacity) : items_ {capacity}, concurrent_level_ {concurrent_level} {}
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param concurrent_level The estimated number of threads that will update the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> concurrently,.
        /// @param collection The xtd::collections::generic::ienumerable<value_type> whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(xtd::usize concurrent_level, xtd::collections::generic::ienumerable<value_type>&& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {comparer} {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_.add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that contains elements copied from the specified xtd::iterable, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param concurrent_level The estimated number of threads that will update the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> concurrently,.
        /// @param collection The xtd::iterable whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(xtd::usize concurrent_level, xtd::iterable auto&& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {comparer} {
          lock_guard_(items_)
          for (const auto& item : collection)
            items_add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> class that is empty, has the specified concurrency level and capacity, and uses the specified xtd::collections::generic::iequality_comparer<key_type>.
        /// @param concurrent_level The estimated number of threads that will update the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> concurrently,.
        /// @param capacity The initial number of elements that the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> can contain.
        /// @param comparer The equality comparison implementation to use when comparing keys.
        concurrent_dictionary(xtd::usize concurrent_level, xtd::usize capacity, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : items_ {capacity, comparer}, concurrent_level_ {concurrent_level} {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// concurrent_dictionary(init.begin(), init.end())
        /// ```
        concurrent_dictionary(std::initializer_list<std::pair<key_t, value_t>> items) {
          lock_guard_(items_) {
            items_.ensure_capacity(items.size());
            for (const auto& [key, value] : items)
              items_.add(key, value);
          }
        }
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        concurrent_dictionary(std::initializer_list<value_type> items) {
          lock_guard_(items_) {
            items_.ensure_capacity(items.size());
            for (const auto& item : items)
              items_.add(item);
          }
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the xtd::collections::generic::iequality_comparer <type_t> that is used to determine equality of keys for the dictionary.
        /// @return The xtd::collections::generic::iequality_comparer <type_t> generic interface implementation that is used to determine equality of keys for the current xtd::collections::generic::dictionary <key_t, value_t> and to provide hash values for the keys.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify one, the default generic equality comparer td::collections::generic::equality_comparer::default_equality_comparer is used.
        [[nodiscard]] auto comparer() const noexcept -> const xtd::collections::generic::iequality_comparer<key_t>& {
          return items_.comparer();
        }

        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection.
        /// @return The number of elements contained in the xtd::collections::generic::icollection.
        [[nodiscard]] auto count() const noexcept -> xtd::usize override {
          lock_guard_(items_)
            return items_.count();
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Gets a value that indicates whether the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is empty.
        /// @return `true` if the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is empty; otherwise, `false`.
        /// @remarks or determining whether the collection contains any items, use of this property is recommended rather than retrieving the number of items from the xtd::collections::concurrent::concurrent_dictionary::count property and comparing it to 0. However, as this collection is intended to be accessed concurrently, it may be the case that another thread will modify the collection after xtd::collections::concurrent::concurrent_dictionary::is_empty returns, thus invalidating the result.
        [[nodiscard]] auto is_empty() const noexcept -> bool {
          lock_guard_(items_)
            return items_.is_empty();
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Gets a value indicating whether the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is read-only.
        /// @return `true` if the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is read-only; otherwise, `false`.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> interface only supports addition and removal operations. For example, the xtd::collections::concurrent::concurrent_dictionary::is_read_only property of an array that is cast or converted to an xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> object returns `true`, even though individual array elements can be modified.
        [[nodiscard]] auto is_read_only() const noexcept -> bool override {return false;}
        
        /// @brief Gets a value indicating whether access to the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is synchronized (thread safe).
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
        
        /// @brief Gets a collection containing the keys in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @return A collection of keys in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @remarks The property returns a copy of all the keys. It's not kept in sync with xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        auto keys() const noexcept -> key_collection override {
          lock_guard_(items_)
            return items_.keys();
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Gets a collection that contains the values in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @return A collection that contains the values in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @remarks The property returns a copy of all the values. It's not kept in sync with xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        auto values() const noexcept -> value_collection override {
          lock_guard_(items_)
            return items_.values();
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Uses the specified functions to add a key/value pair to the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> if the key does not already exist, or to update a key/value pair in the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> if the key already exists.
        /// @param key The key to be added or whose value should be updated.
        /// @param add_value_factory
        /// @param update_value_factory
        /// @return The new value for the key. This will be either be the result of `add_value_factory` (if the key was absent) or the result of `update_value_factory` (if the key was present).
        /// @remarks If you call xtd::collections::concurrent::concurrent_dictionary::add_or_update simultaneously on different threads, addValueFactory may be called multiple times, but its key/value pair might not be added to the dictionary for every call.
        auto add_or_update(const key_t& key, xtd::callable<value_t, key_t> auto&& add_value_factory, xtd::callable<value_t, key_t, value_t> auto&& update_value_factory) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value_factory(key));
            else items_[key] = update_value_factory(key, items_[key]);
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Adds a key/value pair to the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> if the key does not already exist, or updates a key/value pair in the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> by using the specified function if the key already exists.
        /// @param key The key to be added or whose value should be updated.
        /// @param value The value to be added for an absent key.
        /// @param update_value_factory The function used to generate a new value for an existing key based on the key's existing value.
        /// @return The new value for the key. This will be either be `add_value` (if the key was absent) or the result of `update_value_factory` (if the key was present).
        auto add_or_update(const key_t& key, const value_t& add_value, xtd::callable<value_t, key_t, value_t> auto&& update_value_factory) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value);
            else items_[key] = update_value_factory(key, items_[key]);
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Uses the specified functions and argument to add a key/value pair to the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> if the key does not already exist, or to update a key/value pair in the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> if the key already exists.
        /// @param key The key to be added or whose value should be updated.
        /// @param add_value_factory The function used to generate a value for an absent key.
        /// @param update_value_factory The function used to generate a new value for an existing key based on the key's existing value.
        /// @param factory_argument An argument to pass into `add_value_factory` and `update_value_factory`.
        /// @return The new value for the key. This will be either be the result of `add_value_factory` (if the key was absent) or the result of `update_value_factory` (if the key was present).
        /// @remarks If you call xtd::collections::concurrent::concurrent_dictionary::add_or_update simultaneously on different threads, addValueFactory may be called multiple times, but its key/value pair might not be added to the dictionary for every call.
        template<typename arg_t>
        auto add_or_update(const key_t& key, xtd::callable<value_t, key_t, arg_t> auto&& add_value_factory, xtd::callable<value_t, key_t, value_t, arg_t> auto&& update_value_factory, arg_t&& factory_argument) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value_factory(key, factory_argument));
            else items_[key] = update_value_factory(key, items_[key], factory_argument);
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }

        /// @brief Removes all keys and values from the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        auto clear() -> void override {
          lock_guard_(items_)
            items_.clear();
        }
        
        /// @brief Determines whether the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> contains the specified key.
        /// @param key The key to locate in the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @return `true` if the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> contains an element with the specified key; otherwise, `false`.
        auto contains_key(const key_t& key) const noexcept -> bool override {
          lock_guard_(items_)
            return items_.contains_key(key);
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Copies the elements of the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::concurrent::concurrent_dictionary <key_t, value_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is greater than the available space from `array_index` to the end of the destination `array`.
        auto copy_to(xtd::array<value_type>& array, xtd::usize array_index) const -> void override {
          lock_guard_(items_)
            items_.copy_to(array, array_index);
        }
        
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        /// @todo : use enumerator with a snapshot of the collection instead reference : enumerator {items_, enumerator_mode::snapshot};
        [[nodiscard]] auto get_enumerator() const -> xtd::collections::generic::enumerator<value_type> override {
          static thread_local auto items = xtd::array<value_type> {};
          items = to_array();
          return items.get_enumerator();
        }
        
        /// @brief Adds a key/value pair to the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> by using the specified function if the key does not already exist. Returns the new value, or the existing value if the key exists.
        /// @param key The key of the element to add.
        /// @param ad_value_factory The function used to generate a value for the key.
        /// @return The value for the key. This will be either the existing value for the key if the key is already in the dictionary, or the new value if the key was not in the dictionary.
        [[nodiscard]] auto get_or_add(const key_t& key, xtd::callable<value_t, key_t> auto&& add_value_factory) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value_factory(key));
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Adds a key/value pair to the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> if the key does not already exist. Returns the new value, or the existing value if the key exists.
        /// @param key  The key of the element to add.
        /// @param add_value The value to be added, if the key does not already exist.
        /// @return The value for the key. This will be either the existing value for the key if the key is already in the dictionary, or the new value if the key was not in the dictionary.
        [[nodiscard]] auto get_or_add(const key_t& key, const value_t& add_value) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value);
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Adds a key/value pair to the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> by using the specified function and an argument if the key does not already exist, or returns the existing value if the key exists.
        /// @param key The key of the element to add.
        /// @param ad_value_factory The function used to generate a value for the key.
        /// @param factory_argument An argument value to pass into valueFactory.
        /// @return The value for the key. This will be either the existing value for the key if the key is already in the dictionary, or the new value if the key was not in the dictionary.
        template<typename arg_t>
        [[nodiscard]] auto get_or_add(const key_t& key, xtd::callable<value_t, key_t, arg_t> auto&& add_value_factory, arg_t&& factory_argument) -> const value_t& {
          lock_guard_(items_) {
            if (!items_.contains_key(key)) items_.add(key, add_value_factory(key, factory_argument));
            return items_[key];
          }
          xtd::environment::fail_fast("This line is never executed.");
        }

        /// @brief Copies the elements contained in the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> to a new array.
        /// @return A new array containing the elements copied from the xtd::collections::concurrent::iproducer_consumer_collection <type_t.
        /// @remarks The method provides a snapshot of the underlying collection. It is possible for other threads to add or remove items immediately after the array is made.
        [[nodiscard]] auto to_array() const -> xtd::array<value_type> {
          lock_guard_(items_)
            return items_.to_array();
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override {
          return to_array().to_string();
        }
        
        /// @brief Attempts to add the specified key and value to the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        /// @param key The key of the element to add.
        /// @param value The value of the element to add. The value can be null for reference types.
        /// @return `true` if the key/value pair was added to the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> successfully; `false` if the key already exists.
        auto try_add(const key_t& key, const value_t& value) -> bool {
          lock_guard_(items_) {
            if (items_.contains_key(key)) return false;
            items_.add(key, value);
            return true;
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Attempts to get the value associated with the specified key from the xtd::collections::concurrent::concurrent_dictionary <key_t,value_t>.
        /// @param key The key of the value to get.
        /// @return value When this method returns, contains the object from the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> that has the specified key, or the default value of the type if the operation failed.
        auto try_get_value(const key_t& key, value_t& value) const -> bool override {
          lock_guard_(items_)
            return items_.try_get_value(key, value);
          xtd::environment::fail_fast("This line is never executed.");
        }

        /// @brief Attempts to remove and return the value that has the specified key from the xtd::collections::concurrent::concurrent_dictionary <key_t,value_t>.
        /// @param key The key of the element to remove and return.
        /// @param value When this method returns, contains the object removed from the xtd::collections::concurrent::concurrent_dictionary <key_t,value_t>, or the default value of the `value_t` type if key does not exist.
        /// @return `true` if the object was removed successfully; otherwise, `false`.
        auto try_remove(const key_t& key, value_t& value) -> bool {
          lock_guard_(items_) {
            if (!items_.try_get_value(key, value)) return false;
            return items_.remove(key);
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Removes a key and value from the dictionary.
        /// @pram item The xtd::collections::generic::key_value_pair<key_t,value_t> representing the key and value to remove.
        /// @return `true` if the key and value represented by item are successfully found and removed; otherwise, `false`.
        /// @remarks Both the specifed key and value must match the entry in the dictionary for it to be removed.
        /// @remarks The key is compared using the dictionary's comparer (or the default comparer for `key_t` if no comparer was provided to the dictionary when it was constructed). The value is compared using the default comparer for `value_t`.
        auto try_remove(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> bool {
          lock_guard_(items_) {
            if (!items_.contains(item)) return false;
            return items_.remove(item);
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        /// @brief Updates the value associated with key to `new_value` if the existing value with `key` is equal to `comparison_value`.
        /// @param key The key of the value that is compared with `comparison_value` and possibly replaced.
        /// @param new_value The value that replaces the value of the element that has the specified key if the comparison results in equality.
        /// @param comparison_value The value that is compared with the value of the element that has the specified `key`.
        /// @return `true` if the value with key was equal to `comparison_value` and was replaced with `new_value`; otherwise, `false`.
        auto try_update(const key_t& key, const value_t& new_value, const value_t& comparison_value) -> bool {
          lock_guard_(items_) {
            if (!items_.contains({key, comparison_value})) return false;
            items_[key] = new_value;
            return true;
          }
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        auto operator [](const key_t& key) const -> const value_t& override {
          lock_guard_(items_)
            return items_.operator [](key);
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        auto operator [](const key_t& key) -> value_t& override {
          lock_guard_(items_)
            return items_.operator [](key);
          xtd::environment::fail_fast("This line is never executed.");
        }
        /// @}
        
      private:
        auto sync_root() const noexcept -> const xtd::object& override {return xtd::as<xtd::collections::generic::idictionary<key_t, value_t>>(items_).sync_root();}
        
        auto add(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> void override {
          lock_guard_(items_)
            items_.add(item);
        }
        auto add(const key_t& key, const value_t& value) -> void override {
          lock_guard_(items_)
            items_.add(key, value);
        }
        
        auto contains(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) const noexcept -> bool override {
          lock_guard_(items_)
            return items_.contains(item);
          xtd::environment::fail_fast("This line is never executed.");
        }

        auto remove(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> bool override {
          lock_guard_(items_)
            return items_.remove(item);
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        auto remove(const key_t& key) noexcept -> bool override {
          lock_guard_(items_)
            return items_.remove(key);
          xtd::environment::fail_fast("This line is never executed.");
        }
        
        collection_type items_;
        xtd::usize concurrent_level_ = xtd::environment::processor_count();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::concurrent::concurrent_dictionary
      // {
      template<typename key_t, typename value_t >
      concurrent_dictionary(xtd::collections::generic::idictionary<key_t, value_t>) -> concurrent_dictionary<key_t, value_t>;
      
      template<typename key_t, typename value_t >
      concurrent_dictionary(xtd::collections::generic::ienumerable<xtd::collections::generic::key_value_pair<key_t, value_t>>) -> concurrent_dictionary<key_t, value_t>;
      
      template<xtd::iterable iterable_t>
      concurrent_dictionary(iterable_t&&) -> concurrent_dictionary<std::remove_const_t<std::tuple_element_t<0, xtd::iterable_value_type<iterable_t>>>, std::remove_const_t<std::tuple_element_t<1, xtd::iterable_value_type<iterable_t>>>>;
      
      template<typename key_t, typename value_t >
      concurrent_dictionary(std::initializer_list<xtd::collections::generic::key_value_pair<key_t, value_t>>) -> concurrent_dictionary<key_t, value_t>;
      
      template<typename key_t, typename value_t >
      concurrent_dictionary(std::initializer_list<std::pair<key_t, value_t>>) -> concurrent_dictionary<key_t, value_t>;
      
      template<typename input_iterator_t >
      concurrent_dictionary(input_iterator_t, input_iterator_t) -> concurrent_dictionary<xtd::collections::generic::helpers::iterator_key_t<input_iterator_t>, xtd::collections::generic::helpers::iterator_mapped_t<input_iterator_t>>;
      // }
      /// @endcond
    }
  }
}
