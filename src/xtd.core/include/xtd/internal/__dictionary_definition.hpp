/// @file
/// @brief Contains string definitions.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include <unordered_map>
#define __XTD_STD_INTERNAL__
#include "../collections/generic/helpers/allocator.hpp"
#include "../collections/generic/helpers/equator.hpp"
#include "../collections/generic/helpers/hasher.hpp"
#include "../collections/generic/helpers/iterator.hpp"
#include "../collections/generic/idictionary.hpp"
#undef __XTD_STD_INTERNAL__

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
      template<typename key_t, typename value_t, typename hasher_t = xtd::collections::generic::helpers::hasher<key_t>, typename equator_t = xtd::collections::generic::helpers::equator<key_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t >>>
      class dictionary;
    }
  }
}
