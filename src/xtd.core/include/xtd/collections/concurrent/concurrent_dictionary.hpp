/// @file
/// @brief Contains xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iproducer_consumer_collection.hpp"
#include "../generic/dictionary.hpp"
#include "../../threading/lock_guard.hpp"
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
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary<TKey,TValue> class that is empty, has the default concurrency level, has the default initial capacity, and uses the default comparer for the key type.
        concurrent_dictionary() = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::idictionary <key_t, value_t> and uses the default equality comparer for the key type.
        /// @param dictionary The xtd::collections::generic::idictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the default equality comparer; likewise, every key in the source `dictionary` must also be unique according to the default equality comparer.
        /// @remarks The initial capacity of the new xtd::collections::generic::dictionary <key_t, value_t> is large enough to contain all the elements in dictionary.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, xtd::collections::generic::equality_comparer::default_equality_comparer. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in dictionary.
        /// @par Examples
        /// The following code example demonstrates how to use the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor to initialize a xtd::collections::generic::dictionary <key_t, value_t> with sorted content from another dictionary. The code example creates a xtd::collections::generic::sorted_dictionary <key_t, value_t> and populates it with data in random order, then passes the xtd::collections::generic::sorted_dictionary <key_t, value_t> to the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor, creating a xtd::collections::generic::dictionary <key_t, value_t> that is sorted. This is useful if you need to build a sorted dictionary that at some point becomes static; copying the data from a xtd::collections::generic::sorted_dictionary <key_t, value_t> to a xtd::collections::generic::dictionary <key_t, value_t> improves retrieval speed.
        /// @include generic_dictionary_constructor_with_idicationary.cpp
        concurrent_dictionary(const xtd::collections::generic::idictionary<key_t, value_t>& dictionary) {
          lock_guard_(items_) {
            ensure_capacity(dictionary.count());
            for (const auto& item : dictionary)
              items_.add(item);
          }
        }
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
        /// @brief Initializes a new instance of the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> class that contains elements copied from the specified collection.
        concurrent_dictionary(xtd::collections::generic::ienumerable<value_type>&& collection) {
          lock_guard_(items_)
            for (const auto& item : collection)
              items_.add(item);
        }
        /// @brief Initializes a new instance of the xtd::iterable that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param items The iterable whose elements are copied to the new xtd::collections::concurrent::concurrent_dictionary <key_t, value_t>.
        concurrent_dictionary(xtd::iterable auto&& items) {
          for (const auto& item : items)
            items_add(item);
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
          return {};
        }
        
        /// @brief Gets a value that indicates whether the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is empty.
        /// @return `true` if the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> is empty; otherwise, `false`.
        /// @remarks or determining whether the collection contains any items, use of this property is recommended rather than retrieving the number of items from the xtd::collections::concurrent::concurrent_dictionary::count property and comparing it to 0. However, as this collection is intended to be accessed concurrently, it may be the case that another thread will modify the collection after xtd::collections::concurrent::concurrent_dictionary::is_empty returns, thus invalidating the result.
        [[nodiscard]] auto is_empty() const noexcept -> bool {
          lock_guard_(items_)
            return items_.is_empty();
          return {};
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
          return {};
        }
        
        /// @brief Gets a collection that contains the values in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @return A collection that contains the values in the xtd::collections::generic::ictionary<key_t,value_t>.
        /// @remarks The property returns a copy of all the values. It's not kept in sync with xtd::collections::concurrent::concurrent_dictionary<key_t,value_t>.
        auto values() const noexcept -> value_collection override {
          lock_guard_(items_)
            return items_.values();
          return {};
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
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
          return {};
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
        
        /// @brief Copies the elements contained in the xtd::collections::concurrent::concurrent_dictionary <key_t, value_t> to a new array.
        /// @return A new array containing the elements copied from the xtd::collections::concurrent::iproducer_consumer_collection <type_t.
        /// @remarks The method provides a snapshot of the underlying collection. It is possible for other threads to add or remove items immediately after the array is made.
        [[nodiscard]] auto to_array() const -> xtd::array<value_type> {
          lock_guard_(items_)
            return items_.to_array();
          return {};
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override {
          return to_array().to_string();
        }
        
        /// @brief Attempts to get the value associated with the specified key from the xtd::collections::concurrent::concurrent_dictionary <key_t,value_t>.
        /// @param key The key of the value to get.
        /// @return value When this method returns, contains the object from the xtd::collections::concurrent::concurrent_dictionary<key_t,value_t> that has the specified key, or the default value of the type if the operation failed.
        auto try_get_value(const key_t& key, value_t& value) const -> bool override {
          lock_guard_(items_)
            return items_.try_get_value(key, value);
          return {};
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
          return items_.operator [](key);
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
          return items_.operator [](key);
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
          return {};
        }

        auto remove(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> bool override {
          lock_guard_(items_)
            return items_.remove(item);
          return {};
        }
        
        auto remove(const key_t& key) noexcept -> bool override {
          lock_guard_(items_)
            return items_.remove(key);
          return {};
        }
        
        collection_type items_;
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
