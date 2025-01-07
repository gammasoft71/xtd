/// @file
/// @brief Contains xtd::collections::generic::dictionary struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
#include "idictionary.hpp"
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
      /// template<typename key_t, typename value_t>
      /// using dictionary = std::unordered_map<key_t, value_t, helpers::hasher<key_t>, helpers::equator<key_t>, helpers::allocator<std::pair<const key_t, value_t>>>;
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
      template<typename key_t, typename value_t, typename hasher_t = xtd::collections::generic::helpers::hasher<key_t>, typename equator_t = xtd::collections::generic::helpers::equator<key_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      class dictionary : public xtd::collections::generic::idictionary<key_t, value_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = key_t;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = value_t;
        /// @brief Represents the dictionary value type.
        using value_type = xtd::collections::generic::key_value_pair<key_t, value_t>;
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
        using pointer = std::allocator_traits<allocator_t>::pointer;
        /// @brief Represents the dictionary const pointer type.
        using const_pointer = std::allocator_traits<allocator_t>::const_pointer;
        /// @brief Represents the iterator of dictionary value type.
        using iterator = typename xtd::collections::generic::icollection<value_type>::iterator;
        /// @brief Represents the const iterator of dictionary value type.
        using const_iterator = typename xtd::collections::generic::icollection<value_type>::const_iterator;
        /// @brief Represents the local iterator of dictionary value type.
        using local_iterator = typename base_type::local_iterator;
        /// @brief Represents the const local iterator of dictionary value type.
        using const_local_iterator = typename base_type::const_local_iterator;
        /// @brief Represents the dictionary node type.
        using node_type = typename base_type::node_type;
        /// @brief Represents the dictionary insert return type.
        using insert_return_type = typename base_type::insert_return_type;
        /// @}

        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the dictionary <key_t, value_t> class that is empty, has the default initial capacity, and uses the default equality comparer for the key type.
        /// @remarks Every key in a dictionary <key_t, value_t> must be unique according to the default equality comparer.
        /// @remarks dictionary <key_t, value_t> requires an equality implementation to determine whether keys are equal. This constructor uses the default generic equality comparer, equality_comparer::default. If type `key_t` implements the xtd::equatable <type_t> generic interface, the default equality comparer uses that implementation. Alternatively, you can specify an implementation of the iequality_comparer <typer_t> generic interface by using a constructor that accepts a comparer parameter.
        /// @note If you can estimate the size of the collection, using a constructor that specifies the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the dictionary <key_t, value_t>.
        /// @remarks This constructor is an O(1) operation.
        /// @par Exemples
        /// The following code example creates an empty dictionary <key_t, value_t> of strings with string keys and uses the Add method to add some elements. The example demonstrates that the dictionary::add method throws an xtd::argument_exception when attempting to add a duplicate key.
        ///
        /// This code example is part of a larger example provided for the dictionary <key_t, value_t> class.
        /// ```
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
        /// @}

        /// @name Public Properties
        
        /// @{
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @}

      private:
        struct data {
          base_type items;
          size_type version = 0;
          xtd::object sync_root;
        };
        xtd::ptr<data> data_ = xtd::new_ptr<data>();
      };
    }
  }
}
