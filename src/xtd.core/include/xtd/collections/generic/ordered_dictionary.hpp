/// @file
/// @brief Contains xtd::collections::generic::ordered_dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "dictionary.hpp"
#include "list.hpp"
#include "key_not_found_exception.hpp"
#include "helpers/iterator.hpp"
#include "../../threading/lock.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of key/value pairs that are accessible by the key or index.
      /// @par Definition
      /// ```cpp
      /// template<class key_t, class value_t, class allocator_t = xtd::collections::generic::helpers::allocator <std::pair<const key_t, value_t>>>
      /// class ordered_dictionary : public xtd::object, public xtd::collections::generic::idictionary <key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/ordered_dictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class key_t, class value_t, class allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      class ordered_dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = typename xtd::collections::generic::idictionary<key_t, value_t>::key_type;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = typename xtd::collections::generic::idictionary<key_t, value_t>::mapped_type;
        /// @brief Represents the dictionary value type.
        using value_type = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_type;
        /// @brief Represents the dictionary size type.
        using size_type = xtd::size;
        /// @brief Represents the dictionary base value type.
        using base_value_type = xtd::collections::generic::key_value_pair<key_type, mapped_type>;
        /// @brief Represents the dictionary base type.
        using base_type = xtd::collections::generic::dictionary<key_type, mapped_type>;
        /// @brief Represents the dictionary base type.
        using list_type = xtd::collections::generic::list<key_type>;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_collection;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary class.
        /// @par Examples
        /// The following code example demonstrates the creation and population of an xtd::collections::generic::ordered_dictionary collection. This code is part of a larger code example that can be viewed at xtd::collections::generic::ordered_dictionary.
        /// ```cpp
        /// // Creates and initializes a ordered_dictionary.
        /// auto my_ordered_dictionary = ordered_dictionary<string, string> {};
        /// my_ordered_dictionary.add("test_key1", "test_value1");
        /// my_ordered_dictionary.add("test_key2", "test_value2");
        /// my_ordered_dictionary.add("key_to_delete", "value_to_delete");
        /// my_ordered_dictionary.add("test_key3", "test_value3");
        ///
        /// // Display the contents using the key and value collections
        /// display_contents(my_ordered_dictionary.keys(), my_ordered_dictionary.values(), my_ordered_dictionary.count());
        /// ```
        /// @remarks The comparer determines whether two keys are equal. Every key in a xtd::collections::generic::ordered_dictionary collection must be unique. The default comparer is the key's implementation of '==' operator.
        ordered_dictionary() noexcept = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::idictionary <key_t, value_t> and uses the default equality comparer for the key type.
        /// @param dictionary The xtd::collections::generic::idictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Every key in a xtd::collections::generic::ordered_dictionary <key_t, value_t> must be unique according to the default equality comparer; likewise, every key in the source `dictionary` must also be unique according to the default equality comparer.
        /// @remarks The initial capacity of the new xtd::collections::generic::ordered_dictionary <key_t, value_t> is large enough to contain all the elements in dictionary.
        /// @remarks xtd::collections::generic::ordered_dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, xtd::collections::generic::equality_comparer::default_equality_comparer. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in dictionary.
        ordered_dictionary(const xtd::collections::generic::idictionary<key_t, value_t>& dictionary) {
          data_->items = dictionary;
          data_->keys.capacity(dictionary.count());
          for (const auto& item : dictionary)
            data_->keys.add(item.first);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::idictionary <key_t, value_t> and uses the default equality comparer for the key type, and uses the specified xtd::collections::generic::iequality_comparer <key_type>.
        /// @param dictionary The xtd::collections::generic::idictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <key_type> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Every key in a xtd::collections::generic::ordered_dictionary <key_t, value_t> must be unique according to the default equality comparer; likewise, every key in the source `dictionary` must also be unique according to the default equality comparer.
        /// @remarks The initial capacity of the new xtd::collections::generic::ordered_dictionary <key_t, value_t> is large enough to contain all the elements in dictionary.
        /// @remarks xtd::collections::generic::ordered_dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, xtd::collections::generic::equality_comparer::default_equality_comparer. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in dictionary.
        ordered_dictionary(const xtd::collections::generic::idictionary<key_t, value_t>& dictionary, const xtd::collections::generic::iequality_comparer<key_type>& comparer) {
          data_->items = base_type(dictionary, comparer);
          data_->keys.capacity(dictionary.count());
          for (const auto& item : dictionary)
            data_->keys.add(item.first);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::ordered_dictionary <key_t, value_t>
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        ordered_dictionary(const xtd::collections::generic::ienumerable < value_type >& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t>, and uses the specified xtd::collections::generic::iequality_comparer <key_type>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::ordered_dictionary <key_t, value_t>
        /// @param comparer The xtd::collections::generic::iequality_comparer <key_type> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        ordered_dictionary(const xtd::collections::generic::ienumerable < value_type >& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) {
          data_->items = base_type(comparer);
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that is empty, has the specified initial capacit.
        /// @param capacity The initial number of elements that the xtd::collections::generic::ordered_dictionary <key_t, value_t> can contain.
        /// @remarks Every key in a xtd::collections::generic::ordered_dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::ordered_dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::ordered_dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::ordered_dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::ordered_dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type TKey implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks xtd::collections::generic::ordered_dictionary::capacity and xtd::collections::generic::ordered_dictionary::bucket_count are equivalent properties.
        ordered_dictionary(size_t capacity) {
          data_->keys.capacity(capacity);
          data_->items.ensure_capacity(capacity);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that is empty, has the specified initial capacit, and uses the specified xtd::collections::generic::iequality_comparer <key_type>.
        /// @param capacity The initial number of elements that the xtd::collections::generic::ordered_dictionary <key_t, value_t> can contain.
        /// @param comparer The xtd::collections::generic::iequality_comparer <key_type> implementation to use when comparing keys.
        /// @remarks Every key in a xtd::collections::generic::ordered_dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::ordered_dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::ordered_dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::ordered_dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::ordered_dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type TKey implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks xtd::collections::generic::ordered_dictionary::capacity and xtd::collections::generic::ordered_dictionary::bucket_count are equivalent properties.
        ordered_dictionary(size_t capacity, const xtd::collections::generic::iequality_comparer<key_type>& comparer) {
          data_->items = base_type(capacity, comparer);
          data_->keys.capacity(capacity);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class that is empty, and uses the specified xtd::collections::generic::iequality_comparer <key_type>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <key_type> implementation to use when comparing keys.
        /// @remarks Every key in a xtd::collections::generic::ordered_dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::ordered_dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::ordered_dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::ordered_dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::ordered_dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type TKey implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks xtd::collections::generic::ordered_dictionary::capacity and xtd::collections::generic::ordered_dictionary::bucket_count are equivalent properties.
        ordered_dictionary(const xtd::collections::generic::iequality_comparer<key_type>& comparer) {
          data_->items = base_type(comparer);
        }
        /// @brief Initializes instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class from a variety of data sources.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::ordered_dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        /// @remarks xtd::collections::generic::ordered_dictionary::bucket_count and xtd::collections::generic::ordered_dictionary::capacity are equivalent properties.
        template < class input_iterator_t >
        explicit ordered_dictionary(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @brief Initializes instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        ordered_dictionary(const ordered_dictionary & other) noexcept : data_(xtd::new_ptr<dictionary_data>(other.data_->items, other.data_->version)) {}
        /// @brief Initializes instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        ordered_dictionary(ordered_dictionary&& other) noexcept = default;
        ordered_dictionary(std::initializer_list<base_value_type> init) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::ordered_dictionary <key_t, value_t> class from a variety of data sources.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        template < class init_key_t, class init_value_t >
        explicit ordered_dictionary(std::initializer_list<key_value_pair<init_key_t, init_value_t>> init) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::ordered_dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::ordered_dictionary <key_t, value_t> can store. The xtd::collections::generic::ordered_dictionary::count property is the number of elements that are actually in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::ordered_dictionary::count. If xtd::collections::generic::ordered_dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto count() const noexcept -> size_type override {return data_->items.count();}
        
        /// @brief Gets the xtd::collections::generic::iequality_comparer <type_t> that is used to determine equality of keys for the dictionary.
        /// @return The xtd::collections::generic::iequality_comparer <type_t> generic interface implementation that is used to determine equality of keys for the current xtd::collections::generic::dictionary <key_t, value_t> and to provide hash values for the keys.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify one, the default generic equality comparer td::collections::generic::equality_comparer::default_equality_comparer is used.
        auto comparer() const noexcept -> const iequality_comparer < key_t >& {
          return data_->items.comparer();
        }
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual auto items() const noexcept -> const base_type& {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual auto items() noexcept -> base_type& {return data_->items;}
        
        /// @brief Gets a collection containing the keys in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::ordered_dictionary::key_collection containing the keys in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks The order of the keys in the xtd::collections::generic::ordered_dictionary::key_collection is unspecified, but it is the same order as the associated values in the xtd::collections::generic::ordered_dictionary::value_collection returned by the xtd::collections::generic::ordered_dictionary::values property.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto keys() const noexcept -> key_collection override {
          auto keys = key_collection {};
          for (const auto& key : data_->keys)
            keys.add(key);
          return keys;
        }
        
        /// @brief Gets a collection containing the values in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::ordered_dictionary::value_collection containing the values in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks The order of the values in the xtd::collections::generic::ordered_dictionary::value_collection is unspecified, but it is the same order as the associated keys in the xtd::collections::generic::ordered_dictionary::key_collection returned by the xtd::collections::generic::ordered_dictionary::keys property.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto values() const noexcept -> value_collection override {
          auto values = value_collection {};
          for (const auto& key : data_->keys)
            values.add(data_->items[key]);
          return values;
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an element with the provided key and value to the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @param key The object to use as the key of the element to add.
        /// @param value The object to use as the value of the element to add.
        /// @exception xtd::argument_exception An element with the same key already exists in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::ordered_dictionary::add method does not modify existing elements.
        auto add(const key_t & key, const value_t& value) -> void override {
          insert(count(), key, value);
        }
        
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        auto add(const value_type & item) -> void override {
          insert(count(), item.key(), item.value());
        }
        
        /// @brief Removes all keys and values from the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks The xtd::collections::generic::ordered_dictionary::count property is set to 0, and references to other objects from elements of the collection are also released. The capacity remains unchanged.
        auto clear() noexcept -> void override {
          lock_(data_->sync_op) {
            data_->keys.clear();
            data_->items.clear();
          }
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains an element with the specified `item` ; otherwise, `false`.
        auto contains(const value_type & item) const noexcept -> bool override {
          return data_->items.contains(item);
        }
        
        /// @brief Determines whether the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains the specified key.
        /// @param The key to locate in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method approaches an O(1) operation.
        auto contains_key(const key_t & key) const noexcept -> bool override {
          return data_->items.contains_key(key);
        }
        
        /// @brief Determines whether the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains the specified value.
        /// @param The value to locate in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method performs a linear search; therefore, the average execution time is proportional to xtd::collections::generic::ordered_dictionary::count. That is, this method is an O(n) operation, where n is xtd::collections::generic::ordered_dictionary::count.
        auto contains_value(const value_t& value) const noexcept -> bool {
          return data_->items.contains_value(value);
        }
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        auto copy_to(xtd::array<value_type>& array, xtd::size array_index) const -> void override {
          if (array_index + count() > array.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          for (const auto& item : self_)
            array[array_index++] = item;
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return A xtd::collections::enumerator structure for the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        auto get_enumerator() const noexcept -> xtd::collections::generic::enumerator<value_type> override {
          struct ordered_dictionary_enumerator : public ienumerator<value_type> {
            explicit ordered_dictionary_enumerator(const ordered_dictionary & items, xtd::size version) : items_(items), version_(version) {}
            
            auto current() const -> const value_type& override {
              if (index_ >= items_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return (value_ = value_type {key_t {items_.data_->keys[index_]}, value_t {items_.data_->items[items_.data_->keys[index_]]}});
            }
            
            auto move_next() -> bool override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return ++index_ < items_.data_->keys.count();
            }
            
            auto reset() -> void override {
              version_ = items_.data_->version;
              index_ = xtd::npos;
            }
            
          private:
            size_type index_ = xtd::npos;
            const ordered_dictionary& items_;
            mutable value_type value_;
            size_type version_ = 0;
          };
          
          return {new_ptr<ordered_dictionary_enumerator>(self_, data_->version)};
        }
        
        /// @brief Inserts a new entry into the xtd::collections::generic::ordered_dictionary collection with the specified key at the specified index.
        /// @param index The zero-based index at which the element should be inserted.
        /// @param key The key of the entry to add.
        /// @exception xtd::argument_out_of_range index is out of range.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        auto insert(xtd::size index, const key_t & key) -> void {insert(index, key, value_t {});}
        
        /// @brief Inserts a new entry into the xtd::collections::generic::ordered_dictionary collection with the specified key and value at the specified index.
        /// @param index The zero-based index at which the element should be inserted.
        /// @param key The key of the entry to add.
        /// @param value The value of the entry to add.
        /// @exception xtd::argument_out_of_range index is out of range.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        auto insert(xtd::size index, const key_t & key, const value_t& value) -> void {
          if (contains_key(key)) return xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          lock_(data_->sync_op) {
            data_->items.add(key, value);
            data_->keys.insert(index, key);
          }
          ++data_->version;
        }
        
        /// @brief Removes the value with the specified key from the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @param key The key of the element to remove.
        /// @return `true` if the element is successfully found and removed; otherwise, `false`. This method returns `false` if key is not found in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @remarks If the xtd::collections::generic::ordered_dictionary <key_t, value_t> does not contain an element with the specified key, the xtd::collections::generic::ordered_dictionary <key_t, value_t> remains unchanged. No exception is thrown.
        auto remove(const key_t & key) noexcept -> bool override {
          if (!contains_key(key)) return false;
          lock_(data_->sync_op) {
            remove_at(get_index(key));
          }
          ++data_->version;
          return true;
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @param item The object to remove from the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item value was not found in the xtd::collections::generic::ordered_dictionary <key_t, value_t>.
        auto remove(const value_type & item) noexcept -> bool override {
          lock_(data_->sync_op) {
            auto result = data_->items.remove(item.first);
            if (!result) return false;
            data_->keys.remove_at(get_index(item.first));
          }
          ++data_->version;
          return true;
        }
        
        /// @brief Removes the entry at the specified index from the OrderedDictionary collection.
        /// @param index The zero-based index of the entry to remove.
        /// @exception xtd::argument_out_of_range index is out of range.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks The entries that follow the removed entry move up to occupy the vacated spot and the indexes of the entries that move are also updated.
        auto remove_at(xtd::size index) -> void {
          lock_(data_->sync_op) {
            data_->items.remove(data_->keys[index]);
            data_->keys.remove_at(index);
          }
          ++data_->version;
        }
        
        /// @brief Gets a string that represents the current object.
        /// @return A string that represents the current object.
        auto to_string() const noexcept -> xtd::string override {return xtd::string::format("{{{}}}", xtd::string::join(", ", self_));}
        
        /// @brief Gets the value associated with the specified key.
        /// @param key The key of the value to get.
        /// @param value When this method returns, contains the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter.
        /// @return `true` if the xtd::collections::generic::ordered_dictionary <key_t, value_t> contains an element with the specified key; otherwise, `false`.
        auto try_get_value(const key_t & key, value_t& value) const -> bool override {
          return data_->items.try_get_value(key, value);
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(ordered_dictionary&& other) noexcept -> ordered_dictionary& = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(const ordered_dictionary & other) noexcept -> ordered_dictionary& {
          *data_ = *other.data_;
          return self_;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        auto operator =(std::initializer_list<base_value_type> ilist) -> ordered_dictionary& {
          clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
          return self_;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        template < class init_key_t, class init_value_t >
        auto operator =(std::initializer_list<key_value_pair<init_key_t, init_value_t>> ilist) -> ordered_dictionary& {
          clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
          return self_;
        }
        
        /// @brief Gets the value at the specified index.
        /// @param index The zero-based index of the value to get or set.
        /// @return The value of the item at the specified index.
        /// @exception xtd::argument_out_of_range index is out of range.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks This property allows you to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        auto operator()(xtd::size index) const -> const value_t& {return operator [](data_->keys[index]);}
        /// @brief Sets the value at the specified index.
        /// @param index The zero-based index of the value to get or set.
        /// @return The value of the item at the specified index.
        /// @exception xtd::argument_out_of_range index is out of range.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks This property allows you to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        auto operator()(xtd::size index) -> value_t& {return operator [](data_->keys[index]);}
        
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::ordered_dictionary::add method does not modify existing elements.
        auto operator [](const key_t & key) const -> const value_t& override {return data_->items[key];}
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::ordered_dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::ordered_dictionary::add method does not modify existing elements.
        auto operator [](const key_t & key) -> value_t& override {
          auto iterator = data_->items.items().find(key);
          if (iterator != data_->items.items().end())
            return iterator->second;
          data_->keys.add(key);
          return data_->items[key];
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type& () const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type& () noexcept {return data_->items;}
        /// @}
        
      private:
        auto get_index(const key_t & key) const noexcept -> xtd::size {
          auto index = xtd::size {0};
          for (const auto& item_key : data_->keys) {
            if (item_key == key) return index;
            ++index;
          }
          return xtd::npos;
        }
        
        auto is_read_only() const noexcept -> bool override {return false;}
        auto is_synchronized() const noexcept -> bool override {return false;}
        auto sync_root() const noexcept -> const xtd::object& override {return data_->sync_root;}
        
        struct dictionary_data {
          dictionary_data() noexcept = default;
          dictionary_data(const base_type & items, size_type version) noexcept : items {items}, version {version} {
            for (const auto& item : this->items)
              keys.add(item.first);
          }
          dictionary_data(base_type&& items, size_type version) noexcept : items {items}, version {version} {
            for (const auto& item : this->items)
              keys.add(item.first);
          }
          
          list_type keys;
          base_type items;
          size_type version = 0;
          xtd::object sync_root;
          xtd::object sync_op;
        };
        xtd::ptr < dictionary_data > data_ = xtd::new_ptr < dictionary_data > ();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::specialized::ordered_dictionary
      // {
      template < class key_t, class value_t >
      ordered_dictionary(xtd::collections::generic::idictionary < key_t, value_t >) -> ordered_dictionary < key_t, value_t>;
      
      template < class key_t, class value_t >
      ordered_dictionary(xtd::collections::generic::ienumerable < key_value_pair < key_t, value_t>>) -> ordered_dictionary<key_t, value_t>;
      
      template < class key_t, class value_t >
      ordered_dictionary(std::initializer_list < key_value_pair < key_t, value_t>>) -> ordered_dictionary < key_t, value_t >;
      
      template < class key_t, class value_t >
      ordered_dictionary(std::initializer_list < std::pair < key_t, value_t>>) -> ordered_dictionary < key_t, value_t >;
      
      template < class input_iterator_t >
      ordered_dictionary(input_iterator_t, input_iterator_t) -> ordered_dictionary < xtd::collections::generic::helpers::iterator_key_t < input_iterator_t>, xtd::collections::generic::helpers::iterator_mapped_t<input_iterator_t >>;
      // }
      /// @endcond
    }
  }
}
