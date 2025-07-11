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
        /// @name Public Classes
        
        /// @{
        /// @brief Represents the dictionary hasher type.
        struct hasher {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the argument type.
          using argument_type = key_t;
          /// @brief Represents the result type.
          using result_type = xtd::size;
          /// @}
          
          /// @name Public Operators
          
          /// @{
          /// @brief Serves as a hash function for a specified key with a particular type (type_t).
          /// @param key The key to hash.
          /// @return A hash code for the spesified key.
          /// @remarks If key_t inherits from xtd::object, the xtd::object::get_hash_code method will be used; otherwise, the [std::hash](https://en.cppreference.com/w/cpp/utility/hash) object function will be used.
          size_t operator()(const key_t& key) const {
            if (comparer) return comparer->get_hash_code(key);
            return hasher_t {}(key);
          }
          /// @}
          
private:
          friend class dictionary;
          hasher() = default;
          explicit hasher(const iequality_comparer<key_t>* comparer) : comparer {comparer} {}
          const iequality_comparer<key_t>* comparer = nullptr;
        };
        
        /// @brief Represents the dictionary equator type.
        struct equator {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the first argument type.
          using first_argument_type = key_t;
          /// @brief Represents the second argument type.
          using second_argument_type = key_t;
          /// @brief Represents the result type.
          using result_type = bool;
          /// @}
          
          /// @name Public Operators
          
          /// @{
          /// @brief checks if the specified a and b keys are equal.
          /// @param a The first key to check.
          /// @param b The second key to check.
          /// @return `true` if keys are equals; otherwise `false`.
          /// @remarks If key_t inherits from xtd::object, the xtd::object::equals method will be used; otherwise, the [std::equal_to](https://en.cppreference.com/w/cpp/utility/functional/equal_to) object function will be used.
          bool operator()(const key_t & a, const key_t & b) const {
            if (&a == &b) return true;
            if (comparer) return comparer->equals(a, b);
            return equator_t {}(a, b);
          }
          /// @}
          
private:
          friend class dictionary;
          equator() = default;
          explicit equator(const iequality_comparer < key_t > * comparer) : comparer {comparer} {}
          const iequality_comparer < key_t > * comparer = nullptr;
        };
        /// @}
        
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
        /// @brief Represents the dictionary difference type.
        using difference_type = xtd::ptrdiff;
        /// @brief Represents the dictionary key_equal type.
        using key_equal = equator;
        /// @brief Represents the dictionary allocator type.
        using allocator_type = allocator_t;
        /// @brief Represents the dictionary base value type.
        using base_value_type = std::pair < const key_t, value_t >;
        /// @brief Represents the dictionary base type.
        using base_type = std::unordered_map < key_type, mapped_type, hasher, key_equal, allocator_type >;
        /// @brief Represents the dictionary reference type.
        using reference = value_type&;
        /// @brief Represents the dictionary const reference type.
        using const_reference = const value_type&;
        /// @brief Represents the dictionary pointer type.
        using pointer = typename std::allocator_traits < allocator_t >::pointer;
        /// @brief Represents the dictionary const pointer type.
        using const_pointer = typename std::allocator_traits < allocator_t >::const_pointer;
        /// @brief Represents the iterator of dictionary value type.
        using iterator = typename xtd::collections::generic::idictionary < key_type, mapped_type >::iterator;
        /// @brief Represents the const iterator of dictionary value type.
        using const_iterator = typename xtd::collections::generic::idictionary < key_type, mapped_type >::const_iterator;
        /// @brief Represents the local iterator of dictionary value type.
        using local_iterator = typename base_type::local_iterator;
        /// @brief Represents the const local iterator of dictionary value type.
        using const_local_iterator = typename base_type::const_local_iterator;
        /// @brief Represents the dictionary node type.
        using node_type = typename base_type::node_type;
        /// @brief Represents the dictionary insert return type.
        using insert_return_type = typename base_type::insert_return_type;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary < key_type, mapped_type >::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary < key_type, mapped_type >::value_collection;
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
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in dictionary.
        /// @par Examples
        /// The following code example shows how to use the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor to initialize a xtd::collections::generic::dictionary <key_t, value_t> with sorted content from another dictionary. The code example creates a xtd::collections::generic::sorted_dictionary <key_t, value_t> and populates it with data in random order, then passes the xtd::collections::generic::sorted_dictionary <key_t, value_t> to the xtd::collections::generic::dictionary <key_t, value_t>(xtd::collections::generic::iequality_comparer <key_t>) constructor, creating a xtd::collections::generic::dictionary <key_t, value_t> that is sorted. This is useful if you need to build a sorted dictionary that at some point becomes static; copying the data from a xtd::collections::generic::sorted_dictionary <key_t, value_t> to a xtd::collections::generic::dictionary <key_t, value_t> improves retrieval speed.
        /// @include generic_dictionary_constructor_with_idicationary.cpp
        dictionary(const idictionary < key_t, value_t > & dictionary) {
          ensure_capacity(dictionary.count());
          for (const auto& item : dictionary)
            add(item);
        }
        
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        dictionary(const ienumerable < value_type > & collection) {
          for (const auto& item : collection)
            add(item);
        }
        
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that is empty, has the default initial capacity, and uses the specified xtd::collections::generic::iequality_comparer<type_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer<type_t> implementation to use when comparing keys.
        /// @remarks Use this constructor with the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        template < class equality_comparer_t >
        dictionary(const equality_comparer_t& comparer) : data_(xtd::new_ptr < data > (new_ptr < equality_comparer_t > (comparer))) {}
        
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        explicit dictionary(size_type bucket_count, const hasher_t& hash = hasher_t {}, const equator_t& equal = equator_t {}, const allocator_type& alloc = allocator_type {}) noexcept : data_(xtd::new_ptr < data > (bucket_count)) {}
        
        /* Confict with dictionary(size_t capacity, const equality_comparer_t& comparer) constructor
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        dictionary(size_type bucket_count, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(bucket_count)) {}
         */
        
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to 1.0. For the default constructor, the number of buckets is implementation-defined.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that can be added to the xtd::collections::generic::dictionary <key_t, value_t> before resizing is necessary. As elements are added to a xtd::collections::generic::dictionary <key_t, value_t>, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        dictionary(size_type bucket_count, const hasher_t& hash, const allocator_type & alloc) noexcept : data_(xtd::new_ptr < data > (bucket_count)) {}
        
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::dictionary <key_t, value_t> and uses the specified xtd::collections::generic::iequality_comparer <type_t>.
        /// @param dictionary The xtd::collections::generic::dictionary <key_t, value_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Use this constructor with the case-insensitive string comparers provided by the xtd::string_comparer class to create dictionaries with case-insensitive string keys.
        /// @remarks Every key in a xtd::collections::generic::dictionary <key_t, value_t> must be unique according to the specified comparer; likewise, every key in the source `dictionary` must also be unique according to the specified comparer.
        /// @note For example, duplicate keys can occur if `comparer` is one of the case-insensitive string comparers provided by the xtd::string_comparer class and `dictionary` does not use a case-insensitive comparer key.
        /// @remarks The initial capacity of the new xtd::collections::generic::dictionary <key_t, value_t> is large enough to contain all the elements in `dictionary`.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. If type `key_t` implements the xtd::iequatable <type_t> generic interface, the default equality comparer uses that implementation.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in dictionary.
        template < class equality_comparer_t >
        dictionary(const idictionary < key_t, value_t > & dictionary, const equality_comparer_t& comparer) : data_(xtd::new_ptr < data>(new_ptr < equality_comparer_t > (comparer))) {
          ensure_capacity(dictionary.count());
          for (const auto& item : dictionary)
            add(item);
        }
        
        /// @brief Initializes a new instance of the xtd::collections::generic::dictionary <key_t, value_t> class that contains elements copied from the specified xtd::collections::generic::ienumerable <type_t> and uses the specified xtd::collections::generic::iequality_comparer <type_t>.
        /// @param collection The xtd::collections::generic::ienumerable <type_t> whose elements are copied to the new xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing keys.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        template < class equality_comparer_t >
        dictionary(const ienumerable < value_type > & collection, const equality_comparer_t& comparer) : data_(xtd::new_ptr < data>(new_ptr < equality_comparer_t > (comparer))) {
          for (const auto& item : collection)
            add(item);
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
        template < class equality_comparer_t >
        dictionary(size_t capacity, const equality_comparer_t& comparer) : data_(xtd::new_ptr < data > (new_ptr < equality_comparer_t > (comparer))) {
          ensure_capacity(capacity);
        }
        
        /* Conflict with dictionary(const equality_comparer_t& comparer) constructor.
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Constructs empty container. Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. For the default constructor, the number of buckets is implementation-defined.
        explicit dictionary(const allocator_t& alloc) noexcept {}
        */
        
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param first The fist iterator of the range [first, last) to copy the elements from.
        /// @param last  Thaae last itezrator of the range [first, last) to copy the elements from.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class input_iterator_t >
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count = 0, const hasher_t& hash = hasher_t {}, const equator_t& equal = equator_t {}, const allocator_type& alloc = allocator_type {}) : data_(xtd::new_ptr < data > (bucket_count)) {
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
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class input_iterator_t >
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
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
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Constructs the container with the contents of the range [first, last). Sets xtd::collections::generic::dictionary::max_load_factor() to `1.0`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844).
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class input_iterator_t >
        explicit dictionary(input_iterator_t first, input_iterator_t last, size_type bucket_count, const hasher_t& hash, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
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
        dictionary(const dictionary & other) noexcept : data_(xtd::new_ptr < data > (other.data_->comparer, other.data_->items, other.data_->version)) {}
        
        /* Conflict with dictionary(const idictionary<key_t, value_t>& dictionary, const equality_comparer_t& comparer) constructor.
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const dictionary& other, const allocator_type& alloc) noexcept : data_(xtd::new_ptr<data>(other.data_->comparer, other.data_->items, other.data_->version)) {}
         */
        
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const std::unordered_map < key_t, value_t > & other) {
          for (auto iterator = other.begin(); iterator != other.end(); ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks Copy constructor. Constructs the container with the copy of the contents of `other`, copies the load factor, the predicate, and the hash function as well. If `alloc` is not provided, allocator is obtained by calling
        /// ```cpp
        /// std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())
        /// ```
        dictionary(const std::unordered_map < key_t, value_t > & other, const allocator_type & alloc) {
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
        dictionary(dictionary&& other, const allocator_type & alloc) noexcept : data_(xtd::new_ptr < data > (std::move(other.data_->items), other.data_->version)) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(std::unordered_map < key_t, value_t > && other) noexcept : data_(xtd::new_ptr < data>(std::move(other.data_->items))) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param other Another container to be used as source to initialize the elements of the container with.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @remarks [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor). Constructs the container with the contents of `other` using move semantics. If `alloc` is not provided, allocator is obtained by move-construction from the allocator belonging to other.
        dictionary(std::unordered_map < key_t, value_t > && other, const allocator_type & alloc) noexcept : data_(xtd::new_ptr < data>(std::move(other.data_->items))) {}
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        explicit dictionary(std::initializer_list < base_value_type > init, size_type bucket_count = 0, const hasher_t& hash = hasher_t {}, const equator_t& equal = equator_t {}, const allocator_type& alloc = allocator_type {}) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        dictionary(std::initializer_list < base_value_type > init, size_type bucket_count, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        dictionary(std::initializer_list < base_value_type > init, size_type bucket_count, const hasher_t& hash, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param equal Comparison function to use for all key comparisons of this container.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class init_key_t, class init_value_t >
        explicit dictionary(std::initializer_list < key_value_pair < init_key_t, init_value_t>> init, size_type bucket_count = 0, const hasher_t& hash = hasher_t {}, const equator_t& equal = equator_t {}, const allocator_type& alloc = allocator_type {}) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class init_key_t, class init_value_t >
        dictionary(std::initializer_list < key_value_pair < init_key_t, init_value_t>> init, size_type bucket_count, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @brief Initializes instance of the xtd::collections::generic::dictionary <key_t, value_t> class from a variety of data sources. Optionally uses user supplied `bucket_count` as a minimal number of buckets to create, `hash` as the hash function, `equal` as the function to compare keys and `alloc` as the allocator.
        /// @param init Initializer list to initialize the elements of the container with.
        /// @param bucket_count Minimal number of buckets to use on initialization. If it is not specified, implementation-defined default value is used.
        /// @param hash Hash function to use.
        /// @param alloc Allocator to use for all memory allocations of this container.
        /// @exception xtd::argument_exception `dictionary` contains one or more duplicate keys.
        /// @remarks [Initializer-list](https://en.cppreference.com/w/cpp/language/list_initialization) constructor. Constructs the container with the contents of the initializer list init, same as
        /// ```cpp
        /// dictionary(init.begin(), init.end())
        /// ```
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        template < class init_key_t, class init_value_t >
        dictionary(std::initializer_list < key_value_pair < init_key_t, init_value_t>> init, size_type bucket_count, const hasher_t& hash, const allocator_type & alloc) : data_(xtd::new_ptr < data > (bucket_count)) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
            (*this)[key] = value;
          }
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns an iterator to the first element of the enumerable.
        /// @return Iterator to the first element.
        const_iterator begin() const noexcept override {return ienumerable < value_type >::begin();}
        /// @brief Returns an iterator to the first element of the enumerable.
        /// @return Iterator to the first element.
        iterator begin() noexcept override {return ienumerable < value_type >::begin();}
        
        /// @brief Gets the number of buckets in the container.
        /// @return The number of buckets in the container.
        /// @remarks xtd::collections::generic::dictionary::bucket_count and xtd::collections::generic::dictionary::capacity are equivalent properties.
        size_type bucket_count() const noexcept {return data_->items.bucket_count();}
        
        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        /// @remarks xtd::collections::generic::dictionary::capacity and xtd::collections::generic::dictionary::bucket_count are equivalent properties.
        size_type capacity() const noexcept {return bucket_count();}
        
        /// @brief Returns an iterator to the first element of the enumerable.
        /// @return Iterator to the first element.
        const_iterator cbegin() const noexcept override {return ienumerable < value_type >::cbegin();}
        
        /// @brief Returns an iterator to the element following the last element of the enumerable.
        /// @return Iterator to the element following the last element.
        const_iterator cend() const noexcept override {return ienumerable < value_type >::cend();}
        
        /// @brief Gets the td::collections::generic::iequality_comparer <type_t> that is used to determine equality of keys for the dictionary.
        /// @return The xtd::collections::generic::iequality_comparer <type_t> generic interface implementation that is used to determine equality of keys for the current xtd::collections::generic::dictionary <key_t, value_t> and to provide hash values for the keys.
        /// @remarks xtd::collections::generic::dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the td::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify one, the default generic equality comparer td::collections::generic::equality_comparer::default_equality_comparer is used.
        const iequality_comparer < key_t > & comparer() const noexcept {
          if (data_->comparer) return *data_->comparer;
          return equality_comparer < key_t >::default_equality_comparer();
        }
        
        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        size_type count() const noexcept override {return data_->items.size();}
        
        /// @brief Checks if the container has no elements, i.e. whether `begin() == end()`.
        /// @return `true` if the container is empty; otherwise `false`.
        bool empty() const noexcept {return data_->items.empty();}
        
        /// @brief Returns an iterator to the element following the last element of the enumerable.
        /// @return Iterator to the element following the last element.
        const_iterator end() const noexcept override {return ienumerable < value_type >::cend();}
        
        /// @brief Returns an iterator to the element following the last element of the enumerable.
        /// @return Iterator to the element following the last element.
        iterator end() noexcept override {return ienumerable < value_type >::end();}
        
        /// @brief Gets a value indicating whether the xtd::collections::generic::icollection <type_t> is read-only.
        /// @return `true` if the xtd::collections::generic::icollection <type_t> is read-only; otherwise, `false`.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::generic::icollection <type_t> interface only supports addition and removal operations. For example, the IsReadOnly property of an array that is cast or converted to an xtd::collections::generic::icollection <type_t> object returns `true`, even though individual array elements can be modified.
        bool is_read_only() const noexcept override {return false;}
        
        /// @brief Gets a value indicating whether access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe).
        /// @return `true` if access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe); otherwise, `false`.
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
        bool is_synchronized() const noexcept override {return false;}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual const base_type & items() const noexcept {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual base_type & items() noexcept {return data_->items;}
        
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
        const xtd::object & sync_root() const noexcept override {return data_->sync_root;}
        
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
        void add(const key_t & key, const value_t value) override {
          if (!try_add(key, value)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
        }
        
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        void add(const value_type & item) override {
          add(item.key(), item.value());
        }
        
        
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        const value_t& at(const key_t & key) const {
          auto iterator = data_->items.find(key);
          if (iterator == data_->items.end()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::key_not_found);
          return iterator->second;
        }
        
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        value_t& at(const key_t & key) {
          auto iterator = data_->items.find(key);
          if (iterator == data_->items.end()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::key_not_found);
          return iterator->second;
        }
        
        /// @brief Returns an iterator to the beginning of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the first element.
        /// @remarks Returns an iterator to the first element of the bucket with index `n`.
        local_iterator begin(size_type n) {
          return data_->items.begin(n);
        }
        
        /// @brief Returns an iterator to the beginning of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the first element.
        /// @remarks Returns an iterator to the first element of the bucket with index `n`.
        const_local_iterator begin(size_type n) const {
          return data_->items.begin(n);
        }
        
        /// @brief Returns the index of the bucket for key key. Elements (if any) with keys equivalent to key are always found in this bucket.
        /// @param key The value of the key to examine.
        /// @return Bucket index for the requested key.
        size_type bucket(const key_t & key) const {return data_->items.bucket(key);}
        
        /// @brief Returns the number of elements in the bucket with index `n`.
        /// @param n The index of the bucket to examine.
        /// @return The number of elements in the bucket `n`.
        size_type bucket_size(size_type n) const noexcept {return data_->items.bucket_size(n);}
        
        /// @brief Returns an iterator to the beginning of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the first element.
        /// @remarks Returns an iterator to the first element of the bucket with index `n`.
        const_local_iterator cbegin(size_type n) const {
          return data_->items.begin(n);
        }
        
        /// @brief Returns an iterator to the end of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the element following the last element.
        /// @remarks Returns an iterator to the element following the last element of the bucket with index `n`. This element acts as a placeholder, attempting to access it results in undefined behavior.
        const_local_iterator cend(size_type n) const {
          return data_->items.end(n);
        }
        
        /// @brief Removes all keys and values from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The xtd::collections::generic::dictionary::count property is set to 0, and references to other objects from elements of the collection are also released. The capacity remains unchanged.
        void clear() noexcept override {
          data_->items.clear();
          ++data_->version;
        }
        
        /// @brief Checks if the container contains element with specific key.
        /// @remarks Checks if there is an element with `key` equivalent to key in the container.
        bool contains(const key_t & key) const noexcept {
          return data_->items.find(key) != data_->items.end();
        }
        
        /// @brief Checks if the container contains element with specific key.
        /// @remarks Checks if there is an element with key that compares equivalent to the value `x`. This overload participates in overload resolution only if `hasher_t::is_transparent` and `equator_t::is_transparent` are valid and each denotes a type. This assumes that such `hasher_t` is callable with both `contains_key_t` and `key_t` type, and that the `equator_t` is transparent, which, together, allows calling this function without constructing an instance of `key_t`.
        template < class contains_key_t >
        bool contains(const contains_key_t& x) const {
          return data_->items.find(x) != data_->items.end();
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `item` ; otherwise, `false`.
        bool contains(const value_type & item) const noexcept override {
          auto iterator = find(item.key());
          if (iterator == end()) return false;
          return iterator->value() == item.value();
        }
        
        /// @brief Determines whether the xtd::collections::generic::dictionary <key_t, value_t> contains the specified key.
        /// @param The key to locate in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method approaches an O(1) operation.
        bool contains_key(const key_t & key) const noexcept override {
          return contains(key);
        }
        
        bool contains_value(const value_t& value) const noexcept {
          for (const auto& [item_key, item_value] : *this)
            if (item_value == value) return true;
          return false;
        }
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        void copy_to(xtd::array < value_type > & array, xtd::size array_index) const override {
          if (array_index + count() > array.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);;
          auto index = size_type {0};
          for (const auto& item : *this)
            array[array_index + index++] = item;
        }
        
        /// @brief Constructs element in-place.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks Inserts a new element into the container constructed in-place with the given args, if there is no element with the key in the container.
        /// @remarks The constructor of the new element (i.e. `std::pair<const key_t, value_t>)` is called with exactly the same arguments as supplied to emplace, forwarded via `std::forward<args_t>(args)....` The element may be constructed even if there already is an element with the key in the container, in which case the newly constructed element will be destroyed immediately (see xtd::collections::generic::dictionary::try_emplace if this behavior is undesirable).
        /// @remarks Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class ...args_t >
        key_value_pair < iterator, bool > emplace(args_t&& ...args) {
          const auto& [iterator, succeeded] = data_->items.emplace(std::forward < args_t > (args)...);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        
        /// @brief constructs elements in-place using a hint
        /// @param hint The iterator, used as a suggestion as to where to insert the new element.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts a new element into the container, using `hint` as a suggestion where the element should go.
        /// @remarks The constructor of the element type (value_type, that is, `std::pair<const key_t, value_t>`) is called with exactly the same arguments as supplied to the function, forwarded with `std::forward<args_t>(args)...`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class ...args_t >
        iterator emplace_hint(iterator hint, args_t&& ...args) {
          ++data_->version;
          return to_type_iterator(data_->items.emplace_hint(to_base_type_iterator(hint), std::forward < args_t > (args)...));
        }
        
        /// @brief Returns an iterator to the end of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the element following the last element.
        /// @remarks Returns an iterator to the element following the last element of the bucket with index `n`. This element acts as a placeholder, attempting to access it results in undefined behavior.
        local_iterator end(size_type n) {
          return data_->items.end(n);
        }
        
        /// @brief Returns an iterator to the end of the specified bucket.
        /// @param n The index of the bucket to access.
        /// @return Iterator to the element following the last element.
        /// @remarks Returns an iterator to the element following the last element of the bucket with index `n`. This element acts as a placeholder, attempting to access it results in undefined behavior.
        const_local_iterator end(size_type n) const {
          return data_->items.end(n);
        }
        
        /// @brief Ensures that the dictionary can hold up to a specified number of entries without any further expansion of its backing storage.
        /// @param capacity The number of entries.
        /// @return The current capacity of the xtd::collections::generic::dictionary <key_t, value_t>.
        xtd::size ensure_capacity(xtd::size capacity) noexcept {
          data_->items.reserve(capacity);
          return this->capacity();
        }
        
        /// @brief Returns range of elements matching a specific key.
        /// @param key The key value to compare the elements to.
        /// @return xtd::collections::generic::key_value_pair containing a pair of iterators defining the wanted range. If there are no such elements, past-the-end (see xtd::collections::generic::dictionary::end) iterators are returned as both elements of the pair.
        /// @remarks Returns a range containing all elements with key `key` in the container. The range is defined by two iterators, the first pointing to the first element of the wanted range and the second pointing past the last element of the range.
        key_value_pair < iterator, iterator > equal_range(const key_t & key) {
          const auto& [first, last] = data_->items.equal_range(key);
          return {to_type_iterator(first), to_type_iterator(last)};
        }
        
        /// @brief Returns range of elements matching a specific key.
        /// @param key The key value to compare the elements to.
        /// @return xtd::collections::generic::key_value_pair containing a pair of iterators defining the wanted range. If there are no such elements, past-the-end (see xtd::collections::generic::dictionary::end) iterators are returned as both elements of the pair.
        /// @remarks Returns a range containing all elements with key `key` in the container. The range is defined by two iterators, the first pointing to the first element of the wanted range and the second pointing past the last element of the range.
        template < class equal_range_key_t >
        key_value_pair < const_iterator, const_iterator > equal_range(const equal_range_key_t& key) const {
          const auto& [first, last] = data_->items.equal_range(key);
          return {to_const_type_iterator(first), to_const_type_iterator(last)};
        }
        
        /// @brief Returns range of elements matching a specific key.
        /// @param x A value of any type that can be transparently compared with a key.
        /// @return xtd::collections::generic::key_value_pair containing a pair of iterators defining the wanted range. If there are no such elements, past-the-end (see xtd::collections::generic::dictionary::end) iterators are returned as both elements of the pair.
        /// @remarks Returns a range containing all elements in the container with key equivalent to `x`. This overload participates in overload resolution only if `hasher_t::is_transparent` and `equator_t::is_transparent` are valid and each denotes a type. This assumes that such Hash is callable with both `equal_range_key_t` and `key_t` type, and that the `equator_t` is transparent, which, together, allows calling this function without constructing an instance of `equal_range_key_t`.
        template < class equal_range_key_t >
        key_value_pair < iterator, iterator > equal_range(const equal_range_key_t& x) {
          const auto& [first, last] = data_->items.equal_range(x);
          return {to_type_iterator(first), to_type_iterator(last)};
        }
        
        /// @brief Returns range of elements matching a specific key.
        /// @param x A value of any type that can be transparently compared with a key.
        /// @return xtd::collections::generic::key_value_pair containing a pair of iterators defining the wanted range. If there are no such elements, past-the-end (see xtd::collections::generic::dictionary::end) iterators are returned as both elements of the pair.
        /// @remarks Returns a range containing all elements in the container with key equivalent to `x`. This overload participates in overload resolution only if `hasher_t::is_transparent` and `equator_t::is_transparent` are valid and each denotes a type. This assumes that such Hash is callable with both `equal_range_key_t` and `key_t` type, and that the `equator_t` is transparent, which, together, allows calling this function without constructing an instance of `key_t`.
        key_value_pair < const_iterator, const_iterator > equal_range(const key_t & x) const {
          const auto& [first, last] = data_->items.equal_range(x);
          return {to_const_type_iterator(first), to_const_type_iterator(last)};
        }
        
        /// @brief Erases elements.
        /// @param pos The iterator to the element to remove.
        /// @return The iterator following the last removed element.
        /// @remarks Removes specified elements from the container. The order of the remaining elements is preserved. (This makes it possible to erase individual elements while iterating through the container.)
        /// @remarks Removes the element at `pos`.
        /// @remarks References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
        /// @remarks The iterator `pos` must be valid and dereferenceable. Thus the xtd::collections::generic::dictionary::end iterator (which is valid, but is not dereferenceable) cannot be used as a value for `pos`.
        iterator erase(const_iterator pos) {
          ++data_->version;
          return to_type_iterator(data_->items.erase(to_const_base_type_iterator(pos)));
        }
        /// @brief Erases elements.
        /// @param first The first iterator of the range of elements to remove.
        /// @param last The last iterator of the range of elements to remove.
        /// @return The iterator following the last removed element.
        /// @remarks Removes specified elements from the container. The order of the remaining elements is preserved. (This makes it possible to erase individual elements while iterating through the container.)
        /// @remarks Removes the elements in the range [`first`, `last`), which must be a valid range in `*this`.
        /// @remarks References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
        /// @remarks The iterator `pos` must be valid and dereferenceable. Thus the xtd::collections::generic::dictionary::end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for `pos`.
        iterator erase(const_iterator first, const_iterator last) {
          ++data_->version;
          return to_type_iterator(data_->items.erase(to_const_base_type_iterator(first), to_const_base_type_iterator(last)));
        }
        /// @brief Erases elements.
        /// @param key The key value of the elements to remove.
        /// @return The number of elements removed (0 or 1).
        /// @remarks Removes specified elements from the container. The order of the remaining elements is preserved. (This makes it possible to erase individual elements while iterating through the container.)
        /// @remarks Removes the element (if one exists) with the key equivalent to `key`.
        /// @remarks References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
        /// @remarks The iterator `pos` must be valid and dereferenceable. Thus the xtd::collections::generic::dictionary::end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for `pos`.
        size_type erase(const key_t & key) {
          auto removed_count = data_->items.erase(key);
          if (removed_count) ++data_->version;
          return removed_count;
        }
        
        /// @brief Extracts nodes from the container.
        /// @param position A valid iterator into this container.
        /// @return A [node handle](https://en.cppreference.com/w/cpp/container/node_handle) that owns the extracted element, or empty node handle in case the element is not found in.
        /// @remarks Unlinks the node that contains the element pointed to by position and returns a [node handle](https://en.cppreference.com/w/cpp/container/node_handle) that owns it.
        /// @remarks In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed.
        /// @remarks Extracting a node invalidates only the iterators to the extracted element, and preserves the relative order of the elements that are not erased. Pointers and references to the extracted element remain valid, but cannot be used while element is owned by a node handle: they become usable if the element is inserted into a container.
        node_type extract(const_iterator position) noexcept {
          ++data_->version;
          return data_->items.extract(to_const_base_type_iterator(position));
        }
        /// @brief Extracts nodes from the container.
        /// @param k A key to identify the node to be extracted.
        /// @return A [node handle](https://en.cppreference.com/w/cpp/container/node_handle) that owns the extracted element, or empty node handle in case the element is not found in.
        /// @remarks If the container has an element with key equivalent to k, unlinks the node that contains that element from the container and returns a [node handle](https://en.cppreference.com/w/cpp/container/node_handle) that owns it. Otherwise, returns an empty node handle.
        /// @remarks In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed.
        /// @remarks Extracting a node invalidates only the iterators to the extracted element, and preserves the relative order of the elements that are not erased. Pointers and references to the extracted element remain valid, but cannot be used while element is owned by a node handle: they become usable if the element is inserted into a container.
        node_type extract(const key_t k) {
          ++data_->version;
          return data_->items.extract(k);
        }
        
        /// @brief Finds element with specific key.
        /// @param key The key value of the element to search for.
        /// @return An iterator to the requested element. If no such element is found, past-the-end (see xtd::collections::generic::dictionary::end) iterator is returned.
        /// @remarks Finds an element with key equivalent to `key`.
        const_iterator find(const key_t & key) const {
          return to_const_type_iterator(data_->items.find(key));
        }
        
        /// @brief Finds element with specific key.
        /// @param key The key value of the element to search for.
        /// @return An iterator to the requested element. If no such element is found, past-the-end (see xtd::collections::generic::dictionary::end) iterator is returned.
        /// @remarks Finds an element with key equivalent to `key`.
        iterator find(const key_t & key) {
          return to_type_iterator(data_->items.find(key));
        }
        
        /// @brief Finds element with specific key.
        /// @param x A value of any type that can be transparently compared with a key.
        /// @return An iterator to the requested element. If no such element is found, past-the-end (see xtd::collections::generic::dictionary::end) iterator is returned.
        /// @remarks Finds an element with key that compares equivalent to the value `x`. This overload participates in overload resolution only if `hasher_t::is_transparent` and `equator_t::is_transparent` are valid and each denotes a type. This assumes that such `hasher_t` is callable with both `find_key_t` and `key_t` type, and that the `equator_t` is transparent, which, together, allows calling this function without constructing an instance of `key_t`.
        template < class find_key_t >
        const_iterator find(const find_key_t& x) const {
          return to_const_type_iterator(data_->items.find(x));
        }
        
        /// @brief Finds element with specific key.
        /// @param x A value of any type that can be transparently compared with a key.
        /// @remarks Finds an element with key that compares equivalent to the value `x`. This overload participates in overload resolution only if `hasher_t::is_transparent` and `equator_t::is_transparent` are valid and each denotes a type. This assumes that such `hasher_t` is callable with both `find_key_t` and `key_t` type, and that the `equator_t` is transparent, which, together, allows calling this function without constructing an instance of `key_t`.
        template < class find_key_t >
        iterator find(const find_key_t& x) {
          return to_type_iterator(data_->items.find(x));
        }
        
        /// @brief Returns the allocator associated with the container.
        /// @return The associated allocator.
        allocator_type get_allocator() const noexcept {return data_->items.get_allocator();}
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return A xtd::collections::enumerator structure for the xtd::collections::generic::dictionary <key_t, value_t>.
        enumerator < value_type > get_enumerator() const noexcept override {
          struct internal_enumerator : public ienumerator < value_type > {
          public:
            explicit internal_enumerator(const dictionary & items, size_type version) : items_(items), version_(version) {}
            
            const value_type & current() const override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              if (iterator_ != items_.items().cend()) {
                static thread_local auto value = value_type {};
                value = value_type {*iterator_};
                return value;
              }
              static auto default_value_type = value_type {};
              return default_value_type;
            }
            
            bool move_next() override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
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
          return {new_ptr < internal_enumerator > (*this, data_->version)};
        }
        
        /// @brief Returns function used to hash the keys.
        /// @return The hash function.
        /// @remarks Returns the function that hashes the keys.
        hasher hash_function() const {
          return data_->items.hash_function();
        }
        
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        key_value_pair < iterator, bool > insert(const value_type & value) {
          const auto& [iterator, succeeded] = data_->items.insert(value);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        key_value_pair < iterator, bool > insert(value_type&& value) {
          const auto& [iterator, succeeded] = data_->items.insert(value);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param value The element value to insert.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks Inserts `value`.
        /// @remarks Is equivalent to `emplace(std::forward<P>(value))` and only participates in overload resolution if `std::is_constructible<value_type, P&&>::value == true`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class type_t >
        key_value_pair < iterator, bool > insert(type_t&& value) {
          const auto& [iterator, succeeded] = data_->items.insert(value);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        iterator insert(const_iterator hint, const value_type & value) {
          ++data_->version;
          return to_type_iterator(data_->items.insert(to_const_base_type_iterator(hint), value));
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        iterator insert(const_iterator hint, value_type&& value) {
          ++data_->version;
          return to_type_iterator(data_->items.insert(to_const_base_type_iterator(hint), value));
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param value The element value to insert.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks Inserts `value`, using `hint` as a non-binding suggestion to where the search should start.
        /// @remarks Is equivalent to `emplace_hint(hint, std::forward<P>(value))` and only participates in overload resolution if `std::is_constructible<value_type, P&&>::value == true`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class type_t >
        iterator insert(const_iterator hint, type_t&& value) {
          ++data_->version;
          return to_type_iterator(data_->items.insert(to_const_base_type_iterator(hint), value));
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param first The first iterator of the range of elements to insert.
        /// @param last The last iterator of the range of elements to insert.
        /// @remarks Inserts elements from range [`first`, `last`). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844)).
        /// @remarks If [`first`, `last`) is not a valid range, or `first` and/or `last` are iterators into `*this`, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class input_iterator_t >
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
        void insert(std::initializer_list < base_value_type > ilist) {
          for (const auto& [key, value] : ilist)
            add(std::forward < value_type > ({key, value}));
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param ilist The initializer list to insert the values from.
        /// @remarks Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted (pending [LWG2844](https://cplusplus.github.io/LWG/issue2844)).
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        template < class init_key_t, class init_value_t >
        void insert(std::initializer_list < key_value_pair < init_key_t, init_value_t>> ilist) {
          for (const auto& [key, value] : ilist)
            add(std::forward < value_type > ({key, value}));
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param nh A compatible [node handle](https://en.cppreference.com/w/cpp/container/node_handle).
        /// @return An object of xtd::collections::generic::dictionary::insert_return_type with the members initialized as follows:
        ///  * If `nh` is empty, inserted is `false`, position is xtd::collections::generic::dictionary::end, and node is empty.
        ///  * Otherwise if the insertion took place, inserted is `true`, position points to the inserted element, and node is empty.
        ///  * If the insertion failed, inserted is `false`, node has the previous value of `nh`, and position points to an element with a key equivalent to `nh.key()`.
        /// @remarks If `nh` is an empty [node handle](https://en.cppreference.com/w/cpp/container/node_handle), does nothing. Otherwise, inserts the element owned by nh into the container , if the container doesn't already contain an element with a key equivalent to `nh.key()`. The behavior is undefined if `nh` is not empty and `get_allocator() != nh.get_allocator()`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        insert_return_type insert(node_type&& nh) {
          ++data_->version;
          return data_->items.inser(nh);
        }
        /// @brief Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
        /// @param hint The iterator, used as a suggestion as to where to insert the content.
        /// @param nh A compatible [node handle](https://en.cppreference.com/w/cpp/container/node_handle).
        /// @return End iterator if `nh` was empty, iterator pointing to the inserted element if insertion took place, and iterator pointing to an element with a key equivalent to `nh.key()` if it failed.
        /// @remarks If `nh` is an empty [node handle](https://en.cppreference.com/w/cpp/container/node_handle), does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the container, if the container doesn't already contain an element with a key equivalent to `nh.key()`, and returns the iterator pointing to the element with key equivalent to `nh.key()`(regardless of whether the insert succeeded or failed). If the insertion succeeds, `nh` is moved from, otherwise it retains ownership of the element. `hint` is used as a non-binding suggestion to where the search should start. The behavior is undefined if `nh` is not empty and `get_allocator() != nh.get_allocator()`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated. If the insertion is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        iterator insert(const_iterator hint, node_type&& nh) {
          ++data_->version;
          return to_type_iterator(data_->items.inser(to_const_base_type_iterator(hint), nh));
        }
        
        /// @brief Inserts an element or assigns to the current element if the key already exists.
        /// @param k The key used both to look up and to insert if not found.
        /// @param obj The value to insert or assign.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks If a key equivalent to `k` already exists in the container, assigns `std::forward<type_t>(obj)` to the xtd::collections::generic::dictionary::mapped_type corresponding to the key `k`. If the key does not exist, inserts the new value as if by xtd::collections::generic::dictionary::insert, constructing it from `value_type(k, std::forward<type_t>(obj))`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class type_t >
        key_value_pair < iterator, bool > insert_or_assign(const key_t & k, type_t&& obj) {
          const auto& [iterator, succeeded] = data_->items.insert_or_assign(k, obj);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts an element or assigns to the current element if the key already exists.
        /// @param k The key used both to look up and to insert if not found.
        /// @param obj The value to insert or assign.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks If a key equivalent to `k` already exists in the container, assigns `std::forward<type_t>(obj)` to the xtd::collections::generic::dictionary::mapped_type corresponding to the key `k`. If the key does not exist, inserts the new value as if by xtd::collections::generic::dictionary::insert, constructing it from `value_type(k, std::forward<type_t>(obj))`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class type_t >
        key_value_pair < iterator, bool > insert_or_assign(key_t&& k, type_t&& obj) {
          const auto& [iterator, succeeded] = data_->items.insert_or_assign(std::move(k), obj);
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts an element or assigns to the current element if the key already exists.
        /// @param hint The iterator to the position before which the new element will be inserted.
        /// @param k The key used both to look up and to insert if not found.
        /// @param obj The value to insert or assign.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks If a key equivalent to `k` already exists in the container, assigns `std::forward<type_t>(obj)` to the xtd::collections::generic::dictionary::mapped_type corresponding to the key `k`. If the key does not exist, inserts the new value as if by xtd::collections::generic::dictionary::insert, constructing it from `value_type(k, std::forward<type_t>(obj))`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class type_t >
        iterator insert_or_assign(const_iterator hint, const key_t & k, type_t&& obj) {
          ++data_->version;
          return to_type_iterator(data_->items.insert_or_assign(to_const_base_type_iterator(hint), k, obj));
        }
        /// @brief Inserts an element or assigns to the current element if the key already exists.
        /// @param hint The iterator to the position before which the new element will be inserted.
        /// @param k The key used both to look up and to insert if not found.
        /// @param obj The value to insert or assign.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks If a key equivalent to `k` already exists in the container, assigns `std::forward<type_t>(obj)` to the xtd::collections::generic::dictionary::mapped_type corresponding to the key `k`. If the key does not exist, inserts the new value as if by xtd::collections::generic::dictionary::insert, constructing it from `value_type(k, std::forward<type_t>(obj))`.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class type_t >
        iterator insert_or_assign(const_iterator hint, key_t&& k, type_t&& obj) {
          ++data_->version;
          return to_type_iterator(data_->items.insert_or_assign(to_const_base_type_iterator(hint), std::move(k), obj));
        }
        
        /// @brief Returns the function used to compare keys for equality.
        /// @return The key comparison function.
        /// @remarks Returns the function that compares keys for equality.
        key_equal key_eq() const {
          return data_->items.key_eq();
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(dictionary < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > & source) {
          data_->items.merge(source.items);
          ++data_->version;
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(dictionary < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > && source) {
          data_->items.merge(std::move(source.items));
          ++data_->version;
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(std::unordered_map < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > & source) {
          data_->items.merge(source);
          ++data_->version;
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(std::unordered_map < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > && source) {
          data_->items.merge(std::move(source));
          ++data_->version;
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(std::unordered_multimap < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > & source) {
          data_->items.merge(source);
          ++data_->version;
        }
        
        /// @brief Splices nodes from another container.
        /// @param source A compatible container to transfer the nodes from.
        /// @remarks Attempts to extract ("splice") each element in `source` and insert it into `*this` using the hash function and key equality predicate of `*this`. If there is an element in `*this` with key equivalent to the key of an element from `source`, then that element is not extracted from `source`. No elements are copied or moved, only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into `*this`, not into `source`. Iterators referring to the transferred elements and all iterators referring to `*this` are invalidated. Iterators to elements remaining in `source` remain valid.
        /// @remarks The behavior is undefined if `get_allocator() != source.get_allocator()`.
        template < class source_hasher_t, class source_equator_t >
        void merge(std::unordered_multimap < key_t, value_t, source_hasher_t, source_equator_t, allocator_t > && source) {
          data_->items.merge(std::move(source));
          ++data_->version;
        }
        
        /// @brief Reserves at least the specified number of buckets and regenerates the hash table.
        /// @param count The lower bound for the new number of buckets.
        /// @remarks Changes the number of buckets to a value n that is not less than `count` and satisfies `n >= size() / max_load_factor()`, then rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed.
        /// @note `rehash(0)` may be used to force an unconditional rehash, such as after suspension of automatic rehashing by temporarily increasing `max_load_factor()`.
        void rehash(size_type count) {
          data_->items.rehash(count);
        }
        
        /// @brief Removes the value with the specified key from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param key The key of the element to remove.
        /// @return `true` if the element is successfully found and removed; otherwise, `false`. This method returns `false` if key is not found in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks If the xtd::collections::generic::dictionary <key_t, value_t> does not contain an element with the specified key, the xtd::collections::generic::dictionary <key_t, value_t> remains unchanged. No exception is thrown.
        bool remove(const key_t & key) noexcept override {
          return erase(key) == 1;
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to remove from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item value was not found in the xtd::collections::generic::dictionary <key_t, value_t>.
        bool remove(const value_type & item) noexcept override {
          if (!contains_value(item.value())) return false;
          return erase(item.key()) == 1;
        }
        
        /// @brief Removes the value with the specified key from the xtd::collections::generic::dictionary <key_t, value_t>, and copies the element to the `value` parameter.
        /// @param key The key of the element to remove.
        /// @param value The removed element.
        bool remove(const key_t & key, value_t& value) noexcept {
          auto iterator = find(key);
          if (iterator == end()) return false;
          value = iterator->value();
          return erase(iterator) != end();
        }
        
        /// @brief Reserves space for at least the specified number of elements and regenerates the hash table.
        /// @param count The new capacity of the container.
        /// @remarks Sets the number of buckets to the number needed to accommodate at least `count` elements without exceeding maximum load factor and rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed. Effectively calls `rehash(std::ceil(count / max_load_factor()))`.
        void reserve(size_type count) {
          data_->items.reserve(count);
        }
        
        /// @brief Swaps the contents.
        /// @param The container to exchange the contents with.
        /// @remarks Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
        /// @remarks All iterators and references remain valid. The xtd::collections::generic::dictionary::end iterator is invalidated. The `hasher_t` and `equator_t` objects must be [Swappable](https://en.cppreference.com/w/cpp/named_req/Swappable), and they are exchanged using unqualified calls to non-member swap.
        void swap(dictionary & other) noexcept {
          data_->items.swap(other.data_->items);
          std::swap(data_->version, other.data_->version);
        }
        
        /// @brief Gets a string that represents the current object.
        /// @return A string that represents the current object.
        xtd::string to_string() const noexcept override {return xtd::string::format("{{{}}}", xtd::string::join(", ", *this));}
        
        /// @brief Sets the capacity of this dictionary to hold up a specified number of entries without any further expansion of its backing storage.
        /// @param capacity The new capacity.
        /// @exception xtd::argument_out_of_range_exception `capacity` is less than xtd::collections::generic::dictionary::count.
        /// @remarks This method can be used to minimize the memory overhead once it is known that no new elements will be added.
        void trim_excess(size_type capacity) {
          if (capacity < count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);;
          rehash(capacity);
        }
        
        /// @brief Sets the capacity of this dictionary to what it would be if it had been originally initialized with all its entries.
        /// @remarks This method can be used to minimize memory overhead once it is known that no new elements will be added to the dictionary. To allocate a minimum size storage array, execute the following statements:
        /// ```
        /// dictionary.clear();
        /// dictionary.trim_excess();
        /// ```
        void trim_excess() {
          rehash(count());
        }
        
        /// @brief Attempts to add the specified key and value to the dictionary.
        /// @param key The key of the element to add.
        /// @param value The value of the element to add.
        /// @return `true` if the key/value pair was added to the dictionary successfully; otherwise, `false`.
        /// @remarks Unlike the xtd::collections::generic::dictionary::add method, this method doesn't throw an exception if the element with the given key exists in the dictionary. Unlike the xtd::collections::generic::dictionary indexer (operator []), xtd::collections::generic::dictionary::try_add doesn't override the element if the element with the given key exists in the dictionary. If the key already exists, xtd::collections::generic::dictionary::try_add does nothing and returns `false`.
        bool try_add(const key_t & key, const value_t value) noexcept {
          const auto& [iterator, succeeded] = data_->items.insert(std::forward < base_value_type > ({key, value}));
          if (succeeded) ++data_->version;
          return succeeded;
        }
        
        /// @brief Inserts in-place if the key does not exist, does nothing if the key exists.
        /// @param k The key used both to look up and to insert if not found.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks If value_type is not [EmplaceConstructible](https://en.cppreference.com/w/cpp/named_req/EmplaceConstructible) into unordered_map from the corresponding expression, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class ...args_t >
        key_value_pair < iterator, bool > try_emplace(const key_t & k, args_t&&... args) {
          const auto& [iterator, succeeded] = to_type_iterator(data_->items.try_emplace(k, std::forward < args_t > (args)...));
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts in-place if the key does not exist, does nothing if the key exists.
        /// @param k The key used both to look up and to insert if not found.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return A pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool value set to `true` if and only if the insertion took place.
        /// @remarks If value_type is not [EmplaceConstructible](https://en.cppreference.com/w/cpp/named_req/EmplaceConstructible) into unordered_map from the corresponding expression, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class ...args_t >
        key_value_pair < iterator, bool > try_emplace(key_t&& k, args_t&&... args) {
          const auto& [iterator, succeeded] = to_type_iterator(data_->items.try_emplace(std::move(k), std::forward < args_t > (args)...));
          if (succeeded) ++data_->version;
          return {to_type_iterator(iterator), succeeded};
        }
        /// @brief Inserts in-place if the key does not exist, does nothing if the key exists.
        /// @param hint The iterator to the position before which the new element will be inserted.
        /// @param k The key used both to look up and to insert if not found.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks If value_type is not [EmplaceConstructible](https://en.cppreference.com/w/cpp/named_req/EmplaceConstructible) into unordered_map from the corresponding expression, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class ...args_t >
        iterator try_emplace(const_iterator hint, const key_t & k, args_t&&... args) {
          ++data_->version;
          return to_type_iterator(data_->items.try_emplace(to_const_base_type_iterator(hint), k, std::forward < args_t > (args)...));
        }
        /// @brief Inserts in-place if the key does not exist, does nothing if the key exists.
        /// @param hint The iterator to the position before which the new element will be inserted.
        /// @param k The key used both to look up and to insert if not found.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return An iterator to the inserted element, or to the element that prevented the insertion.
        /// @remarks If value_type is not [EmplaceConstructible](https://en.cppreference.com/w/cpp/named_req/EmplaceConstructible) into unordered_map from the corresponding expression, the behavior is undefined.
        /// @remarks If after the operation the new number of elements is greater than old xtd::collections::generic::dictionary::max_load_factor * xtd::collections::generic::dictionary::bucket_count a rehashing takes place.
        /// @remarks If rehashing occurs (due to the insertion), all iterators are invalidated. Otherwise (no rehashing), iterators are not invalidated.
        template < class ...args_t >
        iterator try_emplace(const_iterator hint, key_t&& k, args_t&&... args) {
          ++data_->version;
          return to_type_iterator(data_->items.try_emplace(to_const_base_type_iterator(hint), std::move(k), std::forward < args_t > (args)...));
        }
        
        /// @brief Gets the value associated with the specified key.
        /// @param key The key of the value to get.
        /// @param value When this method returns, contains the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified key; otherwise, `false`.
        bool try_get_value(const key_t & key, value_t& value) const override {
          auto iterator = find(key);
          if (iterator != end()) {
            value = iterator->value();
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
        dictionary& operator =(dictionary&& other) noexcept {
          data_->comparer = std::move(other.data_->comparer);
          data_->items = std::move(other.data_->items);
          data_->version = std::move(other.data_->version);
          return *this;
        }
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(std::unordered_map < key_t, value_t > && other) noexcept {
          data_->items = std::move(other);
          ++data_->version;
          return *this;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(const dictionary & other) noexcept = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        dictionary& operator =(const std::unordered_map < key_t, value_t > & other) noexcept {
          data_->items.clear();
          for (const auto& [key, value] : other)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        dictionary& operator =(std::initializer_list < base_value_type > ilist) {
          data_->items.clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        template < class init_key_t, class init_value_t >
        dictionary& operator =(std::initializer_list < key_value_pair < init_key_t, init_value_t>> ilist) {
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
        const value_t& operator [](const key_t & key) const override {return at(key);}
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::dictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::dictionary::add method does not modify existing elements.
        value_t& operator [](const key_t & key) override {
          ++data_->version;
          return data_->items[key];}
          
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type & () const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type & () noexcept {return data_->items;}
        /// @}
        
      private:
        typename base_type::const_iterator to_const_base_type_iterator(const_iterator value) const noexcept {
          return idictionary < key_t, value_t >::to_const_iterator(value, *this, data_->items);
        }
        
        const_iterator to_const_type_iterator(typename base_type::const_iterator value) const noexcept {
          return idictionary < key_t, value_t >::to_const_iterator(value, data_->items, *this);
        }
        
        typename base_type::const_iterator to_base_type_iterator(const_iterator value) const noexcept {
          return idictionary < key_t, value_t >::to_iterator(value, *this, data_->items);
        }
        
        typename base_type::iterator to_base_type_iterator(iterator value) noexcept {
          return idictionary < key_t, value_t >::to_iterator(value, *this, data_->items);
        }
        
        const_iterator to_type_iterator(typename base_type::const_iterator value) const noexcept {
          return idictionary < key_t, value_t >::to_iterator(value, data_->items, *this);
        }
        
        iterator to_type_iterator(typename base_type::iterator value) noexcept {
          return idictionary < key_t, value_t >::to_iterator(value, data_->items, *this);
        }
        
        struct data {
          data() : items {size_type {}, hasher {}, equator {}, allocator_type {}} {}
          data(ptr < iequality_comparer < key_t>> comparer) : comparer {comparer},  items {size_type {}, hasher {comparer.get()}, equator {comparer.get()}, allocator_type {}} {}
          data(size_type bucket_count) noexcept : items {bucket_count, hasher {}, equator {}, allocator_type {}} {}
          data(ptr < iequality_comparer < key_t>> comparer, const base_type & items, size_type version) noexcept : comparer {comparer}, items {size_type {}, hasher {comparer.get()}, equator {comparer.get()}, allocator_type {}}, version {version} {
            for (const auto& item : items)
              this->items.insert(item);
          }
          data(base_type&& items, size_type version) noexcept : items {size_type {}, hasher {}, equator {}, allocator_type {}}, version {version} {
            for (auto&& item : items)
              this->items.insert(item);
          }
          
          ptr < iequality_comparer < key_t>> comparer;
          base_type items;
          size_type version = 0;
          xtd::object sync_root;
        };
        xtd::ptr < data > data_ = xtd::new_ptr < data > ();
      };
      
      /// @cond
      // C++17 deduction guides for xtd::collections::generic::dictionary
      // {
      template < class key_t, class value_t >
      dictionary(idictionary < key_t, value_t >) -> dictionary < key_t, value_t, helpers::hasher<key_t>, helpers::equator<key_t>, helpers::allocator < std::pair < const key_t, value_t >>>;
      
      template < class key_t, class value_t >
      dictionary(ienumerable < key_value_pair < key_t, value_t>>) -> dictionary<key_t, value_t, helpers::hasher<key_t>, helpers::equator<key_t >, helpers::allocator < std::pair < const key_t, value_t >>>;
      
      template < class key_t, class value_t, class hasher_t = helpers::hasher < key_t>, class equator_t = helpers::equator<key_t>, class allocator_t = helpers::allocator<std::pair < const key_t, value_t >>>
      dictionary(std::initializer_list < key_value_pair < key_t, value_t>>, xtd::size = 0, hasher_t = hasher_t {}, equator_t = equator_t {}, allocator_t = allocator_t {}) -> dictionary < key_t, value_t, hasher_t, equator_t, allocator_t >;
      
      template < class key_t, class value_t, class allocator_t >
      dictionary(std::initializer_list < key_value_pair < key_t, value_t>>, xtd::size, allocator_t) -> dictionary<key_t, value_t, helpers::hasher<key_t >, helpers::equator < key_t >, allocator_t >;
      
      template < class key_t, class value_t, class allocator_t >
      dictionary(std::initializer_list < key_value_pair < key_t, value_t>>, allocator_t) -> dictionary<key_t, value_t, helpers::hasher<key_t >, helpers::equator < key_t >, allocator_t >;
      
      template < class key_t, class value_t, class hasher_t, class allocator_t >
      dictionary(std::initializer_list < key_value_pair < key_t, value_t>>, xtd::size, hasher_t, allocator_t) -> dictionary<key_t, value_t, hasher_t, helpers::equator < key_t >, allocator_t >;
      
      template < class key_t, class value_t, class hasher_t = helpers::hasher < key_t>, class equator_t = helpers::equator<key_t>, class allocator_t = helpers::allocator<std::pair < const key_t, value_t >>>
      dictionary(std::initializer_list < std::pair < key_t, value_t>>, xtd::size bucket_count = 0, hasher_t = hasher_t {}, equator_t = equator_t {}, allocator_t = allocator_t {}) -> dictionary < key_t, value_t, hasher_t, equator_t, allocator_t >;
      
      template < class key_t, class value_t, class allocator_t >
      dictionary(std::initializer_list < std::pair < key_t, value_t>>, xtd::size, allocator_t) -> dictionary<key_t, value_t, helpers::hasher<key_t >, helpers::equator < key_t >, allocator_t >;
      
      template < class key_t, class value_t, class allocator_t >
      dictionary(std::initializer_list < std::pair < key_t, value_t>>, allocator_t) -> dictionary<key_t, value_t, helpers::hasher<key_t >, helpers::equator < key_t >, allocator_t >;
      
      template < class key_t, class value_t, class hasher_t, class allocator_t >
      dictionary(std::initializer_list < std::pair < key_t, value_t>>, xtd::size, hasher_t, allocator_t) -> dictionary<key_t, value_t, hasher_t, helpers::equator < key_t >, allocator_t >;
      
      template < class input_iterator_t, class hasher_t = helpers::hasher < helpers::iterator_key_t<input_iterator_t>>, class equator_t = helpers::equator<helpers::iterator_key_t<input_iterator_t>>, class allocator_t = helpers::allocator < helpers::iterator_to_allocator_t < input_iterator_t >>>
      dictionary(input_iterator_t, input_iterator_t, xtd::size = 0, hasher_t = hasher_t {}, equator_t = equator_t {}, allocator_t = allocator_t {}) -> dictionary < helpers::iterator_key_t < input_iterator_t>, helpers::iterator_mapped_t<input_iterator_t >, hasher_t, equator_t, allocator_t >;
      
      template < class input_iterator_t, class allocator_t >
      dictionary(input_iterator_t, input_iterator_t, xtd::size, allocator_t) -> dictionary < helpers::iterator_key_t < input_iterator_t>, helpers::iterator_mapped_t<input_iterator_t>, helpers::hasher<helpers::iterator_key_t<input_iterator_t>>, helpers::equator < helpers::iterator_key_t < input_iterator_t >>, allocator_t >;
      
      template < class input_iterator_t, class allocator_t >
      dictionary(input_iterator_t, input_iterator_t, allocator_t) -> dictionary < helpers::iterator_key_t < input_iterator_t>, helpers::iterator_mapped_t<input_iterator_t>, helpers::hasher<helpers::iterator_key_t<input_iterator_t>>, helpers::equator < helpers::iterator_key_t < input_iterator_t >>, allocator_t >;
      
      template < class input_iterator_t, class hasher_t, class allocator_t >
      dictionary(input_iterator_t, input_iterator_t, xtd::size, hasher_t, allocator_t) -> dictionary < helpers::iterator_key_t < input_iterator_t>, helpers::iterator_mapped_t<input_iterator_t>, hasher_t, helpers::equator<helpers::iterator_key_t < input_iterator_t >>, allocator_t >;
      // }
      /// @endcond
    }
  }
}
