/// @file
/// @brief Contains xtd::collections::generic::dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
#include "helpers/iterator.hpp"
#include "idictionary.hpp"
#include "key_not_found_exception.hpp"
#include "../../argument_out_of_range_exception.hpp"
#include "../../new_ptr.hpp"
#include "../../ptr.hpp"
#include <cmath>
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
      /// template<class key_t, class value_t, class hasher_t = xtd::collections::generic::helpers::hasher<key_t>, class equator_t = xtd::collections::generic::helpers::equator<key_t>, class allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      /// class dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/dictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @par Examples
      /// The following code example creates an empty xtd::collections::generic::dictionary <key_t, value_t> of strings with string keys and uses the Add method to add some elements. The example demonstrates that the xtd::collections::generic::dictionary::add method throws an xtd::argument_exception when attempting to add a duplicate key.
      ///
      /// The example uses the xtd::collections::generic::dictionary::operator [] to retrieve values, demonstrating that a xtd::collections::generic::key_not_found_exception is thrown when a requested key is not present, and showing that the value associated with a key can be replaced.
      ///
      /// The example shows how to use the xtd::collections::generic::dictionary::try_get_vValue method as a more efficient way to retrieve values if a program often must try key values that are not in the dictionary, and it shows how to use the xtd::collections::generic::dictionary::contains_key method to test whether a key exists before calling the xtd::collections::generic::dictionary::add method.
      ///
      /// The example shows how to enumerate the keys and values in the dictionary and how to enumerate the keys and values alone using the xtd::collections::generic::dictionary::keys property and the xtd::collections::generic::dictionary::values property.
      ///
      /// Finally, the example demonstrates the xtd::collections::generic::dictionary::remove method.
      /// @include generic_dictionary.cpp
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
      template<class key_t, class value_t, class hasher_t = helpers::hasher<key_t>, class equator_t = helpers::equator<key_t>, class allocator_t = helpers::allocator<std::pair<const key_t, value_t >>>
      class dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = typename xtd::collections::generic::idictionary < key_t, value_t >::key_type;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = typename xtd::collections::generic::idictionary < key_t, value_t >::mapped_type;
        /// @brief Represents the dictionary value type.
        using value_type = typename xtd::collections::generic::idictionary < key_type, mapped_type >::value_type;
        /// @brief Represents the dictionary size type.
        using size_type = xtd::size;
        /// @brief Represents the dictionary base value type.
        using base_value_type = std::pair < const key_t, value_t >;
        /// @brief Represents the dictionary base type.
        using base_type = std::unordered_map < key_type, mapped_type, hasher_t, equator_t, allocator_t >;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary < key_type, mapped_type >::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary < key_type, mapped_type >::value_collection;
        /// @brief Represents the dictionary equator type.
        using equator = equator_t;
        /// @brief Represents the dictionary hasher type.
        using hasher = hasher_t;
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
        ///   console::write_line("An element with key = \"txt\" already exists.");
        /// }
        /// ```
        dictionary() noexcept = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::idictionary <key_t, value_t> and uses the default equality comparer for the key type.
        /// @param dictionary The xtd::collections::generic::idictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the default equality comparer; likewise, every key in the source `dictionary` must also be unique according to the default equality comparer.
        /// @remarks The initial capacity of the new xtd::collections::generic::dictionary <key_t, value_t> is large enough to contain all the elements in dictionary.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, xtd::collections::generic::equality_comparer::default_equality_comparer. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in dictionary.
        /// @par Examples
        /// The following code example shows how to use the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor to initialize a xtd::collections::generic::dictionary <key_t, value_t> with sorted content from another dictionary. The code example creates a xtd::collections::generic::sorted_dictionary <key_t, value_t> and populates it with data in random order, then passes the xtd::collections::generic::sorted_dictionary <key_t, value_t> to the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor, creating a xtd::collections::generic::dictionary <key_t, value_t> that is sorted. This is useful if you need to build a sorted dictionary that at some point becomes static; copying the data from a xtd::collections::generic::sorted_dictionary <key_t, value_t> to a xtd::collections::generic::dictionary <key_t, value_t> improves retrieval speed.
        /// @include generic_dictionary_constructor_with_idicationary.cpp
        dictionary(const idictionary < key_t, value_t >& dictionary) {
          ensure_capacity(dictionary.count());
          for (const auto& item : dictionary)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        dictionary(const ienumerable < value_type >& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that is empty, has the default initial capacity, and uses the specified xtd::collections::generic::iequality_comparer<type_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer<type_t> implementation to use when comparing keys.
        /// @remarks Use this constructor with the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        dictionary(const xtd::collections::generic::iequality_comparer<key_type>& comparer) : data_(xtd::new_ptr < dictionary_data > (comparer)) {}
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that is empty, has the specified initial capacit.
        /// @param capacity The initial number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can contain.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type TKey implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks xtd::collections::generic::dictionary::capacity and xtd::collections::generic::dictionary::bucket_count are equivalent properties.
        dictionary(size_t capacity) {
          ensure_capacity(capacity);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that is empty, has the specified initial capacity, and uses the specified xtd::collections::generic::iequality_comparer <type_t>.
        /// @param capacity The initial number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can contain.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing keys.
        /// @remarks Use this constructor with the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type TKey implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks xtd::collections::generic::dictionary::capacity and xtd::collections::generic::dictionary::bucket_count are equivalent properties.
        dictionary(size_t capacity, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : data_(xtd::new_ptr < dictionary_data > (comparer)) {
          ensure_capacity(capacity);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::dictionary <key_t, value_t> and uses the specified xtd::collections::generic::iequality_comparer <type_t>.
        /// @param dictionary The xtd::collections::generic::dictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Use this constructor with the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @note For example, duplicate keys can occur if `comparer` is one of the case-insensitive string comparers provided by the xtd::string_comparer class and `dictionary` does not use a case-insensitive comparer key.
        /// @remarks The initial capacity of the new xtd::collections::generic::dictionary <key_t, value_t> is large enough to contain all the elements in `dictionary`.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in dictionary.
        dictionary(const idictionary < key_t, value_t >& dictionary, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : data_(xtd::new_ptr < dictionary_data>(comparer)) {
          ensure_capacity(dictionary.count());
          for (const auto& item : dictionary)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t> and uses the specified xtd::collections::generic::iequality_comparer <type_t>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        dictionary(const ienumerable < value_type >& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) : data_(xtd::new_ptr < dictionary_data>(comparer)) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(dictionary&& other) noexcept = default;
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        dictionary(const dictionary & other) noexcept : data_(xtd::new_ptr < dictionary_data > (*other.data_->comparer, other.data_->items, other.data_->version)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(std::unordered_map < key_t, value_t > && other) noexcept : data_(xtd::new_ptr < dictionary_data>(std::move(other))) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        dictionary(const std::unordered_map < key_t, value_t >& other) {
          for (auto iterator = other.begin(); iterator != other.end(); ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        dictionary(std::initializer_list < base_value_type > init) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            self_[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class init_key_t, class init_value_t >
        explicit dictionary(std::initializer_list < key_value_pair < init_key_t, init_value_t>> init) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            self_[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class input_iterator_t >
        explicit dictionary(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        /// @remarks xtd::collections::generic::dictionary::capacity and xtd::collections::generic::dictionary::bucket_count are equivalent properties.
        auto capacity() const noexcept -> size_type {return items().bucket_count();}
        
        /// @brief Gets the xtd::collections::generic::iequality_comparer <type_t> that is used to determine equality of keys for the dictionary.
        /// @return The xtd::collections::generic::iequality_comparer <type_t> generic interface implementation that is used to determine equality of keys for the current xtd::collections::generic::dictionary <key_t, value_t> and to provide hash values for the keys.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify one, the default generic equality comparer td::collections::generic::equality_comparer::default_equality_comparer is used.
        auto comparer() const noexcept -> const iequality_comparer < key_t >& {
          if (!data_->comparer) return equality_comparer <key_type>::default_equality_comparer();
          return *data_->comparer;
        }
        
        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto count() const noexcept -> size_type override {return data_->items.size();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual auto items() const noexcept -> const base_type& {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual auto items() noexcept -> base_type& {return data_->items;}
        
        /// @brief Gets a collection containing the keys in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::dictionary::key_collection containing the keys in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The order of the keys in the xtd::collections::generic::dictionary::key_collection is unspecified, but it is the same order as the associated values in the xtd::collections::generic::dictionary::value_collection returned by the xtd::collections::generic::dictionary::values property.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto keys() const noexcept -> key_collection override {
          auto keys = key_collection {};
          for (const auto& [key, value] : data_->items)
            keys.add(key);
          return keys;
        }
        
        /// @brief Gets a collection containing the values in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::generic::dictionary::value_collection containing the values in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The order of the values in the xtd::collections::generic::dictionary::value_collection is unspecified, but it is the same order as the associated keys in the xtd::collections::generic::dictionary::key_collection returned by the xtd::collections::generic::dictionary::keys property.
        /// @remarks Getting the value of this property is an O(1) operation.
        auto values() const noexcept -> value_collection override {
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
        auto add(const key_t & key, const value_t& value) -> void override {
          if (!try_add(key, value)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
        }
        
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        auto add(const value_type & item) -> void override {
          add(item.key(), item.value());
        }
        
        /// @brief Removes all keys and values from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The xtd::collections::generic::dictionary::count property is set to 0, and references to other objects from elements of the collection are also released. The capacity remains unchanged.
        auto clear() noexcept -> void override {
          data_->items.clear();
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `item` ; otherwise, `false`.
        auto contains(const value_type & item) const noexcept -> bool override {
          auto iterator = items().find(item.key());
          if (iterator == items().end()) return false;
          return iterator->second == item.value();
        }
        
        /// @brief Determines whether the xtd::collections::generic::dictionary <key_t, value_t> contains the specified key.
        /// @param The key to locate in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method approaches an O(1) operation.
        auto contains_key(const key_t & key) const noexcept -> bool override {
          return data_->items.find(key) != data_->items.end();
        }
        
        /// @brief Determines whether the xtd::collections::generic::dictionary <key_t, value_t> contains the specified value.
        /// @param The value to locate in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method performs a linear search; therefore, the average execution time is proportional to xtd::collections::generic::dictionary::count. That is, this method is an O(n) operation, where n is xtd::collections::generic::dictionary::count.
        auto contains_value(const value_t& value) const noexcept -> bool {
          for (const auto& [item_key, item_value] : self_)
            if (item_value == value) return true;
          return false;
        }
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        auto copy_to(xtd::array < value_type >& array, xtd::size array_index) const -> void override {
          if (array_index + count() > array.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          for (const auto& item : self_)
            array[array_index++] = item;
        }
        
        /// @brief Ensures that the dictionary can hold up to a specified number of entries without any further expansion of its backing storage.
        /// @param capacity The number of entries.
        /// @return The current capacity of the xtd::collections::generic::dictionary <key_t, value_t>.
        auto ensure_capacity(xtd::size capacity) noexcept -> size_type {
          data_->items.reserve(capacity);
          return self_.capacity();
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::enumerator structure for the xtd::collections::generic::dictionary <key_t, value_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          struct dictionary_enumerator : public ienumerator < value_type > {
            explicit dictionary_enumerator(const dictionary & items, size_type version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (iterator_ == items_.items().cend()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return (value_ = value_type {*iterator_});
            }
            
            auto move_next() -> bool override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              if (index_++ && iterator_ != items_.data_->items.cend()) ++iterator_;
              else iterator_ = items_.items().cbegin();
              return  iterator_ != items_.data_->items.cend();
            }
            
            auto reset() -> void override {
              index_ = 0;
              version_ = items_.data_->version;
              iterator_ = items_.items().cend();
            }
            
          private:
            size_type index_ = 0;
            const dictionary& items_;
            typename dictionary::base_type::const_iterator iterator_ = items_.data_->items.cend();
            mutable value_type value_;
            size_type version_ = 0;
          };
          return {new_ptr < dictionary_enumerator > (self_, data_->version)};
        }
        
        /// @brief Removes the value with the specified key from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param key The key of the element to remove.
        /// @return `true` if the element is successfully found and removed; otherwise, `false`. This method returns `false` if key is not found in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks If the xtd::collections::generic::dictionary <key_t, value_t> does not contain an element with the specified key, the xtd::collections::generic::dictionary <key_t, value_t> remains unchanged. No exception is thrown.
        auto remove(const key_t & key) noexcept -> bool override {
          return items().erase(key) == 1;
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to remove from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item value was not found in the xtd::collections::generic::dictionary <key_t, value_t>.
        auto remove(const value_type & item) noexcept -> bool override {
          if (!contains_value(item.value())) return false;
          return items().erase(item.key()) == 1;
        }
        
        /// @brief Removes the value with the specified key from the xtd::collections::generic::dictionary <key_t, value_t>, and copies the element to the `value` parameter.
        /// @param key The key of the element to remove.
        /// @param value The removed element.
        auto remove(const key_t & key, value_t& value) noexcept -> bool {
          auto iterator = items().find(key);
          if (iterator == items().end()) return false;
          value = iterator->value();
          return items().erase(iterator) != items().end();
        }
        
        /// @brief Gets a string that represents the current object.
        /// @return A string that represents the current object.
        auto to_string() const noexcept -> xtd::string override {return xtd::string::format("{{{}}}", xtd::string::join(", ", self_));}
        
        /// @brief Sets the capacity of this dictionary to hold up a specified number of entries without any further expansion of its backing storage.
        /// @param capacity The new capacity.
        /// @exception xtd::argument_out_of_range_exception `capacity` is less than xtd::collections::generic::dictionary::count.
        /// @remarks This method can be used to minimize the memory overhead once it is known that no new elements will be added.
        auto trim_excess(size_type capacity) -> void {
          if (capacity < count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          items().rehash(capacity);
        }
        
        /// @brief Sets the capacity of this dictionary to what it would be if it had been originally initialized with all its entries.
        /// @remarks This method can be used to minimize memory overhead once it is known that no new elements will be added to the dictionary. To allocate a minimum size storage array, execute the following statements:
        /// ```
        /// dictionary.clear();
        /// dictionary.trim_excess();
        /// ```
        auto trim_excess() -> void {
          rehash(count());
        }
        
        /// @brief Attempts to add the specified key and value to the dictionary.
        /// @param key The key of the element to add.
        /// @param value The value of the element to add.
        /// @return `true` if the key/value pair was added to the dictionary successfully; otherwise, `false`.
        /// @remarks Unlike the xtd::collections::generic::dictionary::add method, this method doesn't throw an exception if the element with the given key exists in the dictionary. Unlike the xtd::collections::generic::dictionary indexer (operator []), xtd::collections::generic::dictionary::try_add doesn't override the element if the element with the given key exists in the dictionary. If the key already exists, xtd::collections::generic::dictionary::try_add does nothing and returns `false`.
        auto try_add(const key_t & key, const value_t value) noexcept -> bool {
          const auto& [iterator, succeeded] = data_->items.insert(std::forward < base_value_type > ({key, value}));
          if (succeeded) ++data_->version;
          return succeeded;
        }
        
        /// @brief Gets the value associated with the specified key.
        /// @param key The key of the value to get.
        /// @param value When this method returns, contains the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified key; otherwise, `false`.
        auto try_get_value(const key_t & key, value_t& value) const -> bool override {
          auto iterator = items().find(key);
          if (iterator != items().end()) {
            value = iterator->second;
            return true;
          }
          value = value_t {};
          return false;
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(dictionary&& other) noexcept -> dictionary& {
          data_->comparer = std::move(other.data_->comparer);
          data_->items = std::move(other.data_->items);
          data_->version = std::move(other.data_->version);
          return self_;
        }
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(std::unordered_map < key_t, value_t > && other) noexcept -> dictionary& {
          data_->items = std::move(other);
          ++data_->version;
          return self_;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(const dictionary & other) noexcept -> dictionary& = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(const std::unordered_map < key_t, value_t >& other) noexcept -> dictionary& {
          data_->items.clear();
          for (const auto& [key, value] : other)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        auto operator =(std::initializer_list < base_value_type > ilist) -> dictionary& {
          data_->items.clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        template < class init_key_t, class init_value_t >
        auto operator =(std::initializer_list < key_value_pair < init_key_t, init_value_t>> ilist) -> dictionary& {
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
        const value_t& operator [](const key_t & key) const override {
          auto iterator = data_->items.find(key);
          if (iterator == data_->items.end()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::key_not_found);
          return iterator->second;
        }
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        value_t& operator [](const key_t & key) override {
          ++data_->version;
          return data_->items[key];
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type& () const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type& () noexcept {return data_->items;}
        /// @brief Gets a std::unordered_map<key_t, value_t>.
        /// @return A std::unordered_map<key_t, value_t>.
        operator std::unordered_map<key_t, value_t>() const noexcept {
          std::unordered_map<key_t, value_t> result;
          for (auto& [key, value] : data_->items)
            result[key] = value;
          return result;
        }
        /// @}
        
      private:
        auto is_read_only() const noexcept -> bool override {return false;}
        auto is_synchronized() const noexcept -> bool override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        
        struct dictionary_data {
          dictionary_data() = default;
          dictionary_data(const xtd::collections::generic::iequality_comparer<key_type>& comparer) : comparer {&comparer}, items {size_type {}, hasher_t {comparer}, equator_t {comparer}} {}
          dictionary_data(const xtd::collections::generic::iequality_comparer<key_type>& comparer, const base_type & items, size_type version) noexcept : comparer {&comparer}, items {size_type {}, hasher_t {comparer}, equator_t {comparer}}, version {version} {
            for (const auto& item : items)
              self_.items.insert(item);
          }
          dictionary_data(base_type&& items, size_type version) noexcept : version {version} {
            for (auto&& item : items)
              self_.items.insert(item);
          }
          
          const xtd::collections::generic::iequality_comparer<key_type>* comparer = null;
          base_type items;
          size_type version = 0;
          xtd::object sync_root;
        };
        xtd::ptr<dictionary_data> data_ = xtd::new_ptr<dictionary_data>();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::generic::dictionary
      // {
      template < class key_t, class value_t >
      dictionary(idictionary < key_t, value_t >) -> dictionary<key_t, value_t>;
      
      template < class key_t, class value_t >
      dictionary(ienumerable < key_value_pair < key_t, value_t>>) -> dictionary<key_t, value_t>;
      
      template < class key_t, class value_t >
      dictionary(std::initializer_list < key_value_pair < key_t, value_t>>) -> dictionary<key_t, value_t>;
      
      template < class key_t, class value_t >
      dictionary(std::initializer_list < std::pair < key_t, value_t>>) -> dictionary<key_t, value_t>;
      
      template < class input_iterator_t >
      dictionary(input_iterator_t, input_iterator_t) -> dictionary<helpers::iterator_key_t<input_iterator_t>, helpers::iterator_mapped_t<input_iterator_t>>;
      // }
      /// @endcond
    }
  }
}
