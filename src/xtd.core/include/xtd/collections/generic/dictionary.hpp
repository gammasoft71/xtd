/// @file
/// @brief Contains xtd::collections::generic::dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
#include "idictionary.hpp"
#include "key_not_found_exception.hpp"
#include "../../new_ptr.hpp"
#include "../../ptr.hpp"
#include <unordered_map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of keys and values.
      /// @par Definition
      /// ```cpp
      /// template<typename key_t, typename value_t, typename hasher_t = xtd::collections::generic::helpers::hasher<key_t>, typename equator_t = xtd::collections::generic::helpers::equator<key_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      /// class dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/dictionary
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::dictionary class is same as [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map).
      /// @par Examples
      /// The following shows how to use xtd::collections::generic::dictionary.
      /// @include dictionary.cpp
      /// @remarks The xtd::collections::generic::dictionary <key_t, value_t> generic class provides a mapping from a set of keys to a set of values. Each addition to the dictionary consists of a value and its associated key. Retrieving a value by using its key is very fast, close to O(1), because the xtd::collections::generic::dictionary <key_t, value_t> class is implemented as a hash table.
      /// @note The speed of retrieval depends on the quality of the hashing algorithm of the type specified for `key_t`.
      /// @remarks As long as an object is used as a key in the xtd::collections::generic::dictionary <key_t, value_t>, it must not change in any way that affects its hash value. Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the dictionary's equality comparer.
      /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify an implementation, the default generic equality comparer xtd::collections::generic::equality_comparer<type_t>::default_equality_comparer is used. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
      /// @note For example, you can use the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
      /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements the xtd::collections::generic::dictionary <key_t, value_t> can hold. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
      /// @remarks For purposes of enumeration, each item in the dictionary is treated as a xtd::collections::generic::key_value_pair <key_t, value_t> structure representing a value and its key. The order in which the items are returned is undefined.
      /// @remarks The for each statement returns an object of the type of the elements in the collection. Since the xtd::collections::generic::dictionary <key_t, value_t> is a collection of keys and values, the element type is not the type of the key or the type of the value. Instead, the element type is a xtd::collections::generic::key_value_pair <key_t, value_t> of the key type and the value type. For example:
      /// ```cpp
      /// for (const key_value_pair<string, string>& kvp : my_dictionary)
      ///   console::write_line("key = {}, value = {}", kvp.key(), kvp.value());
      /// ```
      /// @remarks Or with `auto` key type and the value type. For example:
      /// ```cpp
      /// for (const auto& [key, value] : my_dictionary)
      ///   console::write_line("key = {}, value = {}", key, value);
      /// ```
      template<typename key_t, typename value_t, typename hasher_t = xtd::collections::generic::helpers::hasher<key_t>, typename equator_t = xtd::collections::generic::helpers::equator<key_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      class dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t> {
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
        /// @brief Represents the dictionary difference type.
        using difference_type = xtd::ptrdiff;
        /// @brief Represents the dictionary hasher type.
        using hasher = hasher_t;
        /// @brief Represents the dictionary equator type.
        using equator = equator_t;
        /// @brief Represents the dictionary equator type.
        using key_equal = equator_t;
        /// @brief Represents the dictionary allocator type.
        using allocator_type = allocator_t;
        /// @brief Represents the dictionary base value type.
        using base_value_type = std::pair<const key_t, value_t>;
        /// @brief Represents the dictionary base type.
        using base_type = std::unordered_map<key_type, mapped_type, hasher, key_equal, allocator_type>;
        /// @brief Represents the dictionary reference type.
        using reference = value_type&;
        /// @brief Represents the dictionary const reference type.
        using const_reference = const value_type&;
        /// @brief Represents the dictionary pointer type.
        using pointer = typename std::allocator_traits<allocator_t>::pointer;
        /// @brief Represents the dictionary const pointer type.
        using const_pointer = typename std::allocator_traits<allocator_t>::const_pointer;
        /// @brief Represents the iterator of dictionary value type.
        using iterator = typename xtd::collections::generic::idictionary<key_type, mapped_type>::iterator;
        /// @brief Represents the const iterator of dictionary value type.
        using const_iterator = typename xtd::collections::generic::idictionary<key_type, mapped_type>::const_iterator;
        /// @brief Represents the local iterator of dictionary value type.
        using local_iterator = typename base_type::local_iterator;
        /// @brief Represents the const local iterator of dictionary value type.
        using const_local_iterator = typename base_type::const_local_iterator;
        /// @brief Represents the dictionary node type.
        using node_type = typename base_type::node_type;
        /// @brief Represents the dictionary insert return type.
        using insert_return_type = typename base_type::insert_return_type;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_collection;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that is empty, has the default initial capacity, and uses the default equality comparer for the key type.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the default equality comparer.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, equality_comparer::default. If type `key_t` implements the xtd::equatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the iequality_comparer <typer_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @note If you can estimate the size of the collection, using a constructor that specifies the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        /// @remarks This constructor is an O(1) operation.
        /// @par Examples
        /// The following code example creates an empty xtd::collections::generic::dictionary <key_t, value_t> of strings with string keys and uses the Add method to add some elements. The example demonstrates that the dictionary::add method throws an xtd::argument_exception when attempting to add a duplicate key.
        ///
        /// This code example is part of a larger example provided for the xtd::collections::generic::dictionary <key_t, value_t> class.
        /// ```cpp
        /// // Create a new dictionary of strings, with string keys.
        /// //
        /// auto open_with = dictionary<string, string> {};
        ///
        /// // Add some elements to the dictionary. There are no
        /// // duplicate keys, but some of the values are duplicates.
        /// open_with.add("txt", "notepad.exe");
        /// open_with.add("bmp", "paint.exe");
        /// open_with.add("dib", "paint.exe");
        /// open_with.add("rtf", "wordpad.exe");
        ///
        /// // The add method throws an exception if the new key is
        /// // already in the dictionary.
        /// try {
        ///   open_with.add("txt", "winword.exe");
        /// } catch (const argument_exception&) {
        ///   console::write_line("An element with Key = \"txt\" already exists.");
        /// }
        /// ```
        dictionary() noexcept = default;
        
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        explicit dictionary(size_type bucket_count, const hasher& hash = hasher {}, const equator& equal = equator {}, const allocator_type& alloc = allocator_type {}) noexcept : data_(xtd::new_ptr<data>(bucket_count, hash, equal, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        dictionary(size_type bucket_count, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count, hasher {}, equator {}, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        dictionary(size_type bucket_count, const hasher& hash, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count, hash, equator {}, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. For the default constructor, the number of buckets is implementation-defined.
        explicit dictionary(const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        template <typename input_iterator_t>
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count = 0, const hasher& hash = hasher {}, const equator& equal = equator {}, const allocator_type& alloc = allocator_type {}) noexcept : data_(xtd::new_ptr<data>(bucket_count, hash, equal, alloc)) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        template <typename input_iterator_t>
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count, hasher {}, equator {}, alloc)) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        template <typename input_iterator_t>
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count, const hasher& hash, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count, hash, equator {}, alloc)) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const dictionary& other) noexcept : data_(xtd::new_ptr<data>(other.data_->items, other.data_->version, allocator_type {})) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const dictionary& other, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(other.data_->items, other.data_->version, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const std::unordered_map<key_t, value_t>& other) noexcept : data_(xtd::new_ptr<data>(0, hasher {}, equator {}, allocator_type {})) {
          for (auto iterator = other.begin(); iterator != other.end(); ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const std::unordered_map<key_t, value_t>& other, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(0, hasher {}, equator {}, alloc)) {
          for (auto iterator = other.begin(); iterator != other.end(); ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(dictionary&& other) noexcept = default;
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(dictionary&& other, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(std::move(other.data_->items), other.data_->version, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(std::unordered_map<key_t, value_t>&& other) noexcept : data_(xtd::new_ptr<data>(std::move(other.data_->items), 0, allocator_type {})) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(std::unordered_map<key_t, value_t>&& other, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(std::move(other.data_->items), 0, alloc)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        explicit dictionary(std::initializer_list<base_value_type> init, size_type bucket_count = 0, const hasher& hash = hasher {}, const equator& equal = equator {}, const allocator_type& alloc = allocator_type {}) : data_(xtd::new_ptr<data>(bucket_count, hash, equal, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        dictionary(std::initializer_list<base_value_type> init, size_type bucket_count, const allocator_type& alloc) : data_(xtd::new_ptr<data>(bucket_count, hasher {}, equator {}, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        dictionary(std::initializer_list<base_value_type> init, size_type bucket_count, const hasher& hash, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count, hash, equator {}, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        template <typename init_key_t, typename init_value_t>
        explicit dictionary(std::initializer_list<key_value_pair<init_key_t, init_value_t>> init, size_type bucket_count = 0, const hasher& hash = hasher {}, const equator& equal = equator {}, const allocator_type& alloc = allocator_type {}) : data_(xtd::new_ptr<data>(bucket_count, hash, equal, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        template <typename init_key_t, typename init_value_t>
        dictionary(std::initializer_list<key_value_pair<init_key_t, init_value_t>> init, size_type bucket_count, const allocator_type& alloc) : data_(xtd::new_ptr<data>(bucket_count, hasher {}, equator {}, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        template <typename init_key_t, typename init_value_t>
        dictionary(std::initializer_list<key_value_pair<init_key_t, init_value_t>> init, size_type bucket_count, const hasher& hash, const allocator_type& alloc) : data_(xtd::new_ptr<data>(bucket_count, hash, equator {}, alloc)) {
          for (const auto& [key, value] : init)
            add(key, value);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator begin() const noexcept override {return ienumerable<value_type>::begin();}
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        iterator begin() noexcept override {return ienumerable<value_type>::begin();}

        /// @brief Gets the number of buckets in the container.
        /// @return The number of buckets in the container.
        size_type bucket_count() const noexcept {return data_->items.bucket_count();}

        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        size_type capacity() const noexcept {return data_->items.size();}
        
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator cbegin() const noexcept override {return ienumerable<value_type>::cbegin();}
        
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator cend() const noexcept override {return ienumerable<value_type>::cend();}

        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        size_type count() const noexcept {return data_->items.size();}

        /// @brief Checks if the container has no elements, i.e. whether `begin() == end()`.
        /// @return `true` if the container is empty; otherwise `false`.
        bool empty() const noexcept {return data_->items.empty();}
        
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator end() const noexcept override {return ienumerable<value_type>::cend();}
        
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        iterator end() noexcept override {return ienumerable<value_type>::cend();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual const base_type& items() const noexcept {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual base_type& items() noexcept {return data_->items;}

        /// @brief Gets a collection containing the keys in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::dictionary::key_collection containing the keys in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The order of the keys in the xtd::collections::generic::dictionary::key_collection is unspecified, but it is the same order as the associated values in the xtd::collections::generic::dictionary::value_collection returned by the xtd::collections::generic::dictionary::values property.
        /// @remarks Getting the value of this property is an O(1) operation.
        key_collection keys() const noexcept override {
          auto keys = key_collection {};
          for (const auto& [key, value] : data_->items)
            keys.add(key);
          return keys;
        }
        
        /// @brief Gets the average number of elements per bucket, that is, xtd::collections::generic::dictionary::size divided by xtd::collections::generic::dictionary::bucket_count.
        /// @return Average number of elements per bucket.
        float load_factor() const {return data_->items.load_factor();}

        /// @brief Gets the maximum number of buckets the container is able to hold due to system or library implementation limitations.
        /// @return Maximum number of buckets.
        size_type max_bucket_count() const noexcept {return data_->items.max_bucket_count();}

        /// @brief Gets the maximum load factor (number of elements per bucket). The container automatically increases the number of buckets if the load factor exceeds this threshold.
        /// @return The current maximum load factor.
        float max_load_factor() const {return data_->items.max_load_factor();}
        /// @brief Sets the maximum load factor (number of elements per bucket). The container automatically increases the number of buckets if the load factor exceeds this threshold.
        /// @param value The new maximum load factor setting.
        void max_load_factor(float value) const {data_->items.max_load_factor(value);}

        /// @brief Gets the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. `std::distance(begin(), end())` for the largest container.
        /// @return Maximum number of elements.
        /// @remarks This value typically reflects the theoretical limit on the size of the container, at most `xtd::ptrdiff_object::max_value` or `std::numeric_limits<difference_type>::max()`. At runtime, the size of the container may be limited to a value smaller than max_size() by the amount of RAM available.
        size_type max_size() const noexcept {return data_->items.max_size();}

        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        size_type size() const noexcept {return data_->items.size();}

        /// @brief Gets a collection containing the values in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::dictionary::value_collection containing the values in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The order of the values in the xtd::collections::generic::dictionary::value_collection is unspecified, but it is the same order as the associated keys in the xtd::collections::generic::dictionary::key_collection returned by the xtd::collections::generic::dictionary::keys property.
        /// @remarks Getting the value of this property is an O(1) operation.
        value_collection values() const noexcept override {
          auto values = value_collection {};
          for (const auto& [key, value] : data_->items)
            values.add(value);
          return values;
        }
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Adds an element with the provided key and value to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param key The object to use as the key of the element to add.
        /// @param value The object to use as the value of the element to add.
        /// @exception xtd::argument_exception An element with the same key already exists in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        void add(const key_t& key, const value_t value) override {
          const auto& [iterator, succeeded] = data_->items.insert({key, value});
          if (!succeeded) throw xtd::argument_exception {};
        }

        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        const value_t& at(const key_t& key) const {
          auto iterator = data_->items.find(key);
          if (iterator == data_->items.end()) throw key_not_found_exception {};
          return iterator->second;
        }

        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        value_t& at(const key_t& key) {
          auto iterator = data_->items.find(key);
          if (iterator == data_->items.end()) throw key_not_found_exception {};
          return iterator->second;
        }
        /// @brief Returns the index of the bucket for key key. Elements (if any) with keys equivalent to key are always found in this bucket.
        /// @param key The value of the key to examine.
        /// @return Bucket index for the requested key.
        size_type bucket(const key_t& key) const {return data_->items.bucket(key);}
        
        /// @brief Returns the number of elements in the bucket with index `n`.
        /// @param n The index of the bucket to examine.
        /// @return The number of elements in the bucket `n`.
        size_type bucket_size(size_type n) const noexcept {return data_->items.bucket_size(n);}

        /// @brief Erases all elements from the container. After this call, xtd::collections::generic::dictionary::size returns zero.
        /// @remarks Invalidates any references, pointers, and iterators referring to contained elements. May also invalidate past-the-end iterators.
        void clear() noexcept {data_->items.clear();}
        
        /// @brief Returns the allocator associated with the container.
        /// @return The associated allocator.
        allocator_type get_allocator() const noexcept {return data_->items.get_allocator();}
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::enumerator structure for the xtd::collections::generic::dictionary <key_t, value_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          struct internal_enumerator : public ienumerator<value_type> {
          public:
            explicit internal_enumerator(const dictionary& items, size_type version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (version_ != items_.data_->version) throw xtd::invalid_operation_exception {"Collection was modified; enumeration operation may not execute."};
              if (iterator_ != items_.items().cend()) {
                //return *iterator_;
                static thread_local auto value = value_type {};
                value = value_type {*iterator_};
                return value;
              }
              static auto default_value_type = value_type {};
              return default_value_type;
            }
            
            bool move_next() override {
              if (version_ != items_.data_->version) throw xtd::invalid_operation_exception {"Collection was modified; enumeration operation may not execute."};
              if (!reset_) return ++iterator_ != items_.items().cend();
              reset_ = false;
              iterator_ = items_.items().cbegin();
              return iterator_ != items_.items().cend();
            }
            
            void reset() override {
              reset_ = true;
              version_ = items_.data_->version;
              iterator_ = items_.items().cend();
            }
            
          protected:
            bool reset_ = true;
            const dictionary& items_;
            typename dictionary::base_type::const_iterator iterator_ = items_.items().cend();
            size_type version_ = 0;
          };
          return {new_ptr<internal_enumerator>(*this, data_->version)};
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to true if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        key_value_pair<iterator, bool> insert(const value_type& value) {
          return data_->items.insert(value);
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to true if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        key_value_pair<iterator, bool> insert(value_type&& value) {
          return data_->items.insert(value);
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to true if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks Is equivalent to `emplace(std::forward<P>(value))` and only participates in overload resolution if `std::is_constructible<value_type, P&&>::value == true`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template <typename type_t>
        key_value_pair<iterator, bool> insert(type_t&& value) {
          return data_->items.insert(value);
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        iterator insert(const_iterator hint, const value_type& value) {
          return to_iterator(data_->items.insert(to_base_type_iterator(hint), value));
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        iterator insert(const_iterator hint, value_type&& value) {
          return to_iterator(data_->items.insert(to_base_type_iterator(hint), value));
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks Is equivalent to `emplace_hint(hint, std::forward<P>(value))` and only participates in overload resolution if `std::is_constructible<value_type, P&&>::value == true`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template <typename type_t>
        iterator insert(const_iterator hint, type_t&& value) {
          return to_iterator(data_->items.insert(to_base_type_iterator(hint), value));
        }
                
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param first The first iterator of the range of elements to insert.
        /// @param last The last iterator of the range of elements to insert.
        /// @remarks Inserts elements from range [`first`, `last`). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844)).
        /// @remarks If [`first`, `last`) is not a valid range, or `first` and/or `last` are iterators into `*this`, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template <typename input_iterator_t>
        void insert(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }

        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param ilist The initializer list to insert the values from.
        /// @remarks Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844)).
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        void insert(std::initializer_list<base_value_type> ilist) {
          for (const auto& [key, value] : ilist)
            add({key, value});
        }

        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param ilist The initializer list to insert the values from.
        /// @remarks Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844)).
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template <typename init_key_t, typename init_value_t>
        void insert(std::initializer_list<key_value_pair<init_key_t, init_value_t>> ilist) {
          for (const auto& [key, value] : ilist)
            add({key, value});
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param nh A compatible [node handle](https://en.cppreference.com/w/cpp/container/node_handle).
        /// @return An object of xtd::collections::generic::dictionary::insert_return_type with the members initialized as follows:
        ///  * If `nh` is empty, inserted is `false`, position is xtd::collections::generic::dictionary::end(), and node is empty.
        ///  * Otherwise if the insertion took place, inserted is `true`, position points to the inserted element, and node is empty.
        ///  * If the insertion failed, inserted is `false`, node has the previous value of `nh`, and position points to an element with a key equivalent to `nh.key()`.
        /// @remarks If `nh` is an empty [node handle](https://en.cppreference.com/w/cpp/container/node_handle), does nothing. Otherwise, inserts the element owned by nh into the container , if the container doesn't already contain an element with a key equivalent to `nh.key()`. The behavior is undefined if `nh` is not empty and `get_allocator() != nh.get_allocator()`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        insert_return_type insert(node_type&& nh) {
          return data_->items.inser(nh);
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param nh A compatible [node handle](https://en.cppreference.com/w/cpp/container/node_handle).
        /// @return End iterator if `nh` was empty, iterator pointing to the inserted element if insertion took place, and iterator pointing to an element with a key equivalent to `nh.key()` if it failed.
        /// @remarks If `nh` is an empty [node handle](https://en.cppreference.com/w/cpp/container/node_handle), does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the container, if the container doesn't already contain an element with a key equivalent to `nh.key()`, and returns the iterator pointing to the element with key equivalent to `nh.key()`(regardless of whether the insert succeeded or failed). If the insertion succeeds, `nh` is moved from, otherwise it retains ownership of the element. `hint` is used as a non-binding suggestion to where the search should start. The behavior is undefined if `nh` is not empty and `get_allocator() != nh.get_allocator()`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        iterator insert(const_iterator hint, node_type&& nh) {
          return data_->items.inser(to_base_type_iterator(hint), nh);
        }
        
      /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(dictionary&& other) noexcept {
          data_->items = std::move(other.data_->items);
          data_->version = std::move(other.data_->version);
          return *this;
        }
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(std::unordered_map<key_t, value_t>&& other) noexcept {
          data_->items = std::move(other);
          data_->version = 0;
          return *this;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(const dictionary& other) noexcept = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(const std::unordered_map<key_t, value_t>& other) noexcept {
          data_->items.clear();
          for (const auto& [key, value] : other)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        dictionary& operator =(std::initializer_list<base_value_type> ilist) {
          data_->items.clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        template <typename init_key_t, typename init_value_t>
        dictionary& operator =(std::initializer_list<key_value_pair<init_key_t, init_value_t>> ilist) {
          data_->items.clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
        }
        
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        const value_t& operator [](const key_t& key) const override {return at(key);}
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        value_t& operator [](const key_t& key) override {return data_->items[key];}

        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type&() const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type&() noexcept {return data_->items;}
        /// @}

      private:
        typename base_type::iterator to_base_type_iterator(iterator value) noexcept {
          if (value == begin()) return data_->items.begin();
          if (value == end()) return data_->items.end();
          return data_->items.begin() + std::distance(begin(), value);
        }
        
        iterator to_iterator(typename base_type::iterator value) noexcept {
          if (value == data_->items.begin()) return begin();
          if (value == data_->items.end()) return end();
          return begin() + std::distance(data_->items.begin(), value);
        }
        

        struct data {
          data() = default;
          data(size_type bucket_count, const hasher& hash, const equator& equal, const allocator_type& alloc) noexcept : items(bucket_count, hash, equal, alloc) {}
          explicit data(const allocator_type& alloc) noexcept : items(alloc) {}
          data(const base_type& items, size_type version, const allocator_type& alloc) noexcept : items {items, alloc}, version {version} {}
          data(base_type&& items, size_type version, const allocator_type& alloc) noexcept : items {items, alloc}, version {version} {}

          base_type items;
          size_type version = 0;
          xtd::object sync_root;
        };
        xtd::ptr<data> data_ = xtd::new_ptr<data>();
      };
    }
  }
}
