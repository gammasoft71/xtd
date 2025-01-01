/// @file
/// @brief Contains xtd::collections::hashtable typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/dictionary.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a collection of key/value pairs that are organized based on the hash code of the key.
    /// ```cpp
    /// using hashtable = xtd::collections::generic::dictionary<std::any, std::any>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/hashtable>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @remarks Each element is a key/value pair stored in a xtd::collections::dictionary_entry object. A key cannot be null, but a value can be.
    /// @remarks The objects used as keys by a xtd::collections::hashtable are required to override the xtd::object::get_hash_code method (or the xtd::ihash_code_provider interface) and the xtd::object::equals method (or the xtd::icomparer interface). The implementation of both methods and interfaces must handle case sensitivity the same way; otherwise, the xtd::collections::hashtable might behave incorrectly. For example, when creating a xtd::collections::hashtable, you must use the xtd::case_insensitive_hash_code_provider class (or any case-insensitive xtd::ihash_code_provider implementation) with the xtd::case_insensitive_comparer class (or any case-insensitive xtd::icComparer implementation).
    /// @remarks Furthermore, these methods must produce the same results when called with the same parameters while the key exists in the xtd::collections::hashtable. An alternative is to use a xtd::collections::hashtable constructor with an xtd::iequality_comparer parameter. If key equality were simply reference equality, the inherited implementation of xtd::object::get_hash_code and xtd::object::equals would suffice.
    /// @remarks Key objects must be immutable as long as they are used as keys in the xtd::collections::hashtable.
    /// @remarks When an element is added to the xtd::collections::hashtable, the element is placed into a bucket based on the hash code of the key. Subsequent lookups of the key use the hash code of the key to search in only one particular bucket, thus substantially reducing the number of key comparisons required to find an element.
    /// @remarks The load factor of a xtd::collections::hashtable determines the maximum ratio of elements to buckets. Smaller load factors cause faster average lookup times at the cost of increased memory consumption. The default load factor of 1.0 generally provides the best balance between speed and size. A different load factor can also be specified when the xtd::collections::hashtable is created.
    /// @remarks As elements are added to a xtd::collections::hashtable, the actual load factor of the xtd::collections::hashtable increases. When the actual load factor reaches the specified load factor, the number of buckets in the xtd::collections::hashtable is automatically increased to the smallest prime number that is larger than twice the current number of xtd::collections::hashtable buckets.
    /// @remarks Each key object in the xtd::collections::hashtable must provide its own hash function, which can be accessed by calling GetHash. However, any object implementing IHashCodeProvider can be passed to a xtd::collections::hashtable constructor, and that hash function is used for all objects in the table
    /// @remarks The capacity of a xtd::collections::hashtable is the number of elements the xtd::collections::hashtable can hold. As elements are added to a xtd::collections::hashtable, the capacity is automatically increased as required through reallocation.
    /// @remarks The foreach statement returns an object of the type of the elements in the collection. Since each element of the xtd::collections::hashtable is a key/value pair, the element type is not the type of the key or the type of the value. Instead, the element type is xtd::collections::dictionary_entry. For example:
    /// @code
    /// for (xtd::collections::dictionary_entry de : my_hashtable) {
    ///   // ...
    /// }
    /// @endcode
    /// @remarks The foreach statement is a wrapper around the enumerator, which only allows reading from, not writing to, the collection.
    /// @remarks Because serializing and deserializing an enumerator for a xtd::collections::hashtable can cause the elements to become reordered, it is not possible to continue enumeration without calling the Reset method.
    /// @note Because keys can be inherited and their behavior changed, their absolute uniqueness cannot be guaranteed by comparisons using the Equals method.
    /// @par Exemples
    /// The following example shows how to create, initialize and perform various functions to a xtd::collections::hashtable and how to print out its keys and values.
    /// @include hashtable.cpp
    using hashtable = generic::dictionary<xtd::any_object, xtd::any_object>;
  }
}
